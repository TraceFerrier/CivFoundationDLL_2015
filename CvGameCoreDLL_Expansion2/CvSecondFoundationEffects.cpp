#include "CvGameCoreDLLPCH.h"
#include "CvGameCoreUtils.h"
#include "CvMinorCivAI.h"

static CivilizationTypes eFoundationType;
static const int MaxFoundationPromotedUnits = 150;
static int FoundationPromotedUnitCount = 0; 
static CvUnit* FoundationPromotedUnits[MaxFoundationPromotedUnits];

static PromotionTypes PromoDefenseHigh;
static PromotionTypes PromoDefenseMedium;
static PromotionTypes PromoDefenseLow;
static PromotionTypes PromoOffenseHigh;
static PromotionTypes PromoOffenseMedium;
static PromotionTypes PromoOffenseLow;
static UnitTypes eSecondFoundationerType;
static UnitTypes eTypeWorker;
static UnitTypes eTypeSettler;
static UnitTypes eTypeMissionary;
static UnitTypes eTypeProphet;
static UnitTypes eTypeScientist;
static UnitTypes eTypeGeneral;
static UnitTypes eTypeMerchant;
static UnitTypes eTypeArtist;
static UnitTypes eTypeEngineer;
static UnitTypes eTypeWorkboat;
static UnitTypes eTypeAtomicBomb;
static UnitTypes eTypeNuclearMissile;
static UnitTypes eTypeCaravan;

const int MaxDistanceFromSecondFoundationer = 6;
const int HighDistance = 2;
const int MediumDistance = 4;
const int LowDistance = 6;

//------------------------------------------------------------------------
//   FindUnitsInRangeOfSecondFoundationerAndApplyEffects 
//------------------------------------------------------------------------
void InitializeSecondFoundationEffectsMod()
{
	eFoundationType = (CivilizationTypes)GC.getInfoTypeForString("CIVILIZATION_FOUNDATION");
	PromoDefenseHigh = (PromotionTypes)GC.getInfoTypeForString("PROMOTION_SECOND_FOUNDATION_DEFENSE_HIGH");
	PromoDefenseMedium = (PromotionTypes)GC.getInfoTypeForString("PROMOTION_SECOND_FOUNDATION_DEFENSE_MEDIUM");
	PromoDefenseLow = (PromotionTypes)GC.getInfoTypeForString("PROMOTION_SECOND_FOUNDATION_DEFENSE_LOW");
	PromoOffenseHigh = (PromotionTypes)GC.getInfoTypeForString("PROMOTION_SECOND_FOUNDATION_ATTACK_SUPPRESS_HIGH");
	PromoOffenseMedium = (PromotionTypes)GC.getInfoTypeForString("PROMOTION_SECOND_FOUNDATION_ATTACK_SUPPRESS_MEDIUM");
	PromoOffenseLow = (PromotionTypes)GC.getInfoTypeForString("PROMOTION_SECOND_FOUNDATION_ATTACK_SUPPRESS_LOW");

	eSecondFoundationerType = (UnitTypes)GC.getInfoTypeForString("UNIT_SECOND_FOUNDATIONER");
	eTypeWorker = (UnitTypes)GC.getInfoTypeForString("UNIT_WORKER");
	eTypeSettler = (UnitTypes)GC.getInfoTypeForString("UNIT_SETTLER");
	eTypeMissionary = (UnitTypes)GC.getInfoTypeForString("UNIT_MISSIONARY");
	eTypeProphet = (UnitTypes)GC.getInfoTypeForString("UNIT_PROPHET");
	eTypeScientist = (UnitTypes)GC.getInfoTypeForString("UNIT_SCIENTIST");
	eTypeGeneral = (UnitTypes)GC.getInfoTypeForString("UNIT_GREAT_GENERAL");
	eTypeMerchant = (UnitTypes)GC.getInfoTypeForString("UNIT_MERCHANT");
	eTypeArtist = (UnitTypes)GC.getInfoTypeForString("UNIT_ARTIST");
	eTypeEngineer = (UnitTypes)GC.getInfoTypeForString("UNIT_ENGINEER");
	eTypeWorkboat = (UnitTypes)GC.getInfoTypeForString("UNIT_WORKBOAT");
	eTypeAtomicBomb = (UnitTypes)GC.getInfoTypeForString("UNIT_ATOMIC_BOMB");
	eTypeNuclearMissile = (UnitTypes)GC.getInfoTypeForString("UNIT_NUCLEAR_MISSILE");
	eTypeCaravan = (UnitTypes)GC.getInfoTypeForString("UNIT_CARAVAN");

}

//------------------------------------------------------------------------
//   FindUnitsInRangeOfSecondFoundationerAndApplyEffects 
//------------------------------------------------------------------------
bool CanUnitTakeSecondFoundationerPromotion(CvUnit* pUnit)
{
	if(pUnit->getUnitType() == eSecondFoundationerType)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeWorker)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeSettler)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeMissionary)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeProphet)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeScientist)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeGeneral)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeMerchant)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeArtist)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeEngineer)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeArtist)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeWorkboat)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeAtomicBomb)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeNuclearMissile)
	{
		return false;
	}

	if(pUnit->getUnitType() == eTypeCaravan)
	{
		return false;
	}

	return true;
}

//------------------------------------------------------------------------
//	NotifyModUnitKilled - Notification that a unit has been killed - 
//	remove that unit from our PromotedUnits table.
//------------------------------------------------------------------------
void NotifyModUnitKilled(CvUnit* pUnit)
{
	for (int idx = 0; idx < FoundationPromotedUnitCount; idx++)
	{
		CvUnit* pUnitInTable = FoundationPromotedUnits[idx];
		if (pUnitInTable != NULL)
		{
			if (pUnit->GetID() == pUnitInTable->GetID())
			{
				FoundationPromotedUnits[idx] = NULL;

			}
		}
	}
}

void AddUnitToPromotionsTable(CvUnit* pUnit)
{
	for (int idx = 0; idx < FoundationPromotedUnitCount; idx++)
	{
		CvUnit* pUnitInTable = FoundationPromotedUnits[idx];
		if (pUnitInTable != NULL)
		{
			if (pUnitInTable->GetID() == pUnit->GetID())
			{
				return;
			}
		}
	}

	FoundationPromotedUnits[FoundationPromotedUnitCount] = pUnit;
	FoundationPromotedUnitCount++;
}

//------------------------------------------------------------------------------
void ClearPromotion(CvUnit* pUnit, PromotionTypes promotion)
{
	if (pUnit != NULL && pUnit->isHasPromotion(promotion) == true)
	{
		pUnit->setHasPromotion(promotion, false);
	}
}

//------------------------------------------------------------------------------
void SetPromotion(CvUnit* pUnit, PromotionTypes promotion)
{
	// Be sure to not overflow the promoted units table.
	if (FoundationPromotedUnitCount < MaxFoundationPromotedUnits - 1)
	{
		if (pUnit != NULL && pUnit->isHasPromotion(promotion) == false)
		{
			pUnit->setHasPromotion(promotion, true);
			AddUnitToPromotionsTable(pUnit);
		}
	}
}

//------------------------------------------------------------------------------
void ClearAllPromotions(CvUnit* pUnit)
{
	ClearPromotion(pUnit, PromoDefenseHigh);
	ClearPromotion(pUnit, PromoDefenseMedium);
	ClearPromotion(pUnit, PromoDefenseLow);
	ClearPromotion(pUnit, PromoOffenseHigh);
	ClearPromotion(pUnit, PromoOffenseMedium);
	ClearPromotion(pUnit, PromoOffenseLow);
}

//------------------------------------------------------------------------------
void ClearAllCurrentPromotions()
{
	if (FoundationPromotedUnitCount > 0)
	{
		for (int i = 0; i < FoundationPromotedUnitCount; i++)
		{	CvUnit* pUnit = FoundationPromotedUnits[i];
			if (pUnit != NULL)
			{
				ClearAllPromotions(pUnit);
			}
		}
	}

	FoundationPromotedUnitCount = 0;
}

void ApplyPromotionsToFriend(CvUnit* pUnit, int distance)
{
	if (distance <= HighDistance)
	{
		ClearPromotion(pUnit, PromoDefenseLow);
		ClearPromotion(pUnit, PromoDefenseMedium);
		SetPromotion(pUnit, PromoDefenseHigh);
	}
	else if (distance <= MediumDistance)
	{
		if (pUnit->isHasPromotion(PromoDefenseHigh) == false)
		{
			ClearPromotion(pUnit, PromoDefenseLow);
			SetPromotion(pUnit, PromoDefenseMedium);
		}
	}
	else if (distance <= LowDistance)
	{
		if (pUnit->isHasPromotion(PromoDefenseHigh) == false && pUnit->isHasPromotion(PromoDefenseMedium) == false)
		{
			SetPromotion(pUnit, PromoDefenseLow);
		}
	}
}

void ApplyPromotionsToEnemy(CvUnit* pUnit, int distance)
{
	if (distance <= HighDistance)
	{
		ClearPromotion(pUnit, PromoOffenseLow);
		ClearPromotion(pUnit, PromoOffenseMedium);
		SetPromotion(pUnit, PromoOffenseHigh);
	}
	else if (distance <= MediumDistance)
	{
		if (pUnit->isHasPromotion(PromoOffenseHigh) == false)
		{
			ClearPromotion(pUnit, PromoOffenseLow);
			SetPromotion(pUnit, PromoOffenseMedium);
		}
	}
	else if (distance <= LowDistance)
	{
		if (pUnit->isHasPromotion(PromoOffenseHigh) == false && pUnit->isHasPromotion(PromoOffenseMedium) == false)
		{
			SetPromotion(pUnit, PromoOffenseLow);
		}
	}
}

//------------------------------------------------------------------------
//   FindUnitsInRangeOfSecondFoundationerAndApplyEffects 
//------------------------------------------------------------------------
void FindUnitsInRangeOfSecondFoundationerAndApplyEffects(const CvUnit* pSecondFoundationerUnit)
{
	CvPlayerAI& foundationPlayer = GET_PLAYER(pSecondFoundationerUnit->getOwner());
	TeamTypes foundationTeamID = pSecondFoundationerUnit->getTeam();
	int secondFoundationerX = pSecondFoundationerUnit->getX();
	int secondFoundationerY = pSecondFoundationerUnit->getY();
	int plotX = secondFoundationerX;
	int plotY = secondFoundationerY;
	bool lastPlotReached = false;

	const int MoveRight = 1;
	const int MoveDown = 2;
	const int MoveLeft = 3;
	const int MoveUp = 4;

	int moveDistance = 1;
	int moveDirection = MoveRight;
	int distanceMoved = 0;

	while(lastPlotReached == false)
	{
		CvPlot* pPlot = GC.getMap().plot(plotX, plotY);
		if (pPlot != NULL)
		{
			int distanceFromSecondFoundationer = plotDistance(secondFoundationerX, secondFoundationerY, plotX, plotY);
			if (distanceFromSecondFoundationer > MaxDistanceFromSecondFoundationer)
			{
				lastPlotReached = true;
				break;
			}
			
			int plotNumUnits = pPlot->getNumUnits();
			if (plotNumUnits > 0)
			{
				for (int i = 0; i < plotNumUnits; i++)
				{
					CvUnit* pPlotUnit = pPlot->getUnitByIndex(i);
					if (pPlotUnit != NULL)
					{
						if (CanUnitTakeSecondFoundationerPromotion(pPlotUnit))
						{
							PlayerTypes unitPlayerID = pPlotUnit->getOwner();
							CvPlayerAI& kUnitPlayer = GET_PLAYER(unitPlayerID);
							TeamTypes unitTeamID = pPlotUnit->getTeam();

							bool isFoundationUnit = kUnitPlayer.getCivilizationType() == eFoundationType;
							bool isFoundationAtWarWithUnit = GET_TEAM(foundationTeamID).isAtWar(unitTeamID);

							if (isFoundationUnit || foundationPlayer.GetMinorCivAI()->IsAllies(unitPlayerID) || foundationPlayer.GetMinorCivAI()->IsFriends(unitPlayerID))
							{
								ApplyPromotionsToFriend(pPlotUnit, distanceFromSecondFoundationer);
							}
							else if (isFoundationAtWarWithUnit || GET_TEAM(unitTeamID).isBarbarian())
							{
								ApplyPromotionsToEnemy(pPlotUnit, distanceFromSecondFoundationer);
							}
						}
					}
				}
			}
		}

		if (moveDirection == MoveRight)
		{
			plotX = plotX + 1;
			distanceMoved = distanceMoved + 1;
			if (distanceMoved == moveDistance)
			{
				moveDirection = MoveDown;
				distanceMoved = 0;
			}
		}
		else if (moveDirection == MoveDown)
		{
			plotY = plotY + 1;
			distanceMoved = distanceMoved + 1;
			if (distanceMoved == moveDistance)
			{
				moveDistance = moveDistance + 1;
				moveDirection = MoveLeft;
				distanceMoved = 0;
			}
		}
		else if (moveDirection == MoveLeft)
		{
			plotX = plotX - 1;
			distanceMoved = distanceMoved + 1;
			if (distanceMoved == moveDistance)
			{
				moveDirection = MoveUp;
				distanceMoved = 0;
			}
		}
		else if (moveDirection == MoveUp)
		{
			plotY = plotY - 1;
			distanceMoved = distanceMoved + 1;
			if (distanceMoved == moveDistance)
			{
				moveDistance = moveDistance + 1;
				moveDirection = MoveRight;
				distanceMoved = 0;
			}
		}
	}
}

//------------------------------------------------------------------------
//   PlayerDoModTurn - this will be called at the end of the AI portion
// of every player's turn.
//------------------------------------------------------------------------
void CvPlayer::PlayerDoModTurn()
{
	if (m_isFoundationModInitialized == false)
	{
		InitializeSecondFoundationEffectsMod();

		// Initially clear all 2nd Foundationer promotions, because they could still be set when a
		// a saved game is loaded.
		int iLoop = 0;
		for(CvUnit* pUnit = firstUnit(&iLoop); pUnit != NULL; pUnit = nextUnit(&iLoop))
		{
			ClearAllPromotions(pUnit);
		}

		m_isFoundationModInitialized = true;
	}

	ClearAllCurrentPromotions();

	for (int iPlayer = 0; iPlayer < MAX_PLAYERS; ++iPlayer)
	{
		CvPlayer& kPlayer = GET_PLAYER((PlayerTypes)iPlayer);
		if(kPlayer.getCivilizationType() == eFoundationType)
		{
			int iLoop = 0;
			for(const CvUnit* pUnit = kPlayer.firstUnit(&iLoop); pUnit != NULL; pUnit = kPlayer.nextUnit(&iLoop))
			{
				if(pUnit->getUnitType() == eSecondFoundationerType)
				{
					FindUnitsInRangeOfSecondFoundationerAndApplyEffects(pUnit);
				}
			}
		}
	}

}