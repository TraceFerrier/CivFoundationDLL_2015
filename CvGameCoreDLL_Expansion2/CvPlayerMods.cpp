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

			CvPlot* pPlot = GC.getMap().plotByIndex(aiPlots[uiPlotIndex]);
			if (pPlot->getImprovementType() == GetFoundationCustomsHouseType())
			{
				pPlot->addTraderSupplies(TradingSuppliesPerTurn);
			}
		}
	}

}
