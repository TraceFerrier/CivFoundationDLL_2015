#include "CvGameCoreDLLPCH.h"
#include "CvModUtils.h"

void CvTacticalAI::IdentifyBarbarianPriorityTargetsByType()
{
	// Look through all the enemies we can see
	for(unsigned int iI = 0; iI < m_AllTargets.size(); iI++)
	{
		// Don't consider units that are already high priority
		if(m_AllTargets[iI].GetTargetType() != AI_TACTICAL_TARGET_HIGH_PRIORITY_UNIT)
		{
			// Units defending citadels will always be high priority targets
			CvUnit* pUnit = (CvUnit*)m_AllTargets[iI].GetAuxData();
			if (pUnit->getUnitType() == GetFoundationTraderType())
			{
				if (pUnit->GetTraderSuppliesLoaded() > 0)
				{
					m_AllTargets[iI].SetTargetType(AI_TACTICAL_TARGET_HIGH_PRIORITY_UNIT);
				}
			}
		}
	}
}
