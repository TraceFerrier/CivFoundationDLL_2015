#include "CvGameCoreDLLPCH.h"
#include "CvModUtils.h"

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

