#include "CvGameCoreDLLPCH.h"
#include "CvModUtils.h"

static CivilizationTypes eFoundationType = NO_CIVILIZATION;
static ImprovementTypes eFoundationCustomsHouseType = NO_IMPROVEMENT;
static UnitClassTypes eGreatMerchantType = NO_UNITCLASS;
static UnitTypes eFoundationTraderType = NO_UNIT;
static UnitTypes eFoundationScientistType = NO_UNIT;

UnitTypes GetFoundationTraderType()
{
	if (eFoundationTraderType == NO_UNIT)
	{
		eFoundationTraderType = (UnitTypes)GC.getInfoTypeForString("UNIT_FOUNDATION_SCOUT");
	}

	return eFoundationTraderType;
}

UnitTypes GetFoundationScientistType()
{
	if (eFoundationScientistType == NO_UNIT)
	{
		eFoundationScientistType = (UnitTypes)GC.getInfoTypeForString("UNIT_FOUNDATION_SCIENTIST");
	}

	return eFoundationScientistType;
}

CivilizationTypes GetFoundationCivilizationType()
{
	if (eFoundationType == NO_CIVILIZATION)
	{
		eFoundationType = (CivilizationTypes)GC.getInfoTypeForString("CIVILIZATION_FOUNDATION");
	}

	return eFoundationType;
}


ImprovementTypes GetFoundationTradingDepotType()
{
	if (eFoundationCustomsHouseType == NO_IMPROVEMENT)
	{
		eFoundationCustomsHouseType = (ImprovementTypes)GC.getInfoTypeForString("IMPROVEMENT_FOUNDATION_CUSTOMS_HOUSE");
	}

	return eFoundationCustomsHouseType;
}

UnitClassTypes GetGreatMerchantUnitClassType()
{
	if (eGreatMerchantType == NO_UNITCLASS)
	{
		eGreatMerchantType = (UnitClassTypes) GC.getInfoTypeForString("UNITCLASS_MERCHANT");
	}

	return eGreatMerchantType;
}

bool IsFoundationCivilizationActiveAndHuman()
{
	CivilizationTypes eFoundationType = GetFoundationCivilizationType();
	if (eFoundationType == NO_CIVILIZATION)
	{
		return false;
	}

	for (int iPlayer = 0; iPlayer < MAX_PLAYERS; ++iPlayer)
	{
		CvPlayer& kLoopPlayer = GET_PLAYER((PlayerTypes)iPlayer);
		if(kLoopPlayer.getCivilizationType() == eFoundationType)
		{
			if (kLoopPlayer.isHuman())
			{
				return true;
			}
		}
	}

	return false;

}

ModHandicapTypes GetHandicapType()
{
	// We're only going to give bonuses to the Foundation based on Handicap
	// for human players.
	if (!IsFoundationCivilizationActiveAndHuman())
	{
		return ePrince;
	}

	ModHandicapTypes handicapType = eNoHandicap;
	const char* strHandicapType = GC.getGame().getHandicapInfo().GetType();
					
	if(strcmp(strHandicapType, "HANDICAP_DEITY") == 0)
	{
		handicapType = eDeity;
	}
	else if (strcmp(strHandicapType, "HANDICAP_IMMORTAL") == 0)
	{
		handicapType = eImmortal;
	}
	else if (strcmp(strHandicapType, "HANDICAP_EMPEROR") == 0)
	{
		handicapType = eEmperor;
	}
	else if (strcmp(strHandicapType, "HANDICAP_KING") == 0)
	{
		handicapType = eKing;
	}
	else if (strcmp(strHandicapType, "HANDICAP_PRINCE") == 0)
	{
		handicapType = ePrince;
	}
	else if (strcmp(strHandicapType, "HANDICAP_WARLORD") == 0)
	{
		handicapType = eWarlord;
	}
	else if (strcmp(strHandicapType, "HANDICAP_CHIEFTAN") == 0)
	{
		handicapType = eChieftain;
	}
	else if (strcmp(strHandicapType, "HANDICAP_SETTLER") == 0)
	{
		handicapType = eSettler;
	}

	return handicapType;
}
