#include "CvGameCoreDLLPCH.h"
#include "CvGameCoreUtils.h"
#include "CvDllUnit.h"
#include "CvMinorCivAI.h"
#include "CvModUtils.h"

const int MaxTradingSuppliesCarried = 25;
const int MaxTradingSuppliesAtDepot = 50;
const int ExtraSuppliesPerEra = 10;

int CvUnit::GetMaxTradingSuppliesCarried()
{
	int maxSupplies = MaxTradingSuppliesCarried;
	maxSupplies += ExtraSuppliesPerEra * GET_TEAM(getTeam()).GetCurrentEra();
	return maxSupplies;
}

int CvPlot::GetMaxTradingSuppliesAtDepot()
{
	int maxSupplies = MaxTradingSuppliesAtDepot;
	maxSupplies += ExtraSuppliesPerEra * GET_TEAM(getTeam()).GetCurrentEra();
	return maxSupplies;
}

bool CvUnit::IsTradingModActive() const
{
	PromotionTypes eTraderMissionType = (PromotionTypes)GC.getInfoTypeForString("PROMOTION_FOUNDATION_TRADER_MISSION");
	if (eTraderMissionType != NO_PROMOTION)
	{
		if (isHasPromotion(eTraderMissionType))
		{
			return true;
		}
	}

	return false;
}

bool CvUnit::canDoSupplyReport(const CvPlot* pPlot, bool bTestVisible) const
{
	if (IsTradingModActive() == false)
	{
		return false;
	}

	return true;
}

bool CvUnit::canDoSupplyPickup(const CvPlot* pPlot, bool bTestVisible)
{
	if (IsTradingModActive() == false)
	{
		return false;
	}

	// Things that block usage but not visibility
	if(!bTestVisible)
	{
		if (!pPlot->getImprovementType() == GetFoundationCustomsHouseType())
		{
			return false;
		}


		// Can't do the mission if this unit is carrying all the supplies it can
		if (m_iTraderSuppliesLoaded >= GetMaxTradingSuppliesCarried())
		{
			return false;
		}

		if (pPlot->getTraderSuppliesAvailable() <= 0)
		{
			return false;
		}
	}

	return true;
}

bool CvUnit::canDoFoundationTrade(const CvPlot* pPlot, bool bTestVisible) const
{
	if (IsTradingModActive() == false)
	{
		return false;
	}

	// Things that block usage but not visibility
	if(!bTestVisible)
	{
		// Not owned
		if(pPlot->getOwner() == NO_PLAYER)
			return false;

		// Owned by a non-minor civ
		if(!GET_PLAYER(pPlot->getOwner()).isMinorCiv())
			return false;

		if(GET_TEAM(pPlot->getTeam()).isAtWar(getTeam()))
		{
			return false;
		}

		if (m_iTraderSuppliesLoaded == 0)
		{
			return false;
		}
	}

	return true;
}


bool CvUnit::DoTraderSupplyReport()
{
	VALIDATE_OBJECT

	CvPlot* pPlot = plot();

	if (!canDoSupplyReport(pPlot))
	{
		return false;
	}

	if(getOwner() == GC.getGame().getActivePlayer())
	{
		if (pPlot->getImprovementType() == GetFoundationCustomsHouseType())
		{
			DLLUI->AddUnitMessage(0, GetIDInfo(), getOwner(), true, GC.getEVENT_MESSAGE_TIME(), GetLocalizedText("TXT_KEY_FOUNDATION_SUPPLY_DEPOT_REPORT", m_iTraderSuppliesLoaded, GetMaxTradingSuppliesCarried(), pPlot->getTraderSuppliesAvailable()));
		}
		else
		{
			DLLUI->AddUnitMessage(0, GetIDInfo(), getOwner(), true, GC.getEVENT_MESSAGE_TIME(), GetLocalizedText("TXT_KEY_FOUNDATION_SUPPLY_REPORT", m_iTraderSuppliesLoaded, GetMaxTradingSuppliesCarried()));
		}
	}

	return true;
}


bool CvUnit::DoPickUpTraderSupplies()
{
	VALIDATE_OBJECT

	CvPlot* pPlot = plot();

	if (!canDoSupplyPickup(pPlot))
	{
		return false;
	}

	int iSuppliesToLoad = GetMaxTradingSuppliesCarried() - m_iTraderSuppliesLoaded;
	if (iSuppliesToLoad > pPlot->getTraderSuppliesAvailable())
	{
		iSuppliesToLoad = pPlot->getTraderSuppliesAvailable();
	}

	m_iTraderSuppliesLoaded += iSuppliesToLoad;
	pPlot->addTraderSupplies(-iSuppliesToLoad);

	if(getOwner() == GC.getGame().getActivePlayer())
	{
		DLLUI->AddUnitMessage(0, GetIDInfo(), getOwner(), true, GC.getEVENT_MESSAGE_TIME(), GetLocalizedText("TXT_KEY_FOUNDATION_DEPOT_SUPPLY_PICKUP_RESULT", iSuppliesToLoad, m_iTraderSuppliesLoaded, GetMaxTradingSuppliesCarried()));
	}

	return true;
}

bool CvUnit::DoFoundationTrade()
{
	VALIDATE_OBJECT

	CvPlot* pPlot = plot();

	if(!canDoFoundationTrade(pPlot))
		return false;

	int iTradeGold = getFoundationTradeGold(pPlot);
	
	GET_PLAYER(getOwner()).GetTreasury()->ChangeGold(iTradeGold);

	// Improve relations with the Minor
	PlayerTypes eMinor = pPlot->getOwner();
	CvAssertMsg(eMinor != NO_PLAYER, "Performing a trade mission and not in city state territory. This is bad. Please send Jon this with your last 5 autosaves and what changelist # you're playing.");
	int iFriendship = getFoundationTradeInfluence(pPlot);
	GET_PLAYER(eMinor).GetMinorCivAI()->ChangeFriendshipWithMajor(getOwner(), iFriendship);

	if(getOwner() == GC.getGame().getActivePlayer())
	{
		DLLUI->AddUnitMessage(0, GetIDInfo(), getOwner(), true, GC.getEVENT_MESSAGE_TIME(), GetLocalizedText("TXT_KEY_MERCHANT_RESULT", iTradeGold, iFriendship));
	}

	if(pPlot->isActiveVisible(false))
	{
		auto_ptr<ICvUnit1> pDllUnit(new CvDllUnit(this));
		gDLL->GameplayUnitActivate(pDllUnit.get());
	}

	m_iTraderSuppliesLoaded = 0;
	return true;
}



//	--------------------------------------------------------------------------------
int CvUnit::getFoundationTradeGold(const CvPlot* /*pPlot*/) const
{
	VALIDATE_OBJECT
	int iGold;

	// Seed the gold Value with some cash
	iGold = m_iTraderSuppliesLoaded;

	// Amount of Gold also increases with how far into the game we are
	iGold += (m_pUnitInfo->GetNumGoldPerEra() * GET_TEAM(getTeam()).GetCurrentEra());

	iGold *= GC.getGame().getGameSpeedInfo().getUnitTradePercent();
	iGold /= 100;

	return std::max(0, iGold);
}

//	--------------------------------------------------------------------------------
int CvUnit::getFoundationTradeInfluence(const CvPlot* pPlot) const
{
	VALIDATE_OBJECT
	int iInf = 0;
	if (pPlot && canDoFoundationTrade(pPlot))
	{
		PlayerTypes eMinor = pPlot->getOwner();
		CvAssertMsg(eMinor != NO_PLAYER, "Performing a trade mission and not in city state territory. This is bad. Please send Jon this with your last 5 autosaves and what changelist # you're playing.");
		if (eMinor != NO_PLAYER)
		{
			iInf = m_iTraderSuppliesLoaded;
			int iInfTimes100 = iInf * (100 + GetTradeMissionInfluenceModifier());
			iInf = iInfTimes100 / 100;
		}
	}
	return iInf;
}



int CvPlot::getTraderSuppliesAvailable() const
{
	return m_iTraderSuppliesAvailable;
}

void CvPlot::setTraderSupplies(int iSupplies)
{
	m_iTraderSuppliesAvailable = iSupplies;
}


void CvPlot::addTraderSupplies(int iSupplies)
{
	if (!IsImprovementPillaged())
	{
		m_iTraderSuppliesAvailable += iSupplies;
		if (m_iTraderSuppliesAvailable < 0)
		{
			m_iTraderSuppliesAvailable = 0;
		}

		if (m_iTraderSuppliesAvailable > GetMaxTradingSuppliesAtDepot())
		{
			m_iTraderSuppliesAvailable = GetMaxTradingSuppliesAtDepot();
		}
	}
}


