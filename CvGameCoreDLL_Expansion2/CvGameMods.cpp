#include "CvGameCoreDLLPCH.h"

void CvGame::InitTraitMods()
{
	for(int iI = 0; iI < GC.getNumTraitInfos(); iI++)
	{
		CvTraitEntry* trait = GC.getTraitInfo((TraitTypes)iI);
		if (trait != NULL)
		{
			trait->ApplyTraitMods();
		}
	}
}

void CvGame::InitUnitMods()
{
	for(int iLoop = 0; iLoop < GC.getNumUnitInfos(); iLoop++)
	{
		UnitTypes eUnitType = (UnitTypes)iLoop;
		CvUnitEntry* pUnitEntry = GC.getUnitInfo(eUnitType);
		if(pUnitEntry)
		{
			pUnitEntry->InitUnitMods();
		}
	}
}

void CvGame::InitPromotionMods()
{
	for(int iLoop = 0; iLoop < GC.getNumPromotionInfos(); iLoop++)
	{
		const PromotionTypes ePromotion = static_cast<PromotionTypes>(iLoop);
		CvPromotionEntry* pkPromotionInfo = GC.getPromotionInfo(ePromotion);
		if(pkPromotionInfo)
		{
			pkPromotionInfo->ApplyPromotionMods();
		}
	}
}

void CvGame::InitImprovementMods()
{
	for(int iI = 0; iI < GC.getNumImprovementInfos(); iI++)
	{
		CvImprovementEntry* pImprovementEntry = GC.getImprovementInfo((ImprovementTypes)iI);
		if(pImprovementEntry)
		{
			pImprovementEntry->ApplyImprovementMods();
		}
	}

}