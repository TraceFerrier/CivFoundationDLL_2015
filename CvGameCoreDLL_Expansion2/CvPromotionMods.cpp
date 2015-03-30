#include "CvGameCoreDLLPCH.h"
#include "CvModUtils.h"

void CvPromotionEntry::ApplyPromotionMods()
{
	const int DeityHighAttackMod = -55;
	const int ImmortalHighAttackMod = -45;
	const int EmperorHighAttackMod = -30;
	const int KingHighAttackMod = -20;
	const int StandardHighAttackMod = -15;

	const int DeityMediumAttackMod = -40;
	const int ImmortalMediumAttackMod = -30;
	const int EmperorMediumAttackMod = -20;
	const int KingMediumAttackMod = -15;
	const int StandardMediumAttackMod = -10;

	const int DeityLowAttackMod = -20;
	const int ImmortalLowAttackMod = -15;
	const int EmperorLowAttackMod = -10;
	const int KingLowAttackMod = -5;
	const int StandardLowAttackMod = -5;

	///// High
	const int DeityHighFriendDefenseMod = 40;
	const int DeityHighFriendAttackMod = 20;

	const int ImmortalHighFriendDefenseMod = 30;
	const int ImmortalHighFriendAttackMod = 15;

	const int EmperorHighFriendDefenseMod = 20;
	const int EmperorHighFriendAttackMod = 10;

	const int StandardHighFriendDefenseMod = 10;
	const int StandardHighFriendAttackMod = 5;

	///// Medium
	const int DeityMediumFriendDefenseMod = 20;
	const int DeityMediumFriendAttackMod = 10;

	const int ImmortalMediumFriendDefenseMod = 15;
	const int ImmortalMediumFriendAttackMod = 10;

	const int EmperorMediumFriendDefenseMod = 10;
	const int EmperorMediumFriendAttackMod = 5;

	const int StandardMediumFriendDefenseMod = 5;
	const int StandardMediumFriendAttackMod = 0;

	///// Low
	const int DeityLowFriendDefenseMod = 10;
	const int DeityLowFriendAttackMod = 5;

	const int ImmortalLowFriendDefenseMod = 10;
	const int ImmortalLowFriendAttackMod = 5;

	const int EmperorLowFriendDefenseMod = 5;
	const int EmperorLowFriendAttackMod = 5;

	const int StandardLowFriendDefenseMod = 5;
	const int StandardLowFriendAttackMod = 0;

	///// Advanced Shield
	const int DeityAdvancedShieldMod = 45;
	const int ImmortalAdvancedShieldMod = 35;
	const int EmperorAdvancedShieldMod = 25;
	const int StandardAdvancedShieldMod = 15;

	///// Mentalic Shield
	const int DeityMentalicShieldMod = 50;
	const int ImmortalMentalicShieldMod = 40;
	const int EmperorMentalicShieldMod = 30;
	const int StandardMentalicShieldMod = 20;

	ModHandicapTypes handicap = GetHandicapType();
	if(strcmp(GetType(), "PROMOTION_SECOND_FOUNDATION_ATTACK_SUPPRESS_HIGH") == 0)
	{
		if (handicap == eDeity)
		{
			m_iOpenRangedAttackMod = DeityHighAttackMod;
			m_iRoughRangedAttackMod = DeityHighAttackMod;
			m_iAttackMod = DeityHighAttackMod;
			m_iCityAttackPercent = DeityHighAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eImmortal)
		{
			m_iOpenRangedAttackMod = ImmortalHighAttackMod;
			m_iRoughRangedAttackMod = ImmortalHighAttackMod;
			m_iAttackMod = ImmortalHighAttackMod;
			m_iCityAttackPercent = ImmortalHighAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eEmperor)
		{
			m_iOpenRangedAttackMod = EmperorHighAttackMod;
			m_iRoughRangedAttackMod = EmperorHighAttackMod;
			m_iAttackMod = EmperorHighAttackMod;
			m_iCityAttackPercent = EmperorHighAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eKing)
		{
			m_iOpenRangedAttackMod = KingHighAttackMod;
			m_iRoughRangedAttackMod = KingHighAttackMod;
			m_iAttackMod = KingHighAttackMod;
			m_iCityAttackPercent = KingHighAttackMod;
			m_iMovesChange = -1;
		}
		else
		{
			m_iOpenRangedAttackMod = StandardHighAttackMod;
			m_iRoughRangedAttackMod = StandardHighAttackMod;
			m_iAttackMod = StandardHighAttackMod;
			m_iCityAttackPercent = StandardHighAttackMod;
			m_iMovesChange = -1;
		}
	}
	else if(strcmp(GetType(), "PROMOTION_SECOND_FOUNDATION_ATTACK_SUPPRESS_MEDIUM") == 0)
	{
		if (handicap == eDeity)
		{
			m_iOpenRangedAttackMod = DeityMediumAttackMod;
			m_iRoughRangedAttackMod = DeityMediumAttackMod;
			m_iAttackMod = DeityMediumAttackMod;
			m_iCityAttackPercent = DeityMediumAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eImmortal)
		{
			m_iOpenRangedAttackMod = ImmortalMediumAttackMod;
			m_iRoughRangedAttackMod = ImmortalMediumAttackMod;
			m_iAttackMod = ImmortalMediumAttackMod;
			m_iCityAttackPercent = ImmortalMediumAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eEmperor)
		{
			m_iOpenRangedAttackMod = EmperorMediumAttackMod;
			m_iRoughRangedAttackMod = EmperorMediumAttackMod;
			m_iAttackMod = EmperorMediumAttackMod;
			m_iCityAttackPercent = EmperorMediumAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eKing)
		{
			m_iOpenRangedAttackMod = KingMediumAttackMod;
			m_iRoughRangedAttackMod = KingMediumAttackMod;
			m_iAttackMod = KingMediumAttackMod;
			m_iCityAttackPercent = KingMediumAttackMod;
			m_iMovesChange = -1;
		}
		else
		{
			m_iOpenRangedAttackMod = StandardMediumAttackMod;
			m_iRoughRangedAttackMod = StandardMediumAttackMod;
			m_iAttackMod = StandardMediumAttackMod;
			m_iCityAttackPercent = StandardMediumAttackMod;
			m_iMovesChange = -1;
		}
	}
	else if(strcmp(GetType(), "PROMOTION_SECOND_FOUNDATION_ATTACK_SUPPRESS_LOW") == 0)
	{
		if (handicap == eDeity)
		{
			m_iOpenRangedAttackMod = DeityLowAttackMod;
			m_iRoughRangedAttackMod = DeityLowAttackMod;
			m_iAttackMod = DeityLowAttackMod;
			m_iCityAttackPercent = DeityLowAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eImmortal)
		{
			m_iOpenRangedAttackMod = ImmortalLowAttackMod;
			m_iRoughRangedAttackMod = ImmortalLowAttackMod;
			m_iAttackMod = ImmortalLowAttackMod;
			m_iCityAttackPercent = ImmortalLowAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eEmperor)
		{
			m_iOpenRangedAttackMod = EmperorLowAttackMod;
			m_iRoughRangedAttackMod = EmperorLowAttackMod;
			m_iAttackMod = EmperorLowAttackMod;
			m_iCityAttackPercent = EmperorLowAttackMod;
			m_iMovesChange = -1;
		}
		else if (handicap == eKing)
		{
			m_iOpenRangedAttackMod = KingLowAttackMod;
			m_iRoughRangedAttackMod = KingLowAttackMod;
			m_iAttackMod = KingLowAttackMod;
			m_iCityAttackPercent = KingLowAttackMod;
			m_iMovesChange = -1;
		}
		else
		{
			m_iOpenRangedAttackMod = StandardLowAttackMod;
			m_iRoughRangedAttackMod = StandardLowAttackMod;
			m_iAttackMod = StandardLowAttackMod;
			m_iCityAttackPercent = StandardLowAttackMod;
			m_iMovesChange = -1;
		}
	}

	else if(strcmp(GetType(), "PROMOTION_SECOND_FOUNDATION_DEFENSE_HIGH") == 0)
	{
		if (handicap == eDeity)
		{
			m_iDefenseMod = DeityHighFriendDefenseMod;
			m_iRangedDefenseMod = DeityHighFriendDefenseMod;
			m_iOpenRangedAttackMod = DeityHighFriendAttackMod;
			m_iRoughRangedAttackMod = DeityHighFriendAttackMod;
			m_iAttackMod = DeityHighFriendAttackMod;
		}
		else if (handicap == eImmortal)
		{
			m_iDefenseMod = ImmortalHighFriendDefenseMod;
			m_iRangedDefenseMod = ImmortalHighFriendDefenseMod;
			m_iOpenRangedAttackMod = ImmortalHighFriendAttackMod;
			m_iRoughRangedAttackMod = ImmortalHighFriendAttackMod;
			m_iAttackMod = ImmortalHighFriendAttackMod;
		}
		else if (handicap == eEmperor)
		{
			m_iDefenseMod = EmperorHighFriendDefenseMod;
			m_iRangedDefenseMod = EmperorHighFriendDefenseMod;
			m_iOpenRangedAttackMod = EmperorHighFriendAttackMod;
			m_iRoughRangedAttackMod = EmperorHighFriendAttackMod;
			m_iAttackMod = EmperorHighFriendAttackMod;
		}
		else
		{
			m_iDefenseMod = StandardHighFriendDefenseMod;
			m_iRangedDefenseMod = StandardHighFriendDefenseMod;
			m_iOpenRangedAttackMod = StandardHighFriendAttackMod;
			m_iRoughRangedAttackMod = StandardHighFriendAttackMod;
			m_iAttackMod = StandardHighFriendAttackMod;
		}
	}

	else if(strcmp(GetType(), "PROMOTION_SECOND_FOUNDATION_DEFENSE_MEDIUM") == 0)
	{
		if (handicap == eDeity)
		{
			m_iDefenseMod = DeityMediumFriendDefenseMod;
			m_iRangedDefenseMod = DeityMediumFriendDefenseMod;
			m_iOpenRangedAttackMod = DeityMediumFriendAttackMod;
			m_iRoughRangedAttackMod = DeityMediumFriendAttackMod;
			m_iAttackMod = DeityMediumFriendAttackMod;
		}
		else if (handicap == eImmortal)
		{
			m_iDefenseMod = ImmortalMediumFriendDefenseMod;
			m_iRangedDefenseMod = ImmortalMediumFriendDefenseMod;
			m_iOpenRangedAttackMod = ImmortalMediumFriendAttackMod;
			m_iRoughRangedAttackMod = ImmortalMediumFriendAttackMod;
			m_iAttackMod = ImmortalMediumFriendAttackMod;
		}
		else if (handicap == eEmperor)
		{
			m_iDefenseMod = EmperorMediumFriendDefenseMod;
			m_iRangedDefenseMod = EmperorMediumFriendDefenseMod;
			m_iOpenRangedAttackMod = EmperorMediumFriendAttackMod;
			m_iRoughRangedAttackMod = EmperorMediumFriendAttackMod;
			m_iAttackMod = EmperorMediumFriendAttackMod;
		}
		else
		{
			m_iDefenseMod = StandardMediumFriendDefenseMod;
			m_iRangedDefenseMod = StandardMediumFriendDefenseMod;
			m_iOpenRangedAttackMod = StandardMediumFriendAttackMod;
			m_iRoughRangedAttackMod = StandardMediumFriendAttackMod;
			m_iAttackMod = StandardMediumFriendAttackMod;
		}
	}

	else if(strcmp(GetType(), "PROMOTION_SECOND_FOUNDATION_DEFENSE_LOW") == 0)
	{
		if (handicap == eDeity)
		{
			m_iDefenseMod = DeityLowFriendDefenseMod;
			m_iRangedDefenseMod = DeityLowFriendDefenseMod;
			m_iOpenRangedAttackMod = DeityLowFriendAttackMod;
			m_iRoughRangedAttackMod = DeityLowFriendAttackMod;
			m_iAttackMod = DeityLowFriendAttackMod;
		}
		else if (handicap == eImmortal)
		{
			m_iDefenseMod = ImmortalLowFriendDefenseMod;
			m_iRangedDefenseMod = ImmortalLowFriendDefenseMod;
			m_iOpenRangedAttackMod = ImmortalLowFriendAttackMod;
			m_iRoughRangedAttackMod = ImmortalLowFriendAttackMod;
			m_iAttackMod = ImmortalLowFriendAttackMod;
		}
		else if (handicap == eEmperor)
		{
			m_iDefenseMod = EmperorLowFriendDefenseMod;
			m_iRangedDefenseMod = EmperorLowFriendDefenseMod;
			m_iOpenRangedAttackMod = EmperorLowFriendAttackMod;
			m_iRoughRangedAttackMod = EmperorLowFriendAttackMod;
			m_iAttackMod = EmperorLowFriendAttackMod;
		}
		else
		{
			m_iDefenseMod = StandardLowFriendDefenseMod;
			m_iRangedDefenseMod = StandardLowFriendDefenseMod;
			m_iOpenRangedAttackMod = StandardLowFriendAttackMod;
			m_iRoughRangedAttackMod = StandardLowFriendAttackMod;
			m_iAttackMod = StandardLowFriendAttackMod;
		}
	}

	else if(strcmp(GetType(), "PROMOTION_FOUNDATION_ADVANCED_SHIELD") == 0)
	{
		if (handicap == eDeity)
		{
			m_iDefenseMod = DeityAdvancedShieldMod;
			m_iRangedDefenseMod = DeityAdvancedShieldMod;
		}
		else if (handicap == eImmortal)
		{
			m_iDefenseMod = ImmortalAdvancedShieldMod;
			m_iRangedDefenseMod = ImmortalAdvancedShieldMod;
		}
		else if (handicap == eEmperor)
		{
			m_iDefenseMod = EmperorAdvancedShieldMod;
			m_iRangedDefenseMod = EmperorAdvancedShieldMod;
		}
		else
		{
			m_iDefenseMod = StandardAdvancedShieldMod;
			m_iRangedDefenseMod = StandardAdvancedShieldMod;
		}
	}

	else if(strcmp(GetType(), "PROMOTION_FOUNDATION_MENTALIC_SHIELD") == 0)
	{
		if (handicap == eDeity)
		{
			m_iDefenseMod = DeityMentalicShieldMod;
			m_iRangedDefenseMod = DeityMentalicShieldMod;
		}
		else if (handicap == eImmortal)
		{
			m_iDefenseMod = ImmortalMentalicShieldMod;
			m_iRangedDefenseMod = ImmortalMentalicShieldMod;
		}
		else if (handicap == eEmperor)
		{
			m_iDefenseMod = EmperorMentalicShieldMod;
			m_iRangedDefenseMod = EmperorMentalicShieldMod;
		}
		else
		{
			m_iDefenseMod = StandardMentalicShieldMod;
			m_iRangedDefenseMod = StandardMentalicShieldMod;
		}
	}

	else if(strcmp(GetType(), "PROMOTION_FOUNDATION_VISIBILITY") == 0)
	{
		if (handicap == eDeity)
		{
			m_iVisibilityChange = 2;
		}
		else if (handicap == eImmortal)
		{
			m_iVisibilityChange = 1;
		}
		else if (handicap == eEmperor)
		{
			m_iVisibilityChange = 1;
		}
		else
		{
			m_iVisibilityChange = 0;
		}
	}

}