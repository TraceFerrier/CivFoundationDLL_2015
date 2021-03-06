enum ModHandicapTypes
{
	eNoHandicap = -1,
	eSettler,
	eChieftain,
	eWarlord,
	ePrince,
	eKing,
	eEmperor,
	eImmortal,
	eDeity,
};

const int TradingSuppliesPerTurn = 3;

ModHandicapTypes GetHandicapType();
CivilizationTypes GetFoundationCivilizationType();
ImprovementTypes GetFoundationTradingDepotType();
UnitClassTypes GetGreatMerchantUnitClassType();
UnitTypes GetFoundationTraderType();
UnitTypes GetFoundationScientistType();