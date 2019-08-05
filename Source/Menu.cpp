#pragma once
#include "stdafx.h"
Object latestObj;
vector<int> MapModObjs;
bool stream = false;
float MoveX = 0.5f;
float MoveZ = 0.5f;

char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}
void notifyleft(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}

Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

static char* Boats1[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};
static char* Commercial1[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
};
static char* Compacts1[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
};
static char* Coupes1[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
};
static char* Cycles1[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};
static char* Emergency1[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
};
static char* Helicopters1[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
};
static char* Industrial1[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};
static char* Military1[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
};
static char* Motorcycles1[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2"
};
static char* Muscle1[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
};
static char* OffRoad1[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5"
};
static char* Planes1[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
};
static char* Sedans1[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
};
static char* Service1[] = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER",
};
static char* Sports1[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON"
};
static char* SportsClassics1[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2",
};
static char* Super1[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1"
};
static char* SUVs1[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
};
static char* Trailer1[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
};
static char* Trains1[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};
static char* Utility1[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};
static char* Vans1[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};
static char* Doomsday1[] = {
	"autarch", "avenger", "barrage", "chernobog", "comet4", "comet5",
	"deluxo", "gt500", "hermes", "hustler", "kamacho","khanjali",
	"neon", "pariah", "raiden", "revolter", "riata", "riot2", "savestra",
	"sc1", "sentinel3", "streiter", "stromberg", "thruster", "viseris",
	"volatol", "yosemite", "z190"
};
static char* Supersports1[] = {
	"michelli", "jester3", "flashgt", "tezeract", "entity2", "cheburek",
	"tyrant", "hotring", "ellie", "fagaloa", "gb200", "issi3", "taipan",
	"dominator3", "caracara", "seasparrow",
};
char* pedModels[] = {
	"A_C_Boar","A_C_Chickenhawk","A_C_Chimp","A_C_Chop","A_C_Cormorant","A_C_Cow","A_C_Coyote","A_C_Crow","A_C_Deer","A_C_Fish","A_C_Hen","A_C_Husky","A_C_MtLion","A_C_Pig","A_C_Pigeon","A_C_Rat","A_C_Retriever",
	"A_C_Rhesus","A_C_Rottweiler","A_C_Seagull","A_C_SharkTiger","A_C_shepherd","A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02",
	"A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Tennis_01","A_F_Y_Topless_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01","A_M_M_ACult_01","A_M_M_AfriAmer_01","A_M_M_Beach_01","A_M_M_Beach_02","A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
	"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
	"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
	"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
	"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
	"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02","A_M_Y_Beach_01","A_M_Y_Beach_02","A_M_Y_Beach_03","A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02","A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03","A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02",
	"A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02","A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01","A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02","A_M_Y_MusclBeac_01",
	"A_M_Y_MusclBeac_02","A_M_Y_Polynesian_01","A_M_Y_RoadCyc_01","A_M_Y_Runner_01","A_M_Y_Runner_02","A_M_Y_Salton_01","A_M_Y_Skater_01","A_M_Y_Skater_02","A_M_Y_SouCent_01","A_M_Y_SouCent_02","A_M_Y_SouCent_03","A_M_Y_SouCent_04",
	"A_M_Y_StBla_01","A_M_Y_StBla_02","A_M_Y_StLat_01","A_M_Y_StWhi_01","A_M_Y_StWhi_02","A_M_Y_Sunbathe_01","A_M_Y_Surfer_01","A_M_Y_VinDouche_01","A_M_Y_Vinewood_01","A_M_Y_Vinewood_02","A_M_Y_Vinewood_03","A_M_Y_Vinewood_04",
	"A_M_Y_Yoga_01","CSB_Abigail","CSB_Anita","CSB_Anton","CSB_BallasOG","CSB_Bride","CSB_BurgerDrug","CSB_Car3guy1","CSB_Car3guy2","CSB_Chef","CSB_Chin_goon","CSB_Cletus","CSB_Cop","CSB_Customer","CSB_Denise_friend",
	"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","CSB_PornDudes","CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang",
	"CSB_Ramp_hic","CSB_Ramp_hipster","CSB_Ramp_marine","CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_Stripper_01","CSB_Stripper_02","CSB_Tonya","CSB_TrafficWarden","CS_AmandaTownley","CS_Andreas",
	"cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
	"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
	"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
	"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
	"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01","G_M_M_ArmBoss_01",
	"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
	"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
	"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
	"HC_Driver","HC_Gunman","HC_Hacker","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
	"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
	"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
	"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
	"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
	"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
	"IG_TylerDix","IG_Wade","IG_Zimbor","MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
	"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero","slod_human","slod_large_quadped","slod_small_quadped","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH",
	"S_F_M_SweatShop_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01","S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_FIBOffice_01","S_M_M_FIBOffice_02","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
	"S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
	"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
	"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
	"S_M_Y_Pilot_01","S_M_Y_PrisMuscl_01","S_M_Y_Prisoner_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_Swat_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
	"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
	"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
	"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
	"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_FIBMugger_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
	"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01",
	"U_M_Y_Zombie_01",
};

void wait() {
	WAIT(0);
}
void main() {

	while (true) {
		Menu::Checks::Keys();
		Features::UpdateLoop();

		switch (Menu::Settings::currentMenu) {


		case mainmenu:
		{
			Menu::Title("Skidus");
			Menu::Subtitle("SKiddddd.XYZ");
			Menu::MenuOption("Self Options", self);
			Menu::MenuOption("Teleport Options", tpop);
			Menu::MenuOption("Weapon Options", weaponop);
			Menu::MenuOption("Vehicle Spawner", vehspawner);
			Menu::MenuOption("Vehicle Options", vehicleop);
			Menu::MenuOption("Protections", protect);
			Menu::MenuOption("Network Options", onlinemenu_playerlist);
			Menu::MenuOption("Money Options", moneyop);
			Menu::MenuOption("Recovery Options", recover);
			Menu::MenuOption("Misc Options", miscop);
			Menu::MenuOption("Settings", settings);
			Menu::MenuOption("Credits", Credits);

					
		}
		break;
#pragma endregion
#pragma region Online Menu
		case onlinemenu_playerlist:
		{
			Menu::Title("Network Options");
			Menu::Subtitle("PLAYERS");
			Menu::MenuOption("All Players", allplayerop);
			for (int i = 0; i < 32; ++i) {
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
					Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
				}
			}
		}
		break;
#pragma endregion
#pragma region object spawner
		case objectspawner:
		{
			Menu::Title("Object Spawner");
			Menu::Subtitle("SPAWN OBJECT");
			Menu::MenuOption("Prop List", objectlist);
			if (Menu::Option("Input Object")) {
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Object custom = SpawnObject(CharKeyboard(), pos);
				if (custom != -1) {
					latestObj = custom;
					Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
				}
				else
					notifyMap("~b~Error Invalid object");
			}
			if (Menu::Option("Delete Last Object")) {
				RequestControlOfEnt(latestObj);
				ENTITY::DELETE_ENTITY(&latestObj);
				MapModObjs.pop_back();
			}
			if (Menu::Float("X", MoveX, 0.f, 1000000000.f, 1.f)) {
				RequestControlOfEnt(latestObj);
				Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
				Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
				ENTITY::SET_ENTITY_COORDS(latestObj, MoveX, objCoords.y, objCoords.z, objRot.x, objRot.y, objRot.z, false);
			}
			if (Menu::Float("Z", MoveZ, 0.f, 1000000000.f, 1.f)) {
				RequestControlOfEnt(latestObj);
				Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
				Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
				ENTITY::SET_ENTITY_COORDS(latestObj, objCoords.x, MoveZ, objCoords.z, objRot.x, objRot.y, objRot.z, false);
			}
		}
		break;
#pragma endregion
#pragma region Vehicles
		case vehicleop:
		{
			Menu::Title("Vehicle Options");
			Menu::Subtitle("VEHICLE");
			Menu::Break("VEHICLE WEAPONS");
			Menu::Option("SHOOT WITH +");
			Menu::Toggle("Shoot Rockets", Features::ShootR, [] { Features::ShootRocket(Features::ShootR); });
			Menu::Toggle("Shoot FireWorks", Features::ShootT, [] { Features::ShootTanks(Features::ShootT); });
			Menu::Toggle("Shoot Tank Rounds", Features::ShootTankR, [] { Features::ShootTankRounds(Features::ShootTankR); });
			Menu::Toggle("Shoot Balls", Features::ShootBall, [] { Features::ShootBalls(Features::ShootBall); });
			Menu::Toggle("Shoot Mini Gun", Features::ShootMini, [] { Features::ShootMiniGun(Features::ShootMini); });
			Menu::Break("VEHICLE MENU");
			if (Menu::Option("Custom Plate")) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, CharKeyboard());
			}
			Menu::Toggle("Drift Mode", Features::Drift, [] { Features::DriftMode(Features::Drift); });
			Menu::Toggle("Engine Allways On", Features::enginealwaysonbool, [] { Features::enginealwayson(Features::enginealwaysonbool); });
			Menu::Toggle("Horn Boost", Features::boostbool, [] { Features::carboost(Features::boostbool); });
			Menu::Toggle("Drive on Water", Features::dowbool, [] { Features::DriveOnWater(Features::dowbool); });
			Menu::Toggle("Flying Car", Features::fcbool, [] { Features::FlyingCarLoop(Features::fcbool); });
			Menu::Toggle("Rainbow Tire Smoke", Features::Rainb, [] { Features::Rainbow(Features::Rainb); });
			Menu::Toggle("Rainbow Neons", Features::Rneon, [] { Features::RainbowNeon(Features::Rneon); });
			if (Menu::Option("Fix Car")) {
				uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				VEHICLE::SET_VEHICLE_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
			}
			if (Menu::Option("Max Upgrade Car")) {
				Features::maxvehicle();
			}
			if (Menu::Option("Flip Car")) {
				Features::flipup();
			}
			if (Menu::Option("Open Doors")) {
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 2, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 3, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 4, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 5, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 6, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 7, true, false);
			}
			if (Menu::Option("Close Doors")) {
				VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
			}
		}
		break;
#pragma endregion
#pragma region Vehicles
		case miscop:
		{
			Menu::Title("Miscellanous");
			Menu::Subtitle("MISC OPTIONS");
			Menu::MenuOption("Animations", anim);
			Menu::MenuOption("Scenarios", senas);
			Menu::Break("OBJECTS");
			Menu::MenuOption("Map Mods", exploitramp);
			Menu::MenuOption("Object Spawner", objectspawner);
			Menu::Break("WEATHER OPTIONS");
			if (Menu::Option("Sun")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); }
			if (Menu::Option("Rain")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing"); }
			if (Menu::Option("Snow")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight"); }
			if (Menu::Option("Thunder")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); }
			if (Menu::Option("Blizzard")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); }
			if (Menu::Option("Overcast")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); }
			if (Menu::Option("Foggy")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy"); }
			if (Menu::Option("Smog")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog"); }
			if (Menu::Option("Clouds")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); }



		}
		break;
#pragma endregion
#pragma region object list
		case objectlist:
		{
			Menu::Title("Prop List");
			Menu::Subtitle("OBJECTS");
			Menu::Option("PROP_MP_RAMP_03");
			Menu::Option("prop_a4_pile_01");
			Menu::Option("prop_a4_sheet_01");
			Menu::Option("prop_a4_sheet_02");
			Menu::Option("prop_a4_sheet_03");
			Menu::Option("prop_a4_sheet_03");
			Menu::Option("prop_a4_sheet_04");
			Menu::Option("prop_a4_sheet_05");
			Menu::Option("prop_abat_roller_static");
			Menu::Option("prop_abat_slide");
			Menu::Option("prop_acc_guitar_01");
			Menu::Option("prop_acc_guitar_01_d1");
			Menu::Option("prop_aerial_01a");
			Menu::Option("prop_aerial_01b");
			Menu::Option("prop_aerial_01c");
			Menu::Option("prop_aerial_01d");
			Menu::Option("prop_afsign_amun");
			Menu::Option("prop_afsign_vbike");
			Menu::Option("prop_agave_01");
			Menu::Option("prop_agave_02");
			Menu::Option("prop_aiprort_sign_01");
			Menu::Option("prop_aiprort_sign_02");
			Menu::Option("prop_aircon_l_01");
			Menu::Option("prop_aircon_l_02");
			Menu::Option("prop_aircon_l_03");
			Menu::Option("prop_aircon_l_03");
			Menu::Option("prop_aircon_l_04");
			Menu::Option("prop_aircon_m_09");
			Menu::Option("prop_aircon_s_01a");
			Menu::Option("prop_aircon_s_02a");
			Menu::Option("prop_aircon_s_02b");
			Menu::Option("prop_aircon_s_03a");
			Menu::Option("prop_aircon_s_03b");
			Menu::Option("prop_aircon_s_04a");
			Menu::Option("prop_aircon_s_05a");
			Menu::Option("prop_aircon_s_06a");
			Menu::Option("prop_aircon_s_07a");
			Menu::Option("prop_aircon_s_07b");
			Menu::Option("prop_airhockey_01");
			Menu::Option("prop_air_bagloader");
			Menu::Option("prop_air_bagloader2");
			Menu::Option("prop_air_barrier");
			Menu::Option("prop_air_bench_01");
			Menu::Option("prop_air_bench_02");
			Menu::Option("prop_air_bigradar_l1");
			Menu::Option("prop_air_bigradar_l2");
			Menu::Option("prop_air_bigradar_slod");
			Menu::Option("prop_air_blastfence_01");
			Menu::Option("prop_air_blastfence_02");
			Menu::Option("prop_air_bridge01");
			Menu::Option("prop_air_bridge02");
			Menu::Option("prop_air_cargoloader_01");
			Menu::Option("prop_air_cargo_01a");
			Menu::Option("prop_air_cargo_01b");
			Menu::Option("prop_air_cargo_01c");
			Menu::Option("prop_air_cargo_02a");
			Menu::Option("prop_air_cargo_02b");
			Menu::Option("prop_air_cargo_03a");
			Menu::Option("prop_air_cargo_04a");
			Menu::Option("prop_air_cargo_04b");
			Menu::Option("prop_air_cargo_04c");
			Menu::Option("prop_air_chock_01");
			Menu::Option("prop_air_chock_03");
			Menu::Option("prop_air_chock_04");
			Menu::Option("prop_air_fueltrail1");
			Menu::Option("prop_air_fueltrail2");
			Menu::Option("prop_air_gasbogey_01");
			Menu::Option("prop_air_generator_01");
			Menu::Option("prop_air_generator_03");
			Menu::Option("prop_air_hoc_paddle_01");
			Menu::Option("prop_air_hoc_paddle_02");
			Menu::Option("prop_air_lights_01a");
			Menu::Option("prop_air_lights_01b");
			Menu::Option("prop_air_lights_03a");
			Menu::Option("prop_air_luggtrolley");
			Menu::Option("prop_air_mast_01");
			Menu::Option("prop_air_mast_02");
			Menu::Option("prop_air_monhut_01");
			Menu::Option("prop_air_monhut_02");
			Menu::Option("prop_air_monhut_03");
			Menu::Option("prop_air_propeller01");
			Menu::Option("prop_air_radar_01");
			Menu::Option("prop_air_stair_01");
			Menu::Option("prop_air_stair_02");
			Menu::Option("prop_air_stair_03");
			Menu::Option("prop_air_stair_04a");
			Menu::Option("prop_air_stair_04b");
			Menu::Option("prop_air_towbar_01");
			Menu::Option("prop_air_towbar_02");
			Menu::Option("prop_air_towbar_03");
			Menu::Option("prop_air_trailer_4a");
			Menu::Option("prop_air_trailer_4b");
			Menu::Option("prop_air_trailer_4c");
			Menu::Option("prop_air_watertank1");
			Menu::Option("prop_air_watertank2");
			Menu::Option("prop_air_windsock_base");
			Menu::Option("prop_air_woodsteps");
			Menu::Option("prop_alarm_01");
			Menu::Option("prop_alarm_02");
			Menu::Option("prop_alien_egg_01");
			Menu::Option("prop_aloevera_01");
			Menu::Option("prop_amanda_note_01");
			Menu::Option("prop_amanda_note_01b");
			Menu::Option("prop_amb_40oz_02");
			Menu::Option("prop_amb_40oz_03");
			Menu::Option("prop_amb_beer_bottle");
			Menu::Option("prop_amb_ciggy_01");
			Menu::Option("prop_amb_donut");
			Menu::Option("prop_amb_handbag_01");
			Menu::Option("prop_amb_phone");
			Menu::Option("prop_amp_01");
			Menu::Option("prop_am_box_wood_01");
			Menu::Option("prop_anim_cash_note");
			Menu::Option("prop_anim_cash_note_b");
			Menu::Option("prop_anim_cash_pile_01");
			Menu::Option("prop_anim_cash_pile_02");
			Menu::Option("prop_apple_box_01");
			Menu::Option("prop_apple_box_02");
			Menu::Option("prop_arcade_01");
			Menu::Option("prop_arcade_02");
			Menu::Option("prop_arc_blueprints_01");
			Menu::Option("prop_armchair_01");
			Menu::Option("prop_armenian_gate");
			Menu::Option("prop_armour_pickup");
			Menu::Option("prop_arm_gate_l");
			Menu::Option("prop_arm_wrestle_01");
			Menu::Option("prop_artgallery_02_dl");
			Menu::Option("prop_artgallery_02_dr");
			Menu::Option("prop_artgallery_dl");
			Menu::Option("prop_artgallery_dr");
			Menu::Option("prop_artifact_01");
			Menu::Option("prop_ashtray_01");
			Menu::Option("prop_asteroid_01");
			Menu::Option("prop_atm_02");
			Menu::Option("prop_atm_03");
			Menu::Option("prop_attache_case_01");
			Menu::Option("prop_aviators_01");
			Menu::Option("prop_a_base_bars_01");
			Menu::Option("prop_a_trailer_door_01");
			Menu::Option("prop_bahammenu");
			Menu::Option("prop_ballistic_shield");
			Menu::Option("prop_ballistic_shield_lod1");
			Menu::Option("prop_bandsaw_01");
			Menu::Option("prop_bank_shutter");
			Menu::Option("prop_bank_vaultdoor");
			Menu::Option("prop_barbell_01");
			Menu::Option("prop_barbell_02");
			Menu::Option("prop_barbell_100kg");
			Menu::Option("prop_barbell_10kg");
			Menu::Option("prop_barbell_20kg");
			Menu::Option("prop_barbell_30kg");
			Menu::Option("prop_barbell_40kg");
			Menu::Option("prop_barbell_50kg");
			Menu::Option("prop_barbell_60kg");
			Menu::Option("prop_barbell_80kg");
			Menu::Option("prop_barier_conc_01b");
			Menu::Option("prop_barier_conc_01c");
			Menu::Option("prop_barier_conc_02b");
			Menu::Option("prop_barier_conc_02c");
			Menu::Option("prop_barier_conc_03a");
			Menu::Option("prop_barier_conc_04a");
			Menu::Option("prop_barier_conc_05a");
			Menu::Option("prop_barier_conc_05b");
			Menu::Option("prop_barn_door_l");
			Menu::Option("prop_barn_door_r");
			Menu::Option("prop_barrachneon");
			Menu::Option("prop_barrel_01a");
			Menu::Option("prop_barrel_02a");
			Menu::Option("prop_barrel_02b");
			Menu::Option("prop_barrel_03a");
			Menu::Option("prop_barrel_03d");
			Menu::Option("prop_barrel_float_1");
			Menu::Option("prop_barrel_float_2");
			Menu::Option("prop_barriercrash_03");
			Menu::Option("prop_barriercrash_04");
			Menu::Option("prop_barrier_wat_01a");
			Menu::Option("prop_barrier_wat_03b");
			Menu::Option("prop_barrier_work01c");
			Menu::Option("prop_barry_table_detail");
			Menu::Option("prop_bar_coastbarr");
			Menu::Option("prop_bar_coastchamp");
			Menu::Option("prop_bar_coastdusc");
			Menu::Option("prop_bar_coastmount");
			Menu::Option("prop_bar_cooler_01");
			Menu::Option("prop_bar_cooler_03");
			Menu::Option("prop_bar_fridge_01");
			Menu::Option("prop_bar_fridge_02");
			Menu::Option("prop_bar_fridge_03");
			Menu::Option("prop_bar_fridge_04");
			Menu::Option("prop_bar_ice_01");
			Menu::Option("prop_bar_napkindisp");
			Menu::Option("prop_bar_pump_01");
			Menu::Option("prop_bar_pump_04");
			Menu::Option("prop_bar_pump_05");
			Menu::Option("prop_bar_pump_06");
			Menu::Option("prop_bar_pump_07");
			Menu::Option("prop_bar_pump_08");
			Menu::Option("prop_bar_pump_09");
			Menu::Option("prop_bar_pump_10");
			Menu::Option("prop_bar_sink_01");
			Menu::Option("prop_bar_stool_01");
			Menu::Option("prop_basejump_target_01");
			Menu::Option("prop_basketball_net");
			Menu::Option("prop_bath_dirt_01");
			Menu::Option("prop_battery_01");
			Menu::Option("prop_battery_02");
			Menu::Option("prop_bball_arcade_01");
			Menu::Option("prop_bbq_2");
			Menu::Option("prop_bbq_3");
			Menu::Option("prop_beachbag_01");
			Menu::Option("prop_beachbag_02");
			Menu::Option("prop_beachbag_03");
			Menu::Option("prop_beachbag_04");
			Menu::Option("prop_beachbag_05");
			Menu::Option("prop_beachbag_06");
			Menu::Option("prop_beachbag_combo_01");
			Menu::Option("prop_beachbag_combo_02");
			Menu::Option("prop_beachball_02");
			Menu::Option("prop_beachflag_le");
			Menu::Option("prop_beach_bars_01");
			Menu::Option("prop_beach_bars_02");
			Menu::Option("prop_beach_bbq");
			Menu::Option("prop_beach_dip_bars_01");
			Menu::Option("prop_beach_dip_bars_02");
			Menu::Option("prop_beach_fire");
			Menu::Option("prop_beach_lg_float");
			Menu::Option("prop_beach_lg_stretch");
			Menu::Option("prop_beach_lg_surf");
			Menu::Option("prop_beach_lotion_01");
			Menu::Option("prop_beach_lotion_02");
			Menu::Option("prop_beach_lotion_03");
			Menu::Option("prop_beach_punchbag");
			Menu::Option("prop_beach_rings_01");
			Menu::Option("prop_beach_sculp_01");
			Menu::Option("prop_beach_towel_02");
			Menu::Option("prop_beach_volball01");
			Menu::Option("prop_beach_volball02");
			Menu::Option("prop_beerneon");
			Menu::Option("prop_beer_bison");
			Menu::Option("prop_beer_box_01");
			Menu::Option("prop_beer_neon_01");
			Menu::Option("prop_beer_neon_02");
			Menu::Option("prop_beer_neon_03");
			Menu::Option("prop_beer_neon_04");
			Menu::Option("prop_beggers_sign_01");
			Menu::Option("prop_beggers_sign_02");
			Menu::Option("prop_beggers_sign_03");
			Menu::Option("prop_beggers_sign_04");
			Menu::Option("prop_bench_01b");
			Menu::Option("prop_bench_01c");
			Menu::Option("prop_bench_04");
			Menu::Option("prop_bench_05");
			Menu::Option("prop_bench_09");
			Menu::Option("prop_beta_tape");
			Menu::Option("prop_beware_dog_sign");
			Menu::Option("prop_bh1_03_gate_l");
			Menu::Option("prop_bh1_03_gate_r");
			Menu::Option("prop_bh1_08_mp_gar");
			Menu::Option("prop_bh1_09_mp_gar");
			Menu::Option("prop_bh1_09_mp_l");
			Menu::Option("prop_bh1_09_mp_r");
			Menu::Option("prop_bh1_16_display");
			Menu::Option("prop_bh1_44_door_01l");
			Menu::Option("prop_bh1_44_door_01r");
			Menu::Option("prop_bh1_48_backdoor_l");
			Menu::Option("prop_bh1_48_backdoor_r");
			Menu::Option("prop_bh1_48_gate_1");
			Menu::Option("prop_bhhotel_door_l");
			Menu::Option("prop_bhhotel_door_r");
			Menu::Option("prop_big_bag_01");
			Menu::Option("prop_big_clock_01");
			Menu::Option("prop_big_shit_01");
			Menu::Option("prop_big_shit_02");
			Menu::Option("prop_bikerack_2");
			Menu::Option("prop_bikini_disp_01");
			Menu::Option("prop_bikini_disp_02");
			Menu::Option("prop_bikini_disp_03");
			Menu::Option("prop_bikini_disp_04");
			Menu::Option("prop_bikini_disp_05");
			Menu::Option("prop_bikini_disp_06");
			Menu::Option("prop_billboard_01");
			Menu::Option("prop_billboard_02");
			Menu::Option("prop_billboard_03");
			Menu::Option("prop_billboard_04");
			Menu::Option("prop_billboard_05");
			Menu::Option("prop_billboard_06");
			Menu::Option("prop_billboard_07");
			Menu::Option("prop_billboard_08");
			Menu::Option("prop_billboard_09");
			Menu::Option("prop_billboard_09wall");
			Menu::Option("prop_billboard_10");
			Menu::Option("prop_billboard_11");
			Menu::Option("prop_billboard_12");
			Menu::Option("prop_billboard_13");
			Menu::Option("prop_billboard_14");
			Menu::Option("prop_billboard_15");
			Menu::Option("prop_billboard_16");
			Menu::Option("prop_billb_frame01a");
			Menu::Option("prop_billb_frame01b");
			Menu::Option("prop_billb_frame02a");
			Menu::Option("prop_billb_frame02b");
			Menu::Option("prop_billb_frame03a");
			Menu::Option("prop_billb_frame03b");
			Menu::Option("prop_billb_frame03c");
			Menu::Option("prop_billb_frame04a");
			Menu::Option("prop_billb_frame04b");
			Menu::Option("prop_binoc_01");
			Menu::Option("prop_bin_04a");
			Menu::Option("prop_bin_10a");
			Menu::Option("prop_bin_10b");
			Menu::Option("prop_bin_11a");
			Menu::Option("prop_bin_11b");
			Menu::Option("prop_bin_12a");
			Menu::Option("prop_bin_13a");
			Menu::Option("prop_bin_14a");
			Menu::Option("prop_bin_14b");
			Menu::Option("prop_bin_beach_01d");
			Menu::Option("prop_bin_delpiero");
			Menu::Option("prop_bin_delpiero_b");
			Menu::Option("prop_biolab_g_door");
			Menu::Option("prop_biotech_store");
			Menu::Option("prop_bison_winch");
			Menu::Option("prop_blackjack_01");
			Menu::Option("prop_bleachers_01");
			Menu::Option("prop_bleachers_02");
			Menu::Option("prop_bleachers_03");
			Menu::Option("prop_bleachers_04");
			Menu::Option("prop_bleachers_05");
			Menu::Option("prop_blox_spray");
			Menu::Option("prop_bmu_01");
			Menu::Option("prop_bmu_01_b");
			Menu::Option("prop_bmu_02");
			Menu::Option("prop_bmu_02_ld");
			Menu::Option("prop_bmu_02_ld_cab");
			Menu::Option("prop_bmu_02_ld_sup");
			Menu::Option("prop_bmu_track01");
			Menu::Option("prop_bmu_track02");
			Menu::Option("prop_bmu_track03");
			Menu::Option("prop_bodyarmour_02");
			Menu::Option("prop_bodyarmour_03");
			Menu::Option("prop_bodyarmour_04");
			Menu::Option("prop_bodyarmour_05");
			Menu::Option("prop_bodyarmour_06");
			Menu::Option("prop_bollard_01a");
			Menu::Option("prop_bollard_01b");
			Menu::Option("prop_bollard_01c");
			Menu::Option("prop_bollard_03a");
			Menu::Option("prop_bomb_01");
			Menu::Option("prop_bomb_01_s");
			Menu::Option("prop_bonesaw");
			Menu::Option("prop_bongos_01");
			Menu::Option("prop_bong_01");
			Menu::Option("prop_boogbd_stack_01");
			Menu::Option("prop_boogbd_stack_02");
			Menu::Option("prop_boogieboard_01");
			Menu::Option("prop_boogieboard_02");
			Menu::Option("prop_boogieboard_03");
			Menu::Option("prop_boogieboard_04");
			Menu::Option("prop_boogieboard_05");
			Menu::Option("prop_boogieboard_06");
			Menu::Option("prop_boogieboard_07");
			Menu::Option("prop_boogieboard_08");
			Menu::Option("prop_boogieboard_09");
			Menu::Option("prop_boogieboard_10");
			Menu::Option("prop_boombox_01");
			Menu::Option("prop_bottle_cap_01");
			Menu::Option("prop_bowling_ball");
			Menu::Option("prop_bowling_pin");
			Menu::Option("prop_bowl_crisps");
			Menu::Option("prop_boxcar5_handle");
			Menu::Option("prop_boxing_glove_01");
			Menu::Option("prop_boxpile_10a");
			Menu::Option("prop_boxpile_10b");
			Menu::Option("prop_box_ammo01a");
			Menu::Option("prop_box_ammo02a");
			Menu::Option("prop_box_ammo03a_set");
			Menu::Option("prop_box_ammo03a_set2");
			Menu::Option("prop_box_ammo04a");
			Menu::Option("prop_box_ammo05b");
			Menu::Option("prop_box_ammo07a");
			Menu::Option("prop_box_ammo07b");
			Menu::Option("prop_box_guncase_01a");
			Menu::Option("prop_box_guncase_02a");
			Menu::Option("prop_box_guncase_03a");
			Menu::Option("prop_box_tea01a");
			Menu::Option("prop_box_wood05a");
			Menu::Option("prop_box_wood05b");
			Menu::Option("prop_box_wood08a");
			Menu::Option("prop_breadbin_01");
			Menu::Option("prop_bread_rack_01");
			Menu::Option("prop_bread_rack_02");
			Menu::Option("prop_broken_cboard_p1");
			Menu::Option("prop_broken_cboard_p2");
			Menu::Option("prop_broken_cell_gate_01");
			Menu::Option("prop_broom_unit_01");
			Menu::Option("prop_bskball_01");
			Menu::Option("prop_bs_map_door_01");
			Menu::Option("prop_buckets_02");
			Menu::Option("prop_bucket_01a");
			Menu::Option("prop_bucket_01b");
			Menu::Option("prop_bucket_02a");
			Menu::Option("prop_buck_spade_01");
			Menu::Option("prop_buck_spade_02");
			Menu::Option("prop_buck_spade_03");
			Menu::Option("prop_buck_spade_04");
			Menu::Option("prop_buck_spade_05");
			Menu::Option("prop_buck_spade_06");
			Menu::Option("prop_buck_spade_07");
			Menu::Option("prop_buck_spade_08");
			Menu::Option("prop_buck_spade_09");
			Menu::Option("prop_buck_spade_10");
			Menu::Option("prop_bumper_01");
			Menu::Option("prop_bumper_02");
			Menu::Option("prop_bumper_03");
			Menu::Option("prop_bumper_04");
			Menu::Option("prop_bumper_05");
			Menu::Option("prop_bumper_06");
			Menu::Option("prop_bumper_car_01");
			Menu::Option("prop_burto_gate_01");
			Menu::Option("prop_bush_dead_02");
			Menu::Option("prop_bush_grape_01");
			Menu::Option("prop_bush_ivy_01_1m");
			Menu::Option("prop_bush_ivy_01_2m");
			Menu::Option("prop_bush_ivy_01_bk");
			Menu::Option("prop_bush_ivy_01_l");
			Menu::Option("prop_bush_ivy_01_pot");
			Menu::Option("prop_bush_ivy_01_r");
			Menu::Option("prop_bush_ivy_01_top");
			Menu::Option("prop_bush_ivy_02_1m");
			Menu::Option("prop_bush_ivy_02_2m");
			Menu::Option("prop_bush_ivy_02_l");
			Menu::Option("prop_bush_ivy_02_pot");
			Menu::Option("prop_bush_ivy_02_r");
			Menu::Option("prop_bush_ivy_02_top");
			Menu::Option("prop_bush_lrg_01");
			Menu::Option("prop_bush_lrg_01b");
			Menu::Option("prop_bush_lrg_01c");
			Menu::Option("prop_bush_lrg_01d");
			Menu::Option("prop_bush_lrg_01e");
			Menu::Option("prop_bush_lrg_02");
			Menu::Option("prop_bush_lrg_02b");
			Menu::Option("prop_bush_lrg_03");
			Menu::Option("prop_bush_lrg_03b");
			Menu::Option("prop_bush_lrg_04b");
			Menu::Option("prop_bush_lrg_04c");
			Menu::Option("prop_bush_lrg_04d");
			Menu::Option("prop_bush_med_01");
			Menu::Option("prop_bush_med_02");
			Menu::Option("prop_bush_med_03");
			Menu::Option("prop_bush_med_05");
			Menu::Option("prop_bush_med_06");
			Menu::Option("prop_bush_med_07");
			Menu::Option("prop_bush_neat_01");
			Menu::Option("prop_bush_neat_02");
			Menu::Option("prop_bush_neat_03");
			Menu::Option("prop_bush_neat_04");
			Menu::Option("prop_bush_neat_05");
			Menu::Option("prop_bush_neat_06");
			Menu::Option("prop_bush_neat_07");
			Menu::Option("prop_bush_neat_08");
			Menu::Option("prop_bush_ornament_01");
			Menu::Option("prop_bush_ornament_02");
			Menu::Option("prop_bush_ornament_03");
			Menu::Option("prop_bush_ornament_04");
			Menu::Option("prop_busker_hat_01");
			Menu::Option("prop_byard_bench01");
			Menu::Option("prop_byard_bench02");
			Menu::Option("prop_byard_block_01");
			Menu::Option("prop_byard_boat01");
			Menu::Option("prop_byard_boat02");
			Menu::Option("prop_byard_chains01");
			Menu::Option("prop_byard_dingy");
			Menu::Option("prop_byard_elecbox01");
			Menu::Option("prop_byard_elecbox02");
			Menu::Option("prop_byard_elecbox03");
			Menu::Option("prop_byard_elecbox04");
			Menu::Option("prop_byard_floatpile");
			Menu::Option("prop_byard_float_01");
			Menu::Option("prop_byard_float_01b");
			Menu::Option("prop_byard_float_02");
			Menu::Option("prop_byard_float_02b");
			Menu::Option("prop_byard_hoist");
			Menu::Option("prop_byard_hoist_2");
			Menu::Option("prop_byard_hoses01");
			Menu::Option("prop_byard_hoses02");
			Menu::Option("prop_byard_ladder01");
			Menu::Option("prop_byard_machine01");
			Menu::Option("prop_byard_machine02");
			Menu::Option("prop_byard_machine03");
			Menu::Option("prop_byard_motor_01");
			Menu::Option("prop_byard_motor_02");
			Menu::Option("prop_byard_motor_03");
			Menu::Option("prop_byard_net02");
			Menu::Option("prop_byard_phone");
			Menu::Option("prop_byard_pipes01");
			Menu::Option("prop_byard_pipe_01");
			Menu::Option("prop_byard_planks01");
			Menu::Option("prop_byard_pulley01");
			Menu::Option("prop_byard_rack");
			Menu::Option("prop_byard_ramp");
			Menu::Option("prop_byard_rampold");
			Menu::Option("prop_byard_rowboat1");
			Menu::Option("prop_byard_rowboat2");
			Menu::Option("prop_byard_rowboat3");
			Menu::Option("prop_byard_rowboat4");
			Menu::Option("prop_byard_rowboat5");
			Menu::Option("prop_byard_scfhold01");
			Menu::Option("prop_byard_sleeper01");
			Menu::Option("prop_byard_sleeper02");
			Menu::Option("prop_byard_steps_01");
			Menu::Option("prop_byard_tank_01");
			Menu::Option("prop_byard_trailer01");
			Menu::Option("prop_byard_trailer02");
			Menu::Option("prop_b_board_blank");
			Menu::Option("prop_c4_final");
			Menu::Option("prop_c4_final_green");
			Menu::Option("prop_cabinet_01");
			Menu::Option("prop_cabinet_01b");
			Menu::Option("prop_cabinet_02b");
			Menu::Option("prop_cablespool_01a");
			Menu::Option("prop_cablespool_01b");
			Menu::Option("prop_cablespool_02");
			Menu::Option("prop_cablespool_03");
			Menu::Option("prop_cablespool_04");
			Menu::Option("prop_cablespool_05");
			Menu::Option("prop_cablespool_06");
			Menu::Option("prop_cable_hook_01");
			Menu::Option("prop_camera_strap");
			Menu::Option("prop_candy_pqs");
			Menu::Option("prop_can_canoe");
			Menu::Option("prop_cap_01");
			Menu::Option("prop_cap_01b");
			Menu::Option("prop_cap_row_01");
			Menu::Option("prop_cap_row_01b");
			Menu::Option("prop_cap_row_02");
			Menu::Option("prop_cap_row_02b");
			Menu::Option("prop_carcreeper");
			Menu::Option("prop_cargo_int");
			Menu::Option("prop_carjack");
			Menu::Option("prop_carjack_l2");
			Menu::Option("prop_carrier_bag_01");
			Menu::Option("prop_carrier_bag_01_lod");
			Menu::Option("prop_cartwheel_01");
			Menu::Option("prop_carwash_roller_horz");
			Menu::Option("prop_carwash_roller_vert");
			Menu::Option("prop_car_battery_01");
			Menu::Option("prop_car_bonnet_01");
			Menu::Option("prop_car_bonnet_02");
			Menu::Option("prop_car_door_01");
			Menu::Option("prop_car_door_02");
			Menu::Option("prop_car_door_03");
			Menu::Option("prop_car_door_04");
			Menu::Option("prop_car_engine_01");
			Menu::Option("prop_car_exhaust_01");
			Menu::Option("prop_car_ignition");
			Menu::Option("prop_car_seat");
			Menu::Option("prop_casey_sec_id");
			Menu::Option("prop_cash_case_01");
			Menu::Option("prop_cash_case_02");
			Menu::Option("prop_cash_crate_01");
			Menu::Option("prop_cash_dep_bag_01");
			Menu::Option("prop_cash_envelope_01");
			Menu::Option("prop_cash_note_01");
			Menu::Option("prop_cash_pile_01");
			Menu::Option("prop_cash_pile_02");
			Menu::Option("prop_cash_trolly");
			Menu::Option("prop_casino_door_01l");
			Menu::Option("prop_casino_door_01r");
			Menu::Option("prop_cattlecrush");
			Menu::Option("prop_cat_tail_01");
			Menu::Option("prop_cctv_02_sm");
			Menu::Option("prop_cctv_cont_01");
			Menu::Option("prop_cctv_cont_03");
			Menu::Option("prop_cctv_cont_04");
			Menu::Option("prop_cctv_cont_05");
			Menu::Option("prop_cctv_cont_06");
			Menu::Option("prop_cctv_unit_01");
			Menu::Option("prop_cctv_unit_02");
			Menu::Option("prop_cctv_unit_05");
			Menu::Option("prop_cementmixer_01a");
			Menu::Option("prop_cementmixer_02a");
			Menu::Option("prop_ceramic_jug_01");
			Menu::Option("prop_ceramic_jug_cork");
			Menu::Option("prop_ch1_07_door_01l");
			Menu::Option("prop_ch1_07_door_01r");
			Menu::Option("prop_ch1_07_door_02l");
			Menu::Option("prop_ch1_07_door_02r");
			Menu::Option("prop_ch2_05d_g_door");
			Menu::Option("prop_ch2_07b_20_g_door");
			Menu::Option("prop_ch2_09b_door");
			Menu::Option("prop_ch2_09c_garage_door");
			Menu::Option("prop_ch3_01_trlrdoor_l");
			Menu::Option("prop_ch3_01_trlrdoor_r");
			Menu::Option("prop_ch3_04_door_01l");
			Menu::Option("prop_ch3_04_door_01r");
			Menu::Option("prop_ch3_04_door_02");
			Menu::Option("prop_chair_01a");
			Menu::Option("prop_chair_01b");
			Menu::Option("prop_chair_02");
			Menu::Option("prop_chair_03");
			Menu::Option("prop_chair_04a");
			Menu::Option("prop_chair_04b");
			Menu::Option("prop_chair_05");
			Menu::Option("prop_chair_06");
			Menu::Option("prop_chair_07");
			Menu::Option("prop_chair_08");
			Menu::Option("prop_chair_09");
			Menu::Option("prop_chair_10");
			Menu::Option("prop_chair_pile_01");
			Menu::Option("prop_chall_lamp_01");
			Menu::Option("prop_chall_lamp_01n");
			Menu::Option("prop_chall_lamp_02");
			Menu::Option("prop_chateau_chair_01");
			Menu::Option("prop_cheetah_covered");
			Menu::Option("prop_chem_grill");
			Menu::Option("prop_chem_grill_bit");
			Menu::Option("prop_chem_vial_02");
			Menu::Option("prop_chem_vial_02b");
			Menu::Option("prop_cherenneon");
			Menu::Option("prop_chickencoop_a");
			Menu::Option("prop_chip_fryer");
			Menu::Option("prop_choc_ego");
			Menu::Option("prop_choc_meto");
			Menu::Option("prop_choc_pq");
			Menu::Option("prop_ch_025c_g_door_01");
			Menu::Option("prop_cigar_01");
			Menu::Option("prop_cigar_02");
			Menu::Option("prop_cigar_03");
			Menu::Option("prop_cigar_pack_01");
			Menu::Option("prop_cigar_pack_02");
			Menu::Option("prop_clapper_brd_01");
			Menu::Option("prop_cleaver");
			Menu::Option("prop_cliff_paper");
			Menu::Option("prop_clippers_01");
			Menu::Option("prop_clothes_rail_02");
			Menu::Option("prop_clothes_rail_03");
			Menu::Option("prop_clothes_rail_2b");
			Menu::Option("prop_clothes_tub_01");
			Menu::Option("prop_clown_chair");
			Menu::Option("prop_cntrdoor_ld_l");
			Menu::Option("prop_cntrdoor_ld_r");
			Menu::Option("prop_coathook_01");
			Menu::Option("prop_cockneon");
			Menu::Option("prop_coffee_cup_trailer");
			Menu::Option("prop_coffee_mac_02");
			Menu::Option("prop_coffin_02");
			Menu::Option("prop_coffin_02b");
			Menu::Option("prop_coke_block_01");
			Menu::Option("prop_coke_block_half_a");
			Menu::Option("prop_coke_block_half_b");
			Menu::Option("prop_compressor_01");
			Menu::Option("prop_compressor_02");
			Menu::Option("prop_compressor_03");
			Menu::Option("prop_com_gar_door_01");
			Menu::Option("prop_com_ls_door_01");
			Menu::Option("prop_conc_sacks_02a");
			Menu::Option("prop_cone_float_1");
			Menu::Option("prop_conschute");
			Menu::Option("prop_consign_01c");
			Menu::Option("prop_consign_02a");
			Menu::Option("prop_conslift_base");
			Menu::Option("prop_conslift_brace");
			Menu::Option("prop_conslift_cage");
			Menu::Option("prop_conslift_door");
			Menu::Option("prop_conslift_lift");
			Menu::Option("prop_conslift_rail");
			Menu::Option("prop_conslift_rail2");
			Menu::Option("prop_conslift_steps");
			Menu::Option("prop_console_01");
			Menu::Option("prop_construcionlamp_01");
			Menu::Option("prop_const_fence01a");
			Menu::Option("prop_const_fence01b");
			Menu::Option("prop_const_fence02a");
			Menu::Option("prop_const_fence02b");
			Menu::Option("prop_const_fence03b");
			Menu::Option("prop_cons_crate");
			Menu::Option("prop_cons_plank");
			Menu::Option("prop_cons_ply01");
			Menu::Option("prop_cons_ply02");
			Menu::Option("prop_container_01a");
			Menu::Option("prop_container_01b");
			Menu::Option("prop_container_01c");
			Menu::Option("prop_container_01d");
			Menu::Option("prop_container_01e");
			Menu::Option("prop_container_01f");
			Menu::Option("prop_container_01g");
			Menu::Option("prop_container_01h");
			Menu::Option("prop_container_01mb");
			Menu::Option("prop_container_02a");
			Menu::Option("prop_container_03a");
			Menu::Option("prop_container_03b");
			Menu::Option("prop_container_03mb");
			Menu::Option("prop_container_03_ld");
			Menu::Option("prop_container_04a");
			Menu::Option("prop_container_04mb");
			Menu::Option("prop_container_05mb");
			Menu::Option("prop_container_door_mb_l");
			Menu::Option("prop_container_door_mb_r");
			Menu::Option("prop_container_hole");
			Menu::Option("prop_container_ld");
			Menu::Option("prop_container_ld2");
			Menu::Option("prop_container_old1");
			Menu::Option("prop_contnr_pile_01a");
			Menu::Option("prop_controller_01");
			Menu::Option("prop_control_rm_door_01");
			Menu::Option("prop_cont_chiller_01");
			Menu::Option("prop_cooker_03");
			Menu::Option("prop_copier_01");
			Menu::Option("prop_copper_pan");
			Menu::Option("prop_coral_bush_01");
			Menu::Option("prop_coral_flat_01");
			Menu::Option("prop_coral_flat_01_l1");
			Menu::Option("prop_coral_flat_02");
			Menu::Option("prop_coral_flat_brainy");
			Menu::Option("prop_coral_flat_clam");
			Menu::Option("prop_coral_grass_01");
			Menu::Option("prop_coral_grass_02");
			Menu::Option("prop_coral_kelp_01");
			Menu::Option("prop_coral_kelp_01_l1");
			Menu::Option("prop_coral_kelp_02");
			Menu::Option("prop_coral_kelp_02_l1");
			Menu::Option("prop_coral_kelp_03");
			Menu::Option("prop_coral_kelp_03a");
			Menu::Option("prop_coral_kelp_03b");
			Menu::Option("prop_coral_kelp_03c");
			Menu::Option("prop_coral_kelp_03d");
			Menu::Option("prop_coral_kelp_03_l1");
			Menu::Option("prop_coral_kelp_04");
			Menu::Option("prop_coral_kelp_04_l1");
			Menu::Option("prop_coral_pillar_01");
			Menu::Option("prop_coral_pillar_02");
			Menu::Option("prop_coral_spikey_01");
			Menu::Option("prop_coral_stone_03");
			Menu::Option("prop_coral_stone_04");
			Menu::Option("prop_coral_sweed_01");
			Menu::Option("prop_coral_sweed_02");
			Menu::Option("prop_coral_sweed_03");
			Menu::Option("prop_coral_sweed_04");
			Menu::Option("prop_cora_clam_01");
			Menu::Option("prop_cork_board");
			Menu::Option("prop_couch_01");
			Menu::Option("prop_couch_03");
			Menu::Option("prop_couch_04");
			Menu::Option("prop_couch_lg_02");
			Menu::Option("prop_couch_lg_05");
			Menu::Option("prop_couch_lg_06");
			Menu::Option("prop_couch_lg_07");
			Menu::Option("prop_couch_lg_08");
			Menu::Option("prop_couch_sm1_07");
			Menu::Option("prop_couch_sm2_07");
			Menu::Option("prop_couch_sm_02");
			Menu::Option("prop_couch_sm_05");
			Menu::Option("prop_couch_sm_06");
			Menu::Option("prop_couch_sm_07");
			Menu::Option("prop_crane_01_truck1");
			Menu::Option("prop_crane_01_truck2");
			Menu::Option("prop_cranial_saw");
			Menu::Option("prop_crashed_heli");
			Menu::Option("prop_cratepile_07a_l1");
			Menu::Option("prop_crate_01a");
			Menu::Option("prop_crate_02a");
			Menu::Option("prop_crate_08a");
			Menu::Option("prop_crate_09a");
			Menu::Option("prop_crate_10a");
			Menu::Option("prop_crate_11a");
			Menu::Option("prop_crate_11b");
			Menu::Option("prop_crate_11c");
			Menu::Option("prop_crate_11d");
			Menu::Option("prop_crate_float_1");
			Menu::Option("prop_creosote_b_01");
			Menu::Option("prop_crisp");
			Menu::Option("prop_crisp_small");
			Menu::Option("prop_crosssaw_01");
			Menu::Option("prop_cs1_14b_traind");
			Menu::Option("prop_cs1_14b_traind_dam");
			Menu::Option("prop_cs4_05_tdoor");
			Menu::Option("prop_cs4_10_tr_gd_01");
			Menu::Option("prop_cs4_11_door");
			Menu::Option("prop_cs6_03_door_l");
			Menu::Option("prop_cs6_03_door_r");
			Menu::Option("prop_cs_20m_rope");
			Menu::Option("prop_cs_30m_rope");
			Menu::Option("prop_cs_abattoir_switch");
			Menu::Option("prop_cs_aircon_01");
			Menu::Option("prop_cs_aircon_fan");
			Menu::Option("prop_cs_amanda_shoe");
			Menu::Option("prop_cs_ashtray");
			Menu::Option("prop_cs_bandana");
			Menu::Option("prop_cs_bar");
			Menu::Option("prop_cs_beachtowel_01");
			Menu::Option("prop_cs_beer_bot_01");
			Menu::Option("prop_cs_beer_bot_01b");
			Menu::Option("prop_cs_beer_bot_01lod");
			Menu::Option("prop_cs_beer_bot_02");
			Menu::Option("prop_cs_beer_bot_03");
			Menu::Option("prop_cs_beer_bot_40oz");
			Menu::Option("prop_cs_beer_bot_40oz_02");
			Menu::Option("prop_cs_beer_bot_40oz_03");
			Menu::Option("prop_cs_beer_bot_test");
			Menu::Option("prop_cs_binder_01");
			Menu::Option("prop_cs_bin_01");
			Menu::Option("prop_cs_bin_01_lid");
			Menu::Option("prop_cs_bin_01_skinned");
			Menu::Option("prop_cs_bin_02");
			Menu::Option("prop_cs_bin_03");
			Menu::Option("prop_cs_book_01");
			Menu::Option("prop_cs_bottle_opener");
			Menu::Option("prop_cs_bowie_knife");
			Menu::Option("prop_cs_bowl_01");
			Menu::Option("prop_cs_bowl_01b");
			Menu::Option("prop_cs_box_clothes");
			Menu::Option("prop_cs_box_step");
			Menu::Option("prop_cs_brain_chunk");
			Menu::Option("prop_cs_bs_cup");
			Menu::Option("prop_cs_bucket_s");
			Menu::Option("prop_cs_bucket_s_lod");
			Menu::Option("prop_cs_burger_01");
			Menu::Option("prop_cs_business_card");
			Menu::Option("prop_cs_cardbox_01");
			Menu::Option("prop_cs_cash_note_01");
			Menu::Option("prop_cs_cctv");
			Menu::Option("prop_cs_champ_flute");
			Menu::Option("prop_cs_ciggy_01");
			Menu::Option("prop_cs_ciggy_01b");
			Menu::Option("prop_cs_clothes_box");
			Menu::Option("prop_cs_coke_line");
			Menu::Option("prop_cs_cont_latch");
			Menu::Option("prop_cs_crackpipe");
			Menu::Option("prop_cs_credit_card");
			Menu::Option("prop_cs_creeper_01");
			Menu::Option("prop_cs_crisps_01");
			Menu::Option("prop_cs_cuffs_01");
			Menu::Option("prop_cs_diaphram");
			Menu::Option("prop_cs_dildo_01");
			Menu::Option("prop_cs_documents_01");
			Menu::Option("prop_cs_dog_lead_2a");
			Menu::Option("prop_cs_dog_lead_2b");
			Menu::Option("prop_cs_dog_lead_2c");
			Menu::Option("prop_cs_dog_lead_3a");
			Menu::Option("prop_cs_dog_lead_3b");
			Menu::Option("prop_cs_dog_lead_a");
			Menu::Option("prop_cs_dog_lead_b");
			Menu::Option("prop_cs_dog_lead_c");
			Menu::Option("prop_cs_duffel_01");
			Menu::Option("prop_cs_duffel_01b");
			Menu::Option("prop_cs_dumpster_01a");
			Menu::Option("prop_cs_dumpster_lidl");
			Menu::Option("prop_cs_dumpster_lidr");
			Menu::Option("prop_cs_dvd");
			Menu::Option("prop_cs_dvd_case");
			Menu::Option("prop_cs_dvd_player");
			Menu::Option("prop_cs_envolope_01");
			Menu::Option("prop_cs_fertilizer");
			Menu::Option("prop_cs_film_reel_01");
			Menu::Option("prop_cs_folding_chair_01");
			Menu::Option("prop_cs_fork");
			Menu::Option("prop_cs_frank_photo");
			Menu::Option("prop_cs_freightdoor_l1");
			Menu::Option("prop_cs_freightdoor_r1");
			Menu::Option("prop_cs_fridge");
			Menu::Option("prop_cs_fridge_door");
			Menu::Option("prop_cs_fuel_hose");
			Menu::Option("prop_cs_fuel_nozle");
			Menu::Option("prop_cs_gascutter_1");
			Menu::Option("prop_cs_gascutter_2");
			Menu::Option("prop_cs_glass_scrap");
			Menu::Option("prop_cs_gravyard_gate_l");
			Menu::Option("prop_cs_gravyard_gate_r");
			Menu::Option("prop_cs_gunrack");
			Menu::Option("prop_cs_hand_radio");
			Menu::Option("prop_cs_heist_bag_01");
			Menu::Option("prop_cs_heist_bag_02");
			Menu::Option("prop_cs_heist_bag_strap_01");
			Menu::Option("prop_cs_heist_rope");
			Menu::Option("prop_cs_heist_rope_b");
			Menu::Option("prop_cs_hotdog_01");
			Menu::Option("prop_cs_hotdog_02");
			Menu::Option("prop_cs_h_bag_strap_01");
			Menu::Option("prop_cs_ice_locker");
			Menu::Option("prop_cs_ice_locker_door_l");
			Menu::Option("prop_cs_ice_locker_door_r");
			Menu::Option("prop_cs_ilev_blind_01");
			Menu::Option("prop_cs_ironing_board");
			Menu::Option("prop_cs_katana_01");
			Menu::Option("prop_cs_kettle_01");
			Menu::Option("prop_cs_keyboard_01");
			Menu::Option("prop_cs_keys_01");
			Menu::Option("prop_cs_kitchen_cab_l2");
			Menu::Option("prop_cs_kitchen_cab_ld");
			Menu::Option("prop_cs_kitchen_cab_rd");
			Menu::Option("prop_cs_lazlow_ponytail");
			Menu::Option("prop_cs_lazlow_shirt_01");
			Menu::Option("prop_cs_lazlow_shirt_01b");
			Menu::Option("prop_cs_leaf");
			Menu::Option("prop_cs_leg_chain_01");
			Menu::Option("prop_cs_lester_crate");
			Menu::Option("prop_cs_lipstick");
			Menu::Option("prop_cs_magazine");
			Menu::Option("prop_cs_marker_01");
			Menu::Option("prop_cs_meth_pipe");
			Menu::Option("prop_cs_milk_01");
			Menu::Option("prop_cs_mini_tv");
			Menu::Option("prop_cs_mopbucket_01");
			Menu::Option("prop_cs_mop_s");
			Menu::Option("prop_cs_mouse_01");
			Menu::Option("prop_cs_nail_file");
			Menu::Option("prop_cs_newspaper");
			Menu::Option("prop_cs_office_chair");
			Menu::Option("prop_cs_overalls_01");
			Menu::Option("prop_cs_package_01");
			Menu::Option("prop_cs_padlock");
			Menu::Option("prop_cs_pamphlet_01");
			Menu::Option("prop_cs_panel_01");
			Menu::Option("prop_cs_panties");
			Menu::Option("prop_cs_panties_02");
			Menu::Option("prop_cs_panties_03");
			Menu::Option("prop_cs_paper_cup");
			Menu::Option("prop_cs_para_ropebit");
			Menu::Option("prop_cs_para_ropes");
			Menu::Option("prop_cs_pebble");
			Menu::Option("prop_cs_pebble_02");
			Menu::Option("prop_cs_petrol_can");
			Menu::Option("prop_cs_phone_01");
			Menu::Option("prop_cs_photoframe_01");
			Menu::Option("prop_cs_pills");
			Menu::Option("prop_cs_plane_int_01");
			Menu::Option("prop_cs_planning_photo");
			Menu::Option("prop_cs_plant_01");
			Menu::Option("prop_cs_plate_01");
			Menu::Option("prop_cs_polaroid");
			Menu::Option("prop_cs_police_torch");
			Menu::Option("prop_cs_pour_tube");
			Menu::Option("prop_cs_power_cell");
			Menu::Option("prop_cs_power_cord");
			Menu::Option("prop_cs_protest_sign_01");
			Menu::Option("prop_cs_protest_sign_02");
			Menu::Option("prop_cs_protest_sign_02b");
			Menu::Option("prop_cs_protest_sign_03");
			Menu::Option("prop_cs_protest_sign_04a");
			Menu::Option("prop_cs_protest_sign_04b");
			Menu::Option("prop_cs_rage_statue_p1");
			Menu::Option("prop_cs_rage_statue_p2");
			Menu::Option("prop_cs_remote_01");
			Menu::Option("prop_cs_rolled_paper");
			Menu::Option("prop_cs_rope_tie_01");
			Menu::Option("prop_cs_rub_binbag_01");
			Menu::Option("prop_cs_rub_box_01");
			Menu::Option("prop_cs_rub_box_02");
			Menu::Option("prop_cs_r_business_card");
			Menu::Option("prop_cs_sack_01");
			Menu::Option("prop_cs_saucer_01");
			Menu::Option("prop_cs_sc1_11_gate");
			Menu::Option("prop_cs_scissors");
			Menu::Option("prop_cs_script_bottle");
			Menu::Option("prop_cs_script_bottle_01");
			Menu::Option("prop_cs_server_drive");
			Menu::Option("prop_cs_sheers");
			Menu::Option("prop_cs_shirt_01");
			Menu::Option("prop_cs_shopping_bag");
			Menu::Option("prop_cs_shot_glass");
			Menu::Option("prop_cs_silver_tray");
			Menu::Option("prop_cs_sink_filler");
			Menu::Option("prop_cs_sink_filler_02");
			Menu::Option("prop_cs_sink_filler_03");
			Menu::Option("prop_cs_sm_27_gate");
			Menu::Option("prop_cs_sol_glasses");
			Menu::Option("prop_cs_spray_can");
			Menu::Option("prop_cs_steak");
			Menu::Option("prop_cs_stock_book");
			Menu::Option("prop_cs_street_binbag_01");
			Menu::Option("prop_cs_street_card_01");
			Menu::Option("prop_cs_street_card_02");
			Menu::Option("prop_cs_sub_hook_01");
			Menu::Option("prop_cs_sub_rope_01");
			Menu::Option("prop_cs_swipe_card");
			Menu::Option("prop_cs_tablet");
			Menu::Option("prop_cs_tablet_02");
			Menu::Option("prop_cs_toaster");
			Menu::Option("prop_cs_trolley_01");
			Menu::Option("prop_cs_trowel");
			Menu::Option("prop_cs_truck_ladder");
			Menu::Option("prop_cs_tshirt_ball_01");
			Menu::Option("prop_cs_tv_stand");
			Menu::Option("prop_cs_t_shirt_pile");
			Menu::Option("prop_cs_valve");
			Menu::Option("prop_cs_vent_cover");
			Menu::Option("prop_cs_vial_01");
			Menu::Option("prop_cs_walkie_talkie");
			Menu::Option("prop_cs_walking_stick");
			Menu::Option("prop_cs_whiskey_bottle");
			Menu::Option("prop_cs_whiskey_bot_stop");
			Menu::Option("prop_cs_wrench");
			Menu::Option("prop_cub_door_lifeblurb");
			Menu::Option("prop_cub_lifeblurb");
			Menu::Option("prop_cuff_keys_01");
			Menu::Option("prop_cup_saucer_01");
			Menu::Option("prop_curl_bar_01");
			Menu::Option("prop_damdoor_01");
			Menu::Option("prop_dart_1");
			Menu::Option("prop_dart_2");
			Menu::Option("prop_dart_bd_01");
			Menu::Option("prop_dart_bd_cab_01");
			Menu::Option("prop_defilied_ragdoll_01");
			Menu::Option("prop_desert_iron_01");
			Menu::Option("prop_detergent_01a");
			Menu::Option("prop_detergent_01b");
			Menu::Option("prop_devin_box_01");
			Menu::Option("prop_devin_rope_01");
			Menu::Option("prop_diggerbkt_01");
			Menu::Option("prop_direct_chair_01");
			Menu::Option("prop_direct_chair_02");
			Menu::Option("prop_display_unit_01");
			Menu::Option("prop_display_unit_02");
			Menu::Option("prop_disp_cabinet_002");
			Menu::Option("prop_disp_cabinet_01");
			Menu::Option("prop_disp_razor_01");
			Menu::Option("prop_distantcar_day");
			Menu::Option("prop_distantcar_night");
			Menu::Option("prop_distantcar_truck");
			Menu::Option("prop_dj_deck_01");
			Menu::Option("prop_dj_deck_02");
			Menu::Option("prop_dock_bouy_1");
			Menu::Option("prop_dock_bouy_2");
			Menu::Option("prop_dock_bouy_3");
			Menu::Option("prop_dock_bouy_5");
			Menu::Option("prop_dock_crane_01");
			Menu::Option("prop_dock_crane_02");
			Menu::Option("prop_dock_crane_02_cab");
			Menu::Option("prop_dock_crane_02_hook");
			Menu::Option("prop_dock_crane_02_ld");
			Menu::Option("prop_dock_crane_04");
			Menu::Option("prop_dock_crane_lift");
			Menu::Option("prop_dock_float_1");
			Menu::Option("prop_dock_float_1b");
			Menu::Option("prop_dock_moor_01");
			Menu::Option("prop_dock_moor_04");
			Menu::Option("prop_dock_moor_05");
			Menu::Option("prop_dock_moor_06");
			Menu::Option("prop_dock_moor_07");
			Menu::Option("prop_dock_ropefloat");
			Menu::Option("prop_dock_ropetyre1");
			Menu::Option("prop_dock_ropetyre2");
			Menu::Option("prop_dock_ropetyre3");
			Menu::Option("prop_dock_rtg_01");
			Menu::Option("prop_dock_rtg_ld");
			Menu::Option("prop_dock_shippad");
			Menu::Option("prop_dock_sign_01");
			Menu::Option("prop_dock_woodpole1");
			Menu::Option("prop_dock_woodpole2");
			Menu::Option("prop_dock_woodpole3");
			Menu::Option("prop_dock_woodpole4");
			Menu::Option("prop_dock_woodpole5");
			Menu::Option("prop_dog_cage_01");
			Menu::Option("prop_dog_cage_02");
			Menu::Option("prop_dolly_01");
			Menu::Option("prop_dolly_02");
			Menu::Option("prop_donut_01");
			Menu::Option("prop_donut_02");
			Menu::Option("prop_donut_02b");
			Menu::Option("prop_door_01");
			Menu::Option("prop_door_balcony_frame");
			Menu::Option("prop_door_balcony_left");
			Menu::Option("prop_door_balcony_right");
			Menu::Option("prop_door_bell_01");
			Menu::Option("prop_double_grid_line");
			Menu::Option("prop_dress_disp_01");
			Menu::Option("prop_dress_disp_02");
			Menu::Option("prop_dress_disp_03");
			Menu::Option("prop_dress_disp_04");
			Menu::Option("prop_drop_armscrate_01");
			Menu::Option("prop_drop_armscrate_01b");
			Menu::Option("prop_drop_crate_01");
			Menu::Option("prop_drop_crate_01_set");
			Menu::Option("prop_drop_crate_01_set2");
			Menu::Option("prop_drug_burner");
			Menu::Option("prop_drug_package");
			Menu::Option("prop_drug_package_02");
			Menu::Option("prop_drywallpile_01");
			Menu::Option("prop_drywallpile_02");
			Menu::Option("prop_dt1_13_groundlight");
			Menu::Option("prop_dt1_13_walllightsource");
			Menu::Option("prop_dt1_20_mp_door_l");
			Menu::Option("prop_dt1_20_mp_door_r");
			Menu::Option("prop_dt1_20_mp_gar");
			Menu::Option("prop_ducktape_01");
			Menu::Option("prop_dummy_01");
			Menu::Option("prop_dummy_car");
			Menu::Option("prop_dummy_light");
			Menu::Option("prop_dummy_plane");
			Menu::Option("prop_dumpster_3a");
			Menu::Option("prop_dumpster_3step");
			Menu::Option("prop_dumpster_4a");
			Menu::Option("prop_dumpster_4b");
			Menu::Option("prop_d_balcony_l_light");
			Menu::Option("prop_d_balcony_r_light");
			Menu::Option("prop_ear_defenders_01");
			Menu::Option("prop_ecg_01");
			Menu::Option("prop_ecg_01_cable_01");
			Menu::Option("prop_ecg_01_cable_02");
			Menu::Option("prop_ecola_can");
			Menu::Option("prop_egg_clock_01");
			Menu::Option("prop_ejector_seat_01");
			Menu::Option("prop_elecbox_03a");
			Menu::Option("prop_elecbox_10");
			Menu::Option("prop_elecbox_12");
			Menu::Option("prop_elecbox_13");
			Menu::Option("prop_elecbox_14");
			Menu::Option("prop_elecbox_15");
			Menu::Option("prop_elecbox_16");
			Menu::Option("prop_elecbox_17");
			Menu::Option("prop_elecbox_18");
			Menu::Option("prop_elecbox_19");
			Menu::Option("prop_elecbox_20");
			Menu::Option("prop_elecbox_21");
			Menu::Option("prop_elecbox_22");
			Menu::Option("prop_elecbox_23");
			Menu::Option("prop_elecbox_24");
			Menu::Option("prop_elecbox_24b");
			Menu::Option("prop_elecbox_25");
			Menu::Option("prop_el_guitar_01");
			Menu::Option("prop_el_guitar_02");
			Menu::Option("prop_el_guitar_03");
			Menu::Option("prop_employee_month_01");
			Menu::Option("prop_employee_month_02");
			Menu::Option("prop_energy_drink");
			Menu::Option("prop_entityxf_covered");
			Menu::Option("prop_epsilon_door_l");
			Menu::Option("prop_epsilon_door_r");
			Menu::Option("prop_etricmotor_01");
			Menu::Option("prop_exer_bike_01");
			Menu::Option("prop_faceoffice_door_l");
			Menu::Option("prop_faceoffice_door_r");
			Menu::Option("prop_face_rag_01");
			Menu::Option("prop_facgate_01");
			Menu::Option("prop_facgate_01b");
			Menu::Option("prop_facgate_02pole");
			Menu::Option("prop_facgate_02_l");
			Menu::Option("prop_facgate_03post");
			Menu::Option("prop_facgate_03_l");
			Menu::Option("prop_facgate_03_ld_l");
			Menu::Option("prop_facgate_03_ld_r");
			Menu::Option("prop_facgate_03_r");
			Menu::Option("prop_facgate_04_l");
			Menu::Option("prop_facgate_04_r");
			Menu::Option("prop_facgate_05_r");
			Menu::Option("prop_facgate_05_r_dam_l1");
			Menu::Option("prop_facgate_05_r_l1");
			Menu::Option("prop_facgate_06_l");
			Menu::Option("prop_facgate_06_r");
			Menu::Option("prop_facgate_07");
			Menu::Option("prop_facgate_07b");
			Menu::Option("prop_facgate_08");
			Menu::Option("prop_facgate_08_frame");
			Menu::Option("prop_facgate_08_ld2");
			Menu::Option("prop_facgate_id1_27");
			Menu::Option("prop_fac_machine_02");
			Menu::Option("prop_fag_packet_01");
			Menu::Option("prop_fan_01");
			Menu::Option("prop_fan_palm_01a");
			Menu::Option("prop_fax_01");
			Menu::Option("prop_fbi3_coffee_table");
			Menu::Option("prop_fbibombbin");
			Menu::Option("prop_fbibombcupbrd");
			Menu::Option("prop_fbibombfile");
			Menu::Option("prop_fbibombplant");
			Menu::Option("prop_feeder1");
			Menu::Option("prop_feed_sack_01");
			Menu::Option("prop_feed_sack_02");
			Menu::Option("prop_fence_log_01");
			Menu::Option("prop_fence_log_02");
			Menu::Option("prop_ferris_car_01");
			Menu::Option("prop_ferris_car_01_lod1");
			Menu::Option("prop_ff_counter_01");
			Menu::Option("prop_ff_counter_02");
			Menu::Option("prop_ff_counter_03");
			Menu::Option("prop_ff_noodle_01");
			Menu::Option("prop_ff_noodle_02");
			Menu::Option("prop_ff_shelves_01");
			Menu::Option("prop_ff_sink_01");
			Menu::Option("prop_ff_sink_02");
			Menu::Option("prop_fib_badge");
			Menu::Option("prop_fib_broken_window");
			Menu::Option("prop_fib_skylight_piece");
			Menu::Option("prop_film_cam_01");
			Menu::Option("prop_fireescape_01a");
			Menu::Option("prop_fireescape_01b");
			Menu::Option("prop_fireescape_02a");
			Menu::Option("prop_fireescape_02b");
			Menu::Option("prop_fire_driser_1a");
			Menu::Option("prop_fire_driser_1b");
			Menu::Option("prop_fire_driser_2b");
			Menu::Option("prop_fire_driser_3b");
			Menu::Option("prop_fire_driser_4a");
			Menu::Option("prop_fire_driser_4b");
			Menu::Option("prop_fire_hosereel");
			Menu::Option("prop_fishing_rod_01");
			Menu::Option("prop_fishing_rod_02");
			Menu::Option("prop_fish_slice_01");
			Menu::Option("prop_flagpole_1a");
			Menu::Option("prop_flagpole_2a");
			Menu::Option("prop_flagpole_3a");
			Menu::Option("prop_flare_01");
			Menu::Option("prop_flare_01b");
			Menu::Option("prop_flash_unit");
			Menu::Option("prop_flatbed_strap");
			Menu::Option("prop_flatbed_strap_b");
			Menu::Option("prop_flatscreen_overlay");
			Menu::Option("prop_flattrailer_01a");
			Menu::Option("prop_flattruck_01a");
			Menu::Option("prop_fleeca_atm");
			Menu::Option("prop_flight_box_01");
			Menu::Option("prop_flight_box_insert");
			Menu::Option("prop_flight_box_insert2");
			Menu::Option("prop_flipchair_01");
			Menu::Option("prop_floor_duster_01");
			Menu::Option("prop_fncconstruc_02a");
			Menu::Option("prop_fnccorgm_05a");
			Menu::Option("prop_fnccorgm_05b");
			Menu::Option("prop_fnccorgm_06a");
			Menu::Option("prop_fnccorgm_06b");
			Menu::Option("prop_fnclink_01gate1");
			Menu::Option("prop_fnclink_02gate1");
			Menu::Option("prop_fnclink_02gate2");
			Menu::Option("prop_fnclink_02gate5");
			Menu::Option("prop_fnclink_02gate6_l");
			Menu::Option("prop_fnclink_02gate6_r");
			Menu::Option("prop_fnclink_02gate7");
			Menu::Option("prop_fnclink_03gate1");
			Menu::Option("prop_fnclink_03gate2");
			Menu::Option("prop_fnclink_03gate4");
			Menu::Option("prop_fnclink_03gate5");
			Menu::Option("prop_fnclink_04gate1");
			Menu::Option("prop_fnclink_04h_l2");
			Menu::Option("prop_fnclink_06gate2");
			Menu::Option("prop_fnclink_06gate3");
			Menu::Option("prop_fnclink_06gatepost");
			Menu::Option("prop_fnclink_07gate1");
			Menu::Option("prop_fnclink_07gate2");
			Menu::Option("prop_fnclink_07gate3");
			Menu::Option("prop_fnclink_09gate1");
			Menu::Option("prop_fnclink_10a");
			Menu::Option("prop_fnclink_10b");
			Menu::Option("prop_fnclink_10c");
			Menu::Option("prop_fnclink_10d");
			Menu::Option("prop_fnclink_10e");
			Menu::Option("prop_fnclog_01a");
			Menu::Option("prop_fnclog_01b");
			Menu::Option("prop_fncpeir_03a");
			Menu::Option("prop_fncres_02a");
			Menu::Option("prop_fncres_02b");
			Menu::Option("prop_fncres_02c");
			Menu::Option("prop_fncres_02d");
			Menu::Option("prop_fncres_02_gate1");
			Menu::Option("prop_fncres_03gate1");
			Menu::Option("prop_fncres_05c_l1");
			Menu::Option("prop_fncsec_01a");
			Menu::Option("prop_fncsec_01b");
			Menu::Option("prop_fncsec_01crnr");
			Menu::Option("prop_fncsec_01gate");
			Menu::Option("prop_fncsec_01pole");
			Menu::Option("prop_fncsec_02a");
			Menu::Option("prop_fncsec_02pole");
			Menu::Option("prop_fncsec_04a");
			Menu::Option("prop_fncwood_07gate1");
			Menu::Option("prop_fncwood_11a_l1");
			Menu::Option("prop_fncwood_16a");
			Menu::Option("prop_fncwood_16b");
			Menu::Option("prop_fncwood_16c");
			Menu::Option("prop_fncwood_18a");
			Menu::Option("prop_folded_polo_shirt");
			Menu::Option("prop_folder_01");
			Menu::Option("prop_folder_02");
			Menu::Option("prop_food_bin_01");
			Menu::Option("prop_food_bin_02");
			Menu::Option("prop_food_bs_bshelf");
			Menu::Option("prop_food_bs_cups01");
			Menu::Option("prop_food_bs_cups03");
			Menu::Option("prop_food_bs_soda_01");
			Menu::Option("prop_food_bs_soda_02");
			Menu::Option("prop_food_bs_tray_01");
			Menu::Option("prop_food_bs_tray_06");
			Menu::Option("prop_food_burg1");
			Menu::Option("prop_food_burg2");
			Menu::Option("prop_food_cb_bshelf");
			Menu::Option("prop_food_cb_burg01");
			Menu::Option("prop_food_cb_cups01");
			Menu::Option("prop_food_cb_donuts");
			Menu::Option("prop_food_cb_nugets");
			Menu::Option("prop_food_cb_soda_01");
			Menu::Option("prop_food_cb_soda_02");
			Menu::Option("prop_food_cb_tray_01");
			Menu::Option("prop_food_cups1");
			Menu::Option("prop_food_napkin_01");
			Menu::Option("prop_food_napkin_02");
			Menu::Option("prop_food_tray_01");
			Menu::Option("prop_food_van_01");
			Menu::Option("prop_food_van_02");
			Menu::Option("prop_forsalejr2");
			Menu::Option("prop_forsalejr3");
			Menu::Option("prop_forsalejr4");
			Menu::Option("prop_foundation_sponge");
			Menu::Option("prop_fountain1");
			Menu::Option("prop_fountain2");
			Menu::Option("prop_franklin_dl");
			Menu::Option("prop_freeweight_01");
			Menu::Option("prop_freeweight_02");
			Menu::Option("prop_fridge_01");
			Menu::Option("prop_fridge_03");
			Menu::Option("prop_front_seat_01");
			Menu::Option("prop_front_seat_02");
			Menu::Option("prop_front_seat_03");
			Menu::Option("prop_front_seat_04");
			Menu::Option("prop_front_seat_05");
			Menu::Option("prop_front_seat_06");
			Menu::Option("prop_front_seat_07");
			Menu::Option("prop_front_seat_row_01");
			Menu::Option("prop_fruitstand_b_nite");
			Menu::Option("prop_fruit_basket");
			Menu::Option("prop_ftowel_01");
			Menu::Option("prop_ftowel_07");
			Menu::Option("prop_ftowel_08");
			Menu::Option("prop_ftowel_10");
			Menu::Option("prop_f_b_insert_broken");
			Menu::Option("prop_f_duster_01_s");
			Menu::Option("prop_f_duster_02");
			Menu::Option("prop_gaffer_arm_bind");
			Menu::Option("prop_gaffer_arm_bind_cut");
			Menu::Option("prop_gaffer_leg_bind");
			Menu::Option("prop_gaffer_leg_bind_cut");
			Menu::Option("prop_gaffer_tape");
			Menu::Option("prop_gaffer_tape_strip");
			Menu::Option("prop_game_clock_01");
			Menu::Option("prop_game_clock_02");
			Menu::Option("prop_garden_dreamcatch_01");
			Menu::Option("prop_garden_edging_01");
			Menu::Option("prop_garden_edging_02");
			Menu::Option("prop_garden_zapper_01");
			Menu::Option("prop_gardnght_01");
			Menu::Option("prop_gar_door_01");
			Menu::Option("prop_gar_door_02");
			Menu::Option("prop_gar_door_03");
			Menu::Option("prop_gar_door_03_ld");
			Menu::Option("prop_gar_door_04");
			Menu::Option("prop_gar_door_05");
			Menu::Option("prop_gar_door_05_l");
			Menu::Option("prop_gar_door_05_r");
			Menu::Option("prop_gar_door_a_01");
			Menu::Option("prop_gar_door_plug");
			Menu::Option("prop_gascage01");
			Menu::Option("prop_gascyl_ramp_01");
			Menu::Option("prop_gascyl_ramp_door_01");
			Menu::Option("prop_gas_01");
			Menu::Option("prop_gas_02");
			Menu::Option("prop_gas_03");
			Menu::Option("prop_gas_04");
			Menu::Option("prop_gas_05");
			Menu::Option("prop_gas_grenade");
			Menu::Option("prop_gas_mask_hang_01");
			Menu::Option("prop_gatecom_02");
			Menu::Option("prop_gate_airport_01");
			Menu::Option("prop_gate_bridge_ld");
			Menu::Option("prop_gate_cult_01_l");
			Menu::Option("prop_gate_cult_01_r");
			Menu::Option("prop_gate_docks_ld");
			Menu::Option("prop_gate_farm_01a");
			Menu::Option("prop_gate_farm_post");
			Menu::Option("prop_gate_frame_01");
			Menu::Option("prop_gate_frame_02");
			Menu::Option("prop_gate_frame_04");
			Menu::Option("prop_gate_frame_05");
			Menu::Option("prop_gate_frame_06");
			Menu::Option("prop_gate_military_01");
			Menu::Option("prop_gate_prison_01");
			Menu::Option("prop_gate_tep_01_l");
			Menu::Option("prop_gate_tep_01_r");
			Menu::Option("prop_gazebo_03");
			Menu::Option("prop_gd_ch2_08");
			Menu::Option("prop_generator_02a");
			Menu::Option("prop_generator_03a");
			Menu::Option("prop_generator_04");
			Menu::Option("prop_ghettoblast_02");
			Menu::Option("prop_girder_01a");
			Menu::Option("prop_glasscutter_01");
			Menu::Option("prop_glass_suck_holder");
			Menu::Option("prop_glf_roller");
			Menu::Option("prop_glf_spreader");
			Menu::Option("prop_gold_bar");
			Menu::Option("prop_gold_cont_01");
			Menu::Option("prop_gold_cont_01b");
			Menu::Option("prop_gold_trolly");
			Menu::Option("prop_gold_trolly_full");
			Menu::Option("prop_gold_trolly_strap_01");
			Menu::Option("prop_golf_bag_01");
			Menu::Option("prop_golf_bag_01b");
			Menu::Option("prop_golf_bag_01c");
			Menu::Option("prop_golf_ball");
			Menu::Option("prop_golf_ball_p2");
			Menu::Option("prop_golf_ball_p3");
			Menu::Option("prop_golf_ball_p4");
			Menu::Option("prop_golf_ball_tee");
			Menu::Option("prop_golf_driver");
			Menu::Option("prop_golf_iron_01");
			Menu::Option("prop_golf_marker_01");
			Menu::Option("prop_golf_pitcher_01");
			Menu::Option("prop_golf_putter_01");
			Menu::Option("prop_golf_tee");
			Menu::Option("prop_golf_wood_01");
			Menu::Option("prop_grain_hopper");
			Menu::Option("prop_grapes_01");
			Menu::Option("prop_grapes_02");
			Menu::Option("prop_grass_dry_02");
			Menu::Option("prop_grass_dry_03");
			Menu::Option("prop_gravestones_01a");
			Menu::Option("prop_gravestones_02a");
			Menu::Option("prop_gravestones_03a");
			Menu::Option("prop_gravestones_04a");
			Menu::Option("prop_gravestones_05a");
			Menu::Option("prop_gravestones_06a");
			Menu::Option("prop_gravestones_07a");
			Menu::Option("prop_gravestones_08a");
			Menu::Option("prop_gravestones_09a");
			Menu::Option("prop_gravestones_10a");
			Menu::Option("prop_gravetomb_01a");
			Menu::Option("prop_gravetomb_02a");
			Menu::Option("prop_griddle_01");
			Menu::Option("prop_griddle_02");
			Menu::Option("prop_grumandoor_l");
			Menu::Option("prop_grumandoor_r");
			Menu::Option("prop_gshotsensor_01");
			Menu::Option("prop_gun_case_01");
			Menu::Option("prop_gun_case_02");
			Menu::Option("prop_gun_frame");
			Menu::Option("prop_hacky_sack_01");
			Menu::Option("prop_handdry_01");
			Menu::Option("prop_handdry_02");
			Menu::Option("prop_handrake");
			Menu::Option("prop_handtowels");
			Menu::Option("prop_hand_toilet");
			Menu::Option("prop_hanger_door_1");
			Menu::Option("prop_hard_hat_01");
			Menu::Option("prop_hat_box_01");
			Menu::Option("prop_hat_box_02");
			Menu::Option("prop_hat_box_03");
			Menu::Option("prop_hat_box_04");
			Menu::Option("prop_hat_box_05");
			Menu::Option("prop_hat_box_06");
			Menu::Option("prop_haybailer_01");
			Menu::Option("prop_haybale_01");
			Menu::Option("prop_haybale_02");
			Menu::Option("prop_haybale_stack_01");
			Menu::Option("prop_hd_seats_01");
			Menu::Option("prop_headphones_01");
			Menu::Option("prop_headset_01");
			Menu::Option("prop_hedge_trimmer_01");
			Menu::Option("prop_helipad_01");
			Menu::Option("prop_helipad_02");
			Menu::Option("prop_henna_disp_01");
			Menu::Option("prop_henna_disp_02");
			Menu::Option("prop_henna_disp_03");
			Menu::Option("prop_hifi_01");
			Menu::Option("prop_hobo_stove_01");
			Menu::Option("prop_hockey_bag_01");
			Menu::Option("prop_hole_plug_01");
			Menu::Option("prop_holster_01");
			Menu::Option("prop_homeless_matress_01");
			Menu::Option("prop_homeless_matress_02");
			Menu::Option("prop_hose_1");
			Menu::Option("prop_hose_2");
			Menu::Option("prop_hose_3");
			Menu::Option("prop_hose_nozzle");
			Menu::Option("prop_hospitaldoors_start");
			Menu::Option("prop_hospital_door_l");
			Menu::Option("prop_hospital_door_r");
			Menu::Option("prop_hotel_clock_01");
			Menu::Option("prop_hotel_trolley");
			Menu::Option("prop_hottub2");
			Menu::Option("prop_huf_rag_01");
			Menu::Option("prop_huge_display_01");
			Menu::Option("prop_huge_display_02");
			Menu::Option("prop_hunterhide");
			Menu::Option("prop_hw1_03_gardoor_01");
			Menu::Option("prop_hw1_04_door_l1");
			Menu::Option("prop_hw1_04_door_r1");
			Menu::Option("prop_hw1_23_door");
			Menu::Option("prop_hwbowl_pseat_6x1");
			Menu::Option("prop_hwbowl_seat_01");
			Menu::Option("prop_hwbowl_seat_02");
			Menu::Option("prop_hwbowl_seat_03");
			Menu::Option("prop_hwbowl_seat_03b");
			Menu::Option("prop_hwbowl_seat_6x6");
			Menu::Option("prop_hydro_platform_01");
			Menu::Option("prop_ice_box_01");
			Menu::Option("prop_ice_box_01_l1");
			Menu::Option("prop_ice_cube_01");
			Menu::Option("prop_ice_cube_02");
			Menu::Option("prop_ice_cube_03");
			Menu::Option("prop_id2_11_gdoor");
			Menu::Option("prop_id2_20_clock");
			Menu::Option("prop_idol_01");
			Menu::Option("prop_idol_01_error");
			Menu::Option("prop_idol_case");
			Menu::Option("prop_idol_case_01");
			Menu::Option("prop_idol_case_02");
			Menu::Option("prop_id_21_gardoor_01");
			Menu::Option("prop_id_21_gardoor_02");
			Menu::Option("prop_indus_meet_door_l");
			Menu::Option("prop_indus_meet_door_r");
			Menu::Option("prop_ind_barge_01");
			Menu::Option("prop_ind_barge_02");
			Menu::Option("prop_ind_coalcar_01");
			Menu::Option("prop_ind_coalcar_02");
			Menu::Option("prop_ind_coalcar_03");
			Menu::Option("prop_ind_conveyor_01");
			Menu::Option("prop_ind_conveyor_02");
			Menu::Option("prop_ind_conveyor_04");
			Menu::Option("prop_ind_crusher");
			Menu::Option("prop_ind_deiseltank");
			Menu::Option("prop_ind_light_01a");
			Menu::Option("prop_ind_light_01b");
			Menu::Option("prop_ind_light_01c");
			Menu::Option("prop_ind_mech_01c");
			Menu::Option("prop_ind_mech_02a");
			Menu::Option("prop_ind_mech_02b");
			Menu::Option("prop_ind_mech_03a");
			Menu::Option("prop_ind_mech_04a");
			Menu::Option("prop_ind_oldcrane");
			Menu::Option("prop_ind_washer_02");
			Menu::Option("prop_inflatearch_01");
			Menu::Option("prop_inflategate_01");
			Menu::Option("prop_ing_camera_01");
			Menu::Option("prop_ing_crowbar");
			Menu::Option("prop_inhaler_01");
			Menu::Option("prop_int_gate01");
			Menu::Option("prop_in_tray_01");
			Menu::Option("prop_irish_sign_01");
			Menu::Option("prop_irish_sign_02");
			Menu::Option("prop_irish_sign_03");
			Menu::Option("prop_irish_sign_04");
			Menu::Option("prop_irish_sign_05");
			Menu::Option("prop_irish_sign_06");
			Menu::Option("prop_irish_sign_07");
			Menu::Option("prop_irish_sign_08");
			Menu::Option("prop_irish_sign_09");
			Menu::Option("prop_irish_sign_10");
			Menu::Option("prop_irish_sign_11");
			Menu::Option("prop_irish_sign_12");
			Menu::Option("prop_irish_sign_13");
			Menu::Option("prop_iron_01");
			Menu::Option("prop_jb700_covered");
			Menu::Option("prop_jeans_01");
			Menu::Option("prop_jetski_ramp_01");
			Menu::Option("prop_jet_bloodsplat_01");
			Menu::Option("prop_jewel_02a");
			Menu::Option("prop_jewel_02b");
			Menu::Option("prop_jewel_02c");
			Menu::Option("prop_jewel_03a");
			Menu::Option("prop_jewel_03b");
			Menu::Option("prop_jewel_04a");
			Menu::Option("prop_jewel_04b");
			Menu::Option("prop_jewel_pickup_new_01");
			Menu::Option("prop_juice_dispenser");
			Menu::Option("prop_juice_pool_01");
			Menu::Option("prop_jukebox_01");
			Menu::Option("prop_jukebox_02");
			Menu::Option("prop_jyard_block_01a");
			Menu::Option("prop_j_disptray_01");
			Menu::Option("prop_j_disptray_01b");
			Menu::Option("prop_j_disptray_01_dam");
			Menu::Option("prop_j_disptray_02");
			Menu::Option("prop_j_disptray_02_dam");
			Menu::Option("prop_j_disptray_03");
			Menu::Option("prop_j_disptray_03_dam");
			Menu::Option("prop_j_disptray_04");
			Menu::Option("prop_j_disptray_04b");
			Menu::Option("prop_j_disptray_05");
			Menu::Option("prop_j_disptray_05b");
			Menu::Option("prop_j_heist_pic_01");
			Menu::Option("prop_j_heist_pic_02");
			Menu::Option("prop_j_heist_pic_03");
			Menu::Option("prop_j_heist_pic_04");
			Menu::Option("prop_j_neck_disp_01");
			Menu::Option("prop_j_neck_disp_02");
			Menu::Option("prop_j_neck_disp_03");
			Menu::Option("prop_kayak_01");
			Menu::Option("prop_kayak_01b");
			Menu::Option("prop_kebab_grill");
			Menu::Option("prop_keg_01");
			Menu::Option("prop_kettle");
			Menu::Option("prop_kettle_01");
			Menu::Option("prop_keyboard_01a");
			Menu::Option("prop_keyboard_01b");
			Menu::Option("prop_kino_light_01");
			Menu::Option("prop_kino_light_03");
			Menu::Option("prop_kitch_juicer");
			Menu::Option("prop_kitch_pot_fry");
			Menu::Option("prop_kitch_pot_huge");
			Menu::Option("prop_kitch_pot_lrg");
			Menu::Option("prop_kitch_pot_lrg2");
			Menu::Option("prop_kitch_pot_med");
			Menu::Option("prop_kitch_pot_sm");
			Menu::Option("prop_knife");
			Menu::Option("prop_knife_stand");
			Menu::Option("prop_kt1_06_door_l");
			Menu::Option("prop_kt1_06_door_r");
			Menu::Option("prop_kt1_10_mpdoor_l");
			Menu::Option("prop_kt1_10_mpdoor_r");
			Menu::Option("prop_ladel");
			Menu::Option("prop_laptop_02_closed");
			Menu::Option("prop_laptop_jimmy");
			Menu::Option("prop_laptop_lester");
			Menu::Option("prop_laptop_lester2");
			Menu::Option("prop_large_gold");
			Menu::Option("prop_large_gold_alt_a");
			Menu::Option("prop_large_gold_alt_b");
			Menu::Option("prop_large_gold_alt_c");
			Menu::Option("prop_large_gold_empty");
			Menu::Option("prop_lawnmower_01");
			Menu::Option("prop_ld_alarm_01");
			Menu::Option("prop_ld_alarm_01_dam");
			Menu::Option("prop_ld_alarm_alert");
			Menu::Option("prop_ld_ammo_pack_01");
			Menu::Option("prop_ld_ammo_pack_02");
			Menu::Option("prop_ld_ammo_pack_03");
			Menu::Option("prop_ld_armour");
			Menu::Option("prop_ld_balcfnc_01a");
			Menu::Option("prop_ld_balcfnc_02a");
			Menu::Option("prop_ld_balcfnc_02c");
			Menu::Option("prop_ld_bankdoors_02");
			Menu::Option("prop_ld_barrier_01");
			Menu::Option("prop_ld_binbag_01");
			Menu::Option("prop_ld_bomb");
			Menu::Option("prop_ld_bomb_01");
			Menu::Option("prop_ld_bomb_01_open");
			Menu::Option("prop_ld_bomb_anim");
			Menu::Option("prop_ld_cable");
			Menu::Option("prop_ld_cable_tie_01");
			Menu::Option("prop_ld_can_01");
			Menu::Option("prop_ld_case_01");
			Menu::Option("prop_ld_case_01_lod");
			Menu::Option("prop_ld_case_01_s");
			Menu::Option("prop_ld_contact_card");
			Menu::Option("prop_ld_container");
			Menu::Option("prop_ld_contain_dl");
			Menu::Option("prop_ld_contain_dl2");
			Menu::Option("prop_ld_contain_dr");
			Menu::Option("prop_ld_contain_dr2");
			Menu::Option("prop_ld_crate_01");
			Menu::Option("prop_ld_crate_lid_01");
			Menu::Option("prop_ld_crocclips01");
			Menu::Option("prop_ld_crocclips02");
			Menu::Option("prop_ld_dummy_rope");
			Menu::Option("prop_ld_fags_01");
			Menu::Option("prop_ld_fags_02");
			Menu::Option("prop_ld_fan_01");
			Menu::Option("prop_ld_fan_01_old");
			Menu::Option("prop_ld_faucet");
			Menu::Option("prop_ld_ferris_wheel");
			Menu::Option("prop_ld_fireaxe");
			Menu::Option("prop_ld_flow_bottle");
			Menu::Option("prop_ld_fragwall_01a");
			Menu::Option("prop_ld_garaged_01");
			Menu::Option("prop_ld_gold_tooth");
			Menu::Option("prop_ld_greenscreen_01");
			Menu::Option("prop_ld_handbag");
			Menu::Option("prop_ld_handbag_s");
			Menu::Option("prop_ld_hat_01");
			Menu::Option("prop_ld_haybail");
			Menu::Option("prop_ld_hdd_01");
			Menu::Option("prop_ld_health_pack");
			Menu::Option("prop_ld_hook");
			Menu::Option("prop_ld_int_safe_01");
			Menu::Option("prop_ld_jail_door");
			Menu::Option("prop_ld_jeans_01");
			Menu::Option("prop_ld_jeans_02");
			Menu::Option("prop_ld_jerrycan_01");
			Menu::Option("prop_ld_keypad_01");
			Menu::Option("prop_ld_keypad_01b");
			Menu::Option("prop_ld_keypad_01b_lod");
			Menu::Option("prop_ld_lap_top");
			Menu::Option("prop_ld_monitor_01");
			Menu::Option("prop_ld_peep_slider");
			Menu::Option("prop_ld_pipe_single_01");
			Menu::Option("prop_ld_planning_pin_01");
			Menu::Option("prop_ld_planning_pin_02");
			Menu::Option("prop_ld_planning_pin_03");
			Menu::Option("prop_ld_purse_01");
			Menu::Option("prop_ld_purse_01_lod");
			Menu::Option("prop_ld_rail_01");
			Menu::Option("prop_ld_rail_02");
			Menu::Option("prop_ld_rope_t");
			Menu::Option("prop_ld_rubble_01");
			Menu::Option("prop_ld_rubble_02");
			Menu::Option("prop_ld_rubble_03");
			Menu::Option("prop_ld_rubble_04");
			Menu::Option("prop_ld_rub_binbag_01");
			Menu::Option("prop_ld_scrap");
			Menu::Option("prop_ld_shirt_01");
			Menu::Option("prop_ld_shoe_01");
			Menu::Option("prop_ld_shoe_02");
			Menu::Option("prop_ld_shovel");
			Menu::Option("prop_ld_shovel_dirt");
			Menu::Option("prop_ld_snack_01");
			Menu::Option("prop_ld_suitcase_01");
			Menu::Option("prop_ld_suitcase_02");
			Menu::Option("prop_ld_test_01");
			Menu::Option("prop_ld_toilet_01");
			Menu::Option("prop_ld_tooth");
			Menu::Option("prop_ld_tshirt_01");
			Menu::Option("prop_ld_tshirt_02");
			Menu::Option("prop_ld_vault_door");
			Menu::Option("prop_ld_wallet_01");
			Menu::Option("prop_ld_wallet_01_s");
			Menu::Option("prop_ld_wallet_02");
			Menu::Option("prop_ld_wallet_pickup");
			Menu::Option("prop_ld_w_me_machette");
			Menu::Option("prop_leaf_blower_01");
			Menu::Option("prop_lectern_01");
			Menu::Option("prop_letterbox_04");
			Menu::Option("prop_lev_crate_01");
			Menu::Option("prop_lev_des_barge_01");
			Menu::Option("prop_lev_des_barge_02");
			Menu::Option("prop_lifeblurb_01");
			Menu::Option("prop_lifeblurb_01b");
			Menu::Option("prop_lifeblurb_02");
			Menu::Option("prop_lifeblurb_02b");
			Menu::Option("prop_life_ring_02");
			Menu::Option("prop_lift_overlay_01");
			Menu::Option("prop_lift_overlay_02");
			Menu::Option("prop_litter_picker");
			Menu::Option("prop_loggneon");
			Menu::Option("prop_logpile_05");
			Menu::Option("prop_logpile_06");
			Menu::Option("prop_logpile_06b");
			Menu::Option("prop_logpile_07");
			Menu::Option("prop_logpile_07b");
			Menu::Option("prop_log_01");
			Menu::Option("prop_log_02");
			Menu::Option("prop_log_03");
			Menu::Option("prop_loose_rag_01");
			Menu::Option("prop_lrggate_01c_l");
			Menu::Option("prop_lrggate_01c_r");
			Menu::Option("prop_lrggate_01_l");
			Menu::Option("prop_lrggate_01_pst");
			Menu::Option("prop_lrggate_01_r");
			Menu::Option("prop_lrggate_02_ld");
			Menu::Option("prop_lrggate_03a");
			Menu::Option("prop_lrggate_03b");
			Menu::Option("prop_lrggate_03b_ld");
			Menu::Option("prop_lrggate_04a");
			Menu::Option("prop_lrggate_05a");
			Menu::Option("prop_lrggate_06a");
			Menu::Option("prop_luggage_01a");
			Menu::Option("prop_luggage_02a");
			Menu::Option("prop_luggage_03a");
			Menu::Option("prop_luggage_04a");
			Menu::Option("prop_luggage_05a");
			Menu::Option("prop_luggage_06a");
			Menu::Option("prop_luggage_07a");
			Menu::Option("prop_luggage_08a");
			Menu::Option("prop_luggage_09a");
			Menu::Option("prop_magenta_door");
			Menu::Option("prop_makeup_trail_01");
			Menu::Option("prop_makeup_trail_02");
			Menu::Option("prop_map_door_01");
			Menu::Option("prop_mast_01");
			Menu::Option("prop_mat_box");
			Menu::Option("prop_mb_cargo_01a");
			Menu::Option("prop_mb_cargo_02a");
			Menu::Option("prop_mb_cargo_03a");
			Menu::Option("prop_mb_cargo_04a");
			Menu::Option("prop_mb_cargo_04b");
			Menu::Option("prop_mb_crate_01a");
			Menu::Option("prop_mb_crate_01a_set");
			Menu::Option("prop_mb_crate_01b");
			Menu::Option("prop_mb_hesco_06");
			Menu::Option("prop_mb_ordnance_01");
			Menu::Option("prop_mb_ordnance_03");
			Menu::Option("prop_mb_sandblock_01");
			Menu::Option("prop_mb_sandblock_02");
			Menu::Option("prop_mb_sandblock_03");
			Menu::Option("prop_mb_sandblock_04");
			Menu::Option("prop_mb_sandblock_05");
			Menu::Option("prop_medal_01");
			Menu::Option("prop_medstation_02");
			Menu::Option("prop_medstation_03");
			Menu::Option("prop_medstation_04");
			Menu::Option("prop_med_bag_01");
			Menu::Option("prop_med_bag_01b");
			Menu::Option("prop_med_jet_01");
			Menu::Option("prop_megaphone_01");
			Menu::Option("prop_mem_candle_04");
			Menu::Option("prop_mem_candle_05");
			Menu::Option("prop_mem_candle_06");
			Menu::Option("prop_mem_reef_01");
			Menu::Option("prop_mem_reef_02");
			Menu::Option("prop_mem_reef_03");
			Menu::Option("prop_mem_teddy_01");
			Menu::Option("prop_mem_teddy_02");
			Menu::Option("prop_metalfoodjar_01");
			Menu::Option("prop_metal_plates01");
			Menu::Option("prop_metal_plates02");
			Menu::Option("prop_meth_bag_01");
			Menu::Option("prop_michaels_credit_tv");
			Menu::Option("prop_michael_backpack");
			Menu::Option("prop_michael_balaclava");
			Menu::Option("prop_michael_door");
			Menu::Option("prop_michael_sec_id");
			Menu::Option("prop_microphone_02");
			Menu::Option("prop_microwave_1");
			Menu::Option("prop_micro_01");
			Menu::Option("prop_micro_02");
			Menu::Option("prop_micro_cs_01");
			Menu::Option("prop_micro_cs_01_door");
			Menu::Option("prop_military_pickup_01");
			Menu::Option("prop_mil_crate_01");
			Menu::Option("prop_mil_crate_02");
			Menu::Option("prop_minigun_01");
			Menu::Option("prop_mobile_mast_1");
			Menu::Option("prop_mobile_mast_2");
			Menu::Option("prop_money_bag_01");
			Menu::Option("prop_monitor_01c");
			Menu::Option("prop_monitor_01d");
			Menu::Option("prop_monitor_02");
			Menu::Option("prop_monitor_03b");
			Menu::Option("prop_motel_door_09");
			Menu::Option("prop_mouse_01");
			Menu::Option("prop_mouse_01a");
			Menu::Option("prop_mouse_01b");
			Menu::Option("prop_mouse_02");
			Menu::Option("prop_movie_rack");
			Menu::Option("prop_mp3_dock");
			Menu::Option("prop_mp_arrow_barrier_01");
			Menu::Option("prop_mp_barrier_01");
			Menu::Option("prop_mp_barrier_01b");
			Menu::Option("prop_mp_barrier_02");
			Menu::Option("prop_mp_barrier_02b");
			Menu::Option("prop_mp_base_marker");
			Menu::Option("prop_mp_boost_01");
			Menu::Option("prop_mp_cant_place_lrg");
			Menu::Option("prop_mp_cant_place_med");
			Menu::Option("prop_mp_cant_place_sm");
			Menu::Option("prop_mp_cone_01");
			Menu::Option("prop_mp_cone_02");
			Menu::Option("prop_mp_cone_03");
			Menu::Option("prop_mp_cone_04");
			Menu::Option("prop_mp_drug_package");
			Menu::Option("prop_mp_drug_pack_blue");
			Menu::Option("prop_mp_drug_pack_red");
			Menu::Option("prop_mp_icon_shad_lrg");
			Menu::Option("prop_mp_icon_shad_med");
			Menu::Option("prop_mp_icon_shad_sm");
			Menu::Option("prop_mp_max_out_lrg");
			Menu::Option("prop_mp_max_out_med");
			Menu::Option("prop_mp_max_out_sm");
			Menu::Option("prop_mp_num_0");
			Menu::Option("prop_mp_num_1");
			Menu::Option("prop_mp_num_2");
			Menu::Option("prop_mp_num_3");
			Menu::Option("prop_mp_num_4");
			Menu::Option("prop_mp_num_5");
			Menu::Option("prop_mp_num_6");
			Menu::Option("prop_mp_num_7");
			Menu::Option("prop_mp_num_8");
			Menu::Option("prop_mp_num_9");
			Menu::Option("prop_mp_placement");
			Menu::Option("prop_mp_placement_lrg");
			Menu::Option("prop_mp_placement_maxd");
			Menu::Option("prop_mp_placement_med");
			Menu::Option("prop_mp_placement_red");
			Menu::Option("prop_mp_placement_sm");
			Menu::Option("prop_mp_ramp_01");
			Menu::Option("prop_mp_ramp_02");
			Menu::Option("prop_mp_ramp_03");
			Menu::Option("prop_mp_repair");
			Menu::Option("prop_mp_repair_01");
			Menu::Option("prop_mp_respawn_02");
			Menu::Option("prop_mp_rocket_01");
			Menu::Option("prop_mp_spike_01");
			Menu::Option("prop_mr_rasberryclean");
			Menu::Option("prop_mr_raspberry_01");
			Menu::Option("prop_muscle_bench_01");
			Menu::Option("prop_muscle_bench_02");
			Menu::Option("prop_muscle_bench_03");
			Menu::Option("prop_muscle_bench_04");
			Menu::Option("prop_muscle_bench_05");
			Menu::Option("prop_muscle_bench_06");
			Menu::Option("prop_muster_wboard_01");
			Menu::Option("prop_muster_wboard_02");
			Menu::Option("prop_m_pack_int_01");
			Menu::Option("prop_necklace_board");
			Menu::Option("prop_news_disp_02a_s");
			Menu::Option("prop_new_drug_pack_01");
			Menu::Option("prop_nigel_bag_pickup");
			Menu::Option("prop_night_safe_01");
			Menu::Option("prop_notepad_01");
			Menu::Option("prop_notepad_02");
			Menu::Option("prop_novel_01");
			Menu::Option("prop_npc_phone");
			Menu::Option("prop_npc_phone_02");
			Menu::Option("prop_office_alarm_01");
			Menu::Option("prop_office_desk_01");
			Menu::Option("prop_offroad_bale01");
			Menu::Option("prop_offroad_bale02_l1_frag_");
			Menu::Option("prop_offroad_barrel01");
			Menu::Option("prop_offroad_tyres01");
			Menu::Option("prop_off_chair_01");
			Menu::Option("prop_off_chair_03");
			Menu::Option("prop_off_chair_04");
			Menu::Option("prop_off_chair_04b");
			Menu::Option("prop_off_chair_04_s");
			Menu::Option("prop_off_chair_05");
			Menu::Option("prop_off_phone_01");
			Menu::Option("prop_oiltub_01");
			Menu::Option("prop_oiltub_02");
			Menu::Option("prop_oiltub_03");
			Menu::Option("prop_oiltub_05");
			Menu::Option("prop_oiltub_06");
			Menu::Option("prop_oil_derrick_01");
			Menu::Option("prop_oil_guage_01");
			Menu::Option("prop_oil_spool_02");
			Menu::Option("prop_oil_valve_01");
			Menu::Option("prop_oil_valve_02");
			Menu::Option("prop_oil_wellhead_01");
			Menu::Option("prop_oil_wellhead_03");
			Menu::Option("prop_oil_wellhead_04");
			Menu::Option("prop_oil_wellhead_05");
			Menu::Option("prop_oil_wellhead_06");
			Menu::Option("prop_oldplough1");
			Menu::Option("prop_old_boot");
			Menu::Option("prop_old_churn_01");
			Menu::Option("prop_old_churn_02");
			Menu::Option("prop_old_deck_chair");
			Menu::Option("prop_old_deck_chair_02");
			Menu::Option("prop_old_farm_01");
			Menu::Option("prop_old_farm_02");
			Menu::Option("prop_old_wood_chair");
			Menu::Option("prop_old_wood_chair_lod");
			Menu::Option("prop_orang_can_01");
			Menu::Option("prop_outdoor_fan_01");
			Menu::Option("prop_out_door_speaker");
			Menu::Option("prop_overalls_01");
			Menu::Option("prop_owl_totem_01");
			Menu::Option("prop_paints_can01");
			Menu::Option("prop_paints_can02");
			Menu::Option("prop_paints_can03");
			Menu::Option("prop_paints_can04");
			Menu::Option("prop_paints_can05");
			Menu::Option("prop_paints_can06");
			Menu::Option("prop_paints_can07");
			Menu::Option("prop_paint_brush01");
			Menu::Option("prop_paint_brush02");
			Menu::Option("prop_paint_brush03");
			Menu::Option("prop_paint_brush04");
			Menu::Option("prop_paint_brush05");
			Menu::Option("prop_paint_roller");
			Menu::Option("prop_paint_spray01a");
			Menu::Option("prop_paint_spray01b");
			Menu::Option("prop_paint_stepl01");
			Menu::Option("prop_paint_stepl01b");
			Menu::Option("prop_paint_stepl02");
			Menu::Option("prop_paint_tray");
			Menu::Option("prop_paint_wpaper01");
			Menu::Option("prop_pallettruck_01");
			Menu::Option("prop_palm_fan_02_a");
			Menu::Option("prop_palm_fan_02_b");
			Menu::Option("prop_palm_fan_03_a");
			Menu::Option("prop_palm_fan_03_b");
			Menu::Option("prop_palm_fan_03_c");
			Menu::Option("prop_palm_fan_03_d");
			Menu::Option("prop_palm_fan_04_a");
			Menu::Option("prop_palm_fan_04_b");
			Menu::Option("prop_palm_fan_04_c");
			Menu::Option("prop_palm_fan_04_d");
			Menu::Option("prop_palm_huge_01a");
			Menu::Option("prop_palm_huge_01b");
			Menu::Option("prop_palm_med_01a");
			Menu::Option("prop_palm_med_01b");
			Menu::Option("prop_palm_med_01c");
			Menu::Option("prop_palm_med_01d");
			Menu::Option("prop_palm_sm_01a");
			Menu::Option("prop_palm_sm_01d");
			Menu::Option("prop_palm_sm_01e");
			Menu::Option("prop_palm_sm_01f");
			Menu::Option("prop_paper_bag_01");
			Menu::Option("prop_paper_bag_small");
			Menu::Option("prop_paper_ball");
			Menu::Option("prop_paper_box_01");
			Menu::Option("prop_paper_box_02");
			Menu::Option("prop_paper_box_03");
			Menu::Option("prop_paper_box_04");
			Menu::Option("prop_paper_box_05");
			Menu::Option("prop_pap_camera_01");
			Menu::Option("prop_parachute");
			Menu::Option("prop_parapack_01");
			Menu::Option("prop_parasol_01");
			Menu::Option("prop_parasol_01_b");
			Menu::Option("prop_parasol_01_c");
			Menu::Option("prop_parasol_01_down");
			Menu::Option("prop_parasol_02");
			Menu::Option("prop_parasol_02_b");
			Menu::Option("prop_parasol_02_c");
			Menu::Option("prop_parasol_03");
			Menu::Option("prop_parasol_03_b");
			Menu::Option("prop_parasol_03_c");
			Menu::Option("prop_parasol_04e");
			Menu::Option("prop_parasol_04e_lod1");
			Menu::Option("prop_parasol_bh_48");
			Menu::Option("prop_parking_sign_06");
			Menu::Option("prop_parking_sign_07");
			Menu::Option("prop_parking_sign_1");
			Menu::Option("prop_parking_sign_2");
			Menu::Option("prop_parking_wand_01");
			Menu::Option("prop_park_ticket_01");
			Menu::Option("prop_partsbox_01");
			Menu::Option("prop_passport_01");
			Menu::Option("prop_patio_heater_01");
			Menu::Option("prop_patio_lounger1");
			Menu::Option("prop_patio_lounger1b");
			Menu::Option("prop_patio_lounger1_table");
			Menu::Option("prop_patio_lounger_2");
			Menu::Option("prop_patio_lounger_3");
			Menu::Option("prop_patriotneon");
			Menu::Option("prop_paynspray_door_l");
			Menu::Option("prop_paynspray_door_r");
			Menu::Option("prop_pc_01a");
			Menu::Option("prop_pc_02a");
			Menu::Option("prop_peanut_bowl_01");
			Menu::Option("prop_ped_pic_01");
			Menu::Option("prop_ped_pic_01_sm");
			Menu::Option("prop_ped_pic_02");
			Menu::Option("prop_ped_pic_02_sm");
			Menu::Option("prop_ped_pic_03");
			Menu::Option("prop_ped_pic_03_sm");
			Menu::Option("prop_ped_pic_04");
			Menu::Option("prop_ped_pic_04_sm");
			Menu::Option("prop_ped_pic_05");
			Menu::Option("prop_ped_pic_05_sm");
			Menu::Option("prop_ped_pic_06");
			Menu::Option("prop_ped_pic_06_sm");
			Menu::Option("prop_ped_pic_07");
			Menu::Option("prop_ped_pic_07_sm");
			Menu::Option("prop_ped_pic_08");
			Menu::Option("prop_ped_pic_08_sm");
			Menu::Option("prop_pencil_01");
			Menu::Option("prop_pharm_sign_01");
			Menu::Option("prop_phonebox_05a");
			Menu::Option("prop_phone_ing");
			Menu::Option("prop_phone_ing_02");
			Menu::Option("prop_phone_ing_03");
			Menu::Option("prop_phone_overlay_01");
			Menu::Option("prop_phone_overlay_02");
			Menu::Option("prop_phone_overlay_anim");
			Menu::Option("prop_phone_proto");
			Menu::Option("prop_phone_proto_back");
			Menu::Option("prop_phone_proto_battery");
			Menu::Option("prop_picnictable_02");
			Menu::Option("prop_piercing_gun");
			Menu::Option("prop_pier_kiosk_01");
			Menu::Option("prop_pier_kiosk_02");
			Menu::Option("prop_pier_kiosk_03");
			Menu::Option("prop_pile_dirt_01");
			Menu::Option("prop_pile_dirt_02");
			Menu::Option("prop_pile_dirt_03");
			Menu::Option("prop_pile_dirt_04");
			Menu::Option("prop_pile_dirt_06");
			Menu::Option("prop_pile_dirt_07");
			Menu::Option("prop_ping_pong");
			Menu::Option("prop_pipes_01a");
			Menu::Option("prop_pipes_01b");
			Menu::Option("prop_pipes_03b");
			Menu::Option("prop_pipes_04a");
			Menu::Option("prop_pipes_05a");
			Menu::Option("prop_pipes_conc_01");
			Menu::Option("prop_pipes_conc_02");
			Menu::Option("prop_pipe_single_01");
			Menu::Option("prop_pistol_holster");
			Menu::Option("prop_pitcher_01_cs");
			Menu::Option("prop_pizza_box_01");
			Menu::Option("prop_pizza_box_02");
			Menu::Option("prop_pizza_oven_01");
			Menu::Option("prop_planer_01");
			Menu::Option("prop_plant_01a");
			Menu::Option("prop_plant_01b");
			Menu::Option("prop_plant_base_01");
			Menu::Option("prop_plant_base_02");
			Menu::Option("prop_plant_base_03");
			Menu::Option("prop_plant_cane_01a");
			Menu::Option("prop_plant_cane_01b");
			Menu::Option("prop_plant_cane_02a");
			Menu::Option("prop_plant_cane_02b");
			Menu::Option("prop_plant_clover_01");
			Menu::Option("prop_plant_clover_02");
			Menu::Option("prop_plant_fern_01a");
			Menu::Option("prop_plant_fern_01b");
			Menu::Option("prop_plant_fern_02a");
			Menu::Option("prop_plant_fern_02b");
			Menu::Option("prop_plant_fern_02c");
			Menu::Option("prop_plant_flower_01");
			Menu::Option("prop_plant_flower_02");
			Menu::Option("prop_plant_flower_03");
			Menu::Option("prop_plant_flower_04");
			Menu::Option("prop_plant_group_01");
			Menu::Option("prop_plant_group_02");
			Menu::Option("prop_plant_group_03");
			Menu::Option("prop_plant_group_04");
			Menu::Option("prop_plant_group_05");
			Menu::Option("prop_plant_group_05b");
			Menu::Option("prop_plant_group_05c");
			Menu::Option("prop_plant_group_05d");
			Menu::Option("prop_plant_group_06a");
			Menu::Option("prop_plant_group_06b");
			Menu::Option("prop_plant_group_06c");
			Menu::Option("prop_plant_int_02a");
			Menu::Option("prop_plant_int_02b");
			Menu::Option("prop_plant_int_05a");
			Menu::Option("prop_plant_int_05b");
			Menu::Option("prop_plant_int_06a");
			Menu::Option("prop_plant_int_06b");
			Menu::Option("prop_plant_int_06c");
			Menu::Option("prop_plant_paradise");
			Menu::Option("prop_plant_paradise_b");
			Menu::Option("prop_plastic_cup_02");
			Menu::Option("prop_plas_barier_01a");
			Menu::Option("prop_plate_04");
			Menu::Option("prop_plate_stand_01");
			Menu::Option("prop_plate_warmer");
			Menu::Option("prop_player_gasmask");
			Menu::Option("prop_player_phone_01");
			Menu::Option("prop_player_phone_02");
			Menu::Option("prop_pliers_01");
			Menu::Option("prop_plywoodpile_01a");
			Menu::Option("prop_plywoodpile_01b");
			Menu::Option("prop_podium_mic");
			Menu::Option("prop_police_door_l");
			Menu::Option("prop_police_door_l_dam");
			Menu::Option("prop_police_door_r");
			Menu::Option("prop_police_door_r_dam");
			Menu::Option("prop_police_door_surround");
			Menu::Option("prop_police_phone");
			Menu::Option("prop_police_radio_handset");
			Menu::Option("prop_police_radio_main");
			Menu::Option("prop_poly_bag_01");
			Menu::Option("prop_poly_bag_money");
			Menu::Option("prop_poolball_1");
			Menu::Option("prop_poolball_10");
			Menu::Option("prop_poolball_11");
			Menu::Option("prop_poolball_12");
			Menu::Option("prop_poolball_13");
			Menu::Option("prop_poolball_14");
			Menu::Option("prop_poolball_15");
			Menu::Option("prop_poolball_2");
			Menu::Option("prop_poolball_3");
			Menu::Option("prop_poolball_4");
			Menu::Option("prop_poolball_5");
			Menu::Option("prop_poolball_6");
			Menu::Option("prop_poolball_7");
			Menu::Option("prop_poolball_8");
			Menu::Option("prop_poolball_9");
			Menu::Option("prop_poolball_cue");
			Menu::Option("prop_poolskimmer");
			Menu::Option("prop_pooltable_02");
			Menu::Option("prop_pooltable_3b");
			Menu::Option("prop_pool_ball_01");
			Menu::Option("prop_pool_cue");
			Menu::Option("prop_pool_rack_01");
			Menu::Option("prop_pool_rack_02");
			Menu::Option("prop_pool_tri");
			Menu::Option("prop_porn_mag_01");
			Menu::Option("prop_porn_mag_02");
			Menu::Option("prop_porn_mag_03");
			Menu::Option("prop_porn_mag_04");
			Menu::Option("prop_portable_hifi_01");
			Menu::Option("prop_portacabin01");
			Menu::Option("prop_portasteps_01");
			Menu::Option("prop_portasteps_02");
			Menu::Option("prop_postcard_rack");
			Menu::Option("prop_poster_tube_01");
			Menu::Option("prop_poster_tube_02");
			Menu::Option("prop_postit_drive");
			Menu::Option("prop_postit_gun");
			Menu::Option("prop_postit_it");
			Menu::Option("prop_postit_lock");
			Menu::Option("prop_potatodigger");
			Menu::Option("prop_pot_01");
			Menu::Option("prop_pot_02");
			Menu::Option("prop_pot_03");
			Menu::Option("prop_pot_04");
			Menu::Option("prop_pot_05");
			Menu::Option("prop_pot_06");
			Menu::Option("prop_pot_plant_02a");
			Menu::Option("prop_pot_plant_02b");
			Menu::Option("prop_pot_plant_02c");
			Menu::Option("prop_pot_plant_02d");
			Menu::Option("prop_pot_plant_03a");
			Menu::Option("prop_pot_plant_04a");
			Menu::Option("prop_pot_plant_05d_l1");
			Menu::Option("prop_pot_plant_bh1");
			Menu::Option("prop_pot_rack");
			Menu::Option("prop_power_cell");
			Menu::Option("prop_power_cord_01");
			Menu::Option("prop_premier_fence_01");
			Menu::Option("prop_premier_fence_02");
			Menu::Option("prop_printer_01");
			Menu::Option("prop_printer_02");
			Menu::Option("prop_pris_bars_01");
			Menu::Option("prop_pris_bench_01");
			Menu::Option("prop_pris_door_01_l");
			Menu::Option("prop_pris_door_01_r");
			Menu::Option("prop_pris_door_02");
			Menu::Option("prop_pris_door_03");
			Menu::Option("prop_prlg_gravestone_05a_l1");
			Menu::Option("prop_prlg_gravestone_06a");
			Menu::Option("prop_projector_overlay");
			Menu::Option("prop_prologue_phone");
			Menu::Option("prop_prop_tree_01");
			Menu::Option("prop_prop_tree_02");
			Menu::Option("prop_protest_sign_01");
			Menu::Option("prop_protest_table_01");
			Menu::Option("prop_prototype_minibomb");
			Menu::Option("prop_proxy_chateau_table");
			Menu::Option("prop_punch_bag_l");
			Menu::Option("prop_pylon_01");
			Menu::Option("prop_pylon_02");
			Menu::Option("prop_pylon_03");
			Menu::Option("prop_pylon_04");
			Menu::Option("prop_p_jack_03_col");
			Menu::Option("prop_p_spider_01a");
			Menu::Option("prop_p_spider_01c");
			Menu::Option("prop_p_spider_01d");
			Menu::Option("prop_ql_revolving_door");
			Menu::Option("prop_quad_grid_line");
			Menu::Option("prop_radiomast01");
			Menu::Option("prop_radiomast02");
			Menu::Option("prop_rad_waste_barrel_01");
			Menu::Option("prop_ragganeon");
			Menu::Option("prop_rag_01");
			Menu::Option("prop_railsleepers01");
			Menu::Option("prop_railsleepers02");
			Menu::Option("prop_railstack01");
			Menu::Option("prop_railstack02");
			Menu::Option("prop_railstack03");
			Menu::Option("prop_railstack04");
			Menu::Option("prop_railstack05");
			Menu::Option("prop_rail_boxcar");
			Menu::Option("prop_rail_boxcar2");
			Menu::Option("prop_rail_boxcar3");
			Menu::Option("prop_rail_boxcar4");
			Menu::Option("prop_rail_boxcar5");
			Menu::Option("prop_rail_boxcar5_d");
			Menu::Option("prop_rail_buffer_01");
			Menu::Option("prop_rail_buffer_02");
			Menu::Option("prop_rail_controller");
			Menu::Option("prop_rail_crane_01");
			Menu::Option("prop_rail_points01");
			Menu::Option("prop_rail_points02");
			Menu::Option("prop_rail_sigbox01");
			Menu::Option("prop_rail_sigbox02");
			Menu::Option("prop_rail_signals02");
			Menu::Option("prop_rail_tankcar");
			Menu::Option("prop_rail_tankcar2");
			Menu::Option("prop_rail_tankcar3");
			Menu::Option("prop_rail_wellcar");
			Menu::Option("prop_rail_wellcar2");
			Menu::Option("prop_range_target_01");
			Menu::Option("prop_range_target_02");
			Menu::Option("prop_range_target_03");
			Menu::Option("prop_rebar_pile01");
			Menu::Option("prop_recyclebin_02a");
			Menu::Option("prop_recyclebin_02b");
			Menu::Option("prop_recyclebin_02_c");
			Menu::Option("prop_recyclebin_02_d");
			Menu::Option("prop_recyclebin_03_a");
			Menu::Option("prop_recyclebin_04_a");
			Menu::Option("prop_recyclebin_04_b");
			Menu::Option("prop_recyclebin_05_a");
			Menu::Option("prop_ret_door");
			Menu::Option("prop_ret_door_02");
			Menu::Option("prop_ret_door_03");
			Menu::Option("prop_ret_door_04");
			Menu::Option("prop_rf_conc_pillar");
			Menu::Option("prop_riding_crop_01");
			Menu::Option("prop_riot_shield");
			Menu::Option("prop_rio_del_01");
			Menu::Option("prop_roadcone01a");
			Menu::Option("prop_roadcone01b");
			Menu::Option("prop_roadcone01c");
			Menu::Option("prop_roadcone02a");
			Menu::Option("prop_roadcone02b");
			Menu::Option("prop_roadcone02c");
			Menu::Option("prop_roadheader_01");
			Menu::Option("prop_rock_1_a");
			Menu::Option("prop_rock_1_b");
			Menu::Option("prop_rock_1_c");
			Menu::Option("prop_rock_1_d");
			Menu::Option("prop_rock_1_e");
			Menu::Option("prop_rock_1_f");
			Menu::Option("prop_rock_1_g");
			Menu::Option("prop_rock_1_h");
			Menu::Option("prop_rock_1_i");
			Menu::Option("prop_rock_2_a");
			Menu::Option("prop_rock_2_c");
			Menu::Option("prop_rock_2_d");
			Menu::Option("prop_rock_2_f");
			Menu::Option("prop_rock_2_g");
			Menu::Option("prop_rock_3_a");
			Menu::Option("prop_rock_3_b");
			Menu::Option("prop_rock_3_c");
			Menu::Option("prop_rock_3_d");
			Menu::Option("prop_rock_3_e");
			Menu::Option("prop_rock_3_f");
			Menu::Option("prop_rock_3_g");
			Menu::Option("prop_rock_3_h");
			Menu::Option("prop_rock_3_i");
			Menu::Option("prop_rock_3_j");
			Menu::Option("prop_rock_4_c");
			Menu::Option("prop_rock_4_d");
			Menu::Option("prop_rock_chair_01");
			Menu::Option("prop_rolled_sock_01");
			Menu::Option("prop_rolled_sock_02");
			Menu::Option("prop_rolled_yoga_mat");
			Menu::Option("prop_roller_car_01");
			Menu::Option("prop_roller_car_02");
			Menu::Option("prop_ron_door_01");
			Menu::Option("prop_roofpipe_01");
			Menu::Option("prop_roofpipe_02");
			Menu::Option("prop_roofpipe_03");
			Menu::Option("prop_roofpipe_04");
			Menu::Option("prop_roofpipe_05");
			Menu::Option("prop_roofpipe_06");
			Menu::Option("prop_roofvent_011a");
			Menu::Option("prop_roofvent_01a");
			Menu::Option("prop_roofvent_01b");
			Menu::Option("prop_roofvent_02a");
			Menu::Option("prop_roofvent_02b");
			Menu::Option("prop_roofvent_03a");
			Menu::Option("prop_roofvent_04a");
			Menu::Option("prop_roofvent_05a");
			Menu::Option("prop_roofvent_05b");
			Menu::Option("prop_roofvent_07a");
			Menu::Option("prop_roofvent_08a");
			Menu::Option("prop_roofvent_09a");
			Menu::Option("prop_roofvent_10a");
			Menu::Option("prop_roofvent_10b");
			Menu::Option("prop_roofvent_11b");
			Menu::Option("prop_roofvent_11c");
			Menu::Option("prop_roofvent_12a");
			Menu::Option("prop_roofvent_13a");
			Menu::Option("prop_roofvent_15a");
			Menu::Option("prop_roofvent_16a");
			Menu::Option("prop_rope_family_3");
			Menu::Option("prop_rope_hook_01");
			Menu::Option("prop_roundbailer01");
			Menu::Option("prop_roundbailer02");
			Menu::Option("prop_rub_bike_01");
			Menu::Option("prop_rub_bike_02");
			Menu::Option("prop_rub_bike_03");
			Menu::Option("prop_rub_binbag_sd_01");
			Menu::Option("prop_rub_binbag_sd_02");
			Menu::Option("prop_rub_busdoor_01");
			Menu::Option("prop_rub_busdoor_02");
			Menu::Option("prop_rub_buswreck_01");
			Menu::Option("prop_rub_buswreck_03");
			Menu::Option("prop_rub_buswreck_06");
			Menu::Option("prop_rub_cabinet");
			Menu::Option("prop_rub_cabinet01");
			Menu::Option("prop_rub_cabinet02");
			Menu::Option("prop_rub_cabinet03");
			Menu::Option("prop_rub_cage01a");
			Menu::Option("prop_rub_carpart_02");
			Menu::Option("prop_rub_carpart_03");
			Menu::Option("prop_rub_carpart_04");
			Menu::Option("prop_rub_chassis_01");
			Menu::Option("prop_rub_chassis_02");
			Menu::Option("prop_rub_chassis_03");
			Menu::Option("prop_rub_cont_01a");
			Menu::Option("prop_rub_cont_01b");
			Menu::Option("prop_rub_cont_01c");
			Menu::Option("prop_rub_flotsam_01");
			Menu::Option("prop_rub_flotsam_02");
			Menu::Option("prop_rub_flotsam_03");
			Menu::Option("prop_rub_frklft");
			Menu::Option("prop_rub_litter_01");
			Menu::Option("prop_rub_litter_02");
			Menu::Option("prop_rub_litter_03");
			Menu::Option("prop_rub_litter_03b");
			Menu::Option("prop_rub_litter_03c");
			Menu::Option("prop_rub_litter_04");
			Menu::Option("prop_rub_litter_04b");
			Menu::Option("prop_rub_litter_05");
			Menu::Option("prop_rub_litter_06");
			Menu::Option("prop_rub_litter_07");
			Menu::Option("prop_rub_litter_09");
			Menu::Option("prop_rub_litter_8");
			Menu::Option("prop_rub_matress_01");
			Menu::Option("prop_rub_matress_02");
			Menu::Option("prop_rub_matress_03");
			Menu::Option("prop_rub_matress_04");
			Menu::Option("prop_rub_monitor");
			Menu::Option("prop_rub_pile_01");
			Menu::Option("prop_rub_pile_02");
			Menu::Option("prop_rub_planks_01");
			Menu::Option("prop_rub_planks_02");
			Menu::Option("prop_rub_planks_03");
			Menu::Option("prop_rub_planks_04");
			Menu::Option("prop_rub_railwreck_1");
			Menu::Option("prop_rub_railwreck_2");
			Menu::Option("prop_rub_railwreck_3");
			Menu::Option("prop_rub_scrap_02");
			Menu::Option("prop_rub_scrap_03");
			Menu::Option("prop_rub_scrap_04");
			Menu::Option("prop_rub_scrap_05");
			Menu::Option("prop_rub_scrap_06");
			Menu::Option("prop_rub_scrap_07");
			Menu::Option("prop_rub_stool");
			Menu::Option("prop_rub_sunktyre");
			Menu::Option("prop_rub_t34");
			Menu::Option("prop_rub_trainers_01");
			Menu::Option("prop_rub_trolley01a");
			Menu::Option("prop_rub_trolley02a");
			Menu::Option("prop_rub_trolley03a");
			Menu::Option("prop_rub_trukwreck_1");
			Menu::Option("prop_rub_trukwreck_2");
			Menu::Option("prop_rub_tyre_01");
			Menu::Option("prop_rub_tyre_02");
			Menu::Option("prop_rub_tyre_03");
			Menu::Option("prop_rub_tyre_dam1");
			Menu::Option("prop_rub_tyre_dam2");
			Menu::Option("prop_rub_tyre_dam3");
			Menu::Option("prop_rub_washer_01");
			Menu::Option("prop_rub_wheel_01");
			Menu::Option("prop_rub_wheel_02");
			Menu::Option("prop_rub_wreckage_3");
			Menu::Option("prop_rub_wreckage_4");
			Menu::Option("prop_rub_wreckage_5");
			Menu::Option("prop_rub_wreckage_6");
			Menu::Option("prop_rub_wreckage_7");
			Menu::Option("prop_rub_wreckage_8");
			Menu::Option("prop_rub_wreckage_9");
			Menu::Option("prop_rural_windmill_l1");
			Menu::Option("prop_rural_windmill_l2");
			Menu::Option("prop_rus_olive");
			Menu::Option("prop_rus_olive_wint");
			Menu::Option("prop_sacktruck_01");
			Menu::Option("prop_sacktruck_02a");
			Menu::Option("prop_safety_glasses");
			Menu::Option("prop_sam_01");
			Menu::Option("prop_sandwich_01");
			Menu::Option("prop_satdish_2_a");
			Menu::Option("prop_satdish_2_f");
			Menu::Option("prop_satdish_2_g");
			Menu::Option("prop_satdish_3_b");
			Menu::Option("prop_satdish_3_c");
			Menu::Option("prop_satdish_3_d");
			Menu::Option("prop_satdish_l_01");
			Menu::Option("prop_satdish_s_03");
			Menu::Option("prop_satdish_s_05a");
			Menu::Option("prop_satdish_s_05b");
			Menu::Option("prop_sc1_06_gate_l");
			Menu::Option("prop_sc1_06_gate_r");
			Menu::Option("prop_sc1_12_door");
			Menu::Option("prop_sc1_21_g_door_01");
			Menu::Option("prop_scaffold_pole");
			Menu::Option("prop_scafold_01a");
			Menu::Option("prop_scafold_01c");
			Menu::Option("prop_scafold_01f");
			Menu::Option("prop_scafold_02a");
			Menu::Option("prop_scafold_02c");
			Menu::Option("prop_scafold_03a");
			Menu::Option("prop_scafold_03b");
			Menu::Option("prop_scafold_03c");
			Menu::Option("prop_scafold_03f");
			Menu::Option("prop_scafold_04a");
			Menu::Option("prop_scafold_05a");
			Menu::Option("prop_scafold_06a");
			Menu::Option("prop_scafold_06b");
			Menu::Option("prop_scafold_06c");
			Menu::Option("prop_scafold_07a");
			Menu::Option("prop_scafold_08a");
			Menu::Option("prop_scafold_09a");
			Menu::Option("prop_scafold_frame1a");
			Menu::Option("prop_scafold_frame1b");
			Menu::Option("prop_scafold_frame1c");
			Menu::Option("prop_scafold_frame1f");
			Menu::Option("prop_scafold_frame2a");
			Menu::Option("prop_scafold_frame2b");
			Menu::Option("prop_scafold_frame2c");
			Menu::Option("prop_scafold_frame3a");
			Menu::Option("prop_scafold_frame3c");
			Menu::Option("prop_scafold_rail_01");
			Menu::Option("prop_scafold_rail_02");
			Menu::Option("prop_scafold_rail_03");
			Menu::Option("prop_scafold_xbrace");
			Menu::Option("prop_scalpel");
			Menu::Option("prop_scn_police_torch");
			Menu::Option("prop_scourer_01");
			Menu::Option("prop_scrap_2_crate");
			Menu::Option("prop_scrap_win_01");
			Menu::Option("prop_scrim_01");
			Menu::Option("prop_scythemower");
			Menu::Option("prop_section_garage_01");
			Menu::Option("prop_securityvan_lightrig");
			Menu::Option("prop_security_case_01");
			Menu::Option("prop_security_case_02");
			Menu::Option("prop_sec_gate_01b");
			Menu::Option("prop_sec_gate_01c");
			Menu::Option("prop_sec_gate_01d");
			Menu::Option("prop_set_generator_01");
			Menu::Option("prop_sewing_fabric");
			Menu::Option("prop_sewing_machine");
			Menu::Option("prop_sglasses_stand_01");
			Menu::Option("prop_sglasses_stand_02");
			Menu::Option("prop_sglasses_stand_02b");
			Menu::Option("prop_sglasses_stand_03");
			Menu::Option("prop_sglasss_1b_lod");
			Menu::Option("prop_sglasss_1_lod");
			Menu::Option("prop_shamal_crash");
			Menu::Option("prop_shelves_01");
			Menu::Option("prop_shelves_02");
			Menu::Option("prop_shelves_03");
			Menu::Option("prop_shopping_bags01");
			Menu::Option("prop_shopping_bags02");
			Menu::Option("prop_shop_front_door_l");
			Menu::Option("prop_shop_front_door_r");
			Menu::Option("prop_shots_glass_cs");
			Menu::Option("prop_shower_01");
			Menu::Option("prop_shower_rack_01");
			Menu::Option("prop_shower_towel");
			Menu::Option("prop_showroom_door_l");
			Menu::Option("prop_showroom_door_r");
			Menu::Option("prop_showroom_glass_1b");
			Menu::Option("prop_shredder_01");
			Menu::Option("prop_shrub_rake");
			Menu::Option("prop_shuttering01");
			Menu::Option("prop_shuttering02");
			Menu::Option("prop_shuttering03");
			Menu::Option("prop_shuttering04");
			Menu::Option("prop_sh_beer_pissh_01");
			Menu::Option("prop_sh_bong_01");
			Menu::Option("prop_sh_cigar_01");
			Menu::Option("prop_sh_joint_01");
			Menu::Option("prop_sh_mr_rasp_01");
			Menu::Option("prop_sh_shot_glass");
			Menu::Option("prop_sh_tall_glass");
			Menu::Option("prop_sh_tt_fridgedoor");
			Menu::Option("prop_sh_wine_glass");
			Menu::Option("prop_side_lights");
			Menu::Option("prop_side_spreader");
			Menu::Option("prop_sign_airp_01a");
			Menu::Option("prop_sign_airp_02a");
			Menu::Option("prop_sign_airp_02b");
			Menu::Option("prop_sign_big_01");
			Menu::Option("prop_sign_mallet");
			Menu::Option("prop_sign_road_04g_l1");
			Menu::Option("prop_single_grid_line");
			Menu::Option("prop_single_rose");
			Menu::Option("prop_sink_01");
			Menu::Option("prop_sink_02");
			Menu::Option("prop_sink_03");
			Menu::Option("prop_sink_04");
			Menu::Option("prop_sink_05");
			Menu::Option("prop_sink_06");
			Menu::Option("prop_skate_flatramp");
			Menu::Option("prop_skate_funbox");
			Menu::Option("prop_skate_halfpipe");
			Menu::Option("prop_skate_kickers");
			Menu::Option("prop_skate_quartpipe");
			Menu::Option("prop_skate_rail");
			Menu::Option("prop_skate_spiner");
			Menu::Option("prop_skid_chair_01");
			Menu::Option("prop_skid_chair_02");
			Menu::Option("prop_skid_chair_03");
			Menu::Option("prop_skid_sleepbag_1");
			Menu::Option("prop_skid_tent_01");
			Menu::Option("prop_skid_tent_01b");
			Menu::Option("prop_skid_tent_03");
			Menu::Option("prop_skip_01a");
			Menu::Option("prop_skip_02a");
			Menu::Option("prop_skip_03");
			Menu::Option("prop_skip_04");
			Menu::Option("prop_skip_05a");
			Menu::Option("prop_skip_05b");
			Menu::Option("prop_skip_06a");
			Menu::Option("prop_skip_08a");
			Menu::Option("prop_skip_08b");
			Menu::Option("prop_skip_10a");
			Menu::Option("prop_skip_rope_01");
			Menu::Option("prop_skunk_bush_01");
			Menu::Option("prop_skylight_01");
			Menu::Option("prop_skylight_02");
			Menu::Option("prop_skylight_03");
			Menu::Option("prop_skylight_04");
			Menu::Option("prop_skylight_05");
			Menu::Option("prop_skylight_06a");
			Menu::Option("prop_skylight_06b");
			Menu::Option("prop_skylight_06c");
			Menu::Option("prop_sky_cover_01");
			Menu::Option("prop_slacks_01");
			Menu::Option("prop_slacks_02");
			Menu::Option("prop_sluicegate");
			Menu::Option("prop_sluicegatel");
			Menu::Option("prop_sluicegater");
			Menu::Option("prop_slush_dispenser");
			Menu::Option("prop_sm1_11_doorl");
			Menu::Option("prop_sm1_11_doorr");
			Menu::Option("prop_sm1_11_garaged");
			Menu::Option("prop_smg_holster_01");
			Menu::Option("prop_sm_10_mp_door");
			Menu::Option("prop_sm_14_mp_gar");
			Menu::Option("prop_sm_19_clock");
			Menu::Option("prop_sm_27_door");
			Menu::Option("prop_sm_27_gate");
			Menu::Option("prop_sm_27_gate_02");
			Menu::Option("prop_sm_27_gate_03");
			Menu::Option("prop_sm_27_gate_04");
			Menu::Option("prop_sm_locker_door");
			Menu::Option("prop_snow_bailer_01");
			Menu::Option("prop_snow_barrel_pile_03");
			Menu::Option("prop_snow_bench_01");
			Menu::Option("prop_snow_bin_01");
			Menu::Option("prop_snow_bin_02");
			Menu::Option("prop_snow_bush_01_a");
			Menu::Option("prop_snow_bush_02_a");
			Menu::Option("prop_snow_bush_02_b");
			Menu::Option("prop_snow_bush_03");
			Menu::Option("prop_snow_bush_04");
			Menu::Option("prop_snow_bush_04b");
			Menu::Option("prop_snow_cam_03");
			Menu::Option("prop_snow_cam_03a");
			Menu::Option("prop_snow_diggerbkt_01");
			Menu::Option("prop_snow_dumpster_01");
			Menu::Option("prop_snow_elecbox_16");
			Menu::Option("prop_snow_facgate_01");
			Menu::Option("prop_snow_field_01");
			Menu::Option("prop_snow_field_02");
			Menu::Option("prop_snow_field_03");
			Menu::Option("prop_snow_field_04");
			Menu::Option("prop_snow_flower_01");
			Menu::Option("prop_snow_flower_02");
			Menu::Option("prop_snow_fnclink_03crnr2");
			Menu::Option("prop_snow_fnclink_03h");
			Menu::Option("prop_snow_fnclink_03i");
			Menu::Option("prop_snow_fncwood_14a");
			Menu::Option("prop_snow_fncwood_14b");
			Menu::Option("prop_snow_fncwood_14c");
			Menu::Option("prop_snow_fncwood_14d");
			Menu::Option("prop_snow_fncwood_14e");
			Menu::Option("prop_snow_fnc_01");
			Menu::Option("prop_snow_gate_farm_03");
			Menu::Option("prop_snow_grain_01");
			Menu::Option("prop_snow_grass_01");
			Menu::Option("prop_snow_light_01");
			Menu::Option("prop_snow_oldlight_01b");
			Menu::Option("prop_snow_rail_signals02");
			Menu::Option("prop_snow_rub_trukwreck_2");
			Menu::Option("prop_snow_side_spreader_01");
			Menu::Option("prop_snow_streetlight01");
			Menu::Option("prop_snow_streetlight_01_frag_");
			Menu::Option("prop_snow_sub_frame_01a");
			Menu::Option("prop_snow_sub_frame_04b");
			Menu::Option("prop_snow_telegraph_01a");
			Menu::Option("prop_snow_telegraph_02a");
			Menu::Option("prop_snow_telegraph_03");
			Menu::Option("prop_snow_traffic_rail_1a");
			Menu::Option("prop_snow_traffic_rail_1b");
			Menu::Option("prop_snow_trailer01");
			Menu::Option("prop_snow_tree_03_e");
			Menu::Option("prop_snow_tree_03_h");
			Menu::Option("prop_snow_tree_03_i");
			Menu::Option("prop_snow_tree_04_d");
			Menu::Option("prop_snow_tree_04_f");
			Menu::Option("prop_snow_truktrailer_01a");
			Menu::Option("prop_snow_tyre_01");
			Menu::Option("prop_snow_t_ml_01");
			Menu::Option("prop_snow_t_ml_02");
			Menu::Option("prop_snow_t_ml_03");
			Menu::Option("prop_snow_wall_light_15a");
			Menu::Option("prop_snow_watertower01");
			Menu::Option("prop_snow_watertower01_l2");
			Menu::Option("prop_snow_watertower03");
			Menu::Option("prop_snow_woodpile_04a");
			Menu::Option("prop_soap_disp_01");
			Menu::Option("prop_soap_disp_02");
			Menu::Option("prop_solarpanel_01");
			Menu::Option("prop_solarpanel_02");
			Menu::Option("prop_solarpanel_03");
			Menu::Option("prop_sol_chair");
			Menu::Option("prop_space_pistol");
			Menu::Option("prop_space_rifle");
			Menu::Option("prop_speaker_01");
			Menu::Option("prop_speaker_02");
			Menu::Option("prop_speaker_03");
			Menu::Option("prop_speaker_05");
			Menu::Option("prop_speaker_06");
			Menu::Option("prop_speaker_07");
			Menu::Option("prop_speaker_08");
			Menu::Option("prop_speedball_01");
			Menu::Option("prop_sponge_01");
			Menu::Option("prop_sports_clock_01");
			Menu::Option("prop_spot_01");
			Menu::Option("prop_spot_clamp");
			Menu::Option("prop_spot_clamp_02");
			Menu::Option("prop_sprayer");
			Menu::Option("prop_spraygun_01");
			Menu::Option("prop_spray_backpack_01");
			Menu::Option("prop_spray_jackframe");
			Menu::Option("prop_spray_jackleg");
			Menu::Option("prop_sprink_crop_01");
			Menu::Option("prop_sprink_golf_01");
			Menu::Option("prop_sprink_park_01");
			Menu::Option("prop_spycam");
			Menu::Option("prop_squeegee");
			Menu::Option("prop_ss1_05_mp_door");
			Menu::Option("prop_ss1_08_mp_door_l");
			Menu::Option("prop_ss1_08_mp_door_r");
			Menu::Option("prop_ss1_10_door_l");
			Menu::Option("prop_ss1_10_door_r");
			Menu::Option("prop_ss1_14_garage_door");
			Menu::Option("prop_ss1_mpint_door_l");
			Menu::Option("prop_ss1_mpint_door_r");
			Menu::Option("prop_ss1_mpint_garage");
			Menu::Option("prop_ss1_mpint_garage_cl");
			Menu::Option("prop_stag_do_rope");
			Menu::Option("prop_start_finish_line_01");
			Menu::Option("prop_start_grid_01");
			Menu::Option("prop_staticmixer_01");
			Menu::Option("prop_stat_pack_01");
			Menu::Option("prop_steam_basket_01");
			Menu::Option("prop_steam_basket_02");
			Menu::Option("prop_steps_big_01");
			Menu::Option("prop_stickbfly");
			Menu::Option("prop_stickhbird");
			Menu::Option("prop_still");
			Menu::Option("prop_stockade_wheel");
			Menu::Option("prop_stockade_wheel_flat");
			Menu::Option("prop_stool_01");
			Menu::Option("prop_storagetank_01");
			Menu::Option("prop_storagetank_02");
			Menu::Option("prop_storagetank_03");
			Menu::Option("prop_storagetank_03a");
			Menu::Option("prop_storagetank_03b");
			Menu::Option("prop_storagetank_04");
			Menu::Option("prop_storagetank_05");
			Menu::Option("prop_storagetank_06");
			Menu::Option("prop_storagetank_07a");
			Menu::Option("prop_stripmenu");
			Menu::Option("prop_strip_door_01");
			Menu::Option("prop_strip_pole_01");
			Menu::Option("prop_studio_light_02");
			Menu::Option("prop_studio_light_03");
			Menu::Option("prop_sub_chunk_01");
			Menu::Option("prop_sub_cover_01");
			Menu::Option("prop_sub_crane_hook");
			Menu::Option("prop_sub_frame_01a");
			Menu::Option("prop_sub_frame_01b");
			Menu::Option("prop_sub_frame_01c");
			Menu::Option("prop_sub_frame_02a");
			Menu::Option("prop_sub_frame_03a");
			Menu::Option("prop_sub_frame_04a");
			Menu::Option("prop_sub_frame_04b");
			Menu::Option("prop_sub_gantry");
			Menu::Option("prop_sub_release");
			Menu::Option("prop_sub_trans_01a");
			Menu::Option("prop_sub_trans_02a");
			Menu::Option("prop_sub_trans_03a");
			Menu::Option("prop_sub_trans_04a");
			Menu::Option("prop_sub_trans_05b");
			Menu::Option("prop_sub_trans_06b");
			Menu::Option("prop_suitcase_01");
			Menu::Option("prop_suitcase_01b");
			Menu::Option("prop_suitcase_01c");
			Menu::Option("prop_suitcase_01d");
			Menu::Option("prop_suitcase_02");
			Menu::Option("prop_suitcase_03");
			Menu::Option("prop_suitcase_03b");
			Menu::Option("prop_surf_board_ldn_01");
			Menu::Option("prop_surf_board_ldn_02");
			Menu::Option("prop_surf_board_ldn_03");
			Menu::Option("prop_surf_board_ldn_04");
			Menu::Option("prop_syringe_01");
			Menu::Option("prop_s_pine_dead_01");
			Menu::Option("prop_tablesaw_01");
			Menu::Option("prop_tablesmall_01");
			Menu::Option("prop_table_02");
			Menu::Option("prop_table_03b_cs");
			Menu::Option("prop_table_04");
			Menu::Option("prop_table_04_chr");
			Menu::Option("prop_table_05");
			Menu::Option("prop_table_05_chr");
			Menu::Option("prop_table_06");
			Menu::Option("prop_table_06_chr");
			Menu::Option("prop_table_07");
			Menu::Option("prop_table_07_l1");
			Menu::Option("prop_table_08");
			Menu::Option("prop_table_08_chr");
			Menu::Option("prop_table_08_side");
			Menu::Option("prop_table_mic_01");
			Menu::Option("prop_table_para_comb_04");
			Menu::Option("prop_table_tennis");
			Menu::Option("prop_table_ten_bat");
			Menu::Option("prop_taco_01");
			Menu::Option("prop_taco_02");
			Menu::Option("prop_tail_gate_col");
			Menu::Option("prop_tapeplayer_01");
			Menu::Option("prop_target_arm");
			Menu::Option("prop_target_arm_b");
			Menu::Option("prop_target_arm_long");
			Menu::Option("prop_target_arm_sm");
			Menu::Option("prop_target_backboard");
			Menu::Option("prop_target_backboard_b");
			Menu::Option("prop_target_blue");
			Menu::Option("prop_target_blue_arrow");
			Menu::Option("prop_target_bull");
			Menu::Option("prop_target_bull_b");
			Menu::Option("prop_target_comp_metal");
			Menu::Option("prop_target_comp_wood");
			Menu::Option("prop_target_frame_01");
			Menu::Option("prop_target_inner1");
			Menu::Option("prop_target_inner2");
			Menu::Option("prop_target_inner2_b");
			Menu::Option("prop_target_inner3");
			Menu::Option("prop_target_inner3_b");
			Menu::Option("prop_target_inner_b");
			Menu::Option("prop_target_orange_arrow");
			Menu::Option("prop_target_oran_cross");
			Menu::Option("prop_target_ora_purp_01");
			Menu::Option("prop_target_purp_arrow");
			Menu::Option("prop_target_purp_cross");
			Menu::Option("prop_target_red");
			Menu::Option("prop_target_red_arrow");
			Menu::Option("prop_target_red_blue_01");
			Menu::Option("prop_target_red_cross");
			Menu::Option("prop_tarp_strap");
			Menu::Option("prop_taxi_meter_1");
			Menu::Option("prop_taxi_meter_2");
			Menu::Option("prop_tea_trolly");
			Menu::Option("prop_tea_urn");
			Menu::Option("prop_telegraph_01a");
			Menu::Option("prop_telegraph_01b");
			Menu::Option("prop_telegraph_01c");
			Menu::Option("prop_telegraph_01d");
			Menu::Option("prop_telegraph_01e");
			Menu::Option("prop_telegraph_01f");
			Menu::Option("prop_telegraph_01g");
			Menu::Option("prop_telegraph_02a");
			Menu::Option("prop_telegraph_02b");
			Menu::Option("prop_telegraph_03");
			Menu::Option("prop_telegraph_04a");
			Menu::Option("prop_telegraph_04b");
			Menu::Option("prop_telegraph_05a");
			Menu::Option("prop_telegraph_05b");
			Menu::Option("prop_telegraph_05c");
			Menu::Option("prop_telegraph_06a");
			Menu::Option("prop_telegraph_06b");
			Menu::Option("prop_telegraph_06c");
			Menu::Option("prop_telegwall_01a");
			Menu::Option("prop_telegwall_01b");
			Menu::Option("prop_telegwall_02a");
			Menu::Option("prop_telegwall_03a");
			Menu::Option("prop_telegwall_03b");
			Menu::Option("prop_telegwall_04a");
			Menu::Option("prop_telescope");
			Menu::Option("prop_telescope_01");
			Menu::Option("prop_temp_block_blocker");
			Menu::Option("prop_tennis_bag_01");
			Menu::Option("prop_tennis_ball");
			Menu::Option("prop_tennis_ball_lobber");
			Menu::Option("prop_tennis_rack_01");
			Menu::Option("prop_tennis_rack_01b");
			Menu::Option("prop_test_boulder_01");
			Menu::Option("prop_test_boulder_02");
			Menu::Option("prop_test_boulder_03");
			Menu::Option("prop_test_boulder_04");
			Menu::Option("prop_test_elevator");
			Menu::Option("prop_test_elevator_dl");
			Menu::Option("prop_test_elevator_dr");
			Menu::Option("prop_tick");
			Menu::Option("prop_tick_02");
			Menu::Option("prop_till_01_dam");
			Menu::Option("prop_till_02");
			Menu::Option("prop_till_03");
			Menu::Option("prop_time_capsule_01");
			Menu::Option("prop_tint_towel");
			Menu::Option("prop_tint_towels_01");
			Menu::Option("prop_tint_towels_01b");
			Menu::Option("prop_toaster_01");
			Menu::Option("prop_toaster_02");
			Menu::Option("prop_toiletfoot_static");
			Menu::Option("prop_toilet_01");
			Menu::Option("prop_toilet_02");
			Menu::Option("prop_toilet_03");
			Menu::Option("prop_toilet_brush_01");
			Menu::Option("prop_toilet_cube_01");
			Menu::Option("prop_toilet_cube_02");
			Menu::Option("prop_toilet_roll_01");
			Menu::Option("prop_toilet_roll_02");
			Menu::Option("prop_toilet_roll_03");
			Menu::Option("prop_toilet_roll_04");
			Menu::Option("prop_toilet_roll_05");
			Menu::Option("prop_toilet_shamp_01");
			Menu::Option("prop_toilet_shamp_02");
			Menu::Option("prop_toilet_soap_01");
			Menu::Option("prop_toilet_soap_02");
			Menu::Option("prop_toilet_soap_03");
			Menu::Option("prop_toilet_soap_04");
			Menu::Option("prop_toolchest_01");
			Menu::Option("prop_toolchest_02");
			Menu::Option("prop_toolchest_03");
			Menu::Option("prop_toolchest_04");
			Menu::Option("prop_toolchest_05");
			Menu::Option("prop_tool_adjspanner");
			Menu::Option("prop_tool_bench01");
			Menu::Option("prop_tool_bluepnt");
			Menu::Option("prop_tool_box_01");
			Menu::Option("prop_tool_box_02");
			Menu::Option("prop_tool_box_03");
			Menu::Option("prop_tool_box_04");
			Menu::Option("prop_tool_box_05");
			Menu::Option("prop_tool_box_06");
			Menu::Option("prop_tool_box_07");
			Menu::Option("prop_tool_broom");
			Menu::Option("prop_tool_broom2");
			Menu::Option("prop_tool_broom2_l1");
			Menu::Option("prop_tool_cable01");
			Menu::Option("prop_tool_cable02");
			Menu::Option("prop_tool_consaw");
			Menu::Option("prop_tool_drill");
			Menu::Option("prop_tool_fireaxe");
			Menu::Option("prop_tool_hammer");
			Menu::Option("prop_tool_hardhat");
			Menu::Option("prop_tool_jackham");
			Menu::Option("prop_tool_mallet");
			Menu::Option("prop_tool_mopbucket");
			Menu::Option("prop_tool_nailgun");
			Menu::Option("prop_tool_pickaxe");
			Menu::Option("prop_tool_pliers");
			Menu::Option("prop_tool_rake");
			Menu::Option("prop_tool_rake_l1");
			Menu::Option("prop_tool_sawhorse");
			Menu::Option("prop_tool_screwdvr01");
			Menu::Option("prop_tool_screwdvr02");
			Menu::Option("prop_tool_screwdvr03");
			Menu::Option("prop_tool_shovel");
			Menu::Option("prop_tool_shovel006");
			Menu::Option("prop_tool_shovel2");
			Menu::Option("prop_tool_shovel3");
			Menu::Option("prop_tool_shovel4");
			Menu::Option("prop_tool_shovel5");
			Menu::Option("prop_tool_sledgeham");
			Menu::Option("prop_tool_spanner01");
			Menu::Option("prop_tool_spanner02");
			Menu::Option("prop_tool_spanner03");
			Menu::Option("prop_tool_torch");
			Menu::Option("prop_tool_wrench");
			Menu::Option("prop_toothbrush_01");
			Menu::Option("prop_toothb_cup_01");
			Menu::Option("prop_toothpaste_01");
			Menu::Option("prop_tornado_wheel");
			Menu::Option("prop_torture_01");
			Menu::Option("prop_torture_ch_01");
			Menu::Option("prop_tourist_map_01");
			Menu::Option("prop_towel2_01");
			Menu::Option("prop_towel2_02");
			Menu::Option("prop_towel_01");
			Menu::Option("prop_towel_rail_01");
			Menu::Option("prop_towel_rail_02");
			Menu::Option("prop_towel_shelf_01");
			Menu::Option("prop_towel_small_01");
			Menu::Option("prop_towercrane_01a");
			Menu::Option("prop_towercrane_02a");
			Menu::Option("prop_towercrane_02b");
			Menu::Option("prop_towercrane_02c");
			Menu::Option("prop_towercrane_02d");
			Menu::Option("prop_towercrane_02e");
			Menu::Option("prop_towercrane_02el");
			Menu::Option("prop_towercrane_02el2");
			Menu::Option("prop_traffic_rail_1c");
			Menu::Option("prop_traffic_rail_2");
			Menu::Option("prop_trailer01");
			Menu::Option("prop_trailer01_up");
			Menu::Option("prop_trailer_01_new");
			Menu::Option("prop_trailer_door_closed");
			Menu::Option("prop_trailer_door_open");
			Menu::Option("prop_trailer_monitor_01");
			Menu::Option("prop_trailr_base");
			Menu::Option("prop_trailr_base_static");
			Menu::Option("prop_train_ticket_02");
			Menu::Option("prop_tram_pole_double01");
			Menu::Option("prop_tram_pole_double02");
			Menu::Option("prop_tram_pole_double03");
			Menu::Option("prop_tram_pole_roadside");
			Menu::Option("prop_tram_pole_single01");
			Menu::Option("prop_tram_pole_single02");
			Menu::Option("prop_tram_pole_wide01");
			Menu::Option("prop_tree_birch_01");
			Menu::Option("prop_tree_birch_02");
			Menu::Option("prop_tree_birch_03");
			Menu::Option("prop_tree_birch_03b");
			Menu::Option("prop_tree_birch_04");
			Menu::Option("prop_tree_birch_05");
			Menu::Option("prop_tree_cedar_02");
			Menu::Option("prop_tree_cedar_03");
			Menu::Option("prop_tree_cedar_04");
			Menu::Option("prop_tree_cedar_s_01");
			Menu::Option("prop_tree_cedar_s_02");
			Menu::Option("prop_tree_cedar_s_04");
			Menu::Option("prop_tree_cedar_s_05");
			Menu::Option("prop_tree_cedar_s_06");
			Menu::Option("prop_tree_cypress_01");
			Menu::Option("prop_tree_eng_oak_01");
			Menu::Option("prop_tree_eucalip_01");
			Menu::Option("prop_tree_fallen_01");
			Menu::Option("prop_tree_fallen_02");
			Menu::Option("prop_tree_fallen_pine_01");
			Menu::Option("prop_tree_jacada_01");
			Menu::Option("prop_tree_jacada_02");
			Menu::Option("prop_tree_lficus_02");
			Menu::Option("prop_tree_lficus_03");
			Menu::Option("prop_tree_lficus_05");
			Menu::Option("prop_tree_lficus_06");
			Menu::Option("prop_tree_log_01");
			Menu::Option("prop_tree_log_02");
			Menu::Option("prop_tree_maple_02");
			Menu::Option("prop_tree_maple_03");
			Menu::Option("prop_tree_mquite_01");
			Menu::Option("prop_tree_oak_01");
			Menu::Option("prop_tree_olive_01");
			Menu::Option("prop_tree_pine_01");
			Menu::Option("prop_tree_pine_02");
			Menu::Option("prop_tree_stump_01");
			Menu::Option("prop_trevor_rope_01");
			Menu::Option("prop_trev_sec_id");
			Menu::Option("prop_trev_tv_01");
			Menu::Option("prop_triple_grid_line");
			Menu::Option("prop_tri_finish_banner");
			Menu::Option("prop_tri_pod");
			Menu::Option("prop_tri_pod_lod");
			Menu::Option("prop_tri_start_banner");
			Menu::Option("prop_tri_table_01");
			Menu::Option("prop_trough1");
			Menu::Option("prop_truktrailer_01a");
			Menu::Option("prop_tshirt_box_02");
			Menu::Option("prop_tshirt_shelf_1");
			Menu::Option("prop_tshirt_shelf_2");
			Menu::Option("prop_tshirt_shelf_2a");
			Menu::Option("prop_tshirt_shelf_2b");
			Menu::Option("prop_tshirt_shelf_2c");
			Menu::Option("prop_tshirt_stand_01");
			Menu::Option("prop_tshirt_stand_01b");
			Menu::Option("prop_tshirt_stand_02");
			Menu::Option("prop_tshirt_stand_04");
			Menu::Option("prop_tt_screenstatic");
			Menu::Option("prop_tumbler_01");
			Menu::Option("prop_tumbler_01b");
			Menu::Option("prop_tumbler_01_empty");
			Menu::Option("prop_tunnel_liner01");
			Menu::Option("prop_tunnel_liner02");
			Menu::Option("prop_tunnel_liner03");
			Menu::Option("prop_turkey_leg_01");
			Menu::Option("prop_turnstyle_01");
			Menu::Option("prop_tv_02");
			Menu::Option("prop_tv_03_overlay");
			Menu::Option("prop_tv_04");
			Menu::Option("prop_tv_05");
			Menu::Option("prop_tv_06");
			Menu::Option("prop_tv_07");
			Menu::Option("prop_tv_cabinet_03");
			Menu::Option("prop_tv_cabinet_04");
			Menu::Option("prop_tv_cabinet_05");
			Menu::Option("prop_tv_cam_02");
			Menu::Option("prop_tv_flat_01");
			Menu::Option("prop_tv_flat_01_screen");
			Menu::Option("prop_tv_flat_02b");
			Menu::Option("prop_tv_flat_03");
			Menu::Option("prop_tv_flat_03b");
			Menu::Option("prop_tv_flat_michael");
			Menu::Option("prop_tv_test");
			Menu::Option("prop_tyre_rack_01");
			Menu::Option("prop_tyre_spike_01");
			Menu::Option("prop_t_coffe_table");
			Menu::Option("prop_t_shirt_ironing");
			Menu::Option("prop_t_shirt_row_01");
			Menu::Option("prop_t_shirt_row_02");
			Menu::Option("prop_t_shirt_row_02b");
			Menu::Option("prop_t_shirt_row_03");
			Menu::Option("prop_t_shirt_row_04");
			Menu::Option("prop_t_shirt_row_05l");
			Menu::Option("prop_t_shirt_row_05r");
			Menu::Option("prop_t_sofa");
			Menu::Option("prop_t_sofa_02");
			Menu::Option("prop_t_telescope_01b");
			Menu::Option("prop_umpire_01");
			Menu::Option("prop_utensil");
			Menu::Option("prop_valet_03");
			Menu::Option("prop_vault_shutter");
			Menu::Option("prop_vb_34_tencrt_lighting");
			Menu::Option("prop_vcr_01");
			Menu::Option("prop_veg_corn_01");
			Menu::Option("prop_veg_crop_01");
			Menu::Option("prop_veg_crop_02");
			Menu::Option("prop_veg_crop_04");
			Menu::Option("prop_veg_crop_04_leaf");
			Menu::Option("prop_veg_crop_05");
			Menu::Option("prop_veg_crop_06");
			Menu::Option("prop_veg_crop_orange");
			Menu::Option("prop_veg_crop_tr_01");
			Menu::Option("prop_veg_crop_tr_02");
			Menu::Option("prop_veg_grass_01_a");
			Menu::Option("prop_veg_grass_01_b");
			Menu::Option("prop_veg_grass_01_c");
			Menu::Option("prop_veg_grass_01_d");
			Menu::Option("prop_veg_grass_02_a");
			Menu::Option("prop_vehicle_hook");
			Menu::Option("prop_vend_coffe_01");
			Menu::Option("prop_vend_condom_01");
			Menu::Option("prop_vend_fags_01");
			Menu::Option("prop_vend_fridge01");
			Menu::Option("prop_vend_snak_01");
			Menu::Option("prop_venice_board_01");
			Menu::Option("prop_venice_board_02");
			Menu::Option("prop_venice_board_03");
			Menu::Option("prop_venice_counter_01");
			Menu::Option("prop_venice_counter_02");
			Menu::Option("prop_venice_counter_03");
			Menu::Option("prop_venice_counter_04");
			Menu::Option("prop_venice_shop_front_01");
			Menu::Option("prop_venice_sign_09");
			Menu::Option("prop_venice_sign_10");
			Menu::Option("prop_venice_sign_11");
			Menu::Option("prop_venice_sign_12");
			Menu::Option("prop_venice_sign_14");
			Menu::Option("prop_venice_sign_15");
			Menu::Option("prop_venice_sign_16");
			Menu::Option("prop_venice_sign_17");
			Menu::Option("prop_venice_sign_18");
			Menu::Option("prop_ventsystem_01");
			Menu::Option("prop_ventsystem_02");
			Menu::Option("prop_ventsystem_03");
			Menu::Option("prop_ventsystem_04");
			Menu::Option("prop_ven_market_stool");
			Menu::Option("prop_ven_market_table1");
			Menu::Option("prop_ven_shop_1_counter");
			Menu::Option("prop_vertdrill_01");
			Menu::Option("prop_voltmeter_01");
			Menu::Option("prop_v_15_cars_clock");
			Menu::Option("prop_v_5_bclock");
			Menu::Option("prop_v_bmike_01");
			Menu::Option("prop_v_cam_01");
			Menu::Option("prop_v_door_44");
			Menu::Option("prop_v_hook_s");
			Menu::Option("prop_v_m_phone_01");
			Menu::Option("prop_v_m_phone_o1s");
			Menu::Option("prop_v_parachute");
			Menu::Option("prop_waiting_seat_01");
			Menu::Option("prop_wait_bench_01");
			Menu::Option("prop_walllight_ld_01b");
			Menu::Option("prop_wall_light_08a");
			Menu::Option("prop_wall_light_10a");
			Menu::Option("prop_wall_light_10b");
			Menu::Option("prop_wall_light_10c");
			Menu::Option("prop_wall_light_11");
			Menu::Option("prop_wall_light_12");
			Menu::Option("prop_wall_light_17b");
			Menu::Option("prop_wall_light_18a");
			Menu::Option("prop_wall_vent_01");
			Menu::Option("prop_wall_vent_02");
			Menu::Option("prop_wall_vent_03");
			Menu::Option("prop_wall_vent_04");
			Menu::Option("prop_wall_vent_05");
			Menu::Option("prop_wall_vent_06");
			Menu::Option("prop_wardrobe_door_01");
			Menu::Option("prop_warehseshelf01");
			Menu::Option("prop_warehseshelf02");
			Menu::Option("prop_warehseshelf03");
			Menu::Option("prop_warninglight_01");
			Menu::Option("prop_washer_01");
			Menu::Option("prop_washer_02");
			Menu::Option("prop_washer_03");
			Menu::Option("prop_washing_basket_01");
			Menu::Option("prop_watercrate_01");
			Menu::Option("prop_wateringcan");
			Menu::Option("prop_watertower01");
			Menu::Option("prop_watertower02");
			Menu::Option("prop_watertower03");
			Menu::Option("prop_watertower04");
			Menu::Option("prop_waterwheela");
			Menu::Option("prop_waterwheelb");
			Menu::Option("prop_water_bottle");
			Menu::Option("prop_water_bottle_dark");
			Menu::Option("prop_water_corpse_01");
			Menu::Option("prop_water_corpse_02");
			Menu::Option("prop_water_ramp_01");
			Menu::Option("prop_water_ramp_02");
			Menu::Option("prop_water_ramp_03");
			Menu::Option("prop_weed_01");
			Menu::Option("prop_weed_02");
			Menu::Option("prop_weed_block_01");
			Menu::Option("prop_weed_bottle");
			Menu::Option("prop_weed_pallet");
			Menu::Option("prop_weed_tub_01");
			Menu::Option("prop_weed_tub_01b");
			Menu::Option("prop_weight_10k");
			Menu::Option("prop_weight_15k");
			Menu::Option("prop_weight_1_5k");
			Menu::Option("prop_weight_20k");
			Menu::Option("prop_weight_2_5k");
			Menu::Option("prop_weight_5k");
			Menu::Option("prop_weight_rack_01");
			Menu::Option("prop_weight_rack_02");
			Menu::Option("prop_welding_mask_01");
			Menu::Option("prop_weld_torch");
			Menu::Option("prop_wheat_grass_empty");
			Menu::Option("prop_wheat_grass_glass");
			Menu::Option("prop_wheelbarrow01a");
			Menu::Option("prop_wheelbarrow02a");
			Menu::Option("prop_wheelchair_01");
			Menu::Option("prop_wheel_01");
			Menu::Option("prop_wheel_02");
			Menu::Option("prop_wheel_03");
			Menu::Option("prop_wheel_04");
			Menu::Option("prop_wheel_05");
			Menu::Option("prop_wheel_06");
			Menu::Option("prop_wheel_hub_01");
			Menu::Option("prop_wheel_hub_02_lod_02");
			Menu::Option("prop_wheel_rim_01");
			Menu::Option("prop_wheel_rim_02");
			Menu::Option("prop_wheel_rim_03");
			Menu::Option("prop_wheel_rim_04");
			Menu::Option("prop_wheel_rim_05");
			Menu::Option("prop_wheel_tyre");
			Menu::Option("prop_whisk");
			Menu::Option("prop_white_keyboard");
			Menu::Option("prop_winch_hook_long");
			Menu::Option("prop_winch_hook_short");
			Menu::Option("prop_windmill2");
			Menu::Option("prop_windmill_01_l1");
			Menu::Option("prop_windmill_01_slod");
			Menu::Option("prop_windmill_01_slod2");
			Menu::Option("prop_windowbox_a");
			Menu::Option("prop_windowbox_b");
			Menu::Option("prop_windowbox_broken");
			Menu::Option("prop_windowbox_small");
			Menu::Option("prop_win_plug_01");
			Menu::Option("prop_win_plug_01_dam");
			Menu::Option("prop_win_trailer_ld");
			Menu::Option("prop_wok");
			Menu::Option("prop_woodpile_02a");
			Menu::Option("prop_worklight_01a_l1");
			Menu::Option("prop_worklight_03a_l1");
			Menu::Option("prop_worklight_03b_l1");
			Menu::Option("prop_worklight_04a");
			Menu::Option("prop_worklight_04b_l1");
			Menu::Option("prop_worklight_04c_l1");
			Menu::Option("prop_worklight_04d_l1");
			Menu::Option("prop_workwall_01");
			Menu::Option("prop_workwall_02");
			Menu::Option("prop_wreckedcart");
			Menu::Option("prop_wrecked_buzzard");
			Menu::Option("prop_w_board_blank");
			Menu::Option("prop_w_board_blank_2");
			Menu::Option("prop_w_fountain_01");
			Menu::Option("prop_w_r_cedar_01");
			Menu::Option("prop_w_r_cedar_dead");
			Menu::Option("prop_xmas_tree_int");
			Menu::Option("prop_xmas_ext");
			Menu::Option("prop_yacht_lounger");
			Menu::Option("prop_yacht_seat_01");
			Menu::Option("prop_yacht_seat_02");
			Menu::Option("prop_yacht_seat_03");
			Menu::Option("prop_yacht_table_01");
			Menu::Option("prop_yacht_table_02");
			Menu::Option("prop_yacht_table_03");
			Menu::Option("prop_yaught_chair_01");
			Menu::Option("prop_yaught_sofa_01");
			Menu::Option("prop_yell_plastic_target");
			Menu::Option("prop_yoga_mat_01");
			Menu::Option("prop_yoga_mat_02");
			Menu::Option("prop_yoga_mat_03");
			Menu::Option("prop_ztype_covered");
			Menu::Option("p_ing_skiprope_01");
			Menu::Option("p_ing_skiprope_01_s");
			Menu::Option("p_skiprope_r_s");
			Menu::Option("test_prop_gravestones_04a");
			Menu::Option("test_prop_gravestones_05a");
			Menu::Option("test_prop_gravestones_07a");
			Menu::Option("test_prop_gravestones_08a");
			Menu::Option("test_prop_gravestones_09a");
			Menu::Option("test_prop_gravetomb_01a");
			Menu::Option("test_prop_gravetomb_02a");
			Menu::Option("prop_cs_dog_lead_a_s");
			Menu::Option("prop_cs_dog_lead_b_s");
			Menu::Option("prop_welding_mask_01_s");
			Menu::Option("prop_wheelchair_01_s");
			Menu::Option("p_a4_sheets_s");
			Menu::Option("p_amanda_note_01_s");
			Menu::Option("p_armchair_01_s");
			Menu::Option("p_arm_bind_cut_s");
			Menu::Option("p_ashley_neck_01_s");
			Menu::Option("p_banknote_onedollar_s");
			Menu::Option("p_banknote_s");
			Menu::Option("p_binbag_01_s");
			Menu::Option("p_bison_winch_s");
			Menu::Option("p_bloodsplat_s");
			Menu::Option("p_blueprints_01_s");
			Menu::Option("p_brain_chunk_s");
			Menu::Option("p_bs_map_door_01_s");
			Menu::Option("p_cablecar_s");
			Menu::Option("p_cablecar_s_door_l");
			Menu::Option("p_cablecar_s_door_r");
			Menu::Option("p_cash_envelope_01_s");
			Menu::Option("p_cctv_s");
			Menu::Option("p_chem_vial_02b_s");
			Menu::Option("p_clb_officechair_s");
			Menu::Option("p_cletus_necklace_s");
			Menu::Option("p_clothtarp_down_s");
			Menu::Option("p_clothtarp_s");
			Menu::Option("p_clothtarp_up_s");
			Menu::Option("p_controller_01_s");
			Menu::Option("p_crahsed_heli_s");
			Menu::Option("p_cs1_14b_train_s");
			Menu::Option("p_cs1_14b_train_s_col");
			Menu::Option("p_cs1_14b_train_s_colopen");
			Menu::Option("p_csbporndudes_necklace_s");
			Menu::Option("p_csh_strap_01_pro_s");
			Menu::Option("p_csh_strap_01_s");
			Menu::Option("p_csh_strap_03_s");
			Menu::Option("p_cs_15m_rope_s");
			Menu::Option("p_cs_bandana_s");
			Menu::Option("p_cs_beachtowel_01_s");
			Menu::Option("p_cs_beverly_lanyard_s");
			Menu::Option("p_cs_bowl_01b_s");
			Menu::Option("p_cs_ciggy_01b_s");
			Menu::Option("p_cs_clothes_box_s");
			Menu::Option("p_cs_coke_line_s");
			Menu::Option("p_cs_cuffs_02_s");
			Menu::Option("p_cs_duffel_01_s");
			Menu::Option("p_cs_laz_ptail_s");
			Menu::Option("p_cs_leaf_s");
			Menu::Option("p_cs_mp_jet_01_s");
			Menu::Option("p_cs_newspaper_s");
			Menu::Option("p_cs_pamphlet_01_s");
			Menu::Option("p_cs_panties_03_s");
			Menu::Option("p_cs_para_ropebit_s");
			Menu::Option("p_cs_para_ropes_s");
			Menu::Option("p_cs_polaroid_s");
			Menu::Option("p_cs_police_torch_s");
			Menu::Option("p_cs_pour_tube_s");
			Menu::Option("p_cs_power_cord_s");
			Menu::Option("p_cs_rope_tie_01_s");
			Menu::Option("p_cs_sack_01_s");
			Menu::Option("p_cs_saucer_01_s");
			Menu::Option("p_cs_scissors_s");
			Menu::Option("p_cs_script_s");
			Menu::Option("p_cs_shirt_01_s");
			Menu::Option("p_cs_shot_glass_2_s");
			Menu::Option("p_cs_shot_glass_s");
			Menu::Option("p_cs_sub_hook_01_s");
			Menu::Option("p_cs_toaster_s");
			Menu::Option("p_cs_tracy_neck2_s");
			Menu::Option("p_cs_trolley_01_s");
			Menu::Option("p_defilied_ragdoll_01_s");
			Menu::Option("p_devin_box_01_s");
			Menu::Option("p_dinechair_01_s");
			Menu::Option("p_d_scuba_mask_s");
			Menu::Option("p_d_scuba_tank_s");
			Menu::Option("p_ecg_01_cable_01_s");
			Menu::Option("p_fib_rubble_s");
			Menu::Option("p_finale_bld_ground_s");
			Menu::Option("p_finale_bld_pool_s");
			Menu::Option("p_fin_vaultdoor_s");
			Menu::Option("p_flatbed_strap_s");
			Menu::Option("p_folding_chair_01_s");
			Menu::Option("p_gaffer_tape_s");
			Menu::Option("p_gaffer_tape_strip_s");
			Menu::Option("p_gasmask_s");
			Menu::Option("p_gcase_s");
			Menu::Option("p_hand_toilet_s");
			Menu::Option("p_hw1_22_doors_s");
			Menu::Option("p_hw1_22_table_s");
			Menu::Option("p_ice_box_01_s");
			Menu::Option("p_ice_box_proxy_col");
			Menu::Option("p_idol_case_s");
			Menu::Option("p_ilev_p_easychair_s");
			Menu::Option("p_inhaler_01_s");
			Menu::Option("p_jimmyneck_03_s");
			Menu::Option("p_jimmy_necklace_s");
			Menu::Option("p_kitch_juicer_s");
			Menu::Option("p_lamarneck_01_s");
			Menu::Option("p_laptop_02_s");
			Menu::Option("p_large_gold_s");
			Menu::Option("p_lazlow_shirt_s");
			Menu::Option("p_laz_j01_s");
			Menu::Option("p_laz_j02_s");
			Menu::Option("p_ld_cable_tie_01_s");
			Menu::Option("p_ld_crocclips01_s");
			Menu::Option("p_ld_crocclips02_s");
			Menu::Option("p_ld_heist_bag_s_1");
			Menu::Option("p_ld_heist_bag_s_2");
			Menu::Option("p_ld_heist_bag_s_pro");
			Menu::Option("p_ld_heist_bag_s_pro2_s");
			Menu::Option("p_ld_heist_bag_s_pro_o");
			Menu::Option("p_leg_bind_cut_s");
			Menu::Option("p_lestersbed_s");
			Menu::Option("p_lev_sofa_s");
			Menu::Option("p_lifeinv_neck_01_s");
			Menu::Option("p_loose_rag_01_s");
			Menu::Option("p_mbbed_s");
			Menu::Option("p_medal_01_s");
			Menu::Option("p_med_jet_01_s");
			Menu::Option("p_meth_bag_01_s");
			Menu::Option("p_michael_backpack_s");
			Menu::Option("p_michael_scuba_mask_s");
			Menu::Option("p_michael_scuba_tank_s");
			Menu::Option("p_mp_showerdoor_s");
			Menu::Option("p_mrk_harness_s");
			Menu::Option("p_mr_raspberry_01_s");
			Menu::Option("p_novel_01_s");
			Menu::Option("p_omega_neck_01_s");
			Menu::Option("p_omega_neck_02_s");
			Menu::Option("p_orleans_mask_s");
			Menu::Option("p_ortega_necklace_s");
			Menu::Option("p_oscar_necklace_s");
			Menu::Option("p_overalls_02_s");
			Menu::Option("p_pistol_holster_s");
			Menu::Option("p_po1_01_doorm_s");
			Menu::Option("p_police_radio_hset_s");
			Menu::Option("p_poly_bag_01_s");
			Menu::Option("p_pour_wine_s");
			Menu::Option("p_rail_controller_s");
			Menu::Option("p_res_sofa_l_s");
			Menu::Option("p_rpulley_s");
			Menu::Option("p_sec_case_02_s");
			Menu::Option("p_shower_towel_s");
			Menu::Option("p_single_rose_s");
			Menu::Option("p_smg_holster_01_s");
			Menu::Option("p_soloffchair_s");
			Menu::Option("p_spinning_anus_s");
			Menu::Option("p_steve_scuba_hood_s");
			Menu::Option("p_stretch_necklace_s");
			Menu::Option("p_syringe_01_s");
			Menu::Option("p_s_scuba_mask_s");
			Menu::Option("p_s_scuba_tank_s");
			Menu::Option("p_till_01_s");
			Menu::Option("p_tmom_earrings_s");
			Menu::Option("p_tourist_map_01_s");
			Menu::Option("p_trevor_prologe_bally_s");
			Menu::Option("p_trev_rope_01_s");
			Menu::Option("p_trev_ski_mask_s");
			Menu::Option("p_tumbler_01_s");
			Menu::Option("p_tumbler_02_s1");
			Menu::Option("p_tumbler_cs2_s");
			Menu::Option("p_tv_cam_02_s");
			Menu::Option("p_t_shirt_pile_s");
			Menu::Option("p_v_43_safe_s");
			Menu::Option("p_v_ilev_chopshopswitch_s");
			Menu::Option("p_v_med_p_sofa_s");
			Menu::Option("p_v_res_tt_bed_s");
			Menu::Option("p_wade_necklace_s");
			Menu::Option("p_wboard_clth_s");
			Menu::Option("p_weed_bottle_s");
			Menu::Option("p_whiskey_bottle_s");
			Menu::Option("p_winch_long_s");
			Menu::Option("s_prop_hdphones");
			Menu::Option("s_prop_hdphones_1");
			Menu::Option("v_ilev_fib_door1_s");
			Menu::Option("v_res_msonbed_s");
			Menu::Option("v_res_tre_sofa_s");
			Menu::Option("v_tre_sofa_mess_a_s");
			Menu::Option("v_tre_sofa_mess_b_s");
			Menu::Option("v_tre_sofa_mess_c_s");
			Menu::Option("prop_ar_arrow_1");
			Menu::Option("prop_ar_arrow_2");
			Menu::Option("prop_ar_arrow_3");
			Menu::Option("prop_ar_ring_01");
			Menu::Option("prop_mk_arrow_3d");
			Menu::Option("prop_mk_arrow_flat");
			Menu::Option("prop_mk_bike_logo_1");
			Menu::Option("prop_mk_bike_logo_2");
			Menu::Option("prop_mk_boost");
			Menu::Option("prop_mk_cone");
			Menu::Option("prop_mk_cylinder");
			Menu::Option("prop_mk_flag");
			Menu::Option("prop_mk_flag_2");
			Menu::Option("prop_mk_heli");
			Menu::Option("prop_mk_lap");
			Menu::Option("prop_mk_mp_ring_01");
			Menu::Option("prop_mk_mp_ring_01b");
			Menu::Option("prop_mk_num_0");
			Menu::Option("prop_mk_num_1");
			Menu::Option("prop_mk_num_2");
			Menu::Option("prop_mk_num_3");
			Menu::Option("prop_mk_num_4");
			Menu::Option("prop_mk_num_5");
			Menu::Option("prop_mk_num_6");
			Menu::Option("prop_mk_num_7");
			Menu::Option("prop_mk_num_8");
			Menu::Option("prop_mk_num_9");
			Menu::Option("prop_mk_plane");
			Menu::Option("prop_mk_race_chevron_01");
			Menu::Option("prop_mk_race_chevron_02");
			Menu::Option("prop_mk_race_chevron_03");
			Menu::Option("prop_mk_repair");
			Menu::Option("prop_mk_ring");
			Menu::Option("prop_mk_ring_flat");
			Menu::Option("prop_mk_sphere");
			Menu::Option("prop_mk_tri_cycle");
			Menu::Option("prop_mk_tri_run");
			Menu::Option("prop_mk_tri_swim");
			Menu::Option("prop_mp_arrow_ring");
			Menu::Option("prop_mp_halo");
			Menu::Option("prop_mp_halo_lrg");
			Menu::Option("prop_mp_halo_med");
			Menu::Option("prop_mp_halo_point");
			Menu::Option("prop_mp_halo_point_lrg");
			Menu::Option("prop_mp_halo_point_med");
			Menu::Option("prop_mp_halo_point_sm");
			Menu::Option("prop_mp_halo_rotate");
			Menu::Option("prop_mp_halo_rotate_lrg");
			Menu::Option("prop_mp_halo_rotate_med");
			Menu::Option("prop_mp_halo_rotate_sm");
			Menu::Option("prop_mp_halo_sm");
			Menu::Option("prop_mp_pointer_ring");
			Menu::Option("prop_mp_solid_ring");
			Menu::Option("cj_parachute");
			Menu::Option("gb_cap_use");
			Menu::Option("gb_specs_use");
			Menu::Option("cj_proc_tin2");
			Menu::Option("proc_coral_01");
			Menu::Option("proc_fern_02");
			Menu::Option("proc_litter_01");
			Menu::Option("proc_litter_02");
			Menu::Option("proc_mntn_stone01");
			Menu::Option("proc_mntn_stone02");
			Menu::Option("proc_mntn_stone03");
			Menu::Option("proc_searock_01");
			Menu::Option("proc_searock_02");
			Menu::Option("proc_searock_03");
			Menu::Option("proc_sml_stones01");
			Menu::Option("proc_sml_stones02");
			Menu::Option("proc_sml_stones03");
			Menu::Option("proc_trolley_lakebed");
			Menu::Option("prop_bush_gorse_dry");
			Menu::Option("prop_bush_gorse_lush");
			Menu::Option("prop_coral_01");
			Menu::Option("prop_coral_02");
			Menu::Option("prop_coral_03");
			Menu::Option("prop_sapling_01");
			Menu::Option("prop_seabrain_01");
			Menu::Option("prop_seagroup_02");
			Menu::Option("prop_sealife_01");
			Menu::Option("prop_sealife_02");
			Menu::Option("prop_sealife_03");
			Menu::Option("prop_sealife_04");
			Menu::Option("prop_sealife_05");
			Menu::Option("prop_seaweed_01");
			Menu::Option("prop_seaweed_02");
			Menu::Option("prop_starfish_01");
			Menu::Option("prop_starfish_02");
			Menu::Option("prop_starfish_03");
			Menu::Option("prop_aerial_01a");
			Menu::Option("prop_aerial_01b");
			Menu::Option("prop_aerial_01c");
			Menu::Option("prop_aerial_01d");
			Menu::Option("prop_aircon_l_01");
			Menu::Option("prop_aircon_l_02");
			Menu::Option("prop_aircon_l_03");
			Menu::Option("prop_aircon_l_04");
			Menu::Option("prop_aircon_m_09");
			Menu::Option("prop_aircon_s_01a");
			Menu::Option("prop_aircon_s_02a");
			Menu::Option("prop_aircon_s_02b");
			Menu::Option("prop_aircon_s_03a");
			Menu::Option("prop_aircon_s_03b");
			Menu::Option("prop_aircon_s_04a");
			Menu::Option("prop_aircon_s_05a");
			Menu::Option("prop_aircon_s_06a");
			Menu::Option("prop_aircon_s_07a");
			Menu::Option("prop_aircon_s_07b");
			Menu::Option("prop_alarm_01");
			Menu::Option("prop_alarm_02");
			Menu::Option("prop_billb_frame01a");
			Menu::Option("prop_billb_frame01b");
			Menu::Option("prop_billb_frame02a");
			Menu::Option("prop_billb_frame02b");
			Menu::Option("prop_billb_frame03a");
			Menu::Option("prop_billb_frame03b");
			Menu::Option("prop_billb_frame03c");
			Menu::Option("prop_billb_frame04a");
			Menu::Option("prop_billb_frame04b");
			Menu::Option("prop_bmu_01");
			Menu::Option("prop_bmu_01_b");
			Menu::Option("prop_bmu_02");
			Menu::Option("prop_bmu_02_ld");
			Menu::Option("prop_bmu_02_ld_cab");
			Menu::Option("prop_bmu_02_ld_sup");
			Menu::Option("prop_bmu_track01");
			Menu::Option("prop_bmu_track02");
			Menu::Option("prop_bmu_track03");
			Menu::Option("prop_fireescape_01a");
			Menu::Option("prop_fireescape_01b");
			Menu::Option("prop_fireescape_02a");
			Menu::Option("prop_fireescape_02b");
			Menu::Option("prop_flagpole_1a");
			Menu::Option("prop_flagpole_2a");
			Menu::Option("prop_flagpole_3a");
			Menu::Option("prop_helipad_01");
			Menu::Option("prop_helipad_02");
			Menu::Option("prop_radiomast01");
			Menu::Option("prop_radiomast02");
			Menu::Option("prop_roofpipe_01");
			Menu::Option("prop_roofpipe_02");
			Menu::Option("prop_roofpipe_03");
			Menu::Option("prop_roofpipe_04");
			Menu::Option("prop_roofpipe_05");
			Menu::Option("prop_roofpipe_06");
			Menu::Option("prop_roofvent_011a");
			Menu::Option("prop_roofvent_01a");
			Menu::Option("prop_roofvent_01b");
			Menu::Option("prop_roofvent_02a");
			Menu::Option("prop_roofvent_02b");
			Menu::Option("prop_roofvent_03a");
			Menu::Option("prop_roofvent_04a");
			Menu::Option("prop_roofvent_05a");
			Menu::Option("prop_roofvent_05b");
			Menu::Option("prop_roofvent_07a");
			Menu::Option("prop_roofvent_08a");
			Menu::Option("prop_roofvent_09a");
			Menu::Option("prop_roofvent_10a");
			Menu::Option("prop_roofvent_10b");
			Menu::Option("prop_roofvent_11b");
			Menu::Option("prop_roofvent_11c");
			Menu::Option("prop_roofvent_12a");
			Menu::Option("prop_roofvent_13a");
			Menu::Option("prop_roofvent_15a");
			Menu::Option("prop_roofvent_16a");
			Menu::Option("prop_satdish_2_a");
			Menu::Option("prop_satdish_2_f");
			Menu::Option("prop_satdish_2_g");
			Menu::Option("prop_satdish_3_b");
			Menu::Option("prop_satdish_3_c");
			Menu::Option("prop_satdish_3_d");
			Menu::Option("prop_satdish_l_01");
			Menu::Option("prop_satdish_s_03");
			Menu::Option("prop_satdish_s_05a");
			Menu::Option("prop_satdish_s_05b");
			Menu::Option("prop_skylight_01");
			Menu::Option("prop_skylight_02");
			Menu::Option("prop_skylight_03");
			Menu::Option("prop_skylight_04");
			Menu::Option("prop_skylight_05");
			Menu::Option("prop_skylight_06a");
			Menu::Option("prop_skylight_06b");
			Menu::Option("prop_skylight_06c");
			Menu::Option("prop_solarpanel_01");
			Menu::Option("prop_solarpanel_02");
			Menu::Option("prop_solarpanel_03");
			Menu::Option("prop_ventsystem_01");
			Menu::Option("prop_ventsystem_02");
			Menu::Option("prop_ventsystem_03");
			Menu::Option("prop_ventsystem_04");
			Menu::Option("prop_wall_vent_01");
			Menu::Option("prop_wall_vent_02");
			Menu::Option("prop_wall_vent_03");
			Menu::Option("prop_wall_vent_04");
			Menu::Option("prop_wall_vent_05");
			Menu::Option("prop_wall_vent_06");
			Menu::Option("prop_watertower01");
			Menu::Option("prop_watertower02");
			Menu::Option("prop_watertower03");
			Menu::Option("prop_watertower04");
			Menu::Option("prop_bahammenu");
			Menu::Option("prop_barrachneon");
			Menu::Option("prop_bar_coastbarr");
			Menu::Option("prop_bar_coastchamp");
			Menu::Option("prop_bar_coastdusc");
			Menu::Option("prop_bar_coastmount");
			Menu::Option("prop_bar_cooler_01");
			Menu::Option("prop_bar_cooler_03");
			Menu::Option("prop_bar_fridge_01");
			Menu::Option("prop_bar_fridge_02");
			Menu::Option("prop_bar_fridge_03");
			Menu::Option("prop_bar_fridge_04");
			Menu::Option("prop_bar_ice_01");
			Menu::Option("prop_bar_napkindisp");
			Menu::Option("prop_bar_pump_01");
			Menu::Option("prop_bar_pump_04");
			Menu::Option("prop_bar_pump_05");
			Menu::Option("prop_bar_pump_06");
			Menu::Option("prop_bar_pump_07");
			Menu::Option("prop_bar_pump_08");
			Menu::Option("prop_bar_pump_09");
			Menu::Option("prop_bar_pump_10");
			Menu::Option("prop_bar_sink_01");
			Menu::Option("prop_bar_stool_01");
			Menu::Option("prop_beerneon");
			Menu::Option("prop_beer_bison");
			Menu::Option("prop_cherenneon");
			Menu::Option("prop_cockneon");
			Menu::Option("prop_cs_kitchen_cab_l2");
			Menu::Option("prop_cs_kitchen_cab_ld");
			Menu::Option("prop_cs_kitchen_cab_rd");
			Menu::Option("prop_irish_sign_01");
			Menu::Option("prop_irish_sign_02");
			Menu::Option("prop_irish_sign_03");
			Menu::Option("prop_irish_sign_04");
			Menu::Option("prop_irish_sign_05");
			Menu::Option("prop_irish_sign_06");
			Menu::Option("prop_irish_sign_07");
			Menu::Option("prop_irish_sign_08");
			Menu::Option("prop_irish_sign_09");
			Menu::Option("prop_irish_sign_10");
			Menu::Option("prop_irish_sign_11");
			Menu::Option("prop_irish_sign_12");
			Menu::Option("prop_irish_sign_13");
			Menu::Option("prop_loggneon");
			Menu::Option("prop_patriotneon");
			Menu::Option("prop_pitcher_01_cs");
			Menu::Option("prop_ragganeon");
			Menu::Option("prop_shots_glass_cs");
			Menu::Option("prop_stripmenu");
			Menu::Option("prop_bread_rack_01");
			Menu::Option("prop_bread_rack_02");
			Menu::Option("prop_chip_fryer");
			Menu::Option("prop_coffee_mac_02");
			Menu::Option("prop_detergent_01a");
			Menu::Option("prop_detergent_01b");
			Menu::Option("prop_ff_counter_01");
			Menu::Option("prop_ff_counter_02");
			Menu::Option("prop_ff_counter_03");
			Menu::Option("prop_ff_noodle_01");
			Menu::Option("prop_ff_noodle_02");
			Menu::Option("prop_ff_shelves_01");
			Menu::Option("prop_ff_sink_01");
			Menu::Option("prop_ff_sink_02");
			Menu::Option("prop_food_bin_01");
			Menu::Option("prop_food_bin_02");
			Menu::Option("prop_food_bs_bshelf");
			Menu::Option("prop_food_bs_cups01");
			Menu::Option("prop_food_bs_cups03");
			Menu::Option("prop_food_bs_soda_01");
			Menu::Option("prop_food_bs_soda_02");
			Menu::Option("prop_food_bs_tray_01");
			Menu::Option("prop_food_bs_tray_06");
			Menu::Option("prop_food_burg1");
			Menu::Option("prop_food_burg2");
			Menu::Option("prop_food_cb_bshelf");
			Menu::Option("prop_food_cb_burg01");
			Menu::Option("prop_food_cb_cups01");
			Menu::Option("prop_food_cb_donuts");
			Menu::Option("prop_food_cb_nugets");
			Menu::Option("prop_food_cb_soda_01");
			Menu::Option("prop_food_cb_soda_02");
			Menu::Option("prop_food_cb_tray_01");
			Menu::Option("prop_food_cups1");
			Menu::Option("prop_food_napkin_01");
			Menu::Option("prop_food_napkin_02");
			Menu::Option("prop_food_tray_01");
			Menu::Option("prop_griddle_01");
			Menu::Option("prop_griddle_02");
			Menu::Option("prop_handtowels");
			Menu::Option("prop_juice_dispenser");
			Menu::Option("prop_kebab_grill");
			Menu::Option("prop_microwave_1");
			Menu::Option("prop_pizza_oven_01");
			Menu::Option("prop_slush_dispenser");
			Menu::Option("prop_bumper_01");
			Menu::Option("prop_bumper_02");
			Menu::Option("prop_bumper_03");
			Menu::Option("prop_bumper_04");
			Menu::Option("prop_bumper_05");
			Menu::Option("prop_bumper_06");
			Menu::Option("prop_carcreeper");
			Menu::Option("prop_carjack");
			Menu::Option("prop_carjack_l2");
			Menu::Option("prop_car_battery_01");
			Menu::Option("prop_car_bonnet_01");
			Menu::Option("prop_car_bonnet_02");
			Menu::Option("prop_car_door_01");
			Menu::Option("prop_car_door_02");
			Menu::Option("prop_car_door_03");
			Menu::Option("prop_car_door_04");
			Menu::Option("prop_car_engine_01");
			Menu::Option("prop_car_exhaust_01");
			Menu::Option("prop_car_seat");
			Menu::Option("prop_cheetah_covered");
			Menu::Option("prop_compressor_01");
			Menu::Option("prop_compressor_02");
			Menu::Option("prop_compressor_03");
			Menu::Option("prop_entityxf_covered");
			Menu::Option("prop_jb700_covered");
			Menu::Option("prop_spray_jackframe");
			Menu::Option("prop_spray_jackleg");
			Menu::Option("prop_toolchest_01");
			Menu::Option("prop_toolchest_02");
			Menu::Option("prop_toolchest_03");
			Menu::Option("prop_toolchest_04");
			Menu::Option("prop_toolchest_05");
			Menu::Option("prop_wheel_01");
			Menu::Option("prop_wheel_02");
			Menu::Option("prop_wheel_03");
			Menu::Option("prop_wheel_04");
			Menu::Option("prop_wheel_05");
			Menu::Option("prop_wheel_06");
			Menu::Option("prop_wheel_hub_01");
			Menu::Option("prop_wheel_hub_02_lod_02");
			Menu::Option("prop_wheel_rim_01");
			Menu::Option("prop_wheel_rim_02");
			Menu::Option("prop_wheel_rim_03");
			Menu::Option("prop_wheel_rim_04");
			Menu::Option("prop_wheel_rim_05");
			Menu::Option("prop_wheel_tyre");
			Menu::Option("prop_ztype_covered");
			Menu::Option("prop_cabinet_01");
			Menu::Option("prop_cabinet_01b");
			Menu::Option("prop_cabinet_02b");
			Menu::Option("prop_coathook_01");
			Menu::Option("prop_copier_01");
			Menu::Option("prop_fan_01");
			Menu::Option("prop_fax_01");
			Menu::Option("prop_folder_01");
			Menu::Option("prop_folder_02");
			Menu::Option("prop_in_tray_01");
			Menu::Option("prop_office_alarm_01");
			Menu::Option("prop_office_desk_01");
			Menu::Option("prop_off_chair_01");
			Menu::Option("prop_off_chair_03");
			Menu::Option("prop_off_chair_04");
			Menu::Option("prop_off_chair_04b");
			Menu::Option("prop_off_chair_05");
			Menu::Option("prop_off_phone_01");
			Menu::Option("prop_paper_box_01");
			Menu::Option("prop_paper_box_02");
			Menu::Option("prop_paper_box_03");
			Menu::Option("prop_paper_box_04");
			Menu::Option("prop_paper_box_05");
			Menu::Option("prop_printer_01");
			Menu::Option("prop_printer_02");
			Menu::Option("prop_shredder_01");
			Menu::Option("prop_sol_chair");
			Menu::Option("prop_tablesmall_01");
			Menu::Option("prop_waiting_seat_01");
			Menu::Option("prop_wait_bench_01");
			Menu::Option("prop_water_bottle");
			Menu::Option("prop_water_bottle_dark");
			Menu::Option("prop_air_bagloader");
			Menu::Option("prop_air_bagloader2");
			Menu::Option("prop_air_barrier");
			Menu::Option("prop_air_bench_01");
			Menu::Option("prop_air_bench_02");
			Menu::Option("prop_air_bigradar_l1");
			Menu::Option("prop_air_bigradar_l2");
			Menu::Option("prop_air_bigradar_slod");
			Menu::Option("prop_air_blastfence_01");
			Menu::Option("prop_air_blastfence_02");
			Menu::Option("prop_air_bridge01");
			Menu::Option("prop_air_bridge02");
			Menu::Option("prop_air_cargoloader_01");
			Menu::Option("prop_air_cargo_01a");
			Menu::Option("prop_air_cargo_01b");
			Menu::Option("prop_air_cargo_01c");
			Menu::Option("prop_air_cargo_02a");
			Menu::Option("prop_air_cargo_02b");
			Menu::Option("prop_air_cargo_03a");
			Menu::Option("prop_air_cargo_04a");
			Menu::Option("prop_air_cargo_04b");
			Menu::Option("prop_air_cargo_04c");
			Menu::Option("prop_air_chock_01");
			Menu::Option("prop_air_chock_03");
			Menu::Option("prop_air_chock_04");
			Menu::Option("prop_air_fueltrail1");
			Menu::Option("prop_air_fueltrail2");
			Menu::Option("prop_air_gasbogey_01");
			Menu::Option("prop_air_generator_01");
			Menu::Option("prop_air_generator_03");
			Menu::Option("prop_air_lights_01a");
			Menu::Option("prop_air_lights_01b");
			Menu::Option("prop_air_lights_03a");
			Menu::Option("prop_air_luggtrolley");
			Menu::Option("prop_air_mast_01");
			Menu::Option("prop_air_mast_02");
			Menu::Option("prop_air_monhut_01");
			Menu::Option("prop_air_monhut_02");
			Menu::Option("prop_air_monhut_03");
			Menu::Option("prop_air_propeller01");
			Menu::Option("prop_air_radar_01");
			Menu::Option("prop_air_stair_01");
			Menu::Option("prop_air_stair_02");
			Menu::Option("prop_air_stair_03");
			Menu::Option("prop_air_stair_04a");
			Menu::Option("prop_air_stair_04b");
			Menu::Option("prop_air_towbar_01");
			Menu::Option("prop_air_towbar_02");
			Menu::Option("prop_air_towbar_03");
			Menu::Option("prop_air_trailer_4a");
			Menu::Option("prop_air_trailer_4b");
			Menu::Option("prop_air_trailer_4c");
			Menu::Option("prop_air_watertank1");
			Menu::Option("prop_air_watertank2");
			Menu::Option("prop_air_windsock_base");
			Menu::Option("prop_air_woodsteps");
			Menu::Option("prop_luggage_01a");
			Menu::Option("prop_luggage_02a");
			Menu::Option("prop_luggage_03a");
			Menu::Option("prop_luggage_04a");
			Menu::Option("prop_luggage_05a");
			Menu::Option("prop_luggage_06a");
			Menu::Option("prop_luggage_07a");
			Menu::Option("prop_luggage_08a");
			Menu::Option("prop_luggage_09a");
			Menu::Option("prop_mb_cargo_01a");
			Menu::Option("prop_mb_cargo_02a");
			Menu::Option("prop_mb_cargo_03a");
			Menu::Option("prop_mb_cargo_04a");
			Menu::Option("prop_mb_cargo_04b");
			Menu::Option("prop_mb_crate_01a");
			Menu::Option("prop_mb_crate_01b");
			Menu::Option("prop_mb_hesco_06");
			Menu::Option("prop_mb_ordnance_01");
			Menu::Option("prop_mb_ordnance_03");
			Menu::Option("prop_mb_sandblock_01");
			Menu::Option("prop_mb_sandblock_02");
			Menu::Option("prop_mb_sandblock_03");
			Menu::Option("prop_mb_sandblock_04");
			Menu::Option("prop_mb_sandblock_05");
			Menu::Option("prop_boxcar5_handle");
			Menu::Option("prop_byard_bench01");
			Menu::Option("prop_byard_bench02");
			Menu::Option("prop_byard_block_01");
			Menu::Option("prop_byard_boat01");
			Menu::Option("prop_byard_boat02");
			Menu::Option("prop_byard_chains01");
			Menu::Option("prop_byard_dingy");
			Menu::Option("prop_byard_elecbox01");
			Menu::Option("prop_byard_elecbox02");
			Menu::Option("prop_byard_elecbox03");
			Menu::Option("prop_byard_elecbox04");
			Menu::Option("prop_byard_floatpile");
			Menu::Option("prop_byard_float_01");
			Menu::Option("prop_byard_float_01b");
			Menu::Option("prop_byard_float_02");
			Menu::Option("prop_byard_float_02b");
			Menu::Option("prop_byard_hoist");
			Menu::Option("prop_byard_hoist_2");
			Menu::Option("prop_byard_hoses01");
			Menu::Option("prop_byard_hoses02");
			Menu::Option("prop_byard_ladder01");
			Menu::Option("prop_byard_machine01");
			Menu::Option("prop_byard_machine02");
			Menu::Option("prop_byard_machine03");
			Menu::Option("prop_byard_motor_01");
			Menu::Option("prop_byard_motor_02");
			Menu::Option("prop_byard_motor_03");
			Menu::Option("prop_byard_net02");
			Menu::Option("prop_byard_phone");
			Menu::Option("prop_byard_pipes01");
			Menu::Option("prop_byard_pipe_01");
			Menu::Option("prop_byard_planks01");
			Menu::Option("prop_byard_pulley01");
			Menu::Option("prop_byard_rack");
			Menu::Option("prop_byard_ramp");
			Menu::Option("prop_byard_rampold");
			Menu::Option("prop_byard_rowboat1");
			Menu::Option("prop_byard_rowboat2");
			Menu::Option("prop_byard_rowboat3");
			Menu::Option("prop_byard_rowboat4");
			Menu::Option("prop_byard_rowboat5");
			Menu::Option("prop_byard_scfhold01");
			Menu::Option("prop_byard_sleeper01");
			Menu::Option("prop_byard_sleeper02");
			Menu::Option("prop_byard_steps_01");
			Menu::Option("prop_byard_tank_01");
			Menu::Option("prop_byard_trailer01");
			Menu::Option("prop_byard_trailer02");
			Menu::Option("prop_crane_01_truck1");
			Menu::Option("prop_crane_01_truck2");
			Menu::Option("prop_dock_bouy_1");
			Menu::Option("prop_dock_bouy_2");
			Menu::Option("prop_dock_bouy_3");
			Menu::Option("prop_dock_bouy_5");
			Menu::Option("prop_dock_crane_01");
			Menu::Option("prop_dock_crane_02");
			Menu::Option("prop_dock_crane_02_cab");
			Menu::Option("prop_dock_crane_02_hook");
			Menu::Option("prop_dock_crane_02_ld");
			Menu::Option("prop_dock_crane_04");
			Menu::Option("prop_dock_crane_lift");
			Menu::Option("prop_dock_float_1");
			Menu::Option("prop_dock_float_1b");
			Menu::Option("prop_dock_moor_01");
			Menu::Option("prop_dock_moor_04");
			Menu::Option("prop_dock_moor_05");
			Menu::Option("prop_dock_moor_06");
			Menu::Option("prop_dock_moor_07");
			Menu::Option("prop_dock_ropefloat");
			Menu::Option("prop_dock_ropetyre1");
			Menu::Option("prop_dock_ropetyre2");
			Menu::Option("prop_dock_ropetyre3");
			Menu::Option("prop_dock_rtg_01");
			Menu::Option("prop_dock_rtg_ld");
			Menu::Option("prop_dock_shippad");
			Menu::Option("prop_dock_sign_01");
			Menu::Option("prop_dock_woodpole1");
			Menu::Option("prop_dock_woodpole2");
			Menu::Option("prop_dock_woodpole3");
			Menu::Option("prop_dock_woodpole4");
			Menu::Option("prop_dock_woodpole5");
			Menu::Option("prop_ind_barge_01");
			Menu::Option("prop_ind_barge_02");
			Menu::Option("prop_ind_coalcar_01");
			Menu::Option("prop_ind_coalcar_02");
			Menu::Option("prop_ind_coalcar_03");
			Menu::Option("prop_ind_oldcrane");
			Menu::Option("prop_jetski_ramp_01");
			Menu::Option("prop_railsleepers01");
			Menu::Option("prop_railsleepers02");
			Menu::Option("prop_railstack01");
			Menu::Option("prop_railstack02");
			Menu::Option("prop_railstack03");
			Menu::Option("prop_railstack04");
			Menu::Option("prop_railstack05");
			Menu::Option("prop_rail_boxcar");
			Menu::Option("prop_rail_boxcar2");
			Menu::Option("prop_rail_boxcar3");
			Menu::Option("prop_rail_boxcar4");
			Menu::Option("prop_rail_boxcar5");
			Menu::Option("prop_rail_boxcar5_d");
			Menu::Option("prop_rail_buffer_01");
			Menu::Option("prop_rail_buffer_02");
			Menu::Option("prop_rail_crane_01");
			Menu::Option("prop_rail_points01");
			Menu::Option("prop_rail_points02");
			Menu::Option("prop_rail_sigbox01");
			Menu::Option("prop_rail_sigbox02");
			Menu::Option("prop_rail_signals02");
			Menu::Option("prop_rail_tankcar");
			Menu::Option("prop_rail_tankcar2");
			Menu::Option("prop_rail_tankcar3");
			Menu::Option("prop_rail_wellcar");
			Menu::Option("prop_rail_wellcar2");
			Menu::Option("p_dock_rtg_ld_cab");
			Menu::Option("p_dock_rtg_ld_spdr");
			Menu::Option("p_dock_rtg_ld_wheel");
			Menu::Option("prop_fac_machine_02");
			Menu::Option("prop_ind_conveyor_01");
			Menu::Option("prop_ind_conveyor_02");
			Menu::Option("prop_ind_conveyor_04");
			Menu::Option("prop_ind_crusher");
			Menu::Option("prop_ind_deiseltank");
			Menu::Option("prop_ind_mech_01c");
			Menu::Option("prop_ind_mech_02a");
			Menu::Option("prop_ind_mech_02b");
			Menu::Option("prop_ind_mech_03a");
			Menu::Option("prop_ind_mech_04a");
			Menu::Option("prop_jyard_block_01a");
			Menu::Option("prop_oil_derrick_01");
			Menu::Option("prop_oil_guage_01");
			Menu::Option("prop_oil_spool_02");
			Menu::Option("prop_oil_valve_01");
			Menu::Option("prop_oil_valve_02");
			Menu::Option("prop_oil_wellhead_01");
			Menu::Option("prop_oil_wellhead_03");
			Menu::Option("prop_oil_wellhead_04");
			Menu::Option("prop_oil_wellhead_05");
			Menu::Option("prop_oil_wellhead_06");
			Menu::Option("prop_portacabin01");
			Menu::Option("prop_portasteps_01");
			Menu::Option("prop_portasteps_02");
			Menu::Option("prop_pylon_01");
			Menu::Option("prop_pylon_02");
			Menu::Option("prop_pylon_03");
			Menu::Option("prop_pylon_04");
			Menu::Option("prop_sluicegate");
			Menu::Option("prop_sluicegatel");
			Menu::Option("prop_sluicegater");
			Menu::Option("prop_storagetank_01");
			Menu::Option("prop_storagetank_02");
			Menu::Option("prop_storagetank_03");
			Menu::Option("prop_storagetank_03a");
			Menu::Option("prop_storagetank_03b");
			Menu::Option("prop_storagetank_04");
			Menu::Option("prop_storagetank_05");
			Menu::Option("prop_storagetank_06");
			Menu::Option("prop_storagetank_07a");
			Menu::Option("prop_sub_crane_hook");
			Menu::Option("prop_sub_frame_01a");
			Menu::Option("prop_sub_frame_01b");
			Menu::Option("prop_sub_frame_01c");
			Menu::Option("prop_sub_frame_02a");
			Menu::Option("prop_sub_frame_03a");
			Menu::Option("prop_sub_frame_04a");
			Menu::Option("prop_sub_frame_04b");
			Menu::Option("prop_sub_gantry");
			Menu::Option("prop_sub_trans_01a");
			Menu::Option("prop_sub_trans_02a");
			Menu::Option("prop_sub_trans_03a");
			Menu::Option("prop_sub_trans_04a");
			Menu::Option("prop_sub_trans_05b");
			Menu::Option("prop_sub_trans_06b");
			Menu::Option("prop_windmill_01_l1");
			Menu::Option("prop_windmill_01_slod");
			Menu::Option("prop_windmill_01_slod2");
			Menu::Option("prop_acc_guitar_01");
			Menu::Option("prop_acc_guitar_01_d1");
			Menu::Option("prop_alien_egg_01");
			Menu::Option("prop_amb_handbag_01");
			Menu::Option("prop_amb_phone");
			Menu::Option("prop_asteroid_01");
			Menu::Option("prop_attache_case_01");
			Menu::Option("prop_bank_shutter");
			Menu::Option("prop_bank_vaultdoor");
			Menu::Option("prop_barrel_float_1");
			Menu::Option("prop_barrel_float_2");
			Menu::Option("prop_beggers_sign_01");
			Menu::Option("prop_beggers_sign_02");
			Menu::Option("prop_beggers_sign_03");
			Menu::Option("prop_beggers_sign_04");
			Menu::Option("prop_bh1_16_display");
			Menu::Option("prop_big_bag_01");
			Menu::Option("prop_big_clock_01");
			Menu::Option("prop_biotech_store");
			Menu::Option("prop_bomb_01");
			Menu::Option("prop_bonesaw");
			Menu::Option("prop_bskball_01");
			Menu::Option("prop_b_board_blank");
			Menu::Option("prop_cable_hook_01");
			Menu::Option("prop_camera_strap");
			Menu::Option("prop_cash_dep_bag_01");
			Menu::Option("prop_cash_trolly");
			Menu::Option("prop_chem_grill");
			Menu::Option("prop_chem_grill_bit");
			Menu::Option("prop_chem_vial_02");
			Menu::Option("prop_chem_vial_02b");
			Menu::Option("prop_choc_ego");
			Menu::Option("prop_choc_meto");
			Menu::Option("prop_choc_pq");
			Menu::Option("prop_clapper_brd_01");
			Menu::Option("prop_cone_float_1");
			Menu::Option("prop_container_hole");
			Menu::Option("prop_cont_chiller_01");
			Menu::Option("prop_cork_board");
			Menu::Option("prop_cranial_saw");
			Menu::Option("prop_crate_float_1");
			Menu::Option("prop_cs_20m_rope");
			Menu::Option("prop_cs_30m_rope");
			Menu::Option("prop_cs_aircon_01");
			Menu::Option("prop_cs_aircon_fan");
			Menu::Option("prop_cs_ashtray");
			Menu::Option("prop_cs_bin_01");
			Menu::Option("prop_cs_bin_01_lid");
			Menu::Option("prop_cs_bin_02");
			Menu::Option("prop_cs_bin_03");
			Menu::Option("prop_cs_box_clothes");
			Menu::Option("prop_cs_cardbox_01");
			Menu::Option("prop_cs_dumpster_01a");
			Menu::Option("prop_cs_dumpster_lidl");
			Menu::Option("prop_cs_dumpster_lidr");
			Menu::Option("prop_cs_fertilizer");
			Menu::Option("prop_cs_folding_chair_01");
			Menu::Option("prop_cs_fridge");
			Menu::Option("prop_cs_fridge_door");
			Menu::Option("prop_cs_heist_bag_01");
			Menu::Option("prop_cs_heist_bag_02");
			Menu::Option("prop_cs_heist_bag_strap_01");
			Menu::Option("prop_cs_h_bag_strap_01");
			Menu::Option("prop_cs_ice_locker");
			Menu::Option("prop_cs_ice_locker_door_l");
			Menu::Option("prop_cs_ice_locker_door_r");
			Menu::Option("prop_cs_keys_01");
			Menu::Option("prop_cs_leaf");
			Menu::Option("prop_cs_office_chair");
			Menu::Option("prop_cs_package_01");
			Menu::Option("prop_cs_panel_01");
			Menu::Option("prop_cs_panties");
			Menu::Option("prop_cs_panties_02");
			Menu::Option("prop_cs_panties_03");
			Menu::Option("prop_cs_planning_photo");
			Menu::Option("prop_cs_polaroid");
			Menu::Option("prop_cs_remote_01");
			Menu::Option("prop_cs_rope_tie_01");
			Menu::Option("prop_cs_rub_binbag_01");
			Menu::Option("prop_cs_scissors");
			Menu::Option("prop_cs_shopping_bag");
			Menu::Option("prop_cs_spray_can");
			Menu::Option("prop_cs_tablet");
			Menu::Option("prop_cs_tablet_02");
			Menu::Option("prop_cs_vial_01");
			Menu::Option("prop_cs_walking_stick");
			Menu::Option("prop_cub_door_lifeblurb");
			Menu::Option("prop_cub_lifeblurb");
			Menu::Option("prop_cuff_keys_01");
			Menu::Option("prop_defilied_ragdoll_01");
			Menu::Option("prop_drop_armscrate_01");
			Menu::Option("prop_drop_armscrate_01b");
			Menu::Option("prop_dummy_01");
			Menu::Option("prop_dummy_light");
			Menu::Option("prop_dummy_plane");
			Menu::Option("prop_egg_clock_01");
			Menu::Option("prop_ejector_seat_01");
			Menu::Option("prop_el_guitar_01");
			Menu::Option("prop_el_guitar_02");
			Menu::Option("prop_el_guitar_03");
			Menu::Option("prop_fbibombbin");
			Menu::Option("prop_fbibombcupbrd");
			Menu::Option("prop_fbibombfile");
			Menu::Option("prop_fbibombplant");
			Menu::Option("prop_feed_sack_01");
			Menu::Option("prop_feed_sack_02");
			Menu::Option("prop_fib_broken_window");
			Menu::Option("prop_flash_unit");
			Menu::Option("prop_flatbed_strap_b");
			Menu::Option("prop_floor_duster_01");
			Menu::Option("prop_folded_polo_shirt");
			Menu::Option("prop_foundation_sponge");
			Menu::Option("prop_fruit_basket");
			Menu::Option("prop_f_duster_02");
			Menu::Option("prop_gascyl_ramp_01");
			Menu::Option("prop_gascyl_ramp_door_01");
			Menu::Option("prop_gas_grenade");
			Menu::Option("prop_gas_mask_hang_01");
			Menu::Option("prop_gold_bar");
			Menu::Option("prop_gold_trolly");
			Menu::Option("prop_gold_trolly_full");
			Menu::Option("prop_grapes_01");
			Menu::Option("prop_grapes_02");
			Menu::Option("prop_hacky_sack_01");
			Menu::Option("prop_hd_seats_01");
			Menu::Option("prop_hole_plug_01");
			Menu::Option("prop_hotel_clock_01");
			Menu::Option("prop_hotel_trolley");
			Menu::Option("prop_huge_display_01");
			Menu::Option("prop_huge_display_02");
			Menu::Option("prop_idol_01_error");
			Menu::Option("prop_idol_case_01");
			Menu::Option("prop_ing_camera_01");
			Menu::Option("prop_int_gate01");
			Menu::Option("prop_jewel_02a");
			Menu::Option("prop_jewel_02b");
			Menu::Option("prop_jewel_02c");
			Menu::Option("prop_jewel_03a");
			Menu::Option("prop_jewel_03b");
			Menu::Option("prop_jewel_04a");
			Menu::Option("prop_jewel_04b");
			Menu::Option("prop_jewel_pickup_new_01");
			Menu::Option("prop_j_disptray_01");
			Menu::Option("prop_j_disptray_01b");
			Menu::Option("prop_j_disptray_01_dam");
			Menu::Option("prop_j_disptray_02");
			Menu::Option("prop_j_disptray_02_dam");
			Menu::Option("prop_j_disptray_03");
			Menu::Option("prop_j_disptray_03_dam");
			Menu::Option("prop_j_disptray_04");
			Menu::Option("prop_j_disptray_04b");
			Menu::Option("prop_j_disptray_05");
			Menu::Option("prop_j_disptray_05b");
			Menu::Option("prop_j_heist_pic_01");
			Menu::Option("prop_j_heist_pic_02");
			Menu::Option("prop_j_heist_pic_03");
			Menu::Option("prop_j_heist_pic_04");
			Menu::Option("prop_j_neck_disp_01");
			Menu::Option("prop_j_neck_disp_02");
			Menu::Option("prop_j_neck_disp_03");
			Menu::Option("prop_large_gold");
			Menu::Option("prop_large_gold_alt_a");
			Menu::Option("prop_large_gold_alt_b");
			Menu::Option("prop_large_gold_alt_c");
			Menu::Option("prop_large_gold_empty");
			Menu::Option("prop_ld_alarm_01");
			Menu::Option("prop_ld_alarm_01_dam");
			Menu::Option("prop_ld_alarm_alert");
			Menu::Option("prop_ld_armour");
			Menu::Option("prop_ld_binbag_01");
			Menu::Option("prop_ld_bomb");
			Menu::Option("prop_ld_cable");
			Menu::Option("prop_ld_cable_tie_01");
			Menu::Option("prop_ld_case_01");
			Menu::Option("prop_ld_case_01_lod");
			Menu::Option("prop_ld_container");
			Menu::Option("prop_ld_contain_dl");
			Menu::Option("prop_ld_contain_dl2");
			Menu::Option("prop_ld_contain_dr");
			Menu::Option("prop_ld_contain_dr2");
			Menu::Option("prop_ld_crate_01");
			Menu::Option("prop_ld_crate_lid_01");
			Menu::Option("prop_ld_fan_01");
			Menu::Option("prop_ld_fan_01_old");
			Menu::Option("prop_ld_greenscreen_01");
			Menu::Option("prop_ld_handbag");
			Menu::Option("prop_ld_haybail");
			Menu::Option("prop_ld_health_pack");
			Menu::Option("prop_ld_hook");
			Menu::Option("prop_ld_int_safe_01");
			Menu::Option("prop_ld_jerrycan_01");
			Menu::Option("prop_ld_keypad_01");
			Menu::Option("prop_ld_keypad_01b");
			Menu::Option("prop_ld_keypad_01b_lod");
			Menu::Option("prop_ld_lap_top");
			Menu::Option("prop_ld_monitor_01");
			Menu::Option("prop_ld_pipe_single_01");
			Menu::Option("prop_ld_planning_pin_01");
			Menu::Option("prop_ld_planning_pin_02");
			Menu::Option("prop_ld_planning_pin_03");
			Menu::Option("prop_ld_purse_01");
			Menu::Option("prop_ld_purse_01_lod");
			Menu::Option("prop_ld_rope_t");
			Menu::Option("prop_ld_rub_binbag_01");
			Menu::Option("prop_ld_suitcase_01");
			Menu::Option("prop_ld_suitcase_02");
			Menu::Option("prop_ld_toilet_01");
			Menu::Option("prop_ld_vault_door");
			Menu::Option("prop_ld_wallet_01");
			Menu::Option("prop_ld_w_me_machette");
			Menu::Option("prop_lectern_01");
			Menu::Option("prop_lev_crate_01");
			Menu::Option("prop_lifeblurb_01");
			Menu::Option("prop_lifeblurb_01b");
			Menu::Option("prop_lifeblurb_02");
			Menu::Option("prop_lifeblurb_02b");
			Menu::Option("prop_mast_01");
			Menu::Option("prop_medal_01");
			Menu::Option("prop_med_bag_01");
			Menu::Option("prop_med_bag_01b");
			Menu::Option("prop_michael_backpack");
			Menu::Option("prop_mr_rasberryclean");
			Menu::Option("prop_mr_raspberry_01");
			Menu::Option("prop_muster_wboard_01");
			Menu::Option("prop_muster_wboard_02");
			Menu::Option("prop_necklace_board");
			Menu::Option("prop_new_drug_pack_01");
			Menu::Option("prop_night_safe_01");
			Menu::Option("prop_novel_01");
			Menu::Option("prop_npc_phone");
			Menu::Option("prop_npc_phone_02");
			Menu::Option("prop_out_door_speaker");
			Menu::Option("prop_overalls_01");
			Menu::Option("prop_paper_bag_01");
			Menu::Option("prop_paper_bag_small");
			Menu::Option("prop_paper_ball");
			Menu::Option("prop_pap_camera_01");
			Menu::Option("prop_parachute");
			Menu::Option("prop_parapack_01");
			Menu::Option("prop_paynspray_door_l");
			Menu::Option("prop_paynspray_door_r");
			Menu::Option("prop_ped_pic_01");
			Menu::Option("prop_ped_pic_01_sm");
			Menu::Option("prop_ped_pic_02");
			Menu::Option("prop_ped_pic_02_sm");
			Menu::Option("prop_ped_pic_03");
			Menu::Option("prop_ped_pic_03_sm");
			Menu::Option("prop_ped_pic_04");
			Menu::Option("prop_ped_pic_04_sm");
			Menu::Option("prop_ped_pic_05");
			Menu::Option("prop_ped_pic_05_sm");
			Menu::Option("prop_ped_pic_06");
			Menu::Option("prop_ped_pic_06_sm");
			Menu::Option("prop_ped_pic_07");
			Menu::Option("prop_ped_pic_07_sm");
			Menu::Option("prop_ped_pic_08");
			Menu::Option("prop_ped_pic_08_sm");
			Menu::Option("prop_phone_ing");
			Menu::Option("prop_phone_ing_02");
			Menu::Option("prop_phone_ing_03");
			Menu::Option("prop_phone_overlay_01");
			Menu::Option("prop_phone_overlay_02");
			Menu::Option("prop_phone_overlay_anim");
			Menu::Option("prop_phone_proto");
			Menu::Option("prop_phone_proto_back");
			Menu::Option("prop_phone_proto_battery");
			Menu::Option("prop_player_phone_01");
			Menu::Option("prop_player_phone_02");
			Menu::Option("prop_podium_mic");
			Menu::Option("prop_police_phone");
			Menu::Option("prop_poly_bag_01");
			Menu::Option("prop_poly_bag_money");
			Menu::Option("prop_pool_ball_01");
			Menu::Option("prop_postit_drive");
			Menu::Option("prop_postit_gun");
			Menu::Option("prop_postit_it");
			Menu::Option("prop_postit_lock");
			Menu::Option("prop_prologue_phone");
			Menu::Option("prop_protest_sign_01");
			Menu::Option("prop_protest_table_01");
			Menu::Option("prop_prototype_minibomb");
			Menu::Option("prop_rag_01");
			Menu::Option("prop_rf_conc_pillar");
			Menu::Option("prop_riding_crop_01");
			Menu::Option("prop_rock_chair_01");
			Menu::Option("prop_rolled_yoga_mat");
			Menu::Option("prop_rope_hook_01");
			Menu::Option("prop_scalpel");
			Menu::Option("prop_scrap_win_01");
			Menu::Option("prop_security_case_01");
			Menu::Option("prop_security_case_02");
			Menu::Option("prop_shamal_crash");
			Menu::Option("prop_shopping_bags01");
			Menu::Option("prop_shopping_bags02");
			Menu::Option("prop_showroom_glass_1b");
			Menu::Option("prop_side_lights");
			Menu::Option("prop_single_rose");
			Menu::Option("prop_sky_cover_01");
			Menu::Option("prop_sm_19_clock");
			Menu::Option("prop_sm_locker_door");
			Menu::Option("prop_spot_01");
			Menu::Option("prop_spot_clamp");
			Menu::Option("prop_spot_clamp_02");
			Menu::Option("prop_stat_pack_01");
			Menu::Option("prop_strip_pole_01");
			Menu::Option("prop_sub_chunk_01");
			Menu::Option("prop_tail_gate_col");
			Menu::Option("prop_taxi_meter_1");
			Menu::Option("prop_taxi_meter_2");
			Menu::Option("prop_telescope_01");
			Menu::Option("prop_tennis_bag_01");
			Menu::Option("prop_test_elevator");
			Menu::Option("prop_test_elevator_dl");
			Menu::Option("prop_test_elevator_dr");
			Menu::Option("prop_tick");
			Menu::Option("prop_tick_02");
			Menu::Option("prop_toiletfoot_static");
			Menu::Option("prop_torture_ch_01");
			Menu::Option("prop_tri_table_01");
			Menu::Option("prop_tyre_spike_01");
			Menu::Option("prop_t_coffe_table");
			Menu::Option("prop_t_sofa");
			Menu::Option("prop_t_sofa_02");
			Menu::Option("prop_t_telescope_01b");
			Menu::Option("prop_vb_34_tencrt_lighting");
			Menu::Option("prop_vehicle_hook");
			Menu::Option("prop_v_bmike_01");
			Menu::Option("prop_v_cam_01");
			Menu::Option("prop_v_hook_s");
			Menu::Option("prop_v_m_phone_01");
			Menu::Option("prop_v_parachute");
			Menu::Option("prop_water_ramp_01");
			Menu::Option("prop_water_ramp_02");
			Menu::Option("prop_water_ramp_03");
			Menu::Option("prop_wheelchair_01");
			Menu::Option("prop_windowbox_a");
			Menu::Option("prop_windowbox_b");
			Menu::Option("prop_windowbox_broken");
			Menu::Option("prop_windowbox_small");
			Menu::Option("prop_win_trailer_ld");
			Menu::Option("prop_w_board_blank");
			Menu::Option("prop_w_board_blank_2");
			Menu::Option("prop_yoga_mat_01");
			Menu::Option("prop_yoga_mat_02");
			Menu::Option("prop_yoga_mat_03");
			Menu::Option("p_amb_bag_bottle_01");
			Menu::Option("p_amb_brolly_01");
			Menu::Option("p_amb_brolly_01_s");
			Menu::Option("p_amb_clipboard_01");
			Menu::Option("p_amb_coffeecup_01");
			Menu::Option("p_amb_joint_01");
			Menu::Option("p_amb_lap_top_01");
			Menu::Option("p_amb_lap_top_02");
			Menu::Option("p_amb_phone_01");
			Menu::Option("p_car_keys_01");
			Menu::Option("p_counter_01_glass");
			Menu::Option("p_counter_01_glass_plug");
			Menu::Option("p_counter_02_glass");
			Menu::Option("p_counter_03_glass");
			Menu::Option("p_counter_04_glass");
			Menu::Option("p_cs_cam_phone");
			Menu::Option("p_cs_comb_01");
			Menu::Option("p_cs_laptop_02");
			Menu::Option("p_cs_laptop_02_w");
			Menu::Option("p_cs_locker_01");
			Menu::Option("p_cs_locker_02");
			Menu::Option("p_cs_locker_door_01");
			Menu::Option("p_cs_locker_door_01b");
			Menu::Option("p_cs_locker_door_02");
			Menu::Option("p_cs_paper_disp_02");
			Menu::Option("p_cs_paper_disp_1");
			Menu::Option("p_disp_02_door_01");
			Menu::Option("p_ferris_car_01");
			Menu::Option("p_f_duster_handle_01");
			Menu::Option("p_f_duster_head_01");
			Menu::Option("p_ing_skiprope_01");
			Menu::Option("p_int_jewel_mirror");
			Menu::Option("p_int_jewel_plant_01");
			Menu::Option("p_int_jewel_plant_02");
			Menu::Option("p_jewel_necklace_02");
			Menu::Option("p_ld_am_ball_01");
			Menu::Option("p_ld_coffee_vend_01");
			Menu::Option("p_ld_conc_cyl_01");
			Menu::Option("p_ld_frisbee_01");
			Menu::Option("p_ld_heist_bag_01");
			Menu::Option("p_ld_sax");
			Menu::Option("p_ld_soc_ball_01");
			Menu::Option("p_new_j_counter_01");
			Menu::Option("p_new_j_counter_02");
			Menu::Option("p_new_j_counter_03");
			Menu::Option("p_num_plate_01");
			Menu::Option("p_num_plate_02");
			Menu::Option("p_num_plate_03");
			Menu::Option("p_num_plate_04");
			Menu::Option("p_oil_slick_01");
			Menu::Option("p_pharm_unit_01");
			Menu::Option("p_pharm_unit_02");
			Menu::Option("p_planning_board_01");
			Menu::Option("p_planning_board_02");
			Menu::Option("p_planning_board_03");
			Menu::Option("p_planning_board_04");
			Menu::Option("p_secret_weapon_02");
			Menu::Option("p_stinger_02");
			Menu::Option("p_stinger_03");
			Menu::Option("p_stinger_04");
			Menu::Option("p_stinger_piece_01");
			Menu::Option("p_stinger_piece_02");
			Menu::Option("p_watch_01");
			Menu::Option("p_watch_02");
			Menu::Option("p_watch_03");
			Menu::Option("p_watch_04");
			Menu::Option("p_watch_05");
			Menu::Option("p_watch_06");
			Menu::Option("prop_bomb_01_s");
			Menu::Option("prop_cs_bin_01_skinned");
			Menu::Option("prop_cs_bucket_s");
			Menu::Option("prop_cs_bucket_s_lod");
			Menu::Option("prop_cs_mop_s");
			Menu::Option("prop_f_duster_01_s");
			Menu::Option("prop_ld_case_01_s");
			Menu::Option("prop_ld_handbag_s");
			Menu::Option("prop_ld_wallet_01_s");
			Menu::Option("prop_news_disp_02a_s");
			Menu::Option("prop_off_chair_04_s");
			Menu::Option("prop_p_jack_03_col");
			Menu::Option("prop_rub_binbag_sd_01");
			Menu::Option("prop_rub_binbag_sd_02");
			Menu::Option("prop_v_m_phone_o1s");
			Menu::Option("p_abat_roller_1");
			Menu::Option("p_abat_roller_1_col");
			Menu::Option("p_amb_drain_water_double");
			Menu::Option("p_amb_drain_water_longstrip");
			Menu::Option("p_amb_drain_water_single");
			Menu::Option("p_attache_case_01_s");
			Menu::Option("p_balaclavamichael_s");
			Menu::Option("p_barierbase_test_s");
			Menu::Option("p_barier_test_s");
			Menu::Option("p_beefsplitter_s");
			Menu::Option("p_cargo_chute_s");
			Menu::Option("p_cigar_pack_02_s");
			Menu::Option("p_cs_locker_01_s");
			Menu::Option("p_cs_script_bottle_s");
			Menu::Option("p_dock_crane_cable_s");
			Menu::Option("p_dock_crane_cabl_s");
			Menu::Option("p_dock_crane_sld_s");
			Menu::Option("p_dumpster_t");
			Menu::Option("p_fag_packet_01_s");
			Menu::Option("p_ferris_wheel_amo_l");
			Menu::Option("p_ferris_wheel_amo_l2");
			Menu::Option("p_ferris_wheel_amo_p");
			Menu::Option("p_gar_door_01_s");
			Menu::Option("p_gar_door_02_s");
			Menu::Option("p_gar_door_03_s");
			Menu::Option("p_gdoor1colobject_s");
			Menu::Option("p_gdoor1_s");
			Menu::Option("p_ing_skiprope_01_s");
			Menu::Option("p_jewel_necklace01_s");
			Menu::Option("p_jewel_necklace02_s");
			Menu::Option("p_jewel_pickup33_s");
			Menu::Option("p_ld_coffee_vend_s");
			Menu::Option("p_ld_heist_bag_s");
			Menu::Option("p_ld_stinger_s");
			Menu::Option("p_litter_picker_s");
			Menu::Option("p_mast_01_s");
			Menu::Option("p_notepad_01_s");
			Menu::Option("p_oil_pjack_01_amo");
			Menu::Option("p_oil_pjack_01_frg_s");
			Menu::Option("p_oil_pjack_02_amo");
			Menu::Option("p_oil_pjack_02_frg_s");
			Menu::Option("p_oil_pjack_03_amo");
			Menu::Option("p_oil_pjack_03_frg_s");
			Menu::Option("p_pallet_02a_s");
			Menu::Option("p_panties_s");
			Menu::Option("p_parachute1_mp_s");
			Menu::Option("p_parachute1_s");
			Menu::Option("p_parachute1_sp_s");
			Menu::Option("p_parachute_fallen_s");
			Menu::Option("p_parachute_s");
			Menu::Option("p_parachute_s_shop");
			Menu::Option("p_para_broken1_s");
			Menu::Option("p_patio_lounger1_s");
			Menu::Option("p_phonebox_02_s");
			Menu::Option("p_pliers_01_s");
			Menu::Option("p_rcss_folded");
			Menu::Option("p_rcss_s");
			Menu::Option("p_ringbinder_01_s");
			Menu::Option("p_sec_gate_01_s");
			Menu::Option("p_sec_gate_01_s_col");
			Menu::Option("p_shoalfish_s");
			Menu::Option("p_skiprope_r_s");
			Menu::Option("p_sofa_s");
			Menu::Option("p_sub_crane_s");
			Menu::Option("p_sunglass_m_s");
			Menu::Option("p_tennis_bag_01_s");
			Menu::Option("p_tram_crash_s");
			Menu::Option("p_watch_01_s");
			Menu::Option("p_watch_02_s");
			Menu::Option("p_watch_03_s");
			Menu::Option("p_waterboardc_s");
			Menu::Option("p_yacht_chair_01_s");
			Menu::Option("p_yacht_sofa_01_s");
			Menu::Option("p_yoga_mat_01_s");
			Menu::Option("p_yoga_mat_02_s");
			Menu::Option("p_yoga_mat_03_s");
			Menu::Option("pop_v_bank_door_l");
			Menu::Option("pop_v_bank_door_r");
			Menu::Option("prop_abat_roller_static");
			Menu::Option("prop_abat_slide");
			Menu::Option("prop_artgallery_02_dl");
			Menu::Option("prop_artgallery_02_dr");
			Menu::Option("prop_artgallery_dl");
			Menu::Option("prop_artgallery_dr");
			Menu::Option("prop_barn_door_l");
			Menu::Option("prop_barn_door_r");
			Menu::Option("prop_bh1_03_gate_l");
			Menu::Option("prop_bh1_03_gate_r");
			Menu::Option("prop_bh1_08_mp_gar");
			Menu::Option("prop_bh1_09_mp_gar");
			Menu::Option("prop_bh1_09_mp_l");
			Menu::Option("prop_bh1_09_mp_r");
			Menu::Option("prop_bh1_44_door_01l");
			Menu::Option("prop_bh1_44_door_01r");
			Menu::Option("prop_bh1_48_backdoor_l");
			Menu::Option("prop_bh1_48_backdoor_r");
			Menu::Option("prop_bh1_48_gate_1");
			Menu::Option("prop_bhhotel_door_l");
			Menu::Option("prop_bhhotel_door_r");
			Menu::Option("prop_biolab_g_door");
			Menu::Option("prop_broken_cell_gate_01");
			Menu::Option("prop_bs_map_door_01");
			Menu::Option("prop_burto_gate_01");
			Menu::Option("prop_casino_door_01l");
			Menu::Option("prop_casino_door_01r");
			Menu::Option("prop_ch1_07_door_01l");
			Menu::Option("prop_ch1_07_door_01r");
			Menu::Option("prop_ch1_07_door_02l");
			Menu::Option("prop_ch1_07_door_02r");
			Menu::Option("prop_ch2_05d_g_door");
			Menu::Option("prop_ch2_07b_20_g_door");
			Menu::Option("prop_ch2_09b_door");
			Menu::Option("prop_ch2_09c_garage_door");
			Menu::Option("prop_ch3_01_trlrdoor_l");
			Menu::Option("prop_ch3_01_trlrdoor_r");
			Menu::Option("prop_ch3_04_door_01l");
			Menu::Option("prop_ch3_04_door_01r");
			Menu::Option("prop_ch3_04_door_02");
			Menu::Option("prop_ch_025c_g_door_01");
			Menu::Option("prop_com_gar_door_01");
			Menu::Option("prop_com_ls_door_01");
			Menu::Option("prop_control_rm_door_01");
			Menu::Option("prop_cs1_14b_traind");
			Menu::Option("prop_cs1_14b_traind_dam");
			Menu::Option("prop_cs4_05_tdoor");
			Menu::Option("prop_cs4_10_tr_gd_01");
			Menu::Option("prop_cs4_11_door");
			Menu::Option("prop_cs6_03_door_l");
			Menu::Option("prop_cs6_03_door_r");
			Menu::Option("prop_cs_freightdoor_l1");
			Menu::Option("prop_cs_freightdoor_r1");
			Menu::Option("prop_cs_gravyard_gate_l");
			Menu::Option("prop_cs_gravyard_gate_r");
			Menu::Option("prop_cs_sc1_11_gate");
			Menu::Option("prop_cs_sm_27_gate");
			Menu::Option("prop_damdoor_01");
			Menu::Option("prop_door_01");
			Menu::Option("prop_door_balcony_frame");
			Menu::Option("prop_door_balcony_left");
			Menu::Option("prop_door_balcony_right");
			Menu::Option("prop_dt1_20_mp_door_l");
			Menu::Option("prop_dt1_20_mp_door_r");
			Menu::Option("prop_dt1_20_mp_gar");
			Menu::Option("prop_d_balcony_l_light");
			Menu::Option("prop_d_balcony_r_light");
			Menu::Option("prop_epsilon_door_l");
			Menu::Option("prop_epsilon_door_r");
			Menu::Option("prop_faceoffice_door_l");
			Menu::Option("prop_faceoffice_door_r");
			Menu::Option("prop_gar_door_01");
			Menu::Option("prop_gar_door_02");
			Menu::Option("prop_gar_door_03");
			Menu::Option("prop_gar_door_03_ld");
			Menu::Option("prop_gar_door_04");
			Menu::Option("prop_gar_door_05");
			Menu::Option("prop_gar_door_05_l");
			Menu::Option("prop_gar_door_05_r");
			Menu::Option("prop_gar_door_a_01");
			Menu::Option("prop_gar_door_plug");
			Menu::Option("prop_gd_ch2_08");
			Menu::Option("prop_grumandoor_l");
			Menu::Option("prop_grumandoor_r");
			Menu::Option("prop_hanger_door_1");
			Menu::Option("prop_hospitaldoors_start");
			Menu::Option("prop_hospital_door_l");
			Menu::Option("prop_hospital_door_r");
			Menu::Option("prop_hw1_03_gardoor_01");
			Menu::Option("prop_hw1_04_door_l1");
			Menu::Option("prop_hw1_04_door_r1");
			Menu::Option("prop_hw1_23_door");
			Menu::Option("prop_id2_11_gdoor");
			Menu::Option("prop_id_21_gardoor_01");
			Menu::Option("prop_id_21_gardoor_02");
			Menu::Option("prop_indus_meet_door_l");
			Menu::Option("prop_indus_meet_door_r");
			Menu::Option("prop_kt1_06_door_l");
			Menu::Option("prop_kt1_06_door_r");
			Menu::Option("prop_kt1_10_mpdoor_l");
			Menu::Option("prop_kt1_10_mpdoor_r");
			Menu::Option("prop_ld_garaged_01");
			Menu::Option("prop_ld_jail_door");
			Menu::Option("prop_magenta_door");
			Menu::Option("prop_map_door_01");
			Menu::Option("prop_michael_door");
			Menu::Option("prop_motel_door_09");
			Menu::Option("prop_police_door_l");
			Menu::Option("prop_police_door_l_dam");
			Menu::Option("prop_police_door_r");
			Menu::Option("prop_police_door_r_dam");
			Menu::Option("prop_police_door_surround");
			Menu::Option("prop_pris_door_01_l");
			Menu::Option("prop_pris_door_01_r");
			Menu::Option("prop_pris_door_02");
			Menu::Option("prop_pris_door_03");
			Menu::Option("prop_ql_revolving_door");
			Menu::Option("prop_ret_door");
			Menu::Option("prop_ret_door_02");
			Menu::Option("prop_ret_door_03");
			Menu::Option("prop_ret_door_04");
			Menu::Option("prop_ron_door_01");
			Menu::Option("prop_sc1_06_gate_l");
			Menu::Option("prop_sc1_06_gate_r");
			Menu::Option("prop_sc1_12_door");
			Menu::Option("prop_sc1_21_g_door_01");
			Menu::Option("prop_section_garage_01");
			Menu::Option("prop_sec_gate_01b");
			Menu::Option("prop_sec_gate_01c");
			Menu::Option("prop_sec_gate_01d");
			Menu::Option("prop_showroom_door_l");
			Menu::Option("prop_showroom_door_r");
			Menu::Option("prop_sm1_11_doorl");
			Menu::Option("prop_sm1_11_doorr");
			Menu::Option("prop_sm1_11_garaged");
			Menu::Option("prop_sm_10_mp_door");
			Menu::Option("prop_sm_14_mp_gar");
			Menu::Option("prop_sm_27_door");
			Menu::Option("prop_sm_27_gate");
			Menu::Option("prop_sm_27_gate_02");
			Menu::Option("prop_sm_27_gate_03");
			Menu::Option("prop_sm_27_gate_04");
			Menu::Option("prop_ss1_05_mp_door");
			Menu::Option("prop_ss1_08_mp_door_l");
			Menu::Option("prop_ss1_08_mp_door_r");
			Menu::Option("prop_ss1_10_door_l");
			Menu::Option("prop_ss1_10_door_r");
			Menu::Option("prop_ss1_14_garage_door");
			Menu::Option("prop_ss1_mpint_door_l");
			Menu::Option("prop_ss1_mpint_door_r");
			Menu::Option("prop_ss1_mpint_garage");
			Menu::Option("prop_ss1_mpint_garage_cl");
			Menu::Option("prop_strip_door_01");
			Menu::Option("prop_vault_shutter");
			Menu::Option("prop_v_door_44");
			Menu::Option("prop_wardrobe_door_01");
			Menu::Option("prop_win_plug_01");
			Menu::Option("prop_win_plug_01_dam");
			Menu::Option("p_cut_door_01");
			Menu::Option("p_cut_door_02");
			Menu::Option("p_cut_door_03");
			Menu::Option("p_jewel_door_l");
			Menu::Option("p_jewel_door_r1");
			Menu::Option("prop_a4_pile_01");
			Menu::Option("prop_a4_sheet_01");
			Menu::Option("prop_a4_sheet_02");
			Menu::Option("prop_a4_sheet_03");
			Menu::Option("prop_a4_sheet_04");
			Menu::Option("prop_a4_sheet_05");
			Menu::Option("prop_aiprort_sign_01");
			Menu::Option("prop_aiprort_sign_02");
			Menu::Option("prop_amanda_note_01");
			Menu::Option("prop_amanda_note_01b");
			Menu::Option("prop_amb_40oz_02");
			Menu::Option("prop_amb_40oz_03");
			Menu::Option("prop_amb_beer_bottle");
			Menu::Option("prop_amb_ciggy_01");
			Menu::Option("prop_amb_donut");
			Menu::Option("prop_anim_cash_note");
			Menu::Option("prop_anim_cash_note_b");
			Menu::Option("prop_anim_cash_pile_01");
			Menu::Option("prop_anim_cash_pile_02");
			Menu::Option("prop_arc_blueprints_01");
			Menu::Option("prop_armour_pickup");
			Menu::Option("prop_artifact_01");
			Menu::Option("prop_ashtray_01");
			Menu::Option("prop_aviators_01");
			Menu::Option("prop_a_trailer_door_01");
			Menu::Option("prop_ballistic_shield");
			Menu::Option("prop_ballistic_shield_lod1");
			Menu::Option("prop_barry_table_detail");
			Menu::Option("prop_basejump_target_01");
			Menu::Option("prop_battery_01");
			Menu::Option("prop_battery_02");
			Menu::Option("prop_beer_box_01");
			Menu::Option("prop_beta_tape");
			Menu::Option("prop_big_shit_01");
			Menu::Option("prop_big_shit_02");
			Menu::Option("prop_binoc_01");
			Menu::Option("prop_bison_winch");
			Menu::Option("prop_blackjack_01");
			Menu::Option("prop_blox_spray");
			Menu::Option("prop_bodyarmour_02");
			Menu::Option("prop_bodyarmour_03");
			Menu::Option("prop_bodyarmour_04");
			Menu::Option("prop_bodyarmour_05");
			Menu::Option("prop_bodyarmour_06");
			Menu::Option("prop_bongos_01");
			Menu::Option("prop_bong_01");
			Menu::Option("prop_boombox_01");
			Menu::Option("prop_bottle_cap_01");
			Menu::Option("prop_bowl_crisps");
			Menu::Option("prop_broken_cboard_p1");
			Menu::Option("prop_broken_cboard_p2");
			Menu::Option("prop_busker_hat_01");
			Menu::Option("prop_c4_final");
			Menu::Option("prop_c4_final_green");
			Menu::Option("prop_candy_pqs");
			Menu::Option("prop_cargo_int");
			Menu::Option("prop_carrier_bag_01");
			Menu::Option("prop_carrier_bag_01_lod");
			Menu::Option("prop_carwash_roller_horz");
			Menu::Option("prop_carwash_roller_vert");
			Menu::Option("prop_car_ignition");
			Menu::Option("prop_casey_sec_id");
			Menu::Option("prop_cash_case_01");
			Menu::Option("prop_cash_case_02");
			Menu::Option("prop_cash_crate_01");
			Menu::Option("prop_cash_envelope_01");
			Menu::Option("prop_cash_note_01");
			Menu::Option("prop_cash_pile_01");
			Menu::Option("prop_cash_pile_02");
			Menu::Option("prop_ceramic_jug_01");
			Menu::Option("prop_ceramic_jug_cork");
			Menu::Option("prop_cigar_01");
			Menu::Option("prop_cigar_02");
			Menu::Option("prop_cigar_03");
			Menu::Option("prop_cigar_pack_01");
			Menu::Option("prop_cigar_pack_02");
			Menu::Option("prop_cliff_paper");
			Menu::Option("prop_clippers_01");
			Menu::Option("prop_coffee_cup_trailer");
			Menu::Option("prop_coffin_02");
			Menu::Option("prop_coffin_02b");
			Menu::Option("prop_coke_block_01");
			Menu::Option("prop_coke_block_half_a");
			Menu::Option("prop_coke_block_half_b");
			Menu::Option("prop_controller_01");
			Menu::Option("prop_crisp");
			Menu::Option("prop_crisp_small");
			Menu::Option("prop_cs_abattoir_switch");
			Menu::Option("prop_cs_amanda_shoe");
			Menu::Option("prop_cs_bandana");
			Menu::Option("prop_cs_bar");
			Menu::Option("prop_cs_beer_bot_01");
			Menu::Option("prop_cs_beer_bot_01b");
			Menu::Option("prop_cs_beer_bot_01lod");
			Menu::Option("prop_cs_beer_bot_02");
			Menu::Option("prop_cs_beer_bot_03");
			Menu::Option("prop_cs_beer_bot_40oz");
			Menu::Option("prop_cs_beer_bot_40oz_02");
			Menu::Option("prop_cs_beer_bot_40oz_03");
			Menu::Option("prop_cs_beer_bot_test");
			Menu::Option("prop_cs_binder_01");
			Menu::Option("prop_cs_book_01");
			Menu::Option("prop_cs_bottle_opener");
			Menu::Option("prop_cs_bowie_knife");
			Menu::Option("prop_cs_bowl_01");
			Menu::Option("prop_cs_bowl_01b");
			Menu::Option("prop_cs_box_step");
			Menu::Option("prop_cs_brain_chunk");
			Menu::Option("prop_cs_bs_cup");
			Menu::Option("prop_cs_burger_01");
			Menu::Option("prop_cs_business_card");
			Menu::Option("prop_cs_cash_note_01");
			Menu::Option("prop_cs_cctv");
			Menu::Option("prop_cs_champ_flute");
			Menu::Option("prop_cs_ciggy_01");
			Menu::Option("prop_cs_ciggy_01b");
			Menu::Option("prop_cs_clothes_box");
			Menu::Option("prop_cs_coke_line");
			Menu::Option("prop_cs_cont_latch");
			Menu::Option("prop_cs_crackpipe");
			Menu::Option("prop_cs_credit_card");
			Menu::Option("prop_cs_creeper_01");
			Menu::Option("prop_cs_crisps_01");
			Menu::Option("prop_cs_cuffs_01");
			Menu::Option("prop_cs_diaphram");
			Menu::Option("prop_cs_dildo_01");
			Menu::Option("prop_cs_documents_01");
			Menu::Option("prop_cs_dog_lead_2a");
			Menu::Option("prop_cs_dog_lead_2b");
			Menu::Option("prop_cs_dog_lead_2c");
			Menu::Option("prop_cs_dog_lead_3a");
			Menu::Option("prop_cs_dog_lead_3b");
			Menu::Option("prop_cs_dog_lead_a");
			Menu::Option("prop_cs_dog_lead_b");
			Menu::Option("prop_cs_dog_lead_c");
			Menu::Option("prop_cs_duffel_01");
			Menu::Option("prop_cs_duffel_01b");
			Menu::Option("prop_cs_dvd");
			Menu::Option("prop_cs_dvd_case");
			Menu::Option("prop_cs_envolope_01");
			Menu::Option("prop_cs_film_reel_01");
			Menu::Option("prop_cs_fork");
			Menu::Option("prop_cs_frank_photo");
			Menu::Option("prop_cs_fuel_hose");
			Menu::Option("prop_cs_fuel_nozle");
			Menu::Option("prop_cs_gascutter_1");
			Menu::Option("prop_cs_gascutter_2");
			Menu::Option("prop_cs_glass_scrap");
			Menu::Option("prop_cs_gunrack");
			Menu::Option("prop_cs_hand_radio");
			Menu::Option("prop_cs_heist_rope");
			Menu::Option("prop_cs_heist_rope_b");
			Menu::Option("prop_cs_hotdog_01");
			Menu::Option("prop_cs_hotdog_02");
			Menu::Option("prop_cs_ilev_blind_01");
			Menu::Option("prop_cs_ironing_board");
			Menu::Option("prop_cs_katana_01");
			Menu::Option("prop_cs_kettle_01");
			Menu::Option("prop_cs_lazlow_ponytail");
			Menu::Option("prop_cs_lazlow_shirt_01");
			Menu::Option("prop_cs_lazlow_shirt_01b");
			Menu::Option("prop_cs_leg_chain_01");
			Menu::Option("prop_cs_lester_crate");
			Menu::Option("prop_cs_lipstick");
			Menu::Option("prop_cs_magazine");
			Menu::Option("prop_cs_marker_01");
			Menu::Option("prop_cs_meth_pipe");
			Menu::Option("prop_cs_milk_01");
			Menu::Option("prop_cs_mini_tv");
			Menu::Option("prop_cs_mopbucket_01");
			Menu::Option("prop_cs_nail_file");
			Menu::Option("prop_cs_newspaper");
			Menu::Option("prop_cs_overalls_01");
			Menu::Option("prop_cs_padlock");
			Menu::Option("prop_cs_pamphlet_01");
			Menu::Option("prop_cs_paper_cup");
			Menu::Option("prop_cs_para_ropebit");
			Menu::Option("prop_cs_para_ropes");
			Menu::Option("prop_cs_pebble");
			Menu::Option("prop_cs_pebble_02");
			Menu::Option("prop_cs_petrol_can");
			Menu::Option("prop_cs_phone_01");
			Menu::Option("prop_cs_photoframe_01");
			Menu::Option("prop_cs_pills");
			Menu::Option("prop_cs_plane_int_01");
			Menu::Option("prop_cs_plate_01");
			Menu::Option("prop_cs_police_torch");
			Menu::Option("prop_cs_pour_tube");
			Menu::Option("prop_cs_power_cell");
			Menu::Option("prop_cs_power_cord");
			Menu::Option("prop_cs_protest_sign_01");
			Menu::Option("prop_cs_protest_sign_02");
			Menu::Option("prop_cs_protest_sign_02b");
			Menu::Option("prop_cs_protest_sign_03");
			Menu::Option("prop_cs_protest_sign_04a");
			Menu::Option("prop_cs_protest_sign_04b");
			Menu::Option("prop_cs_rage_statue_p1");
			Menu::Option("prop_cs_rage_statue_p2");
			Menu::Option("prop_cs_rolled_paper");
			Menu::Option("prop_cs_rub_box_01");
			Menu::Option("prop_cs_rub_box_02");
			Menu::Option("prop_cs_r_business_card");
			Menu::Option("prop_cs_sack_01");
			Menu::Option("prop_cs_saucer_01");
			Menu::Option("prop_cs_script_bottle");
			Menu::Option("prop_cs_script_bottle_01");
			Menu::Option("prop_cs_server_drive");
			Menu::Option("prop_cs_sheers");
			Menu::Option("prop_cs_shirt_01");
			Menu::Option("prop_cs_shot_glass");
			Menu::Option("prop_cs_silver_tray");
			Menu::Option("prop_cs_sink_filler");
			Menu::Option("prop_cs_sink_filler_02");
			Menu::Option("prop_cs_sink_filler_03");
			Menu::Option("prop_cs_sol_glasses");
			Menu::Option("prop_cs_steak");
			Menu::Option("prop_cs_stock_book");
			Menu::Option("prop_cs_street_binbag_01");
			Menu::Option("prop_cs_street_card_01");
			Menu::Option("prop_cs_street_card_02");
			Menu::Option("prop_cs_sub_hook_01");
			Menu::Option("prop_cs_sub_rope_01");
			Menu::Option("prop_cs_swipe_card");
			Menu::Option("prop_cs_toaster");
			Menu::Option("prop_cs_trolley_01");
			Menu::Option("prop_cs_trowel");
			Menu::Option("prop_cs_truck_ladder");
			Menu::Option("prop_cs_tshirt_ball_01");
			Menu::Option("prop_cs_t_shirt_pile");
			Menu::Option("prop_cs_valve");
			Menu::Option("prop_cs_vent_cover");
			Menu::Option("prop_cs_walkie_talkie");
			Menu::Option("prop_cs_whiskey_bottle");
			Menu::Option("prop_cs_whiskey_bot_stop");
			Menu::Option("prop_cs_wrench");
			Menu::Option("prop_devin_box_01");
			Menu::Option("prop_devin_rope_01");
			Menu::Option("prop_direct_chair_01");
			Menu::Option("prop_direct_chair_02");
			Menu::Option("prop_disp_razor_01");
			Menu::Option("prop_distantcar_day");
			Menu::Option("prop_distantcar_night");
			Menu::Option("prop_distantcar_truck");
			Menu::Option("prop_donut_01");
			Menu::Option("prop_donut_02");
			Menu::Option("prop_donut_02b");
			Menu::Option("prop_door_bell_01");
			Menu::Option("prop_double_grid_line");
			Menu::Option("prop_drug_package");
			Menu::Option("prop_drug_package_02");
			Menu::Option("prop_dummy_car");
			Menu::Option("prop_ear_defenders_01");
			Menu::Option("prop_ecg_01");
			Menu::Option("prop_ecg_01_cable_01");
			Menu::Option("prop_ecg_01_cable_02");
			Menu::Option("prop_ecola_can");
			Menu::Option("prop_employee_month_01");
			Menu::Option("prop_employee_month_02");
			Menu::Option("prop_energy_drink");
			Menu::Option("prop_face_rag_01");
			Menu::Option("prop_fag_packet_01");
			Menu::Option("prop_fbi3_coffee_table");
			Menu::Option("prop_fib_badge");
			Menu::Option("prop_fib_skylight_piece");
			Menu::Option("prop_fishing_rod_01");
			Menu::Option("prop_fishing_rod_02");
			Menu::Option("prop_fish_slice_01");
			Menu::Option("prop_flare_01");
			Menu::Option("prop_flare_01b");
			Menu::Option("prop_flatbed_strap");
			Menu::Option("prop_flight_box_01");
			Menu::Option("prop_flight_box_insert");
			Menu::Option("prop_flight_box_insert2");
			Menu::Option("prop_franklin_dl");
			Menu::Option("prop_f_b_insert_broken");
			Menu::Option("prop_gaffer_arm_bind");
			Menu::Option("prop_gaffer_arm_bind_cut");
			Menu::Option("prop_gaffer_leg_bind");
			Menu::Option("prop_gaffer_leg_bind_cut");
			Menu::Option("prop_gaffer_tape");
			Menu::Option("prop_gaffer_tape_strip");
			Menu::Option("prop_glasscutter_01");
			Menu::Option("prop_glass_suck_holder");
			Menu::Option("prop_gold_cont_01");
			Menu::Option("prop_gold_cont_01b");
			Menu::Option("prop_gold_trolly_strap_01");
			Menu::Option("prop_gun_case_01");
			Menu::Option("prop_gun_case_02");
			Menu::Option("prop_gun_frame");
			Menu::Option("prop_hand_toilet");
			Menu::Option("prop_hard_hat_01");
			Menu::Option("prop_headphones_01");
			Menu::Option("prop_headset_01");
			Menu::Option("prop_hockey_bag_01");
			Menu::Option("prop_holster_01");
			Menu::Option("prop_hose_nozzle");
			Menu::Option("prop_huf_rag_01");
			Menu::Option("prop_ice_cube_01");
			Menu::Option("prop_ice_cube_02");
			Menu::Option("prop_ice_cube_03");
			Menu::Option("prop_id2_20_clock");
			Menu::Option("prop_idol_01");
			Menu::Option("prop_idol_case");
			Menu::Option("prop_idol_case_02");
			Menu::Option("prop_ing_crowbar");
			Menu::Option("prop_inhaler_01");
			Menu::Option("prop_iron_01");
			Menu::Option("prop_jet_bloodsplat_01");
			Menu::Option("prop_juice_pool_01");
			Menu::Option("prop_ld_ammo_pack_01");
			Menu::Option("prop_ld_ammo_pack_02");
			Menu::Option("prop_ld_ammo_pack_03");
			Menu::Option("prop_ld_barrier_01");
			Menu::Option("prop_ld_bomb_01");
			Menu::Option("prop_ld_bomb_01_open");
			Menu::Option("prop_ld_bomb_anim");
			Menu::Option("prop_ld_can_01");
			Menu::Option("prop_ld_contact_card");
			Menu::Option("prop_ld_crocclips01");
			Menu::Option("prop_ld_crocclips02");
			Menu::Option("prop_ld_dummy_rope");
			Menu::Option("prop_ld_fags_01");
			Menu::Option("prop_ld_fags_02");
			Menu::Option("prop_ld_faucet");
			Menu::Option("prop_ld_ferris_wheel");
			Menu::Option("prop_ld_fireaxe");
			Menu::Option("prop_ld_flow_bottle");
			Menu::Option("prop_ld_gold_tooth");
			Menu::Option("prop_ld_hdd_01");
			Menu::Option("prop_ld_peep_slider");
			Menu::Option("prop_ld_rail_01");
			Menu::Option("prop_ld_rail_02");
			Menu::Option("prop_ld_rubble_01");
			Menu::Option("prop_ld_rubble_02");
			Menu::Option("prop_ld_rubble_03");
			Menu::Option("prop_ld_rubble_04");
			Menu::Option("prop_ld_scrap");
			Menu::Option("prop_ld_shovel");
			Menu::Option("prop_ld_shovel_dirt");
			Menu::Option("prop_ld_snack_01");
			Menu::Option("prop_ld_test_01");
			Menu::Option("prop_ld_tooth");
			Menu::Option("prop_ld_wallet_02");
			Menu::Option("prop_ld_wallet_pickup");
			Menu::Option("prop_lev_des_barge_01");
			Menu::Option("prop_lev_des_barge_02");
			Menu::Option("prop_lift_overlay_01");
			Menu::Option("prop_lift_overlay_02");
			Menu::Option("prop_litter_picker");
			Menu::Option("prop_loose_rag_01");
			Menu::Option("prop_med_jet_01");
			Menu::Option("prop_megaphone_01");
			Menu::Option("prop_mem_candle_04");
			Menu::Option("prop_mem_candle_05");
			Menu::Option("prop_mem_candle_06");
			Menu::Option("prop_mem_reef_01");
			Menu::Option("prop_mem_reef_02");
			Menu::Option("prop_mem_reef_03");
			Menu::Option("prop_mem_teddy_01");
			Menu::Option("prop_mem_teddy_02");
			Menu::Option("prop_meth_bag_01");
			Menu::Option("prop_michael_balaclava");
			Menu::Option("prop_michael_sec_id");
			Menu::Option("prop_microphone_02");
			Menu::Option("prop_military_pickup_01");
			Menu::Option("prop_mil_crate_01");
			Menu::Option("prop_mil_crate_02");
			Menu::Option("prop_minigun_01");
			Menu::Option("prop_money_bag_01");
			Menu::Option("prop_mp3_dock");
			Menu::Option("prop_mp_arrow_barrier_01");
			Menu::Option("prop_mp_barrier_01");
			Menu::Option("prop_mp_barrier_01b");
			Menu::Option("prop_mp_barrier_02");
			Menu::Option("prop_mp_barrier_02b");
			Menu::Option("prop_mp_base_marker");
			Menu::Option("prop_mp_boost_01");
			Menu::Option("prop_mp_cant_place_lrg");
			Menu::Option("prop_mp_cant_place_med");
			Menu::Option("prop_mp_cant_place_sm");
			Menu::Option("prop_mp_cone_01");
			Menu::Option("prop_mp_cone_02");
			Menu::Option("prop_mp_cone_03");
			Menu::Option("prop_mp_cone_04");
			Menu::Option("prop_mp_drug_package");
			Menu::Option("prop_mp_drug_pack_blue");
			Menu::Option("prop_mp_drug_pack_red");
			Menu::Option("prop_mp_icon_shad_lrg");
			Menu::Option("prop_mp_icon_shad_med");
			Menu::Option("prop_mp_icon_shad_sm");
			Menu::Option("prop_mp_max_out_lrg");
			Menu::Option("prop_mp_max_out_med");
			Menu::Option("prop_mp_max_out_sm");
			Menu::Option("prop_mp_num_0");
			Menu::Option("prop_mp_num_1");
			Menu::Option("prop_mp_num_2");
			Menu::Option("prop_mp_num_3");
			Menu::Option("prop_mp_num_4");
			Menu::Option("prop_mp_num_5");
			Menu::Option("prop_mp_num_6");
			Menu::Option("prop_mp_num_7");
			Menu::Option("prop_mp_num_8");
			Menu::Option("prop_mp_num_9");
			Menu::Option("prop_mp_placement");
			Menu::Option("prop_mp_placement_lrg");
			Menu::Option("prop_mp_placement_maxd");
			Menu::Option("prop_mp_placement_med");
			Menu::Option("prop_mp_placement_red");
			Menu::Option("prop_mp_placement_sm");
			Menu::Option("prop_mp_ramp_01");
			Menu::Option("prop_mp_ramp_02");
			Menu::Option("prop_mp_ramp_03");
			Menu::Option("prop_mp_repair");
			Menu::Option("prop_mp_repair_01");
			Menu::Option("prop_mp_respawn_02");
			Menu::Option("prop_mp_rocket_01");
			Menu::Option("prop_mp_spike_01");
			Menu::Option("prop_m_pack_int_01");
			Menu::Option("prop_nigel_bag_pickup");
			Menu::Option("prop_notepad_01");
			Menu::Option("prop_notepad_02");
			Menu::Option("prop_old_boot");
			Menu::Option("prop_orang_can_01");
			Menu::Option("prop_parking_wand_01");
			Menu::Option("prop_passport_01");
			Menu::Option("prop_peanut_bowl_01");
			Menu::Option("prop_pencil_01");
			Menu::Option("prop_piercing_gun");
			Menu::Option("prop_ping_pong");
			Menu::Option("prop_pistol_holster");
			Menu::Option("prop_plastic_cup_02");
			Menu::Option("prop_player_gasmask");
			Menu::Option("prop_pliers_01");
			Menu::Option("prop_police_radio_handset");
			Menu::Option("prop_police_radio_main");
			Menu::Option("prop_poster_tube_01");
			Menu::Option("prop_poster_tube_02");
			Menu::Option("prop_power_cell");
			Menu::Option("prop_power_cord_01");
			Menu::Option("prop_premier_fence_01");
			Menu::Option("prop_premier_fence_02");
			Menu::Option("prop_quad_grid_line");
			Menu::Option("prop_rad_waste_barrel_01");
			Menu::Option("prop_rail_controller");
			Menu::Option("prop_range_target_01");
			Menu::Option("prop_range_target_02");
			Menu::Option("prop_range_target_03");
			Menu::Option("prop_riot_shield");
			Menu::Option("prop_rolled_sock_01");
			Menu::Option("prop_rolled_sock_02");
			Menu::Option("prop_rope_family_3");
			Menu::Option("prop_safety_glasses");
			Menu::Option("prop_sam_01");
			Menu::Option("prop_sandwich_01");
			Menu::Option("prop_scaffold_pole");
			Menu::Option("prop_scn_police_torch");
			Menu::Option("prop_scourer_01");
			Menu::Option("prop_scrap_2_crate");
			Menu::Option("prop_sewing_fabric");
			Menu::Option("prop_sewing_machine");
			Menu::Option("prop_shower_towel");
			Menu::Option("prop_sh_beer_pissh_01");
			Menu::Option("prop_sh_bong_01");
			Menu::Option("prop_sh_cigar_01");
			Menu::Option("prop_sh_joint_01");
			Menu::Option("prop_sh_mr_rasp_01");
			Menu::Option("prop_sh_shot_glass");
			Menu::Option("prop_sh_tall_glass");
			Menu::Option("prop_sh_tt_fridgedoor");
			Menu::Option("prop_sh_wine_glass");
			Menu::Option("prop_single_grid_line");
			Menu::Option("prop_smg_holster_01");
			Menu::Option("prop_space_pistol");
			Menu::Option("prop_space_rifle");
			Menu::Option("prop_spycam");
			Menu::Option("prop_squeegee");
			Menu::Option("prop_stag_do_rope");
			Menu::Option("prop_start_finish_line_01");
			Menu::Option("prop_start_grid_01");
			Menu::Option("prop_stockade_wheel");
			Menu::Option("prop_stockade_wheel_flat");
			Menu::Option("prop_sub_cover_01");
			Menu::Option("prop_sub_release");
			Menu::Option("prop_syringe_01");
			Menu::Option("prop_table_mic_01");
			Menu::Option("prop_table_ten_bat");
			Menu::Option("prop_taco_01");
			Menu::Option("prop_taco_02");
			Menu::Option("prop_tapeplayer_01");
			Menu::Option("prop_target_arm");
			Menu::Option("prop_target_arm_b");
			Menu::Option("prop_target_arm_long");
			Menu::Option("prop_target_arm_sm");
			Menu::Option("prop_target_backboard");
			Menu::Option("prop_target_backboard_b");
			Menu::Option("prop_target_blue");
			Menu::Option("prop_target_blue_arrow");
			Menu::Option("prop_target_bull");
			Menu::Option("prop_target_bull_b");
			Menu::Option("prop_target_comp_metal");
			Menu::Option("prop_target_comp_wood");
			Menu::Option("prop_target_frame_01");
			Menu::Option("prop_target_inner1");
			Menu::Option("prop_target_inner2");
			Menu::Option("prop_target_inner2_b");
			Menu::Option("prop_target_inner3");
			Menu::Option("prop_target_inner3_b");
			Menu::Option("prop_target_inner_b");
			Menu::Option("prop_target_orange_arrow");
			Menu::Option("prop_target_oran_cross");
			Menu::Option("prop_target_ora_purp_01");
			Menu::Option("prop_target_purp_arrow");
			Menu::Option("prop_target_purp_cross");
			Menu::Option("prop_target_red");
			Menu::Option("prop_target_red_arrow");
			Menu::Option("prop_target_red_blue_01");
			Menu::Option("prop_target_red_cross");
			Menu::Option("prop_tarp_strap");
			Menu::Option("prop_tea_trolly");
			Menu::Option("prop_temp_block_blocker");
			Menu::Option("prop_tennis_ball");
			Menu::Option("prop_tennis_rack_01");
			Menu::Option("prop_tennis_rack_01b");
			Menu::Option("prop_time_capsule_01");
			Menu::Option("prop_tornado_wheel");
			Menu::Option("prop_torture_01");
			Menu::Option("prop_tourist_map_01");
			Menu::Option("prop_trailer_01_new");
			Menu::Option("prop_trailer_door_closed");
			Menu::Option("prop_trailer_door_open");
			Menu::Option("prop_trevor_rope_01");
			Menu::Option("prop_trev_sec_id");
			Menu::Option("prop_triple_grid_line");
			Menu::Option("prop_tri_finish_banner");
			Menu::Option("prop_tri_start_banner");
			Menu::Option("prop_tumbler_01");
			Menu::Option("prop_tumbler_01b");
			Menu::Option("prop_tumbler_01_empty");
			Menu::Option("prop_turkey_leg_01");
			Menu::Option("prop_tv_cam_02");
			Menu::Option("prop_tv_test");
			Menu::Option("prop_t_shirt_ironing");
			Menu::Option("prop_voltmeter_01");
			Menu::Option("prop_water_corpse_01");
			Menu::Option("prop_water_corpse_02");
			Menu::Option("prop_weed_01");
			Menu::Option("prop_weed_02");
			Menu::Option("prop_weed_block_01");
			Menu::Option("prop_weed_bottle");
			Menu::Option("prop_weed_pallet");
			Menu::Option("prop_weed_tub_01");
			Menu::Option("prop_weed_tub_01b");
			Menu::Option("prop_welding_mask_01");
			Menu::Option("prop_weld_torch");
			Menu::Option("prop_wheat_grass_empty");
			Menu::Option("prop_wheat_grass_glass");
			Menu::Option("prop_winch_hook_long");
			Menu::Option("prop_winch_hook_short");
			Menu::Option("prop_wrecked_buzzard");
			Menu::Option("prop_yacht_lounger");
			Menu::Option("prop_yacht_seat_01");
			Menu::Option("prop_yacht_seat_02");
			Menu::Option("prop_yacht_seat_03");
			Menu::Option("prop_yacht_table_01");
			Menu::Option("prop_yacht_table_02");
			Menu::Option("prop_yacht_table_03");
			Menu::Option("prop_yell_plastic_target");
			Menu::Option("p_amb_bagel_01");
			Menu::Option("p_cs_bbbat_01");
			Menu::Option("p_cs_bottle_01");
			Menu::Option("p_cs_clipboard");
			Menu::Option("p_cs_joint_01");
			Menu::Option("p_cs_joint_02");
			Menu::Option("p_cs_lighter_01");
			Menu::Option("p_cs_papers_01");
			Menu::Option("p_cs_papers_02");
			Menu::Option("p_cs_papers_03");
			Menu::Option("p_ing_bagel_01");
			Menu::Option("p_ing_microphonel_01");
			Menu::Option("p_ld_bs_bag_01");
			Menu::Option("p_ld_id_card_002");
			Menu::Option("p_ld_id_card_01");
			Menu::Option("p_rc_handset");
			Menu::Option("p_whiskey_notop");
			Menu::Option("p_whiskey_notop_empty");
			Menu::Option("prop_crashed_heli");
			Menu::Option("prop_ld_bankdoors_02");
			Menu::Option("prop_ld_fragwall_01a");
			Menu::Option("prop_pipe_single_01");
			Menu::Option("prop_test_boulder_01");
			Menu::Option("prop_test_boulder_02");
			Menu::Option("prop_test_boulder_03");
			Menu::Option("prop_test_boulder_04");
			Menu::Option("prop_trailr_base");
			Menu::Option("prop_trailr_base_static");
			Menu::Option("proc_drkyel001");
			Menu::Option("proc_flower1");
			Menu::Option("proc_flower_wild_04");
			Menu::Option("proc_weeds01a");
			Menu::Option("proc_weeds01b");
			Menu::Option("proc_weeds01c");
			Menu::Option("prop_test_bed");
			Menu::Option("proair_hoc_puck");
			Menu::Option("prop_airhockey_01");
			Menu::Option("prop_air_hoc_paddle_01");
			Menu::Option("prop_air_hoc_paddle_02");
			Menu::Option("prop_arcade_01");
			Menu::Option("prop_arcade_02");
			Menu::Option("prop_ice_box_01");
			Menu::Option("prop_ice_box_01_l1");
			Menu::Option("prop_jukebox_01");
			Menu::Option("prop_jukebox_02");
			Menu::Option("prop_park_ticket_01");
			Menu::Option("prop_pier_kiosk_01");
			Menu::Option("prop_pier_kiosk_02");
			Menu::Option("prop_pier_kiosk_03");
			Menu::Option("prop_pooltable_02");
			Menu::Option("prop_pooltable_3b");
			Menu::Option("prop_pool_cue");
			Menu::Option("prop_pool_rack_01");
			Menu::Option("prop_pool_rack_02");
			Menu::Option("prop_pool_tri");
			Menu::Option("prop_telescope");
			Menu::Option("prop_train_ticket_02");
			Menu::Option("prop_turnstyle_01");
			Menu::Option("prop_vend_coffe_01");
			Menu::Option("prop_vend_condom_01");
			Menu::Option("prop_vend_fags_01");
			Menu::Option("prop_vend_fridge01");
			Menu::Option("prop_vend_snak_01");
			Menu::Option("prop_apple_box_01");
			Menu::Option("prop_apple_box_02");
			Menu::Option("prop_arm_wrestle_01");
			Menu::Option("prop_a_base_bars_01");
			Menu::Option("prop_barbell_01");
			Menu::Option("prop_barbell_02");
			Menu::Option("prop_barbell_100kg");
			Menu::Option("prop_barbell_10kg");
			Menu::Option("prop_barbell_20kg");
			Menu::Option("prop_barbell_30kg");
			Menu::Option("prop_barbell_40kg");
			Menu::Option("prop_barbell_50kg");
			Menu::Option("prop_barbell_60kg");
			Menu::Option("prop_barbell_80kg");
			Menu::Option("prop_basketball_net");
			Menu::Option("prop_bball_arcade_01");
			Menu::Option("prop_beachbag_01");
			Menu::Option("prop_beachbag_02");
			Menu::Option("prop_beachbag_03");
			Menu::Option("prop_beachbag_04");
			Menu::Option("prop_beachbag_05");
			Menu::Option("prop_beachbag_06");
			Menu::Option("prop_beachbag_combo_01");
			Menu::Option("prop_beachbag_combo_02");
			Menu::Option("prop_beachball_02");
			Menu::Option("prop_beachflag_le");
			Menu::Option("prop_beach_bars_01");
			Menu::Option("prop_beach_bars_02");
			Menu::Option("prop_beach_bbq");
			Menu::Option("prop_beach_dip_bars_01");
			Menu::Option("prop_beach_dip_bars_02");
			Menu::Option("prop_beach_fire");
			Menu::Option("prop_beach_lg_float");
			Menu::Option("prop_beach_lg_stretch");
			Menu::Option("prop_beach_lg_surf");
			Menu::Option("prop_beach_lotion_01");
			Menu::Option("prop_beach_lotion_02");
			Menu::Option("prop_beach_lotion_03");
			Menu::Option("prop_beach_punchbag");
			Menu::Option("prop_beach_rings_01");
			Menu::Option("prop_beach_sculp_01");
			Menu::Option("prop_beach_towel_02");
			Menu::Option("prop_beach_volball01");
			Menu::Option("prop_beach_volball02");
			Menu::Option("prop_bikini_disp_01");
			Menu::Option("prop_bikini_disp_02");
			Menu::Option("prop_bikini_disp_03");
			Menu::Option("prop_bikini_disp_04");
			Menu::Option("prop_bikini_disp_05");
			Menu::Option("prop_bikini_disp_06");
			Menu::Option("prop_bleachers_01");
			Menu::Option("prop_bleachers_02");
			Menu::Option("prop_bleachers_03");
			Menu::Option("prop_bleachers_04");
			Menu::Option("prop_bleachers_05");
			Menu::Option("prop_boogbd_stack_01");
			Menu::Option("prop_boogbd_stack_02");
			Menu::Option("prop_boogieboard_01");
			Menu::Option("prop_boogieboard_02");
			Menu::Option("prop_boogieboard_03");
			Menu::Option("prop_boogieboard_04");
			Menu::Option("prop_boogieboard_05");
			Menu::Option("prop_boogieboard_06");
			Menu::Option("prop_boogieboard_07");
			Menu::Option("prop_boogieboard_08");
			Menu::Option("prop_boogieboard_09");
			Menu::Option("prop_boogieboard_10");
			Menu::Option("prop_bowling_ball");
			Menu::Option("prop_bowling_pin");
			Menu::Option("prop_boxing_glove_01");
			Menu::Option("prop_buck_spade_01");
			Menu::Option("prop_buck_spade_02");
			Menu::Option("prop_buck_spade_03");
			Menu::Option("prop_buck_spade_04");
			Menu::Option("prop_buck_spade_05");
			Menu::Option("prop_buck_spade_06");
			Menu::Option("prop_buck_spade_07");
			Menu::Option("prop_buck_spade_08");
			Menu::Option("prop_buck_spade_09");
			Menu::Option("prop_buck_spade_10");
			Menu::Option("prop_bumper_car_01");
			Menu::Option("prop_can_canoe");
			Menu::Option("prop_cap_01");
			Menu::Option("prop_cap_01b");
			Menu::Option("prop_cap_row_01");
			Menu::Option("prop_cap_row_01b");
			Menu::Option("prop_cap_row_02");
			Menu::Option("prop_cap_row_02b");
			Menu::Option("prop_clothes_rail_02");
			Menu::Option("prop_clothes_rail_03");
			Menu::Option("prop_clothes_rail_2b");
			Menu::Option("prop_clothes_tub_01");
			Menu::Option("prop_cs_beachtowel_01");
			Menu::Option("prop_cup_saucer_01");
			Menu::Option("prop_curl_bar_01");
			Menu::Option("prop_dart_1");
			Menu::Option("prop_dart_2");
			Menu::Option("prop_dart_bd_01");
			Menu::Option("prop_dart_bd_cab_01");
			Menu::Option("prop_display_unit_01");
			Menu::Option("prop_display_unit_02");
			Menu::Option("prop_disp_cabinet_002");
			Menu::Option("prop_disp_cabinet_01");
			Menu::Option("prop_dolly_01");
			Menu::Option("prop_dolly_02");
			Menu::Option("prop_dress_disp_01");
			Menu::Option("prop_dress_disp_02");
			Menu::Option("prop_dress_disp_03");
			Menu::Option("prop_dress_disp_04");
			Menu::Option("prop_drug_burner");
			Menu::Option("prop_exer_bike_01");
			Menu::Option("prop_ferris_car_01");
			Menu::Option("prop_ferris_car_01_lod1");
			Menu::Option("prop_film_cam_01");
			Menu::Option("prop_flipchair_01");
			Menu::Option("prop_food_van_01");
			Menu::Option("prop_food_van_02");
			Menu::Option("prop_freeweight_01");
			Menu::Option("prop_freeweight_02");
			Menu::Option("prop_front_seat_01");
			Menu::Option("prop_front_seat_02");
			Menu::Option("prop_front_seat_03");
			Menu::Option("prop_front_seat_04");
			Menu::Option("prop_front_seat_05");
			Menu::Option("prop_front_seat_06");
			Menu::Option("prop_front_seat_07");
			Menu::Option("prop_front_seat_row_01");
			Menu::Option("prop_ftowel_01");
			Menu::Option("prop_ftowel_07");
			Menu::Option("prop_ftowel_08");
			Menu::Option("prop_ftowel_10");
			Menu::Option("prop_game_clock_01");
			Menu::Option("prop_game_clock_02");
			Menu::Option("prop_golf_bag_01");
			Menu::Option("prop_golf_bag_01b");
			Menu::Option("prop_golf_bag_01c");
			Menu::Option("prop_golf_ball");
			Menu::Option("prop_golf_ball_p2");
			Menu::Option("prop_golf_ball_p3");
			Menu::Option("prop_golf_ball_p4");
			Menu::Option("prop_golf_ball_tee");
			Menu::Option("prop_golf_driver");
			Menu::Option("prop_golf_iron_01");
			Menu::Option("prop_golf_marker_01");
			Menu::Option("prop_golf_pitcher_01");
			Menu::Option("prop_golf_putter_01");
			Menu::Option("prop_golf_tee");
			Menu::Option("prop_golf_wood_01");
			Menu::Option("prop_hat_box_01");
			Menu::Option("prop_hat_box_02");
			Menu::Option("prop_hat_box_03");
			Menu::Option("prop_hat_box_04");
			Menu::Option("prop_hat_box_05");
			Menu::Option("prop_hat_box_06");
			Menu::Option("prop_henna_disp_01");
			Menu::Option("prop_henna_disp_02");
			Menu::Option("prop_henna_disp_03");
			Menu::Option("prop_hwbowl_pseat_6x1");
			Menu::Option("prop_hwbowl_seat_01");
			Menu::Option("prop_hwbowl_seat_02");
			Menu::Option("prop_hwbowl_seat_03");
			Menu::Option("prop_hwbowl_seat_03b");
			Menu::Option("prop_hwbowl_seat_6x6");
			Menu::Option("prop_hydro_platform_01");
			Menu::Option("prop_inflatearch_01");
			Menu::Option("prop_inflategate_01");
			Menu::Option("prop_jeans_01");
			Menu::Option("prop_kayak_01");
			Menu::Option("prop_kayak_01b");
			Menu::Option("prop_kino_light_01");
			Menu::Option("prop_kino_light_03");
			Menu::Option("prop_ld_hat_01");
			Menu::Option("prop_ld_jeans_01");
			Menu::Option("prop_ld_jeans_02");
			Menu::Option("prop_ld_shirt_01");
			Menu::Option("prop_ld_shoe_01");
			Menu::Option("prop_ld_shoe_02");
			Menu::Option("prop_ld_tshirt_01");
			Menu::Option("prop_ld_tshirt_02");
			Menu::Option("prop_life_ring_02");
			Menu::Option("prop_makeup_trail_01");
			Menu::Option("prop_makeup_trail_02");
			Menu::Option("prop_mat_box");
			Menu::Option("prop_movie_rack");
			Menu::Option("prop_muscle_bench_01");
			Menu::Option("prop_muscle_bench_02");
			Menu::Option("prop_muscle_bench_03");
			Menu::Option("prop_muscle_bench_04");
			Menu::Option("prop_muscle_bench_05");
			Menu::Option("prop_muscle_bench_06");
			Menu::Option("prop_offroad_bale01");
			Menu::Option("prop_offroad_bale02_l1_frag_");
			Menu::Option("prop_offroad_barrel01");
			Menu::Option("prop_offroad_tyres01");
			Menu::Option("prop_plate_stand_01");
			Menu::Option("prop_poolball_1");
			Menu::Option("prop_poolball_10");
			Menu::Option("prop_poolball_11");
			Menu::Option("prop_poolball_12");
			Menu::Option("prop_poolball_13");
			Menu::Option("prop_poolball_14");
			Menu::Option("prop_poolball_15");
			Menu::Option("prop_poolball_2");
			Menu::Option("prop_poolball_3");
			Menu::Option("prop_poolball_4");
			Menu::Option("prop_poolball_5");
			Menu::Option("prop_poolball_6");
			Menu::Option("prop_poolball_7");
			Menu::Option("prop_poolball_8");
			Menu::Option("prop_poolball_9");
			Menu::Option("prop_poolball_cue");
			Menu::Option("prop_porn_mag_01");
			Menu::Option("prop_porn_mag_02");
			Menu::Option("prop_porn_mag_03");
			Menu::Option("prop_porn_mag_04");
			Menu::Option("prop_postcard_rack");
			Menu::Option("prop_pris_bars_01");
			Menu::Option("prop_pris_bench_01");
			Menu::Option("prop_prop_tree_01");
			Menu::Option("prop_prop_tree_02");
			Menu::Option("prop_punch_bag_l");
			Menu::Option("prop_roller_car_01");
			Menu::Option("prop_roller_car_02");
			Menu::Option("prop_scrim_01");
			Menu::Option("prop_set_generator_01");
			Menu::Option("prop_sglasses_stand_01");
			Menu::Option("prop_sglasses_stand_02");
			Menu::Option("prop_sglasses_stand_02b");
			Menu::Option("prop_sglasses_stand_03");
			Menu::Option("prop_sglasss_1b_lod");
			Menu::Option("prop_sglasss_1_lod");
			Menu::Option("prop_shop_front_door_l");
			Menu::Option("prop_shop_front_door_r");
			Menu::Option("prop_skate_flatramp");
			Menu::Option("prop_skate_funbox");
			Menu::Option("prop_skate_halfpipe");
			Menu::Option("prop_skate_kickers");
			Menu::Option("prop_skate_quartpipe");
			Menu::Option("prop_skate_rail");
			Menu::Option("prop_skate_spiner");
			Menu::Option("prop_skip_rope_01");
			Menu::Option("prop_slacks_01");
			Menu::Option("prop_slacks_02");
			Menu::Option("prop_speedball_01");
			Menu::Option("prop_sports_clock_01");
			Menu::Option("prop_studio_light_02");
			Menu::Option("prop_studio_light_03");
			Menu::Option("prop_suitcase_01");
			Menu::Option("prop_suitcase_01b");
			Menu::Option("prop_suitcase_01c");
			Menu::Option("prop_suitcase_01d");
			Menu::Option("prop_suitcase_02");
			Menu::Option("prop_suitcase_03");
			Menu::Option("prop_suitcase_03b");
			Menu::Option("prop_surf_board_ldn_01");
			Menu::Option("prop_surf_board_ldn_02");
			Menu::Option("prop_surf_board_ldn_03");
			Menu::Option("prop_surf_board_ldn_04");
			Menu::Option("prop_table_tennis");
			Menu::Option("prop_tennis_ball_lobber");
			Menu::Option("prop_tint_towel");
			Menu::Option("prop_tint_towels_01");
			Menu::Option("prop_tint_towels_01b");
			Menu::Option("prop_towel2_01");
			Menu::Option("prop_towel2_02");
			Menu::Option("prop_towel_shelf_01");
			Menu::Option("prop_tri_pod");
			Menu::Option("prop_tri_pod_lod");
			Menu::Option("prop_tshirt_box_02");
			Menu::Option("prop_tshirt_shelf_1");
			Menu::Option("prop_tshirt_shelf_2");
			Menu::Option("prop_tshirt_shelf_2a");
			Menu::Option("prop_tshirt_shelf_2b");
			Menu::Option("prop_tshirt_shelf_2c");
			Menu::Option("prop_tshirt_stand_01");
			Menu::Option("prop_tshirt_stand_01b");
			Menu::Option("prop_tshirt_stand_02");
			Menu::Option("prop_tshirt_stand_04");
			Menu::Option("prop_t_shirt_row_01");
			Menu::Option("prop_t_shirt_row_02");
			Menu::Option("prop_t_shirt_row_02b");
			Menu::Option("prop_t_shirt_row_03");
			Menu::Option("prop_t_shirt_row_04");
			Menu::Option("prop_t_shirt_row_05l");
			Menu::Option("prop_t_shirt_row_05r");
			Menu::Option("prop_venice_board_01");
			Menu::Option("prop_venice_board_02");
			Menu::Option("prop_venice_board_03");
			Menu::Option("prop_venice_counter_01");
			Menu::Option("prop_venice_counter_02");
			Menu::Option("prop_venice_counter_03");
			Menu::Option("prop_venice_counter_04");
			Menu::Option("prop_venice_shop_front_01");
			Menu::Option("prop_venice_sign_09");
			Menu::Option("prop_venice_sign_10");
			Menu::Option("prop_venice_sign_11");
			Menu::Option("prop_venice_sign_12");
			Menu::Option("prop_venice_sign_14");
			Menu::Option("prop_venice_sign_15");
			Menu::Option("prop_venice_sign_16");
			Menu::Option("prop_venice_sign_17");
			Menu::Option("prop_venice_sign_18");
			Menu::Option("prop_ven_market_stool");
			Menu::Option("prop_ven_market_table1");
			Menu::Option("prop_ven_shop_1_counter");
			Menu::Option("prop_v_15_cars_clock");
			Menu::Option("prop_v_5_bclock");
			Menu::Option("prop_weight_10k");
			Menu::Option("prop_weight_15k");
			Menu::Option("prop_weight_1_5k");
			Menu::Option("prop_weight_20k");
			Menu::Option("prop_weight_2_5k");
			Menu::Option("prop_weight_5k");
			Menu::Option("prop_weight_rack_01");
			Menu::Option("prop_weight_rack_02");
			Menu::Option("p_film_set_static_01");
			Menu::Option("prop_bath_dirt_01");
			Menu::Option("prop_broom_unit_01");
			Menu::Option("prop_handdry_01");
			Menu::Option("prop_handdry_02");
			Menu::Option("prop_shower_01");
			Menu::Option("prop_shower_rack_01");
			Menu::Option("prop_sink_01");
			Menu::Option("prop_sink_02");
			Menu::Option("prop_sink_03");
			Menu::Option("prop_sink_04");
			Menu::Option("prop_sink_05");
			Menu::Option("prop_sink_06");
			Menu::Option("prop_soap_disp_01");
			Menu::Option("prop_soap_disp_02");
			Menu::Option("prop_sponge_01");
			Menu::Option("prop_toilet_01");
			Menu::Option("prop_toilet_02");
			Menu::Option("prop_toilet_03");
			Menu::Option("prop_toilet_brush_01");
			Menu::Option("prop_toilet_cube_01");
			Menu::Option("prop_toilet_cube_02");
			Menu::Option("prop_toilet_roll_01");
			Menu::Option("prop_toilet_roll_02");
			Menu::Option("prop_toilet_roll_03");
			Menu::Option("prop_toilet_roll_04");
			Menu::Option("prop_toilet_roll_05");
			Menu::Option("prop_toilet_shamp_01");
			Menu::Option("prop_toilet_shamp_02");
			Menu::Option("prop_toilet_soap_01");
			Menu::Option("prop_toilet_soap_02");
			Menu::Option("prop_toilet_soap_03");
			Menu::Option("prop_toilet_soap_04");
			Menu::Option("prop_toothbrush_01");
			Menu::Option("prop_toothb_cup_01");
			Menu::Option("prop_toothpaste_01");
			Menu::Option("prop_towel_01");
			Menu::Option("prop_towel_rail_01");
			Menu::Option("prop_towel_rail_02");
			Menu::Option("prop_towel_small_01");
			Menu::Option("prop_w_fountain_01");
			Menu::Option("prop_amp_01");
			Menu::Option("prop_cctv_02_sm");
			Menu::Option("prop_cctv_cont_01");
			Menu::Option("prop_cctv_cont_03");
			Menu::Option("prop_cctv_cont_04");
			Menu::Option("prop_cctv_cont_05");
			Menu::Option("prop_cctv_cont_06");
			Menu::Option("prop_cctv_unit_01");
			Menu::Option("prop_cctv_unit_02");
			Menu::Option("prop_cctv_unit_05");
			Menu::Option("prop_console_01");
			Menu::Option("prop_cs_dvd_player");
			Menu::Option("prop_cs_keyboard_01");
			Menu::Option("prop_cs_mouse_01");
			Menu::Option("prop_cs_tv_stand");
			Menu::Option("prop_dj_deck_01");
			Menu::Option("prop_dj_deck_02");
			Menu::Option("prop_flatscreen_overlay");
			Menu::Option("prop_ghettoblast_02");
			Menu::Option("prop_hifi_01");
			Menu::Option("prop_keyboard_01a");
			Menu::Option("prop_keyboard_01b");
			Menu::Option("prop_laptop_02_closed");
			Menu::Option("prop_laptop_jimmy");
			Menu::Option("prop_laptop_lester");
			Menu::Option("prop_laptop_lester2");
			Menu::Option("prop_michaels_credit_tv");
			Menu::Option("prop_monitor_01c");
			Menu::Option("prop_monitor_01d");
			Menu::Option("prop_monitor_02");
			Menu::Option("prop_monitor_03b");
			Menu::Option("prop_mouse_01");
			Menu::Option("prop_mouse_01a");
			Menu::Option("prop_mouse_01b");
			Menu::Option("prop_mouse_02");
			Menu::Option("prop_pc_01a");
			Menu::Option("prop_pc_02a");
			Menu::Option("prop_portable_hifi_01");
			Menu::Option("prop_projector_overlay");
			Menu::Option("prop_speaker_01");
			Menu::Option("prop_speaker_02");
			Menu::Option("prop_speaker_03");
			Menu::Option("prop_speaker_05");
			Menu::Option("prop_speaker_06");
			Menu::Option("prop_speaker_07");
			Menu::Option("prop_speaker_08");
			Menu::Option("prop_till_01_dam");
			Menu::Option("prop_till_02");
			Menu::Option("prop_till_03");
			Menu::Option("prop_trailer_monitor_01");
			Menu::Option("prop_trev_tv_01");
			Menu::Option("prop_tt_screenstatic");
			Menu::Option("prop_tv_02");
			Menu::Option("prop_tv_03_overlay");
			Menu::Option("prop_tv_04");
			Menu::Option("prop_tv_05");
			Menu::Option("prop_tv_06");
			Menu::Option("prop_tv_07");
			Menu::Option("prop_tv_cabinet_03");
			Menu::Option("prop_tv_cabinet_04");
			Menu::Option("prop_tv_cabinet_05");
			Menu::Option("prop_tv_flat_01");
			Menu::Option("prop_tv_flat_01_screen");
			Menu::Option("prop_tv_flat_02b");
			Menu::Option("prop_tv_flat_03");
			Menu::Option("prop_tv_flat_03b");
			Menu::Option("prop_tv_flat_michael");
			Menu::Option("prop_vcr_01");
			Menu::Option("prop_white_keyboard");
			Menu::Option("prop_bbq_2");
			Menu::Option("prop_bbq_3");
			Menu::Option("prop_beware_dog_sign");
			Menu::Option("prop_forsalejr2");
			Menu::Option("prop_forsalejr3");
			Menu::Option("prop_forsalejr4");
			Menu::Option("prop_fountain1");
			Menu::Option("prop_fountain2");
			Menu::Option("prop_garden_dreamcatch_01");
			Menu::Option("prop_garden_edging_01");
			Menu::Option("prop_garden_edging_02");
			Menu::Option("prop_garden_zapper_01");
			Menu::Option("prop_gardnght_01");
			Menu::Option("prop_gazebo_03");
			Menu::Option("prop_glf_roller");
			Menu::Option("prop_glf_spreader");
			Menu::Option("prop_gravestones_01a");
			Menu::Option("prop_gravestones_02a");
			Menu::Option("prop_gravestones_03a");
			Menu::Option("prop_gravestones_04a");
			Menu::Option("prop_gravestones_05a");
			Menu::Option("prop_gravestones_06a");
			Menu::Option("prop_gravestones_07a");
			Menu::Option("prop_gravestones_08a");
			Menu::Option("prop_gravestones_09a");
			Menu::Option("prop_gravestones_10a");
			Menu::Option("prop_gravetomb_01a");
			Menu::Option("prop_gravetomb_02a");
			Menu::Option("prop_hedge_trimmer_01");
			Menu::Option("prop_hose_1");
			Menu::Option("prop_hose_2");
			Menu::Option("prop_hose_3");
			Menu::Option("prop_hottub2");
			Menu::Option("prop_lawnmower_01");
			Menu::Option("prop_leaf_blower_01");
			Menu::Option("prop_letterbox_04");
			Menu::Option("prop_outdoor_fan_01");
			Menu::Option("prop_owl_totem_01");
			Menu::Option("prop_poolskimmer");
			Menu::Option("prop_prlg_gravestone_05a_l1");
			Menu::Option("prop_prlg_gravestone_06a");
			Menu::Option("prop_shrub_rake");
			Menu::Option("prop_sign_mallet");
			Menu::Option("prop_spray_backpack_01");
			Menu::Option("prop_sprink_crop_01");
			Menu::Option("prop_sprink_golf_01");
			Menu::Option("prop_sprink_park_01");
			Menu::Option("prop_stickbfly");
			Menu::Option("prop_stickhbird");
			Menu::Option("prop_wateringcan");
			Menu::Option("prop_windmill2");
			Menu::Option("test_prop_gravestones_04a");
			Menu::Option("test_prop_gravestones_05a");
			Menu::Option("test_prop_gravestones_07a");
			Menu::Option("test_prop_gravestones_08a");
			Menu::Option("test_prop_gravestones_09a");
			Menu::Option("test_prop_gravetomb_01a");
			Menu::Option("test_prop_gravetomb_02a");
			Menu::Option("prop_breadbin_01");
			Menu::Option("prop_cleaver");
			Menu::Option("prop_cooker_03");
			Menu::Option("prop_copper_pan");
			Menu::Option("prop_fridge_01");
			Menu::Option("prop_fridge_03");
			Menu::Option("prop_ind_washer_02");
			Menu::Option("prop_kettle");
			Menu::Option("prop_kettle_01");
			Menu::Option("prop_kitch_juicer");
			Menu::Option("prop_kitch_pot_fry");
			Menu::Option("prop_kitch_pot_huge");
			Menu::Option("prop_kitch_pot_lrg");
			Menu::Option("prop_kitch_pot_lrg2");
			Menu::Option("prop_kitch_pot_med");
			Menu::Option("prop_kitch_pot_sm");
			Menu::Option("prop_knife");
			Menu::Option("prop_knife_stand");
			Menu::Option("prop_ladel");
			Menu::Option("prop_metalfoodjar_01");
			Menu::Option("prop_micro_01");
			Menu::Option("prop_micro_02");
			Menu::Option("prop_micro_cs_01");
			Menu::Option("prop_micro_cs_01_door");
			Menu::Option("prop_plate_04");
			Menu::Option("prop_plate_warmer");
			Menu::Option("prop_pot_01");
			Menu::Option("prop_pot_02");
			Menu::Option("prop_pot_03");
			Menu::Option("prop_pot_04");
			Menu::Option("prop_pot_05");
			Menu::Option("prop_pot_06");
			Menu::Option("prop_pot_rack");
			Menu::Option("prop_steam_basket_01");
			Menu::Option("prop_steam_basket_02");
			Menu::Option("prop_tea_urn");
			Menu::Option("prop_toaster_01");
			Menu::Option("prop_toaster_02");
			Menu::Option("prop_utensil");
			Menu::Option("prop_washer_01");
			Menu::Option("prop_washer_02");
			Menu::Option("prop_washer_03");
			Menu::Option("prop_washing_basket_01");
			Menu::Option("prop_whisk");
			Menu::Option("prop_wok");
			Menu::Option("prop_armchair_01");
			Menu::Option("prop_couch_01");
			Menu::Option("prop_couch_03");
			Menu::Option("prop_couch_04");
			Menu::Option("prop_couch_lg_02");
			Menu::Option("prop_couch_lg_05");
			Menu::Option("prop_couch_lg_06");
			Menu::Option("prop_couch_lg_07");
			Menu::Option("prop_couch_lg_08");
			Menu::Option("prop_couch_sm1_07");
			Menu::Option("prop_couch_sm2_07");
			Menu::Option("prop_couch_sm_02");
			Menu::Option("prop_couch_sm_05");
			Menu::Option("prop_couch_sm_06");
			Menu::Option("prop_couch_sm_07");
			Menu::Option("prop_yaught_chair_01");
			Menu::Option("prop_yaught_sofa_01");
			Menu::Option("prop_bin_04a");
			Menu::Option("prop_bin_10a");
			Menu::Option("prop_bin_10b");
			Menu::Option("prop_bin_11a");
			Menu::Option("prop_bin_11b");
			Menu::Option("prop_bin_12a");
			Menu::Option("prop_bin_13a");
			Menu::Option("prop_bin_14a");
			Menu::Option("prop_bin_14b");
			Menu::Option("prop_bin_beach_01d");
			Menu::Option("prop_bin_delpiero");
			Menu::Option("prop_bin_delpiero_b");
			Menu::Option("prop_dumpster_3a");
			Menu::Option("prop_dumpster_3step");
			Menu::Option("prop_dumpster_4a");
			Menu::Option("prop_dumpster_4b");
			Menu::Option("prop_recyclebin_02a");
			Menu::Option("prop_recyclebin_02b");
			Menu::Option("prop_recyclebin_02_c");
			Menu::Option("prop_recyclebin_02_d");
			Menu::Option("prop_recyclebin_03_a");
			Menu::Option("prop_recyclebin_04_a");
			Menu::Option("prop_recyclebin_04_b");
			Menu::Option("prop_recyclebin_05_a");
			Menu::Option("prop_skip_01a");
			Menu::Option("prop_skip_02a");
			Menu::Option("prop_skip_03");
			Menu::Option("prop_skip_04");
			Menu::Option("prop_skip_05a");
			Menu::Option("prop_skip_05b");
			Menu::Option("prop_skip_06a");
			Menu::Option("prop_skip_08a");
			Menu::Option("prop_skip_08b");
			Menu::Option("prop_skip_10a");
			Menu::Option("prop_bandsaw_01");
			Menu::Option("prop_barier_conc_01b");
			Menu::Option("prop_barier_conc_01c");
			Menu::Option("prop_barier_conc_02b");
			Menu::Option("prop_barier_conc_02c");
			Menu::Option("prop_barier_conc_03a");
			Menu::Option("prop_barier_conc_04a");
			Menu::Option("prop_barier_conc_05a");
			Menu::Option("prop_barier_conc_05b");
			Menu::Option("prop_barriercrash_03");
			Menu::Option("prop_barriercrash_04");
			Menu::Option("prop_barrier_wat_01a");
			Menu::Option("prop_barrier_wat_03b");
			Menu::Option("prop_barrier_work01c");
			Menu::Option("prop_cablespool_01a");
			Menu::Option("prop_cablespool_01b");
			Menu::Option("prop_cablespool_02");
			Menu::Option("prop_cablespool_03");
			Menu::Option("prop_cablespool_04");
			Menu::Option("prop_cablespool_05");
			Menu::Option("prop_cablespool_06");
			Menu::Option("prop_cementmixer_01a");
			Menu::Option("prop_cementmixer_02a");
			Menu::Option("prop_conc_sacks_02a");
			Menu::Option("prop_conschute");
			Menu::Option("prop_consign_01c");
			Menu::Option("prop_consign_02a");
			Menu::Option("prop_conslift_base");
			Menu::Option("prop_conslift_brace");
			Menu::Option("prop_conslift_cage");
			Menu::Option("prop_conslift_door");
			Menu::Option("prop_conslift_lift");
			Menu::Option("prop_conslift_rail");
			Menu::Option("prop_conslift_rail2");
			Menu::Option("prop_conslift_steps");
			Menu::Option("prop_cons_crate");
			Menu::Option("prop_cons_plank");
			Menu::Option("prop_cons_ply01");
			Menu::Option("prop_cons_ply02");
			Menu::Option("prop_crosssaw_01");
			Menu::Option("prop_diggerbkt_01");
			Menu::Option("prop_drywallpile_01");
			Menu::Option("prop_drywallpile_02");
			Menu::Option("prop_ducktape_01");
			Menu::Option("prop_etricmotor_01");
			Menu::Option("prop_generator_02a");
			Menu::Option("prop_generator_03a");
			Menu::Option("prop_generator_04");
			Menu::Option("prop_girder_01a");
			Menu::Option("prop_logpile_05");
			Menu::Option("prop_logpile_06");
			Menu::Option("prop_logpile_06b");
			Menu::Option("prop_logpile_07");
			Menu::Option("prop_logpile_07b");
			Menu::Option("prop_log_01");
			Menu::Option("prop_log_02");
			Menu::Option("prop_log_03");
			Menu::Option("prop_medstation_02");
			Menu::Option("prop_medstation_03");
			Menu::Option("prop_medstation_04");
			Menu::Option("prop_metal_plates01");
			Menu::Option("prop_metal_plates02");
			Menu::Option("prop_oiltub_01");
			Menu::Option("prop_oiltub_02");
			Menu::Option("prop_oiltub_03");
			Menu::Option("prop_oiltub_05");
			Menu::Option("prop_oiltub_06");
			Menu::Option("prop_paints_can01");
			Menu::Option("prop_paints_can02");
			Menu::Option("prop_paints_can03");
			Menu::Option("prop_paints_can04");
			Menu::Option("prop_paints_can05");
			Menu::Option("prop_paints_can06");
			Menu::Option("prop_paints_can07");
			Menu::Option("prop_paint_brush01");
			Menu::Option("prop_paint_brush02");
			Menu::Option("prop_paint_brush03");
			Menu::Option("prop_paint_brush04");
			Menu::Option("prop_paint_brush05");
			Menu::Option("prop_paint_roller");
			Menu::Option("prop_paint_spray01a");
			Menu::Option("prop_paint_spray01b");
			Menu::Option("prop_paint_stepl01");
			Menu::Option("prop_paint_stepl01b");
			Menu::Option("prop_paint_stepl02");
			Menu::Option("prop_paint_tray");
			Menu::Option("prop_paint_wpaper01");
			Menu::Option("prop_partsbox_01");
			Menu::Option("prop_pile_dirt_01");
			Menu::Option("prop_pile_dirt_02");
			Menu::Option("prop_pile_dirt_03");
			Menu::Option("prop_pile_dirt_04");
			Menu::Option("prop_pile_dirt_06");
			Menu::Option("prop_pile_dirt_07");
			Menu::Option("prop_pipes_01a");
			Menu::Option("prop_pipes_01b");
			Menu::Option("prop_pipes_03b");
			Menu::Option("prop_pipes_04a");
			Menu::Option("prop_pipes_05a");
			Menu::Option("prop_pipes_conc_01");
			Menu::Option("prop_pipes_conc_02");
			Menu::Option("prop_planer_01");
			Menu::Option("prop_plas_barier_01a");
			Menu::Option("prop_plywoodpile_01a");
			Menu::Option("prop_plywoodpile_01b");
			Menu::Option("prop_rebar_pile01");
			Menu::Option("prop_roadcone01a");
			Menu::Option("prop_roadcone01b");
			Menu::Option("prop_roadcone01c");
			Menu::Option("prop_roadcone02a");
			Menu::Option("prop_roadcone02b");
			Menu::Option("prop_roadcone02c");
			Menu::Option("prop_roadheader_01");
			Menu::Option("prop_scafold_01a");
			Menu::Option("prop_scafold_01c");
			Menu::Option("prop_scafold_01f");
			Menu::Option("prop_scafold_02a");
			Menu::Option("prop_scafold_02c");
			Menu::Option("prop_scafold_03a");
			Menu::Option("prop_scafold_03b");
			Menu::Option("prop_scafold_03c");
			Menu::Option("prop_scafold_03f");
			Menu::Option("prop_scafold_04a");
			Menu::Option("prop_scafold_05a");
			Menu::Option("prop_scafold_06a");
			Menu::Option("prop_scafold_06b");
			Menu::Option("prop_scafold_06c");
			Menu::Option("prop_scafold_07a");
			Menu::Option("prop_scafold_08a");
			Menu::Option("prop_scafold_09a");
			Menu::Option("prop_scafold_frame1a");
			Menu::Option("prop_scafold_frame1b");
			Menu::Option("prop_scafold_frame1c");
			Menu::Option("prop_scafold_frame1f");
			Menu::Option("prop_scafold_frame2a");
			Menu::Option("prop_scafold_frame2b");
			Menu::Option("prop_scafold_frame2c");
			Menu::Option("prop_scafold_frame3a");
			Menu::Option("prop_scafold_frame3c");
			Menu::Option("prop_scafold_rail_01");
			Menu::Option("prop_scafold_rail_02");
			Menu::Option("prop_scafold_rail_03");
			Menu::Option("prop_scafold_xbrace");
			Menu::Option("prop_shuttering01");
			Menu::Option("prop_shuttering02");
			Menu::Option("prop_shuttering03");
			Menu::Option("prop_shuttering04");
			Menu::Option("prop_spraygun_01");
			Menu::Option("prop_staticmixer_01");
			Menu::Option("prop_steps_big_01");
			Menu::Option("prop_tablesaw_01");
			Menu::Option("prop_tool_adjspanner");
			Menu::Option("prop_tool_bench01");
			Menu::Option("prop_tool_bluepnt");
			Menu::Option("prop_tool_box_01");
			Menu::Option("prop_tool_box_02");
			Menu::Option("prop_tool_box_03");
			Menu::Option("prop_tool_box_04");
			Menu::Option("prop_tool_box_05");
			Menu::Option("prop_tool_box_06");
			Menu::Option("prop_tool_box_07");
			Menu::Option("prop_tool_broom");
			Menu::Option("prop_tool_broom2");
			Menu::Option("prop_tool_broom2_l1");
			Menu::Option("prop_tool_cable01");
			Menu::Option("prop_tool_cable02");
			Menu::Option("prop_tool_consaw");
			Menu::Option("prop_tool_drill");
			Menu::Option("prop_tool_fireaxe");
			Menu::Option("prop_tool_hammer");
			Menu::Option("prop_tool_hardhat");
			Menu::Option("prop_tool_jackham");
			Menu::Option("prop_tool_mallet");
			Menu::Option("prop_tool_mopbucket");
			Menu::Option("prop_tool_nailgun");
			Menu::Option("prop_tool_pickaxe");
			Menu::Option("prop_tool_pliers");
			Menu::Option("prop_tool_rake");
			Menu::Option("prop_tool_rake_l1");
			Menu::Option("prop_tool_sawhorse");
			Menu::Option("prop_tool_screwdvr01");
			Menu::Option("prop_tool_screwdvr02");
			Menu::Option("prop_tool_screwdvr03");
			Menu::Option("prop_tool_shovel");
			Menu::Option("prop_tool_shovel006");
			Menu::Option("prop_tool_shovel2");
			Menu::Option("prop_tool_shovel3");
			Menu::Option("prop_tool_shovel4");
			Menu::Option("prop_tool_shovel5");
			Menu::Option("prop_tool_sledgeham");
			Menu::Option("prop_tool_spanner01");
			Menu::Option("prop_tool_spanner02");
			Menu::Option("prop_tool_spanner03");
			Menu::Option("prop_tool_torch");
			Menu::Option("prop_tool_wrench");
			Menu::Option("prop_towercrane_01a");
			Menu::Option("prop_towercrane_02a");
			Menu::Option("prop_towercrane_02b");
			Menu::Option("prop_towercrane_02c");
			Menu::Option("prop_towercrane_02d");
			Menu::Option("prop_towercrane_02e");
			Menu::Option("prop_towercrane_02el");
			Menu::Option("prop_towercrane_02el2");
			Menu::Option("prop_tunnel_liner01");
			Menu::Option("prop_tunnel_liner02");
			Menu::Option("prop_tunnel_liner03");
			Menu::Option("prop_vertdrill_01");
			Menu::Option("prop_wheelbarrow01a");
			Menu::Option("prop_wheelbarrow02a");
			Menu::Option("prop_woodpile_02a");
			Menu::Option("prop_worklight_01a_l1");
			Menu::Option("prop_worklight_03a_l1");
			Menu::Option("prop_worklight_03b_l1");
			Menu::Option("prop_worklight_04a");
			Menu::Option("prop_worklight_04b_l1");
			Menu::Option("prop_worklight_04c_l1");
			Menu::Option("prop_worklight_04d_l1");
			Menu::Option("prop_workwall_01");
			Menu::Option("prop_workwall_02");
			Menu::Option("prop_armenian_gate");
			Menu::Option("prop_arm_gate_l");
			Menu::Option("prop_const_fence01a");
			Menu::Option("prop_const_fence01b");
			Menu::Option("prop_const_fence02a");
			Menu::Option("prop_const_fence02b");
			Menu::Option("prop_const_fence03b");
			Menu::Option("prop_facgate_01");
			Menu::Option("prop_facgate_01b");
			Menu::Option("prop_facgate_02pole");
			Menu::Option("prop_facgate_02_l");
			Menu::Option("prop_facgate_03post");
			Menu::Option("prop_facgate_03_l");
			Menu::Option("prop_facgate_03_ld_l");
			Menu::Option("prop_facgate_03_ld_r");
			Menu::Option("prop_facgate_03_r");
			Menu::Option("prop_facgate_04_l");
			Menu::Option("prop_facgate_04_r");
			Menu::Option("prop_facgate_05_r");
			Menu::Option("prop_facgate_05_r_dam_l1");
			Menu::Option("prop_facgate_05_r_l1");
			Menu::Option("prop_facgate_06_l");
			Menu::Option("prop_facgate_06_r");
			Menu::Option("prop_facgate_07");
			Menu::Option("prop_facgate_07b");
			Menu::Option("prop_facgate_08");
			Menu::Option("prop_facgate_08_frame");
			Menu::Option("prop_facgate_08_ld2");
			Menu::Option("prop_facgate_id1_27");
			Menu::Option("prop_fence_log_01");
			Menu::Option("prop_fence_log_02");
			Menu::Option("prop_fncconstruc_02a");
			Menu::Option("prop_fnclog_01a");
			Menu::Option("prop_fnclog_01b");
			Menu::Option("prop_fncpeir_03a");
			Menu::Option("prop_fncres_02a");
			Menu::Option("prop_fncres_02b");
			Menu::Option("prop_fncres_02c");
			Menu::Option("prop_fncres_02d");
			Menu::Option("prop_fncres_02_gate1");
			Menu::Option("prop_fncres_03gate1");
			Menu::Option("prop_fncres_05c_l1");
			Menu::Option("prop_fncsec_01a");
			Menu::Option("prop_fncsec_01b");
			Menu::Option("prop_fncsec_01crnr");
			Menu::Option("prop_fncsec_01gate");
			Menu::Option("prop_fncsec_01pole");
			Menu::Option("prop_fncsec_02a");
			Menu::Option("prop_fncsec_02pole");
			Menu::Option("prop_fncwood_07gate1");
			Menu::Option("prop_fncwood_11a_l1");
			Menu::Option("prop_fncwood_16a");
			Menu::Option("prop_fncwood_16b");
			Menu::Option("prop_fncwood_16c");
			Menu::Option("prop_fncwood_18a");
			Menu::Option("prop_gatecom_02");
			Menu::Option("prop_gate_airport_01");
			Menu::Option("prop_gate_cult_01_l");
			Menu::Option("prop_gate_cult_01_r");
			Menu::Option("prop_gate_docks_ld");
			Menu::Option("prop_gate_farm_01a");
			Menu::Option("prop_gate_farm_post");
			Menu::Option("prop_gate_frame_01");
			Menu::Option("prop_gate_frame_02");
			Menu::Option("prop_gate_frame_04");
			Menu::Option("prop_gate_frame_05");
			Menu::Option("prop_gate_frame_06");
			Menu::Option("prop_gate_military_01");
			Menu::Option("prop_gate_prison_01");
			Menu::Option("prop_gate_tep_01_l");
			Menu::Option("prop_gate_tep_01_r");
			Menu::Option("prop_ld_balcfnc_01a");
			Menu::Option("prop_ld_balcfnc_02a");
			Menu::Option("prop_ld_balcfnc_02c");
			Menu::Option("prop_lrggate_01c_l");
			Menu::Option("prop_lrggate_01c_r");
			Menu::Option("prop_lrggate_01_l");
			Menu::Option("prop_lrggate_01_pst");
			Menu::Option("prop_lrggate_01_r");
			Menu::Option("prop_lrggate_02_ld");
			Menu::Option("prop_lrggate_03a");
			Menu::Option("prop_lrggate_03b");
			Menu::Option("prop_lrggate_03b_ld");
			Menu::Option("prop_lrggate_04a");
			Menu::Option("prop_lrggate_05a");
			Menu::Option("prop_lrggate_06a");
			Menu::Option("prop_fnccorgm_05a");
			Menu::Option("prop_fnccorgm_05b");
			Menu::Option("prop_fnccorgm_06a");
			Menu::Option("prop_fnccorgm_06b");
			Menu::Option("prop_fnclink_01gate1");
			Menu::Option("prop_fnclink_02gate1");
			Menu::Option("prop_fnclink_02gate2");
			Menu::Option("prop_fnclink_02gate5");
			Menu::Option("prop_fnclink_02gate6_l");
			Menu::Option("prop_fnclink_02gate6_r");
			Menu::Option("prop_fnclink_02gate7");
			Menu::Option("prop_fnclink_03gate1");
			Menu::Option("prop_fnclink_03gate2");
			Menu::Option("prop_fnclink_03gate4");
			Menu::Option("prop_fnclink_03gate5");
			Menu::Option("prop_fnclink_04gate1");
			Menu::Option("prop_fnclink_04h_l2");
			Menu::Option("prop_fnclink_06gate2");
			Menu::Option("prop_fnclink_06gate3");
			Menu::Option("prop_fnclink_06gatepost");
			Menu::Option("prop_fnclink_07gate1");
			Menu::Option("prop_fnclink_07gate2");
			Menu::Option("prop_fnclink_07gate3");
			Menu::Option("prop_fnclink_09gate1");
			Menu::Option("prop_fnclink_10a");
			Menu::Option("prop_fnclink_10b");
			Menu::Option("prop_fnclink_10c");
			Menu::Option("prop_fnclink_10d");
			Menu::Option("prop_fnclink_10e");
			Menu::Option("prop_fncsec_04a");
			Menu::Option("prop_gate_bridge_ld");
			Menu::Option("prop_hobo_stove_01");
			Menu::Option("prop_homeless_matress_01");
			Menu::Option("prop_homeless_matress_02");
			Menu::Option("prop_pizza_box_01");
			Menu::Option("prop_pizza_box_02");
			Menu::Option("prop_rub_bike_01");
			Menu::Option("prop_rub_bike_02");
			Menu::Option("prop_rub_bike_03");
			Menu::Option("prop_rub_busdoor_01");
			Menu::Option("prop_rub_busdoor_02");
			Menu::Option("prop_rub_buswreck_01");
			Menu::Option("prop_rub_buswreck_03");
			Menu::Option("prop_rub_buswreck_06");
			Menu::Option("prop_rub_cabinet");
			Menu::Option("prop_rub_cabinet01");
			Menu::Option("prop_rub_cabinet02");
			Menu::Option("prop_rub_cabinet03");
			Menu::Option("prop_rub_cage01a");
			Menu::Option("prop_rub_carpart_02");
			Menu::Option("prop_rub_carpart_03");
			Menu::Option("prop_rub_carpart_04");
			Menu::Option("prop_rub_chassis_01");
			Menu::Option("prop_rub_chassis_02");
			Menu::Option("prop_rub_chassis_03");
			Menu::Option("prop_rub_cont_01a");
			Menu::Option("prop_rub_cont_01b");
			Menu::Option("prop_rub_cont_01c");
			Menu::Option("prop_rub_flotsam_01");
			Menu::Option("prop_rub_flotsam_02");
			Menu::Option("prop_rub_flotsam_03");
			Menu::Option("prop_rub_frklft");
			Menu::Option("prop_rub_litter_01");
			Menu::Option("prop_rub_litter_02");
			Menu::Option("prop_rub_litter_03");
			Menu::Option("prop_rub_litter_03b");
			Menu::Option("prop_rub_litter_03c");
			Menu::Option("prop_rub_litter_04");
			Menu::Option("prop_rub_litter_04b");
			Menu::Option("prop_rub_litter_05");
			Menu::Option("prop_rub_litter_06");
			Menu::Option("prop_rub_litter_07");
			Menu::Option("prop_rub_litter_09");
			Menu::Option("prop_rub_litter_8");
			Menu::Option("prop_rub_matress_01");
			Menu::Option("prop_rub_matress_02");
			Menu::Option("prop_rub_matress_03");
			Menu::Option("prop_rub_matress_04");
			Menu::Option("prop_rub_monitor");
			Menu::Option("prop_rub_pile_01");
			Menu::Option("prop_rub_pile_02");
			Menu::Option("prop_rub_planks_01");
			Menu::Option("prop_rub_planks_02");
			Menu::Option("prop_rub_planks_03");
			Menu::Option("prop_rub_planks_04");
			Menu::Option("prop_rub_railwreck_1");
			Menu::Option("prop_rub_railwreck_2");
			Menu::Option("prop_rub_railwreck_3");
			Menu::Option("prop_rub_scrap_02");
			Menu::Option("prop_rub_scrap_03");
			Menu::Option("prop_rub_scrap_04");
			Menu::Option("prop_rub_scrap_05");
			Menu::Option("prop_rub_scrap_06");
			Menu::Option("prop_rub_scrap_07");
			Menu::Option("prop_rub_stool");
			Menu::Option("prop_rub_sunktyre");
			Menu::Option("prop_rub_t34");
			Menu::Option("prop_rub_trainers_01");
			Menu::Option("prop_rub_trolley01a");
			Menu::Option("prop_rub_trolley02a");
			Menu::Option("prop_rub_trolley03a");
			Menu::Option("prop_rub_trukwreck_1");
			Menu::Option("prop_rub_trukwreck_2");
			Menu::Option("prop_rub_tyre_01");
			Menu::Option("prop_rub_tyre_02");
			Menu::Option("prop_rub_tyre_03");
			Menu::Option("prop_rub_tyre_dam1");
			Menu::Option("prop_rub_tyre_dam2");
			Menu::Option("prop_rub_tyre_dam3");
			Menu::Option("prop_rub_washer_01");
			Menu::Option("prop_rub_wheel_01");
			Menu::Option("prop_rub_wheel_02");
			Menu::Option("prop_rub_wreckage_3");
			Menu::Option("prop_rub_wreckage_4");
			Menu::Option("prop_rub_wreckage_5");
			Menu::Option("prop_rub_wreckage_6");
			Menu::Option("prop_rub_wreckage_7");
			Menu::Option("prop_rub_wreckage_8");
			Menu::Option("prop_rub_wreckage_9");
			Menu::Option("prop_skid_chair_01");
			Menu::Option("prop_skid_chair_02");
			Menu::Option("prop_skid_chair_03");
			Menu::Option("prop_skid_sleepbag_1");
			Menu::Option("prop_skid_tent_01");
			Menu::Option("prop_skid_tent_01b");
			Menu::Option("prop_skid_tent_03");
			Menu::Option("prop_still");
			Menu::Option("prop_bench_01b");
			Menu::Option("prop_bench_01c");
			Menu::Option("prop_bench_04");
			Menu::Option("prop_bench_05");
			Menu::Option("prop_bench_09");
			Menu::Option("prop_chair_01a");
			Menu::Option("prop_chair_01b");
			Menu::Option("prop_chair_02");
			Menu::Option("prop_chair_03");
			Menu::Option("prop_chair_04a");
			Menu::Option("prop_chair_04b");
			Menu::Option("prop_chair_05");
			Menu::Option("prop_chair_06");
			Menu::Option("prop_chair_07");
			Menu::Option("prop_chair_08");
			Menu::Option("prop_chair_09");
			Menu::Option("prop_chair_10");
			Menu::Option("prop_chair_pile_01");
			Menu::Option("prop_chateau_chair_01");
			Menu::Option("prop_clown_chair");
			Menu::Option("prop_old_deck_chair");
			Menu::Option("prop_old_deck_chair_02");
			Menu::Option("prop_old_wood_chair");
			Menu::Option("prop_old_wood_chair_lod");
			Menu::Option("prop_parasol_01");
			Menu::Option("prop_parasol_01_b");
			Menu::Option("prop_parasol_01_c");
			Menu::Option("prop_parasol_01_down");
			Menu::Option("prop_parasol_02");
			Menu::Option("prop_parasol_02_b");
			Menu::Option("prop_parasol_02_c");
			Menu::Option("prop_parasol_03");
			Menu::Option("prop_parasol_03_b");
			Menu::Option("prop_parasol_03_c");
			Menu::Option("prop_parasol_04e");
			Menu::Option("prop_parasol_04e_lod1");
			Menu::Option("prop_parasol_bh_48");
			Menu::Option("prop_patio_heater_01");
			Menu::Option("prop_patio_lounger1");
			Menu::Option("prop_patio_lounger1b");
			Menu::Option("prop_patio_lounger1_table");
			Menu::Option("prop_patio_lounger_2");
			Menu::Option("prop_patio_lounger_3");
			Menu::Option("prop_picnictable_02");
			Menu::Option("prop_proxy_chateau_table");
			Menu::Option("prop_stool_01");
			Menu::Option("prop_table_02");
			Menu::Option("prop_table_03b_cs");
			Menu::Option("prop_table_04");
			Menu::Option("prop_table_04_chr");
			Menu::Option("prop_table_05");
			Menu::Option("prop_table_05_chr");
			Menu::Option("prop_table_06");
			Menu::Option("prop_table_06_chr");
			Menu::Option("prop_table_07");
			Menu::Option("prop_table_07_l1");
			Menu::Option("prop_table_08");
			Menu::Option("prop_table_08_chr");
			Menu::Option("prop_table_08_side");
			Menu::Option("prop_table_para_comb_04");
			Menu::Option("prop_umpire_01");
			Menu::Option("prop_afsign_amun");
			Menu::Option("prop_afsign_vbike");
			Menu::Option("prop_beer_neon_01");
			Menu::Option("prop_beer_neon_02");
			Menu::Option("prop_beer_neon_03");
			Menu::Option("prop_beer_neon_04");
			Menu::Option("prop_billboard_01");
			Menu::Option("prop_billboard_02");
			Menu::Option("prop_billboard_03");
			Menu::Option("prop_billboard_04");
			Menu::Option("prop_billboard_05");
			Menu::Option("prop_billboard_06");
			Menu::Option("prop_billboard_07");
			Menu::Option("prop_billboard_08");
			Menu::Option("prop_billboard_09");
			Menu::Option("prop_billboard_09wall");
			Menu::Option("prop_billboard_10");
			Menu::Option("prop_billboard_11");
			Menu::Option("prop_billboard_12");
			Menu::Option("prop_billboard_13");
			Menu::Option("prop_billboard_14");
			Menu::Option("prop_billboard_15");
			Menu::Option("prop_billboard_16");
			Menu::Option("prop_gas_01");
			Menu::Option("prop_gas_02");
			Menu::Option("prop_gas_03");
			Menu::Option("prop_gas_04");
			Menu::Option("prop_gas_05");
			Menu::Option("prop_pharm_sign_01");
			Menu::Option("prop_sign_airp_01a");
			Menu::Option("prop_sign_airp_02a");
			Menu::Option("prop_sign_airp_02b");
			Menu::Option("prop_sign_big_01");
			Menu::Option("prop_sign_road_04g_l1");
			Menu::Option("prop_barrel_01a");
			Menu::Option("prop_barrel_02a");
			Menu::Option("prop_barrel_02b");
			Menu::Option("prop_barrel_03a");
			Menu::Option("prop_barrel_03d");
			Menu::Option("prop_boxpile_10a");
			Menu::Option("prop_boxpile_10b");
			Menu::Option("prop_box_ammo01a");
			Menu::Option("prop_box_ammo02a");
			Menu::Option("prop_box_ammo03a_set");
			Menu::Option("prop_box_ammo03a_set2");
			Menu::Option("prop_box_ammo04a");
			Menu::Option("prop_box_ammo05b");
			Menu::Option("prop_box_ammo07a");
			Menu::Option("prop_box_ammo07b");
			Menu::Option("prop_box_guncase_01a");
			Menu::Option("prop_box_guncase_02a");
			Menu::Option("prop_box_guncase_03a");
			Menu::Option("prop_box_tea01a");
			Menu::Option("prop_box_wood05a");
			Menu::Option("prop_box_wood05b");
			Menu::Option("prop_box_wood08a");
			Menu::Option("prop_buckets_02");
			Menu::Option("prop_bucket_01a");
			Menu::Option("prop_bucket_01b");
			Menu::Option("prop_bucket_02a");
			Menu::Option("prop_cntrdoor_ld_l");
			Menu::Option("prop_cntrdoor_ld_r");
			Menu::Option("prop_container_01a");
			Menu::Option("prop_container_01b");
			Menu::Option("prop_container_01c");
			Menu::Option("prop_container_01d");
			Menu::Option("prop_container_01e");
			Menu::Option("prop_container_01f");
			Menu::Option("prop_container_01g");
			Menu::Option("prop_container_01h");
			Menu::Option("prop_container_01mb");
			Menu::Option("prop_container_02a");
			Menu::Option("prop_container_03a");
			Menu::Option("prop_container_03b");
			Menu::Option("prop_container_03mb");
			Menu::Option("prop_container_03_ld");
			Menu::Option("prop_container_04a");
			Menu::Option("prop_container_04mb");
			Menu::Option("prop_container_05mb");
			Menu::Option("prop_container_door_mb_l");
			Menu::Option("prop_container_door_mb_r");
			Menu::Option("prop_container_ld");
			Menu::Option("prop_container_ld2");
			Menu::Option("prop_container_old1");
			Menu::Option("prop_contnr_pile_01a");
			Menu::Option("prop_cratepile_07a_l1");
			Menu::Option("prop_crate_01a");
			Menu::Option("prop_crate_02a");
			Menu::Option("prop_crate_08a");
			Menu::Option("prop_crate_09a");
			Menu::Option("prop_crate_10a");
			Menu::Option("prop_crate_11a");
			Menu::Option("prop_crate_11b");
			Menu::Option("prop_crate_11c");
			Menu::Option("prop_crate_11d");
			Menu::Option("prop_dog_cage_01");
			Menu::Option("prop_dog_cage_02");
			Menu::Option("prop_drop_crate_01");
			Menu::Option("prop_drop_crate_01_set");
			Menu::Option("prop_drop_crate_01_set2");
			Menu::Option("prop_flattrailer_01a");
			Menu::Option("prop_flattruck_01a");
			Menu::Option("prop_fruitstand_b_nite");
			Menu::Option("prop_gascage01");
			Menu::Option("prop_keg_01");
			Menu::Option("prop_mb_crate_01a_set");
			Menu::Option("prop_pallettruck_01");
			Menu::Option("prop_sacktruck_01");
			Menu::Option("prop_sacktruck_02a");
			Menu::Option("prop_shelves_01");
			Menu::Option("prop_shelves_02");
			Menu::Option("prop_shelves_03");
			Menu::Option("prop_truktrailer_01a");
			Menu::Option("prop_warehseshelf01");
			Menu::Option("prop_warehseshelf02");
			Menu::Option("prop_warehseshelf03");
			Menu::Option("prop_watercrate_01");
			Menu::Option("prop_chall_lamp_01");
			Menu::Option("prop_chall_lamp_01n");
			Menu::Option("prop_chall_lamp_02");
			Menu::Option("prop_construcionlamp_01");
			Menu::Option("prop_dt1_13_groundlight");
			Menu::Option("prop_dt1_13_walllightsource");
			Menu::Option("prop_ind_light_01a");
			Menu::Option("prop_ind_light_01b");
			Menu::Option("prop_ind_light_01c");
			Menu::Option("prop_securityvan_lightrig");
			Menu::Option("prop_traffic_rail_1c");
			Menu::Option("prop_traffic_rail_2");
			Menu::Option("prop_walllight_ld_01b");
			Menu::Option("prop_wall_light_08a");
			Menu::Option("prop_wall_light_10a");
			Menu::Option("prop_wall_light_10b");
			Menu::Option("prop_wall_light_10c");
			Menu::Option("prop_wall_light_11");
			Menu::Option("prop_wall_light_12");
			Menu::Option("prop_wall_light_17b");
			Menu::Option("prop_wall_light_18a");
			Menu::Option("prop_warninglight_01");
			Menu::Option("prop_atm_02");
			Menu::Option("prop_atm_03");
			Menu::Option("prop_bikerack_2");
			Menu::Option("prop_bollard_01a");
			Menu::Option("prop_bollard_01b");
			Menu::Option("prop_bollard_01c");
			Menu::Option("prop_bollard_03a");
			Menu::Option("prop_elecbox_03a");
			Menu::Option("prop_elecbox_10");
			Menu::Option("prop_elecbox_12");
			Menu::Option("prop_elecbox_13");
			Menu::Option("prop_elecbox_14");
			Menu::Option("prop_elecbox_15");
			Menu::Option("prop_elecbox_16");
			Menu::Option("prop_elecbox_17");
			Menu::Option("prop_elecbox_18");
			Menu::Option("prop_elecbox_19");
			Menu::Option("prop_elecbox_20");
			Menu::Option("prop_elecbox_21");
			Menu::Option("prop_elecbox_22");
			Menu::Option("prop_elecbox_23");
			Menu::Option("prop_elecbox_24");
			Menu::Option("prop_elecbox_24b");
			Menu::Option("prop_elecbox_25");
			Menu::Option("prop_fire_driser_1a");
			Menu::Option("prop_fire_driser_1b");
			Menu::Option("prop_fire_driser_2b");
			Menu::Option("prop_fire_driser_3b");
			Menu::Option("prop_fire_driser_4a");
			Menu::Option("prop_fire_driser_4b");
			Menu::Option("prop_fire_hosereel");
			Menu::Option("prop_fleeca_atm");
			Menu::Option("prop_gshotsensor_01");
			Menu::Option("prop_mobile_mast_1");
			Menu::Option("prop_mobile_mast_2");
			Menu::Option("prop_parking_sign_06");
			Menu::Option("prop_parking_sign_07");
			Menu::Option("prop_parking_sign_1");
			Menu::Option("prop_parking_sign_2");
			Menu::Option("prop_phonebox_05a");
			Menu::Option("prop_telegraph_01a");
			Menu::Option("prop_telegraph_01b");
			Menu::Option("prop_telegraph_01c");
			Menu::Option("prop_telegraph_01d");
			Menu::Option("prop_telegraph_01e");
			Menu::Option("prop_telegraph_01f");
			Menu::Option("prop_telegraph_01g");
			Menu::Option("prop_telegraph_02a");
			Menu::Option("prop_telegraph_02b");
			Menu::Option("prop_telegraph_03");
			Menu::Option("prop_telegraph_04a");
			Menu::Option("prop_telegraph_04b");
			Menu::Option("prop_telegraph_05a");
			Menu::Option("prop_telegraph_05b");
			Menu::Option("prop_telegraph_05c");
			Menu::Option("prop_telegraph_06a");
			Menu::Option("prop_telegraph_06b");
			Menu::Option("prop_telegraph_06c");
			Menu::Option("prop_telegwall_01a");
			Menu::Option("prop_telegwall_01b");
			Menu::Option("prop_telegwall_02a");
			Menu::Option("prop_telegwall_03a");
			Menu::Option("prop_telegwall_03b");
			Menu::Option("prop_telegwall_04a");
			Menu::Option("prop_tram_pole_double01");
			Menu::Option("prop_tram_pole_double02");
			Menu::Option("prop_tram_pole_double03");
			Menu::Option("prop_tram_pole_roadside");
			Menu::Option("prop_tram_pole_single01");
			Menu::Option("prop_tram_pole_single02");
			Menu::Option("prop_tram_pole_wide01");
			Menu::Option("prop_tyre_rack_01");
			Menu::Option("prop_valet_03");
			Menu::Option("prop_cartwheel_01");
			Menu::Option("prop_cattlecrush");
			Menu::Option("prop_chickencoop_a");
			Menu::Option("prop_feeder1");
			Menu::Option("prop_grain_hopper");
			Menu::Option("prop_handrake");
			Menu::Option("prop_haybailer_01");
			Menu::Option("prop_haybale_01");
			Menu::Option("prop_haybale_02");
			Menu::Option("prop_haybale_stack_01");
			Menu::Option("prop_hunterhide");
			Menu::Option("prop_oldplough1");
			Menu::Option("prop_old_churn_01");
			Menu::Option("prop_old_churn_02");
			Menu::Option("prop_old_farm_01");
			Menu::Option("prop_old_farm_02");
			Menu::Option("prop_potatodigger");
			Menu::Option("prop_roundbailer01");
			Menu::Option("prop_roundbailer02");
			Menu::Option("prop_rural_windmill_l1");
			Menu::Option("prop_rural_windmill_l2");
			Menu::Option("prop_scythemower");
			Menu::Option("prop_side_spreader");
			Menu::Option("prop_snow_bailer_01");
			Menu::Option("prop_snow_barrel_pile_03");
			Menu::Option("prop_snow_bench_01");
			Menu::Option("prop_snow_bin_01");
			Menu::Option("prop_snow_bin_02");
			Menu::Option("prop_snow_cam_03");
			Menu::Option("prop_snow_cam_03a");
			Menu::Option("prop_snow_diggerbkt_01");
			Menu::Option("prop_snow_dumpster_01");
			Menu::Option("prop_snow_elecbox_16");
			Menu::Option("prop_snow_facgate_01");
			Menu::Option("prop_snow_flower_01");
			Menu::Option("prop_snow_flower_02");
			Menu::Option("prop_snow_fnclink_03crnr2");
			Menu::Option("prop_snow_fnclink_03h");
			Menu::Option("prop_snow_fnclink_03i");
			Menu::Option("prop_snow_fncwood_14a");
			Menu::Option("prop_snow_fncwood_14b");
			Menu::Option("prop_snow_fncwood_14c");
			Menu::Option("prop_snow_fncwood_14d");
			Menu::Option("prop_snow_fncwood_14e");
			Menu::Option("prop_snow_fnc_01");
			Menu::Option("prop_snow_gate_farm_03");
			Menu::Option("prop_snow_grain_01");
			Menu::Option("prop_snow_light_01");
			Menu::Option("prop_snow_oldlight_01b");
			Menu::Option("prop_snow_rail_signals02");
			Menu::Option("prop_snow_rub_trukwreck_2");
			Menu::Option("prop_snow_side_spreader_01");
			Menu::Option("prop_snow_streetlight01");
			Menu::Option("prop_snow_streetlight_01_frag_");
			Menu::Option("prop_snow_sub_frame_01a");
			Menu::Option("prop_snow_sub_frame_04b");
			Menu::Option("prop_snow_telegraph_01a");
			Menu::Option("prop_snow_telegraph_02a");
			Menu::Option("prop_snow_telegraph_03");
			Menu::Option("prop_snow_traffic_rail_1a");
			Menu::Option("prop_snow_traffic_rail_1b");
			Menu::Option("prop_snow_trailer01");
			Menu::Option("prop_snow_truktrailer_01a");
			Menu::Option("prop_snow_tyre_01");
			Menu::Option("prop_snow_wall_light_15a");
			Menu::Option("prop_snow_watertower01");
			Menu::Option("prop_snow_watertower01_l2");
			Menu::Option("prop_snow_watertower03");
			Menu::Option("prop_snow_woodpile_04a");
			Menu::Option("prop_sprayer");
			Menu::Option("prop_trailer01");
			Menu::Option("prop_trailer01_up");
			Menu::Option("prop_trough1");
			Menu::Option("prop_waterwheela");
			Menu::Option("prop_waterwheelb");
			Menu::Option("prop_wreckedcart");
			Menu::Option("prop_am_box_wood_01");
			Menu::Option("prop_bush_ivy_01_1m");
			Menu::Option("prop_bush_ivy_01_2m");
			Menu::Option("prop_bush_ivy_01_bk");
			Menu::Option("prop_bush_ivy_01_l");
			Menu::Option("prop_bush_ivy_01_pot");
			Menu::Option("prop_bush_ivy_01_r");
			Menu::Option("prop_bush_ivy_01_top");
			Menu::Option("prop_bush_ivy_02_1m");
			Menu::Option("prop_bush_ivy_02_2m");
			Menu::Option("prop_bush_ivy_02_l");
			Menu::Option("prop_bush_ivy_02_pot");
			Menu::Option("prop_bush_ivy_02_r");
			Menu::Option("prop_bush_ivy_02_top");
			Menu::Option("prop_bush_lrg_01");
			Menu::Option("prop_bush_lrg_01b");
			Menu::Option("prop_bush_lrg_01c");
			Menu::Option("prop_bush_lrg_01d");
			Menu::Option("prop_bush_lrg_01e");
			Menu::Option("prop_bush_lrg_02");
			Menu::Option("prop_bush_lrg_02b");
			Menu::Option("prop_bush_lrg_03");
			Menu::Option("prop_bush_lrg_03b");
			Menu::Option("prop_bush_lrg_04b");
			Menu::Option("prop_bush_lrg_04c");
			Menu::Option("prop_bush_lrg_04d");
			Menu::Option("prop_bush_med_01");
			Menu::Option("prop_bush_med_02");
			Menu::Option("prop_bush_med_03");
			Menu::Option("prop_bush_med_05");
			Menu::Option("prop_bush_med_06");
			Menu::Option("prop_bush_med_07");
			Menu::Option("prop_bush_neat_01");
			Menu::Option("prop_bush_neat_02");
			Menu::Option("prop_bush_neat_03");
			Menu::Option("prop_bush_neat_04");
			Menu::Option("prop_bush_neat_05");
			Menu::Option("prop_bush_neat_06");
			Menu::Option("prop_bush_neat_07");
			Menu::Option("prop_bush_neat_08");
			Menu::Option("prop_bush_ornament_01");
			Menu::Option("prop_bush_ornament_02");
			Menu::Option("prop_bush_ornament_03");
			Menu::Option("prop_bush_ornament_04");
			Menu::Option("prop_creosote_b_01");
			Menu::Option("prop_desert_iron_01");
			Menu::Option("prop_plant_group_01");
			Menu::Option("prop_plant_group_02");
			Menu::Option("prop_plant_group_03");
			Menu::Option("prop_plant_group_04");
			Menu::Option("prop_plant_group_05");
			Menu::Option("prop_plant_group_05b");
			Menu::Option("prop_plant_group_05c");
			Menu::Option("prop_plant_group_05d");
			Menu::Option("prop_plant_group_06a");
			Menu::Option("prop_plant_group_06b");
			Menu::Option("prop_plant_group_06c");
			Menu::Option("prop_skunk_bush_01");
			Menu::Option("prop_bush_grape_01");
			Menu::Option("prop_coral_bush_01");
			Menu::Option("prop_coral_flat_01");
			Menu::Option("prop_coral_flat_01_l1");
			Menu::Option("prop_coral_flat_02");
			Menu::Option("prop_coral_flat_brainy");
			Menu::Option("prop_coral_flat_clam");
			Menu::Option("prop_coral_grass_01");
			Menu::Option("prop_coral_grass_02");
			Menu::Option("prop_coral_kelp_01");
			Menu::Option("prop_coral_kelp_01_l1");
			Menu::Option("prop_coral_kelp_02");
			Menu::Option("prop_coral_kelp_02_l1");
			Menu::Option("prop_coral_kelp_03");
			Menu::Option("prop_coral_kelp_03a");
			Menu::Option("prop_coral_kelp_03b");
			Menu::Option("prop_coral_kelp_03c");
			Menu::Option("prop_coral_kelp_03d");
			Menu::Option("prop_coral_kelp_03_l1");
			Menu::Option("prop_coral_kelp_04");
			Menu::Option("prop_coral_kelp_04_l1");
			Menu::Option("prop_coral_pillar_01");
			Menu::Option("prop_coral_pillar_02");
			Menu::Option("prop_coral_spikey_01");
			Menu::Option("prop_coral_stone_03");
			Menu::Option("prop_coral_stone_04");
			Menu::Option("prop_coral_sweed_01");
			Menu::Option("prop_coral_sweed_02");
			Menu::Option("prop_coral_sweed_03");
			Menu::Option("prop_coral_sweed_04");
			Menu::Option("prop_cora_clam_01");
			Menu::Option("prop_tree_birch_05");
			Menu::Option("prop_veg_corn_01");
			Menu::Option("prop_veg_crop_01");
			Menu::Option("prop_veg_crop_02");
			Menu::Option("prop_veg_crop_04");
			Menu::Option("prop_veg_crop_04_leaf");
			Menu::Option("prop_veg_crop_05");
			Menu::Option("prop_veg_crop_06");
			Menu::Option("prop_veg_crop_orange");
			Menu::Option("prop_veg_crop_tr_01");
			Menu::Option("prop_veg_crop_tr_02");
			Menu::Option("prop_agave_01");
			Menu::Option("prop_agave_02");
			Menu::Option("prop_aloevera_01");
			Menu::Option("prop_bush_dead_02");
			Menu::Option("prop_cat_tail_01");
			Menu::Option("prop_cs_plant_01");
			Menu::Option("prop_grass_dry_02");
			Menu::Option("prop_grass_dry_03");
			Menu::Option("prop_plant_01a");
			Menu::Option("prop_plant_01b");
			Menu::Option("prop_plant_base_01");
			Menu::Option("prop_plant_base_02");
			Menu::Option("prop_plant_base_03");
			Menu::Option("prop_plant_cane_01a");
			Menu::Option("prop_plant_cane_01b");
			Menu::Option("prop_plant_cane_02a");
			Menu::Option("prop_plant_cane_02b");
			Menu::Option("prop_plant_clover_01");
			Menu::Option("prop_plant_clover_02");
			Menu::Option("prop_plant_fern_01a");
			Menu::Option("prop_plant_fern_01b");
			Menu::Option("prop_plant_fern_02a");
			Menu::Option("prop_plant_fern_02b");
			Menu::Option("prop_plant_fern_02c");
			Menu::Option("prop_plant_flower_01");
			Menu::Option("prop_plant_flower_02");
			Menu::Option("prop_plant_flower_03");
			Menu::Option("prop_plant_flower_04");
			Menu::Option("prop_plant_paradise");
			Menu::Option("prop_plant_paradise_b");
			Menu::Option("prop_p_spider_01a");
			Menu::Option("prop_p_spider_01c");
			Menu::Option("prop_p_spider_01d");
			Menu::Option("prop_veg_grass_01_a");
			Menu::Option("prop_veg_grass_01_b");
			Menu::Option("prop_veg_grass_01_c");
			Menu::Option("prop_veg_grass_01_d");
			Menu::Option("prop_veg_grass_02_a");
			Menu::Option("prop_fan_palm_01a");
			Menu::Option("prop_palm_fan_02_a");
			Menu::Option("prop_palm_fan_02_b");
			Menu::Option("prop_palm_fan_03_a");
			Menu::Option("prop_palm_fan_03_b");
			Menu::Option("prop_palm_fan_03_c");
			Menu::Option("prop_palm_fan_03_d");
			Menu::Option("prop_palm_fan_04_a");
			Menu::Option("prop_palm_fan_04_b");
			Menu::Option("prop_palm_fan_04_c");
			Menu::Option("prop_palm_fan_04_d");
			Menu::Option("prop_palm_huge_01a");
			Menu::Option("prop_palm_huge_01b");
			Menu::Option("prop_palm_med_01a");
			Menu::Option("prop_palm_med_01b");
			Menu::Option("prop_palm_med_01c");
			Menu::Option("prop_palm_med_01d");
			Menu::Option("prop_palm_sm_01a");
			Menu::Option("prop_palm_sm_01d");
			Menu::Option("prop_palm_sm_01e");
			Menu::Option("prop_palm_sm_01f");
			Menu::Option("prop_plant_int_02a");
			Menu::Option("prop_plant_int_02b");
			Menu::Option("prop_plant_int_05a");
			Menu::Option("prop_plant_int_05b");
			Menu::Option("prop_plant_int_06a");
			Menu::Option("prop_plant_int_06b");
			Menu::Option("prop_plant_int_06c");
			Menu::Option("prop_pot_plant_02a");
			Menu::Option("prop_pot_plant_02b");
			Menu::Option("prop_pot_plant_02c");
			Menu::Option("prop_pot_plant_02d");
			Menu::Option("prop_pot_plant_03a");
			Menu::Option("prop_pot_plant_04a");
			Menu::Option("prop_pot_plant_05d_l1");
			Menu::Option("prop_pot_plant_bh1");
			Menu::Option("prop_rock_1_a");
			Menu::Option("prop_rock_1_b");
			Menu::Option("prop_rock_1_c");
			Menu::Option("prop_rock_1_d");
			Menu::Option("prop_rock_1_e");
			Menu::Option("prop_rock_1_f");
			Menu::Option("prop_rock_1_g");
			Menu::Option("prop_rock_1_h");
			Menu::Option("prop_rock_1_i");
			Menu::Option("prop_rock_2_a");
			Menu::Option("prop_rock_2_c");
			Menu::Option("prop_rock_2_d");
			Menu::Option("prop_rock_2_f");
			Menu::Option("prop_rock_2_g");
			Menu::Option("prop_rock_3_a");
			Menu::Option("prop_rock_3_b");
			Menu::Option("prop_rock_3_c");
			Menu::Option("prop_rock_3_d");
			Menu::Option("prop_rock_3_e");
			Menu::Option("prop_rock_3_f");
			Menu::Option("prop_rock_3_g");
			Menu::Option("prop_rock_3_h");
			Menu::Option("prop_rock_3_i");
			Menu::Option("prop_rock_3_j");
			Menu::Option("prop_rock_4_c");
			Menu::Option("prop_rock_4_d");
			Menu::Option("rock_4_cl_2_1");
			Menu::Option("rock_4_cl_2_2");
			Menu::Option("prop_snow_bush_01_a");
			Menu::Option("prop_snow_bush_02_a");
			Menu::Option("prop_snow_bush_02_b");
			Menu::Option("prop_snow_bush_03");
			Menu::Option("prop_snow_bush_04");
			Menu::Option("prop_snow_bush_04b");
			Menu::Option("prop_snow_field_01");
			Menu::Option("prop_snow_field_02");
			Menu::Option("prop_snow_field_03");
			Menu::Option("prop_snow_field_04");
			Menu::Option("prop_snow_grass_01");
			Menu::Option("prop_snow_tree_03_e");
			Menu::Option("prop_snow_tree_03_h");
			Menu::Option("prop_snow_tree_03_i");
			Menu::Option("prop_snow_tree_04_d");
			Menu::Option("prop_snow_tree_04_f");
			Menu::Option("prop_snow_t_ml_01");
			Menu::Option("prop_snow_t_ml_02");
			Menu::Option("prop_snow_t_ml_03");
			Menu::Option("prop_rio_del_01");
			Menu::Option("prop_rus_olive");
			Menu::Option("prop_rus_olive_wint");
			Menu::Option("prop_s_pine_dead_01");
			Menu::Option("prop_tree_birch_01");
			Menu::Option("prop_tree_birch_02");
			Menu::Option("prop_tree_birch_03");
			Menu::Option("prop_tree_birch_03b");
			Menu::Option("prop_tree_birch_04");
			Menu::Option("prop_tree_cedar_02");
			Menu::Option("prop_tree_cedar_03");
			Menu::Option("prop_tree_cedar_04");
			Menu::Option("prop_tree_cedar_s_01");
			Menu::Option("prop_tree_cedar_s_02");
			Menu::Option("prop_tree_cedar_s_04");
			Menu::Option("prop_tree_cedar_s_05");
			Menu::Option("prop_tree_cedar_s_06");
			Menu::Option("prop_tree_cypress_01");
			Menu::Option("prop_tree_eng_oak_01");
			Menu::Option("prop_tree_eucalip_01");
			Menu::Option("prop_tree_fallen_01");
			Menu::Option("prop_tree_fallen_02");
			Menu::Option("prop_tree_fallen_pine_01");
			Menu::Option("prop_tree_jacada_01");
			Menu::Option("prop_tree_jacada_02");
			Menu::Option("prop_tree_lficus_02");
			Menu::Option("prop_tree_lficus_03");
			Menu::Option("prop_tree_lficus_05");
			Menu::Option("prop_tree_lficus_06");
			Menu::Option("prop_tree_log_01");
			Menu::Option("prop_tree_log_02");
			Menu::Option("prop_tree_maple_02");
			Menu::Option("prop_tree_maple_03");
			Menu::Option("prop_tree_mquite_01");
			Menu::Option("prop_tree_oak_01");
			Menu::Option("prop_tree_olive_01");
			Menu::Option("prop_tree_pine_01");
			Menu::Option("prop_tree_pine_02");
			Menu::Option("prop_tree_stump_01");
			Menu::Option("prop_w_r_cedar_01");
			Menu::Option("prop_w_r_cedar_dead");
			Menu::Option("w_am_baseball");
			Menu::Option("w_am_baseball_hi");
			Menu::Option("w_am_brfcase");
			Menu::Option("w_am_case");
			Menu::Option("w_am_digiscanner");
			Menu::Option("w_am_digiscanner_hi");
			Menu::Option("w_am_fire_exting");
			Menu::Option("w_am_flare");
			Menu::Option("w_am_flare_hi");
			Menu::Option("w_am_jerrycan");
			Menu::Option("w_ar_advancedrifle");
			Menu::Option("w_ar_advancedrifle_hi");
			Menu::Option("w_ar_advancedrifle_mag1");
			Menu::Option("w_ar_advancedrifle_mag2");
			Menu::Option("w_ar_assaultrifle");
			Menu::Option("w_ar_assaultrifle_hi");
			Menu::Option("w_ar_assaultrifle_mag1");
			Menu::Option("w_ar_assaultrifle_mag2");
			Menu::Option("w_ar_carbinerifle");
			Menu::Option("w_ar_carbinerifle_hi");
			Menu::Option("w_ar_carbinerifle_mag1");
			Menu::Option("w_ar_carbinerifle_mag2");
			Menu::Option("w_at_ar_afgrip");
			Menu::Option("w_at_ar_afgrip_hi");
			Menu::Option("w_at_ar_flsh");
			Menu::Option("w_at_ar_flsh_hi");
			Menu::Option("w_at_ar_supp");
			Menu::Option("w_at_ar_supp_02");
			Menu::Option("w_at_ar_supp_02_hi");
			Menu::Option("w_at_ar_supp_hi");
			Menu::Option("w_at_pi_flsh");
			Menu::Option("w_at_pi_flsh_hi");
			Menu::Option("w_at_pi_supp");
			Menu::Option("w_at_pi_supp_hi");
			Menu::Option("w_at_railcover_01");
			Menu::Option("w_at_railcover_01_hi");
			Menu::Option("w_at_scope_large");
			Menu::Option("w_at_scope_large_hi");
			Menu::Option("w_at_scope_macro");
			Menu::Option("w_at_scope_macro_hi");
			Menu::Option("w_at_scope_max");
			Menu::Option("w_at_scope_max_hi");
			Menu::Option("w_at_scope_medium");
			Menu::Option("w_at_scope_medium_hi");
			Menu::Option("w_at_scope_small");
			Menu::Option("w_at_scope_small_hi");
			Menu::Option("w_at_sr_supp");
			Menu::Option("w_at_sr_supp_hi");
			Menu::Option("w_ex_grenadefrag");
			Menu::Option("w_ex_grenadefrag_hi");
			Menu::Option("w_ex_grenadesmoke");
			Menu::Option("w_ex_molotov");
			Menu::Option("w_ex_molotov_hi");
			Menu::Option("w_ex_pe");
			Menu::Option("w_ex_pe_hi");
			Menu::Option("w_lr_40mm");
			Menu::Option("w_lr_40mm_pu");
			Menu::Option("w_lr_grenadelauncher");
			Menu::Option("w_lr_grenadelauncher_hi");
			Menu::Option("w_lr_rpg");
			Menu::Option("w_lr_rpg_hi");
			Menu::Option("w_lr_rpg_rocket");
			Menu::Option("w_lr_rpg_rocket_pu");
			Menu::Option("w_me_bat");
			Menu::Option("w_me_crowbar");
			Menu::Option("w_me_gclub");
			Menu::Option("w_me_hammer");
			Menu::Option("w_me_knife_01");
			Menu::Option("w_me_nightstick");
			Menu::Option("w_mg_combatmg");
			Menu::Option("w_mg_combatmg_hi");
			Menu::Option("w_mg_combatmg_mag1");
			Menu::Option("w_mg_combatmg_mag2");
			Menu::Option("w_mg_mg");
			Menu::Option("w_mg_mg_hi");
			Menu::Option("w_mg_mg_mag1");
			Menu::Option("w_mg_mg_mag2");
			Menu::Option("w_mg_minigun");
			Menu::Option("w_mg_minigun_hi");
			Menu::Option("w_pi_appistol");
			Menu::Option("w_pi_appistol_hi");
			Menu::Option("w_pi_appistol_mag1");
			Menu::Option("w_pi_appistol_mag2");
			Menu::Option("w_pi_combatpistol");
			Menu::Option("w_pi_combatpistol_hi");
			Menu::Option("w_pi_combatpistol_mag1");
			Menu::Option("w_pi_combatpistol_mag2");
			Menu::Option("w_pi_pistol");
			Menu::Option("w_pi_pistol50");
			Menu::Option("w_pi_pistol50_hi");
			Menu::Option("w_pi_pistol50_mag1");
			Menu::Option("w_pi_pistol50_mag2");
			Menu::Option("w_pi_pistol_hi");
			Menu::Option("w_pi_pistol_mag1");
			Menu::Option("w_pi_pistol_mag2");
			Menu::Option("w_pi_stungun");
			Menu::Option("w_pi_stungun_hi");
			Menu::Option("w_sb_assaultsmg");
			Menu::Option("w_sb_assaultsmg_hi");
			Menu::Option("w_sb_assaultsmg_mag1");
			Menu::Option("w_sb_assaultsmg_mag2");
			Menu::Option("w_sb_microsmg");
			Menu::Option("w_sb_microsmg_hi");
			Menu::Option("w_sb_microsmg_mag1");
			Menu::Option("w_sb_microsmg_mag2");
			Menu::Option("w_sb_smg");
			Menu::Option("w_sb_smg_hi");
			Menu::Option("w_sb_smg_mag1");
			Menu::Option("w_sb_smg_mag2");
			Menu::Option("w_sg_assaultshotgun");
			Menu::Option("w_sg_assaultshotgun_hi");
			Menu::Option("w_sg_assaultshotgun_mag1");
			Menu::Option("w_sg_assaultshotgun_mag2");
			Menu::Option("w_sg_bullpupshotgun");
			Menu::Option("w_sg_bullpupshotgun_hi");
			Menu::Option("w_sg_pumpshotgun");
			Menu::Option("w_sg_pumpshotgun_hi");
			Menu::Option("w_sg_sawnoff");
			Menu::Option("w_sg_sawnoff_hi");
			Menu::Option("w_sr_heavysniper");
			Menu::Option("w_sr_heavysniper_hi");
			Menu::Option("w_sr_heavysniper_mag1");
			Menu::Option("w_sr_sniperrifle");
			Menu::Option("w_sr_sniperrifle_hi");
			Menu::Option("w_sr_sniperrifle_mag1");
		}
		break;
#pragma endregion
#pragma region Online Menu

		case onlinemenu_selected:
		{
			bool unk0;
			uint64_t* args;
			int argCount;
			int bitFlags;

			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
			GRAPHICS::DRAW_MARKER(2, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, 255, 0, 0, 200, 1, 1, 1, 0, 0, 0, 0);
			Menu::Subtitle(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
			Menu::Title("OPTIONS FOR A PLAYER");
			Menu::Break("~r~Troll Options");
			Menu::MenuOption("Teleport Options", OnlineTP);
			Menu::MenuOption("Vehicle Options", cartroll);
			Menu::MenuOption("Drop Options ~RISK", dropoptions);
			Menu::MenuOption("Effects Menu", PTFXO);
			Menu::MenuOption("Attach Options", attachoptions);
			Menu::Toggle("Water Loop", Features::Online::WaterLoop, [] { Features::Online::waterLoop(Features::Online::WaterLoop); });
			Menu::Toggle("Freeze Loop", Features::Online::FreezeLoop, [] { Features::Online::FreezeLooop(Features::Online::FreezeLoop); });
			Menu::Toggle("Explode Loop", Features::Online::Explode, [] { Features::Online::Explodee(Features::Online::Explode); });
			if (Menu::Option("Trap on Cage")) { Features::attachobjects2("prop_gold_cont_01"); }
			if (Menu::Option("~r~Crash ")) {

				int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);
				PED::CLONE_PED(Handle, 1, 1, 1);

			}
			
			if (Menu::Option("Explode")) {
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 28, 10.5f, true, false, 10.f);
			}
			if (Features::Online::selectedPlayer != PLAYER::PLAYER_ID()) { Menu::Toggle("Spectate", Features::spectate[Features::Online::selectedPlayer], [] { Features::specter(Features::spectate[Features::Online::selectedPlayer]); }); }
			if (Menu::Option("Kill"))
			{
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 10, 1000.f, true, false, 10000.f);

			}
			
			if (Menu::Option("Shake  Player Cam")) {
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 000.f, true, false, 10000.f);

			}
			if (Menu::Option("Force Fld")) {

				Player playerPed2 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed2, 0);
				FIRE::ADD_EXPLOSION(pCoords.x, pCoords.y, pCoords.z, 7, 9.0f, false, true, 0.0f);

			}
			if (Menu::Option("~y~Airstrike Player")) 
			{

				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1);
				Coords.z += 15;
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 35, Coords.x, Coords.y, Coords.z, 250, 1, GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1, 1, 500);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 30, Coords.x, Coords.y, Coords.z, 250, 0, GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), 0, 1, 1, 500);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 55, Coords.x, Coords.y, Coords.z, 100, false, 0xF8A3939F, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true, true, 600);


			}

			if (Menu::Option("Fire Player"))
			{
				Vector3 Coords2 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1);
		FIRE::START_SCRIPT_FIRE(Coords2.x, Coords2.y, Coords2.z, 1, false);



			}
			if (Menu::Option("Clone Player"))
			{
				Vector3 Coords2 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1);
				FIRE::START_SCRIPT_FIRE(Coords2.x, Coords2.y, Coords2.z, 1, false);



			}





		}
		break;

#pragma endregion
#pragma region Effect Online Options
		case OnlineTP:
		{
			bool unk0;
			uint64_t* args;
			int argCount;
			int bitFlags;

			Menu::Title("Teleport Player");
			Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
			Menu::Subtitle(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			Menu::Option("Teleport To Player", [] {Features::Online::TeleportToPlayer(Features::Online::selectedPlayer); });
			if (Menu::Option("Teleport Into Player Car")) 
			{
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				for (int i = -1; i < 16; i++)
				{
					if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i))
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, i);
					}
				}
			}
			
		}
		break;
#pragma endregion
#pragma region Attach Options
		case attachoptions:
		{
			Menu::Title("Attach To Players");
			Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
			Menu::Subtitle(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			if (Menu::Option("Plate")) { Features::attachobjects2("p_oil_slick_01"); }
			if (Menu::Option("EMP")) { Features::attachobjects2("hei_prop_heist_emp"); }
			if (Menu::Option("Orange Ball")) { Features::attachobjects2("prop_juicestand"); }
			if (Menu::Option("Weed")) { Features::attachobjects2("prop_weed_01"); }
			if (Menu::Option("Safe")) { Features::attachobjects2("p_v_43_safe_s"); }
			if (Menu::Option("Ufo")) { Features::attachobjects2("p_spinning_anus_s"); }
			if (Menu::Option("Toilet")) { Features::attachobjects2("prop_ld_toilet_01"); }
			if (Menu::Option("Christmas Tree")) { Features::attachobjects2("prop_xmas_tree_int"); }
			if (Menu::Option("Windmill")) { Features::attachobjects2("prop_windmill_01"); }
			if (Menu::Option("Radar")) { Features::attachobjects2("prop_air_bigradar"); }
			if (Menu::Option("Alien Egg")) { Features::attachobjects2("prop_alien_egg_01"); }
			if (Menu::Option("Beggers Sign")) { Features::attachobjects2("prop_beggers_sign_01"); }
			if (Menu::Option("Tramp Sign")) { Features::attachobjects2("prop_beggers_sign_02"); }
			if (Menu::Option("Egg Clock")) { Features::attachobjects2("prop_egg_clock_01"); }
			if (Menu::Option("Guitar")) { Features::attachobjects2("prop_acc_guitar_01_d1"); }
			if (Menu::Option("Duffel")) { Features::attachobjects2("prop_cs_duffel_01b"); }
			if (Menu::Option("Vending Dispenser")) { Features::attachobjects2("prop_juice_dispenser"); }
			if (Menu::Option("Boxing")) { Features::attachobjects2("prop_boxing_glove_01"); }
			if (Menu::Option("Dingy")) { Features::attachobjects2("prop_byard_dingy"); }
			if (Menu::Option("Dildo")) { Features::attachobjects2("prop_cs_dildo_01"); }
			if (Menu::Option("Dumpster")) { Features::attachobjects2("prop_cs_dumpster_01a"); }
			if (Menu::Option("DJ")) { Features::attachobjects2("prop_dj_deck_02"); }
			if (Menu::Option("Plane")) { Features::attachobjects2("prop_dummy_plane"); }
			if (Menu::Option("Ramp")) { Features::attachobjects2("PROP_MP_RAMP_03"); }
			if (Menu::Option("Ramp2")) { Features::attachobjects2("PROP_MP_RAMP_02"); }
			if (Menu::Option("Ramp3")) { Features::attachobjects2("PROP_MP_RAMP_01"); }
			if (Menu::Option("Skip")) { Features::attachobjects2("PROP_SKIP_08A"); }
			if (Menu::Option("Number 1")) { Features::attachobjects2("PROP_MP_NUM_1"); }
			if (Menu::Option("Number 2")) { Features::attachobjects2("PROP_MP_NUM_2"); }
			if (Menu::Option("Number 3")) { Features::attachobjects2("PROP_MP_NUM_3"); }
			if (Menu::Option("Number 4")) { Features::attachobjects2("PROP_MP_NUM_4"); }
			if (Menu::Option("Number 5")) { Features::attachobjects2("PROP_MP_NUM_5"); }
			if (Menu::Option("Number 6")) { Features::attachobjects2("PROP_MP_NUM_6"); }
			if (Menu::Option("Number 7")) { Features::attachobjects2("PROP_MP_NUM_7"); }
			if (Menu::Option("Number 8")) { Features::attachobjects2("PROP_MP_NUM_8"); }
			if (Menu::Option("Number 9")) { Features::attachobjects2("PROP_MP_NUM_9"); }
			if (Menu::Option("Beer Neon")) { Features::attachobjects2("prop_beer_neon_01"); }
			if (Menu::Option("Dummy Plane")) { Features::attachobjects2("prop_dummy_plane"); }
			if (Menu::Option("Cash Pile")) { Features::attachobjects2("prop_anim_cash_pile_02"); }
			if (Menu::Option("Asteroid")) { Features::attachobjects2("prop_asteroid_01"); }
			if (Menu::Option("Weed Palet")) { Features::attachobjects2("prop_weed_pallet"); }
			if (Menu::Option("Ferris Wheel")) { Features::attachobjects2("prop_Ld_ferris_wheel"); }
			if (Menu::Option("Donut")) { Features::attachobjects2("prop_amb_donut"); }
			if (Menu::Option("Basejump")) { Features::attachobjects2("prop_basejump_target_01"); }
			if (Menu::Option("Handbag")) { Features::attachobjects2("prop_amb_handbag_01"); }
			if (Menu::Option("Cargo")) { Features::attachobjects2("prop_air_cargo_01a"); }
			if (Menu::Option("Stunt Ramp BIG")) { Features::attachobjects2("stt_prop_ramp_multi_loop_rb"); }
			if (Menu::Option("Crashed Heli")) { Features::attachobjects2("prop_crashed_heli"); }
			if (Menu::Option("Crashed Heli 2")) { Features::attachobjects2("prop_crashed_heli_s"); }
			if (Menu::Option("Train")) { Features::attachobjects2("prop_rail_boxcar3"); }
			if (Menu::Option("Roller")) { Features::attachobjects2("prop_roller_car_02"); }
			if (Menu::Option("Para")) { Features::attachobjects2("p_cargo_chute_s"); }
			char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };

			if (Menu::Option("Delete All Objects")) {
				for (int i = 0; i < 5; i++) {
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1);
					GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
					for (int i = 0; i < 136; i++) {
						Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

						if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer))) {
							RequestControlOfEnt(obj);
							int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
							NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
							Features::RequestControlOfid(netID);
							ENTITY::DETACH_ENTITY(obj, 1, 1);
							if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
								ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
								ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
								ENTITY::DELETE_ENTITY(&obj);
							}
						}
					}
				}
			}
		}
		break;
#pragma endregion
#pragma region Effect Online Options
		case PTFXO:
		{
			Menu::Title("Online Effects");
			Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
			Menu::Subtitle(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			Menu::Toggle("Looped", Features::PTLoopedO[Features::Online::selectedPlayer]);
			if (Menu::Option("Clown Appears"))Features::PTFXCALLO("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", Features::Online::selectedPlayer);
			if (Menu::Option("Firework 1"))Features::PTFXCALLO("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", Features::Online::selectedPlayer);
			if (Menu::Option("Firework 2"))Features::PTFXCALLO("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw", Features::Online::selectedPlayer);
			if (Menu::Option("Firework 3"))Features::PTFXCALLO("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw", Features::Online::selectedPlayer);
			if (Menu::Option("Banknotes"))Features::PTFXCALLO("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes", Features::Online::selectedPlayer);
			if (Menu::Option("Truck Crash"))Features::PTFXCALLO("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash", Features::Online::selectedPlayer);
			if (Menu::Option("Ped Sliced"))Features::PTFXCALLO("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced", Features::Online::selectedPlayer);
			if (Menu::Option("Camera"))Features::PTFXCALLO("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera", Features::Online::selectedPlayer);
			if (Menu::Option("Alien 1"))Features::PTFXCALLO("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", Features::Online::selectedPlayer);
			if (Menu::Option("Alien 2"))Features::PTFXCALLO("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", Features::Online::selectedPlayer);
			if (Menu::Option("Electric Box"))Features::PTFXCALLO("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", Features::Online::selectedPlayer);
			if (Menu::Option("Water Splash"))Features::PTFXCALLO("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", Features::Online::selectedPlayer);
			if (Menu::Option("Bubbles"))Features::PTFXCALLO("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles", Features::Online::selectedPlayer);
			if (Menu::Option("Blood Entry"))Features::PTFXCALLO("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", Features::Online::selectedPlayer);
			if (Menu::Option("Sniper Impact"))Features::PTFXCALLO("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact", Features::Online::selectedPlayer);
			if (Menu::Option("Dirt Throw"))Features::PTFXCALLO("core_snow", "core_snow", "cs_mich1_spade_dirt_throw", Features::Online::selectedPlayer);
			if (Menu::Option("Blood Stab"))Features::PTFXCALLO("scr_michael2", "scr_michael2", "scr_mich2_blood_stab", Features::Online::selectedPlayer);
			if (Menu::Option("Meth Smoke"))Features::PTFXCALLO("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", Features::Online::selectedPlayer);
			if (Menu::Option("Burial Dirt"))Features::PTFXCALLO("scr_reburials", "scr_reburials", "scr_burial_dirt", Features::Online::selectedPlayer);
		}
		break;
#pragma endregion
#pragma region cartroll
		case cartroll:
		{
			Menu::Title("Vehicle Troll Options");
			Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
			Menu::Subtitle(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			if (Menu::Option("Slingshot Car")) {
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true));
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true)));
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true), 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
				}
			}
			if (Menu::Option("Kick him out of Car")) {
				Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(playerPed);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
				AI::CLEAR_PED_TASKS(playerPed);
				AI::CLEAR_PED_SECONDARY_TASK(playerPed);
			}
			if (Menu::Option("Explode Vehicle")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 29, 0.5f, true, false, 5.0f);
			}
			if (Menu::Option("Launch Vehicle")) {
				Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
				{
					RequestControlOfEnt(veh);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 300.0);
				}
			}
			if (Menu::Option("Push Vehicle")) {
				Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
				{
					RequestControlOfEnt(veh);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 120.0);

				}
			}
			if (Menu::Option("Pop Tires")) {
				Vehicle selectedlPlayerveh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), FALSE);
				bool isveh = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), FALSE);
				if (isveh)
				{
					RequestControlOfEnt(selectedlPlayerveh);
					VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(selectedlPlayerveh, TRUE);
					for (int i = 5; i--;)
						VEHICLE::SET_VEHICLE_TYRE_BURST(selectedlPlayerveh, i, TRUE, 1000.f);

				}
			}
			Menu::Break("GIVE VEHICLE");
			if (Menu::Option("T20"))
			{
				int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
				Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
				Vehicle zentorno = Features::SpawnVehicle("t20", Ocoords, 0, 0.0f);
				ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
			}
			if (Menu::Option("Monster"))
			{
				int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
				Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
				Vehicle zentorno = Features::SpawnVehicle("MONSTER", Ocoords, 0, 0.0f);
				ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
			}
			if (Menu::Option("Rhino Thank"))
			{
				int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
				Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
				Vehicle zentorno = Features::SpawnVehicle("RHINO", Ocoords, 0, 0.0f);
				ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
			}
			if (Menu::Option("Docker"))
			{
				int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
				Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
				Vehicle zentorno = Features::SpawnVehicle("DUNE2", Ocoords, 0, 0.0f);
				ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
			}
		}
		break;
#pragma endregion
#pragma region dropoptions
		case dropoptions:
		{
			Menu::Title("Drop Options");
			Menu::Subtitle(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			if (Menu::Option("Give All Weapons")) {
				uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), Weapons[i], 9999, 1);
					WAIT(10);
				}
			}
			if (Menu::Option("Take All Weapons")) {
				WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
			}
			if (Menu::Option("Drop Armor")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				OBJECT::CREATE_AMBIENT_PICKUP(1274757841, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
			}
			if (Menu::Option("Drop Parachute")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				OBJECT::CREATE_AMBIENT_PICKUP(1735599485, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
			}
			if (Menu::Option("Drop Snack")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				OBJECT::CREATE_AMBIENT_PICKUP(483577702, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
			}
			if (Menu::Option("Drop Health")) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				OBJECT::CREATE_AMBIENT_PICKUP(678958360, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
			}
		}
		break;
#pragma endregion
#pragma region mapmode
		case exploitramp:
		{
			Menu::Title("Map Mods");
			Menu::Subtitle("MAPS");
			Menu::MenuOption("Maze Bank Small Ramp", ramp1);
			Menu::MenuOption("Maze Bank Roof Ramp", ramp2);
			Menu::MenuOption("Beach Ramp", ramp3);
			Menu::MenuOption("Mount Chilliad Ramp", ramp4);
			Menu::MenuOption("Airport Mini Ramp", ramp5);
			Menu::MenuOption("Airport Gate Ramp", ramp6);
			Menu::MenuOption("Space Tower", ramp7);
			Menu::MenuOption("Quad Ramp", ramp8);
			Menu::MenuOption("Fort", ramp9);
			Menu::MenuOption("Halfpipe", ramp10);
			Menu::MenuOption("Airport Loop Ramp", ramp11);
			Menu::MenuOption("Mega Ramp", ramp12);
		}
		break;
#pragma region mapmode
		case ramp1:
			Menu::Title("Maze Bank Demolition");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(2475986526, -80.9087, -830.357, 325.097, -14.4264, -8.53774, 152.209, -1, 0);
				Features::PlaceObjectByHash(2475986526, -79.2316, -831.297, 325.108, -14.4054, 4.26887, 164.271, -1, 0);
				Features::PlaceObjectByHash(2475986526, -76.7563, -831.549, 325.123, -14.4263, -0, 171.818, -1, 0);
				Features::PlaceObjectByHash(2475986526, -74.2595, -831.691, 325.09, -14.2059, -1.06722, -176.517, -1, 0);
				Features::PlaceObjectByHash(2475986526, -71.9478, -831.257, 325.113, -14.4264, 2.13443, -166.006, -1, 0);
				Features::PlaceObjectByHash(2475986526, -69.5981, -830.542, 325.066, -14.5918, -4.26887, -155.474, -1, 0);
				Features::PlaceObjectByHash(2475986526, -67.4174, -829.035, 325.097, -14.4263, -4.26887, -140.651, -1, 0);
				Features::PlaceObjectByHash(2475986526, -65.7121, -827.409, 325.068, -14.3048, -1.70755, -130.667, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.2717, -825.422, 325.112, -14.4263, -0, -121.256, -1, 0);
				Features::PlaceObjectByHash(2475986526, -63.2876, -823.434, 325.114, -14.5345, -0, -111.446, -1, 0);
				Features::PlaceObjectByHash(2475986526, -62.4924, -821.128, 325.082, -14.5467, 2.13443, -102.385, -1, 0);
				Features::PlaceObjectByHash(2475986526, -62.233, -818.528, 325.065, -14.6184, -8.00413, -88.1861, -1, 0);
				Features::PlaceObjectByHash(2475986526, -62.8694, -815.926, 325.118, -14.4265, -6.4033, -76.5979, -1, 0);
				Features::PlaceObjectByHash(2475986526, -63.6142, -813.68, 325.112, -14.3655, 8.53774, -66.7885, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.9883, -811.439, 325.107, -14.4263, 1.28066, -52.8494, -1, 0);
				Features::PlaceObjectByHash(2475986526, -66.5913, -808.328, 325.238, -12.4517, -0, -40.3246, -1, 0);
				Features::PlaceObjectByHash(2475986526, -68.2603, -807.899, 325.336, -13.8689, -0, -33.062, -1, 0);
				Features::PlaceObjectByHash(2475986526, -71.1526, -807.598, 325.153, -12.0416, 4.26887, -28.0523, -1, 0);
				Features::PlaceObjectByHash(2475986526, -73.2853, -806.628, 325.151, -11.7962, -0, -19.1717, -1, 0);
				Features::PlaceObjectByHash(2475986526, -75.2243, -806.286, 325.164, -12.0419, -0, 1.55726, -1, 0);
				Features::PlaceObjectByHash(2475986526, -77.5757, -806.312, 325.088, -14.1843, -0, 12.6263, -1, 0);
				Features::PlaceObjectByHash(2475986526, -79.8704, -807.22, 325.143, -14.049, -4.26887, 21.4769, -1, 0);
				Features::PlaceObjectByHash(2475986526, -82.0222, -807.83, 325.036, -14.1422, -4.26887, 32.7605, -1, 0);
				Features::PlaceObjectByHash(2475986526, -83.8934, -809.424, 325.073, -14.5264, -8.53774, 46.5132, -1, 0);
				Features::PlaceObjectByHash(2475986526, -85.2523, -810.983, 325.043, -14.859, -0, 53.5324, -1, 0);
				Features::PlaceObjectByHash(2475986526, -86.5177, -813.202, 325.089, -14.5267, 4.26887, 64.6634, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.6645, -815.707, 325.059, -14.8589, 4.26887, 73.157, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.7973, -817.987, 325.119, -14.8468, -1.33402, 89.3982, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.5801, -821.034, 325.059, -14.8593, -0, 95.4435, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.2815, -822.239, 325.126, -15.6308, -4.26887, 100.311, -1, 0);
				Features::PlaceObjectByHash(2475986526, -86.7602, -824.03, 325.044, -15.9224, -0, 116.957, -1, 0);
				Features::PlaceObjectByHash(2475986526, -85.3743, -826.099, 325.136, -15.7025, 2.56132, 124.307, -1, 0);
				Features::PlaceObjectByHash(2475986526, -83.4737, -828.611, 325.076, -15.0688, -0, 132.538, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.9554, -832.877, 325.894, -14.1563, 4.26887, 132.995, -1, 0);
				Features::PlaceObjectByHash(2475986526, -89.3865, -831.322, 325.887, -14.1562, -0, 126.154, -1, 0);
				Features::PlaceObjectByHash(2475986526, -86.4247, -834.407, 325.915, -14.2701, 4.26887, 143.277, -1, 0);
				Features::PlaceObjectByHash(2475986526, -85.1736, -833.789, 325.653, -14.4072, -4.26887, 145.777, -1, 0);
				Features::PlaceObjectByHash(2475986526, -83.8118, -835.765, 326.063, -12.243, 4.26887, 151.527, -1, 0);
				Features::PlaceObjectByHash(2475986526, -80.7015, -837.145, 326.059, -12.3172, 2.13443, 162.332, -1, 0);
				Features::PlaceObjectByHash(2475986526, -77.6428, -837.649, 326.163, -10.8391, 3.20165, 171.297, -1, 0);
				Features::PlaceObjectByHash(2475986526, -75.479, -837.909, 326.025, -12.3172, -1.06722, 174.574, -1, 0);
				Features::PlaceObjectByHash(2475986526, -73.861, -837.826, 326.061, -12.3173, 5.33609, -176.632, -1, 0);
				Features::PlaceObjectByHash(2475986526, -70.4799, -837.265, 326.09, -12.3173, -0, -166.182, -1, 0);
				Features::PlaceObjectByHash(2475986526, -67.0415, -836.185, 326.018, -12.3171, -0, -156.039, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.8504, -834.996, 325.951, -11.5263, -0, -145.834, -1, 0);
				Features::PlaceObjectByHash(2475986526, -63.5702, -833.725, 326.1, -11.2947, -0, -140.961, -1, 0);
				Features::PlaceObjectByHash(2475986526, -60.9992, -831.419, 326.075, -11.5262, -4.26887, -130.963, -1, 0);
				Features::PlaceObjectByHash(2475986526, -58.9923, -828.729, 326.116, -11.5262, 4.26887, -121.973, -1, 0);
				Features::PlaceObjectByHash(2475986526, -57.5045, -825.626, 326.114, -11.5263, -0, -110.959, -1, 0);
				Features::PlaceObjectByHash(2475986526, -56.5533, -822.397, 326.08, -11.1311, -6.4033, -102, -1, 0);
				Features::PlaceObjectByHash(2475986526, -56.0911, -820.05, 326.049, -11.0325, 2.13443, -100.794, -1, 0);
				Features::PlaceObjectByHash(2475986526, -56.0681, -818.32, 326.087, -11.1312, -2.66804, -87.9469, -1, 0);
				Features::PlaceObjectByHash(2475986526, -56.2989, -816.237, 326.048, -11.0324, 2.13443, -83.2139, -1, 0);
				Features::PlaceObjectByHash(2475986526, -56.8952, -814.518, 326.142, -11.0324, -2.13443, -76.5476, -1, 0);
				Features::PlaceObjectByHash(2475986526, -58.1209, -811.23, 326.116, -10.9697, -0, -66.7674, -1, 0);
				Features::PlaceObjectByHash(2475986526, -59.0622, -809.17, 326.095, -11.0574, 4.26887, -62.782, -1, 0);
				Features::PlaceObjectByHash(2475986526, -60.096, -807.639, 326.119, -11.5544, -0, -52.7596, -1, 0);
				Features::PlaceObjectByHash(2475986526, -62.081, -805.317, 326.116, -11.1035, -0, -40.7682, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.1466, -804.55, 326.283, -11.1035, -0, -30.477, -1, 0);
				Features::PlaceObjectByHash(2475986526, -67.9795, -798.8, 326.717, -10.1561, -0, -29.3495, -1, 0);
				Features::PlaceObjectByHash(2475986526, -67.5734, -802.52, 326.262, -10.471, -8.53774, -31.2185, -1, 0);
				Features::PlaceObjectByHash(2475986526, -70.9341, -800.541, 326.198, -10.5317, -0, -20.0064, -1, 0);
				Features::PlaceObjectByHash(2475986526, -75.3309, -801.285, 325.849, -10.2407, -0, 1.58401, -1, 0);
				Features::PlaceObjectByHash(2475986526, -74.0222, -799.865, 326.177, -10.7327, -0, -5.98314, -1, 0);
				Features::PlaceObjectByHash(2475986526, -76.5167, -797.998, 326.32, -12.4969, -2.66804, 1.58883, -1, 0);
				Features::PlaceObjectByHash(2475986526, -79.2787, -800.531, 326.011, -12.9433, 4.26887, 13.0054, -1, 0);
				Features::PlaceObjectByHash(2475986526, -81.6721, -801.017, 325.9, -12.4601, 2.13443, 17.3792, -1, 0);
				Features::PlaceObjectByHash(2475986526, -83.6027, -801.744, 325.971, -12.9433, -0, 26.3052, -1, 0);
				Features::PlaceObjectByHash(2475986526, -85.6586, -802.789, 325.95, -12.8791, 1.28066, 32.5856, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.5086, -804.25, 325.978, -12.9432, 4.26887, 42.3279, -1, 0);
				Features::PlaceObjectByHash(2475986526, -88.9923, -805.73, 325.89, -11.9333, -4.26887, 46.0613, -1, 0);
				Features::PlaceObjectByHash(2475986526, -90.167, -807.318, 325.946, -13.0244, -0, 53.178, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.5987, -807.353, 326.343, -11.5713, 4.26887, 60.8753, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.5166, -813.963, 325.942, -13.4341, -4.26887, 73.0256, -1, 0);
				Features::PlaceObjectByHash(2475986526, -92.121, -810.584, 325.996, -13.4339, -4.26887, 64.9353, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.9931, -815.866, 325.924, -13.0519, -0, 79.5966, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.8716, -817.904, 325.988, -13.4339, -0, 88.8361, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.7912, -821.777, 325.946, -13.6946, -2.66804, 91.1427, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.2951, -823.554, 325.966, -13.157, -0, 101.424, -1, 0);
				Features::PlaceObjectByHash(2475986526, -92.5757, -827.033, 325.87, -13.5323, -0, 104.668, -1, 0);
				Features::PlaceObjectByHash(2475986526, -91.53, -828.342, 325.842, -14.1563, 4.26887, 120.328, -1, 0);
				Features::PlaceObjectByHash(2475986526, -90.5203, -829.611, 325.936, -14.1563, -0, 124.573, -1, 0);
				Features::PlaceObjectByHash(2475986526, -95.5355, -833.068, 327.049, -9.63525, 1.70755, 124.512, -1, 0);
				Features::PlaceObjectByHash(2475986526, -94.2445, -835.1, 326.976, -9.27617, -1.28066, 128.396, -1, 0);
				Features::PlaceObjectByHash(2475986526, -92.513, -837.087, 327.008, -9.63523, -4.26887, 132.871, -1, 0);
				Features::PlaceObjectByHash(2475986526, -90.07, -839.341, 327.025, -9.63574, 4.26887, 143.545, -1, 0);
				Features::PlaceObjectByHash(2475986526, -86.7336, -841.135, 327.284, -9.63566, -0, 150.983, -1, 0);
				Features::PlaceObjectByHash(2475986526, -84.8343, -842.167, 327.254, -9.36742, -4.26887, 152.377, -1, 0);
				Features::PlaceObjectByHash(2475986526, -90.0883, -842.661, 327.589, -7.98782, -8.53774, 146.409, -1, 0);
				Features::PlaceObjectByHash(2475986526, -82.595, -843.001, 327.277, -9.6352, -0, 161.654, -1, 0);
				Features::PlaceObjectByHash(2475986526, -80.8027, -843.618, 327.263, -9.36755, -2.13443, 165.215, -1, 0);
				Features::PlaceObjectByHash(2475986526, -78.5619, -843.703, 327.458, -9.63545, -2.13443, 171.015, -1, 0);
				Features::PlaceObjectByHash(2475986526, -76.2479, -844.026, 327.261, -9.36765, 1.06722, 175.986, -1, 0);
				Features::PlaceObjectByHash(2475986526, -73.5382, -843.999, 327.285, -9.6355, -0, -177.212, -1, 0);
				Features::PlaceObjectByHash(2475986526, -71.2047, -843.988, 327.3, -9.36764, -1.06722, -172.013, -1, 0);
				Features::PlaceObjectByHash(2475986526, -69.036, -843.266, 327.309, -9.63525, 4.26887, -166.686, -1, 0);
				Features::PlaceObjectByHash(2475986526, -67.2981, -840.996, 326.756, -9.37509, -2.13443, -159.014, -1, 0);
				Features::PlaceObjectByHash(2475986526, -66.7067, -842.714, 327.222, -9.37501, 2.13443, -159.27, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.5693, -841.792, 327.24, -9.63515, 4.26887, -156.16, -1, 0);
				Features::PlaceObjectByHash(2475986526, -61.8874, -840.436, 327.231, -9.37483, 4.26887, -146.534, -1, 0);
				Features::PlaceObjectByHash(2475986526, -59.7118, -838.501, 327.384, -9.63533, -0, -141.372, -1, 0);
				Features::PlaceObjectByHash(2475986526, -57.9491, -837.16, 327.309, -9.37471, 4.26887, -135.839, -1, 0);
				Features::PlaceObjectByHash(2475986526, -56.3494, -835.471, 327.34, -9.63578, 4.26887, -131.675, -1, 0);
				Features::PlaceObjectByHash(2475986526, -54.9387, -833.93, 327.334, -9.37482, -0, -127.887, -1, 0);
				Features::PlaceObjectByHash(2475986526, -53.727, -832.032, 327.367, -9.63521, -4.26887, -122.142, -1, 0);
				Features::PlaceObjectByHash(2475986526, -52.5928, -830.077, 327.332, -9.37496, -0, -116.843, -1, 0);
				Features::PlaceObjectByHash(2475986526, -51.7552, -827.819, 327.385, -9.63569, 6.4033, -111.077, -1, 0);
				Features::PlaceObjectByHash(2475986526, -51.0061, -825.839, 327.369, -9.37494, 4.26887, -107.054, -1, 0);
				Features::PlaceObjectByHash(2475986526, -50.5468, -823.622, 327.378, -9.63572, 4.26887, -101.598, -1, 0);
				Features::PlaceObjectByHash(2475986526, -50.0992, -820.896, 327.345, -9.47333, -1.06722, -95.7976, -1, 0);
				Features::PlaceObjectByHash(2475986526, -49.9295, -818.102, 327.381, -9.63531, -8.00413, -88.2146, -1, 0);
				Features::PlaceObjectByHash(2475986526, -50.1895, -815.816, 327.358, -9.4734, -0, -82.8649, -1, 0);
				Features::PlaceObjectByHash(2475986526, -50.9164, -813.132, 327.442, -9.63524, 2.13443, -76.865, -1, 0);
				Features::PlaceObjectByHash(2475986526, -51.1585, -811.568, 327.373, -9.58574, -0, -69.3402, -1, 0);
				Features::PlaceObjectByHash(2475986526, -52.0622, -809.533, 327.354, -9.63541, 2.13443, -65.7624, -1, 0);
				Features::PlaceObjectByHash(2475986526, -53.4048, -806.624, 327.376, -9.63526, 2.13443, -65.3971, -1, 0);
				Features::PlaceObjectByHash(2475986526, -55.2978, -803.815, 327.389, -9.63524, 4.26887, -52.2107, -1, 0);
				Features::PlaceObjectByHash(2475986526, -56.5179, -802.266, 327.366, -9.51013, 4.26887, -50.6537, -1, 0);
				Features::PlaceObjectByHash(2475986526, -57.9995, -800.68, 327.42, -9.6353, 1.28066, -41.7027, -1, 0);
				Features::PlaceObjectByHash(2475986526, -61.0278, -799.404, 327.549, -9.63516, 8.53774, -31.016, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.37, -797.284, 327.603, -9.6351, -0, -31.6732, -1, 0);
				Features::PlaceObjectByHash(2475986526, -66.3998, -795.965, 327.526, -9.42422, 8.53773, -29.018, -1, 0);
				Features::PlaceObjectByHash(2475986526, -68.8079, -794.744, 327.535, -9.63558, -2.13443, -20.0341, -1, 0);
				Features::PlaceObjectByHash(2475986526, -72.1225, -793.825, 327.497, -9.57894, -2.13443, -12.2336, -1, 0);
				Features::PlaceObjectByHash(2475986526, -75.6415, -795.169, 327.2, -9.63555, -1.60083, 2.8097, -1, 0);
				Features::PlaceObjectByHash(2475986526, -77.9613, -794.235, 327.223, -8.9769, -5.33608, 4.53814, -1, 0);
				Features::PlaceObjectByHash(2475986526, -75.3695, -789.507, 328.306, -8.84722, -8.33763, -0.0879073, -1, 0);
				Features::PlaceObjectByHash(2475986526, -80.6908, -794.505, 327.217, -9.63537, 4.26887, 13.0745, -1, 0);
				Features::PlaceObjectByHash(2475986526, -83.5673, -795.148, 327.101, -9.92985, 2.13443, 17.5819, -1, 0);
				Features::PlaceObjectByHash(2475986526, -86.3087, -796.203, 327.177, -9.63542, -4.26887, 25.9296, -1, 0);
				Features::PlaceObjectByHash(2475986526, -88.9655, -797.634, 327.118, -9.92994, -4.26887, 33.0571, -1, 0);
				Features::PlaceObjectByHash(2475986526, -91.6251, -799.702, 327.176, -9.63539, -0, 42.2513, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.414, -801.299, 327.124, -9.92995, -0, 48.7085, -1, 0);
				Features::PlaceObjectByHash(2475986526, -95.1453, -803.637, 327.147, -9.63537, -8.53774, 53.6544, -1, 0);
				Features::PlaceObjectByHash(2475986526, -96.5885, -805.701, 327.144, -9.8947, -0, 60.5096, -1, 0);
				Features::PlaceObjectByHash(2475986526, -97.6945, -807.971, 327.174, -9.63569, 4.26887, 64.7568, -1, 0);
				Features::PlaceObjectByHash(2475986526, -98.7075, -809.885, 327.026, -8.13758, -0, 67.8881, -1, 0);
				Features::PlaceObjectByHash(2475986526, -99.394, -812.176, 327.105, -9.63525, -4.26887, 73.0223, -1, 0);
				Features::PlaceObjectByHash(2475986526, -100.025, -814.868, 327.097, -9.97277, 2.13443, 83.1537, -1, 0);
				Features::PlaceObjectByHash(2475986526, -100.012, -817.789, 327.15, -9.63535, -1.33402, 88.8234, -1, 0);
				Features::PlaceObjectByHash(2475986526, -100.069, -819.76, 327.099, -9.95297, -1.33402, 90.8729, -1, 0);
				Features::PlaceObjectByHash(2475986526, -99.969, -821.91, 327.11, -9.63541, -2.66804, 91.5501, -1, 0);
				Features::PlaceObjectByHash(2475986526, -99.3358, -824.801, 327.138, -9.63539, 2.13443, 101.678, -1, 0);
				Features::PlaceObjectByHash(2475986526, -98.5443, -828.598, 327.033, -9.63553, -0, 104.64, -1, 0);
				Features::PlaceObjectByHash(2475986526, -97.0896, -831.054, 326.937, -10.0741, 4.26887, 118.72, -1, 0);
				Features::PlaceObjectByHash(2475986526, -102.435, -833.952, 328.506, -5.26399, -0, 118.502, -1, 0);
				Features::PlaceObjectByHash(2475986526, -103.536, -831.932, 328.513, -5.42142, 4.26887, 111.099, -1, 0);
				Features::PlaceObjectByHash(2475986526, -100.644, -836.571, 328.636, -5.26398, -0, 124.006, -1, 0);
				Features::PlaceObjectByHash(2475986526, -99.0448, -838.912, 328.589, -5.26395, -2.13443, 128.175, -1, 0);
				Features::PlaceObjectByHash(2475986526, -96.9401, -841.184, 328.589, -5.26384, -2.13443, 132.615, -1, 0);
				Features::PlaceObjectByHash(2475986526, -95.4409, -842.718, 328.551, -5.01006, -2.13443, 136.57, -1, 0);
				Features::PlaceObjectByHash(2475986526, -93.6584, -844.231, 328.606, -5.26388, -0, 143.429, -1, 0);
				Features::PlaceObjectByHash(2475986526, -92.1044, -845.82, 328.655, -5.01307, -2.13443, 147.428, -1, 0);
				Features::PlaceObjectByHash(2475986526, -89.6061, -846.328, 328.851, -5.26389, -0, 150.62, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.5884, -847.552, 328.829, -5.6777, -0, 153.36, -1, 0);
				Features::PlaceObjectByHash(2475986526, -84.5215, -848.802, 328.867, -5.26405, 5.33608, 161.164, -1, 0);
				Features::PlaceObjectByHash(2475986526, -81.9779, -849.605, 328.821, -5.67769, 1.06722, 166.961, -1, 0);
				Features::PlaceObjectByHash(2475986526, -79.5282, -849.717, 329.046, -5.26392, 1.06722, 170.517, -1, 0);
				Features::PlaceObjectByHash(2475986526, -76.7555, -850.113, 328.885, -4.93224, 2.66804, 175.995, -1, 0);
				Features::PlaceObjectByHash(2475986526, -73.2336, -850.06, 328.883, -5.26397, -0, -177.431, -1, 0);
				Features::PlaceObjectByHash(2475986526, -70.4067, -849.836, 328.854, -4.82287, -5.33608, -172.2, -1, 0);
				Features::PlaceObjectByHash(2475986526, -67.6252, -849.166, 328.911, -5.26394, -0, -166.741, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.6525, -848.331, 328.792, -4.82267, -2.13443, -160.74, -1, 0);
				Features::PlaceObjectByHash(2475986526, -62.1086, -847.355, 328.837, -5.26389, 2.13443, -156.346, -1, 0);
				Features::PlaceObjectByHash(2475986526, -60.2755, -846.895, 328.808, -5.97307, -2.13443, -151.031, -1, 0);
				Features::PlaceObjectByHash(2475986526, -58.5152, -845.543, 328.833, -5.26392, 1.06722, -147.129, -1, 0);
				Features::PlaceObjectByHash(2475986526, -55.9339, -843.258, 328.987, -5.26394, 2.13443, -141.8, -1, 0);
				Features::PlaceObjectByHash(2475986526, -53.6636, -841.564, 328.905, -5.18348, -0, -136.192, -1, 0);
				Features::PlaceObjectByHash(2475986526, -51.8013, -839.526, 328.926, -5.26393, -2.13443, -131.788, -1, 0);
				Features::PlaceObjectByHash(2475986526, -49.9112, -837.51, 328.916, -5.18352, -8.53774, -125.894, -1, 0);
				Features::PlaceObjectByHash(2475986526, -48.5833, -835.261, 328.968, -5.26388, 2.13443, -122.598, -1, 0);
				Features::PlaceObjectByHash(2475986526, -47.1369, -832.806, 328.936, -5.18352, -0, -117.146, -1, 0);
				Features::PlaceObjectByHash(2475986526, -46.1092, -830.019, 328.985, -5.26389, -0, -111.097, -1, 0);
				Features::PlaceObjectByHash(2475986526, -45.2549, -827.659, 328.957, -5.18353, -1.06722, -105.915, -1, 0);
				Features::PlaceObjectByHash(2475986526, -44.5598, -824.856, 328.973, -5.26387, -0, -101.582, -1, 0);
				Features::PlaceObjectByHash(2475986526, -44.0346, -821.522, 328.953, -5.26387, 5.33608, -95.978, -1, 0);
				Features::PlaceObjectByHash(2475986526, -43.8673, -817.92, 328.98, -5.26387, -4.00206, -88.1556, -1, 0);
				Features::PlaceObjectByHash(2475986526, -44.1983, -815.072, 328.956, -5.26387, -0, -82.8806, -1, 0);
				Features::PlaceObjectByHash(2475986526, -45.0463, -811.788, 329.021, -5.26392, -0, -77.2513, -1, 0);
				Features::PlaceObjectByHash(2475986526, -45.6154, -809.566, 328.95, -5.25705, -2.13443, -72.2094, -1, 0);
				Features::PlaceObjectByHash(2475986526, -46.5685, -807.149, 328.929, -5.26395, -2.13443, -66.9958, -1, 0);
				Features::PlaceObjectByHash(2475986526, -47.9752, -804.122, 328.959, -5.26398, -0, -65.1505, -1, 0);
				Features::PlaceObjectByHash(2475986526, -49.0785, -802.078, 328.914, -5.31539, 4.26887, -57.7224, -1, 0);
				Features::PlaceObjectByHash(2475986526, -50.5092, -800.141, 328.99, -5.26406, -0, -52.4683, -1, 0);
				Features::PlaceObjectByHash(2475986526, -52.041, -798.134, 329.001, -5.31536, -2.13443, -49.2493, -1, 0);
				Features::PlaceObjectByHash(2475986526, -53.8808, -796.134, 329.041, -5.26389, -0, -42.3308, -1, 0);
				Features::PlaceObjectByHash(2475986526, -55.4375, -794.682, 329.045, -5.32055, 2.13443, -37.3601, -1, 0);
				Features::PlaceObjectByHash(2475986526, -57.7537, -794.2, 329.16, -5.26393, 2.13443, -32.2267, -1, 0);
				Features::PlaceObjectByHash(2475986526, -61.0299, -792.042, 329.172, -5.26389, -2.13443, -32.1174, -1, 0);
				Features::PlaceObjectByHash(2475986526, -63.5163, -790.736, 329.085, -5.04535, -4.26887, -29.2933, -1, 0);
				Features::PlaceObjectByHash(2475986526, -64.7324, -789.882, 329.081, -4.987, -2.13443, -27.7917, -1, 0);
				Features::PlaceObjectByHash(2475986526, -66.7775, -788.94, 329.155, -5.04558, 1.06722, -19.5666, -1, 0);
				Features::PlaceObjectByHash(2475986526, -68.6555, -788.272, 329.103, -5.30654, 3.20165, -16.9146, -1, 0);
				Features::PlaceObjectByHash(2475986526, -70.8259, -787.837, 329.128, -5.04546, 1.06722, -12.2941, -1, 0);
				Features::PlaceObjectByHash(2475986526, -74.5572, -787.022, 329.08, -4.61724, 1.06722, -10.7316, -1, 0);
				Features::PlaceObjectByHash(2475986526, -75.8754, -788.646, 328.671, -6.78921, -0, 2.98721, -1, 0);
				Features::PlaceObjectByHash(2475986526, -78.4, -788.132, 328.83, -5.91899, 2.66804, 3.75875, -1, 0);
				Features::PlaceObjectByHash(2475986526, -80.5351, -788.179, 328.782, -5.80051, -0, 7.26539, -1, 0);
				Features::PlaceObjectByHash(2475986526, -82.1189, -788.558, 328.793, -5.9192, 1.06722, 12.7168, -1, 0);
				Features::PlaceObjectByHash(2475986526, -85.4054, -789.317, 328.666, -5.79433, -0, 17.1877, -1, 0);
				Features::PlaceObjectByHash(2475986526, -87.4651, -789.98, 328.647, -5.63204, -0, 20.2315, -1, 0);
				Features::PlaceObjectByHash(2475986526, -88.9795, -790.697, 328.76, -5.79416, -0, 25.9501, -1, 0);
				Features::PlaceObjectByHash(2475986526, -90.9922, -791.487, 328.684, -6.26149, -0, 27.0819, -1, 0);
				Features::PlaceObjectByHash(2475986526, -92.3298, -792.474, 328.677, -5.79412, -0, 33.3113, -1, 0);
				Features::PlaceObjectByHash(2475986526, -94.2322, -793.73, 328.669, -5.58479, -2.13443, 37.4974, -1, 0);
				Features::PlaceObjectByHash(2475986526, -95.7282, -795.2, 328.764, -5.79431, -0, 41.8672, -1, 0);
				Features::PlaceObjectByHash(2475986526, -97.9782, -797.316, 328.695, -5.58488, -0, 48.9171, -1, 0);
				Features::PlaceObjectByHash(2475986526, -100.042, -800.063, 328.731, -5.79425, 2.13443, 53.7039, -1, 0);
				Features::PlaceObjectByHash(2475986526, -101.884, -802.718, 328.706, -5.5848, 2.13443, 60.3613, -1, 0);
				Features::PlaceObjectByHash(2475986526, -103.09, -805.421, 328.718, -5.79425, -0, 64.506, -1, 0);
				Features::PlaceObjectByHash(2475986526, -104.284, -807.711, 328.691, -5.58488, -2.13443, 65.966, -1, 0);
				Features::PlaceObjectByHash(2475986526, -105.262, -810.369, 328.729, -5.26384, 1.06722, 73.2414, -1, 0);
				Features::PlaceObjectByHash(2475986526, -105.769, -812.146, 328.645, -5.25205, -1.06722, 75.8091, -1, 0);
				Features::PlaceObjectByHash(2475986526, -106.155, -814.128, 328.687, -5.26388, -1.06722, 82.8157, -1, 0);
				Features::PlaceObjectByHash(2475986526, -106.062, -817.685, 328.758, -5.26388, 2.66804, 88.7458, -1, 0);
				Features::PlaceObjectByHash(2475986526, -106.154, -819.723, 328.716, -5.25204, -0, 90.1628, -1, 0);
				Features::PlaceObjectByHash(2475986526, -106.082, -822.072, 328.729, -5.26387, -1.33402, 91.2972, -1, 0);
				Features::PlaceObjectByHash(2475986526, -105.911, -823.815, 328.7, -5.52135, 5.33608, 99.4393, -1, 0);
				Features::PlaceObjectByHash(2475986526, -105.28, -826.029, 328.734, -5.26391, 1.06722, 101.615, -1, 0);
				Features::PlaceObjectByHash(2475986526, -105.06, -827.904, 328.644, -5.29978, 1.06722, 102.515, -1, 0);
				Features::PlaceObjectByHash(2475986526, -104.327, -830.112, 328.614, -5.26391, -2.13443, 104.719, -1, 0);
				Features::PlaceObjectByHash(3291218330, -108.551, -853.416, 327.387, 2.94456, 89.1111, -166.155, -1, 0);
				Features::PlaceObjectByHash(3291218330, -80.2509, -866.418, 327.301, 3.7405, 89.3, 146.641, -1, 0);
				Features::PlaceObjectByHash(3291218330, -55.8513, -863.921, 327.333, 6.87468, 89.6184, 149.776, -1, 0);
				Features::PlaceObjectByHash(3291218330, -37.3907, -848.122, 327.717, 2.33633, 88.8797, -16.2595, -1, 0);
				Features::PlaceObjectByHash(3291218330, -26.1908, -818.332, 328.76, 0.490556, 84.6598, -18.107, -1, 0);
				Features::PlaceObjectByHash(3291218330, -37.891, -789.138, 328.134, 1.11673, 87.6571, 42.7186, -1, 0);
				Features::PlaceObjectByHash(3291218330, -63.492, -772.044, 327.866, 3.09962, 89.1556, 44.702, -1, 0);
				Features::PlaceObjectByHash(3291218330, -93.4916, -774.848, 327.398, 2.73771, 89.0443, 122.539, -1, 0);
				Features::PlaceObjectByHash(3291218330, -115.991, -795.259, 327.27, 3.28432, 89.2033, 123.086, -1, 0);
				Features::PlaceObjectByHash(3291218330, -122.551, -825.074, 327.213, 173.37, 89.6048, 4.27077, -1, 0);
				Features::PlaceObjectByHash(118627012, -74.8438, -819.617, 323.685, 0, 0, -3.37511, -1, 0);
				Features::PlaceObjectByHash(2475986526, -67.6253, -820.244, 323.793, -14.4263, -8.53774, -100.02, -1, 0);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}
			break;
#pragma region mapmode
		case ramp2:
			Menu::Title("Maze Bank Roof Ramp");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(1600026313, -78.4864, -807.943, 323.202, 109.364, -89.9209, 0, -1, 1);
				Features::PlaceObjectByHash(1600026313, -79.2766, -805.701, 323.204, 109.364, -89.9209, 0, -1, 1);
				Features::PlaceObjectByHash(1600026313, -79.8373, -803.709, 323.205, 109.364, -89.9209, 0, -1, 1);
				Features::PlaceObjectByHash(1600026313, -80.4295, -801.947, 323.207, 109.364, -89.9209, 0, -1, 1);
				Features::PlaceObjectByHash(4143853297, -97.4731, -778.557, 308.877, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(1087520462, -84.2429, -793.182, 321.08, -63.5625, -0, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -83.5429, -795.106, 322.073, -63.5625, -0, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -84.9429, -791.108, 319.956, -62.6673, 8.53774e-007, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -85.8122, -788.585, 318.638, -63.5625, -0, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -89.1589, -779.487, 313.336, -59.5389, 0.0405551, -160.567, -1, 1);
				Features::PlaceObjectByHash(1087520462, -90.7065, -774.863, 310.09, -57.4959, 0.322988, -160.758, -1, 1);
				Features::PlaceObjectByHash(1087520462, -91.4887, -772.564, 308.403, -55.1692, 0.383369, -161.049, -1, 1);
				Features::PlaceObjectByHash(1087520462, -91.7565, -771.74, 307.844, -56.4466, 0.0442451, -160.565, -1, 1);
				Features::PlaceObjectByHash(1087520462, -93.6941, -766.245, 302.736, -45.9996, 0.0556114, -160.556, -1, 1);
				Features::PlaceObjectByHash(1087520462, -94.2969, -764.648, 301.067, -44.7623, -1.70755e-006, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -94.2969, -764.648, 301.067, -44.7623, -1.70755e-006, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -94.886, -762.996, 298.741, -36.7051, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -95.4855, -761.334, 296.406, -36.7051, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -95.4855, -761.334, 296.406, -36.7051, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -96.1606, -759.499, 294.259, -42.0766, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.709, -36.7051, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.709, -36.7051, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.46, -36.7051, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -96.8807, -757.391, 292.506, -51.0291, -8.53774e-007, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -96.8807, -757.391, 292.506, -51.0291, -8.53774e-007, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -97.3203, -756.159, 291.688, -57.2958, -0, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -97.9597, -754.358, 290.78, -62.6673, 8.53774e-007, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -97.9597, -754.358, 290.78, -62.6673, 8.53774e-007, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -98.7192, -752.356, 290.042, -69.9278, 3.20165e-005, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -99.0244, -751.684, 290.499, -90, -8.46346e-007, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -99.3223, -750.534, 290.479, -90, -8.46346e-007, -160.249, -1, 1);
				Features::PlaceObjectByHash(1087520462, -100.348, -747.881, 290.452, -89.5256, -1.33402e-008, -159.354, -1, 1);
				Features::PlaceObjectByHash(1087520462, -100.26, -748.154, 290.462, -76.096, 4.26887e-007, 19.6954, -1, 1);
				Features::PlaceObjectByHash(1087520462, -100.687, -747.053, 290.731, -62.6673, -8.53774e-007, 20.5907, -1, 1);
				Features::PlaceObjectByHash(1087520462, -101.346, -745.387, 291.611, -58.191, 1.70755e-006, 19.6954, -1, 1);
				Features::PlaceObjectByHash(1087520462, -102.234, -743.119, 293.091, -52.2249, 0.00051141, 21.3426, -1, 1);
				Features::PlaceObjectByHash(2475986526, -102.154, -739.285, 294.83, 9.80014, 0.295618, 18.7802, -1, 1);
				Features::PlaceObjectByHash(2475986526, -105.054, -740.282, 294.827, 9.80014, 0.295618, 18.7802, -1, 1);
				Features::PlaceObjectByHash(1087520462, -103.071, -741.047, 294.832, -48.0666, 0.000519094, 21.3419, -1, 1);
				Features::PlaceObjectByHash(1087520462, -103.75, -739.405, 296.413, -45.1472, 0.000547269, 21.3416, -1, 1);
				Features::PlaceObjectByHash(4143853297, -90.3515, -798.112, 319.893, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -93.2293, -790.348, 317.189, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -95.3479, -784.483, 313.696, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -100.01, -771.31, 304.367, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -101.829, -766.277, 299.666, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -103.318, -762.175, 293.966, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -104.948, -757.681, 288.866, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -108.146, -748.798, 288.866, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -108.146, -748.798, 295.608, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -108.225, -748.694, 302.608, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(3167053133, -103.451, -740.541, 307.317, -0.900199, -1.19985, 20.9076, -1, 1);
				Features::PlaceObjectByHash(2375650849, -102.454, -742.6, 309.309, 0, 0, 20.9393, -1, 1);
				Features::PlaceObjectByHash(4143853297, -101.483, -746.044, 305.602, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -94.7458, -743.402, 295.608, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -94.7566, -743.406, 288.866, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -94.7426, -743.595, 302.651, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(1157292806, -99.7732, -750.516, 309.575, 0, 0, 24.1761, -1, 1);
				Features::PlaceObjectByHash(4143853297, -89.9785, -756.476, 293.966, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -91.5378, -752.285, 288.866, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -87.9094, -762.07, 299.666, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -86.2094, -766.939, 304.367, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -84.0215, -772.971, 309.575, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -81.6733, -779.348, 313.696, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -79.5187, -785.083, 317.189, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(4143853297, -76.5616, -793.191, 319.493, 0, -0, -159.831, -1, 1);
				Features::PlaceObjectByHash(1998517203, -81.0993, -790.139, 326.57, 0, 0, -82.6177, -1, 1);
				Features::PlaceObjectByHash(1998517203, -88.8988, -792.911, 326.95, 0, 0, -82.6177, -1, 1);
				Features::PlaceObjectByHash(803874239, -88.3376, -794.173, 327.042, 0, 0, 31.5501, -1, 1);
				Features::PlaceObjectByHash(803874239, -90.0376, -795.174, 327.262, 0, 0, 31.5501, -1, 1);
				Features::PlaceObjectByHash(803874239, -91.6375, -796.175, 327.482, 0, 0, 31.5501, -1, 1);
				Features::PlaceObjectByHash(803874239, -79.0283, -791.31, 326.763, 0, -0, 100.953, -1, 1);
				Features::PlaceObjectByHash(803874239, -76.8377, -790.87, 326.823, 0, -0, 100.953, -1, 1);
				Features::PlaceObjectByHash(803874239, -81.0088, -791.22, 326.713, 0, -0, 100.953, -1, 1);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}
			break;
#pragma region mapmode
		case ramp3:
			Menu::Title("Beach Ferris-Ramp");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(1952396163, -1497.76, -1113.84, -3.08, -90, 6.14715e-007, 165.792, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1461.92, -1216.88, 2.5836, -2.3048, -0, -154.878, -1, 2);
				Features::PlaceObjectByHash(3291218330, -1465.62, -1217.64, 18, 166.516, -5.12264e-006, 24.1717, -1, 2);
				Features::PlaceObjectByHash(3291218330, -1458.89, -1214.4, 18, -38.4956, 8.53774e-007, -153.982, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1460.32, -1219.97, 4.3801, 12.6953, -0, -154.878, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1457, -1226.67, 11.8772, 31.7229, -0, -154.382, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1458.4, -1223.77, 7.9937, 23.6001, -0.0916355, -154.918, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1456.4, -1228.27, 14.9608, 48.674, -0, -153.982, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1456, -1229.07, 19.7441, 68.6628, -0, -153.982, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1456.2, -1228.47, 24.8276, 82.6252, 3.80938, -152.828, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1456.9, -1226.47, 28.9111, 108.498, -8.51368, -157.244, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1458.59, -1223.37, 31.5945, 130.616, -4.72983, -155.087, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1460.59, -1218.38, 33.5779, 143.744, -3.95611, -152.581, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1462.79, -1214.28, 34.161, 163.63, -2.68302, -155.763, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, 4.69576e-006, -152.192, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, 4.69576e-006, -152.192, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1466.9, -1205.68, 29.0062, -155.178, 9.47689e-005, -153.087, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1468.3, -1202.98, 24.1897, -131.11, 6.74481e-005, -153.088, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1468.59, -1202.68, 19.3732, -107.429, 3.07358e-005, -153.087, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1467.99, -1203.88, 13.5732, -89.6528, -0.153235, -155.853, -1, 2);
				Features::PlaceObjectByHash(2475986526, -1467.11, -1205.68, 10.7072, -63.5491, 8.53774e-007, -156.504, -1, 2);
				Features::PlaceObjectByHash(4109455646, -1465.05, -1210.03, 7.9503, 9.53319, 1.38057, 24.2606, -1, 2);
				Features::PlaceObjectByHash(2975320548, -1460.95, -1218.79, 7.66, -29.9323, -0.173323, 24.7221, -1, 2);
				Features::PlaceObjectByHash(2975320548, -1463.05, -1214.19, 6.7879, -6.50192, 1.391, 24.2651, -1, 2);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1513.0f, -1192.0f, 1.0f, 1, 0, 0, 1);
			}
			break;
#pragma region mapmode
		case ramp4:
			Menu::Title("Mount Chilliad Ramp");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(1952396163, -1497.76, -1113.84, -3.08, -90, -0, 165.792, 90, 3);
				Features::PlaceObjectByHash(2475986526, -1461.92, -1216.88, 2.5836, -2.3048, 0, -154.878, 205.14, 3);
				Features::PlaceObjectByHash(3291218330, -1458.89, -1214.4, 18, -38.4956, 0, -153.982, 211.95, 3);
				Features::PlaceObjectByHash(2475986526, -1460.32, -1219.97, 4.3801, 12.6953, 0, -154.878, 205.672, 3);
				Features::PlaceObjectByHash(2975320548, -1463.05, -1214.19, 6.7879, -6.5, -1.391, 24.2651, 24.4244, 3);
				Features::PlaceObjectByHash(3291218330, -1465.62, -1217.64, 18, 166.516, 180, 24.1717, 155.224, 3);
				Features::PlaceObjectByHash(4109455646, -1465.05, -1210.03, 7.9503, 9.5304, -1.3806, 24.2606, 24.5148, 3);
				Features::PlaceObjectByHash(2975320548, -1460.95, -1218.79, 7.66, -29.9322, 0.1733, 24.7221, 27.9617, 3);
				Features::PlaceObjectByHash(2475986526, -1458.4, -1223.77, 7.9937, 23.6001, 0.0916, -154.918, 207.065, 3);
				Features::PlaceObjectByHash(2475986526, -1467.11, -1205.68, 10.7072, -63.5491, 0, -156.505, 224.303, 3);
				Features::PlaceObjectByHash(2475986526, -1457, -1226.67, 11.8772, 31.7229, 0, -154.382, 209.411, 3);
				Features::PlaceObjectByHash(2475986526, -1456.4, -1228.27, 14.9608, 48.674, 0, -153.982, 216.471, 3);
				Features::PlaceObjectByHash(2475986526, -1456, -1229.07, 19.7441, 68.6628, 0, -153.982, 233.298, 3);
				Features::PlaceObjectByHash(2475986526, -1456.2, -1228.47, 24.8276, 81.7043, -3.8094, -152.828, 252.429, 3);
				Features::PlaceObjectByHash(2475986526, -1456.9, -1226.47, 28.9111, 110.301, 171.486, -157.244, 312.201, 3);
				Features::PlaceObjectByHash(2475986526, -1458.59, -1223.37, 31.5945, 130.843, 175.27, -155.087, 325.759, 3);
				Features::PlaceObjectByHash(2475986526, -1460.59, -1218.38, 33.5779, 143.844, 176.044, -152.581, 327.979, 3);
				Features::PlaceObjectByHash(2475986526, -1462.79, -1214.28, 34.161, 163.648, 177.317, -155.763, 335.024, 3);
				Features::PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, -180, -152.192, 331.971, 3);
				Features::PlaceObjectByHash(2475986526, -1466.9, -1205.68, 29.0062, -155.178, -180, -153.087, 330.783, 3);
				Features::PlaceObjectByHash(2475986526, -1468.3, -1202.98, 24.1897, -131.11, -180, -153.088, 322.332, 3);
				Features::PlaceObjectByHash(2475986526, -1468.59, -1202.68, 19.3732, -107.429, -180, -153.087, 300.544, 3);
				Features::PlaceObjectByHash(2475986526, -1467.99, -1203.88, 13.5732, -89.6205, 0.1532, -155.853, 269.072, 3);
				Features::PlaceObjectByHash(3966705493, 509.842, 5589.24, 791.066, 0.141, 0, 65.3998, 65.3999, 3);
				Features::PlaceObjectByHash(3966705493, 520.5, 5584.38, 790.503, 5.441, 0, 65.3998, 65.4976, 3);
				Features::PlaceObjectByHash(3966705493, 531.057, 5579.54, 788.691, 12.441, 0, 65.3998, 65.9111, 3);
				Features::PlaceObjectByHash(3966705493, 568.672, 5562.32, 767.428, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 576.972, 5558.53, 759.566, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 560.174, 5566.2, 774.698, 35.0403, 0, 65.3998, 69.4512, 3);
				Features::PlaceObjectByHash(3966705493, 541.325, 5574.84, 785.49, 19.4409, 0, 65.3998, 66.6484, 3);
				Features::PlaceObjectByHash(3966705493, 551.066, 5570.37, 780.799, 27.5407, 0, 65.3998, 67.9049, 3);
				Features::PlaceObjectByHash(3966705493, 585.249, 5554.75, 751.745, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 618.334, 5539.62, 720.386, 40.7936, 0, 65.3998, 70.8829, 3);
				Features::PlaceObjectByHash(3966705493, 626.602, 5535.85, 712.547, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 610.065, 5543.4, 728.217, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 601.777, 5547.19, 736.076, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 593.507, 5550.97, 743.917, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 634.862, 5532.07, 704.725, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 643.121, 5528.29, 696.894, 40.7936, 0, 65.3998, 70.8829, 3);
				Features::PlaceObjectByHash(3966705493, 651.391, 5524.51, 689.053, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 659.651, 5520.73, 681.221, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 667.911, 5516.94, 673.389, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 676.171, 5513.17, 665.558, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 684.431, 5509.38, 657.727, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 692.691, 5505.61, 649.905, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 700.95, 5501.83, 642.074, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 709.22, 5498.05, 634.243, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 717.46, 5494.28, 626.431, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 725.72, 5490.5, 618.6, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 733.98, 5486.72, 610.778, 40.7396, 0, 65.3998, 70.8685, 3);
				Features::PlaceObjectByHash(3966705493, 742.6, 5482.78, 603.167, 36.9395, 0, 65.3998, 69.9005, 3);
				Features::PlaceObjectByHash(3966705493, 751.83, 5478.55, 596.335, 31.0392, 0, 65.3998, 68.5807, 3);
				Features::PlaceObjectByHash(3966705493, 761.71, 5474.02, 590.613, 24.5989, 0, 65.3998, 67.3986, 3);
				Features::PlaceObjectByHash(3966705493, 772.07, 5469.28, 586.08, 18.9288, 0, 65.3998, 66.5835, 3);
				Features::PlaceObjectByHash(3966705493, 782.84, 5464.34, 582.86, 11.5788, 0, 65.3998, 65.8427, 3);
				Features::PlaceObjectByHash(3966705493, 793.89, 5459.28, 581.117, 5.0787, 0, 65.3998, 65.485, 3);
				Features::PlaceObjectByHash(3966705493, 805.1, 5454.15, 580.876, -2.5212, 0, 65.3998, 65.4208, 3);
				Features::PlaceObjectByHash(3966705493, 816.17, 5449.08, 581.975, -7.6213, 0, 65.3998, 65.5917, 3);
				Features::PlaceObjectByHash(3966705493, 827.191, 5444.04, 584.582, -16.6212, 0, 65.3998, 66.3125, 3);
				Features::PlaceObjectByHash(3966705493, 837.681, 5439.24, 588.899, -24.421, 0, 65.3998, 67.3698, 3);
				Features::PlaceObjectByHash(2580877897, 522.61, 5584.49, 779.214, 79.7153, -9.2252, 55.7018, 77.7612, 3);
				Features::PlaceObjectByHash(3862788492, 522.445, 5583.69, 779.551, -0.9197, -69.229, -167.468, 184.555, 3);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 500, 5593, 795, 1, 0, 0, 1);
			}

			break;
#pragma region mapmode
		case ramp5:
			Menu::Title("Airport Mini Ramp");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(2475986526, -1242.08, -2931.15, 12.9924, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				Features::PlaceObjectByHash(2475986526, -1247.11, -2928.46, 15.013, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				Features::PlaceObjectByHash(2475986526, -1251.58, -2926.05, 16.7865, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				Features::PlaceObjectByHash(2475986526, -1254.69, -2924.35, 18.25, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1276.69, -2912.99, 23.0019, 0, 0.05, 60.9705, -1, 4);
				Features::PlaceObjectByHash(2475986526, -1258.35, -2922.28, 20.2135, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1270.89, -2916.22, 23.0123, 0, 0, 60.8909, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1270.25, -2914.99, 23.0137, 0, 0, 60.8909, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1274.87, -2909.4, 23.0049, 0, 0.05, 60.9705, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1269.01, -2912.64, 22.9993, 0, 0.05, 60.9705, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1267.87, -2915.44, 28.3632, 0, -0, 147.299, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1272.13, -2918.33, 28.4791, 0, 0.05, 60.9705, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1272.11, -2918.35, 25.6708, -0.48, 0.0499982, 60.9701, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1277.93, -2915.14, 25.604, 0, 0.05, 60.9705, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1279.69, -2909.85, 25.6358, 0, -0, -151.239, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1279.69, -2909.85, 28.4844, 0, -0, -151.239, -1, 4);
				Features::PlaceObjectByHash(2475986526, -1261.82, -2920.38, 21.767, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1273.65, -2907.11, 22.9763, 0, 0.05, 60.9705, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1267.77, -2910.37, 22.9978, 0, 0.05, 60.9705, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1266.49, -2908.08, 22.9987, 0, -0, -119.462, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1265.15, -2905.8, 23.0042, 0, -0, -119.462, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1266.44, -2905.21, 25.6255, 0, -0, -118.761, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1265.66, -2911.99, 25.6968, 0, 0, -30.9603, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1264.88, -2910.66, 25.6982, 0, 0, -30.9603, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1264.84, -2905.14, 25.624, 0, -0, -118.761, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1272.37, -2900.96, 25.6199, 0, -0, -118.761, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1276.35, -2903.91, 25.6214, 0, -0, -151.239, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1276.35, -2903.91, 28.4329, 0, -0, -151.239, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1272.37, -2900.96, 28.4385, 0, -0, -118.761, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1266.44, -2905.21, 28.437, 0, -0, -118.761, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1265.17, -2905.14, 28.3426, 0, -0, -118.861, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1271.09, -2902.58, 23.0057, 0, -0, -119.462, -1, 4);
				Features::PlaceObjectByHash(3966705493, -1272.37, -2904.83, 22.9972, 0, -0, -119.462, -1, 4);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1208, -2950, 13, 1, 0, 0, 1);
			}

			break;
#pragma region mapmode
		case ramp6:
			Menu::Title("Airport Gate Ramp");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(2475986526, -1098.36, -2631.17, 19, 0, -0, 152.671, -1, 5);
				Features::PlaceObjectByHash(2475986526, -1100.26, -2634.64, 21.1976, 16.2002, 0.192059, 150.427, -1, 5);
				Features::PlaceObjectByHash(2475986526, -1102.26, -2638.02, 25.01, 26.7003, 0.178675, 149.261, -1, 5);
				Features::PlaceObjectByHash(2475986526, -1103.96, -2640.91, 29.04, 28.3717, -0, 146.82, -1, 5);
				Features::PlaceObjectByHash(1952396163, -1119.61, -2670.96, -5.125, 0, -0, 150.514, -1, 5);
				Features::PlaceObjectByHash(1952396163, -1119.61, -2670.96, -5.125, 0, -0, 150.401, -1, 5);
				Features::PlaceObjectByHash(3137065507, -1044.69, -2530.08, 20.4011, 94.8962, 4.26887e-007, 147.716, -1, 5);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1046, -2538, 20, 1, 0, 0, 1);
			}

			break;
#pragma region mapmode
		case ramp7:
			Menu::Title("UFO Tower");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 654.365, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 646.186, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 638.008, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 629.829, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 621.65, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 613.471, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 605.292, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 597.114, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 588.935, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 580.756, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 572.577, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 564.399, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 556.22, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 662.544, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 548.041, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 539.862, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 531.683, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 523.505, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 515.326, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 507.147, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 498.968, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 490.79, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 482.611, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 474.432, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 466.253, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 458.074, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 449.896, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 441.717, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 433.538, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 425.359, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 417.18, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 409.001, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 400.823, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 392.644, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 384.465, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 376.286, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 368.107, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 359.929, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 351.75, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 343.571, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 335.392, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 327.213, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 319.035, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 310.856, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 302.677, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 294.498, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 286.319, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 278.141, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 269.962, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 261.783, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 253.604, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 245.425, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 237.247, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 229.068, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 220.889, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 212.71, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 204.531, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 196.353, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 188.174, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 179.995, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 171.816, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 163.637, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 155.459, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 147.28, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 139.101, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 130.922, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 122.743, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 114.565, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 106.386, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 98.207, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 90.0282, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 81.8494, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 73.6706, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 65.4918, 0.660085, -0.919939, -109.32, -1, 6);
				Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 57.313, 0.660085, -0.919939, -109.32, -1, 6);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 70, -674, 680, 1, 0, 0, 1);
			}
			break;
#pragma region mapmode
		case ramp8:
			Menu::Title("Maze Bank Quad Ramp");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(3522933110, -81.3886, -814.648, 325.169, 0, -0, 180, -1, 7);
				Features::PlaceObjectByHash(3681122061, -81.7456, -809.064, 324.799, 0.500021, 2.66804, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -86.1333, -802.279, 321.92, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -89.7406, -796.701, 316.539, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -93.601, -790.725, 310.777, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -97.4741, -784.73, 304.997, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -101.373, -778.696, 299.179, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -105.233, -772.72, 293.417, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -109.106, -766.725, 287.637, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -112.954, -760.769, 281.894, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -116.827, -754.773, 276.113, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -120.687, -748.798, 270.352, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -124.518, -742.868, 264.636, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -128.358, -736.925, 258.909, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -132.22, -730.949, 253.151, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -136.081, -724.974, 247.394, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -139.943, -718.998, 241.636, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -143.826, -712.99, 235.846, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -147.667, -707.047, 230.12, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -151.508, -701.104, 224.394, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -155.369, -695.128, 218.636, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -159.252, -689.12, 212.846, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -163.072, -683.209, 207.152, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -166.976, -677.168, 201.331, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -170.838, -671.193, 195.573, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -174.7, -665.217, 189.815, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -178.583, -659.209, 184.026, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -182.444, -653.233, 178.268, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -186.327, -647.225, 172.479, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -190.189, -641.249, 166.721, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -194.03, -635.306, 160.994, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -197.871, -629.363, 155.268, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -201.711, -623.42, 149.542, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -205.552, -617.477, 143.815, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -209.393, -611.534, 138.089, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -213.255, -605.559, 132.331, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -217.095, -599.616, 126.605, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -220.957, -593.64, 120.847, -38.9999, -1.45141, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -222.245, -591.648, 118.928, -33.8999, 1.02453, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -223.349, -589.94, 117.561, -29.31, 1.79292, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -224.58, -588.036, 116.288, -26.25, 5.12264, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -225.869, -586.04, 115.116, -24.7199, -1.10991, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -227.127, -584.095, 114.05, -21.6599, 1.8783, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -228.615, -581.794, 112.961, -19.6199, 1.02453, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -230.201, -579.341, 111.92, -17.0699, -0, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -232.121, -576.369, 110.833, -12.9899, 4.26887, 32.8808, -1, 7);
				Features::PlaceObjectByHash(3681122061, -234.105, -573.302, 109.991, -9.9299, -2.98821, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -236.628, -569.396, 109.329, -7.3799, -4.26887, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -239.81, -564.475, 108.721, -4.3199, 1.28066, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -241.76, -561.459, 108.549, -0.7499, -1.12058, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -244.04, -557.932, 108.494, 2.82011, -2.77476, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -246.372, -554.326, 108.705, 5.8801, -2.77476, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -248.668, -550.777, 109.14, 10.4701, 8.96462, 32.8806, -1, 7);
				Features::PlaceObjectByHash(3681122061, -251.664, -546.138, 110.313, 13.5301, 1.15259, 32.8806, -1, 7);
				Features::PlaceObjectByHash(3681122061, -254.537, -541.694, 111.791, 16.5901, 4.26887, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -256.28, -538.999, 112.748, 19.6501, -1.19528, 32.8807, -1, 7);
				Features::PlaceObjectByHash(3681122061, -65.9078, -814.752, 326.106, 19.89, 4.26887, -53.8105, -1, 7);
				Features::PlaceObjectByHash(3681122061, -58.6541, -809.444, 327.336, -4.08004, -2.13443, -53.8103, -1, 7);
				Features::PlaceObjectByHash(3681122061, -52.4476, -804.909, 323.715, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -47.2332, -801.09, 317.168, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -42.0187, -797.272, 310.621, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -36.8326, -793.474, 304.109, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -31.5898, -789.635, 297.526, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -26.4037, -785.838, 291.014, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -21.1893, -782.019, 284.467, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -15.9748, -778.201, 277.919, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -10.7604, -774.383, 271.372, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -5.57426, -770.585, 264.86, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, -0.359839, -766.767, 258.313, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 4.82623, -762.969, 251.799, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 10.0123, -759.171, 245.285, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 15.2268, -755.353, 238.735, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 20.4412, -751.535, 232.184, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 25.6273, -747.737, 225.67, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 30.8135, -743.939, 219.155, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 36.0279, -740.121, 212.605, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 41.214, -736.323, 206.091, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 46.4285, -732.505, 199.54, -45.3899, 2.56132, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 48.4122, -731.052, 197.049, -41.8198, 1.62217, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 49.5549, -730.218, 195.782, -38.2499, 3.24434, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 51.171, -729.035, 194.203, -36.2098, 2.39057, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 52.8966, -727.773, 192.637, -33.1499, -6.83019, -53.8101, -1, 7);
				Features::PlaceObjectByHash(3681122061, 54.586, -726.537, 191.27, -30.0898, 8.70849, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 56.5413, -725.105, 189.866, -25.4998, 7.59859, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 58.8359, -723.425, 188.509, -22.4398, 4.26887, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 60.738, -722.033, 187.536, -18.3599, 1.10991, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 63.1509, -720.268, 186.544, -15.8098, 5.03727, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 65.131, -718.821, 185.849, -12.7498, 5.07995, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 67.1384, -717.352, 185.286, -9.17981, 4.78113, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 69.2894, -715.776, 184.855, -4.5898, 4.18349, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 71.7831, -713.952, 184.607, 0.000193536, 4.16213, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 74.0832, -712.268, 184.607, 3.06019, 3.7566, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 76.0175, -710.853, 184.736, 8.1602, 4.35424, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 77.7752, -709.567, 185.048, 13.2602, 5.50684, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 79.6997, -708.158, 185.61, 17.3402, 3.7566, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 81.3947, -706.918, 186.266, 21.9302, 4.26887, -53.81, -1, 7);
				Features::PlaceObjectByHash(3681122061, 83.3036, -705.52, 187.219, 26.0102, 9.39151, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 85.6244, -703.821, 188.622, 29.0702, 1.96368, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 87.3526, -702.556, 189.812, 33.1501, 2.90283, -53.8098, -1, 7);
				Features::PlaceObjectByHash(3681122061, 89.2107, -701.196, 191.316, 37.2301, 4.86651, -53.8098, -1, 7);
				Features::PlaceObjectByHash(3681122061, 90.8492, -699.998, 192.859, 41.82, -2.56132, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 92.6236, -698.701, 194.826, 46.41, 8.2816, -53.8099, -1, 7);
				Features::PlaceObjectByHash(3681122061, 94.2096, -697.539, 196.89, 52.0199, 6.57406, -53.8098, -1, 7);
				Features::PlaceObjectByHash(3681122061, 95.6251, -696.503, 199.137, 56.61, 9.22075, -53.8097, -1, 7);
				Features::PlaceObjectByHash(3681122061, 96.9799, -695.512, 201.683, 61.7098, 8.53774, -53.8097, -1, 7);
				Features::PlaceObjectByHash(3681122061, 98.1658, -694.646, 204.413, 65.7899, 5.03726, -53.8096, -1, 7);
				Features::PlaceObjectByHash(3681122061, -69.0186, -829.452, 324.775, 0, -0, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -65.276, -836.288, 321.491, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -62.2554, -842.061, 315, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -59.2515, -847.802, 308.544, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -56.2313, -853.574, 302.053, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -53.1945, -859.378, 295.526, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -50.2071, -865.088, 289.106, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -47.2032, -870.829, 282.65, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -44.1829, -876.602, 276.159, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -41.1626, -882.374, 269.667, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -38.1751, -888.084, 263.247, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -35.1713, -893.825, 256.791, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -32.1674, -899.566, 250.335, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -29.1635, -905.307, 243.879, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -26.1432, -911.079, 237.388, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -23.1393, -916.821, 230.932, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -20.119, -922.593, 224.44, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -17.1152, -928.334, 217.985, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -14.1112, -934.075, 211.529, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -11.1235, -939.785, 205.108, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -8.13589, -945.495, 198.687, -44.8796, 3.24434, -152.398, -1, 7);
				Features::PlaceObjectByHash(3681122061, -5.28891, -951.101, 192.102, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, -2.35757, -956.552, 185.364, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 0.589775, -962.033, 178.59, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 3.5211, -967.483, 171.852, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 9.3998, -978.414, 158.339, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 6.46847, -972.964, 165.077, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 12.3311, -983.865, 151.601, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 15.2944, -989.375, 144.789, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 21.1569, -1000.28, 131.313, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 18.2417, -994.856, 138.014, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 24.0722, -1005.7, 124.612, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 27.0355, -1011.21, 117.801, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 29.9828, -1016.69, 111.026, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 35.8294, -1027.56, 97.5867, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 37.2241, -1030.15, 94.4555, -44.3698, -1.70754, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 38.7475, -1032.99, 91.3086, -39.7798, -4.26887, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 39.7483, -1034.85, 89.5491, -36.7197, 3.4151, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 40.9818, -1037.14, 87.6062, -33.6597, -2.21981, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 42.1248, -1039.27, 85.999, -30.0898, -1.96368, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 32.9141, -1022.14, 104.288, -47.4298, -1.79292, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 43.3132, -1041.47, 84.5449, -26.5197, -1.79293, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 44.7115, -1044.08, 83.0715, -23.4597, -2.39056, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 45.9496, -1046.38, 81.937, -20.3997, -2.47594, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 47.0815, -1048.48, 81.0483, -17.3397, -2.09174, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 48.302, -1050.75, 80.2436, -14.7897, -8.96462, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 50.0647, -1054.03, 79.2608, -13.2597, -2.77476, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 52.0238, -1057.67, 78.2861, -11.7297, -1.45141, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 53.7395, -1060.86, 77.5341, -9.17973, -1.1099, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 55.7265, -1064.56, 76.8558, -6.11973, -6.61674, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 57.3746, -1067.62, 76.4825, -3.56972, -9.60496, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 59.3125, -1071.23, 76.2272, 0.000276446, -9.05818, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 61.112, -1074.58, 76.2272, 4.08028, -8.00412, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 62.529, -1077.21, 76.4405, 7.65027, -7.04364, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 64.0779, -1080.1, 76.8796, 10.7103, -1.28066, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 65.9388, -1083.55, 77.623, 14.2802, -1.70755, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 67.4076, -1086.29, 78.4126, 17.3403, -1.57948, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, 68.7639, -1088.81, 79.3066, 21.4202, 1.36604, -151.734, -1, 7);
				Features::PlaceObjectByHash(3681122061, -86.0915, -825.576, 324.775, 0, -0, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -99.1939, -833.684, 315.911, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -105.248, -837.511, 310.056, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -93.1729, -829.876, 321.734, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -111.268, -841.319, 304.233, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -123.245, -848.891, 292.651, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -147.333, -864.12, 269.359, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -141.278, -860.292, 275.213, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -135.256, -856.485, 281.036, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -129.266, -852.699, 286.828, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -117.224, -845.084, 298.474, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -165.367, -875.521, 251.921, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -213.415, -905.895, 205.464, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -207.426, -902.108, 211.255, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -201.403, -898.301, 217.078, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -195.414, -894.515, 222.87, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -183.434, -886.942, 234.452, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -177.445, -883.156, 240.244, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -171.422, -879.348, 246.067, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -159.378, -871.734, 257.713, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -153.355, -867.927, 263.536, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -189.424, -890.728, 228.661, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -231.449, -917.296, 188.027, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -225.46, -913.509, 193.818, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -219.47, -909.723, 199.609, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -237.439, -921.082, 182.235, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -284.806, -951.016, 167.673, 28.5601, -7.5132, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -289.048, -953.697, 170.578, 34.1701, -3.41509, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -290.727, -954.757, 171.926, 37.23, 3.41509, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -286.998, -952.399, 169.084, 31.62, -1.36604, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -282.375, -949.481, 166.27, 26.0101, 3.50047, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -280.014, -947.991, 165.174, 21.4201, -6.83019, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -277.4, -946.336, 164.178, 17.8501, -3.15896, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -270.266, -941.827, 162.896, 4.59013, -1.79292, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -266.683, -939.562, 163.103, -6.11989, -1.38738, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -259.328, -934.913, 165.339, -17.8499, -4.69576, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -253.478, -931.22, 168.474, -26.01, -4.18349, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -248.103, -927.823, 172.247, -33.66, -5.97642, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -243.429, -924.868, 176.444, -39.27, -2.30519, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -256.593, -933.187, 166.676, -22.4399, -5.97641, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -262.183, -936.72, 164.252, -14.2799, -3.20165, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -268.321, -940.597, 162.896, 0.000125527, -1.95033, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -272.668, -943.344, 163.123, 8.67012, -2.86014, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -275.091, -944.877, 163.561, 12.7501, -5.1226, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -249.757, -928.867, 170.944, -31.11, -6.0617, 122.286, -1, 7);
				Features::PlaceObjectByHash(3681122061, -251.566, -930.012, 169.653, -27.54, -3.58585, 122.286, -1, 7);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}

			break;
#pragma region mapmode
		case ramp9:
			Menu::Title("Fort Zancudo Motorcross");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(3213433054, -2661.22, 3209.43, 32.7118, 0, -0, -120.437, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2657.86, 3207.56, 32.7118, 0, 0, 59.6808, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2659.52, 3212.33, 32.7118, 0, -0, -120.437, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2656.2, 3210.41, 32.7118, 0, 0, 59.6808, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2654.54, 3213.26, 32.7118, 0, 0, 59.6808, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2657.84, 3215.18, 32.7118, 0, -0, -120.437, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2615.14, 3183, 32.8118, 0, -0, -120.45, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2611.82, 3181.02, 32.8118, 0, 0, 58.529, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2613.47, 3185.85, 32.8118, 0, -0, -120.45, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2610.11, 3183.91, 32.8118, 0, 0, 59.589, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2611.79, 3188.7, 32.8118, 0, -0, -120.45, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2608.46, 3186.71, 32.8118, 0, 0, 58.529, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2550.83, 3162.65, 32.7702, 0, -0, -117.989, -1, 8);
				Features::PlaceObjectByHash(4109455646, -2547.01, 3160.66, 34.9496, 11.66, -2.56132e-006, -118.95, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2476.76, 3120.72, 32.7718, 0, -0, -119.612, -1, 8);
				Features::PlaceObjectByHash(4109455646, -2473.51, 3118.83, 34.5672, 8.47412, -0.0223369, -120.965, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2442.43, 3105.7, 35.6224, -7.42001, -5.12265e-006, 150.074, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2443.67, 3101.83, 35.8732, -11.66, 3.84198e-006, 59.738, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2438.8, 3099, 36.0155, -11.66, -6.40331e-006, 59.7379, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2434.05, 3096.22, 36.6871, -22.26, -1.45141e-005, 59.7379, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2446.85, 3098.2, 35.6088, -7.42, 3.20165e-006, -31.8463, -1, 8);
				Features::PlaceObjectByHash(2402097066, -2448.77, 3097.65, 35.4732, 0, -0, -120.616, -1, 8);
				Features::PlaceObjectByHash(2402097066, -2442.95, 3108.08, 35.4832, 0, -0, -117.436, -1, 8);
				Features::PlaceObjectByHash(2402097066, -2442.95, 3108.08, 35.4832, 0, -0, -117.436, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2389.55, 3069.11, 36.5952, 179.801, -3.76861e-006, -117.806, -1, 8);
				Features::PlaceObjectByHash(1982829832, -2363.33, 3056.01, 31.8257, 0, -0, -119.219, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2389.55, 3069.11, 36.5952, 179.801, -3.76861e-006, -117.806, -1, 8);
				Features::PlaceObjectByHash(2609922146, -2358.79, 3060.59, 31.8217, 0, -0, -119.371, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2325.93, 3034.99, 33.3214, 19.8, 3.41509e-006, -120.09, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2321.78, 3032.58, 36.3899, 25.7399, -8.62311e-005, -120.09, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2317.79, 3030.29, 39.6222, 25.0799, -6.23256e-005, -120.09, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2313.74, 3027.94, 42.9228, 25.7399, -8.62311e-005, -120.09, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2309.83, 3025.69, 46.2289, 27.06, -8.2816e-005, -120.09, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2306.07, 3023.49, 49.5919, 29.0399, -0.000116113, -120.09, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2283.14, 3009.97, 44.7284, 14.12, -2.04906e-005, 60.0397, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2287.5, 3012.47, 46.9591, 13.6, 0.680011, 60.0397, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2302.26, 3021.28, 53.174, 29.6999, -0.000100745, -120.09, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2292.06, 3015.11, 49.2546, 13.6, 1.53679e-005, 60.0397, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2298.56, 3019.12, 56.7472, 30.36, -8.79386e-005, -120.09, -1, 8);
				Features::PlaceObjectByHash(2052512905, -2294.52, 3015.08, 58.6366, 82.6616, 0.00430302, -31.2919, -1, 8);
				Features::PlaceObjectByHash(2052512905, -2293.13, 3017.4, 58.6822, 80.9428, 0.00560716, 149.187, -1, 8);
				Features::PlaceObjectByHash(2787492567, -2293.66, 3016.58, 31.8318, -90, 0.0833042, 109.919, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2202.78, 2963.39, 32.8003, 0, -0, -120.04, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2199.53, 2961.53, 34.17, -40.5599, -2.56132e-006, 59.8803, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2137.1, 2904.97, 32.8327, 16.8, -1.10991e-005, -141.061, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2132.27, 2897.94, 34.4465, 16.8, -14, -141.061, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2127.12, 2890.88, 36.4432, 17.92, -29.68, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2119.98, 2885.33, 38.8379, 17.92, -29.68, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2113.02, 2880, 41.2705, 17.92, -29.68, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2085.18, 2857.71, 49.9177, 19.04, -43.12, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2078.1, 2852.44, 51.662, 19.0399, -50.4001, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2092.05, 2863.54, 48.2285, 17.92, -34.16, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2098.91, 2869.18, 46.2053, 17.92, -29.68, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2105.97, 2874.59, 43.7379, 17.92, -29.68, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2070.42, 2847.69, 53.5814, 19.0399, -50.4001, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2062.85, 2843.01, 55.4739, 19.0399, -50.4001, -136.581, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2055.32, 2838.69, 56.5097, 17.7868, -43.8868, -131.905, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2047.61, 2834.88, 58.9097, 26.1867, -43.8868, -131.905, -1, 8);
				Features::PlaceObjectByHash(3681122061, -2039.74, 2832.2, 62.2769, 38.5067, -45.5668, -131.905, -1, 8);
				Features::PlaceObjectByHash(3681122061, -1996.98, 2830.2, 48.384, 0.202822, -14.4337, -105.503, -1, 8);
				Features::PlaceObjectByHash(3681122061, -1996.42, 2832.89, 59.0601, -179.433, 12.3451, 76.9258, -1, 8);
				Features::PlaceObjectByHash(3213433054, -1951.86, 2849.63, 34.5146, -47.5199, -7.59859e-005, 59.6261, -1, 8);
				Features::PlaceObjectByHash(3213433054, -1950.16, 2852.52, 34.5146, -47.5199, -7.59859e-005, 59.6261, -1, 8);
				Features::PlaceObjectByHash(3213433054, -1953.57, 2854.49, 32.8004, 0, -0, -120.091, -1, 8);
				Features::PlaceObjectByHash(3213433054, -1955.25, 2851.59, 32.8004, 0, -0, -120.091, -1, 8);
				Features::PlaceObjectByHash(4111834409, -1960.72, 2857.38, 31.7305, 0, -0, -118.505, -1, 8);
				Features::PlaceObjectByHash(4109455646, -2144, 2967.21, 36.0606, 9.35852, -0.00134085, 59.8371, -1, 8);
				Features::PlaceObjectByHash(4109455646, -2139.63, 2964.67, 33.9985, 5.84852, -0.0013321, 59.8371, -1, 8);
				Features::PlaceObjectByHash(4109455646, -2135.45, 2962.3, 32.4604, 0, 0, 60.4792, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2193.23, 2995.21, 35.0684, 11.6996, -0.00262322, -119.238, -1, 8);
				Features::PlaceObjectByHash(2975320548, -2197.74, 2997.74, 32.8074, 15.2099, 2.04906e-005, -119.328, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2246.82, 3026.19, 33.0318, 0.0331696, 0.0056356, 58.6423, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2256.38, 3032.02, 35.4343, 6.5707, 0.0279573, 58.7685, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2265.19, 3037.37, 38.408, 10.1262, 0.0254109, 58.7585, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2273.45, 3042.38, 40.214, 8.95404, -0.00182451, 58.7729, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2281.36, 3047.19, 42.7382, 8.89319, 0.151422, 58.8279, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2289.41, 3052.05, 46.2871, 13.2, 0.000150264, 58.7642, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2397.86, 3114.2, 32.8449, 0, 0, 60.2049, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2402.38, 3116.77, 34.7648, 0, 0, 60.2049, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2394.65, 3118.07, 32.5452, 0, 0, 56.6241, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2397.73, 3120.09, 34.1452, 2.04, -1.38738e-006, 56.6241, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2401.78, 3122.77, 36.6227, 8.16, 1.28066e-006, 56.6239, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2405.48, 3125.2, 39.5571, 14.28, 1.02453e-005, 56.6239, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2409.12, 3127.6, 43.2064, 20.4, -2.39057e-005, 56.6239, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2412.29, 3129.71, 46.9494, 24.4781, -1.43125, 56.2632, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2415.18, 3131.49, 51.529, 38.3931, -3.70399, 55.299, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2416.96, 3132.28, 56.2986, 54.0331, -3.70398, 53.2589, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2417.37, 3132.16, 61.6124, 73.753, -3.70394, 53.2588, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2416.48, 3131.04, 66.996, 90.9129, -3.70395, 53.2587, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2414.88, 3129.5, 70.998, 104.113, -3.70383, 50.6186, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2412.46, 3127.2, 74.61, 116.653, -3.70392, 50.6185, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2409.58, 3124.71, 77.6119, 121.273, -3.70395, 50.6185, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2406.75, 3122.18, 80.0586, 127.213, -3.70391, 50.6184, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2403.38, 3119.23, 82.2502, 135.793, -3.70396, 50.6185, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2369.71, 3092.81, 68.2807, -146.327, -3.7039, 50.6183, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2367.45, 3091.4, 63.3347, -134.447, -3.70392, 50.6182, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2366, 3090.66, 58.0814, -123.887, -3.7039, 50.6182, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2365.38, 3090.57, 53.1623, -112.007, -3.70391, 50.6182, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2365.62, 3091.18, 48.0172, -99.4666, -3.70393, 50.6181, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2366.77, 3092.54, 43.04, -86.2661, -3.70399, 50.6181, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2368.73, 3094.52, 38.5669, -74.386, -3.70392, 50.6181, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2371.25, 3096.8, 35.0692, -59.206, -3.70384, 55.2379, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2375.18, 3099.61, 32.3997, -42.0459, -3.70387, 57.2179, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2395.69, 3112.77, 84.6355, 152.292, -3.70389, 50.6184, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2391.54, 3109.37, 84.6603, 162.192, -3.70393, 50.6184, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2387.13, 3105.84, 83.6595, 172.752, -3.70391, 50.6184, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2382.97, 3102.56, 81.8101, -179.988, -3.70391, 50.6184, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2372.52, 3094.76, 72.6855, -154.907, -3.70391, 50.6183, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2379.11, 3099.59, 79.371, -172.728, -3.70391, 50.6183, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2375.46, 3096.85, 76.1692, -162.168, -3.70388, 50.6182, -1, 8);
				Features::PlaceObjectByHash(2475986526, -2399.8, 3116.19, 83.7512, 143.712, -3.70387, 50.6184, -1, 8);
				Features::PlaceObjectByHash(3213433054, -2510.73, 3180.4, 32.8111, 0, 0, 59.4291, -1, 8);
				Features::PlaceObjectByHash(209943352, -2302.92, 3059.95, 50.2208, 76.8397, -0.679965, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2298.84, 3057.5, 48.7042, 71.3997, -0.679954, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2290.6, 3052.58, 47.3498, 84.3198, -0.679946, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2290.6, 3052.58, 47.3498, 84.3198, -0.679946, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2294.73, 3055.05, 47.6692, 76.8398, -0.680059, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2533.2, 3193.91, 37.3948, 0, -0, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2533.2, 3193.91, 37.3948, 0, -0, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2425.58, 3091.36, 36.493, 0, -0, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2425.58, 3091.36, 36.493, 0, -0, -120.716, -1, 8);
				Features::PlaceObjectByHash(209943352, -2293.7, 3012.65, 55.3685, -89.7587, -0.659716, -30.2946, -1, 8);
				Features::PlaceObjectByHash(209943352, -2293.7, 3012.65, 55.3685, -89.7587, -0.659716, -30.2946, -1, 8);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -2731, 3259, 32, 1, 0, 0, 1);
			}

			break;
#pragma region mapmode
		case ramp10:
			Menu::Title("Halfpipe Fun Track");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(3681122061, -1018.78, -2937.26, 12.9646, 0, 0, -30.3132, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1023.38, -2945.17, 12.9646, 0, 0, -30.3132, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1028.02, -2953.13, 12.9646, 0, 0, -30.3132, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1032.66, -2961.06, 12.9646, 0, 0, -30.3132, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1037.32, -2969.04, 12.9646, 0, 0, -30.3132, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1041.95, -2976.96, 12.9646, 0, 0, -30.3132, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1046.18, -2984.19, 12.9646, 0, 0, -30.3132, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1050.78, -2992.12, 12.9646, 0, 0, -29.8732, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1053.22, -2998.13, 12.9646, 0, 0, -14.2534, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1054.14, -3005.28, 12.9646, 0, 0, -0.613478, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1053.45, -3012.85, 12.9646, 0, 0, 11.4866, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1051.19, -3020.08, 12.9646, 0, 0, 23.3667, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1047.43, -3026.73, 12.9646, 0, 0, 35.2469, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1042.42, -3032.37, 12.9646, 0, 0, 47.7871, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1037.1, -3038.16, 12.9646, 0, 0, 37.2273, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1033.11, -3044.75, 12.9646, 0, 0, 25.5675, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1030.43, -3052.11, 12.9646, 0, 0, 14.5676, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1029.18, -3059.85, 12.9646, 0, 0, 4.00757, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1029.37, -3067.7, 12.9646, 0, 0, -6.55247, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1031, -3075.33, 12.9646, 0, 0, -17.5525, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1034.09, -3082.35, 12.9646, 0, 0, -29.6525, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1038.6, -3088.77, 12.9646, 0, 0, -40.2127, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1044.19, -3094.15, 12.9646, 0, 0, -51.653, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1050.65, -3098.2, 12.9646, 0, 0, -63.7531, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1057.89, -3100.91, 12.9646, 0, 0, -75.1935, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1065.18, -3101.87, 12.9646, 0, 0, -89.7139, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1073.03, -3101.2, 12.9646, 0, -0, -100.054, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1080.63, -3099.11, 12.9646, 0, -0, -110.615, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1087.92, -3095.65, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1095.95, -3091.03, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1104.01, -3086.4, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1112.04, -3081.79, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1120.04, -3077.19, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1128.1, -3072.56, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1136.15, -3067.93, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1144.2, -3063.31, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1152.22, -3058.7, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1160.24, -3054.09, 12.9646, 0, -0, -119.855, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1168.22, -3049.48, 12.9646, 0, -0, -120.295, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1176.21, -3044.8, 12.9646, 0, -0, -120.295, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1183.28, -3040.14, 12.9646, 0, -0, -126.455, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1189.23, -3034.89, 12.9646, 0, -0, -136.356, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1193.86, -3028.84, 12.9646, 0, -0, -148.677, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1197.2, -3021.86, 12.9646, 0, -0, -159.898, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1198.78, -3014.77, 12.9646, 0, -0, -174.639, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1198.72, -3007.04, 12.9646, 0, -0, 173.701, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1197, -2999.97, 12.9646, 0, -0, 158.962, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1193.5, -2993.3, 12.9646, 0, -0, 145.982, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1188.51, -2987.1, 12.9646, 0, -0, 136.083, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1182.5, -2981.85, 12.9646, 0, -0, 126.183, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1175.98, -2978.23, 12.9646, 0, -0, 112.104, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1168.67, -2976.15, 12.9646, 0, -0, 99.7843, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1160.82, -2975.53, 12.9646, 0, 0, 89.4449, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1152.93, -2976.29, 12.9646, 0, 0, 79.5455, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1145.21, -2978.39, 12.9646, 0, 0, 70.0859, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1138.14, -2981.75, 12.9646, 0, 0, 59.0863, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1130.27, -2986.43, 12.9646, 0, 0, 59.0863, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1122.46, -2991.09, 12.9646, 0, 0, 59.0863, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1115.12, -2994.75, 12.9646, 0, 0, 67.1435, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1107.63, -2997.13, 12.9646, 0, 0, 76.9913, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1099.8, -2998.14, 12.9646, 0, 0, 86.8389, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1091.94, -2997.76, 12.9646, 0, -0, 97.5819, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1084.47, -2995.95, 12.9646, 0, -0, 108.325, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1077.64, -2992.78, 12.9646, 0, -0, 119.963, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1077.64, -2992.78, 12.9646, 0, -0, 119.963, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1071.68, -2988.3, 12.9646, 0, -0, 132.496, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1066.33, -2982.53, 12.9646, 0, -0, 141.449, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1053.01, -2960.01, 12.9646, 0, 0, -28.5532, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1048.58, -2951.88, 12.9646, 0, 0, -28.5532, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1044.16, -2943.76, 12.9646, 0, 0, -28.5532, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1039.74, -2935.64, 12.9646, 0, 0, -28.5532, -1, 9);
				Features::PlaceObjectByHash(3681122061, -1035.5, -2927.86, 12.9646, 0, 0, -28.5532, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1063.23, -2993.67, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1067.37, -2998.06, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1063.7, -2994.67, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1064.21, -2995.73, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1064.71, -2996.8, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1065.21, -2997.84, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1067.1, -2999.45, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1065.43, -3000.24, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1068.29, -3000.06, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1065.92, -3001.18, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1066.44, -3002.28, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1065.35, -3002.77, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1065.6, -3003.96, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1066.11, -3005.04, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1064.21, -2999.56, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1069.53, -3000.82, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1070.75, -3001.52, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1068.76, -3002.46, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1069.29, -3003.54, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1068.44, -3005.23, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1071.58, -3003.74, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1072.98, -3006.81, 16.0846, 0, 0, -26.0348, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1072.44, -3002.05, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1073.73, -3002.72, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1076.54, -3005.07, 16.0846, 0, 0, -26.0348, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1078.92, -3009.92, 13.7046, 0, 0, -26.0348, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1075.31, -3011.69, 13.7046, 0, 0, -26.0348, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1069.34, -3008.59, 16.0846, 0, 0, -26.0348, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1071.71, -3013.45, 13.7046, 0, 0, -26.0348, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1068.14, -3015.2, 13.7046, 0, 0, -26.0348, -1, 9);
				Features::PlaceObjectByHash(3608473212, -1065.36, -3006.66, 15.3449, 0, 0, -25.1145, -1, 9);
				Features::PlaceObjectByHash(2475986526, -1065.75, -3010.35, 16.0846, 0, 0, -26.0348, -1, 9);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1003, -2916, 14, 1, 0, 0, 1);
			}

			break;
#pragma region mapmode
		case ramp11:
			Menu::Title("Airport Loop");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(3966705493, -1041.89, -3219.51, 10.1797, -2.43331, 5.32208, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1037.79, -3221.47, 10.3641, -2.43331, 5.32208, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1034.16, -3223.3, 10.5366, -2.43331, 5.32208, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1036.76, -3219.45, 10.1526, -2.43331, 5.32208, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1033.12, -3221.28, 10.3251, -2.43331, 5.32208, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1029.37, -3225.6, 11.1956, -11.6033, 5.32207, 62.9335, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1028.33, -3223.58, 10.9842, -11.6033, 5.32207, 62.9335, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1024.27, -3225.54, 12.1104, -18.1533, 5.32205, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1025.44, -3227.83, 12.3497, -18.1533, 5.32205, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1020.36, -3230.06, 15.7972, -40.4234, 5.32214, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1019.22, -3227.83, 15.5634, -40.4234, 5.32214, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1014.85, -3229.56, 20.4393, -50.9034, 5.3221, 62.9337, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1016.07, -3231.95, 20.6898, -50.9034, 5.3221, 62.9337, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1012.88, -3232.96, 26.0664, -64.0034, 5.32209, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1011.63, -3230.51, 25.8104, -64.0034, 5.32209, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1009.27, -3231.06, 32.0819, -73.1735, 5.32204, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1010.52, -3233.51, 32.3379, -73.1735, 5.32214, 62.9337, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1009.36, -3233.48, 38.2311, -83.6535, 5.32208, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1008.09, -3230.98, 37.9695, -83.6535, 5.32208, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1007.71, -3230.43, 44.185, -92.8235, 6.63212, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1009.05, -3228.93, 49.9682, -119.024, 6.63217, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1008.93, -3232.81, 44.4969, -92.8235, 6.63212, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1010.27, -3231.31, 50.2801, -119.024, 6.63217, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1011.96, -3226.91, 54.0691, -142.604, 6.6321, 62.9337, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1013.1, -3229.14, 54.3602, -142.604, 6.6321, 62.9337, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1017.49, -3226.51, 57.2125, -159.634, 6.63211, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1022.14, -3223.91, 58.9186, -168.804, 6.63213, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1035.97, -3216.05, 58.7162, 155.826, 1.39214, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1031.37, -3218.71, 60.1775, 176.786, 6.63213, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1026.33, -3221.63, 59.8766, -168.804, 6.63212, 60.3136, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1020.98, -3221.63, 58.6206, -168.804, 6.63213, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1024.97, -3219.25, 59.5578, -168.804, 6.63212, 60.3136, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1016.33, -3224.24, 56.9145, -159.634, 6.63211, 62.9336, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1029.99, -3216.28, 59.8517, 176.786, 6.63213, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1029.99, -3216.28, 59.8517, 176.786, 6.63213, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1034.73, -3213.86, 58.655, 155.826, 1.39214, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1039.18, -3211.42, 55.2255, 138.796, 1.39206, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1039.18, -3211.42, 55.2255, 138.796, 1.39206, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1040.42, -3213.61, 55.2867, 138.796, 1.39206, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1044.34, -3211.51, 50.6082, 128.316, 1.39213, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1043.09, -3209.33, 50.547, 128.316, 1.39213, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1046.16, -3207.74, 45.1535, 117.837, 1.39215, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1048.17, -3206.74, 39.6252, 104.737, 1.39214, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1048.92, -3206.44, 33.1586, 87.6005, 0.0914728, 60.6227, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1048.18, -3206.88, 26.5446, 77.3408, 0.0913896, 60.6229, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1049.44, -3209.13, 26.5487, 77.3407, 0.0913427, 60.6228, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1047.3, -3210.37, 21.3947, 56.6411, 0.0914017, 58.823, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1047.3, -3210.37, 21.3947, 56.6411, 0.0914017, 58.823, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1045.93, -3208.12, 21.3905, 56.6411, 0.0914017, 58.823, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1042.61, -3210.12, 16.8766, 42.1517, 0.0913785, 58.8231, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1038.64, -3212.63, 13.6141, 28.2018, 0.0914187, 58.8231, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1039.97, -3214.83, 13.6182, 28.2018, 0.0914187, 58.8231, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1034.82, -3217.71, 11.1985, 16.4116, 0.0913871, 69.303, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1033.53, -3215.55, 11.1081, 16.4117, 0.0913619, 66.683, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1043.97, -3212.37, 16.8808, 42.1517, 0.0913785, 58.8231, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1050.19, -3208.69, 33.1627, 87.6005, 0.0914728, 60.6227, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1049.45, -3208.98, 39.6879, 104.737, 1.39214, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1047.44, -3209.98, 45.2161, 117.837, 1.39215, 60.3137, -1, 10);
				Features::PlaceObjectByHash(3966705493, -1047.44, -3209.98, 45.2161, 117.837, 1.39215, 60.3137, -1, 10);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1074, -3201, 13, 1, 0, 0, 1);
			}

			break;
#pragma region mapmode
		case ramp12:
			Menu::Title("Maze Bank Ramp");
			Menu::Subtitle("MAPS");
			if (Menu::Option("Load")) {
				Features::PlaceObjectByHash(3681122061, -82.9657, -818.944, 325.175, 0, -0, 91.03, -1, 11);
				Features::PlaceObjectByHash(3681122061, -91.0941, -819.089, 322.355, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -98.36, -819.224, 316.632, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -105.626, -819.358, 310.91, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -112.892, -819.492, 305.187, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -120.158, -819.626, 299.464, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -127.424, -819.761, 293.741, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -134.69, -819.895, 288.018, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -141.956, -820.029, 282.296, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -149.222, -820.163, 276.573, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -156.487, -820.298, 270.85, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -163.753, -820.432, 265.127, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -171.019, -820.566, 259.404, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -178.285, -820.701, 253.682, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -185.551, -820.835, 247.959, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -192.817, -820.969, 242.236, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -200.083, -821.103, 236.513, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -207.349, -821.238, 230.79, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -214.615, -821.372, 225.068, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -221.881, -821.506, 219.345, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -229.147, -821.641, 213.622, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -236.413, -821.775, 207.899, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -243.679, -821.909, 202.176, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -250.945, -822.043, 196.453, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -258.21, -822.178, 190.731, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -265.476, -822.312, 185.008, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -287.274, -822.715, 167.839, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -280.008, -822.58, 173.562, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -272.742, -822.446, 179.285, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -294.54, -822.849, 162.117, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -301.806, -822.983, 156.394, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -309.072, -823.118, 150.671, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -316.338, -823.252, 144.948, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -323.604, -823.386, 139.225, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -330.87, -823.52, 133.503, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -338.136, -823.655, 127.78, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -345.402, -823.789, 122.057, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -352.668, -823.923, 116.334, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -359.934, -824.057, 110.611, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -367.199, -824.192, 104.889, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -374.465, -824.326, 99.1657, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -381.731, -824.46, 93.4429, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -388.997, -824.595, 87.7201, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -396.263, -824.729, 81.9973, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -403.529, -824.863, 76.2745, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -411.479, -825.022, 68.7971, -19.78, -3.43377e-005, 91.1094, -1, 11);
				Features::PlaceObjectByHash(3681122061, -410.795, -824.997, 70.5517, -38.2199, 0.00787841, 91.0529, -1, 11);
				Features::PlaceObjectByHash(3681122061, -411.96, -825.029, 69.097, -27.6, 1.15259e-005, 91.1095, -1, 11);
				Features::PlaceObjectByHash(3681122061, -412.719, -825.046, 67.8516, -10.58, -2.92151e-006, 91.1095, -1, 11);
				Features::PlaceObjectByHash(3681122061, -413.903, -825.068, 67.2075, -3.21999, 5.66959e-007, 91.1095, -1, 11);
				Features::PlaceObjectByHash(3681122061, -415.378, -825.099, 66.7734, 3.68002, -4.58236e-006, 91.1095, -1, 11);
				Features::PlaceObjectByHash(3681122061, -416.883, -825.126, 66.57, 9.66002, -8.44435e-006, 91.1096, -1, 11);
				Features::PlaceObjectByHash(3681122061, -418.526, -825.157, 66.5571, 15.64, -1.80093e-005, 91.1095, -1, 11);
				Features::PlaceObjectByHash(3681122061, -419.945, -825.184, 66.6727, 20.7001, 8.69782e-006, 91.1094, -1, 11);
				Features::PlaceObjectByHash(3681122061, -421.727, -825.218, 67.0936, 25.7601, -2.09975e-005, 91.1095, -1, 11);
				Features::PlaceObjectByHash(3681122061, -422.006, -825.234, 66.966, 30.8199, 0.114757, 90.6829, -1, 11);
				Features::PlaceObjectByHash(3681122061, -429.913, -825.328, 71.6856, 30.8199, 0.114757, 90.6829, -1, 11);
			}
			if (Menu::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}

			break;
#pragma endregion
#pragma region Self Menu
		case self:
		{
			Menu::Title("Self Options");
			Menu::Subtitle("SELF OPTIONS");
			Menu::MenuOption("Models", modelchanger);
			Menu::MenuOption("Outfits", outfits);
			Menu::MenuOption("Bodyguard", bodyguards);
			Menu::Toggle("Godmode", Features::Godmode, [] { Features::godmode(Features::Godmode); });
			Menu::Toggle("Invisible", Features::Ghostmode, [] { Features::ghostmode(Features::Ghostmode); });
			Menu::Toggle("Super Jump", Features::Superjump, [] { Features::superjump(Features::Superjump); });
			Menu::Toggle("Never Wanted", Features::Neverwanted, [] { Features::neverwanted(Features::Neverwanted); });
			Menu::Toggle("Fast Run", Features::FastRun, [] { Features::fastRun(Features::FastRun); });
			Menu::Toggle("No Ragdoll", Features::NoRagdoll, [] { Features::noRagdoll(Features::NoRagdoll); });
			Menu::Toggle("Extreme Run", Features::ExtremeRun, [] { Features::extremeRun(Features::ExtremeRun); });
			Menu::Toggle("No Clip", Features::flybool, [] { Features::playerflyer(Features::flybool); });
			Menu::Toggle("Tiny Player (TEST)", Features::TinyPlayer, [] { Features::tinyPlayer(Features::TinyPlayer); });
			Menu::Toggle("~g~Free Cam", Features::Free, [] { Features::Freee(Features::Free); });
			Menu::Toggle("~g~Walk on Air", Features::featureWalk, [] { Features::featureWalkk(Features::featureWalk); });
			if (Menu::Option("Random Outfit")) { PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true); }

		}
		break;
#pragma endregion
#pragma region All Players
		case allplayerop:
		{
			Menu::Title("All Players");
			Menu::Subtitle("PLAYERS");
			Menu::Toggle("Explode All Loop", Features::LoopKill, [] { Features::loopKill(Features::LoopKill); });
			Menu::Toggle("Shake Lobby", Features::ShakeLobby, [] { Features::shakeLobby(Features::ShakeLobby); });
			Menu::Toggle("Crash", Features::Crash, [] { Features::crash(Features::Crash); });
			Menu::Toggle("~r~ Freeze all", Features::FreezeA, [] { Features::freeze(Features::FreezeA); });

			if (Menu::Option("Explode All Players")) {
				for (int i = 0; i < 33; i++)
				{
					if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
					{
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
						FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 29, 5.55555555f, true, false, 100.f);
					}
				}
			}
			if (Menu::Option("Kick all from Vehicle")) {
				for (int i = 0; i < 32; i++)
				{
					if (i != PLAYER::PLAYER_ID())
					{
						RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					}
				}
			}
			if (Menu::Option("Alien Invasion")) {
				for (int i = 0; i <= 32; i++)
				{
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
					Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
					Hash oball = GAMEPLAY::GET_HASH_KEY("p_spinning_anus_s");
					STREAMING::REQUEST_MODEL(oball);
					while (!STREAMING::HAS_MODEL_LOADED(oball))
						WAIT(0);
					//	int orangeball = CREATE_OBJECT(oball, pCoords.x, pCoords.y, pCoords.z, true, 1, 0);
					//	ATTACH_ENTITY_TO_ENTITY(orangeball, Handle, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
					int createdObject = NETWORK::OBJ_TO_NET(OBJECT::CREATE_OBJECT_NO_OFFSET(oball, pCoords.x, pCoords.y, pCoords.z, 1, 0, 0));

					{
						if (i == 32)
						{
							break;
						}

					}
				}
			}
			if (Menu::Option("Give All Weapons")) {
				static LPCSTR weaponNames2[] = {
					"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
					"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
					"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
					"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
					"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_COMBATPDW", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
					"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
					"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_KNUCKLE", "WEAPON_MARKSMANPISTOL",
					"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
					"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
					"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLASHLIGHT", "WEAPON_MACHINEPISTOL", "WEAPON_MACHETE"
				};
				{
					for (int i = 0; i <= 32; i++)
					{
						WAIT(0);
						if (i == PLAYER::PLAYER_ID())continue;
						int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);


						for (int i = 0; i < sizeof(weaponNames2) / sizeof(weaponNames2[0]); i++)
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(Handle, GAMEPLAY::GET_HASH_KEY((char *)weaponNames2[i]), 9999, 9999);
						WAIT(100);
						{
							if (i == 32)
							{
								break;
							}
							notifyMap("Added weapons for players");

						}
					}
				}
			}
			if (Menu::Option("Take All Weapons")) {
				for (int i = 0; i <= 32; i++)
				{
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					WEAPON::REMOVE_ALL_PED_WEAPONS(Handle, 1);
					{
						if (i == 32)
						{
							break;
						}
						notifyMap("Removed All weapons");

					}
				}
			}
			if (Menu::Option("Trap All In Cage")) {
				for (int i = 0; i <= 32; i++)
				{
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
					Hash oball = GAMEPLAY::GET_HASH_KEY("prop_gold_cont_01");
					STREAMING::REQUEST_MODEL(oball);
					while (!STREAMING::HAS_MODEL_LOADED(oball))
						WAIT(0);
					//	int orangeball = CREATE_OBJECT(oball, pCoords.x, pCoords.y, pCoords.z, true, 1, 0);
					//	ATTACH_ENTITY_TO_ENTITY(orangeball, Handle, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
					NETWORK::OBJ_TO_NET(OBJECT::CREATE_OBJECT_NO_OFFSET(oball, pCoords.x, pCoords.y, pCoords.z, 1, 0, 0));
					{
						if (i == 32)
						{
							break;
						}

					}
				}
			}
			if (Menu::Option("Show Host")) {
				for (int i = 0; i <= 32; i++)
				{
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);

					char *freemd = "Freemode";
					int Host = NETWORK::NETWORK_GET_HOST_OF_SCRIPT(freemd, -1, 0);
					if (Host == i)
					{
						char* pName = (char*)PLAYER::GET_PLAYER_NAME((Player)(i));
						notifyMap(pName, 1, 0.5f, 0.5f, 1.0f, 1.0f, 255, 255, 255, 255, true);


					}
				}
			}
		}
		break;
#pragma endregion
#pragma region outfitsop
		case outfits:
		{
			Menu::Title("Clothing");
			Menu::Subtitle("OUTFITS");
			if (Menu::Option("Police Uniform")) 
			{				    
					ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()) == GAMEPLAY::GET_HASH_KEY("mp_f_freemode_01");
					PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, 45, 0, 0);
					PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, 48, 0, 0);
					PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 34, 0, 0);
					PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, 0, 0, 0);
					PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, 25, 0, 0);
					PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 8, 35, 0, 0);
			}
			if (Menu::Option("Rockstar Logo")) {
					PED::_APPLY_PED_OVERLAY(PLAYER::PLAYER_PED_ID(), -1398869298, -1730534702);

			}
			if (Menu::Option("Default Variation")) {
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());

			}
			if (Menu::Option("Random Variation")) {
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());

			}
			if (Menu::Option("Random Acessories")) {
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					PED::SET_PED_RANDOM_PROPS(playerPed);
			}
			if (Menu::Option("Reset Apparence")) {
				PED::CLEAR_ALL_PED_PROPS(PLAYER::PLAYER_PED_ID());
				PED::CLEAR_PED_DECORATIONS(PLAYER::PLAYER_PED_ID());
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 1, 0, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, 0, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, 0, 0, 0);
			}
			Menu::Break("OUTFIT MAKER");
			Menu::Option("~y~ COMING SOON ON 2.5");
		}
		break;
#pragma region bodyguard
		case bodyguards:
		{

			Menu::Title("Bodyguards");
			Menu::Subtitle("SPAWN A BODYGUARD");
			if (Menu::Option("Big Foot")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("cs_orleans");
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);

				int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_LEADER(playerPed, my_group);
				PED::SET_PED_AS_GROUP_MEMBER(createdPED, my_group);
				PED::SET_PED_NEVER_LEAVES_GROUP(createdPED, my_group);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
			}
			if (Menu::Option("CIA")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_CIASec_01");
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_SMG");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);

				int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_LEADER(playerPed, my_group);
				PED::SET_PED_AS_GROUP_MEMBER(createdPED, my_group);
				PED::SET_PED_NEVER_LEAVES_GROUP(createdPED, my_group);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
			}
			if (Menu::Option("Swat ")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_SMG");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);

				int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_LEADER(playerPed, my_group);
				PED::SET_PED_AS_GROUP_MEMBER(createdPED, my_group);
				PED::SET_PED_NEVER_LEAVES_GROUP(createdPED, my_group);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
			}
			if (Menu::Option("Sniper")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);

				int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_LEADER(playerPed, my_group);
				PED::SET_PED_AS_GROUP_MEMBER(createdPED, my_group);
				PED::SET_PED_NEVER_LEAVES_GROUP(createdPED, my_group);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
			}
			if (Menu::Option("Police")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_SMG");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);

				int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_LEADER(playerPed, my_group);
				PED::SET_PED_AS_GROUP_MEMBER(createdPED, my_group);
				PED::SET_PED_NEVER_LEAVES_GROUP(createdPED, my_group);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
			}
			if (Menu::Option("Striper2")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				char *anim = "mini@strip_club@lap_dance_2g@ld_2g_p2";
				char *animID = "ld_2g_p2_s2";

				int clone = PED::CLONE_PED(playerPed, pos.x, pos.y, pos.z);
				ENTITY::SET_ENTITY_INVINCIBLE(clone, false);

				STREAMING::REQUEST_ANIM_DICT(anim);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
					WAIT(0);

				AI::TASK_PLAY_ANIM(clone, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
			if (Menu::Option("Medical")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Hash fireworkl = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREWORK");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				char *anim = "rcmcollect_paperleadinout@";
				char *animID = "meditiate_idle";

				int clone = PED::CLONE_PED(playerPed, pos.x, pos.y, pos.z);
				ENTITY::SET_ENTITY_INVINCIBLE(clone, false);
				PED::SET_PED_COMBAT_ABILITY(clone, 100);
				WEAPON::GIVE_WEAPON_TO_PED(clone, fireworkl, fireworkl, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(clone, true);

				STREAMING::REQUEST_ANIM_DICT(anim);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
					WAIT(0);

				AI::TASK_PLAY_ANIM(clone, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
			if (Menu::Option("Ninja")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				char *anim = "amb@world_human_push_ups@male@base";
				char *animID = "base";

				int clone = PED::CLONE_PED(playerPed, pos.x, pos.y, pos.z);
				ENTITY::SET_ENTITY_INVINCIBLE(clone, false);

				STREAMING::REQUEST_ANIM_DICT(anim);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
					WAIT(0);

				AI::TASK_PLAY_ANIM(clone, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
			if (Menu::Option("Striper")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				char *anim = "mini@strip_club@pole_dance@pole_dance2";
				char *animID = "pd_dance_02";

				int clone = PED::CLONE_PED(playerPed, pos.x, pos.y, pos.z);
				ENTITY::SET_ENTITY_INVINCIBLE(clone, false);

				STREAMING::REQUEST_ANIM_DICT(anim);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
					WAIT(0);

				AI::TASK_PLAY_ANIM(clone, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
		}
		break;
#pragma endregion
#pragma region Protections
		case protect:
		{
			Menu::Title("Protections");
			Menu::Subtitle("MODDER PROTECT");
			Menu::Toggle("Anti Particle FX", Features::AntiFx, [] { Features::antiFx(Features::AntiFx); });
			Menu::Toggle("Anti Crash", Features::AntiCrash, [] { Features::antiCrash(Features::AntiCrash); });
			Menu::Option("More will be added soon");
		}
		break;
#pragma endregion
#pragma region Teleport
		case tpop:
		{
			Menu::Title("Teleport Options");
			Menu::Subtitle("TELEPORT");
			if (Menu::Option("Teleport to Waypoint"))
			{
				int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
				if (UI::DOES_BLIP_EXIST(WaypointHandle))
				{
					Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
					WaypointPos.z += 25.0f;
					int Handle = PLAYER::PLAYER_PED_ID();
					if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
						Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
					ENTITY::SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z, 0, 0, 0, 1);
					UI::_SET_NOTIFICATION_TEXT_ENTRY("Teleported to Waypoint");
				}
				else notifyMap("~r~Please set a Waypoint!");
			}
			Menu::Break("IPL MAPS");
			if (Menu::Option("North Yankton")) {
				STREAMING::REQUEST_IPL("prologue01");
				STREAMING::REQUEST_IPL("Prologue01c");
				STREAMING::REQUEST_IPL("Prologue01d");
				STREAMING::REQUEST_IPL("Prologue01e");
				STREAMING::REQUEST_IPL("Prologue01f");
				STREAMING::REQUEST_IPL("Prologue01g");
				STREAMING::REQUEST_IPL("prologue01h");
				STREAMING::REQUEST_IPL("prologue01i");
				STREAMING::REQUEST_IPL("prologue01j");
				STREAMING::REQUEST_IPL("prologue01k");
				STREAMING::REQUEST_IPL("prologue01z");
				STREAMING::REQUEST_IPL("prologue02");
				STREAMING::REQUEST_IPL("prologue03");
				STREAMING::REQUEST_IPL("prologue03b");
				STREAMING::REQUEST_IPL("prologue03_grv_cov");
				STREAMING::REQUEST_IPL("prologue03_grv_dug");
				STREAMING::REQUEST_IPL("prologue03_grv_fun");
				STREAMING::REQUEST_IPL("prologue04");
				STREAMING::REQUEST_IPL("prologue04b");
				STREAMING::REQUEST_IPL("prologue04_cover");
				STREAMING::REQUEST_IPL("prologue05");
				STREAMING::REQUEST_IPL("prologue05b");
				STREAMING::REQUEST_IPL("prologue06");
				STREAMING::REQUEST_IPL("prologue06b");
				STREAMING::REQUEST_IPL("prologue06_int");
				STREAMING::REQUEST_IPL("prologuerd");
				STREAMING::REQUEST_IPL("prologuerdb");
				STREAMING::REQUEST_IPL("prologue_DistantLights");
				STREAMING::REQUEST_IPL("prologue_grv_torch");
				STREAMING::REQUEST_IPL("prologue_m2_door");
				STREAMING::REQUEST_IPL("prologue_LODLights");
				STREAMING::REQUEST_IPL("DES_ProTree_start");
				Vector3 Coords;
				Coords.x = 3595.39673f; Coords.y = -4893.727f; Coords.z = 115.838394f;
				TPto(Coords);
			}
			if (Menu::Option("Porn Yacht")) {
				STREAMING::REQUEST_IPL("smboat");
				Vector3 Coords;
				Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
				TPto(Coords);
			}
			if (Menu::Option("Aircraft Carrier")) {
				STREAMING::REQUEST_IPL("hei_carrier");
				STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
				STREAMING::REQUEST_IPL("hei_Carrier_int1");
				STREAMING::REQUEST_IPL("hei_Carrier_int2");
				STREAMING::REQUEST_IPL("hei_Carrier_int3");
				STREAMING::REQUEST_IPL("hei_Carrier_int4");
				STREAMING::REQUEST_IPL("hei_Carrier_int5");
				STREAMING::REQUEST_IPL("hei_Carrier_int6");
				STREAMING::REQUEST_IPL("hei_carrier_LODLights");
				Vector3 Coords;
				Coords.x = 3069.330f; Coords.y = -4632.4f; Coords.z = 15.043f;
				TPto(Coords);
			}
			if (Menu::Option("Sunken Cargoship")) {
				STREAMING::REQUEST_IPL("sunkcargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
				TPto(Coords);
			}
			if (Menu::Option("Hospital")) {
				STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
				STREAMING::REQUEST_IPL("RC12B_Destroyed");
				Vector3 Coords;
				Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
				TPto(Coords);
			}
			if (Menu::Option("Oneil Farm")) {
				STREAMING::REMOVE_IPL("farm_burnt");
				STREAMING::REMOVE_IPL("farm_burnt_props");
				STREAMING::REQUEST_IPL("farm");
				STREAMING::REQUEST_IPL("farm_props");
				STREAMING::REQUEST_IPL("farmint");
				STREAMING::REQUEST_IPL("farmint_cap");
				Vector3 Coords;
				Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
				TPto(Coords);
			}
			if (Menu::Option("Life Invader Office")) {
				STREAMING::REQUEST_IPL("facelobby");
				STREAMING::REQUEST_IPL("facelobbyfake");
				Vector3 Coords;
				Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
				TPto(Coords);
			}
			if (Menu::Option("Cargoship")) {
				STREAMING::REQUEST_IPL("cargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
				TPto(Coords);
			}
			if (Menu::Option("Jewelry Store")) {
				STREAMING::REQUEST_IPL("jewel2fake");
				STREAMING::REQUEST_IPL("post_hiest_unload");
				STREAMING::REQUEST_IPL("bh1_16_refurb");
				Vector3 Coords;
				Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
				TPto(Coords);
			}
			if (Menu::Option("Morgue")) {
				STREAMING::REQUEST_IPL("Coroner_Int_on");
				Vector3 Coords;
				Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
				TPto(Coords);
			}

		}
		break;
#pragma endregion
#pragma region Model Changer
		case modelchanger:
		{
			Menu::Title("Model Changer");
			Menu::Subtitle("CHANGE YOUR MODEL");
			for (int i = 0; i < ARRAYSIZE(pedModels); i++)
			{
				if (Menu::Option(pedModels[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(pedModels[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);
				}
			}
		}
		break;
#pragma endregion
#pragma region Anim Changer
		case anim:
		{
			Menu::Title("Player Animations");
			Menu::Subtitle("ANIM YOUR PLAYER");
			if (Menu::Option("Clear Animation")) { Features::clearanim(); }
			if (Menu::Option("Sex Receiver")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); }
			if (Menu::Option("Sex Giver")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_a"); }
			if (Menu::Option("Stripper Dance")) { Features::doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
			if (Menu::Option("Pole Dance")) { Features::doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
			if (Menu::Option("Push Ups")) { Features::doAnimation("amb@world_human_push_ups@male@base", "base"); }
			if (Menu::Option("Sit Ups")) { Features::doAnimation("amb@world_human_sit_ups@male@base", "base"); }
			if (Menu::Option("Celebrate")) { Features::doAnimation("rcmfanatic1celebrate", "celebrate"); }
			if (Menu::Option("Electrocution")) { Features::doAnimation("ragdoll@human", "electrocute"); }
			if (Menu::Option("Suicide")) { Features::doAnimation("mp_suicide", "pistol"); }
			if (Menu::Option("Showering")) { Features::doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); }
		}
		break;
#pragma endregion
#pragma region sensa Changer
		case senas:
		{
			Menu::Title("Player Scenarios");
			Menu::Subtitle("SCENARIOS ANIMS");
			if (Menu::Option("Kill Animation")) AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
			if (Menu::Option("Paparizzi")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PAPARAZZI", 0, true);
			if (Menu::Option("Drug Dealer")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
			if (Menu::Option("Drinking Coffee")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_AA_COFFEE", 0, true);
			if (Menu::Option("Playing Instruments")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, true);
			if (Menu::Option("Flexing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
			if (Menu::Option("Jogging")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_JOG_STANDING", 0, true);
			if (Menu::Option("Binoculars")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_BINOCULARS", 0, true);
			if (Menu::Option("Clipboard")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CLIPBOARD", 0, true);
			if (Menu::Option("Bench Press")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
			if (Menu::Option("Chin Ups")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
			if (Menu::Option("BBQ")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_BBQ", 0, true);
			if (Menu::Option("Superhero")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUPERHERO", 0, true);
			if (Menu::Option("Fishing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_STAND_FISHING", 0, true);
			if (Menu::Option("Security")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
			if (Menu::Option("Leaf Blower")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
			if (Menu::Option("Film Shocking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
			if (Menu::Option("Idle Cop")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_COP_IDLES", 0, true);
			if (Menu::Option("Drinking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRINKING", 0, true);
			if (Menu::Option("Golf Player")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GOLF_PLAYER", 0, true);
			if (Menu::Option("Welding")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_WELDING", 0, true);
			if (Menu::Option("Smoking Pot")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SMOKING_POT", 0, true);
			if (Menu::Option("Hammering")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HAMMERING", 0, true);
			if (Menu::Option("Tennis")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
			if (Menu::Option("Drilling")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CONST_DRILL", 0, true);
		}
		break;
#pragma endregion
#pragma region Money
		case moneyop:
		{
			Menu::Title("Money Options");
			Menu::Subtitle("Loop");
			Menu::Break("~g~STEALTH MONEY");
			Menu::Toggle("10 Millions", Features::Stealtha, [] { Features::stealtha(Features::Stealtha); });
			Menu::Toggle("15 Millions", Features::Stealthb, [] { Features::stealthb(Features::Stealthb); });
			Menu::Toggle("200K", Features::Stealthc, [] { Features::stealthc(Features::Stealthc); });
			Menu::Toggle("100k", Features::Stealthd, [] { Features::stealthd(Features::Stealthd); });
			Menu::Toggle("50K", Features::Stealthe, [] { Features::stealthe(Features::Stealthe); });

		}
		break;
#pragma endregion
#pragma region Settings Menu
		case settings:
		{
			Menu::Title("Settings"); 
			Menu::Subtitle("SETTINGS");
			Menu::Toggle("Rainbow Menu", Features::rainbowmenu, [] { Features::Rainbowmenu(Features::rainbowmenu); });
			if (Menu::Float("Change Position", Menu::Settings::menuX, 0.099f, 0.128f))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::menuX = NumberKeyboard();
				}
			}
			Menu::MenuOption("Colors", settingstheme);
			if (Menu::Int("Scroll Delay", Menu::Settings::keyPressDelay2, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Int Delay", Menu::Settings::keyPressDelay3, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay3 = NumberKeyboard();
				}
			}

			Menu::Break("SOCIAL CLUB ACCOUNT");
			Menu::Option(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()));

		}
		break;
		case Credits:
		{
			Menu::Title("Credits");
			Menu::Subtitle("Developers");
			
		}
		break;
		case settingstheme:
		{
			Menu::Title("Colors");
			Menu::Subtitle("COLORS");
			Menu::MenuOption("Theme Loader", themeloader);
			Menu::MenuOption("Title Background", settingstitlerect);
			Menu::MenuOption("Selection Box", settingsscroller);
			Menu::MenuOption("Option Text", settingsoptiontext);
			Menu::MenuOption("Line Color", linesettings);


		}
		break;
		case themeloader:
		{
			Menu::Title("Theme Colors");
			Menu::Subtitle("CUSTOMIZE");
			if (Menu::Option("Red Theme")) {
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
				Menu::Settings::line = { 255, 0, 0, 255 };
			}
			if (Menu::Option("Blue Theme")) {
				Menu::Settings::titleRect = { 0, 0, 200, 255 };
				Menu::Settings::scroller = { 0, 0, 200, 255 };
				Menu::Settings::line = { 0, 0, 255, 255 };
			}
			if (Menu::Option("Green Theme")) {
				Menu::Settings::titleRect = { 0, 180, 0, 255 };
				Menu::Settings::scroller = { 0, 0, 180, 255 };
				Menu::Settings::line = { 0, 255, 0, 255 };
			}
			if (Menu::Option("Load Default Theme")) {
				Menu::Settings::titleText = { 255, 255, 255, 255, 7 };
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
				Menu::Settings::optionText = { 255, 255, 255, 255, 0 };
				Menu::Settings::optionRect = { 0, 0, 0, 110 };
				Menu::Settings::line = { 180, 0, 0, 255 };
			}
		}
		break;
		case settingstitlerect:
		{
			Menu::Title("Title Rect");
			Menu::Subtitle("THEME");
			if (Menu::Int("Red", Menu::Settings::titleRect.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::titleRect.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::titleRect.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::titleRect.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.a = NumberKeyboard();
				}
			}
		}
		break;
		case settingsoptiontext:
		{
			Menu::Title("Option Text");
			Menu::Subtitle("THEME");
			if (Menu::Int("Red", Menu::Settings::optionText.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::optionText.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::optionText.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.a = NumberKeyboard();
				}
			}
			Menu::MenuOption("Font", font);
		}
		break;
		case linesettings:
		{
			Menu::Title("Line Color");
			Menu::Subtitle(".XYZ");
			if (Menu::Int("Red", Menu::Settings::line.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::line.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::line.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::line.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::line.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::line.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::line.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::line.a = NumberKeyboard();
				}
			}
		}
		break;//Menu::Settings::line
		case font:
		{
			Menu::Title("Font");
			Menu::Subtitle("FONTS");
			if (Menu::Option("Chalet London")) { Menu::Settings::optionText.f = 0; }
			if (Menu::Option("House Script")) { Menu::Settings::optionText.f = 1; }
			if (Menu::Option("Monospace")) { Menu::Settings::optionText.f = 2; }
			if (Menu::Option("Wing Dings")) { Menu::Settings::optionText.f = 3; }
			if (Menu::Option("Chalet Comprime Cologne")) { Menu::Settings::optionText.f = 4; }
			if (Menu::Option("Pricedown")) { Menu::Settings::optionText.f = 7; }
		}
		break;
		case settingsscroller:
		{
			Menu::Title("Scroller");
			Menu::Subtitle("SCROLLER");
			if (Menu::Int("Red", Menu::Settings::scroller.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::scroller.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::scroller.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.a = NumberKeyboard();
				}
			}
		}
		break;


#pragma endregion
#pragma region Weapon
		case weaponop:
		{
			Menu::Title("Weapons Options");
			Menu::Subtitle("WEAPONS MODS");
			Menu::Break("~b~Shoot Options");
			if (Menu::Option("Give All Weapons")) {
				uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
				}
			}
			Menu::Toggle("Rainbow Gun", Features::rbgun, [] { Features::RBGuner(Features::rbgun); });
			Menu::Toggle("Gravity Gun", Features::Gravity, [] { Features::GravityGun(Features::Gravity); });

		}
		break;
#pragma endregion
#pragma region Vehicle Spawenr		
		case vehspawner: 
		{
			Menu::Title("Vehicle Spawner");
			Menu::Subtitle("SPAWN VEHICLES");
			Menu::MenuOption("Super Sports", SuperSports);
			Menu::MenuOption("Doomsday", Doomsday);
			Menu::MenuOption("Super", Super);
			Menu::MenuOption("Sports", Sports);
			Menu::MenuOption("Sport Classic", SportClassic);
			Menu::MenuOption("Offroad", Offroad);
			Menu::MenuOption("Sedans", Sedans);
			Menu::MenuOption("Coupes", Coupes);
			Menu::MenuOption("Muscle", Muscle);
			Menu::MenuOption("Boats", Boats);
			Menu::MenuOption("Commercial", Commercial);
			Menu::MenuOption("Compacts", Compacts);
			Menu::MenuOption("Cycles", Cycles);
			Menu::MenuOption("Emergency", Emergency);
			Menu::MenuOption("Helicopters", Helicopters);
			Menu::MenuOption("Industrial", Industrial);
			Menu::MenuOption("Military", Military);
			Menu::MenuOption("Motorcycles", Motorcycles);
			Menu::MenuOption("Planes", Planes);
			Menu::MenuOption("Service", Service);
			Menu::MenuOption("SUV", SUV);
			Menu::MenuOption("Trailer", Trailer);
			Menu::MenuOption("Trains", Trains);
			Menu::MenuOption("Utility", Utility);
			Menu::MenuOption("Vans", Vans);
			
			break;
		case Doomsday:
			Menu::Title("Doomsday");
			Menu::Subtitle("DOOMSDAY VEHICLES");
			for (auto car : Doomsday1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case SuperSports:
			Menu::Title("Super Sports");
			Menu::Subtitle("SUPER SPORTS VEHICLES");
			for (auto car : Supersports1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Super:
			Menu::Title("Super");			
			Menu::Subtitle("SUPER VEHICLES");
			for (auto car : Super1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Sports:
			Menu::Title("Sports");
			Menu::Subtitle("SPORTS VEHICLES");
			for (auto car : Sports1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case SportClassic:
			Menu::Title("Sports Classic");
			Menu::Subtitle("CLASSIC VEHICLES");
			for (auto car : SportsClassics1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Offroad:
			Menu::Title("Offroad");
			Menu::Subtitle("OFFROAD VEHICLES");
			for (auto car : OffRoad1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Sedans:
			Menu::Title("Sedans");
			Menu::Subtitle("SEDANS VEHICLES");
			for (auto car : Sedans1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Coupes:
			Menu::Title("Coupes");
			Menu::Subtitle("COUPES VEHICLES");
			for (auto car : Coupes1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Muscle:
			Menu::Title("Muscle");
			Menu::Subtitle("MUSCLE VEHICLES");
			for (auto car : Muscle1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Boats:
			Menu::Title("Boats");
			Menu::Subtitle("BOATS");
			for (auto car : Boats1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Commercial:
			Menu::Title("Commercial");
			Menu::Subtitle("COMMERCIAL VEHICLES");
			for (auto car : Commercial1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Compacts:
			Menu::Title("Compacts");
			Menu::Subtitle("COMPACT VEHICLES");
			for (auto car : Compacts1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Cycles:
			Menu::Title("Cycles");
			Menu::Subtitle("CYCLES VEHICLES");
			for (auto car : Cycles1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Emergency:
			Menu::Title("Emergency");
			Menu::Subtitle("EMERGENCY VEHICLES");
			for (auto car : Emergency1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Helicopters:
			Menu::Title("Helicopters");
			Menu::Subtitle("HELICOPTERS");
			for (auto car : Helicopters1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Industrial:
			Menu::Title("Industrial");
			Menu::Subtitle("INDUSTRIALS VEHICLES");
			for (auto car : Industrial1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Military:
			Menu::Title("Military");
			Menu::Subtitle("MILLITARY VEHICLES");
			for (auto car : Military1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Motorcycles:
			Menu::Title("Motorcycles");
			Menu::Subtitle("MOTOCYCLES");
			for (auto car : Motorcycles1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Planes:
			Menu::Title("Planes");
			Menu::Subtitle("PLANESS");
			for (auto car : Planes1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Service:
			Menu::Title("Service");
			Menu::Subtitle("SERVICE VEHICLES");
			for (auto car : Service1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case SUV:
			Menu::Title("SUV");
			Menu::Subtitle("SUV VEHICLES");
			for (auto car : SUVs1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Trailer:
			Menu::Title("Trailer");
			Menu::Subtitle("TRAILER");
			for (auto car : Trailer1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Trains:
			Menu::Title("Trains");
			Menu::Subtitle("TRAINS");
			for (auto car : Trains1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Utility:
			Menu::Title("Utility");
			Menu::Subtitle("UTILITY VEHICLES");
			for (auto car : Utility1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		case Vans:
			Menu::Title("Vans");
			Menu::Subtitle("VANS");
			for (auto car : Vans1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			break;
		}
						 break;
#pragma endregion
#pragma region level1
		case level1:
		{
			Menu::Title("Level 1-500");
			Menu::Subtitle("SET RANK OPTIONS");
			if (Menu::Option("Rank 50")) {
				Features::SetRank(50);
			}
			if (Menu::Option("Rank 80")) {
				Features::SetRank(80);
			}
			if (Menu::Option("Rank 120")) {
				Features::SetRank(120);
			}
			if (Menu::Option("Rank 150")) {
				Features::SetRank(150);
			}
			if (Menu::Option("Rank 200")) {
				Features::SetRank(200);
			}
			if (Menu::Option("Rank 300")) {
				Features::SetRank(300);
			}
			if (Menu::Option("Rank 420")) {
				Features::SetRank(420);
			}
			if (Menu::Option("Rank 450")) {
				Features::SetRank(450);
			}
			if (Menu::Option("Rank 800")) {
				Features::SetRank(800);
			}
			if (Menu::Option("Rank 1000")) {
				Features::SetRank(1000);
			}
			if (Menu::Option("Rank 2500")) {
				Features::SetRank(2500);
			}
			if (Menu::Option("Rank 3000")) {
				Features::SetRank(3000);
			}
			if (Menu::Option("Rank 5000")) {
				Features::SetRank(5000);
			}
			if (Menu::Option("Rank 8000")) {
				Features::SetRank(8000);
			}
		}
		break;
#pragma endregion
#pragma region recov
		case maxskill:
		{
			Menu::Title("Recovery Options");
			Menu::Subtitle("UNLOCK OPTIONS");
			if (Menu::Option("Set Max Skill")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STRN"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_stam"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_strn"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_lung"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_driv"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_fly"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_sho"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_script_increase_stl"), 100, 1);
				notifyMap("~g~Max Skills Set!");
			} 
			if (Menu::Option("Maximum Snacks")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_YUM_SNACKS"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_HEALTH_SNACKS"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_EPIC_SNACKS"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_OF_ORANGE_BOUGHT"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CIGARETTES_BOUGHT"), 2000000000, 1);
			}
			if (Menu::Option("Maximus Fireworks")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_BLUE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_BLUE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_BLUE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_BLUE"), 2000000000, 1);
			}
			if (Menu::Option("Clear Reports")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, true);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, true);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OVERALL_BADSPORT"), 0, true);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_CHAR_IS_BADSPORT"), false, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, 1);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, 1);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OVERALL_BADSPORT"), 0, 1);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_CHAR_IS_BADSPORT"), false, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_ISPUNISHED"), 0, 1);
				notifyMap("~g~Reports Removed!");
			}
			if (Menu::Option("Unlock All Tattoos")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_12"), -1, 1);
				notifyMap("~g~Tattoos Unlocked!");
			}
			if (Menu::Option("Unlock Weapon Skins")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MOLOTOV _ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_PISTOL50_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_APPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MICROSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ASLTSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADVRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CMBTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ASLTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_PUMP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SAWNOFF_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BULLPUP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SNIPERRFL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_HVYSNIPER_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_RPG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MINIGUNS_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_GRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_SMKGRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_STKYBMB_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MOLOTOV_ENEMY_KILLS"), 600, 0);
				notifyMap("~g~All Weapon Skins Unlocked!");
			}
			if (Menu::Option("Purchase Clothing")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TORSO"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_DECL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TORSO"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_DECL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TEETH"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_0"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_12"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_13"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_14"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_15"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_16"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_17"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_18"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_19"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_21"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_22"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_23"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_25"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_26"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_27"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_28"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_29"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_30"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_31"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_32"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_33"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_34"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_35"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_36"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_37"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_38"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_39"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_DLC_APPAREL_ACQUIRED_40"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				notifyMap("~g~Clothing Unlocked!");
			}
			if (Menu::Option("Full Recovery")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);

				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
				UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~b~Full Recovery Done");
				UI::_DRAW_NOTIFICATION(FALSE, FALSE);
			}
			if (Menu::Option("Unlock LSC")) {
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS "), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
				notifyMap("~g~Why Hack?!");
			}
		}
		break;
#pragma endregion
#pragma region Recovery Menu
		case recover:
		{
			Menu::Title("Recovery");
			Menu::Subtitle("UNLOCK AND LEVELS");
			Menu::MenuOption("Level Options", level1);
			Menu::MenuOption("Recovery Unlocks", maxskill);
			if (Menu::Option("Clear Badsport Stats")) {
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
			}
			if (Menu::Option("Clear Reports")) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_RESET_MINUTES"), 1.0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, true);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, true);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OVERALL_BADSPORT"), 0, true);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_CHAR_IS_BADSPORT"), false, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BAD_SPORT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_CHEAT_BITSET"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_REPORT_STRENGTH"), 32, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_COMMEND_STRENGTH"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_FRIENDLY"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_HELPFUL"), 100, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GRIEFING"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_UGC"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_VC_HATE"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GAME_EXPLOITS"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_ISPUNISHED"), 0, true);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_BADSPORT_RESET_MINUTES"), 1.0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, 1);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OVERALL_BADSPORT"), 0, 1);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_CHAR_IS_BADSPORT"), false, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_ISPUNISHED"), 0, 1);
				STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OVERALL_BADSPORT"), 0, 1);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_CHAR_IS_BADSPORT"), false, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_BAD_SPORT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_CHEAT_BITSET"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_REPORT_STRENGTH"), 32, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_COMMEND_STRENGTH"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_FRIENDLY"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_HELPFUL"), 100, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GRIEFING"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_OFFENSIVE_UGC"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_VC_HATE"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_GAME_EXPLOITS"), 0, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_ISPUNISHED"), 0, 1);
				notifyMap("~g~Reports Removed");
			}
		}


		}
		Menu::End();
		WAIT(0);
		}
	}

void ScriptMain() {
	srand(GetTickCount());

	main();
}

void titlebox()
{
}