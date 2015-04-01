#include "CvGameCoreDLLPCH.h"
#include "CvModUtils.h"

bool SetImprovementYieldChange(const char* strImprovementType, const char* strYieldType, int change)
{
	int eImprovement = GC.getInfoTypeForString(strImprovementType);
	int eYieldType = GC.getInfoTypeForString(strYieldType);

	CvImprovementEntry* pImprovementEntry = GC.getImprovementInfo((ImprovementTypes) eImprovement);
	if (pImprovementEntry != NULL)
	{
		pImprovementEntry->SetYieldChange(eYieldType, change);
		return true;
	}

	return false;
}

void CvImprovementEntry::ApplyImprovementMods()
{
	ModHandicapTypes handicap = GetHandicapType();
	if (handicap == eDeity)
	{
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 12);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_CULTURE", 3);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_CUSTOMS_HOUSE", "YIELD_GOLD", 8);
	}
	else if (handicap == eImmortal)
	{
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 10);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_CULTURE", 2);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_CUSTOMS_HOUSE", "YIELD_GOLD", 6);
	}
	else if (handicap == eEmperor)
	{
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 8);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_CULTURE", 1);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_CUSTOMS_HOUSE", "YIELD_GOLD", 4);
	}
	else
	{
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_SCIENCE", 6);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_ACADEMY", "YIELD_CULTURE", 1);
		SetImprovementYieldChange("IMPROVEMENT_FOUNDATION_CUSTOMS_HOUSE", "YIELD_GOLD", 3);
	}
}

void CvImprovementEntry::SetYieldChange(int i, int change)
{
	if (m_piYieldChange != NULL && i < NUM_YIELD_TYPES && i > -1)
	{
		m_piYieldChange[i] = change;
	}
}
