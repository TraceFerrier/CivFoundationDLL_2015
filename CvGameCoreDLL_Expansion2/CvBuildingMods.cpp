#include "CvGameCoreDLLPCH.h"
#include "CvModUtils.h"

bool SetBuildingYieldModifier(const char* strBuildingType, const char* strYieldType, int modifier)
{
	int eBuilding = GC.getInfoTypeForString(strBuildingType);
	int eYieldType = GC.getInfoTypeForString(strYieldType);

	CvBuildingEntry* pkBuildingInfo = GC.getBuildingInfo((BuildingTypes) eBuilding);
	if (pkBuildingInfo != NULL)
	{
		pkBuildingInfo->SetYieldModifier(eYieldType, modifier);
		return true;
	}

	return false;
}

bool SetBuildingYieldChange(const char* strBuildingType, const char* strYieldType, int change)
{
	int eBuilding = GC.getInfoTypeForString(strBuildingType);
	int eYieldType = GC.getInfoTypeForString(strYieldType);

	CvBuildingEntry* pkBuildingInfo = GC.getBuildingInfo((BuildingTypes) eBuilding);
	if (pkBuildingInfo != NULL)
	{
		pkBuildingInfo->SetYieldChange(eYieldType, change);
		return true;
	}

	return false;
}



void CvGame::InitBuildingMods()
{
	// First allow each CvBuildingEntry to customize itself
	for(int iLoop = 0; iLoop < GC.getNumBuildingInfos(); iLoop++)
	{
		BuildingTypes eBuildingType = (BuildingTypes)iLoop;
		CvBuildingEntry* pBuildingEntry = GC.getBuildingInfo(eBuildingType);
		if (pBuildingEntry)
		{
			pBuildingEntry->InitBuildingMods();
		}
	}

	ModHandicapTypes handicap = GetHandicapType();
	if (handicap == eDeity)
	{
		SetBuildingYieldModifier("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 15);
		SetBuildingYieldModifier("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 20);
		SetBuildingYieldModifier("BUILDING_FOUNDATION_WORKSHOP", "YIELD_FAITH", 15 );
		SetBuildingYieldModifier("BUILDING_GALACTIC_TEMPLE", "YIELD_PRODUCTION", 15 );
		SetBuildingYieldModifier("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 20 );

		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 5);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_CULTURE", 5);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_PRODUCTION", 2);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 6);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_FOOD", 1);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_FAITH", 8);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_CULTURE", 4);
		SetBuildingYieldChange("BUILDING_FOUNDATION_WORKSHOP", "YIELD_PRODUCTION", 4);
		SetBuildingYieldChange("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 5);
	}
	else if (handicap == eImmortal)
	{
		SetBuildingYieldModifier("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 15);
		SetBuildingYieldModifier("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 15);
		SetBuildingYieldModifier("BUILDING_GALACTIC_TEMPLE", "YIELD_FAITH", 15 );
		SetBuildingYieldModifier("BUILDING_GALACTIC_TEMPLE", "YIELD_PRODUCTION", 15 );
		SetBuildingYieldModifier("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 15 );

		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 5);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_CULTURE", 4);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_PRODUCTION", 1);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 4);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_FOOD", 1);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_FAITH", 5);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_CULTURE", 2);
		SetBuildingYieldChange("BUILDING_FOUNDATION_WORKSHOP", "YIELD_PRODUCTION", 3);
		SetBuildingYieldChange("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 4);
	}
	else if (handicap == eEmperor)
	{
		SetBuildingYieldModifier("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 10);
		SetBuildingYieldModifier("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 10);
		SetBuildingYieldModifier("BUILDING_GALACTIC_TEMPLE", "YIELD_FAITH", 15 );
		SetBuildingYieldModifier("BUILDING_GALACTIC_TEMPLE", "YIELD_PRODUCTION", 15 );
		SetBuildingYieldModifier("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 10 );

		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 4);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_CULTURE", 2);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_PRODUCTION", 1);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 3);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_FOOD", 0);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_FAITH", 4);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_CULTURE", 1);
		SetBuildingYieldChange("BUILDING_FOUNDATION_WORKSHOP", "YIELD_PRODUCTION", 3);
		SetBuildingYieldChange("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 4);
	}
	else
	{
		SetBuildingYieldModifier("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 10);
		SetBuildingYieldModifier("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 10);
		SetBuildingYieldModifier("BUILDING_GALACTIC_TEMPLE", "YIELD_FAITH", 15 );
		SetBuildingYieldModifier("BUILDING_GALACTIC_TEMPLE", "YIELD_PRODUCTION", 15 );
		SetBuildingYieldModifier("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 10 );

		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_SCIENCE", 3);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_CULTURE", 1);
		SetBuildingYieldChange("BUILDING_GALACTIC_LIBRARY", "YIELD_PRODUCTION", 3);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 3);
		SetBuildingYieldChange("BUILDING_SECOND_FOUNDATION_ACADEMY", "YIELD_FOOD", 0);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_FAITH", 3);
		SetBuildingYieldChange("BUILDING_GALACTIC_TEMPLE", "YIELD_CULTURE", 0);
		SetBuildingYieldChange("BUILDING_FOUNDATION_WORKSHOP", "YIELD_PRODUCTION", 3);
		SetBuildingYieldChange("BUILDING_FOUNDATION_MARKET", "YIELD_GOLD", 3);
	}
}

void CvBuildingEntry::SetYieldModifier(int i, int iModifier)
{
	if (m_piYieldModifier != NULL && i < NUM_YIELD_TYPES && i > -1)
	{
		m_piYieldModifier[i] = iModifier;
	}
}

void CvBuildingEntry::SetYieldChange(int i, int change)
{
	if (m_piYieldChange != NULL && i < NUM_YIELD_TYPES && i > -1)
	{
		m_piYieldChange[i] = change;
	}
}

void CvBuildingEntry::InitBuildingMods()
{
	const char* strType = GetType();

	// Foundation Market mods
	if (strcmp(strType, "BUILDING_FOUNDATION_MARKET") == 0)
	{
		ModHandicapTypes handicap = GetHandicapType();
		if (handicap == eDeity)
		{
			m_iGreatPeopleRateChange = 5;
		}
		else if (handicap == eImmortal)
		{
			m_iGreatPeopleRateChange = 4;
		}
		else if (handicap == eEmperor)
		{
			m_iGreatPeopleRateChange = 3;
		}
		else if (handicap == eKing)
		{
			m_iGreatPeopleRateChange = 2;
		}
		else
		{
			m_iGreatPeopleRateChange = 2;
		}
	}
	
	// Workshop mods
	else if (strcmp(strType, "BUILDING_FOUNDATION_WORKSHOP") == 0)
	{
		ModHandicapTypes handicap = GetHandicapType();
		if (handicap == eDeity)
		{
			m_iGreatPeopleRateChange = 3;
		}
		else if (handicap == eImmortal)
		{
			m_iGreatPeopleRateChange = 3;
		}
		else if (handicap == eEmperor)
		{
			m_iGreatPeopleRateChange = 2;
		}
		else if (handicap == eKing)
		{
			m_iGreatPeopleRateChange = 1;
		}
		else
		{
			m_iGreatPeopleRateChange = 1;
		}
	}

	// Workshop mods
	else if (strcmp(strType, "BUILDING_SECOND_FOUNDATION_ACADEMY") == 0)
	{
		ModHandicapTypes handicap = GetHandicapType();
		if (handicap == eDeity)
		{
			m_iGreatPeopleRateChange = 3;
		}
		else if (handicap == eImmortal)
		{
			m_iGreatPeopleRateChange = 3;
		}
		else if (handicap == eEmperor)
		{
			m_iGreatPeopleRateChange = 2;
		}
		else if (handicap == eKing)
		{
			m_iGreatPeopleRateChange = 2;
		}
		else
		{
			m_iGreatPeopleRateChange = 2;
		}
	}
}

