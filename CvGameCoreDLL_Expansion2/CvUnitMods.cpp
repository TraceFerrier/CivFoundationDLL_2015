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

void CvUnitEntry::InitUnitMods()
{
	const char* strType = GetType();

	// Foundation Scientist mods
	if (strcmp(strType, "UNIT_FOUNDATION_SCIENTIST") == 0)
	{
		ModHandicapTypes handicap = GetHandicapType();
		if (handicap == eDeity)
		{
			m_iBaseBeakersTurnsToCount = 16;
			m_iMoves = 4;
		}
		else if (handicap == eImmortal)
		{
			m_iBaseBeakersTurnsToCount = 14;
			m_iMoves = 3;
		}
		else if (handicap == eEmperor)
		{
			m_iBaseBeakersTurnsToCount = 12;
			m_iMoves = 3;
		}
		else if (handicap == eKing)
		{
			m_iBaseBeakersTurnsToCount = 10;
			m_iMoves = 3;
		}
		else
		{
			m_iBaseBeakersTurnsToCount = 8;
			m_iMoves = 3;
		}
	}

	// Trader Mods
	else if (strcmp(strType, "UNIT_FOUNDATION_SCOUT") == 0)
	{
		ModHandicapTypes handicap = GetHandicapType();
		if (handicap == eDeity)
		{
			m_iMoves = 5;
			m_iCombat = 10;
			m_iXPValueDefense = 14;
		}
		else if (handicap == eImmortal)
		{
			m_iMoves = 4;
			m_iCombat = 9;
			m_iXPValueDefense = 13;
		}
		else if (handicap == eEmperor)
		{
			m_iMoves = 3;
			m_iCombat = 8;
			m_iXPValueDefense = 12;
		}
		else if (handicap == eKing)
		{
			m_iMoves = 3;
			m_iCombat = 7;
			m_iXPValueDefense = 11;
		}
		else
		{
			m_iMoves = 3;
			m_iCombat = 6;
			m_iXPValueDefense = 10;
		}
	}

	// Trader Mods
	else if (strcmp(strType, "UNIT_SECOND_FOUNDATIONER") == 0)
	{
		ModHandicapTypes handicap = GetHandicapType();
		if (handicap == eDeity)
		{
			m_iMoves = 5;
			m_iWorkRate = 200;
		}
		else if (handicap == eImmortal)
		{
			m_iMoves = 4;
			m_iWorkRate = 180;
		}
		else if (handicap == eEmperor)
		{
			m_iMoves = 3;
			m_iWorkRate = 160;
		}
		else if (handicap == eKing)
		{
			m_iMoves = 3;
			m_iWorkRate = 150;
		}
		else
		{
			m_iMoves = 3;
			m_iWorkRate = 140;
		}
	}

}


