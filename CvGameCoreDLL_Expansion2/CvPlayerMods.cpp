#include "CvGameCoreDLLPCH.h"
#include "CvModUtils.h"

void CvPlayer::UpdateFoundationImprovements()
{
	if (getCivilizationType() == GetFoundationCivilizationType())
	{
		// Loop through all plots
		const CvPlotsVector& aiPlots = GetPlots();
		for (uint uiPlotIndex = 0; uiPlotIndex < aiPlots.size(); uiPlotIndex++)
		{
			if (aiPlots[uiPlotIndex] == -1)
				continue;

			// For the Foundation Trading Depot, add supplies each turn, based on
			// the number of Merchant specialist points currently being generated
			// per turn in the city hosting the depot.
			CvPlot* pPlot = GC.getMap().plotByIndex(aiPlots[uiPlotIndex]);
			if (pPlot->getImprovementType() == GetFoundationTradingDepotType())
			{
				int iTradingSuppliesPerTurn = 0;

				CvCity* pCity = pPlot->getWorkingCity();
				if (pCity != NULL)
				{
					iTradingSuppliesPerTurn = pCity->GetCityCitizens()->GetGreatPersonPointsForSpecialist(GetGreatMerchantUnitClassType());
				}

				if (iTradingSuppliesPerTurn < 5)
				{
					iTradingSuppliesPerTurn = 5;
				}
				pPlot->addTraderSupplies(iTradingSuppliesPerTurn);
			}
		}
	}

}
