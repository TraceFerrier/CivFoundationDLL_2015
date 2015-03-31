#include "CvGameCoreDLLPCH.h"

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

bool CvUnit::canModTrade(const CvPlot* pPlot, bool bTestVisible) const
{
	if(m_pUnitInfo->GetBaseGold() == 0)
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

		if (m_bTraderSuppliesLoaded == false)
		{
			return false;
		}
	}

	return true;
}

bool CvUnit::ShouldKillAfterTrade()
{
	if (IsTradingModActive())
	{
		m_bTraderSuppliesLoaded = false;
		return false;
	}

	return true;
}

void CvUnit::DoModUnitMoved()
{
	if (IsTradingModActive())
	{
		if (IsInCapitalCity())
		{
			m_bTraderSuppliesLoaded = true;
		}
	}
}

bool CvUnit::IsInCapitalCity() const
{
	CvPlot* pPlot = plot();
	if (pPlot != NULL)
	{
		if (pPlot->isFriendlyCity(*this, false) == false)
		{
			return false;
		}

		CvCity* pCity = pPlot->getPlotCity();
		if (pCity)
		{
			return pCity->isCapital();
		}
	}

	return false;
}

