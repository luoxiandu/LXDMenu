#include "stdafx.h"
#include "Math.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <conio.h>

Vehicle veh;
Object latestObj;

#define PROP_MONEY_BAG_01 0x113FD533
#define PICKUP_MONEY_CASE 0xCE6FDD6B

int timeer = 0;
long in = 0;
int intor = 0;
long out = 0;
bool stream = true;
bool safemode = true;

int fam;
int Face_ = 0;
int Glasses_ = 0;
int Ears_ = 0;
int Mask_ = 0;
int Hair_ = 0;
int Torso_ = 0;
int Legs_ = 0;
int Hands_ = 0;
int Shoes_ = 0;
int Watches_ = 0;
int Special1_ = 0;
int Special2_ = 0;
int Special3_ = 0;
int Texture_ = 0;
int Torso2_ = 0;

#pragma endregion

bool hasTurbo = false;
int VehID;
int Spoilers_ = 0;
int Tint_ = 0;
int Interior_ = 0;
int Grill_ = 0;
int Exhaust_ = 0;
int Skirts_ = 0;
int Suspension_ = 0;
int Hoods_ = 0;
int Bumpers_ = 0;
int Transmission_ = 0;
int Brakes_ = 0;
int Armor_ = 0;
int Colour_ = 0;
int Prim_ = 0;
int Sec_ = 0;
int Red_ = 0;
int Green_ = 0;
int Blue_ = 0;
bool rdev;
int horns = 0;



std::vector<std::string> StringVector{ "test", "testing", "testing123" };
int StringVectorPosition = 0;
std::vector<char*> CharVector{ "test1", "testing1", "testing1231" };
int CharVectorPosition = 0;
std::vector<int> IntVector{ 1, 2, 3, 5, 6, 7, 1234, 13041 };
int IntVectorPosition = 0;
std::vector<float> FloatVector{ 1.2345f, 5.1234f, 5.1237f, 8.3124f };
int FloatVectorPosition = 0;
bool risky = false;
std::string namech;
bool GalExist()
{
	DWORD dwAttrib = GetFileAttributesA(".\\MasterMenu");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}
static char* DiamondDLC[] = {

"CARACARA2",
"DRAFTER",
"DYNASTY",
"EMERUS",
"GAUNTLET3",
"GAUNTLET4",
"HELLION",
"ISSI7",
"JUGULAR",
"KRIEGER",
"LOCUST",
"NEBULA",
"NEO",
"NOVAK",
"PARAGON",
"PARAGON2",
"PEYOTE2",
"RROCKET",
"S80RR",
"THRAX",
"ZION3",
"ZORRUSSO"
};
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
static char* smugglers1[] = {
	"VIGILANTE", "BOMBUSHKA", "ALPHAZ1", "TULA", "HUNTER",
	"ROGUE", "PYRO", "MOGUL", "NOKOTA", "MOLOTOK", "SEABREEZE",
	"HAVOK", "microlight", "HOWARD", "STARLING", "RAPIDGT3",
	"RETINUE", "CYCLONE", "VISIONE"
};
static char* Gunrunning1[] = {
	"APC", "Ardent", "Caddy3", "Cheetah2", "Dune3", "Halftrack", "Hauler2", "Insurgent3",
	"Nightshark", "Oppressor", "Phantom3", "Tampa3", "Technical13", "Torero", "TrailerLarge",
	"Trailers4", "Trailersma11", "Vagner", "Xa21"
};
static char* Doomsday[] = {
	"Z190", "akula", "autarch", "avenger", "avenger2", "barrage", "chernobog",
	"comet4", "comet5", "deluxo", "gt500", "hermes", "hustler", "kamacho",
	"khanjali", "neon", "pariah", "raiden","revolter","riata","riot2","savestra",
	"sc1","sentinel3","streiter","stromberg", "thruster","va_stromberg",
	"viseris","volatol","yosemite"
};
static char* SportSeries[] = {
	"cheburek", "dominator3", "ellie", "entity2", "fagaloa", "flashgt", "gb200",
	"hotring", "issi3", "jester3", "michelli", "seasparrow", "taipan", "tezeract",
	"tyrant"
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

#pragma region allobjects
char*  objs2[] = {
	"prop_a4_pile_01",
	"prop_a4_sheet_01",
	"prop_a4_sheet_02",
	"prop_a4_sheet_03",
	"prop_a4_sheet_04",
	"prop_a4_sheet_05",
	"prop_abat_roller_static",
	"prop_abat_slide",
	"prop_acc_guitar_01",
	"prop_acc_guitar_01_d1",
	"prop_aerial_01a",
	"prop_aerial_01b",
	"prop_aerial_01c",
	"prop_aerial_01d",
	"prop_afsign_amun",
	"prop_afsign_vbike",
	"prop_agave_01",
	"prop_agave_02",
	"prop_aiprort_sign_01",
	"prop_aiprort_sign_02",
	"prop_aircon_l_01",
	"prop_aircon_l_02",
	"prop_aircon_l_03",
	"prop_aircon_l_04",
	"prop_aircon_m_09",
	"prop_aircon_s_01a",
	"prop_aircon_s_02a",
	"prop_aircon_s_02b",
	"prop_aircon_s_03a",
	"prop_aircon_s_03b",
	"prop_aircon_s_04a",
	"prop_aircon_s_05a",
	"prop_aircon_s_06a",
	"prop_aircon_s_07a",
	"prop_aircon_s_07b",
	"prop_airhockey_01",
	"prop_air_bagloader",
	"prop_air_bagloader2",
	"prop_air_barrier",
	"prop_air_bench_01",
	"prop_air_bench_02",
	"prop_air_bigradar_l1",
	"prop_air_bigradar_l2",
	"prop_air_bigradar_slod",
	"prop_air_blastfence_01",
	"prop_air_blastfence_02",
	"prop_air_bridge01",
	"prop_air_bridge02",
	"prop_air_cargoloader_01",
	"prop_air_cargo_01a",
	"prop_air_cargo_01b",
	"prop_air_cargo_01c",
	"prop_air_cargo_02a",
	"prop_air_cargo_02b",
	"prop_air_cargo_03a",
	"prop_air_cargo_04a",
	"prop_air_cargo_04b",
	"prop_air_cargo_04c",
	"prop_air_chock_01",
	"prop_air_chock_03",
	"prop_air_chock_04",
	"prop_air_fueltrail1",
	"prop_air_fueltrail2",
	"prop_air_gasbogey_01",
	"prop_air_generator_01",
	"prop_air_generator_03",
	"prop_air_hoc_paddle_01",
	"prop_air_hoc_paddle_02",
	"prop_air_lights_01a",
	"prop_air_lights_01b",
	"prop_air_lights_03a",
	"prop_air_luggtrolley",
	"prop_air_mast_01",
	"prop_air_mast_02",
	"prop_air_monhut_01",
	"prop_air_monhut_02",
	"prop_air_monhut_03",
	"prop_air_propeller01",
	"prop_air_radar_01",
	"prop_air_stair_01",
	"prop_air_stair_02",
	"prop_air_stair_03",
	"prop_air_stair_04a",
	"prop_air_stair_04b",
	"prop_air_towbar_01",
	"prop_air_towbar_02",
	"prop_air_towbar_03",
	"prop_air_trailer_4a",
	"prop_air_trailer_4b",
	"prop_air_trailer_4c",
	"prop_air_watertank1",
	"prop_air_watertank2",
	"prop_air_windsock_base",
	"prop_air_woodsteps",
	"prop_alarm_01",
	"prop_alarm_02",
	"prop_alien_egg_01",
	"prop_aloevera_01",
	"prop_amanda_note_01",
	"prop_amanda_note_01b",
	"prop_amb_40oz_02",
	"prop_amb_40oz_03",
	"prop_amb_beer_bottle",
	"prop_amb_ciggy_01",
	"prop_amb_donut",
	"prop_amb_handbag_01",
	"prop_amb_phone",
	"prop_amp_01",
	"prop_am_box_wood_01",
	"prop_anim_cash_note",
	"prop_anim_cash_note_b",
	"prop_anim_cash_pile_01",
	"prop_anim_cash_pile_02",
	"prop_apple_box_01",
	"prop_apple_box_02",
	"prop_arcade_01",
	"prop_arcade_02",
	"prop_arc_blueprints_01",
	"prop_armchair_01",
	"prop_armenian_gate",
	"prop_armour_pickup",
	"prop_arm_gate_l",
	"prop_arm_wrestle_01",
	"prop_artgallery_02_dl",
	"prop_artgallery_02_dr",
	"prop_artgallery_dl",
	"prop_artgallery_dr",
	"prop_artifact_01",
	"prop_ashtray_01",
	"prop_asteroid_01",
	"prop_atm_02",
	"prop_atm_03",
	"prop_attache_case_01",
	"prop_aviators_01",
	"prop_a_base_bars_01",
	"prop_a_trailer_door_01",
	"prop_bahammenu",
	"prop_ballistic_shield",
	"prop_ballistic_shield_lod1",
	"prop_bandsaw_01",
	"prop_bank_shutter",
	"prop_bank_vaultdoor",
	"prop_barbell_01",
	"prop_barbell_02",
	"prop_barbell_100kg",
	"prop_barbell_10kg",
	"prop_barbell_20kg",
	"prop_barbell_30kg",
	"prop_barbell_40kg",
	"prop_barbell_50kg",
	"prop_barbell_60kg",
	"prop_barbell_80kg",
	"prop_barier_conc_01b",
	"prop_barier_conc_01c",
	"prop_barier_conc_02b",
	"prop_barier_conc_02c",
	"prop_barier_conc_03a",
	"prop_barier_conc_04a",
	"prop_barier_conc_05a",
	"prop_barier_conc_05b",
	"prop_barn_door_l",
	"prop_barn_door_r",
	"prop_barrachneon",
	"prop_barrel_01a",
	"prop_barrel_02a",
	"prop_barrel_02b",
	"prop_barrel_03a",
	"prop_barrel_03d",
	"prop_barrel_float_1",
	"prop_barrel_float_2",
	"prop_barriercrash_03",
	"prop_barriercrash_04",
	"prop_barrier_wat_01a",
	"prop_barrier_wat_03b",
	"prop_barrier_work01c",
	"prop_barry_table_detail",
	"prop_bar_coastbarr",
	"prop_bar_coastchamp",
	"prop_bar_coastdusc",
	"prop_bar_coastmount",
	"prop_bar_cooler_01",
	"prop_bar_cooler_03",
	"prop_bar_fridge_01",
	"prop_bar_fridge_02",
	"prop_bar_fridge_03",
	"prop_bar_fridge_04",
	"prop_bar_ice_01",
	"prop_bar_napkindisp",
	"prop_bar_pump_01",
	"prop_bar_pump_04",
	"prop_bar_pump_05",
	"prop_bar_pump_06",
	"prop_bar_pump_07",
	"prop_bar_pump_08",
	"prop_bar_pump_09",
	"prop_bar_pump_10",
	"prop_bar_sink_01",
	"prop_bar_stool_01",
	"prop_basejump_target_01",
	"prop_basketball_net",
	"prop_bath_dirt_01",
	"prop_battery_01",
	"prop_battery_02",
	"prop_bball_arcade_01",
	"prop_bbq_2",
	"prop_bbq_3",
	"prop_beachbag_01",
	"prop_beachbag_02",
	"prop_beachbag_03",
	"prop_beachbag_04",
	"prop_beachbag_05",
	"prop_beachbag_06",
	"prop_beachbag_combo_01",
	"prop_beachbag_combo_02",
	"prop_beachball_02",
	"prop_beachflag_le",
	"prop_beach_bars_01",
	"prop_beach_bars_02",
	"prop_beach_bbq",
	"prop_beach_dip_bars_01",
	"prop_beach_dip_bars_02",
	"prop_beach_fire",
	"prop_beach_lg_float",
	"prop_beach_lg_stretch",
	"prop_beach_lg_surf",
	"prop_beach_lotion_01",
	"prop_beach_lotion_02",
	"prop_beach_lotion_03",
	"prop_beach_punchbag",
	"prop_beach_rings_01",
	"prop_beach_sculp_01",
	"prop_beach_towel_02",
	"prop_beach_volball01",
	"prop_beach_volball02",
	"prop_beerneon",
	"prop_beer_bison",
	"prop_beer_box_01",
	"prop_beer_neon_01",
	"prop_beer_neon_02",
	"prop_beer_neon_03",
	"prop_beer_neon_04",
	"prop_beggers_sign_01",
	"prop_beggers_sign_02",
	"prop_beggers_sign_03",
	"prop_beggers_sign_04",
	"prop_bench_01b",
	"prop_bench_01c",
	"prop_bench_04",
	"prop_bench_05",
	"prop_bench_09",
	"prop_beta_tape",
	"prop_beware_dog_sign",
	"prop_bh1_03_gate_l",
	"prop_bh1_03_gate_r",
	"prop_bh1_08_mp_gar",
	"prop_bh1_09_mp_gar",
	"prop_bh1_09_mp_l",
	"prop_bh1_09_mp_r",
	"prop_bh1_16_display",
	"prop_bh1_44_door_01l",
	"prop_bh1_44_door_01r",
	"prop_bh1_48_backdoor_l",
	"prop_bh1_48_backdoor_r",
	"prop_bh1_48_gate_1",
	"prop_bhhotel_door_l",
	"prop_bhhotel_door_r",
	"prop_big_bag_01",
	"prop_big_clock_01",
	"prop_big_shit_01",
	"prop_big_shit_02",
	"prop_bikerack_2",
	"prop_bikini_disp_01",
	"prop_bikini_disp_02",
	"prop_bikini_disp_03",
	"prop_bikini_disp_04",
	"prop_bikini_disp_05",
	"prop_bikini_disp_06",
	"prop_billboard_01",
	"prop_billboard_02",
	"prop_billboard_03",
	"prop_billboard_04",
	"prop_billboard_05",
	"prop_billboard_06",
	"prop_billboard_07",
	"prop_billboard_08",
	"prop_billboard_09",
	"prop_billboard_09wall",
	"prop_billboard_10",
	"prop_billboard_11",
	"prop_billboard_12",
	"prop_billboard_13",
	"prop_billboard_14",
	"prop_billboard_15",
	"prop_billboard_16",
	"prop_billb_frame01a",
	"prop_billb_frame01b",
	"prop_billb_frame02a",
	"prop_billb_frame02b",
	"prop_billb_frame03a",
	"prop_billb_frame03b",
	"prop_billb_frame03c",
	"prop_billb_frame04a",
	"prop_billb_frame04b",
	"prop_binoc_01",
	"prop_bin_04a",
	"prop_bin_10a",
	"prop_bin_10b",
	"prop_bin_11a",
	"prop_bin_11b",
	"prop_bin_12a",
	"prop_bin_13a",
	"prop_bin_14a",
	"prop_bin_14b",
	"prop_bin_beach_01d",
	"prop_bin_delpiero",
	"prop_bin_delpiero_b",
	"prop_biolab_g_door",
	"prop_biotech_store",
	"prop_bison_winch",
	"prop_blackjack_01",
	"prop_bleachers_01",
	"prop_bleachers_02",
	"prop_bleachers_03",
	"prop_bleachers_04",
	"prop_bleachers_05",
	"prop_blox_spray",
	"prop_bmu_01",
	"prop_bmu_01_b",
	"prop_bmu_02",
	"prop_bmu_02_ld",
	"prop_bmu_02_ld_cab",
	"prop_bmu_02_ld_sup",
	"prop_bmu_track01",
	"prop_bmu_track02",
	"prop_bmu_track03",
	"prop_bodyarmour_02",
	"prop_bodyarmour_03",
	"prop_bodyarmour_04",
	"prop_bodyarmour_05",
	"prop_bodyarmour_06",
	"prop_bollard_01a",
	"prop_bollard_01b",
	"prop_bollard_01c",
	"prop_bollard_03a",
	"prop_bomb_01",
	"prop_bomb_01_s",
	"prop_bonesaw",
	"prop_bongos_01",
	"prop_bong_01",
	"prop_boogbd_stack_01",
	"prop_boogbd_stack_02",
	"prop_boogieboard_01",
	"prop_boogieboard_02",
	"prop_boogieboard_03",
	"prop_boogieboard_04",
	"prop_boogieboard_05",
	"prop_boogieboard_06",
	"prop_boogieboard_07",
	"prop_boogieboard_08",
	"prop_boogieboard_09",
	"prop_boogieboard_10",
	"prop_boombox_01",
	"prop_bottle_cap_01",
	"prop_bowling_ball",
	"prop_bowling_pin",
	"prop_bowl_crisps",
	"prop_boxcar5_handle",
	"prop_boxing_glove_01",
	"prop_boxpile_10a",
	"prop_boxpile_10b",
	"prop_box_ammo01a",
	"prop_box_ammo02a",
	"prop_box_ammo03a_set",
	"prop_box_ammo03a_set2",
	"prop_box_ammo04a",
	"prop_box_ammo05b",
	"prop_box_ammo07a",
	"prop_box_ammo07b",
	"prop_box_guncase_01a",
	"prop_box_guncase_02a",
	"prop_box_guncase_03a",
	"prop_box_tea01a",
	"prop_box_wood05a",
	"prop_box_wood05b",
	"prop_box_wood08a",
	"prop_breadbin_01",
	"prop_bread_rack_01",
	"prop_bread_rack_02",
	"prop_broken_cboard_p1",
	"prop_broken_cboard_p2",
	"prop_broken_cell_gate_01",
	"prop_broom_unit_01",
	"prop_bskball_01",
	"prop_bs_map_door_01",
	"prop_buckets_02",
	"prop_bucket_01a",
	"prop_bucket_01b",
	"prop_bucket_02a",
	"prop_buck_spade_01",
	"prop_buck_spade_02",
	"prop_buck_spade_03",
	"prop_buck_spade_04",
	"prop_buck_spade_05",
	"prop_buck_spade_06",
	"prop_buck_spade_07",
	"prop_buck_spade_08",
	"prop_buck_spade_09",
	"prop_buck_spade_10",
	"prop_bumper_01",
	"prop_bumper_02",
	"prop_bumper_03",
	"prop_bumper_04",
	"prop_bumper_05",
	"prop_bumper_06",
	"prop_bumper_car_01",
	"prop_burto_gate_01",
	"prop_bush_dead_02",
	"prop_bush_grape_01",
	"prop_bush_ivy_01_1m",
	"prop_bush_ivy_01_2m",
	"prop_bush_ivy_01_bk",
	"prop_bush_ivy_01_l",
	"prop_bush_ivy_01_pot",
	"prop_bush_ivy_01_r",
	"prop_bush_ivy_01_top",
	"prop_bush_ivy_02_1m",
	"prop_bush_ivy_02_2m",
	"prop_bush_ivy_02_l",
	"prop_bush_ivy_02_pot",
	"prop_bush_ivy_02_r",
	"prop_bush_ivy_02_top",
	"prop_bush_lrg_01",
	"prop_bush_lrg_01b",
	"prop_bush_lrg_01c",
	"prop_bush_lrg_01d",
	"prop_bush_lrg_01e",
	"prop_bush_lrg_02",
	"prop_bush_lrg_02b",
	"prop_bush_lrg_03",
	"prop_bush_lrg_03b",
	"prop_bush_lrg_04b",
	"prop_bush_lrg_04c",
	"prop_bush_lrg_04d",
	"prop_bush_med_01",
	"prop_bush_med_02",
	"prop_bush_med_03",
	"prop_bush_med_05",
	"prop_bush_med_06",
	"prop_bush_med_07",
	"prop_bush_neat_01",
	"prop_bush_neat_02",
	"prop_bush_neat_03",
	"prop_bush_neat_04",
	"prop_bush_neat_05",
	"prop_bush_neat_06",
	"prop_bush_neat_07",
	"prop_bush_neat_08",
	"prop_bush_ornament_01",
	"prop_bush_ornament_02",
	"prop_bush_ornament_03",
	"prop_bush_ornament_04",
	"prop_busker_hat_01",
	"prop_byard_bench01",
	"prop_byard_bench02",
	"prop_byard_block_01",
	"prop_byard_boat01",
	"prop_byard_boat02",
	"prop_byard_chains01",
	"prop_byard_dingy",
	"prop_byard_elecbox01",
	"prop_byard_elecbox02",
	"prop_byard_elecbox03",
	"prop_byard_elecbox04",
	"prop_byard_floatpile",
	"prop_byard_float_01",
	"prop_byard_float_01b",
	"prop_byard_float_02",
	"prop_byard_float_02b",
	"prop_byard_hoist",
	"prop_byard_hoist_2",
	"prop_byard_hoses01",
	"prop_byard_hoses02",
	"prop_byard_ladder01",
	"prop_byard_machine01",
	"prop_byard_machine02",
	"prop_byard_machine03",
	"prop_byard_motor_01",
	"prop_byard_motor_02",
	"prop_byard_motor_03",
	"prop_byard_net02",
	"prop_byard_phone",
	"prop_byard_pipes01",
	"prop_byard_pipe_01",
	"prop_byard_planks01",
	"prop_byard_pulley01",
	"prop_byard_rack",
	"prop_byard_ramp",
	"prop_byard_rampold",
	"prop_byard_rowboat1",
	"prop_byard_rowboat2",
	"prop_byard_rowboat3",
	"prop_byard_rowboat4",
	"prop_byard_rowboat5",
	"prop_byard_scfhold01",
	"prop_byard_sleeper01",
	"prop_byard_sleeper02",
	"prop_byard_steps_01",
	"prop_byard_tank_01",
	"prop_byard_trailer01",
	"prop_byard_trailer02",
	"prop_b_board_blank",
	"prop_c4_final",
	"prop_c4_final_green",
	"prop_cabinet_01",
	"prop_cabinet_01b",
	"prop_cabinet_02b",
	"prop_cablespool_01a",
	"prop_cablespool_01b",
	"prop_cablespool_02",
	"prop_cablespool_03",
	"prop_cablespool_04",
	"prop_cablespool_05",
	"prop_cablespool_06",
	"prop_cable_hook_01",
	"prop_camera_strap",
	"prop_candy_pqs",
	"prop_can_canoe",
	"prop_cap_01",
	"prop_cap_01b",
	"prop_cap_row_01",
	"prop_cap_row_01b",
	"prop_cap_row_02",
	"prop_cap_row_02b",
	"prop_carcreeper",
	"prop_cargo_int",
	"prop_carjack",
	"prop_carjack_l2",
	"prop_carrier_bag_01",
	"prop_carrier_bag_01_lod",
	"prop_cartwheel_01",
	"prop_carwash_roller_horz",
	"prop_carwash_roller_vert",
	"prop_car_battery_01",
	"prop_car_bonnet_01",
	"prop_car_bonnet_02",
	"prop_car_door_01",
	"prop_car_door_02",
	"prop_car_door_03",
	"prop_car_door_04",
	"prop_car_engine_01",
	"prop_car_exhaust_01",
	"prop_car_ignition",
	"prop_car_seat",
	"prop_casey_sec_id",
	"prop_cash_case_01",
	"prop_cash_case_02",
	"prop_cash_crate_01",
	"prop_cash_dep_bag_01",
	"prop_cash_envelope_01",
	"prop_cash_note_01",
	"prop_cash_pile_01",
	"prop_cash_pile_02",
	"prop_cash_trolly",
	"prop_casino_door_01l",
	"prop_casino_door_01r",
	"prop_cattlecrush",
	"prop_cat_tail_01",
	"prop_cctv_02_sm",
	"prop_cctv_cont_01",
	"prop_cctv_cont_03",
	"prop_cctv_cont_04",
	"prop_cctv_cont_05",
	"prop_cctv_cont_06",
	"prop_cctv_unit_01",
	"prop_cctv_unit_02",
	"prop_cctv_unit_05",
	"prop_cementmixer_01a",
	"prop_cementmixer_02a",
	"prop_ceramic_jug_01",
	"prop_ceramic_jug_cork",
	"prop_ch1_07_door_01l",
	"prop_ch1_07_door_01r",
	"prop_ch1_07_door_02l",
	"prop_ch1_07_door_02r",
	"prop_ch2_05d_g_door",
	"prop_ch2_07b_20_g_door",
	"prop_ch2_09b_door",
	"prop_ch2_09c_garage_door",
	"prop_ch3_01_trlrdoor_l",
	"prop_ch3_01_trlrdoor_r",
	"prop_ch3_04_door_01l",
	"prop_ch3_04_door_01r",
	"prop_ch3_04_door_02",
	"prop_chair_01a",
	"prop_chair_01b",
	"prop_chair_02",
	"prop_chair_03",
	"prop_chair_04a",
	"prop_chair_04b",
	"prop_chair_05",
	"prop_chair_06",
	"prop_chair_07",
	"prop_chair_08",
	"prop_chair_09",
	"prop_chair_10",
	"prop_chair_pile_01",
	"prop_chall_lamp_01",
	"prop_chall_lamp_01n",
	"prop_chall_lamp_02",
	"prop_chateau_chair_01",
	"prop_cheetah_covered",
	"prop_chem_grill",
	"prop_chem_grill_bit",
	"prop_chem_vial_02",
	"prop_chem_vial_02b",
	"prop_cherenneon",
	"prop_chickencoop_a",
	"prop_chip_fryer",
	"prop_choc_ego",
	"prop_choc_meto",
	"prop_choc_pq",
	"prop_ch_025c_g_door_01",
	"prop_cigar_01",
	"prop_cigar_02",
	"prop_cigar_03",
	"prop_cigar_pack_01",
	"prop_cigar_pack_02",
	"prop_clapper_brd_01",
	"prop_cleaver",
	"prop_cliff_paper",
	"prop_clippers_01",
	"prop_clothes_rail_02",
	"prop_clothes_rail_03",
	"prop_clothes_rail_2b",
	"prop_clothes_tub_01",
	"prop_clown_chair",
	"prop_cntrdoor_ld_l",
	"prop_cntrdoor_ld_r",
	"prop_coathook_01",
	"prop_cockneon",
	"prop_coffee_cup_trailer",
	"prop_coffee_mac_02",
	"prop_coffin_02",
	"prop_coffin_02b",
	"prop_coke_block_01",
	"prop_coke_block_half_a",
	"prop_coke_block_half_b",
	"prop_compressor_01",
	"prop_compressor_02",
	"prop_compressor_03",
	"prop_com_gar_door_01",
	"prop_com_ls_door_01",
	"prop_conc_sacks_02a",
	"prop_cone_float_1",
	"prop_conschute",
	"prop_consign_01c",
	"prop_consign_02a",
	"prop_conslift_base",
	"prop_conslift_brace",
	"prop_conslift_cage",
	"prop_conslift_door",
	"prop_conslift_lift",
	"prop_conslift_rail",
	"prop_conslift_rail2",
	"prop_conslift_steps",
	"prop_console_01",
	"prop_construcionlamp_01",
	"prop_const_fence01a",
	"prop_const_fence01b",
	"prop_const_fence02a",
	"prop_const_fence02b",
	"prop_const_fence03b",
	"prop_cons_crate",
	"prop_cons_plank",
	"prop_cons_ply01",
	"prop_cons_ply02",
	"prop_container_01a",
	"prop_container_01b",
	"prop_container_01c",
	"prop_container_01d",
	"prop_container_01e",
	"prop_container_01f",
	"prop_container_01g",
	"prop_container_01h",
	"prop_container_01mb",
	"prop_container_02a",
	"prop_container_03a",
	"prop_container_03b",
	"prop_container_03mb",
	"prop_container_03_ld",
	"prop_container_04a",
	"prop_container_04mb",
	"prop_container_05mb",
	"prop_container_door_mb_l",
	"prop_container_door_mb_r",
	"prop_container_hole",
	"prop_container_ld",
	"prop_container_ld2",
	"prop_container_old1",
	"prop_contnr_pile_01a",
	"prop_controller_01",
	"prop_control_rm_door_01",
	"prop_cont_chiller_01",
	"prop_cooker_03",
	"prop_copier_01",
	"prop_copper_pan",
	"prop_coral_bush_01",
	"prop_coral_flat_01",
	"prop_coral_flat_01_l1",
	"prop_coral_flat_02",
	"prop_coral_flat_brainy",
	"prop_coral_flat_clam",
	"prop_coral_grass_01",
	"prop_coral_grass_02",
	"prop_coral_kelp_01",
	"prop_coral_kelp_01_l1",
	"prop_coral_kelp_02",
	"prop_coral_kelp_02_l1",
	"prop_coral_kelp_03",
	"prop_coral_kelp_03a",
	"prop_coral_kelp_03b",
	"prop_coral_kelp_03c",
	"prop_coral_kelp_03d",
	"prop_coral_kelp_03_l1",
	"prop_coral_kelp_04",
	"prop_coral_kelp_04_l1",
	"prop_coral_pillar_01",
	"prop_coral_pillar_02",
	"prop_coral_spikey_01",
	"prop_coral_stone_03",
	"prop_coral_stone_04",
	"prop_coral_sweed_01",
	"prop_coral_sweed_02",
	"prop_coral_sweed_03",
	"prop_coral_sweed_04",
	"prop_cora_clam_01",
	"prop_cork_board",
	"prop_couch_01",
	"prop_couch_03",
	"prop_couch_04",
	"prop_couch_lg_02",
	"prop_couch_lg_05",
	"prop_couch_lg_06",
	"prop_couch_lg_07",
	"prop_couch_lg_08",
	"prop_couch_sm1_07",
	"prop_couch_sm2_07",
	"prop_couch_sm_02",
	"prop_couch_sm_05",
	"prop_couch_sm_06",
	"prop_couch_sm_07",
	"prop_crane_01_truck1",
	"prop_crane_01_truck2",
	"prop_cranial_saw",
	"prop_crashed_heli",
	"prop_cratepile_07a_l1",
	"prop_crate_01a",
	"prop_crate_02a",
	"prop_crate_08a",
	"prop_crate_09a",
	"prop_crate_10a",
	"prop_crate_11a",
	"prop_crate_11b",
	"prop_crate_11c",
	"prop_crate_11d",
	"prop_crate_float_1",
	"prop_creosote_b_01",
	"prop_crisp",
	"prop_crisp_small",
	"prop_crosssaw_01",
	"prop_cs1_14b_traind",
	"prop_cs1_14b_traind_dam",
	"prop_cs4_05_tdoor",
	"prop_cs4_10_tr_gd_01",
	"prop_cs4_11_door",
	"prop_cs6_03_door_l",
	"prop_cs6_03_door_r",
	"prop_cs_20m_rope",
	"prop_cs_30m_rope",
	"prop_cs_abattoir_switch",
	"prop_cs_aircon_01",
	"prop_cs_aircon_fan",
	"prop_cs_amanda_shoe",
	"prop_cs_ashtray",
	"prop_cs_bandana",
	"prop_cs_bar",
	"prop_cs_beachtowel_01",
	"prop_cs_beer_bot_01",
	"prop_cs_beer_bot_01b",
	"prop_cs_beer_bot_01lod",
	"prop_cs_beer_bot_02",
	"prop_cs_beer_bot_03",
	"prop_cs_beer_bot_40oz",
	"prop_cs_beer_bot_40oz_02",
	"prop_cs_beer_bot_40oz_03",
	"prop_cs_beer_bot_test",
	"prop_cs_binder_01",
	"prop_cs_bin_01",
	"prop_cs_bin_01_lid",
	"prop_cs_bin_01_skinned",
	"prop_cs_bin_02",
	"prop_cs_bin_03",
	"prop_cs_book_01",
	"prop_cs_bottle_opener",
	"prop_cs_bowie_knife",
	"prop_cs_bowl_01",
	"prop_cs_bowl_01b",
	"prop_cs_box_clothes",
	"prop_cs_box_step",
	"prop_cs_brain_chunk",
	"prop_cs_bs_cup",
	"prop_cs_bucket_s",
	"prop_cs_bucket_s_lod",
	"prop_cs_burger_01",
	"prop_cs_business_card",
	"prop_cs_cardbox_01",
	"prop_cs_cash_note_01",
	"prop_cs_cctv",
	"prop_cs_champ_flute",
	"prop_cs_ciggy_01",
	"prop_cs_ciggy_01b",
	"prop_cs_clothes_box",
	"prop_cs_coke_line",
	"prop_cs_cont_latch",
	"prop_cs_crackpipe",
	"prop_cs_credit_card",
	"prop_cs_creeper_01",
	"prop_cs_crisps_01",
	"prop_cs_cuffs_01",
	"prop_cs_diaphram",
	"prop_cs_dildo_01",
	"prop_cs_documents_01",
	"prop_cs_dog_lead_2a",
	"prop_cs_dog_lead_2b",
	"prop_cs_dog_lead_2c",
	"prop_cs_dog_lead_3a",
	"prop_cs_dog_lead_3b",
	"prop_cs_dog_lead_a",
	"prop_cs_dog_lead_b",
	"prop_cs_dog_lead_c",
	"prop_cs_duffel_01",
	"prop_cs_duffel_01b",
	"prop_cs_dumpster_01a",
	"prop_cs_dumpster_lidl",
	"prop_cs_dumpster_lidr",
	"prop_cs_dvd",
	"prop_cs_dvd_case",
	"prop_cs_dvd_player",
	"prop_cs_envolope_01",
	"prop_cs_fertilizer",
	"prop_cs_film_reel_01",
	"prop_cs_folding_chair_01",
	"prop_cs_fork",
	"prop_cs_frank_photo",
	"prop_cs_freightdoor_l1",
	"prop_cs_freightdoor_r1",
	"prop_cs_fridge",
	"prop_cs_fridge_door",
	"prop_cs_fuel_hose",
	"prop_cs_fuel_nozle",
	"prop_cs_gascutter_1",
	"prop_cs_gascutter_2",
	"prop_cs_glass_scrap",
	"prop_cs_gravyard_gate_l",
	"prop_cs_gravyard_gate_r",
	"prop_cs_gunrack",
	"prop_cs_hand_radio",
	"prop_cs_heist_bag_01",
	"prop_cs_heist_bag_02",
	"prop_cs_heist_bag_strap_01",
	"prop_cs_heist_rope",
	"prop_cs_heist_rope_b",
	"prop_cs_hotdog_01",
	"prop_cs_hotdog_02",
	"prop_cs_h_bag_strap_01",
	"prop_cs_ice_locker",
	"prop_cs_ice_locker_door_l",
	"prop_cs_ice_locker_door_r",
	"prop_cs_ilev_blind_01",
	"prop_cs_ironing_board",
	"prop_cs_katana_01",
	"prop_cs_kettle_01",
	"prop_cs_keyboard_01",
	"prop_cs_keys_01",
	"prop_cs_kitchen_cab_l2",
	"prop_cs_kitchen_cab_ld",
	"prop_cs_kitchen_cab_rd",
	"prop_cs_lazlow_ponytail",
	"prop_cs_lazlow_shirt_01",
	"prop_cs_lazlow_shirt_01b",
	"prop_cs_leaf",
	"prop_cs_leg_chain_01",
	"prop_cs_lester_crate",
	"prop_cs_lipstick",
	"prop_cs_magazine",
	"prop_cs_marker_01",
	"prop_cs_meth_pipe",
	"prop_cs_milk_01",
	"prop_cs_mini_tv",
	"prop_cs_mopbucket_01",
	"prop_cs_mop_s",
	"prop_cs_mouse_01",
	"prop_cs_nail_file",
	"prop_cs_newspaper",
	"prop_cs_office_chair",
	"prop_cs_overalls_01",
	"prop_cs_package_01",
	"prop_cs_padlock",
	"prop_cs_pamphlet_01",
	"prop_cs_panel_01",
	"prop_cs_panties",
	"prop_cs_panties_02",
	"prop_cs_panties_03",
	"prop_cs_paper_cup",
	"prop_cs_para_ropebit",
	"prop_cs_para_ropes",
	"prop_cs_pebble",
	"prop_cs_pebble_02",
	"prop_cs_petrol_can",
	"prop_cs_phone_01",
	"prop_cs_photoframe_01",
	"prop_cs_pills",
	"prop_cs_plane_int_01",
	"prop_cs_planning_photo",
	"prop_cs_plant_01",
	"prop_cs_plate_01",
	"prop_cs_polaroid",
	"prop_cs_police_torch",
	"prop_cs_pour_tube",
	"prop_cs_power_cell",
	"prop_cs_power_cord",
	"prop_cs_protest_sign_01",
	"prop_cs_protest_sign_02",
	"prop_cs_protest_sign_02b",
	"prop_cs_protest_sign_03",
	"prop_cs_protest_sign_04a",
	"prop_cs_protest_sign_04b",
	"prop_cs_rage_statue_p1",
	"prop_cs_rage_statue_p2",
	"prop_cs_remote_01",
	"prop_cs_rolled_paper",
	"prop_cs_rope_tie_01",
	"prop_cs_rub_binbag_01",
	"prop_cs_rub_box_01",
	"prop_cs_rub_box_02",
	"prop_cs_r_business_card",
	"prop_cs_sack_01",
	"prop_cs_saucer_01",
	"prop_cs_sc1_11_gate",
	"prop_cs_scissors",
	"prop_cs_script_bottle",
	"prop_cs_script_bottle_01",
	"prop_cs_server_drive",
	"prop_cs_sheers",
	"prop_cs_shirt_01",
	"prop_cs_shopping_bag",
	"prop_cs_shot_glass",
	"prop_cs_silver_tray",
	"prop_cs_sink_filler",
	"prop_cs_sink_filler_02",
	"prop_cs_sink_filler_03",
	"prop_cs_sm_27_gate",
	"prop_cs_sol_glasses",
	"prop_cs_spray_can",
	"prop_cs_steak",
	"prop_cs_stock_book",
	"prop_cs_street_binbag_01",
	"prop_cs_street_card_01",
	"prop_cs_street_card_02",
	"prop_cs_sub_hook_01",
	"prop_cs_sub_rope_01",
	"prop_cs_swipe_card",
	"prop_cs_tablet",
	"prop_cs_tablet_02",
	"prop_cs_toaster",
	"prop_cs_trolley_01",
	"prop_cs_trowel",
	"prop_cs_truck_ladder",
	"prop_cs_tshirt_ball_01",
	"prop_cs_tv_stand",
	"prop_cs_t_shirt_pile",
	"prop_cs_valve",
	"prop_cs_vent_cover",
	"prop_cs_vial_01",
	"prop_cs_walkie_talkie",
	"prop_cs_walking_stick",
	"prop_cs_whiskey_bottle",
	"prop_cs_whiskey_bot_stop",
	"prop_cs_wrench",
	"prop_cub_door_lifeblurb",
	"prop_cub_lifeblurb",
	"prop_cuff_keys_01",
	"prop_cup_saucer_01",
	"prop_curl_bar_01",
	"prop_damdoor_01",
	"prop_dart_1",
	"prop_dart_2",
	"prop_dart_bd_01",
	"prop_dart_bd_cab_01",
	"prop_defilied_ragdoll_01",
	"prop_desert_iron_01",
	"prop_detergent_01a",
	"prop_detergent_01b",
	"prop_devin_box_01",
	"prop_devin_rope_01",
	"prop_diggerbkt_01",
	"prop_direct_chair_01",
	"prop_direct_chair_02",
	"prop_display_unit_01",
	"prop_display_unit_02",
	"prop_disp_cabinet_002",
	"prop_disp_cabinet_01",
	"prop_disp_razor_01",
	"prop_distantcar_day",
	"prop_distantcar_night",
	"prop_distantcar_truck",
	"prop_dj_deck_01",
	"prop_dj_deck_02",
	"prop_dock_bouy_1",
	"prop_dock_bouy_2",
	"prop_dock_bouy_3",
	"prop_dock_bouy_5",
	"prop_dock_crane_01",
	"prop_dock_crane_02",
	"prop_dock_crane_02_cab",
	"prop_dock_crane_02_hook",
	"prop_dock_crane_02_ld",
	"prop_dock_crane_04",
	"prop_dock_crane_lift",
	"prop_dock_float_1",
	"prop_dock_float_1b",
	"prop_dock_moor_01",
	"prop_dock_moor_04",
	"prop_dock_moor_05",
	"prop_dock_moor_06",
	"prop_dock_moor_07",
	"prop_dock_ropefloat",
	"prop_dock_ropetyre1",
	"prop_dock_ropetyre2",
	"prop_dock_ropetyre3",
	"prop_dock_rtg_01",
	"prop_dock_rtg_ld",
	"prop_dock_shippad",
	"prop_dock_sign_01",
	"prop_dock_woodpole1",
	"prop_dock_woodpole2",
	"prop_dock_woodpole3",
	"prop_dock_woodpole4",
	"prop_dock_woodpole5",
	"prop_dog_cage_01",
	"prop_dog_cage_02",
	"prop_dolly_01",
	"prop_dolly_02",
	"prop_donut_01",
	"prop_donut_02",
	"prop_donut_02b",
	"prop_door_01",
	"prop_door_balcony_frame",
	"prop_door_balcony_left",
	"prop_door_balcony_right",
	"prop_door_bell_01",
	"prop_double_grid_line",
	"prop_dress_disp_01",
	"prop_dress_disp_02",
	"prop_dress_disp_03",
	"prop_dress_disp_04",
	"prop_drop_armscrate_01",
	"prop_drop_armscrate_01b",
	"prop_drop_crate_01",
	"prop_drop_crate_01_set",
	"prop_drop_crate_01_set2",
	"prop_drug_burner",
	"prop_drug_package",
	"prop_drug_package_02",
	"prop_drywallpile_01",
	"prop_drywallpile_02",
	"prop_dt1_13_groundlight",
	"prop_dt1_13_walllightsource",
	"prop_dt1_20_mp_door_l",
	"prop_dt1_20_mp_door_r",
	"prop_dt1_20_mp_gar",
	"prop_ducktape_01",
	"prop_dummy_01",
	"prop_dummy_car",
	"prop_dummy_light",
	"prop_dummy_plane",
	"prop_dumpster_3a",
	"prop_dumpster_3step",
	"prop_dumpster_4a",
	"prop_dumpster_4b",
	"prop_d_balcony_l_light",
	"prop_d_balcony_r_light",
	"prop_ear_defenders_01",
	"prop_ecg_01",
	"prop_ecg_01_cable_01",
	"prop_ecg_01_cable_02",
	"prop_ecola_can",
	"prop_egg_clock_01",
	"prop_ejector_seat_01",
	"prop_elecbox_03a",
	"prop_elecbox_10",
	"prop_elecbox_12",
	"prop_elecbox_13",
	"prop_elecbox_14",
	"prop_elecbox_15",
	"prop_elecbox_16",
	"prop_elecbox_17",
	"prop_elecbox_18",
	"prop_elecbox_19",
	"prop_elecbox_20",
	"prop_elecbox_21",
	"prop_elecbox_22",
	"prop_elecbox_23",
	"prop_elecbox_24",
	"prop_elecbox_24b",
	"prop_elecbox_25",
	"prop_el_guitar_01",
	"prop_el_guitar_02",
	"prop_el_guitar_03",
	"prop_employee_month_01",
	"prop_employee_month_02",
	"prop_energy_drink",
	"prop_entityxf_covered",
	"prop_epsilon_door_l",
	"prop_epsilon_door_r",
	"prop_etricmotor_01",
	"prop_exer_bike_01",
	"prop_faceoffice_door_l",
	"prop_faceoffice_door_r",
	"prop_face_rag_01",
	"prop_facgate_01",
	"prop_facgate_01b",
	"prop_facgate_02pole",
	"prop_facgate_02_l",
	"prop_facgate_03post",
	"prop_facgate_03_l",
	"prop_facgate_03_ld_l",
	"prop_facgate_03_ld_r",
	"prop_facgate_03_r",
	"prop_facgate_04_l",
	"prop_facgate_04_r",
	"prop_facgate_05_r",
	"prop_facgate_05_r_dam_l1",
	"prop_facgate_05_r_l1",
	"prop_facgate_06_l",
	"prop_facgate_06_r",
	"prop_facgate_07",
	"prop_facgate_07b",
	"prop_facgate_08",
	"prop_facgate_08_frame",
	"prop_facgate_08_ld2",
	"prop_facgate_id1_27",
	"prop_fac_machine_02",
	"prop_fag_packet_01",
	"prop_fan_01",
	"prop_fan_palm_01a",
	"prop_fax_01",
	"prop_fbi3_coffee_table",
	"prop_fbibombbin",
	"prop_fbibombcupbrd",
	"prop_fbibombfile",
	"prop_fbibombplant",
	"prop_feeder1",
	"prop_feed_sack_01",
	"prop_feed_sack_02",
	"prop_fence_log_01",
	"prop_fence_log_02",
	"prop_ferris_car_01",
	"prop_ferris_car_01_lod1",
	"prop_ff_counter_01",
	"prop_ff_counter_02",
	"prop_ff_counter_03",
	"prop_ff_noodle_01",
	"prop_ff_noodle_02",
	"prop_ff_shelves_01",
	"prop_ff_sink_01",
	"prop_ff_sink_02",
	"prop_fib_badge",
	"prop_fib_broken_window",
	"prop_fib_skylight_piece",
	"prop_film_cam_01",
	"prop_fireescape_01a",
	"prop_fireescape_01b",
	"prop_fireescape_02a",
	"prop_fireescape_02b",
	"prop_fire_driser_1a",
	"prop_fire_driser_1b",
	"prop_fire_driser_2b",
	"prop_fire_driser_3b",
	"prop_fire_driser_4a",
	"prop_fire_driser_4b",
	"prop_fire_hosereel",
	"prop_fishing_rod_01",
	"prop_fishing_rod_02",
	"prop_fish_slice_01",
	"prop_flagpole_1a",
	"prop_flagpole_2a",
	"prop_flagpole_3a",
	"prop_flare_01",
	"prop_flare_01b",
	"prop_flash_unit",
	"prop_flatbed_strap",
	"prop_flatbed_strap_b",
	"prop_flatscreen_overlay",
	"prop_flattrailer_01a",
	"prop_flattruck_01a",
	"prop_fleeca_atm",
	"prop_flight_box_01",
	"prop_flight_box_insert",
	"prop_flight_box_insert2",
	"prop_flipchair_01",
	"prop_floor_duster_01",
	"prop_fncconstruc_02a",
	"prop_fnccorgm_05a",
	"prop_fnccorgm_05b",
	"prop_fnccorgm_06a",
	"prop_fnccorgm_06b",
	"prop_fnclink_01gate1",
	"prop_fnclink_02gate1",
	"prop_fnclink_02gate2",
	"prop_fnclink_02gate5",
	"prop_fnclink_02gate6_l",
	"prop_fnclink_02gate6_r",
	"prop_fnclink_02gate7",
	"prop_fnclink_03gate1",
	"prop_fnclink_03gate2",
	"prop_fnclink_03gate4",
	"prop_fnclink_03gate5",
	"prop_fnclink_04gate1",
	"prop_fnclink_04h_l2",
	"prop_fnclink_06gate2",
	"prop_fnclink_06gate3",
	"prop_fnclink_06gatepost",
	"prop_fnclink_07gate1",
	"prop_fnclink_07gate2",
	"prop_fnclink_07gate3",
	"prop_fnclink_09gate1",
	"prop_fnclink_10a",
	"prop_fnclink_10b",
	"prop_fnclink_10c",
	"prop_fnclink_10d",
	"prop_fnclink_10e",
	"prop_fnclog_01a",
	"prop_fnclog_01b",
	"prop_fncpeir_03a",
	"prop_fncres_02a",
	"prop_fncres_02b",
	"prop_fncres_02c",
	"prop_fncres_02d",
	"prop_fncres_02_gate1",
	"prop_fncres_03gate1",
	"prop_fncres_05c_l1",
	"prop_fncsec_01a",
	"prop_fncsec_01b",
	"prop_fncsec_01crnr",
	"prop_fncsec_01gate",
	"prop_fncsec_01pole",
	"prop_fncsec_02a",
	"prop_fncsec_02pole",
	"prop_fncsec_04a",
	"prop_fncwood_07gate1",
	"prop_fncwood_11a_l1",
	"prop_fncwood_16a",
	"prop_fncwood_16b",
	"prop_fncwood_16c",
	"prop_fncwood_18a",
	"prop_folded_polo_shirt",
	"prop_folder_01",
	"prop_folder_02",
	"prop_food_bin_01",
	"prop_food_bin_02",
	"prop_food_bs_bshelf",
	"prop_food_bs_cups01",
	"prop_food_bs_cups03",
	"prop_food_bs_soda_01",
	"prop_food_bs_soda_02",
	"prop_food_bs_tray_01",
	"prop_food_bs_tray_06",
	"prop_food_burg1",
	"prop_food_burg2",
	"prop_food_cb_bshelf",
	"prop_food_cb_burg01",
	"prop_food_cb_cups01",
	"prop_food_cb_donuts",
	"prop_food_cb_nugets",
	"prop_food_cb_soda_01",
	"prop_food_cb_soda_02",
	"prop_food_cb_tray_01",
	"prop_food_cups1",
	"prop_food_napkin_01",
	"prop_food_napkin_02",
	"prop_food_tray_01",
	"prop_food_van_01",
	"prop_food_van_02",
	"prop_forsalejr2",
	"prop_forsalejr3",
	"prop_forsalejr4",
	"prop_foundation_sponge",
	"prop_fountain1",
	"prop_fountain2",
	"prop_franklin_dl",
	"prop_freeweight_01",
	"prop_freeweight_02",
	"prop_fridge_01",
	"prop_fridge_03",
	"prop_front_seat_01",
	"prop_front_seat_02",
	"prop_front_seat_03",
	"prop_front_seat_04",
	"prop_front_seat_05",
	"prop_front_seat_06",
	"prop_front_seat_07",
	"prop_front_seat_row_01",
	"prop_fruitstand_b_nite",
	"prop_fruit_basket",
	"prop_ftowel_01",
	"prop_ftowel_07",
	"prop_ftowel_08",
	"prop_ftowel_10",
	"prop_f_b_insert_broken",
	"prop_f_duster_01_s",
	"prop_f_duster_02",
	"prop_gaffer_arm_bind",
	"prop_gaffer_arm_bind_cut",
	"prop_gaffer_leg_bind",
	"prop_gaffer_leg_bind_cut",
	"prop_gaffer_tape",
	"prop_gaffer_tape_strip",
	"prop_game_clock_01",
	"prop_game_clock_02",
	"prop_garden_dreamcatch_01",
	"prop_garden_edging_01",
	"prop_garden_edging_02",
	"prop_garden_zapper_01",
	"prop_gardnght_01",
	"prop_gar_door_01",
	"prop_gar_door_02",
	"prop_gar_door_03",
	"prop_gar_door_03_ld",
	"prop_gar_door_04",
	"prop_gar_door_05",
	"prop_gar_door_05_l",
	"prop_gar_door_05_r",
	"prop_gar_door_a_01",
	"prop_gar_door_plug",
	"prop_gascage01",
	"prop_gascyl_ramp_01",
	"prop_gascyl_ramp_door_01",
	"prop_gas_01",
	"prop_gas_02",
	"prop_gas_03",
	"prop_gas_04",
	"prop_gas_05",
	"prop_gas_grenade",
	"prop_gas_mask_hang_01",
	"prop_gatecom_02",
	"prop_gate_airport_01",
	"prop_gate_bridge_ld",
	"prop_gate_cult_01_l",
	"prop_gate_cult_01_r",
	"prop_gate_docks_ld",
	"prop_gate_farm_01a",
	"prop_gate_farm_post",
	"prop_gate_frame_01",
	"prop_gate_frame_02",
	"prop_gate_frame_04",
	"prop_gate_frame_05",
	"prop_gate_frame_06",
	"prop_gate_military_01",
	"prop_gate_prison_01",
	"prop_gate_tep_01_l",
	"prop_gate_tep_01_r",
	"prop_gazebo_03",
	"prop_gd_ch2_08",
	"prop_generator_02a",
	"prop_generator_03a",
	"prop_generator_04",
	"prop_ghettoblast_02",
	"prop_girder_01a",
	"prop_glasscutter_01",
	"prop_glass_suck_holder",
	"prop_glf_roller",
	"prop_glf_spreader",
	"prop_gold_bar",
	"prop_gold_cont_01",
	"prop_gold_cont_01b",
	"prop_gold_trolly",
	"prop_gold_trolly_full",
	"prop_gold_trolly_strap_01",
	"prop_golf_bag_01",
	"prop_golf_bag_01b",
	"prop_golf_bag_01c",
	"prop_golf_ball",
	"prop_golf_ball_p2",
	"prop_golf_ball_p3",
	"prop_golf_ball_p4",
	"prop_golf_ball_tee",
	"prop_golf_driver",
	"prop_golf_iron_01",
	"prop_golf_marker_01",
	"prop_golf_pitcher_01",
	"prop_golf_putter_01",
	"prop_golf_tee",
	"prop_golf_wood_01",
	"prop_grain_hopper",
	"prop_grapes_01",
	"prop_grapes_02",
	"prop_grass_dry_02",
	"prop_grass_dry_03",
	"prop_gravestones_01a",
	"prop_gravestones_02a",
	"prop_gravestones_03a",
	"prop_gravestones_04a",
	"prop_gravestones_05a",
	"prop_gravestones_06a",
	"prop_gravestones_07a",
	"prop_gravestones_08a",
	"prop_gravestones_09a",
	"prop_gravestones_10a",
	"prop_gravetomb_01a",
	"prop_gravetomb_02a",
	"prop_griddle_01",
	"prop_griddle_02",
	"prop_grumandoor_l",
	"prop_grumandoor_r",
	"prop_gshotsensor_01",
	"prop_gun_case_01",
	"prop_gun_case_02",
	"prop_gun_frame",
	"prop_hacky_sack_01",
	"prop_handdry_01",
	"prop_handdry_02",
	"prop_handrake",
	"prop_handtowels",
	"prop_hand_toilet",
	"prop_hanger_door_1",
	"prop_hard_hat_01",
	"prop_hat_box_01",
	"prop_hat_box_02",
	"prop_hat_box_03",
	"prop_hat_box_04",
	"prop_hat_box_05",
	"prop_hat_box_06",
	"prop_haybailer_01",
	"prop_haybale_01",
	"prop_haybale_02",
	"prop_haybale_stack_01",
	"prop_hd_seats_01",
	"prop_headphones_01",
	"prop_headset_01",
	"prop_hedge_trimmer_01",
	"prop_helipad_01",
	"prop_helipad_02",
	"prop_henna_disp_01",
	"prop_henna_disp_02",
	"prop_henna_disp_03",
	"prop_hifi_01",
	"prop_hobo_stove_01",
	"prop_hockey_bag_01",
	"prop_hole_plug_01",
	"prop_holster_01",
	"prop_homeless_matress_01",
	"prop_homeless_matress_02",
	"prop_hose_1",
	"prop_hose_2",
	"prop_hose_3",
	"prop_hose_nozzle",
	"prop_hospitaldoors_start",
	"prop_hospital_door_l",
	"prop_hospital_door_r",
	"prop_hotel_clock_01",
	"prop_hotel_trolley",
	"prop_hottub2",
	"prop_huf_rag_01",
	"prop_huge_display_01",
	"prop_huge_display_02",
	"prop_hunterhide",
	"prop_hw1_03_gardoor_01",
	"prop_hw1_04_door_l1",
	"prop_hw1_04_door_r1",
	"prop_hw1_23_door",
	"prop_hwbowl_pseat_6x1",
	"prop_hwbowl_seat_01",
	"prop_hwbowl_seat_02",
	"prop_hwbowl_seat_03",
	"prop_hwbowl_seat_03b",
	"prop_hwbowl_seat_6x6",
	"prop_hydro_platform_01",
	"prop_ice_box_01",
	"prop_ice_box_01_l1",
	"prop_ice_cube_01",
	"prop_ice_cube_02",
	"prop_ice_cube_03",
	"prop_id2_11_gdoor",
	"prop_id2_20_clock",
	"prop_idol_01",
	"prop_idol_01_error",
	"prop_idol_case",
	"prop_idol_case_01",
	"prop_idol_case_02",
	"prop_id_21_gardoor_01",
	"prop_id_21_gardoor_02",
	"prop_indus_meet_door_l",
	"prop_indus_meet_door_r",
	"prop_ind_barge_01",
	"prop_ind_barge_02",
	"prop_ind_coalcar_01",
	"prop_ind_coalcar_02",
	"prop_ind_coalcar_03",
	"prop_ind_conveyor_01",
	"prop_ind_conveyor_02",
	"prop_ind_conveyor_04",
	"prop_ind_crusher",
	"prop_ind_deiseltank",
	"prop_ind_light_01a",
	"prop_ind_light_01b",
	"prop_ind_light_01c",
	"prop_ind_mech_01c",
	"prop_ind_mech_02a",
	"prop_ind_mech_02b",
	"prop_ind_mech_03a",
	"prop_ind_mech_04a",
	"prop_ind_oldcrane",
	"prop_ind_washer_02",
	"prop_inflatearch_01",
	"prop_inflategate_01",
	"prop_ing_camera_01",
	"prop_ing_crowbar",
	"prop_inhaler_01",
	"prop_int_gate01",
	"prop_in_tray_01",
	"prop_irish_sign_01",
	"prop_irish_sign_02",
	"prop_irish_sign_03",
	"prop_irish_sign_04",
	"prop_irish_sign_05",
	"prop_irish_sign_06",
	"prop_irish_sign_07",
	"prop_irish_sign_08",
	"prop_irish_sign_09",
	"prop_irish_sign_10",
	"prop_irish_sign_11",
	"prop_irish_sign_12",
	"prop_irish_sign_13",
	"prop_iron_01",
	"prop_jb700_covered",
	"prop_jeans_01",
	"prop_jetski_ramp_01",
	"prop_jet_bloodsplat_01",
	"prop_jewel_02a",
	"prop_jewel_02b",
	"prop_jewel_02c",
	"prop_jewel_03a",
	"prop_jewel_03b",
	"prop_jewel_04a",
	"prop_jewel_04b",
	"prop_jewel_pickup_new_01",
	"prop_juice_dispenser",
	"prop_juice_pool_01",
	"prop_jukebox_01",
	"prop_jukebox_02",
	"prop_jyard_block_01a",
	"prop_j_disptray_01",
	"prop_j_disptray_01b",
	"prop_j_disptray_01_dam",
	"prop_j_disptray_02",
	"prop_j_disptray_02_dam",
	"prop_j_disptray_03",
	"prop_j_disptray_03_dam",
	"prop_j_disptray_04",
	"prop_j_disptray_04b",
	"prop_j_disptray_05",
	"prop_j_disptray_05b",
	"prop_j_heist_pic_01",
	"prop_j_heist_pic_02",
	"prop_j_heist_pic_03",
	"prop_j_heist_pic_04",
	"prop_j_neck_disp_01",
	"prop_j_neck_disp_02",
	"prop_j_neck_disp_03",
	"prop_kayak_01",
	"prop_kayak_01b",
	"prop_kebab_grill",
	"prop_keg_01",
	"prop_kettle",
	"prop_kettle_01",
	"prop_keyboard_01a",
	"prop_keyboard_01b",
	"prop_kino_light_01",
	"prop_kino_light_03",
	"prop_kitch_juicer",
	"prop_kitch_pot_fry",
	"prop_kitch_pot_huge",
	"prop_kitch_pot_lrg",
	"prop_kitch_pot_lrg2",
	"prop_kitch_pot_med",
	"prop_kitch_pot_sm",
	"prop_knife",
	"prop_knife_stand",
	"prop_kt1_06_door_l",
	"prop_kt1_06_door_r",
	"prop_kt1_10_mpdoor_l",
	"prop_kt1_10_mpdoor_r",
	"prop_ladel",
	"prop_laptop_02_closed",
	"prop_laptop_jimmy",
	"prop_laptop_lester",
	"prop_laptop_lester2",
	"prop_large_gold",
	"prop_large_gold_alt_a",
	"prop_large_gold_alt_b",
	"prop_large_gold_alt_c",
	"prop_large_gold_empty",
	"prop_lawnmower_01",
	"prop_ld_alarm_01",
	"prop_ld_alarm_01_dam",
	"prop_ld_alarm_alert",
	"prop_ld_ammo_pack_01",
	"prop_ld_ammo_pack_02",
	"prop_ld_ammo_pack_03",
	"prop_ld_armour",
	"prop_ld_balcfnc_01a",
	"prop_ld_balcfnc_02a",
	"prop_ld_balcfnc_02c",
	"prop_ld_bankdoors_02",
	"prop_ld_barrier_01",
	"prop_ld_binbag_01",
	"prop_ld_bomb",
	"prop_ld_bomb_01",
	"prop_ld_bomb_01_open",
	"prop_ld_bomb_anim",
	"prop_ld_cable",
	"prop_ld_cable_tie_01",
	"prop_ld_can_01",
	"prop_ld_case_01",
	"prop_ld_case_01_lod",
	"prop_ld_case_01_s",
	"prop_ld_contact_card",
	"prop_ld_container",
	"prop_ld_contain_dl",
	"prop_ld_contain_dl2",
	"prop_ld_contain_dr",
	"prop_ld_contain_dr2",
	"prop_ld_crate_01",
	"prop_ld_crate_lid_01",
	"prop_ld_crocclips01",
	"prop_ld_crocclips02",
	"prop_ld_dummy_rope",
	"prop_ld_fags_01",
	"prop_ld_fags_02",
	"prop_ld_fan_01",
	"prop_ld_fan_01_old",
	"prop_ld_faucet",
	"prop_ld_ferris_wheel",
	"prop_ld_fireaxe",
	"prop_ld_flow_bottle",
	"prop_ld_fragwall_01a",
	"prop_ld_garaged_01",
	"prop_ld_gold_tooth",
	"prop_ld_greenscreen_01",
	"prop_ld_handbag",
	"prop_ld_handbag_s",
	"prop_ld_hat_01",
	"prop_ld_haybail",
	"prop_ld_hdd_01",
	"prop_ld_health_pack",
	"prop_ld_hook",
	"prop_ld_int_safe_01",
	"prop_ld_jail_door",
	"prop_ld_jeans_01",
	"prop_ld_jeans_02",
	"prop_ld_jerrycan_01",
	"prop_ld_keypad_01",
	"prop_ld_keypad_01b",
	"prop_ld_keypad_01b_lod",
	"prop_ld_lap_top",
	"prop_ld_monitor_01",
	"prop_ld_peep_slider",
	"prop_ld_pipe_single_01",
	"prop_ld_planning_pin_01",
	"prop_ld_planning_pin_02",
	"prop_ld_planning_pin_03",
	"prop_ld_purse_01",
	"prop_ld_purse_01_lod",
	"prop_ld_rail_01",
	"prop_ld_rail_02",
	"prop_ld_rope_t",
	"prop_ld_rubble_01",
	"prop_ld_rubble_02",
	"prop_ld_rubble_03",
	"prop_ld_rubble_04",
	"prop_ld_rub_binbag_01",
	"prop_ld_scrap",
	"prop_ld_shirt_01",
	"prop_ld_shoe_01",
	"prop_ld_shoe_02",
	"prop_ld_shovel",
	"prop_ld_shovel_dirt",
	"prop_ld_snack_01",
	"prop_ld_suitcase_01",
	"prop_ld_suitcase_02",
	"prop_ld_test_01",
	"prop_ld_toilet_01",
	"prop_ld_tooth",
	"prop_ld_tshirt_01",
	"prop_ld_tshirt_02",
	"prop_ld_vault_door",
	"prop_ld_wallet_01",
	"prop_ld_wallet_01_s",
	"prop_ld_wallet_02",
	"prop_ld_wallet_pickup",
	"prop_ld_w_me_machette",
	"prop_leaf_blower_01",
	"prop_lectern_01",
	"prop_letterbox_04",
	"prop_lev_crate_01",
	"prop_lev_des_barge_01",
	"prop_lev_des_barge_02",
	"prop_lifeblurb_01",
	"prop_lifeblurb_01b",
	"prop_lifeblurb_02",
	"prop_lifeblurb_02b",
	"prop_life_ring_02",
	"prop_lift_overlay_01",
	"prop_lift_overlay_02",
	"prop_litter_picker",
	"prop_loggneon",
	"prop_logpile_05",
	"prop_logpile_06",
	"prop_logpile_06b",
	"prop_logpile_07",
	"prop_logpile_07b",
	"prop_log_01",
	"prop_log_02",
	"prop_log_03",
	"prop_loose_rag_01",
	"prop_lrggate_01c_l",
	"prop_lrggate_01c_r",
	"prop_lrggate_01_l",
	"prop_lrggate_01_pst",
	"prop_lrggate_01_r",
	"prop_lrggate_02_ld",
	"prop_lrggate_03a",
	"prop_lrggate_03b",
	"prop_lrggate_03b_ld",
	"prop_lrggate_04a",
	"prop_lrggate_05a",
	"prop_lrggate_06a",
	"prop_luggage_01a",
	"prop_luggage_02a",
	"prop_luggage_03a",
	"prop_luggage_04a",
	"prop_luggage_05a",
	"prop_luggage_06a",
	"prop_luggage_07a",
	"prop_luggage_08a",
	"prop_luggage_09a",
	"prop_magenta_door",
	"prop_makeup_trail_01",
	"prop_makeup_trail_02",
	"prop_map_door_01",
	"prop_mast_01",
	"prop_mat_box",
	"prop_mb_cargo_01a",
	"prop_mb_cargo_02a",
	"prop_mb_cargo_03a",
	"prop_mb_cargo_04a",
	"prop_mb_cargo_04b",
	"prop_mb_crate_01a",
	"prop_mb_crate_01a_set",
	"prop_mb_crate_01b",
	"prop_mb_hesco_06",
	"prop_mb_ordnance_01",
	"prop_mb_ordnance_03",
	"prop_mb_sandblock_01",
	"prop_mb_sandblock_02",
	"prop_mb_sandblock_03",
	"prop_mb_sandblock_04",
	"prop_mb_sandblock_05",
	"prop_medal_01",
	"prop_medstation_02",
	"prop_medstation_03",
	"prop_medstation_04",
	"prop_med_bag_01",
	"prop_med_bag_01b",
	"prop_med_jet_01",
	"prop_megaphone_01",
	"prop_mem_candle_04",
	"prop_mem_candle_05",
	"prop_mem_candle_06",
	"prop_mem_reef_01",
	"prop_mem_reef_02",
	"prop_mem_reef_03",
	"prop_mem_teddy_01",
	"prop_mem_teddy_02",
	"prop_metalfoodjar_01",
	"prop_metal_plates01",
	"prop_metal_plates02",
	"prop_meth_bag_01",
	"prop_michaels_credit_tv",
	"prop_michael_backpack",
	"prop_michael_balaclava",
	"prop_michael_door",
	"prop_michael_sec_id",
	"prop_microphone_02",
	"prop_microwave_1",
	"prop_micro_01",
	"prop_micro_02",
	"prop_micro_cs_01",
	"prop_micro_cs_01_door",
	"prop_military_pickup_01",
	"prop_mil_crate_01",
	"prop_mil_crate_02",
	"prop_minigun_01",
	"prop_mobile_mast_1",
	"prop_mobile_mast_2",
	"prop_money_bag_01",
	"prop_monitor_01c",
	"prop_monitor_01d",
	"prop_monitor_02",
	"prop_monitor_03b",
	"prop_motel_door_09",
	"prop_mouse_01",
	"prop_mouse_01a",
	"prop_mouse_01b",
	"prop_mouse_02",
	"prop_movie_rack",
	"prop_mp3_dock",
	"prop_mp_arrow_barrier_01",
	"prop_mp_barrier_01",
	"prop_mp_barrier_01b",
	"prop_mp_barrier_02",
	"prop_mp_barrier_02b",
	"prop_mp_base_marker",
	"prop_mp_boost_01",
	"prop_mp_cant_place_lrg",
	"prop_mp_cant_place_med",
	"prop_mp_cant_place_sm",
	"prop_mp_cone_01",
	"prop_mp_cone_02",
	"prop_mp_cone_03",
	"prop_mp_cone_04",
	"prop_mp_drug_package",
	"prop_mp_drug_pack_blue",
	"prop_mp_drug_pack_red",
	"prop_mp_icon_shad_lrg",
	"prop_mp_icon_shad_med",
	"prop_mp_icon_shad_sm",
	"prop_mp_max_out_lrg",
	"prop_mp_max_out_med",
	"prop_mp_max_out_sm",
	"prop_mp_num_0",
	"prop_mp_num_1",
	"prop_mp_num_2",
	"prop_mp_num_3",
	"prop_mp_num_4",
	"prop_mp_num_5",
	"prop_mp_num_6",
	"prop_mp_num_7",
	"prop_mp_num_8",
	"prop_mp_num_9",
	"prop_mp_placement",
	"prop_mp_placement_lrg",
	"prop_mp_placement_maxd",
	"prop_mp_placement_med",
	"prop_mp_placement_red",
	"prop_mp_placement_sm",
	"prop_mp_ramp_01",
	"prop_mp_ramp_02",
	"prop_mp_ramp_03",
	"prop_mp_repair",
	"prop_mp_repair_01",
	"prop_mp_respawn_02",
	"prop_mp_rocket_01",
	"prop_mp_spike_01",
	"prop_mr_rasberryclean",
	"prop_mr_raspberry_01",
	"prop_muscle_bench_01",
	"prop_muscle_bench_02",
	"prop_muscle_bench_03",
	"prop_muscle_bench_04",
	"prop_muscle_bench_05",
	"prop_muscle_bench_06",
	"prop_muster_wboard_01",
	"prop_muster_wboard_02",
	"prop_m_pack_int_01",
	"prop_necklace_board",
	"prop_news_disp_02a_s",
	"prop_new_drug_pack_01",
	"prop_nigel_bag_pickup",
	"prop_night_safe_01",
	"prop_notepad_01",
	"prop_notepad_02",
	"prop_novel_01",
	"prop_npc_phone",
	"prop_npc_phone_02",
	"prop_office_alarm_01",
	"prop_office_desk_01",
	"prop_offroad_bale01",
	"prop_offroad_bale02_l1_frag_",
	"prop_offroad_barrel01",
	"prop_offroad_tyres01",
	"prop_off_chair_01",
	"prop_off_chair_03",
	"prop_off_chair_04",
	"prop_off_chair_04b",
	"prop_off_chair_04_s",
	"prop_off_chair_05",
	"prop_off_phone_01",
	"prop_oiltub_01",
	"prop_oiltub_02",
	"prop_oiltub_03",
	"prop_oiltub_05",
	"prop_oiltub_06",
	"prop_oil_derrick_01",
	"prop_oil_guage_01",
	"prop_oil_spool_02",
	"prop_oil_valve_01",
	"prop_oil_valve_02",
	"prop_oil_wellhead_01",
	"prop_oil_wellhead_03",
	"prop_oil_wellhead_04",
	"prop_oil_wellhead_05",
	"prop_oil_wellhead_06",
	"prop_oldplough1",
	"prop_old_boot",
	"prop_old_churn_01",
	"prop_old_churn_02",
	"prop_old_deck_chair",
	"prop_old_deck_chair_02",
	"prop_old_farm_01",
	"prop_old_farm_02",
	"prop_old_wood_chair",
	"prop_old_wood_chair_lod",
	"prop_orang_can_01",
	"prop_outdoor_fan_01",
	"prop_out_door_speaker",
	"prop_overalls_01",
	"prop_owl_totem_01",
	"prop_paints_can01",
	"prop_paints_can02",
	"prop_paints_can03",
	"prop_paints_can04",
	"prop_paints_can05",
	"prop_paints_can06",
	"prop_paints_can07",
	"prop_paint_brush01",
	"prop_paint_brush02",
	"prop_paint_brush03",
	"prop_paint_brush04",
	"prop_paint_brush05",
	"prop_paint_roller",
	"prop_paint_spray01a",
	"prop_paint_spray01b",
	"prop_paint_stepl01",
	"prop_paint_stepl01b",
	"prop_paint_stepl02",
	"prop_paint_tray",
	"prop_paint_wpaper01",
	"prop_pallettruck_01",
	"prop_palm_fan_02_a",
	"prop_palm_fan_02_b",
	"prop_palm_fan_03_a",
	"prop_palm_fan_03_b",
	"prop_palm_fan_03_c",
	"prop_palm_fan_03_d",
	"prop_palm_fan_04_a",
	"prop_palm_fan_04_b",
	"prop_palm_fan_04_c",
	"prop_palm_fan_04_d",
	"prop_palm_huge_01a",
	"prop_palm_huge_01b",
	"prop_palm_med_01a",
	"prop_palm_med_01b",
	"prop_palm_med_01c",
	"prop_palm_med_01d",
	"prop_palm_sm_01a",
	"prop_palm_sm_01d",
	"prop_palm_sm_01e",
	"prop_palm_sm_01f",
	"prop_paper_bag_01",
	"prop_paper_bag_small",
	"prop_paper_ball",
	"prop_paper_box_01",
	"prop_paper_box_02",
	"prop_paper_box_03",
	"prop_paper_box_04",
	"prop_paper_box_05",
	"prop_pap_camera_01",
	"prop_parachute",
	"prop_parapack_01",
	"prop_parasol_01",
	"prop_parasol_01_b",
	"prop_parasol_01_c",
	"prop_parasol_01_down",
	"prop_parasol_02",
	"prop_parasol_02_b",
	"prop_parasol_02_c",
	"prop_parasol_03",
	"prop_parasol_03_b",
	"prop_parasol_03_c",
	"prop_parasol_04e",
	"prop_parasol_04e_lod1",
	"prop_parasol_bh_48",
	"prop_parking_sign_06",
	"prop_parking_sign_07",
	"prop_parking_sign_1",
	"prop_parking_sign_2",
	"prop_parking_wand_01",
	"prop_park_ticket_01",
	"prop_partsbox_01",
	"prop_passport_01",
	"prop_patio_heater_01",
	"prop_patio_lounger1",
	"prop_patio_lounger1b",
	"prop_patio_lounger1_table",
	"prop_patio_lounger_2",
	"prop_patio_lounger_3",
	"prop_patriotneon",
	"prop_paynspray_door_l",
	"prop_paynspray_door_r",
	"prop_pc_01a",
	"prop_pc_02a",
	"prop_peanut_bowl_01",
	"prop_ped_pic_01",
	"prop_ped_pic_01_sm",
	"prop_ped_pic_02",
	"prop_ped_pic_02_sm",
	"prop_ped_pic_03",
	"prop_ped_pic_03_sm",
	"prop_ped_pic_04",
	"prop_ped_pic_04_sm",
	"prop_ped_pic_05",
	"prop_ped_pic_05_sm",
	"prop_ped_pic_06",
	"prop_ped_pic_06_sm",
	"prop_ped_pic_07",
	"prop_ped_pic_07_sm",
	"prop_ped_pic_08",
	"prop_ped_pic_08_sm",
	"prop_pencil_01",
	"prop_pharm_sign_01",
	"prop_phonebox_05a",
	"prop_phone_ing",
	"prop_phone_ing_02",
	"prop_phone_ing_03",
	"prop_phone_overlay_01",
	"prop_phone_overlay_02",
	"prop_phone_overlay_anim",
	"prop_phone_proto",
	"prop_phone_proto_back",
	"prop_phone_proto_battery",
	"prop_picnictable_02",
	"prop_piercing_gun",
	"prop_pier_kiosk_01",
	"prop_pier_kiosk_02",
	"prop_pier_kiosk_03",
	"prop_pile_dirt_01",
	"prop_pile_dirt_02",
	"prop_pile_dirt_03",
	"prop_pile_dirt_04",
	"prop_pile_dirt_06",
	"prop_pile_dirt_07",
	"prop_ping_pong",
	"prop_pipes_01a",
	"prop_pipes_01b",
	"prop_pipes_03b",
	"prop_pipes_04a",
	"prop_pipes_05a",
	"prop_pipes_conc_01",
	"prop_pipes_conc_02",
	"prop_pipe_single_01",
	"prop_pistol_holster",
	"prop_pitcher_01_cs",
	"prop_pizza_box_01",
	"prop_pizza_box_02",
	"prop_pizza_oven_01",
	"prop_planer_01",
	"prop_plant_01a",
	"prop_plant_01b",
	"prop_plant_base_01",
	"prop_plant_base_02",
	"prop_plant_base_03",
	"prop_plant_cane_01a",
	"prop_plant_cane_01b",
	"prop_plant_cane_02a",
	"prop_plant_cane_02b",
	"prop_plant_clover_01",
	"prop_plant_clover_02",
	"prop_plant_fern_01a",
	"prop_plant_fern_01b",
	"prop_plant_fern_02a",
	"prop_plant_fern_02b",
	"prop_plant_fern_02c",
	"prop_plant_flower_01",
	"prop_plant_flower_02",
	"prop_plant_flower_03",
	"prop_plant_flower_04",
	"prop_plant_group_01",
	"prop_plant_group_02",
	"prop_plant_group_03",
	"prop_plant_group_04",
	"prop_plant_group_05",
	"prop_plant_group_05b",
	"prop_plant_group_05c",
	"prop_plant_group_05d",
	"prop_plant_group_06a",
	"prop_plant_group_06b",
	"prop_plant_group_06c",
	"prop_plant_int_02a",
	"prop_plant_int_02b",
	"prop_plant_int_05a",
	"prop_plant_int_05b",
	"prop_plant_int_06a",
	"prop_plant_int_06b",
	"prop_plant_int_06c",
	"prop_plant_paradise",
	"prop_plant_paradise_b",
	"prop_plastic_cup_02",
	"prop_plas_barier_01a",
	"prop_plate_04",
	"prop_plate_stand_01",
	"prop_plate_warmer",
	"prop_player_gasmask",
	"prop_player_phone_01",
	"prop_player_phone_02",
	"prop_pliers_01",
	"prop_plywoodpile_01a",
	"prop_plywoodpile_01b",
	"prop_podium_mic",
	"prop_police_door_l",
	"prop_police_door_l_dam",
	"prop_police_door_r",
	"prop_police_door_r_dam",
	"prop_police_door_surround",
	"prop_police_phone",
	"prop_police_radio_handset",
	"prop_police_radio_main",
	"prop_poly_bag_01",
	"prop_poly_bag_money",
	"prop_poolball_1",
	"prop_poolball_10",
	"prop_poolball_11",
	"prop_poolball_12",
	"prop_poolball_13",
	"prop_poolball_14",
	"prop_poolball_15",
	"prop_poolball_2",
	"prop_poolball_3",
	"prop_poolball_4",
	"prop_poolball_5",
	"prop_poolball_6",
	"prop_poolball_7",
	"prop_poolball_8",
	"prop_poolball_9",
	"prop_poolball_cue",
	"prop_poolskimmer",
	"prop_pooltable_02",
	"prop_pooltable_3b",
	"prop_pool_ball_01",
	"prop_pool_cue",
	"prop_pool_rack_01",
	"prop_pool_rack_02",
	"prop_pool_tri",
	"prop_porn_mag_01",
	"prop_porn_mag_02",
	"prop_porn_mag_03",
	"prop_porn_mag_04",
	"prop_portable_hifi_01",
	"prop_portacabin01",
	"prop_portasteps_01",
	"prop_portasteps_02",
	"prop_postcard_rack",
	"prop_poster_tube_01",
	"prop_poster_tube_02",
	"prop_postit_drive",
	"prop_postit_gun",
	"prop_postit_it",
	"prop_postit_lock",
	"prop_potatodigger",
	"prop_pot_01",
	"prop_pot_02",
	"prop_pot_03",
	"prop_pot_04",
	"prop_pot_05",
	"prop_pot_06",
	"prop_pot_plant_02a",
	"prop_pot_plant_02b",
	"prop_pot_plant_02c",
	"prop_pot_plant_02d",
	"prop_pot_plant_03a",
	"prop_pot_plant_04a",
	"prop_pot_plant_05d_l1",
	"prop_pot_plant_bh1",
	"prop_pot_rack",
	"prop_power_cell",
	"prop_power_cord_01",
	"prop_premier_fence_01",
	"prop_premier_fence_02",
	"prop_printer_01",
	"prop_printer_02",
	"prop_pris_bars_01",
	"prop_pris_bench_01",
	"prop_pris_door_01_l",
	"prop_pris_door_01_r",
	"prop_pris_door_02",
	"prop_pris_door_03",
	"prop_prlg_gravestone_05a_l1",
	"prop_prlg_gravestone_06a",
	"prop_projector_overlay",
	"prop_prologue_phone",
	"prop_prop_tree_01",
	"prop_prop_tree_02",
	"prop_protest_sign_01",
	"prop_protest_table_01",
	"prop_prototype_minibomb",
	"prop_proxy_chateau_table",
	"prop_punch_bag_l",
	"prop_pylon_01",
	"prop_pylon_02",
	"prop_pylon_03",
	"prop_pylon_04",
	"prop_p_jack_03_col",
	"prop_p_spider_01a",
	"prop_p_spider_01c",
	"prop_p_spider_01d",
	"prop_ql_revolving_door",
	"prop_quad_grid_line",
	"prop_radiomast01",
	"prop_radiomast02",
	"prop_rad_waste_barrel_01",
	"prop_ragganeon",
	"prop_rag_01",
	"prop_railsleepers01",
	"prop_railsleepers02",
	"prop_railstack01",
	"prop_railstack02",
	"prop_railstack03",
	"prop_railstack04",
	"prop_railstack05",
	"prop_rail_boxcar",
	"prop_rail_boxcar2",
	"prop_rail_boxcar3",
	"prop_rail_boxcar4",
	"prop_rail_boxcar5",
	"prop_rail_boxcar5_d",
	"prop_rail_buffer_01",
	"prop_rail_buffer_02",
	"prop_rail_controller",
	"prop_rail_crane_01",
	"prop_rail_points01",
	"prop_rail_points02",
	"prop_rail_sigbox01",
	"prop_rail_sigbox02",
	"prop_rail_signals02",
	"prop_rail_tankcar",
	"prop_rail_tankcar2",
	"prop_rail_tankcar3",
	"prop_rail_wellcar",
	"prop_rail_wellcar2",
	"prop_range_target_01",
	"prop_range_target_02",
	"prop_range_target_03",
	"prop_rebar_pile01",
	"prop_recyclebin_02a",
	"prop_recyclebin_02b",
	"prop_recyclebin_02_c",
	"prop_recyclebin_02_d",
	"prop_recyclebin_03_a",
	"prop_recyclebin_04_a",
	"prop_recyclebin_04_b",
	"prop_recyclebin_05_a",
	"prop_ret_door",
	"prop_ret_door_02",
	"prop_ret_door_03",
	"prop_ret_door_04",
	"prop_rf_conc_pillar",
	"prop_riding_crop_01",
	"prop_riot_shield",
	"prop_rio_del_01",
	"prop_roadcone01a",
	"prop_roadcone01b",
	"prop_roadcone01c",
	"prop_roadcone02a",
	"prop_roadcone02b",
	"prop_roadcone02c",
	"prop_roadheader_01",
	"prop_rock_1_a",
	"prop_rock_1_b",
	"prop_rock_1_c",
	"prop_rock_1_d",
	"prop_rock_1_e",
	"prop_rock_1_f",
	"prop_rock_1_g",
	"prop_rock_1_h",
	"prop_rock_1_i",
	"prop_rock_2_a",
	"prop_rock_2_c",
	"prop_rock_2_d",
	"prop_rock_2_f",
	"prop_rock_2_g",
	"prop_rock_3_a",
	"prop_rock_3_b",
	"prop_rock_3_c",
	"prop_rock_3_d",
	"prop_rock_3_e",
	"prop_rock_3_f",
	"prop_rock_3_g",
	"prop_rock_3_h",
	"prop_rock_3_i",
	"prop_rock_3_j",
	"prop_rock_4_c",
	"prop_rock_4_d",
	"prop_rock_chair_01",
	"prop_rolled_sock_01",
	"prop_rolled_sock_02",
	"prop_rolled_yoga_mat",
	"prop_roller_car_01",
	"prop_roller_car_02",
	"prop_ron_door_01",
	"prop_roofpipe_01",
	"prop_roofpipe_02",
	"prop_roofpipe_03",
	"prop_roofpipe_04",
	"prop_roofpipe_05",
	"prop_roofpipe_06",
	"prop_roofvent_011a",
	"prop_roofvent_01a",
	"prop_roofvent_01b",
	"prop_roofvent_02a",
	"prop_roofvent_02b",
	"prop_roofvent_03a",
	"prop_roofvent_04a",
	"prop_roofvent_05a",
	"prop_roofvent_05b",
	"prop_roofvent_07a",
	"prop_roofvent_08a",
	"prop_roofvent_09a",
	"prop_roofvent_10a",
	"prop_roofvent_10b",
	"prop_roofvent_11b",
	"prop_roofvent_11c",
	"prop_roofvent_12a",
	"prop_roofvent_13a",
	"prop_roofvent_15a",
	"prop_roofvent_16a",
	"prop_rope_family_3",
	"prop_rope_hook_01",
	"prop_roundbailer01",
	"prop_roundbailer02",
	"prop_rub_bike_01",
	"prop_rub_bike_02",
	"prop_rub_bike_03",
	"prop_rub_binbag_sd_01",
	"prop_rub_binbag_sd_02",
	"prop_rub_busdoor_01",
	"prop_rub_busdoor_02",
	"prop_rub_buswreck_01",
	"prop_rub_buswreck_03",
	"prop_rub_buswreck_06",
	"prop_rub_cabinet",
	"prop_rub_cabinet01",
	"prop_rub_cabinet02",
	"prop_rub_cabinet03",
	"prop_rub_cage01a",
	"prop_rub_carpart_02",
	"prop_rub_carpart_03",
	"prop_rub_carpart_04",
	"prop_rub_chassis_01",
	"prop_rub_chassis_02",
	"prop_rub_chassis_03",
	"prop_rub_cont_01a",
	"prop_rub_cont_01b",
	"prop_rub_cont_01c",
	"prop_rub_flotsam_01",
	"prop_rub_flotsam_02",
	"prop_rub_flotsam_03",
	"prop_rub_frklft",
	"prop_rub_litter_01",
	"prop_rub_litter_02",
	"prop_rub_litter_03",
	"prop_rub_litter_03b",
	"prop_rub_litter_03c",
	"prop_rub_litter_04",
	"prop_rub_litter_04b",
	"prop_rub_litter_05",
	"prop_rub_litter_06",
	"prop_rub_litter_07",
	"prop_rub_litter_09",
	"prop_rub_litter_8",
	"prop_rub_matress_01",
	"prop_rub_matress_02",
	"prop_rub_matress_03",
	"prop_rub_matress_04",
	"prop_rub_monitor",
	"prop_rub_pile_01",
	"prop_rub_pile_02",
	"prop_rub_planks_01",
	"prop_rub_planks_02",
	"prop_rub_planks_03",
	"prop_rub_planks_04",
	"prop_rub_railwreck_1",
	"prop_rub_railwreck_2",
	"prop_rub_railwreck_3",
	"prop_rub_scrap_02",
	"prop_rub_scrap_03",
	"prop_rub_scrap_04",
	"prop_rub_scrap_05",
	"prop_rub_scrap_06",
	"prop_rub_scrap_07",
	"prop_rub_stool",
	"prop_rub_sunktyre",
	"prop_rub_t34",
	"prop_rub_trainers_01",
	"prop_rub_trolley01a",
	"prop_rub_trolley02a",
	"prop_rub_trolley03a",
	"prop_rub_trukwreck_1",
	"prop_rub_trukwreck_2",
	"prop_rub_tyre_01",
	"prop_rub_tyre_02",
	"prop_rub_tyre_03",
	"prop_rub_tyre_dam1",
	"prop_rub_tyre_dam2",
	"prop_rub_tyre_dam3",
	"prop_rub_washer_01",
	"prop_rub_wheel_01",
	"prop_rub_wheel_02",
	"prop_rub_wreckage_3",
	"prop_rub_wreckage_4",
	"prop_rub_wreckage_5",
	"prop_rub_wreckage_6",
	"prop_rub_wreckage_7",
	"prop_rub_wreckage_8",
	"prop_rub_wreckage_9",
	"prop_rural_windmill_l1",
	"prop_rural_windmill_l2",
	"prop_rus_olive",
	"prop_rus_olive_wint",
	"prop_sacktruck_01",
	"prop_sacktruck_02a",
	"prop_safety_glasses",
	"prop_sam_01",
	"prop_sandwich_01",
	"prop_satdish_2_a",
	"prop_satdish_2_f",
	"prop_satdish_2_g",
	"prop_satdish_3_b",
	"prop_satdish_3_c",
	"prop_satdish_3_d",
	"prop_satdish_l_01",
	"prop_satdish_s_03",
	"prop_satdish_s_05a",
	"prop_satdish_s_05b",
	"prop_sc1_06_gate_l",
	"prop_sc1_06_gate_r",
	"prop_sc1_12_door",
	"prop_sc1_21_g_door_01",
	"prop_scaffold_pole",
	"prop_scafold_01a",
	"prop_scafold_01c",
	"prop_scafold_01f",
	"prop_scafold_02a",
	"prop_scafold_02c",
	"prop_scafold_03a",
	"prop_scafold_03b",
	"prop_scafold_03c",
	"prop_scafold_03f",
	"prop_scafold_04a",
	"prop_scafold_05a",
	"prop_scafold_06a",
	"prop_scafold_06b",
	"prop_scafold_06c",
	"prop_scafold_07a",
	"prop_scafold_08a",
	"prop_scafold_09a",
	"prop_scafold_frame1a",
	"prop_scafold_frame1b",
	"prop_scafold_frame1c",
	"prop_scafold_frame1f",
	"prop_scafold_frame2a",
	"prop_scafold_frame2b",
	"prop_scafold_frame2c",
	"prop_scafold_frame3a",
	"prop_scafold_frame3c",
	"prop_scafold_rail_01",
	"prop_scafold_rail_02",
	"prop_scafold_rail_03",
	"prop_scafold_xbrace",
	"prop_scalpel",
	"prop_scn_police_torch",
	"prop_scourer_01",
	"prop_scrap_2_crate",
	"prop_scrap_win_01",
	"prop_scrim_01",
	"prop_scythemower",
	"prop_section_garage_01",
	"prop_securityvan_lightrig",
	"prop_security_case_01",
	"prop_security_case_02",
	"prop_sec_gate_01b",
	"prop_sec_gate_01c",
	"prop_sec_gate_01d",
	"prop_set_generator_01",
	"prop_sewing_fabric",
	"prop_sewing_machine",
	"prop_sglasses_stand_01",
	"prop_sglasses_stand_02",
	"prop_sglasses_stand_02b",
	"prop_sglasses_stand_03",
	"prop_sglasss_1b_lod",
	"prop_sglasss_1_lod",
	"prop_shamal_crash",
	"prop_shelves_01",
	"prop_shelves_02",
	"prop_shelves_03",
	"prop_shopping_bags01",
	"prop_shopping_bags02",
	"prop_shop_front_door_l",
	"prop_shop_front_door_r",
	"prop_shots_glass_cs",
	"prop_shower_01",
	"prop_shower_rack_01",
	"prop_shower_towel",
	"prop_showroom_door_l",
	"prop_showroom_door_r",
	"prop_showroom_glass_1b",
	"prop_shredder_01",
	"prop_shrub_rake",
	"prop_shuttering01",
	"prop_shuttering02",
	"prop_shuttering03",
	"prop_shuttering04",
	"prop_sh_beer_pissh_01",
	"prop_sh_bong_01",
	"prop_sh_cigar_01",
	"prop_sh_joint_01",
	"prop_sh_mr_rasp_01",
	"prop_sh_shot_glass",
	"prop_sh_tall_glass",
	"prop_sh_tt_fridgedoor",
	"prop_sh_wine_glass",
	"prop_side_lights",
	"prop_side_spreader",
	"prop_sign_airp_01a",
	"prop_sign_airp_02a",
	"prop_sign_airp_02b",
	"prop_sign_big_01",
	"prop_sign_mallet",
	"prop_sign_road_04g_l1",
	"prop_single_grid_line",
	"prop_single_rose",
	"prop_sink_01",
	"prop_sink_02",
	"prop_sink_03",
	"prop_sink_04",
	"prop_sink_05",
	"prop_sink_06",
	"prop_skate_flatramp",
	"prop_skate_funbox",
	"prop_skate_halfpipe",
	"prop_skate_kickers",
	"prop_skate_quartpipe",
	"prop_skate_rail",
	"prop_skate_spiner",
	"prop_skid_chair_01",
	"prop_skid_chair_02",
	"prop_skid_chair_03",
	"prop_skid_sleepbag_1",
	"prop_skid_tent_01",
	"prop_skid_tent_01b",
	"prop_skid_tent_03",
	"prop_skip_01a",
	"prop_skip_02a",
	"prop_skip_03",
	"prop_skip_04",
	"prop_skip_05a",
	"prop_skip_05b",
	"prop_skip_06a",
	"prop_skip_08a",
	"prop_skip_08b",
	"prop_skip_10a",
	"prop_skip_rope_01",
	"prop_skunk_bush_01",
	"prop_skylight_01",
	"prop_skylight_02",
	"prop_skylight_03",
	"prop_skylight_04",
	"prop_skylight_05",
	"prop_skylight_06a",
	"prop_skylight_06b",
	"prop_skylight_06c",
	"prop_sky_cover_01",
	"prop_slacks_01",
	"prop_slacks_02",
	"prop_sluicegate",
	"prop_sluicegatel",
	"prop_sluicegater",
	"prop_slush_dispenser",
	"prop_sm1_11_doorl",
	"prop_sm1_11_doorr",
	"prop_sm1_11_garaged",
	"prop_smg_holster_01",
	"prop_sm_10_mp_door",
	"prop_sm_14_mp_gar",
	"prop_sm_19_clock",
	"prop_sm_27_door",
	"prop_sm_27_gate",
	"prop_sm_27_gate_02",
	"prop_sm_27_gate_03",
	"prop_sm_27_gate_04",
	"prop_sm_locker_door",
	"prop_snow_bailer_01",
	"prop_snow_barrel_pile_03",
	"prop_snow_bench_01",
	"prop_snow_bin_01",
	"prop_snow_bin_02",
	"prop_snow_bush_01_a",
	"prop_snow_bush_02_a",
	"prop_snow_bush_02_b",
	"prop_snow_bush_03",
	"prop_snow_bush_04",
	"prop_snow_bush_04b",
	"prop_snow_cam_03",
	"prop_snow_cam_03a",
	"prop_snow_diggerbkt_01",
	"prop_snow_dumpster_01",
	"prop_snow_elecbox_16",
	"prop_snow_facgate_01",
	"prop_snow_field_01",
	"prop_snow_field_02",
	"prop_snow_field_03",
	"prop_snow_field_04",
	"prop_snow_flower_01",
	"prop_snow_flower_02",
	"prop_snow_fnclink_03crnr2",
	"prop_snow_fnclink_03h",
	"prop_snow_fnclink_03i",
	"prop_snow_fncwood_14a",
	"prop_snow_fncwood_14b",
	"prop_snow_fncwood_14c",
	"prop_snow_fncwood_14d",
	"prop_snow_fncwood_14e",
	"prop_snow_fnc_01",
	"prop_snow_gate_farm_03",
	"prop_snow_grain_01",
	"prop_snow_grass_01",
	"prop_snow_light_01",
	"prop_snow_oldlight_01b",
	"prop_snow_rail_signals02",
	"prop_snow_rub_trukwreck_2",
	"prop_snow_side_spreader_01",
	"prop_snow_streetlight01",
	"prop_snow_streetlight_01_frag_",
	"prop_snow_sub_frame_01a",
	"prop_snow_sub_frame_04b",
	"prop_snow_telegraph_01a",
	"prop_snow_telegraph_02a",
	"prop_snow_telegraph_03",
	"prop_snow_traffic_rail_1a",
	"prop_snow_traffic_rail_1b",
	"prop_snow_trailer01",
	"prop_snow_tree_03_e",
	"prop_snow_tree_03_h",
	"prop_snow_tree_03_i",
	"prop_snow_tree_04_d",
	"prop_snow_tree_04_f",
	"prop_snow_truktrailer_01a",
	"prop_snow_tyre_01",
	"prop_snow_t_ml_01",
	"prop_snow_t_ml_02",
	"prop_snow_t_ml_03",
	"prop_snow_wall_light_15a",
	"prop_snow_watertower01",
	"prop_snow_watertower01_l2",
	"prop_snow_watertower03",
	"prop_snow_woodpile_04a",
	"prop_soap_disp_01",
	"prop_soap_disp_02",
	"prop_solarpanel_01",
	"prop_solarpanel_02",
	"prop_solarpanel_03",
	"prop_sol_chair",
	"prop_space_pistol",
	"prop_space_rifle",
	"prop_speaker_01",
	"prop_speaker_02",
	"prop_speaker_03",
	"prop_speaker_05",
	"prop_speaker_06",
	"prop_speaker_07",
	"prop_speaker_08",
	"prop_speedball_01",
	"prop_sponge_01",
	"prop_sports_clock_01",
	"prop_spot_01",
	"prop_spot_clamp",
	"prop_spot_clamp_02",
	"prop_sprayer",
	"prop_spraygun_01",
	"prop_spray_backpack_01",
	"prop_spray_jackframe",
	"prop_spray_jackleg",
	"prop_sprink_crop_01",
	"prop_sprink_golf_01",
	"prop_sprink_park_01",
	"prop_spycam",
	"prop_squeegee",
	"prop_ss1_05_mp_door",
	"prop_ss1_08_mp_door_l",
	"prop_ss1_08_mp_door_r",
	"prop_ss1_10_door_l",
	"prop_ss1_10_door_r",
	"prop_ss1_14_garage_door",
	"prop_ss1_mpint_door_l",
	"prop_ss1_mpint_door_r",
	"prop_ss1_mpint_garage",
	"prop_ss1_mpint_garage_cl",
	"prop_stag_do_rope",
	"prop_start_finish_line_01",
	"prop_start_grid_01",
	"prop_staticmixer_01",
	"prop_stat_pack_01",
	"prop_steam_basket_01",
	"prop_steam_basket_02",
	"prop_steps_big_01",
	"prop_stickbfly",
	"prop_stickhbird",
	"prop_still",
	"prop_stockade_wheel",
	"prop_stockade_wheel_flat",
	"prop_stool_01",
	"prop_storagetank_01",
	"prop_storagetank_02",
	"prop_storagetank_03",
	"prop_storagetank_03a",
	"prop_storagetank_03b",
	"prop_storagetank_04",
	"prop_storagetank_05",
	"prop_storagetank_06",
	"prop_storagetank_07a",
	"prop_stripmenu",
	"prop_strip_door_01",
	"prop_strip_pole_01",
	"prop_studio_light_02",
	"prop_studio_light_03",
	"prop_sub_chunk_01",
	"prop_sub_cover_01",
	"prop_sub_crane_hook",
	"prop_sub_frame_01a",
	"prop_sub_frame_01b",
	"prop_sub_frame_01c",
	"prop_sub_frame_02a",
	"prop_sub_frame_03a",
	"prop_sub_frame_04a",
	"prop_sub_frame_04b",
	"prop_sub_gantry",
	"prop_sub_release",
	"prop_sub_trans_01a",
	"prop_sub_trans_02a",
	"prop_sub_trans_03a",
	"prop_sub_trans_04a",
	"prop_sub_trans_05b",
	"prop_sub_trans_06b",
	"prop_suitcase_01",
	"prop_suitcase_01b",
	"prop_suitcase_01c",
	"prop_suitcase_01d",
	"prop_suitcase_02",
	"prop_suitcase_03",
	"prop_suitcase_03b",
	"prop_surf_board_ldn_01",
	"prop_surf_board_ldn_02",
	"prop_surf_board_ldn_03",
	"prop_surf_board_ldn_04",
	"prop_syringe_01",
	"prop_s_pine_dead_01",
	"prop_tablesaw_01",
	"prop_tablesmall_01",
	"prop_table_02",
	"prop_table_03b_cs",
	"prop_table_04",
	"prop_table_04_chr",
	"prop_table_05",
	"prop_table_05_chr",
	"prop_table_06",
	"prop_table_06_chr",
	"prop_table_07",
	"prop_table_07_l1",
	"prop_table_08",
	"prop_table_08_chr",
	"prop_table_08_side",
	"prop_table_mic_01",
	"prop_table_para_comb_04",
	"prop_table_tennis",
	"prop_table_ten_bat",
	"prop_taco_01",
	"prop_taco_02",
	"prop_tail_gate_col",
	"prop_tapeplayer_01",
	"prop_target_arm",
	"prop_target_arm_b",
	"prop_target_arm_long",
	"prop_target_arm_sm",
	"prop_target_backboard",
	"prop_target_backboard_b",
	"prop_target_blue",
	"prop_target_blue_arrow",
	"prop_target_bull",
	"prop_target_bull_b",
	"prop_target_comp_metal",
	"prop_target_comp_wood",
	"prop_target_frame_01",
	"prop_target_inner1",
	"prop_target_inner2",
	"prop_target_inner2_b",
	"prop_target_inner3",
	"prop_target_inner3_b",
	"prop_target_inner_b",
	"prop_target_orange_arrow",
	"prop_target_oran_cross",
	"prop_target_ora_purp_01",
	"prop_target_purp_arrow",
	"prop_target_purp_cross",
	"prop_target_red",
	"prop_target_red_arrow",
	"prop_target_red_blue_01",
	"prop_target_red_cross",
	"prop_tarp_strap",
	"prop_taxi_meter_1",
	"prop_taxi_meter_2",
	"prop_tea_trolly",
	"prop_tea_urn",
	"prop_telegraph_01a",
	"prop_telegraph_01b",
	"prop_telegraph_01c",
	"prop_telegraph_01d",
	"prop_telegraph_01e",
	"prop_telegraph_01f",
	"prop_telegraph_01g",
	"prop_telegraph_02a",
	"prop_telegraph_02b",
	"prop_telegraph_03",
	"prop_telegraph_04a",
	"prop_telegraph_04b",
	"prop_telegraph_05a",
	"prop_telegraph_05b",
	"prop_telegraph_05c",
	"prop_telegraph_06a",
	"prop_telegraph_06b",
	"prop_telegraph_06c",
	"prop_telegwall_01a",
	"prop_telegwall_01b",
	"prop_telegwall_02a",
	"prop_telegwall_03a",
	"prop_telegwall_03b",
	"prop_telegwall_04a",
	"prop_telescope",
	"prop_telescope_01",
	"prop_temp_block_blocker",
	"prop_tennis_bag_01",
	"prop_tennis_ball",
	"prop_tennis_ball_lobber",
	"prop_tennis_rack_01",
	"prop_tennis_rack_01b",
	"prop_test_boulder_01",
	"prop_test_boulder_02",
	"prop_test_boulder_03",
	"prop_test_boulder_04",
	"prop_test_elevator",
	"prop_test_elevator_dl",
	"prop_test_elevator_dr",
	"prop_tick",
	"prop_tick_02",
	"prop_till_01_dam",
	"prop_till_02",
	"prop_till_03",
	"prop_time_capsule_01",
	"prop_tint_towel",
	"prop_tint_towels_01",
	"prop_tint_towels_01b",
	"prop_toaster_01",
	"prop_toaster_02",
	"prop_toiletfoot_static",
	"prop_toilet_01",
	"prop_toilet_02",
	"prop_toilet_03",
	"prop_toilet_brush_01",
	"prop_toilet_cube_01",
	"prop_toilet_cube_02",
	"prop_toilet_roll_01",
	"prop_toilet_roll_02",
	"prop_toilet_roll_03",
	"prop_toilet_roll_04",
	"prop_toilet_roll_05",
	"prop_toilet_shamp_01",
	"prop_toilet_shamp_02",
	"prop_toilet_soap_01",
	"prop_toilet_soap_02",
	"prop_toilet_soap_03",
	"prop_toilet_soap_04",
	"prop_toolchest_01",
	"prop_toolchest_02",
	"prop_toolchest_03",
	"prop_toolchest_04",
	"prop_toolchest_05",
	"prop_tool_adjspanner",
	"prop_tool_bench01",
	"prop_tool_bluepnt",
	"prop_tool_box_01",
	"prop_tool_box_02",
	"prop_tool_box_03",
	"prop_tool_box_04",
	"prop_tool_box_05",
	"prop_tool_box_06",
	"prop_tool_box_07",
	"prop_tool_broom",
	"prop_tool_broom2",
	"prop_tool_broom2_l1",
	"prop_tool_cable01",
	"prop_tool_cable02",
	"prop_tool_consaw",
	"prop_tool_drill",
	"prop_tool_fireaxe",
	"prop_tool_hammer",
	"prop_tool_hardhat",
	"prop_tool_jackham",
	"prop_tool_mallet",
	"prop_tool_mopbucket",
	"prop_tool_nailgun",
	"prop_tool_pickaxe",
	"prop_tool_pliers",
	"prop_tool_rake",
	"prop_tool_rake_l1",
	"prop_tool_sawhorse",
	"prop_tool_screwdvr01",
	"prop_tool_screwdvr02",
	"prop_tool_screwdvr03",
	"prop_tool_shovel",
	"prop_tool_shovel006",
	"prop_tool_shovel2",
	"prop_tool_shovel3",
	"prop_tool_shovel4",
	"prop_tool_shovel5",
	"prop_tool_sledgeham",
	"prop_tool_spanner01",
	"prop_tool_spanner02",
	"prop_tool_spanner03",
	"prop_tool_torch",
	"prop_tool_wrench",
	"prop_toothbrush_01",
	"prop_toothb_cup_01",
	"prop_toothpaste_01",
	"prop_tornado_wheel",
	"prop_torture_01",
	"prop_torture_ch_01",
	"prop_tourist_map_01",
	"prop_towel2_01",
	"prop_towel2_02",
	"prop_towel_01",
	"prop_towel_rail_01",
	"prop_towel_rail_02",
	"prop_towel_shelf_01",
	"prop_towel_small_01",
	"prop_towercrane_01a",
	"prop_towercrane_02a",
	"prop_towercrane_02b",
	"prop_towercrane_02c",
	"prop_towercrane_02d",
	"prop_towercrane_02e",
	"prop_towercrane_02el",
	"prop_towercrane_02el2",
	"prop_traffic_rail_1c",
	"prop_traffic_rail_2",
	"prop_trailer01",
	"prop_trailer01_up",
	"prop_trailer_01_new",
	"prop_trailer_door_closed",
	"prop_trailer_door_open",
	"prop_trailer_monitor_01",
	"prop_trailr_base",
	"prop_trailr_base_static",
	"prop_train_ticket_02",
	"prop_tram_pole_double01",
	"prop_tram_pole_double02",
	"prop_tram_pole_double03",
	"prop_tram_pole_roadside",
	"prop_tram_pole_single01",
	"prop_tram_pole_single02",
	"prop_tram_pole_wide01",
	"prop_tree_birch_01",
	"prop_tree_birch_02",
	"prop_tree_birch_03",
	"prop_tree_birch_03b",
	"prop_tree_birch_04",
	"prop_tree_birch_05",
	"prop_tree_cedar_02",
	"prop_tree_cedar_03",
	"prop_tree_cedar_04",
	"prop_tree_cedar_s_01",
	"prop_tree_cedar_s_02",
	"prop_tree_cedar_s_04",
	"prop_tree_cedar_s_05",
	"prop_tree_cedar_s_06",
	"prop_tree_cypress_01",
	"prop_tree_eng_oak_01",
	"prop_tree_eucalip_01",
	"prop_tree_fallen_01",
	"prop_tree_fallen_02",
	"prop_tree_fallen_pine_01",
	"prop_tree_jacada_01",
	"prop_tree_jacada_02",
	"prop_tree_lficus_02",
	"prop_tree_lficus_03",
	"prop_tree_lficus_05",
	"prop_tree_lficus_06",
	"prop_tree_log_01",
	"prop_tree_log_02",
	"prop_tree_maple_02",
	"prop_tree_maple_03",
	"prop_tree_mquite_01",
	"prop_tree_oak_01",
	"prop_tree_olive_01",
	"prop_tree_pine_01",
	"prop_tree_pine_02",
	"prop_tree_stump_01",
	"prop_trevor_rope_01",
	"prop_trev_sec_id",
	"prop_trev_tv_01",
	"prop_triple_grid_line",
	"prop_tri_finish_banner",
	"prop_tri_pod",
	"prop_tri_pod_lod",
	"prop_tri_start_banner",
	"prop_tri_table_01",
	"prop_trough1",
	"prop_truktrailer_01a",
	"prop_tshirt_box_02",
	"prop_tshirt_shelf_1",
	"prop_tshirt_shelf_2",
	"prop_tshirt_shelf_2a",
	"prop_tshirt_shelf_2b",
	"prop_tshirt_shelf_2c",
	"prop_tshirt_stand_01",
	"prop_tshirt_stand_01b",
	"prop_tshirt_stand_02",
	"prop_tshirt_stand_04",
	"prop_tt_screenstatic",
	"prop_tumbler_01",
	"prop_tumbler_01b",
	"prop_tumbler_01_empty",
	"prop_tunnel_liner01",
	"prop_tunnel_liner02",
	"prop_tunnel_liner03",
	"prop_turkey_leg_01",
	"prop_turnstyle_01",
	"prop_tv_02",
	"prop_tv_03_overlay",
	"prop_tv_04",
	"prop_tv_05",
	"prop_tv_06",
	"prop_tv_07",
	"prop_tv_cabinet_03",
	"prop_tv_cabinet_04",
	"prop_tv_cabinet_05",
	"prop_tv_cam_02",
	"prop_tv_flat_01",
	"prop_tv_flat_01_screen",
	"prop_tv_flat_02b",
	"prop_tv_flat_03",
	"prop_tv_flat_03b",
	"prop_tv_flat_michael",
	"prop_tv_test",
	"prop_tyre_rack_01",
	"prop_tyre_spike_01",
	"prop_t_coffe_table",
	"prop_t_shirt_ironing",
	"prop_t_shirt_row_01",
	"prop_t_shirt_row_02",
	"prop_t_shirt_row_02b",
	"prop_t_shirt_row_03",
	"prop_t_shirt_row_04",
	"prop_t_shirt_row_05l",
	"prop_t_shirt_row_05r",
	"prop_t_sofa",
	"prop_t_sofa_02",
	"prop_t_telescope_01b",
	"prop_umpire_01",
	"prop_utensil",
	"prop_valet_03",
	"prop_vault_shutter",
	"prop_vb_34_tencrt_lighting",
	"prop_vcr_01",
	"prop_veg_corn_01",
	"prop_veg_crop_01",
	"prop_veg_crop_02",
	"prop_veg_crop_04",
	"prop_veg_crop_04_leaf",
	"prop_veg_crop_05",
	"prop_veg_crop_06",
	"prop_veg_crop_orange",
	"prop_veg_crop_tr_01",
	"prop_veg_crop_tr_02",
	"prop_veg_grass_01_a",
	"prop_veg_grass_01_b",
	"prop_veg_grass_01_c",
	"prop_veg_grass_01_d",
	"prop_veg_grass_02_a",
	"prop_vehicle_hook",
	"prop_vend_coffe_01",
	"prop_vend_condom_01",
	"prop_vend_fags_01",
	"prop_vend_fridge01",
	"prop_vend_snak_01",
	"prop_venice_board_01",
	"prop_venice_board_02",
	"prop_venice_board_03",
	"prop_venice_counter_01",
	"prop_venice_counter_02",
	"prop_venice_counter_03",
	"prop_venice_counter_04",
	"prop_venice_shop_front_01",
	"prop_venice_sign_09",
	"prop_venice_sign_10",
	"prop_venice_sign_11",
	"prop_venice_sign_12",
	"prop_venice_sign_14",
	"prop_venice_sign_15",
	"prop_venice_sign_16",
	"prop_venice_sign_17",
	"prop_venice_sign_18",
	"prop_ventsystem_01",
	"prop_ventsystem_02",
	"prop_ventsystem_03",
	"prop_ventsystem_04",
	"prop_ven_market_stool",
	"prop_ven_market_table1",
	"prop_ven_shop_1_counter",
	"prop_vertdrill_01",
	"prop_voltmeter_01",
	"prop_v_15_cars_clock",
	"prop_v_5_bclock",
	"prop_v_bmike_01",
	"prop_v_cam_01",
	"prop_v_door_44",
	"prop_v_hook_s",
	"prop_v_m_phone_01",
	"prop_v_m_phone_o1s",
	"prop_v_parachute",
	"prop_waiting_seat_01",
	"prop_wait_bench_01",
	"prop_walllight_ld_01b",
	"prop_wall_light_08a",
	"prop_wall_light_10a",
	"prop_wall_light_10b",
	"prop_wall_light_10c",
	"prop_wall_light_11",
	"prop_wall_light_12",
	"prop_wall_light_17b",
	"prop_wall_light_18a",
	"prop_wall_vent_01",
	"prop_wall_vent_02",
	"prop_wall_vent_03",
	"prop_wall_vent_04",
	"prop_wall_vent_05",
	"prop_wall_vent_06",
	"prop_wardrobe_door_01",
	"prop_warehseshelf01",
	"prop_warehseshelf02",
	"prop_warehseshelf03",
	"prop_warninglight_01",
	"prop_washer_01",
	"prop_washer_02",
	"prop_washer_03",
	"prop_washing_basket_01",
	"prop_watercrate_01",
	"prop_wateringcan",
	"prop_watertower01",
	"prop_watertower02",
	"prop_watertower03",
	"prop_watertower04",
	"prop_waterwheela",
	"prop_waterwheelb",
	"prop_water_bottle",
	"prop_water_bottle_dark",
	"prop_water_corpse_01",
	"prop_water_corpse_02",
	"prop_water_ramp_01",
	"prop_water_ramp_02",
	"prop_water_ramp_03",
	"prop_weed_01",
	"prop_weed_02",
	"prop_weed_block_01",
	"prop_weed_bottle",
	"prop_weed_pallet",
	"prop_weed_tub_01",
	"prop_weed_tub_01b",
	"prop_weight_10k",
	"prop_weight_15k",
	"prop_weight_1_5k",
	"prop_weight_20k",
	"prop_weight_2_5k",
	"prop_weight_5k",
	"prop_weight_rack_01",
	"prop_weight_rack_02",
	"prop_welding_mask_01",
	"prop_weld_torch",
	"prop_wheat_grass_empty",
	"prop_wheat_grass_glass",
	"prop_wheelbarrow01a",
	"prop_wheelbarrow02a",
	"prop_wheelchair_01",
	"prop_wheel_01",
	"prop_wheel_02",
	"prop_wheel_03",
	"prop_wheel_04",
	"prop_wheel_05",
	"prop_wheel_06",
	"prop_wheel_hub_01",
	"prop_wheel_hub_02_lod_02",
	"prop_wheel_rim_01",
	"prop_wheel_rim_02",
	"prop_wheel_rim_03",
	"prop_wheel_rim_04",
	"prop_wheel_rim_05",
	"prop_wheel_tyre",
	"prop_whisk",
	"prop_white_keyboard",
	"prop_winch_hook_long",
	"prop_winch_hook_short",
	"prop_windmill2",
	"prop_windmill_01_l1",
	"prop_windmill_01_slod",
	"prop_windmill_01_slod2",
	"prop_windowbox_a",
	"prop_windowbox_b",
	"prop_windowbox_broken",
	"prop_windowbox_small",
	"prop_win_plug_01",
	"prop_win_plug_01_dam",
	"prop_win_trailer_ld",
	"prop_wok",
	"prop_woodpile_02a",
	"prop_worklight_01a_l1",
	"prop_worklight_03a_l1",
	"prop_worklight_03b_l1",
	"prop_worklight_04a",
	"prop_worklight_04b_l1",
	"prop_worklight_04c_l1",
	"prop_worklight_04d_l1",
	"prop_workwall_01",
	"prop_workwall_02",
	"prop_wreckedcart",
	"prop_wrecked_buzzard",
	"prop_w_board_blank",
	"prop_w_board_blank_2",
	"prop_w_fountain_01",
	"prop_w_r_cedar_01",
	"prop_w_r_cedar_dead",
	"prop_xmas_tree_int",
	"prop_xmas_ext",
	"prop_yacht_lounger",
	"prop_yacht_seat_01",
	"prop_yacht_seat_02",
	"prop_yacht_seat_03",
	"prop_yacht_table_01",
	"prop_yacht_table_02",
	"prop_yacht_table_03",
	"prop_yaught_chair_01",
	"prop_yaught_sofa_01",
	"prop_yell_plastic_target",
	"prop_yoga_mat_01",
	"prop_yoga_mat_02",
	"prop_yoga_mat_03",
	"prop_ztype_covered",
	"p_ing_skiprope_01",
	"p_ing_skiprope_01_s",
	"p_skiprope_r_s",
	"test_prop_gravestones_04a",
	"test_prop_gravestones_05a",
	"test_prop_gravestones_07a",
	"test_prop_gravestones_08a",
	"test_prop_gravestones_09a",
	"test_prop_gravetomb_01a",
	"test_prop_gravetomb_02a",
	"prop_cs_dog_lead_a_s",
	"prop_cs_dog_lead_b_s",
	"prop_welding_mask_01_s",
	"prop_wheelchair_01_s",
	"p_a4_sheets_s",
	"p_amanda_note_01_s",
	"p_armchair_01_s",
	"p_arm_bind_cut_s",
	"p_ashley_neck_01_s",
	"p_banknote_onedollar_s",
	"p_banknote_s",
	"p_binbag_01_s",
	"p_bison_winch_s",
	"p_bloodsplat_s",
	"p_blueprints_01_s",
	"p_brain_chunk_s",
	"p_bs_map_door_01_s",
	"p_cablecar_s",
	"p_cablecar_s_door_l",
	"p_cablecar_s_door_r",
	"p_cash_envelope_01_s",
	"p_cctv_s",
	"p_chem_vial_02b_s",
	"p_clb_officechair_s",
	"p_cletus_necklace_s",
	"p_clothtarp_down_s",
	"p_clothtarp_s",
	"p_clothtarp_up_s",
	"p_controller_01_s",
	"p_crahsed_heli_s",
	"p_cs1_14b_train_s",
	"p_cs1_14b_train_s_col",
	"p_cs1_14b_train_s_colopen",
	"p_csbporndudes_necklace_s",
	"p_csh_strap_01_pro_s",
	"p_csh_strap_01_s",
	"p_csh_strap_03_s",
	"p_cs_15m_rope_s",
	"p_cs_bandana_s",
	"p_cs_beachtowel_01_s",
	"p_cs_beverly_lanyard_s",
	"p_cs_bowl_01b_s",
	"p_cs_ciggy_01b_s",
	"p_cs_clothes_box_s",
	"p_cs_coke_line_s",
	"p_cs_cuffs_02_s",
	"p_cs_duffel_01_s",
	"p_cs_laz_ptail_s",
	"p_cs_leaf_s",
	"p_cs_mp_jet_01_s",
	"p_cs_newspaper_s",
	"p_cs_pamphlet_01_s",
	"p_cs_panties_03_s",
	"p_cs_para_ropebit_s",
	"p_cs_para_ropes_s",
	"p_cs_polaroid_s",
	"p_cs_police_torch_s",
	"p_cs_pour_tube_s",
	"p_cs_power_cord_s",
	"p_cs_rope_tie_01_s",
	"p_cs_sack_01_s",
	"p_cs_saucer_01_s",
	"p_cs_scissors_s",
	"p_cs_script_s",
	"p_cs_shirt_01_s",
	"p_cs_shot_glass_2_s",
	"p_cs_shot_glass_s",
	"p_cs_sub_hook_01_s",
	"p_cs_toaster_s",
	"p_cs_tracy_neck2_s",
	"p_cs_trolley_01_s",
	"p_defilied_ragdoll_01_s",
	"p_devin_box_01_s",
	"p_dinechair_01_s",
	"p_d_scuba_mask_s",
	"p_d_scuba_tank_s",
	"p_ecg_01_cable_01_s",
	"p_fib_rubble_s",
	"p_finale_bld_ground_s",
	"p_finale_bld_pool_s",
	"p_fin_vaultdoor_s",
	"p_flatbed_strap_s",
	"p_folding_chair_01_s",
	"p_gaffer_tape_s",
	"p_gaffer_tape_strip_s",
	"p_gasmask_s",
	"p_gcase_s",
	"p_hand_toilet_s",
	"p_hw1_22_doors_s",
	"p_hw1_22_table_s",
	"p_ice_box_01_s",
	"p_ice_box_proxy_col",
	"p_idol_case_s",
	"p_ilev_p_easychair_s",
	"p_inhaler_01_s",
	"p_jimmyneck_03_s",
	"p_jimmy_necklace_s",
	"p_kitch_juicer_s",
	"p_lamarneck_01_s",
	"p_laptop_02_s",
	"p_large_gold_s",
	"p_lazlow_shirt_s",
	"p_laz_j01_s",
	"p_laz_j02_s",
	"p_ld_cable_tie_01_s",
	"p_ld_crocclips01_s",
	"p_ld_crocclips02_s",
	"p_ld_heist_bag_s_1",
	"p_ld_heist_bag_s_2",
	"p_ld_heist_bag_s_pro",
	"p_ld_heist_bag_s_pro2_s",
	"p_ld_heist_bag_s_pro_o",
	"p_leg_bind_cut_s",
	"p_lestersbed_s",
	"p_lev_sofa_s",
	"p_lifeinv_neck_01_s",
	"p_loose_rag_01_s",
	"p_mbbed_s",
	"p_medal_01_s",
	"p_med_jet_01_s",
	"p_meth_bag_01_s",
	"p_michael_backpack_s",
	"p_michael_scuba_mask_s",
	"p_michael_scuba_tank_s",
	"p_mp_showerdoor_s",
	"p_mrk_harness_s",
	"p_mr_raspberry_01_s",
	"p_novel_01_s",
	"p_omega_neck_01_s",
	"p_omega_neck_02_s",
	"p_orleans_mask_s",
	"p_ortega_necklace_s",
	"p_oscar_necklace_s",
	"p_overalls_02_s",
	"p_pistol_holster_s",
	"p_po1_01_doorm_s",
	"p_police_radio_hset_s",
	"p_poly_bag_01_s",
	"p_pour_wine_s",
	"p_rail_controller_s",
	"p_res_sofa_l_s",
	"p_rpulley_s",
	"p_sec_case_02_s",
	"p_shower_towel_s",
	"p_single_rose_s",
	"p_smg_holster_01_s",
	"p_soloffchair_s",
	"p_spinning_anus_s",
	"p_steve_scuba_hood_s",
	"p_stretch_necklace_s",
	"p_syringe_01_s",
	"p_s_scuba_mask_s",
	"p_s_scuba_tank_s",
	"p_till_01_s",
	"p_tmom_earrings_s",
	"p_tourist_map_01_s",
	"p_trevor_prologe_bally_s",
	"p_trev_rope_01_s",
	"p_trev_ski_mask_s",
	"p_tumbler_01_s",
	"p_tumbler_02_s1",
	"p_tumbler_cs2_s",
	"p_tv_cam_02_s",
	"p_t_shirt_pile_s",
	"p_v_43_safe_s",
	"p_v_ilev_chopshopswitch_s",
	"p_v_med_p_sofa_s",
	"p_v_res_tt_bed_s",
	"p_wade_necklace_s",
	"p_wboard_clth_s",
	"p_weed_bottle_s",
	"p_whiskey_bottle_s",
	"p_winch_long_s",
	"s_prop_hdphones",
	"s_prop_hdphones_1",
	"v_ilev_fib_door1_s",
	"v_res_msonbed_s",
	"v_res_tre_sofa_s",
	"v_tre_sofa_mess_a_s",
	"v_tre_sofa_mess_b_s",
	"v_tre_sofa_mess_c_s",
	"prop_ar_arrow_1",
	"prop_ar_arrow_2",
	"prop_ar_arrow_3",
	"prop_ar_ring_01",
	"prop_mk_arrow_3d",
	"prop_mk_arrow_flat",
	"prop_mk_bike_logo_1",
	"prop_mk_bike_logo_2",
	"prop_mk_boost",
	"prop_mk_cone",
	"prop_mk_cylinder",
	"prop_mk_flag",
	"prop_mk_flag_2",
	"prop_mk_heli",
	"prop_mk_lap",
	"prop_mk_mp_ring_01",
	"prop_mk_mp_ring_01b",
	"prop_mk_num_0",
	"prop_mk_num_1",
	"prop_mk_num_2",
	"prop_mk_num_3",
	"prop_mk_num_4",
	"prop_mk_num_5",
	"prop_mk_num_6",
	"prop_mk_num_7",
	"prop_mk_num_8",
	"prop_mk_num_9",
	"prop_mk_plane",
	"prop_mk_race_chevron_01",
	"prop_mk_race_chevron_02",
	"prop_mk_race_chevron_03",
	"prop_mk_repair",
	"prop_mk_ring",
	"prop_mk_ring_flat",
	"prop_mk_sphere",
	"prop_mk_tri_cycle",
	"prop_mk_tri_run",
	"prop_mk_tri_swim",
	"prop_mp_arrow_ring",
	"prop_mp_halo",
	"prop_mp_halo_lrg",
	"prop_mp_halo_med",
	"prop_mp_halo_point",
	"prop_mp_halo_point_lrg",
	"prop_mp_halo_point_med",
	"prop_mp_halo_point_sm",
	"prop_mp_halo_rotate",
	"prop_mp_halo_rotate_lrg",
	"prop_mp_halo_rotate_med",
	"prop_mp_halo_rotate_sm",
	"prop_mp_halo_sm",
	"prop_mp_pointer_ring",
	"prop_mp_solid_ring",
	"cj_parachute",
	"gb_cap_use",
	"gb_specs_use",
	"cj_proc_tin2",
	"proc_coral_01",
	"proc_fern_02",
	"proc_litter_01",
	"proc_litter_02",
	"proc_mntn_stone01",
	"proc_mntn_stone02",
	"proc_mntn_stone03",
	"proc_searock_01",
	"proc_searock_02",
	"proc_searock_03",
	"proc_sml_stones01",
	"proc_sml_stones02",
	"proc_sml_stones03",
	"proc_trolley_lakebed",
	"prop_bush_gorse_dry",
	"prop_bush_gorse_lush",
	"prop_coral_01",
	"prop_coral_02",
	"prop_coral_03",
	"prop_sapling_01",
	"prop_seabrain_01",
	"prop_seagroup_02",
	"prop_sealife_01",
	"prop_sealife_02",
	"prop_sealife_03",
	"prop_sealife_04",
	"prop_sealife_05",
	"prop_seaweed_01",
	"prop_seaweed_02",
	"prop_starfish_01",
	"prop_starfish_02",
	"prop_starfish_03",
	"prop_aerial_01a",
	"prop_aerial_01b",
	"prop_aerial_01c",
	"prop_aerial_01d",
	"prop_aircon_l_01",
	"prop_aircon_l_02",
	"prop_aircon_l_03",
	"prop_aircon_l_04",
	"prop_aircon_m_09",
	"prop_aircon_s_01a",
	"prop_aircon_s_02a",
	"prop_aircon_s_02b",
	"prop_aircon_s_03a",
	"prop_aircon_s_03b",
	"prop_aircon_s_04a",
	"prop_aircon_s_05a",
	"prop_aircon_s_06a",
	"prop_aircon_s_07a",
	"prop_aircon_s_07b",
	"prop_alarm_01",
	"prop_alarm_02",
	"prop_billb_frame01a",
	"prop_billb_frame01b",
	"prop_billb_frame02a",
	"prop_billb_frame02b",
	"prop_billb_frame03a",
	"prop_billb_frame03b",
	"prop_billb_frame03c",
	"prop_billb_frame04a",
	"prop_billb_frame04b",
	"prop_bmu_01",
	"prop_bmu_01_b",
	"prop_bmu_02",
	"prop_bmu_02_ld",
	"prop_bmu_02_ld_cab",
	"prop_bmu_02_ld_sup",
	"prop_bmu_track01",
	"prop_bmu_track02",
	"prop_bmu_track03",
	"prop_fireescape_01a",
	"prop_fireescape_01b",
	"prop_fireescape_02a",
	"prop_fireescape_02b",
	"prop_flagpole_1a",
	"prop_flagpole_2a",
	"prop_flagpole_3a",
	"prop_helipad_01",
	"prop_helipad_02",
	"prop_radiomast01",
	"prop_radiomast02",
	"prop_roofpipe_01",
	"prop_roofpipe_02",
	"prop_roofpipe_03",
	"prop_roofpipe_04",
	"prop_roofpipe_05",
	"prop_roofpipe_06",
	"prop_roofvent_011a",
	"prop_roofvent_01a",
	"prop_roofvent_01b",
	"prop_roofvent_02a",
	"prop_roofvent_02b",
	"prop_roofvent_03a",
	"prop_roofvent_04a",
	"prop_roofvent_05a",
	"prop_roofvent_05b",
	"prop_roofvent_07a",
	"prop_roofvent_08a",
	"prop_roofvent_09a",
	"prop_roofvent_10a",
	"prop_roofvent_10b",
	"prop_roofvent_11b",
	"prop_roofvent_11c",
	"prop_roofvent_12a",
	"prop_roofvent_13a",
	"prop_roofvent_15a",
	"prop_roofvent_16a",
	"prop_satdish_2_a",
	"prop_satdish_2_f",
	"prop_satdish_2_g",
	"prop_satdish_3_b",
	"prop_satdish_3_c",
	"prop_satdish_3_d",
	"prop_satdish_l_01",
	"prop_satdish_s_03",
	"prop_satdish_s_05a",
	"prop_satdish_s_05b",
	"prop_skylight_01",
	"prop_skylight_02",
	"prop_skylight_03",
	"prop_skylight_04",
	"prop_skylight_05",
	"prop_skylight_06a",
	"prop_skylight_06b",
	"prop_skylight_06c",
	"prop_solarpanel_01",
	"prop_solarpanel_02",
	"prop_solarpanel_03",
	"prop_ventsystem_01",
	"prop_ventsystem_02",
	"prop_ventsystem_03",
	"prop_ventsystem_04",
	"prop_wall_vent_01",
	"prop_wall_vent_02",
	"prop_wall_vent_03",
	"prop_wall_vent_04",
	"prop_wall_vent_05",
	"prop_wall_vent_06",
	"prop_watertower01",
	"prop_watertower02",
	"prop_watertower03",
	"prop_watertower04",
	"prop_bahammenu",
	"prop_barrachneon",
	"prop_bar_coastbarr",
	"prop_bar_coastchamp",
	"prop_bar_coastdusc",
	"prop_bar_coastmount",
	"prop_bar_cooler_01",
	"prop_bar_cooler_03",
	"prop_bar_fridge_01",
	"prop_bar_fridge_02",
	"prop_bar_fridge_03",
	"prop_bar_fridge_04",
	"prop_bar_ice_01",
	"prop_bar_napkindisp",
	"prop_bar_pump_01",
	"prop_bar_pump_04",
	"prop_bar_pump_05",
	"prop_bar_pump_06",
	"prop_bar_pump_07",
	"prop_bar_pump_08",
	"prop_bar_pump_09",
	"prop_bar_pump_10",
	"prop_bar_sink_01",
	"prop_bar_stool_01",
	"prop_beerneon",
	"prop_beer_bison",
	"prop_cherenneon",
	"prop_cockneon",
	"prop_cs_kitchen_cab_l2",
	"prop_cs_kitchen_cab_ld",
	"prop_cs_kitchen_cab_rd",
	"prop_irish_sign_01",
	"prop_irish_sign_02",
	"prop_irish_sign_03",
	"prop_irish_sign_04",
	"prop_irish_sign_05",
	"prop_irish_sign_06",
	"prop_irish_sign_07",
	"prop_irish_sign_08",
	"prop_irish_sign_09",
	"prop_irish_sign_10",
	"prop_irish_sign_11",
	"prop_irish_sign_12",
	"prop_irish_sign_13",
	"prop_loggneon",
	"prop_patriotneon",
	"prop_pitcher_01_cs",
	"prop_ragganeon",
	"prop_shots_glass_cs",
	"prop_stripmenu",
	"prop_bread_rack_01",
	"prop_bread_rack_02",
	"prop_chip_fryer",
	"prop_coffee_mac_02",
	"prop_detergent_01a",
	"prop_detergent_01b",
	"prop_ff_counter_01",
	"prop_ff_counter_02",
	"prop_ff_counter_03",
	"prop_ff_noodle_01",
	"prop_ff_noodle_02",
	"prop_ff_shelves_01",
	"prop_ff_sink_01",
	"prop_ff_sink_02",
	"prop_food_bin_01",
	"prop_food_bin_02",
	"prop_food_bs_bshelf",
	"prop_food_bs_cups01",
	"prop_food_bs_cups03",
	"prop_food_bs_soda_01",
	"prop_food_bs_soda_02",
	"prop_food_bs_tray_01",
	"prop_food_bs_tray_06",
	"prop_food_burg1",
	"prop_food_burg2",
	"prop_food_cb_bshelf",
	"prop_food_cb_burg01",
	"prop_food_cb_cups01",
	"prop_food_cb_donuts",
	"prop_food_cb_nugets",
	"prop_food_cb_soda_01",
	"prop_food_cb_soda_02",
	"prop_food_cb_tray_01",
	"prop_food_cups1",
	"prop_food_napkin_01",
	"prop_food_napkin_02",
	"prop_food_tray_01",
	"prop_griddle_01",
	"prop_griddle_02",
	"prop_handtowels",
	"prop_juice_dispenser",
	"prop_kebab_grill",
	"prop_microwave_1",
	"prop_pizza_oven_01",
	"prop_slush_dispenser",
	"prop_bumper_01",
	"prop_bumper_02",
	"prop_bumper_03",
	"prop_bumper_04",
	"prop_bumper_05",
	"prop_bumper_06",
	"prop_carcreeper",
	"prop_carjack",
	"prop_carjack_l2",
	"prop_car_battery_01",
	"prop_car_bonnet_01",
	"prop_car_bonnet_02",
	"prop_car_door_01",
	"prop_car_door_02",
	"prop_car_door_03",
	"prop_car_door_04",
	"prop_car_engine_01",
	"prop_car_exhaust_01",
	"prop_car_seat",
	"prop_cheetah_covered",
	"prop_compressor_01",
	"prop_compressor_02",
	"prop_compressor_03",
	"prop_entityxf_covered",
	"prop_jb700_covered",
	"prop_spray_jackframe",
	"prop_spray_jackleg",
	"prop_toolchest_01",
	"prop_toolchest_02",
	"prop_toolchest_03",
	"prop_toolchest_04",
	"prop_toolchest_05",
	"prop_wheel_01",
	"prop_wheel_02",
	"prop_wheel_03",
	"prop_wheel_04",
	"prop_wheel_05",
	"prop_wheel_06",
	"prop_wheel_hub_01",
	"prop_wheel_hub_02_lod_02",
	"prop_wheel_rim_01",
	"prop_wheel_rim_02",
	"prop_wheel_rim_03",
	"prop_wheel_rim_04",
	"prop_wheel_rim_05",
	"prop_wheel_tyre",
	"prop_ztype_covered",
	"prop_cabinet_01",
	"prop_cabinet_01b",
	"prop_cabinet_02b",
	"prop_coathook_01",
	"prop_copier_01",
	"prop_fan_01",
	"prop_fax_01",
	"prop_folder_01",
	"prop_folder_02",
	"prop_in_tray_01",
	"prop_office_alarm_01",
	"prop_office_desk_01",
	"prop_off_chair_01",
	"prop_off_chair_03",
	"prop_off_chair_04",
	"prop_off_chair_04b",
	"prop_off_chair_05",
	"prop_off_phone_01",
	"prop_paper_box_01",
	"prop_paper_box_02",
	"prop_paper_box_03",
	"prop_paper_box_04",
	"prop_paper_box_05",
	"prop_printer_01",
	"prop_printer_02",
	"prop_shredder_01",
	"prop_sol_chair",
	"prop_tablesmall_01",
	"prop_waiting_seat_01",
	"prop_wait_bench_01",
	"prop_water_bottle",
	"prop_water_bottle_dark",
	"prop_air_bagloader",
	"prop_air_bagloader2",
	"prop_air_barrier",
	"prop_air_bench_01",
	"prop_air_bench_02",
	"prop_air_bigradar_l1",
	"prop_air_bigradar_l2",
	"prop_air_bigradar_slod",
	"prop_air_blastfence_01",
	"prop_air_blastfence_02",
	"prop_air_bridge01",
	"prop_air_bridge02",
	"prop_air_cargoloader_01",
	"prop_air_cargo_01a",
	"prop_air_cargo_01b",
	"prop_air_cargo_01c",
	"prop_air_cargo_02a",
	"prop_air_cargo_02b",
	"prop_air_cargo_03a",
	"prop_air_cargo_04a",
	"prop_air_cargo_04b",
	"prop_air_cargo_04c",
	"prop_air_chock_01",
	"prop_air_chock_03",
	"prop_air_chock_04",
	"prop_air_fueltrail1",
	"prop_air_fueltrail2",
	"prop_air_gasbogey_01",
	"prop_air_generator_01",
	"prop_air_generator_03",
	"prop_air_lights_01a",
	"prop_air_lights_01b",
	"prop_air_lights_03a",
	"prop_air_luggtrolley",
	"prop_air_mast_01",
	"prop_air_mast_02",
	"prop_air_monhut_01",
	"prop_air_monhut_02",
	"prop_air_monhut_03",
	"prop_air_propeller01",
	"prop_air_radar_01",
	"prop_air_stair_01",
	"prop_air_stair_02",
	"prop_air_stair_03",
	"prop_air_stair_04a",
	"prop_air_stair_04b",
	"prop_air_towbar_01",
	"prop_air_towbar_02",
	"prop_air_towbar_03",
	"prop_air_trailer_4a",
	"prop_air_trailer_4b",
	"prop_air_trailer_4c",
	"prop_air_watertank1",
	"prop_air_watertank2",
	"prop_air_windsock_base",
	"prop_air_woodsteps",
	"prop_luggage_01a",
	"prop_luggage_02a",
	"prop_luggage_03a",
	"prop_luggage_04a",
	"prop_luggage_05a",
	"prop_luggage_06a",
	"prop_luggage_07a",
	"prop_luggage_08a",
	"prop_luggage_09a",
	"prop_mb_cargo_01a",
	"prop_mb_cargo_02a",
	"prop_mb_cargo_03a",
	"prop_mb_cargo_04a",
	"prop_mb_cargo_04b",
	"prop_mb_crate_01a",
	"prop_mb_crate_01b",
	"prop_mb_hesco_06",
	"prop_mb_ordnance_01",
	"prop_mb_ordnance_03",
	"prop_mb_sandblock_01",
	"prop_mb_sandblock_02",
	"prop_mb_sandblock_03",
	"prop_mb_sandblock_04",
	"prop_mb_sandblock_05",
	"prop_boxcar5_handle",
	"prop_byard_bench01",
	"prop_byard_bench02",
	"prop_byard_block_01",
	"prop_byard_boat01",
	"prop_byard_boat02",
	"prop_byard_chains01",
	"prop_byard_dingy",
	"prop_byard_elecbox01",
	"prop_byard_elecbox02",
	"prop_byard_elecbox03",
	"prop_byard_elecbox04",
	"prop_byard_floatpile",
	"prop_byard_float_01",
	"prop_byard_float_01b",
	"prop_byard_float_02",
	"prop_byard_float_02b",
	"prop_byard_hoist",
	"prop_byard_hoist_2",
	"prop_byard_hoses01",
	"prop_byard_hoses02",
	"prop_byard_ladder01",
	"prop_byard_machine01",
	"prop_byard_machine02",
	"prop_byard_machine03",
	"prop_byard_motor_01",
	"prop_byard_motor_02",
	"prop_byard_motor_03",
	"prop_byard_net02",
	"prop_byard_phone",
	"prop_byard_pipes01",
	"prop_byard_pipe_01",
	"prop_byard_planks01",
	"prop_byard_pulley01",
	"prop_byard_rack",
	"prop_byard_ramp",
	"prop_byard_rampold",
	"prop_byard_rowboat1",
	"prop_byard_rowboat2",
	"prop_byard_rowboat3",
	"prop_byard_rowboat4",
	"prop_byard_rowboat5",
	"prop_byard_scfhold01",
	"prop_byard_sleeper01",
	"prop_byard_sleeper02",
	"prop_byard_steps_01",
	"prop_byard_tank_01",
	"prop_byard_trailer01",
	"prop_byard_trailer02",
	"prop_crane_01_truck1",
	"prop_crane_01_truck2",
	"prop_dock_bouy_1",
	"prop_dock_bouy_2",
	"prop_dock_bouy_3",
	"prop_dock_bouy_5",
	"prop_dock_crane_01",
	"prop_dock_crane_02",
	"prop_dock_crane_02_cab",
	"prop_dock_crane_02_hook",
	"prop_dock_crane_02_ld",
	"prop_dock_crane_04",
	"prop_dock_crane_lift",
	"prop_dock_float_1",
	"prop_dock_float_1b",
	"prop_dock_moor_01",
	"prop_dock_moor_04",
	"prop_dock_moor_05",
	"prop_dock_moor_06",
	"prop_dock_moor_07",
	"prop_dock_ropefloat",
	"prop_dock_ropetyre1",
	"prop_dock_ropetyre2",
	"prop_dock_ropetyre3",
	"prop_dock_rtg_01",
	"prop_dock_rtg_ld",
	"prop_dock_shippad",
	"prop_dock_sign_01",
	"prop_dock_woodpole1",
	"prop_dock_woodpole2",
	"prop_dock_woodpole3",
	"prop_dock_woodpole4",
	"prop_dock_woodpole5",
	"prop_ind_barge_01",
	"prop_ind_barge_02",
	"prop_ind_coalcar_01",
	"prop_ind_coalcar_02",
	"prop_ind_coalcar_03",
	"prop_ind_oldcrane",
	"prop_jetski_ramp_01",
	"prop_railsleepers01",
	"prop_railsleepers02",
	"prop_railstack01",
	"prop_railstack02",
	"prop_railstack03",
	"prop_railstack04",
	"prop_railstack05",
	"prop_rail_boxcar",
	"prop_rail_boxcar2",
	"prop_rail_boxcar3",
	"prop_rail_boxcar4",
	"prop_rail_boxcar5",
	"prop_rail_boxcar5_d",
	"prop_rail_buffer_01",
	"prop_rail_buffer_02",
	"prop_rail_crane_01",
	"prop_rail_points01",
	"prop_rail_points02",
	"prop_rail_sigbox01",
	"prop_rail_sigbox02",
	"prop_rail_signals02",
	"prop_rail_tankcar",
	"prop_rail_tankcar2",
	"prop_rail_tankcar3",
	"prop_rail_wellcar",
	"prop_rail_wellcar2",
	"p_dock_rtg_ld_cab",
	"p_dock_rtg_ld_spdr",
	"p_dock_rtg_ld_wheel",
	"prop_fac_machine_02",
	"prop_ind_conveyor_01",
	"prop_ind_conveyor_02",
	"prop_ind_conveyor_04",
	"prop_ind_crusher",
	"prop_ind_deiseltank",
	"prop_ind_mech_01c",
	"prop_ind_mech_02a",
	"prop_ind_mech_02b",
	"prop_ind_mech_03a",
	"prop_ind_mech_04a",
	"prop_jyard_block_01a",
	"prop_oil_derrick_01",
	"prop_oil_guage_01",
	"prop_oil_spool_02",
	"prop_oil_valve_01",
	"prop_oil_valve_02",
	"prop_oil_wellhead_01",
	"prop_oil_wellhead_03",
	"prop_oil_wellhead_04",
	"prop_oil_wellhead_05",
	"prop_oil_wellhead_06",
	"prop_portacabin01",
	"prop_portasteps_01",
	"prop_portasteps_02",
	"prop_pylon_01",
	"prop_pylon_02",
	"prop_pylon_03",
	"prop_pylon_04",
	"prop_sluicegate",
	"prop_sluicegatel",
	"prop_sluicegater",
	"prop_storagetank_01",
	"prop_storagetank_02",
	"prop_storagetank_03",
	"prop_storagetank_03a",
	"prop_storagetank_03b",
	"prop_storagetank_04",
	"prop_storagetank_05",
	"prop_storagetank_06",
	"prop_storagetank_07a",
	"prop_sub_crane_hook",
	"prop_sub_frame_01a",
	"prop_sub_frame_01b",
	"prop_sub_frame_01c",
	"prop_sub_frame_02a",
	"prop_sub_frame_03a",
	"prop_sub_frame_04a",
	"prop_sub_frame_04b",
	"prop_sub_gantry",
	"prop_sub_trans_01a",
	"prop_sub_trans_02a",
	"prop_sub_trans_03a",
	"prop_sub_trans_04a",
	"prop_sub_trans_05b",
	"prop_sub_trans_06b",
	"prop_windmill_01_l1",
	"prop_windmill_01_slod",
	"prop_windmill_01_slod2",
	"prop_acc_guitar_01",
	"prop_acc_guitar_01_d1",
	"prop_alien_egg_01",
	"prop_amb_handbag_01",
	"prop_amb_phone",
	"prop_asteroid_01",
	"prop_attache_case_01",
	"prop_bank_shutter",
	"prop_bank_vaultdoor",
	"prop_barrel_float_1",
	"prop_barrel_float_2",
	"prop_beggers_sign_01",
	"prop_beggers_sign_02",
	"prop_beggers_sign_03",
	"prop_beggers_sign_04",
	"prop_bh1_16_display",
	"prop_big_bag_01",
	"prop_big_clock_01",
	"prop_biotech_store",
	"prop_bomb_01",
	"prop_bonesaw",
	"prop_bskball_01",
	"prop_b_board_blank",
	"prop_cable_hook_01",
	"prop_camera_strap",
	"prop_cash_dep_bag_01",
	"prop_cash_trolly",
	"prop_chem_grill",
	"prop_chem_grill_bit",
	"prop_chem_vial_02",
	"prop_chem_vial_02b",
	"prop_choc_ego",
	"prop_choc_meto",
	"prop_choc_pq",
	"prop_clapper_brd_01",
	"prop_cone_float_1",
	"prop_container_hole",
	"prop_cont_chiller_01",
	"prop_cork_board",
	"prop_cranial_saw",
	"prop_crate_float_1",
	"prop_cs_20m_rope",
	"prop_cs_30m_rope",
	"prop_cs_aircon_01",
	"prop_cs_aircon_fan",
	"prop_cs_ashtray",
	"prop_cs_bin_01",
	"prop_cs_bin_01_lid",
	"prop_cs_bin_02",
	"prop_cs_bin_03",
	"prop_cs_box_clothes",
	"prop_cs_cardbox_01",
	"prop_cs_dumpster_01a",
	"prop_cs_dumpster_lidl",
	"prop_cs_dumpster_lidr",
	"prop_cs_fertilizer",
	"prop_cs_folding_chair_01",
	"prop_cs_fridge",
	"prop_cs_fridge_door",
	"prop_cs_heist_bag_01",
	"prop_cs_heist_bag_02",
	"prop_cs_heist_bag_strap_01",
	"prop_cs_h_bag_strap_01",
	"prop_cs_ice_locker",
	"prop_cs_ice_locker_door_l",
	"prop_cs_ice_locker_door_r",
	"prop_cs_keys_01",
	"prop_cs_leaf",
	"prop_cs_office_chair",
	"prop_cs_package_01",
	"prop_cs_panel_01",
	"prop_cs_panties",
	"prop_cs_panties_02",
	"prop_cs_panties_03",
	"prop_cs_planning_photo",
	"prop_cs_polaroid",
	"prop_cs_remote_01",
	"prop_cs_rope_tie_01",
	"prop_cs_rub_binbag_01",
	"prop_cs_scissors",
	"prop_cs_shopping_bag",
	"prop_cs_spray_can",
	"prop_cs_tablet",
	"prop_cs_tablet_02",
	"prop_cs_vial_01",
	"prop_cs_walking_stick",
	"prop_cub_door_lifeblurb",
	"prop_cub_lifeblurb",
	"prop_cuff_keys_01",
	"prop_defilied_ragdoll_01",
	"prop_drop_armscrate_01",
	"prop_drop_armscrate_01b",
	"prop_dummy_01",
	"prop_dummy_light",
	"prop_dummy_plane",
	"prop_egg_clock_01",
	"prop_ejector_seat_01",
	"prop_el_guitar_01",
	"prop_el_guitar_02",
	"prop_el_guitar_03",
	"prop_fbibombbin",
	"prop_fbibombcupbrd",
	"prop_fbibombfile",
	"prop_fbibombplant",
	"prop_feed_sack_01",
	"prop_feed_sack_02",
	"prop_fib_broken_window",
	"prop_flash_unit",
	"prop_flatbed_strap_b",
	"prop_floor_duster_01",
	"prop_folded_polo_shirt",
	"prop_foundation_sponge",
	"prop_fruit_basket",
	"prop_f_duster_02",
	"prop_gascyl_ramp_01",
	"prop_gascyl_ramp_door_01",
	"prop_gas_grenade",
	"prop_gas_mask_hang_01",
	"prop_gold_bar",
	"prop_gold_trolly",
	"prop_gold_trolly_full",
	"prop_grapes_01",
	"prop_grapes_02",
	"prop_hacky_sack_01",
	"prop_hd_seats_01",
	"prop_hole_plug_01",
	"prop_hotel_clock_01",
	"prop_hotel_trolley",
	"prop_huge_display_01",
	"prop_huge_display_02",
	"prop_idol_01_error",
	"prop_idol_case_01",
	"prop_ing_camera_01",
	"prop_int_gate01",
	"prop_jewel_02a",
	"prop_jewel_02b",
	"prop_jewel_02c",
	"prop_jewel_03a",
	"prop_jewel_03b",
	"prop_jewel_04a",
	"prop_jewel_04b",
	"prop_jewel_pickup_new_01",
	"prop_j_disptray_01",
	"prop_j_disptray_01b",
	"prop_j_disptray_01_dam",
	"prop_j_disptray_02",
	"prop_j_disptray_02_dam",
	"prop_j_disptray_03",
	"prop_j_disptray_03_dam",
	"prop_j_disptray_04",
	"prop_j_disptray_04b",
	"prop_j_disptray_05",
	"prop_j_disptray_05b",
	"prop_j_heist_pic_01",
	"prop_j_heist_pic_02",
	"prop_j_heist_pic_03",
	"prop_j_heist_pic_04",
	"prop_j_neck_disp_01",
	"prop_j_neck_disp_02",
	"prop_j_neck_disp_03",
	"prop_large_gold",
	"prop_large_gold_alt_a",
	"prop_large_gold_alt_b",
	"prop_large_gold_alt_c",
	"prop_large_gold_empty",
	"prop_ld_alarm_01",
	"prop_ld_alarm_01_dam",
	"prop_ld_alarm_alert",
	"prop_ld_armour",
	"prop_ld_binbag_01",
	"prop_ld_bomb",
	"prop_ld_cable",
	"prop_ld_cable_tie_01",
	"prop_ld_case_01",
	"prop_ld_case_01_lod",
	"prop_ld_container",
	"prop_ld_contain_dl",
	"prop_ld_contain_dl2",
	"prop_ld_contain_dr",
	"prop_ld_contain_dr2",
	"prop_ld_crate_01",
	"prop_ld_crate_lid_01",
	"prop_ld_fan_01",
	"prop_ld_fan_01_old",
	"prop_ld_greenscreen_01",
	"prop_ld_handbag",
	"prop_ld_haybail",
	"prop_ld_health_pack",
	"prop_ld_hook",
	"prop_ld_int_safe_01",
	"prop_ld_jerrycan_01",
	"prop_ld_keypad_01",
	"prop_ld_keypad_01b",
	"prop_ld_keypad_01b_lod",
	"prop_ld_lap_top",
	"prop_ld_monitor_01",
	"prop_ld_pipe_single_01",
	"prop_ld_planning_pin_01",
	"prop_ld_planning_pin_02",
	"prop_ld_planning_pin_03",
	"prop_ld_purse_01",
	"prop_ld_purse_01_lod",
	"prop_ld_rope_t",
	"prop_ld_rub_binbag_01",
	"prop_ld_suitcase_01",
	"prop_ld_suitcase_02",
	"prop_ld_toilet_01",
	"prop_ld_vault_door",
	"prop_ld_wallet_01",
	"prop_ld_w_me_machette",
	"prop_lectern_01",
	"prop_lev_crate_01",
	"prop_lifeblurb_01",
	"prop_lifeblurb_01b",
	"prop_lifeblurb_02",
	"prop_lifeblurb_02b",
	"prop_mast_01",
	"prop_medal_01",
	"prop_med_bag_01",
	"prop_med_bag_01b",
	"prop_michael_backpack",
	"prop_mr_rasberryclean",
	"prop_mr_raspberry_01",
	"prop_muster_wboard_01",
	"prop_muster_wboard_02",
	"prop_necklace_board",
	"prop_new_drug_pack_01",
	"prop_night_safe_01",
	"prop_novel_01",
	"prop_npc_phone",
	"prop_npc_phone_02",
	"prop_out_door_speaker",
	"prop_overalls_01",
	"prop_paper_bag_01",
	"prop_paper_bag_small",
	"prop_paper_ball",
	"prop_pap_camera_01",
	"prop_parachute",
	"prop_parapack_01",
	"prop_paynspray_door_l",
	"prop_paynspray_door_r",
	"prop_ped_pic_01",
	"prop_ped_pic_01_sm",
	"prop_ped_pic_02",
	"prop_ped_pic_02_sm",
	"prop_ped_pic_03",
	"prop_ped_pic_03_sm",
	"prop_ped_pic_04",
	"prop_ped_pic_04_sm",
	"prop_ped_pic_05",
	"prop_ped_pic_05_sm",
	"prop_ped_pic_06",
	"prop_ped_pic_06_sm",
	"prop_ped_pic_07",
	"prop_ped_pic_07_sm",
	"prop_ped_pic_08",
	"prop_ped_pic_08_sm",
	"prop_phone_ing",
	"prop_phone_ing_02",
	"prop_phone_ing_03",
	"prop_phone_overlay_01",
	"prop_phone_overlay_02",
	"prop_phone_overlay_anim",
	"prop_phone_proto",
	"prop_phone_proto_back",
	"prop_phone_proto_battery",
	"prop_player_phone_01",
	"prop_player_phone_02",
	"prop_podium_mic",
	"prop_police_phone",
	"prop_poly_bag_01",
	"prop_poly_bag_money",
	"prop_pool_ball_01",
	"prop_postit_drive",
	"prop_postit_gun",
	"prop_postit_it",
	"prop_postit_lock",
	"prop_prologue_phone",
	"prop_protest_sign_01",
	"prop_protest_table_01",
	"prop_prototype_minibomb",
	"prop_rag_01",
	"prop_rf_conc_pillar",
	"prop_riding_crop_01",
	"prop_rock_chair_01",
	"prop_rolled_yoga_mat",
	"prop_rope_hook_01",
	"prop_scalpel",
	"prop_scrap_win_01",
	"prop_security_case_01",
	"prop_security_case_02",
	"prop_shamal_crash",
	"prop_shopping_bags01",
	"prop_shopping_bags02",
	"prop_showroom_glass_1b",
	"prop_side_lights",
	"prop_single_rose",
	"prop_sky_cover_01",
	"prop_sm_19_clock",
	"prop_sm_locker_door",
	"prop_spot_01",
	"prop_spot_clamp",
	"prop_spot_clamp_02",
	"prop_stat_pack_01",
	"prop_strip_pole_01",
	"prop_sub_chunk_01",
	"prop_tail_gate_col",
	"prop_taxi_meter_1",
	"prop_taxi_meter_2",
	"prop_telescope_01",
	"prop_tennis_bag_01",
	"prop_test_elevator",
	"prop_test_elevator_dl",
	"prop_test_elevator_dr",
	"prop_tick",
	"prop_tick_02",
	"prop_toiletfoot_static",
	"prop_torture_ch_01",
	"prop_tri_table_01",
	"prop_tyre_spike_01",
	"prop_t_coffe_table",
	"prop_t_sofa",
	"prop_t_sofa_02",
	"prop_t_telescope_01b",
	"prop_vb_34_tencrt_lighting",
	"prop_vehicle_hook",
	"prop_v_bmike_01",
	"prop_v_cam_01",
	"prop_v_hook_s",
	"prop_v_m_phone_01",
	"prop_v_parachute",
	"prop_water_ramp_01",
	"prop_water_ramp_02",
	"prop_water_ramp_03",
	"prop_wheelchair_01",
	"prop_windowbox_a",
	"prop_windowbox_b",
	"prop_windowbox_broken",
	"prop_windowbox_small",
	"prop_win_trailer_ld",
	"prop_w_board_blank",
	"prop_w_board_blank_2",
	"prop_yoga_mat_01",
	"prop_yoga_mat_02",
	"prop_yoga_mat_03",
	"p_amb_bag_bottle_01",
	"p_amb_brolly_01",
	"p_amb_brolly_01_s",
	"p_amb_clipboard_01",
	"p_amb_coffeecup_01",
	"p_amb_joint_01",
	"p_amb_lap_top_01",
	"p_amb_lap_top_02",
	"p_amb_phone_01",
	"p_car_keys_01",
	"p_counter_01_glass",
	"p_counter_01_glass_plug",
	"p_counter_02_glass",
	"p_counter_03_glass",
	"p_counter_04_glass",
	"p_cs_cam_phone",
	"p_cs_comb_01",
	"p_cs_laptop_02",
	"p_cs_laptop_02_w",
	"p_cs_locker_01",
	"p_cs_locker_02",
	"p_cs_locker_door_01",
	"p_cs_locker_door_01b",
	"p_cs_locker_door_02",
	"p_cs_paper_disp_02",
	"p_cs_paper_disp_1",
	"p_disp_02_door_01",
	"p_ferris_car_01",
	"p_f_duster_handle_01",
	"p_f_duster_head_01",
	"p_ing_skiprope_01",
	"p_int_jewel_mirror",
	"p_int_jewel_plant_01",
	"p_int_jewel_plant_02",
	"p_jewel_necklace_02",
	"p_ld_am_ball_01",
	"p_ld_coffee_vend_01",
	"p_ld_conc_cyl_01",
	"p_ld_frisbee_01",
	"p_ld_heist_bag_01",
	"p_ld_sax",
	"p_ld_soc_ball_01",
	"p_new_j_counter_01",
	"p_new_j_counter_02",
	"p_new_j_counter_03",
	"p_num_plate_01",
	"p_num_plate_02",
	"p_num_plate_03",
	"p_num_plate_04",
	"p_oil_slick_01",
	"p_pharm_unit_01",
	"p_pharm_unit_02",
	"p_planning_board_01",
	"p_planning_board_02",
	"p_planning_board_03",
	"p_planning_board_04",
	"p_secret_weapon_02",
	"p_stinger_02",
	"p_stinger_03",
	"p_stinger_04",
	"p_stinger_piece_01",
	"p_stinger_piece_02",
	"p_watch_01",
	"p_watch_02",
	"p_watch_03",
	"p_watch_04",
	"p_watch_05",
	"p_watch_06",
	"prop_bomb_01_s",
	"prop_cs_bin_01_skinned",
	"prop_cs_bucket_s",
	"prop_cs_bucket_s_lod",
	"prop_cs_mop_s",
	"prop_f_duster_01_s",
	"prop_ld_case_01_s",
	"prop_ld_handbag_s",
	"prop_ld_wallet_01_s",
	"prop_news_disp_02a_s",
	"prop_off_chair_04_s",
	"prop_p_jack_03_col",
	"prop_rub_binbag_sd_01",
	"prop_rub_binbag_sd_02",
	"prop_v_m_phone_o1s",
	"p_abat_roller_1",
	"p_abat_roller_1_col",
	"p_amb_drain_water_double",
	"p_amb_drain_water_longstrip",
	"p_amb_drain_water_single",
	"p_attache_case_01_s",
	"p_balaclavamichael_s",
	"p_barierbase_test_s",
	"p_barier_test_s",
	"p_beefsplitter_s",
	"p_cargo_chute_s",
	"p_cigar_pack_02_s",
	"p_cs_locker_01_s",
	"p_cs_script_bottle_s",
	"p_dock_crane_cable_s",
	"p_dock_crane_cabl_s",
	"p_dock_crane_sld_s",
	"p_dumpster_t",
	"p_fag_packet_01_s",
	"p_ferris_wheel_amo_l",
	"p_ferris_wheel_amo_l2",
	"p_ferris_wheel_amo_p",
	"p_gar_door_01_s",
	"p_gar_door_02_s",
	"p_gar_door_03_s",
	"p_gdoor1colobject_s",
	"p_gdoor1_s",
	"p_ing_skiprope_01_s",
	"p_jewel_necklace01_s",
	"p_jewel_necklace02_s",
	"p_jewel_pickup33_s",
	"p_ld_coffee_vend_s",
	"p_ld_heist_bag_s",
	"p_ld_stinger_s",
	"p_litter_picker_s",
	"p_mast_01_s",
	"p_notepad_01_s",
	"p_oil_pjack_01_amo",
	"p_oil_pjack_01_frg_s",
	"p_oil_pjack_02_amo",
	"p_oil_pjack_02_frg_s",
	"p_oil_pjack_03_amo",
	"p_oil_pjack_03_frg_s",
	"p_pallet_02a_s",
	"p_panties_s",
	"p_parachute1_mp_s",
	"p_parachute1_s",
	"p_parachute1_sp_s",
	"p_parachute_fallen_s",
	"p_parachute_s",
	"p_parachute_s_shop",
	"p_para_broken1_s",
	"p_patio_lounger1_s",
	"p_phonebox_02_s",
	"p_pliers_01_s",
	"p_rcss_folded",
	"p_rcss_s",
	"p_ringbinder_01_s",
	"p_sec_gate_01_s",
	"p_sec_gate_01_s_col",
	"p_shoalfish_s",
	"p_skiprope_r_s",
	"p_sofa_s",
	"p_sub_crane_s",
	"p_sunglass_m_s",
	"p_tennis_bag_01_s",
	"p_tram_crash_s",
	"p_watch_01_s",
	"p_watch_02_s",
	"p_watch_03_s",
	"p_waterboardc_s",
	"p_yacht_chair_01_s",
	"p_yacht_sofa_01_s",
	"p_yoga_mat_01_s",
	"p_yoga_mat_02_s",
	"p_yoga_mat_03_s",
	"pop_v_bank_door_l",
	"pop_v_bank_door_r",
	"prop_abat_roller_static",
	"prop_abat_slide",
	"prop_artgallery_02_dl",
	"prop_artgallery_02_dr",
	"prop_artgallery_dl",
	"prop_artgallery_dr",
	"prop_barn_door_l",
	"prop_barn_door_r",
	"prop_bh1_03_gate_l",
	"prop_bh1_03_gate_r",
	"prop_bh1_08_mp_gar",
	"prop_bh1_09_mp_gar",
	"prop_bh1_09_mp_l",
	"prop_bh1_09_mp_r",
	"prop_bh1_44_door_01l",
	"prop_bh1_44_door_01r",
	"prop_bh1_48_backdoor_l",
	"prop_bh1_48_backdoor_r",
	"prop_bh1_48_gate_1",
	"prop_bhhotel_door_l",
	"prop_bhhotel_door_r",
	"prop_biolab_g_door",
	"prop_broken_cell_gate_01",
	"prop_bs_map_door_01",
	"prop_burto_gate_01",
	"prop_casino_door_01l",
	"prop_casino_door_01r",
	"prop_ch1_07_door_01l",
	"prop_ch1_07_door_01r",
	"prop_ch1_07_door_02l",
	"prop_ch1_07_door_02r",
	"prop_ch2_05d_g_door",
	"prop_ch2_07b_20_g_door",
	"prop_ch2_09b_door",
	"prop_ch2_09c_garage_door",
	"prop_ch3_01_trlrdoor_l",
	"prop_ch3_01_trlrdoor_r",
	"prop_ch3_04_door_01l",
	"prop_ch3_04_door_01r",
	"prop_ch3_04_door_02",
	"prop_ch_025c_g_door_01",
	"prop_com_gar_door_01",
	"prop_com_ls_door_01",
	"prop_control_rm_door_01",
	"prop_cs1_14b_traind",
	"prop_cs1_14b_traind_dam",
	"prop_cs4_05_tdoor",
	"prop_cs4_10_tr_gd_01",
	"prop_cs4_11_door",
	"prop_cs6_03_door_l",
	"prop_cs6_03_door_r",
	"prop_cs_freightdoor_l1",
	"prop_cs_freightdoor_r1",
	"prop_cs_gravyard_gate_l",
	"prop_cs_gravyard_gate_r",
	"prop_cs_sc1_11_gate",
	"prop_cs_sm_27_gate",
	"prop_damdoor_01",
	"prop_door_01",
	"prop_door_balcony_frame",
	"prop_door_balcony_left",
	"prop_door_balcony_right",
	"prop_dt1_20_mp_door_l",
	"prop_dt1_20_mp_door_r",
	"prop_dt1_20_mp_gar",
	"prop_d_balcony_l_light",
	"prop_d_balcony_r_light",
	"prop_epsilon_door_l",
	"prop_epsilon_door_r",
	"prop_faceoffice_door_l",
	"prop_faceoffice_door_r",
	"prop_gar_door_01",
	"prop_gar_door_02",
	"prop_gar_door_03",
	"prop_gar_door_03_ld",
	"prop_gar_door_04",
	"prop_gar_door_05",
	"prop_gar_door_05_l",
	"prop_gar_door_05_r",
	"prop_gar_door_a_01",
	"prop_gar_door_plug",
	"prop_gd_ch2_08",
	"prop_grumandoor_l",
	"prop_grumandoor_r",
	"prop_hanger_door_1",
	"prop_hospitaldoors_start",
	"prop_hospital_door_l",
	"prop_hospital_door_r",
	"prop_hw1_03_gardoor_01",
	"prop_hw1_04_door_l1",
	"prop_hw1_04_door_r1",
	"prop_hw1_23_door",
	"prop_id2_11_gdoor",
	"prop_id_21_gardoor_01",
	"prop_id_21_gardoor_02",
	"prop_indus_meet_door_l",
	"prop_indus_meet_door_r",
	"prop_kt1_06_door_l",
	"prop_kt1_06_door_r",
	"prop_kt1_10_mpdoor_l",
	"prop_kt1_10_mpdoor_r",
	"prop_ld_garaged_01",
	"prop_ld_jail_door",
	"prop_magenta_door",
	"prop_map_door_01",
	"prop_michael_door",
	"prop_motel_door_09",
	"prop_police_door_l",
	"prop_police_door_l_dam",
	"prop_police_door_r",
	"prop_police_door_r_dam",
	"prop_police_door_surround",
	"prop_pris_door_01_l",
	"prop_pris_door_01_r",
	"prop_pris_door_02",
	"prop_pris_door_03",
	"prop_ql_revolving_door",
	"prop_ret_door",
	"prop_ret_door_02",
	"prop_ret_door_03",
	"prop_ret_door_04",
	"prop_ron_door_01",
	"prop_sc1_06_gate_l",
	"prop_sc1_06_gate_r",
	"prop_sc1_12_door",
	"prop_sc1_21_g_door_01",
	"prop_section_garage_01",
	"prop_sec_gate_01b",
	"prop_sec_gate_01c",
	"prop_sec_gate_01d",
	"prop_showroom_door_l",
	"prop_showroom_door_r",
	"prop_sm1_11_doorl",
	"prop_sm1_11_doorr",
	"prop_sm1_11_garaged",
	"prop_sm_10_mp_door",
	"prop_sm_14_mp_gar",
	"prop_sm_27_door",
	"prop_sm_27_gate",
	"prop_sm_27_gate_02",
	"prop_sm_27_gate_03",
	"prop_sm_27_gate_04",
	"prop_ss1_05_mp_door",
	"prop_ss1_08_mp_door_l",
	"prop_ss1_08_mp_door_r",
	"prop_ss1_10_door_l",
	"prop_ss1_10_door_r",
	"prop_ss1_14_garage_door",
	"prop_ss1_mpint_door_l",
	"prop_ss1_mpint_door_r",
	"prop_ss1_mpint_garage",
	"prop_ss1_mpint_garage_cl",
	"prop_strip_door_01",
	"prop_vault_shutter",
	"prop_v_door_44",
	"prop_wardrobe_door_01",
	"prop_win_plug_01",
	"prop_win_plug_01_dam",
	"p_cut_door_01",
	"p_cut_door_02",
	"p_cut_door_03",
	"p_jewel_door_l",
	"p_jewel_door_r1",
	"prop_a4_pile_01",
	"prop_a4_sheet_01",
	"prop_a4_sheet_02",
	"prop_a4_sheet_03",
	"prop_a4_sheet_04",
	"prop_a4_sheet_05",
	"prop_aiprort_sign_01",
	"prop_aiprort_sign_02",
	"prop_amanda_note_01",
	"prop_amanda_note_01b",
	"prop_amb_40oz_02",
	"prop_amb_40oz_03",
	"prop_amb_beer_bottle",
	"prop_amb_ciggy_01",
	"prop_amb_donut",
	"prop_anim_cash_note",
	"prop_anim_cash_note_b",
	"prop_anim_cash_pile_01",
	"prop_anim_cash_pile_02",
	"prop_arc_blueprints_01",
	"prop_armour_pickup",
	"prop_artifact_01",
	"prop_ashtray_01",
	"prop_aviators_01",
	"prop_a_trailer_door_01",
	"prop_ballistic_shield",
	"prop_ballistic_shield_lod1",
	"prop_barry_table_detail",
	"prop_basejump_target_01",
	"prop_battery_01",
	"prop_battery_02",
	"prop_beer_box_01",
	"prop_beta_tape",
	"prop_big_shit_01",
	"prop_big_shit_02",
	"prop_binoc_01",
	"prop_bison_winch",
	"prop_blackjack_01",
	"prop_blox_spray",
	"prop_bodyarmour_02",
	"prop_bodyarmour_03",
	"prop_bodyarmour_04",
	"prop_bodyarmour_05",
	"prop_bodyarmour_06",
	"prop_bongos_01",
	"prop_bong_01",
	"prop_boombox_01",
	"prop_bottle_cap_01",
	"prop_bowl_crisps",
	"prop_broken_cboard_p1",
	"prop_broken_cboard_p2",
	"prop_busker_hat_01",
	"prop_c4_final",
	"prop_c4_final_green",
	"prop_candy_pqs",
	"prop_cargo_int",
	"prop_carrier_bag_01",
	"prop_carrier_bag_01_lod",
	"prop_carwash_roller_horz",
	"prop_carwash_roller_vert",
	"prop_car_ignition",
	"prop_casey_sec_id",
	"prop_cash_case_01",
	"prop_cash_case_02",
	"prop_cash_crate_01",
	"prop_cash_envelope_01",
	"prop_cash_note_01",
	"prop_cash_pile_01",
	"prop_cash_pile_02",
	"prop_ceramic_jug_01",
	"prop_ceramic_jug_cork",
	"prop_cigar_01",
	"prop_cigar_02",
	"prop_cigar_03",
	"prop_cigar_pack_01",
	"prop_cigar_pack_02",
	"prop_cliff_paper",
	"prop_clippers_01",
	"prop_coffee_cup_trailer",
	"prop_coffin_02",
	"prop_coffin_02b",
	"prop_coke_block_01",
	"prop_coke_block_half_a",
	"prop_coke_block_half_b",
	"prop_controller_01",
	"prop_crisp",
	"prop_crisp_small",
	"prop_cs_abattoir_switch",
	"prop_cs_amanda_shoe",
	"prop_cs_bandana",
	"prop_cs_bar",
	"prop_cs_beer_bot_01",
	"prop_cs_beer_bot_01b",
	"prop_cs_beer_bot_01lod",
	"prop_cs_beer_bot_02",
	"prop_cs_beer_bot_03",
	"prop_cs_beer_bot_40oz",
	"prop_cs_beer_bot_40oz_02",
	"prop_cs_beer_bot_40oz_03",
	"prop_cs_beer_bot_test",
	"prop_cs_binder_01",
	"prop_cs_book_01",
	"prop_cs_bottle_opener",
	"prop_cs_bowie_knife",
	"prop_cs_bowl_01",
	"prop_cs_bowl_01b",
	"prop_cs_box_step",
	"prop_cs_brain_chunk",
	"prop_cs_bs_cup",
	"prop_cs_burger_01",
	"prop_cs_business_card",
	"prop_cs_cash_note_01",
	"prop_cs_cctv",
	"prop_cs_champ_flute",
	"prop_cs_ciggy_01",
	"prop_cs_ciggy_01b",
	"prop_cs_clothes_box",
	"prop_cs_coke_line",
	"prop_cs_cont_latch",
	"prop_cs_crackpipe",
	"prop_cs_credit_card",
	"prop_cs_creeper_01",
	"prop_cs_crisps_01",
	"prop_cs_cuffs_01",
	"prop_cs_diaphram",
	"prop_cs_dildo_01",
	"prop_cs_documents_01",
	"prop_cs_dog_lead_2a",
	"prop_cs_dog_lead_2b",
	"prop_cs_dog_lead_2c",
	"prop_cs_dog_lead_3a",
	"prop_cs_dog_lead_3b",
	"prop_cs_dog_lead_a",
	"prop_cs_dog_lead_b",
	"prop_cs_dog_lead_c",
	"prop_cs_duffel_01",
	"prop_cs_duffel_01b",
	"prop_cs_dvd",
	"prop_cs_dvd_case",
	"prop_cs_envolope_01",
	"prop_cs_film_reel_01",
	"prop_cs_fork",
	"prop_cs_frank_photo",
	"prop_cs_fuel_hose",
	"prop_cs_fuel_nozle",
	"prop_cs_gascutter_1",
	"prop_cs_gascutter_2",
	"prop_cs_glass_scrap",
	"prop_cs_gunrack",
	"prop_cs_hand_radio",
	"prop_cs_heist_rope",
	"prop_cs_heist_rope_b",
	"prop_cs_hotdog_01",
	"prop_cs_hotdog_02",
	"prop_cs_ilev_blind_01",
	"prop_cs_ironing_board",
	"prop_cs_katana_01",
	"prop_cs_kettle_01",
	"prop_cs_lazlow_ponytail",
	"prop_cs_lazlow_shirt_01",
	"prop_cs_lazlow_shirt_01b",
	"prop_cs_leg_chain_01",
	"prop_cs_lester_crate",
	"prop_cs_lipstick",
	"prop_cs_magazine",
	"prop_cs_marker_01",
	"prop_cs_meth_pipe",
	"prop_cs_milk_01",
	"prop_cs_mini_tv",
	"prop_cs_mopbucket_01",
	"prop_cs_nail_file",
	"prop_cs_newspaper",
	"prop_cs_overalls_01",
	"prop_cs_padlock",
	"prop_cs_pamphlet_01",
	"prop_cs_paper_cup",
	"prop_cs_para_ropebit",
	"prop_cs_para_ropes",
	"prop_cs_pebble",
	"prop_cs_pebble_02",
	"prop_cs_petrol_can",
	"prop_cs_phone_01",
	"prop_cs_photoframe_01",
	"prop_cs_pills",
	"prop_cs_plane_int_01",
	"prop_cs_plate_01",
	"prop_cs_police_torch",
	"prop_cs_pour_tube",
	"prop_cs_power_cell",
	"prop_cs_power_cord",
	"prop_cs_protest_sign_01",
	"prop_cs_protest_sign_02",
	"prop_cs_protest_sign_02b",
	"prop_cs_protest_sign_03",
	"prop_cs_protest_sign_04a",
	"prop_cs_protest_sign_04b",
	"prop_cs_rage_statue_p1",
	"prop_cs_rage_statue_p2",
	"prop_cs_rolled_paper",
	"prop_cs_rub_box_01",
	"prop_cs_rub_box_02",
	"prop_cs_r_business_card",
	"prop_cs_sack_01",
	"prop_cs_saucer_01",
	"prop_cs_script_bottle",
	"prop_cs_script_bottle_01",
	"prop_cs_server_drive",
	"prop_cs_sheers",
	"prop_cs_shirt_01",
	"prop_cs_shot_glass",
	"prop_cs_silver_tray",
	"prop_cs_sink_filler",
	"prop_cs_sink_filler_02",
	"prop_cs_sink_filler_03",
	"prop_cs_sol_glasses",
	"prop_cs_steak",
	"prop_cs_stock_book",
	"prop_cs_street_binbag_01",
	"prop_cs_street_card_01",
	"prop_cs_street_card_02",
	"prop_cs_sub_hook_01",
	"prop_cs_sub_rope_01",
	"prop_cs_swipe_card",
	"prop_cs_toaster",
	"prop_cs_trolley_01",
	"prop_cs_trowel",
	"prop_cs_truck_ladder",
	"prop_cs_tshirt_ball_01",
	"prop_cs_t_shirt_pile",
	"prop_cs_valve",
	"prop_cs_vent_cover",
	"prop_cs_walkie_talkie",
	"prop_cs_whiskey_bottle",
	"prop_cs_whiskey_bot_stop",
	"prop_cs_wrench",
	"prop_devin_box_01",
	"prop_devin_rope_01",
	"prop_direct_chair_01",
	"prop_direct_chair_02",
	"prop_disp_razor_01",
	"prop_distantcar_day",
	"prop_distantcar_night",
	"prop_distantcar_truck",
	"prop_donut_01",
	"prop_donut_02",
	"prop_donut_02b",
	"prop_door_bell_01",
	"prop_double_grid_line",
	"prop_drug_package",
	"prop_drug_package_02",
	"prop_dummy_car",
	"prop_ear_defenders_01",
	"prop_ecg_01",
	"prop_ecg_01_cable_01",
	"prop_ecg_01_cable_02",
	"prop_ecola_can",
	"prop_employee_month_01",
	"prop_employee_month_02",
	"prop_energy_drink",
	"prop_face_rag_01",
	"prop_fag_packet_01",
	"prop_fbi3_coffee_table",
	"prop_fib_badge",
	"prop_fib_skylight_piece",
	"prop_fishing_rod_01",
	"prop_fishing_rod_02",
	"prop_fish_slice_01",
	"prop_flare_01",
	"prop_flare_01b",
	"prop_flatbed_strap",
	"prop_flight_box_01",
	"prop_flight_box_insert",
	"prop_flight_box_insert2",
	"prop_franklin_dl",
	"prop_f_b_insert_broken",
	"prop_gaffer_arm_bind",
	"prop_gaffer_arm_bind_cut",
	"prop_gaffer_leg_bind",
	"prop_gaffer_leg_bind_cut",
	"prop_gaffer_tape",
	"prop_gaffer_tape_strip",
	"prop_glasscutter_01",
	"prop_glass_suck_holder",
	"prop_gold_cont_01",
	"prop_gold_cont_01b",
	"prop_gold_trolly_strap_01",
	"prop_gun_case_01",
	"prop_gun_case_02",
	"prop_gun_frame",
	"prop_hand_toilet",
	"prop_hard_hat_01",
	"prop_headphones_01",
	"prop_headset_01",
	"prop_hockey_bag_01",
	"prop_holster_01",
	"prop_hose_nozzle",
	"prop_huf_rag_01",
	"prop_ice_cube_01",
	"prop_ice_cube_02",
	"prop_ice_cube_03",
	"prop_id2_20_clock",
	"prop_idol_01",
	"prop_idol_case",
	"prop_idol_case_02",
	"prop_ing_crowbar",
	"prop_inhaler_01",
	"prop_iron_01",
	"prop_jet_bloodsplat_01",
	"prop_juice_pool_01",
	"prop_ld_ammo_pack_01",
	"prop_ld_ammo_pack_02",
	"prop_ld_ammo_pack_03",
	"prop_ld_barrier_01",
	"prop_ld_bomb_01",
	"prop_ld_bomb_01_open",
	"prop_ld_bomb_anim",
	"prop_ld_can_01",
	"prop_ld_contact_card",
	"prop_ld_crocclips01",
	"prop_ld_crocclips02",
	"prop_ld_dummy_rope",
	"prop_ld_fags_01",
	"prop_ld_fags_02",
	"prop_ld_faucet",
	"prop_ld_ferris_wheel",
	"prop_ld_fireaxe",
	"prop_ld_flow_bottle",
	"prop_ld_gold_tooth",
	"prop_ld_hdd_01",
	"prop_ld_peep_slider",
	"prop_ld_rail_01",
	"prop_ld_rail_02",
	"prop_ld_rubble_01",
	"prop_ld_rubble_02",
	"prop_ld_rubble_03",
	"prop_ld_rubble_04",
	"prop_ld_scrap",
	"prop_ld_shovel",
	"prop_ld_shovel_dirt",
	"prop_ld_snack_01",
	"prop_ld_test_01",
	"prop_ld_tooth",
	"prop_ld_wallet_02",
	"prop_ld_wallet_pickup",
	"prop_lev_des_barge_01",
	"prop_lev_des_barge_02",
	"prop_lift_overlay_01",
	"prop_lift_overlay_02",
	"prop_litter_picker",
	"prop_loose_rag_01",
	"prop_med_jet_01",
	"prop_megaphone_01",
	"prop_mem_candle_04",
	"prop_mem_candle_05",
	"prop_mem_candle_06",
	"prop_mem_reef_01",
	"prop_mem_reef_02",
	"prop_mem_reef_03",
	"prop_mem_teddy_01",
	"prop_mem_teddy_02",
	"prop_meth_bag_01",
	"prop_michael_balaclava",
	"prop_michael_sec_id",
	"prop_microphone_02",
	"prop_military_pickup_01",
	"prop_mil_crate_01",
	"prop_mil_crate_02",
	"prop_minigun_01",
	"prop_money_bag_01",
	"prop_mp3_dock",
	"prop_mp_arrow_barrier_01",
	"prop_mp_barrier_01",
	"prop_mp_barrier_01b",
	"prop_mp_barrier_02",
	"prop_mp_barrier_02b",
	"prop_mp_base_marker",
	"prop_mp_boost_01",
	"prop_mp_cant_place_lrg",
	"prop_mp_cant_place_med",
	"prop_mp_cant_place_sm",
	"prop_mp_cone_01",
	"prop_mp_cone_02",
	"prop_mp_cone_03",
	"prop_mp_cone_04",
	"prop_mp_drug_package",
	"prop_mp_drug_pack_blue",
	"prop_mp_drug_pack_red",
	"prop_mp_icon_shad_lrg",
	"prop_mp_icon_shad_med",
	"prop_mp_icon_shad_sm",
	"prop_mp_max_out_lrg",
	"prop_mp_max_out_med",
	"prop_mp_max_out_sm",
	"prop_mp_num_0",
	"prop_mp_num_1",
	"prop_mp_num_2",
	"prop_mp_num_3",
	"prop_mp_num_4",
	"prop_mp_num_5",
	"prop_mp_num_6",
	"prop_mp_num_7",
	"prop_mp_num_8",
	"prop_mp_num_9",
	"prop_mp_placement",
	"prop_mp_placement_lrg",
	"prop_mp_placement_maxd",
	"prop_mp_placement_med",
	"prop_mp_placement_red",
	"prop_mp_placement_sm",
	"prop_mp_ramp_01",
	"prop_mp_ramp_02",
	"prop_mp_ramp_03",
	"prop_mp_repair",
	"prop_mp_repair_01",
	"prop_mp_respawn_02",
	"prop_mp_rocket_01",
	"prop_mp_spike_01",
	"prop_m_pack_int_01",
	"prop_nigel_bag_pickup",
	"prop_notepad_01",
	"prop_notepad_02",
	"prop_old_boot",
	"prop_orang_can_01",
	"prop_parking_wand_01",
	"prop_passport_01",
	"prop_peanut_bowl_01",
	"prop_pencil_01",
	"prop_piercing_gun",
	"prop_ping_pong",
	"prop_pistol_holster",
	"prop_plastic_cup_02",
	"prop_player_gasmask",
	"prop_pliers_01",
	"prop_police_radio_handset",
	"prop_police_radio_main",
	"prop_poster_tube_01",
	"prop_poster_tube_02",
	"prop_power_cell",
	"prop_power_cord_01",
	"prop_premier_fence_01",
	"prop_premier_fence_02",
	"prop_quad_grid_line",
	"prop_rad_waste_barrel_01",
	"prop_rail_controller",
	"prop_range_target_01",
	"prop_range_target_02",
	"prop_range_target_03",
	"prop_riot_shield",
	"prop_rolled_sock_01",
	"prop_rolled_sock_02",
	"prop_rope_family_3",
	"prop_safety_glasses",
	"prop_sam_01",
	"prop_sandwich_01",
	"prop_scaffold_pole",
	"prop_scn_police_torch",
	"prop_scourer_01",
	"prop_scrap_2_crate",
	"prop_sewing_fabric",
	"prop_sewing_machine",
	"prop_shower_towel",
	"prop_sh_beer_pissh_01",
	"prop_sh_bong_01",
	"prop_sh_cigar_01",
	"prop_sh_joint_01",
	"prop_sh_mr_rasp_01",
	"prop_sh_shot_glass",
	"prop_sh_tall_glass",
	"prop_sh_tt_fridgedoor",
	"prop_sh_wine_glass",
	"prop_single_grid_line",
	"prop_smg_holster_01",
	"prop_space_pistol",
	"prop_space_rifle",
	"prop_spycam",
	"prop_squeegee",
	"prop_stag_do_rope",
	"prop_start_finish_line_01",
	"prop_start_grid_01",
	"prop_stockade_wheel",
	"prop_stockade_wheel_flat",
	"prop_sub_cover_01",
	"prop_sub_release",
	"prop_syringe_01",
	"prop_table_mic_01",
	"prop_table_ten_bat",
	"prop_taco_01",
	"prop_taco_02",
	"prop_tapeplayer_01",
	"prop_target_arm",
	"prop_target_arm_b",
	"prop_target_arm_long",
	"prop_target_arm_sm",
	"prop_target_backboard",
	"prop_target_backboard_b",
	"prop_target_blue",
	"prop_target_blue_arrow",
	"prop_target_bull",
	"prop_target_bull_b",
	"prop_target_comp_metal",
	"prop_target_comp_wood",
	"prop_target_frame_01",
	"prop_target_inner1",
	"prop_target_inner2",
	"prop_target_inner2_b",
	"prop_target_inner3",
	"prop_target_inner3_b",
	"prop_target_inner_b",
	"prop_target_orange_arrow",
	"prop_target_oran_cross",
	"prop_target_ora_purp_01",
	"prop_target_purp_arrow",
	"prop_target_purp_cross",
	"prop_target_red",
	"prop_target_red_arrow",
	"prop_target_red_blue_01",
	"prop_target_red_cross",
	"prop_tarp_strap",
	"prop_tea_trolly",
	"prop_temp_block_blocker",
	"prop_tennis_ball",
	"prop_tennis_rack_01",
	"prop_tennis_rack_01b",
	"prop_time_capsule_01",
	"prop_tornado_wheel",
	"prop_torture_01",
	"prop_tourist_map_01",
	"prop_trailer_01_new",
	"prop_trailer_door_closed",
	"prop_trailer_door_open",
	"prop_trevor_rope_01",
	"prop_trev_sec_id",
	"prop_triple_grid_line",
	"prop_tri_finish_banner",
	"prop_tri_start_banner",
	"prop_tumbler_01",
	"prop_tumbler_01b",
	"prop_tumbler_01_empty",
	"prop_turkey_leg_01",
	"prop_tv_cam_02",
	"prop_tv_test",
	"prop_t_shirt_ironing",
	"prop_voltmeter_01",
	"prop_water_corpse_01",
	"prop_water_corpse_02",
	"prop_weed_01",
	"prop_weed_02",
	"prop_weed_block_01",
	"prop_weed_bottle",
	"prop_weed_pallet",
	"prop_weed_tub_01",
	"prop_weed_tub_01b",
	"prop_welding_mask_01",
	"prop_weld_torch",
	"prop_wheat_grass_empty",
	"prop_wheat_grass_glass",
	"prop_winch_hook_long",
	"prop_winch_hook_short",
	"prop_wrecked_buzzard",
	"prop_yacht_lounger",
	"prop_yacht_seat_01",
	"prop_yacht_seat_02",
	"prop_yacht_seat_03",
	"prop_yacht_table_01",
	"prop_yacht_table_02",
	"prop_yacht_table_03",
	"prop_yell_plastic_target",
	"p_amb_bagel_01",
	"p_cs_bbbat_01",
	"p_cs_bottle_01",
	"p_cs_clipboard",
	"p_cs_joint_01",
	"p_cs_joint_02",
	"p_cs_lighter_01",
	"p_cs_papers_01",
	"p_cs_papers_02",
	"p_cs_papers_03",
	"p_ing_bagel_01",
	"p_ing_microphonel_01",
	"p_ld_bs_bag_01",
	"p_ld_id_card_002",
	"p_ld_id_card_01",
	"p_rc_handset",
	"p_whiskey_notop",
	"p_whiskey_notop_empty",
	"prop_crashed_heli",
	"prop_ld_bankdoors_02",
	"prop_ld_fragwall_01a",
	"prop_pipe_single_01",
	"prop_test_boulder_01",
	"prop_test_boulder_02",
	"prop_test_boulder_03",
	"prop_test_boulder_04",
	"prop_trailr_base",
	"prop_trailr_base_static",
	"proc_drkyel001",
	"proc_flower1",
	"proc_flower_wild_04",
	"proc_weeds01a",
	"proc_weeds01b",
	"proc_weeds01c",
	"prop_test_bed",
	"proair_hoc_puck",
	"prop_airhockey_01",
	"prop_air_hoc_paddle_01",
	"prop_air_hoc_paddle_02",
	"prop_arcade_01",
	"prop_arcade_02",
	"prop_ice_box_01",
	"prop_ice_box_01_l1",
	"prop_jukebox_01",
	"prop_jukebox_02",
	"prop_park_ticket_01",
	"prop_pier_kiosk_01",
	"prop_pier_kiosk_02",
	"prop_pier_kiosk_03",
	"prop_pooltable_02",
	"prop_pooltable_3b",
	"prop_pool_cue",
	"prop_pool_rack_01",
	"prop_pool_rack_02",
	"prop_pool_tri",
	"prop_telescope",
	"prop_train_ticket_02",
	"prop_turnstyle_01",
	"prop_vend_coffe_01",
	"prop_vend_condom_01",
	"prop_vend_fags_01",
	"prop_vend_fridge01",
	"prop_vend_snak_01",
	"prop_apple_box_01",
	"prop_apple_box_02",
	"prop_arm_wrestle_01",
	"prop_a_base_bars_01",
	"prop_barbell_01",
	"prop_barbell_02",
	"prop_barbell_100kg",
	"prop_barbell_10kg",
	"prop_barbell_20kg",
	"prop_barbell_30kg",
	"prop_barbell_40kg",
	"prop_barbell_50kg",
	"prop_barbell_60kg",
	"prop_barbell_80kg",
	"prop_basketball_net",
	"prop_bball_arcade_01",
	"prop_beachbag_01",
	"prop_beachbag_02",
	"prop_beachbag_03",
	"prop_beachbag_04",
	"prop_beachbag_05",
	"prop_beachbag_06",
	"prop_beachbag_combo_01",
	"prop_beachbag_combo_02",
	"prop_beachball_02",
	"prop_beachflag_le",
	"prop_beach_bars_01",
	"prop_beach_bars_02",
	"prop_beach_bbq",
	"prop_beach_dip_bars_01",
	"prop_beach_dip_bars_02",
	"prop_beach_fire",
	"prop_beach_lg_float",
	"prop_beach_lg_stretch",
	"prop_beach_lg_surf",
	"prop_beach_lotion_01",
	"prop_beach_lotion_02",
	"prop_beach_lotion_03",
	"prop_beach_punchbag",
	"prop_beach_rings_01",
	"prop_beach_sculp_01",
	"prop_beach_towel_02",
	"prop_beach_volball01",
	"prop_beach_volball02",
	"prop_bikini_disp_01",
	"prop_bikini_disp_02",
	"prop_bikini_disp_03",
	"prop_bikini_disp_04",
	"prop_bikini_disp_05",
	"prop_bikini_disp_06",
	"prop_bleachers_01",
	"prop_bleachers_02",
	"prop_bleachers_03",
	"prop_bleachers_04",
	"prop_bleachers_05",
	"prop_boogbd_stack_01",
	"prop_boogbd_stack_02",
	"prop_boogieboard_01",
	"prop_boogieboard_02",
	"prop_boogieboard_03",
	"prop_boogieboard_04",
	"prop_boogieboard_05",
	"prop_boogieboard_06",
	"prop_boogieboard_07",
	"prop_boogieboard_08",
	"prop_boogieboard_09",
	"prop_boogieboard_10",
	"prop_bowling_ball",
	"prop_bowling_pin",
	"prop_boxing_glove_01",
	"prop_buck_spade_01",
	"prop_buck_spade_02",
	"prop_buck_spade_03",
	"prop_buck_spade_04",
	"prop_buck_spade_05",
	"prop_buck_spade_06",
	"prop_buck_spade_07",
	"prop_buck_spade_08",
	"prop_buck_spade_09",
	"prop_buck_spade_10",
	"prop_bumper_car_01",
	"prop_can_canoe",
	"prop_cap_01",
	"prop_cap_01b",
	"prop_cap_row_01",
	"prop_cap_row_01b",
	"prop_cap_row_02",
	"prop_cap_row_02b",
	"prop_clothes_rail_02",
	"prop_clothes_rail_03",
	"prop_clothes_rail_2b",
	"prop_clothes_tub_01",
	"prop_cs_beachtowel_01",
	"prop_cup_saucer_01",
	"prop_curl_bar_01",
	"prop_dart_1",
	"prop_dart_2",
	"prop_dart_bd_01",
	"prop_dart_bd_cab_01",
	"prop_display_unit_01",
	"prop_display_unit_02",
	"prop_disp_cabinet_002",
	"prop_disp_cabinet_01",
	"prop_dolly_01",
	"prop_dolly_02",
	"prop_dress_disp_01",
	"prop_dress_disp_02",
	"prop_dress_disp_03",
	"prop_dress_disp_04",
	"prop_drug_burner",
	"prop_exer_bike_01",
	"prop_ferris_car_01",
	"prop_ferris_car_01_lod1",
	"prop_film_cam_01",
	"prop_flipchair_01",
	"prop_food_van_01",
	"prop_food_van_02",
	"prop_freeweight_01",
	"prop_freeweight_02",
	"prop_front_seat_01",
	"prop_front_seat_02",
	"prop_front_seat_03",
	"prop_front_seat_04",
	"prop_front_seat_05",
	"prop_front_seat_06",
	"prop_front_seat_07",
	"prop_front_seat_row_01",
	"prop_ftowel_01",
	"prop_ftowel_07",
	"prop_ftowel_08",
	"prop_ftowel_10",
	"prop_game_clock_01",
	"prop_game_clock_02",
	"prop_golf_bag_01",
	"prop_golf_bag_01b",
	"prop_golf_bag_01c",
	"prop_golf_ball",
	"prop_golf_ball_p2",
	"prop_golf_ball_p3",
	"prop_golf_ball_p4",
	"prop_golf_ball_tee",
	"prop_golf_driver",
	"prop_golf_iron_01",
	"prop_golf_marker_01",
	"prop_golf_pitcher_01",
	"prop_golf_putter_01",
	"prop_golf_tee",
	"prop_golf_wood_01",
	"prop_hat_box_01",
	"prop_hat_box_02",
	"prop_hat_box_03",
	"prop_hat_box_04",
	"prop_hat_box_05",
	"prop_hat_box_06",
	"prop_henna_disp_01",
	"prop_henna_disp_02",
	"prop_henna_disp_03",
	"prop_hwbowl_pseat_6x1",
	"prop_hwbowl_seat_01",
	"prop_hwbowl_seat_02",
	"prop_hwbowl_seat_03",
	"prop_hwbowl_seat_03b",
	"prop_hwbowl_seat_6x6",
	"prop_hydro_platform_01",
	"prop_inflatearch_01",
	"prop_inflategate_01",
	"prop_jeans_01",
	"prop_kayak_01",
	"prop_kayak_01b",
	"prop_kino_light_01",
	"prop_kino_light_03",
	"prop_ld_hat_01",
	"prop_ld_jeans_01",
	"prop_ld_jeans_02",
	"prop_ld_shirt_01",
	"prop_ld_shoe_01",
	"prop_ld_shoe_02",
	"prop_ld_tshirt_01",
	"prop_ld_tshirt_02",
	"prop_life_ring_02",
	"prop_makeup_trail_01",
	"prop_makeup_trail_02",
	"prop_mat_box",
	"prop_movie_rack",
	"prop_muscle_bench_01",
	"prop_muscle_bench_02",
	"prop_muscle_bench_03",
	"prop_muscle_bench_04",
	"prop_muscle_bench_05",
	"prop_muscle_bench_06",
	"prop_offroad_bale01",
	"prop_offroad_bale02_l1_frag_",
	"prop_offroad_barrel01",
	"prop_offroad_tyres01",
	"prop_plate_stand_01",
	"prop_poolball_1",
	"prop_poolball_10",
	"prop_poolball_11",
	"prop_poolball_12",
	"prop_poolball_13",
	"prop_poolball_14",
	"prop_poolball_15",
	"prop_poolball_2",
	"prop_poolball_3",
	"prop_poolball_4",
	"prop_poolball_5",
	"prop_poolball_6",
	"prop_poolball_7",
	"prop_poolball_8",
	"prop_poolball_9",
	"prop_poolball_cue",
	"prop_porn_mag_01",
	"prop_porn_mag_02",
	"prop_porn_mag_03",
	"prop_porn_mag_04",
	"prop_postcard_rack",
	"prop_pris_bars_01",
	"prop_pris_bench_01",
	"prop_prop_tree_01",
	"prop_prop_tree_02",
	"prop_punch_bag_l",
	"prop_roller_car_01",
	"prop_roller_car_02",
	"prop_scrim_01",
	"prop_set_generator_01",
	"prop_sglasses_stand_01",
	"prop_sglasses_stand_02",
	"prop_sglasses_stand_02b",
	"prop_sglasses_stand_03",
	"prop_sglasss_1b_lod",
	"prop_sglasss_1_lod",
	"prop_shop_front_door_l",
	"prop_shop_front_door_r",
	"prop_skate_flatramp",
	"prop_skate_funbox",
	"prop_skate_halfpipe",
	"prop_skate_kickers",
	"prop_skate_quartpipe",
	"prop_skate_rail",
	"prop_skate_spiner",
	"prop_skip_rope_01",
	"prop_slacks_01",
	"prop_slacks_02",
	"prop_speedball_01",
	"prop_sports_clock_01",
	"prop_studio_light_02",
	"prop_studio_light_03",
	"prop_suitcase_01",
	"prop_suitcase_01b",
	"prop_suitcase_01c",
	"prop_suitcase_01d",
	"prop_suitcase_02",
	"prop_suitcase_03",
	"prop_suitcase_03b",
	"prop_surf_board_ldn_01",
	"prop_surf_board_ldn_02",
	"prop_surf_board_ldn_03",
	"prop_surf_board_ldn_04",
	"prop_table_tennis",
	"prop_tennis_ball_lobber",
	"prop_tint_towel",
	"prop_tint_towels_01",
	"prop_tint_towels_01b",
	"prop_towel2_01",
	"prop_towel2_02",
	"prop_towel_shelf_01",
	"prop_tri_pod",
	"prop_tri_pod_lod",
	"prop_tshirt_box_02",
	"prop_tshirt_shelf_1",
	"prop_tshirt_shelf_2",
	"prop_tshirt_shelf_2a",
	"prop_tshirt_shelf_2b",
	"prop_tshirt_shelf_2c",
	"prop_tshirt_stand_01",
	"prop_tshirt_stand_01b",
	"prop_tshirt_stand_02",
	"prop_tshirt_stand_04",
	"prop_t_shirt_row_01",
	"prop_t_shirt_row_02",
	"prop_t_shirt_row_02b",
	"prop_t_shirt_row_03",
	"prop_t_shirt_row_04",
	"prop_t_shirt_row_05l",
	"prop_t_shirt_row_05r",
	"prop_venice_board_01",
	"prop_venice_board_02",
	"prop_venice_board_03",
	"prop_venice_counter_01",
	"prop_venice_counter_02",
	"prop_venice_counter_03",
	"prop_venice_counter_04",
	"prop_venice_shop_front_01",
	"prop_venice_sign_09",
	"prop_venice_sign_10",
	"prop_venice_sign_11",
	"prop_venice_sign_12",
	"prop_venice_sign_14",
	"prop_venice_sign_15",
	"prop_venice_sign_16",
	"prop_venice_sign_17",
	"prop_venice_sign_18",
	"prop_ven_market_stool",
	"prop_ven_market_table1",
	"prop_ven_shop_1_counter",
	"prop_v_15_cars_clock",
	"prop_v_5_bclock",
	"prop_weight_10k",
	"prop_weight_15k",
	"prop_weight_1_5k",
	"prop_weight_20k",
	"prop_weight_2_5k",
	"prop_weight_5k",
	"prop_weight_rack_01",
	"prop_weight_rack_02",
	"p_film_set_static_01",
	"prop_bath_dirt_01",
	"prop_broom_unit_01",
	"prop_handdry_01",
	"prop_handdry_02",
	"prop_shower_01",
	"prop_shower_rack_01",
	"prop_sink_01",
	"prop_sink_02",
	"prop_sink_03",
	"prop_sink_04",
	"prop_sink_05",
	"prop_sink_06",
	"prop_soap_disp_01",
	"prop_soap_disp_02",
	"prop_sponge_01",
	"prop_toilet_01",
	"prop_toilet_02",
	"prop_toilet_03",
	"prop_toilet_brush_01",
	"prop_toilet_cube_01",
	"prop_toilet_cube_02",
	"prop_toilet_roll_01",
	"prop_toilet_roll_02",
	"prop_toilet_roll_03",
	"prop_toilet_roll_04",
	"prop_toilet_roll_05",
	"prop_toilet_shamp_01",
	"prop_toilet_shamp_02",
	"prop_toilet_soap_01",
	"prop_toilet_soap_02",
	"prop_toilet_soap_03",
	"prop_toilet_soap_04",
	"prop_toothbrush_01",
	"prop_toothb_cup_01",
	"prop_toothpaste_01",
	"prop_towel_01",
	"prop_towel_rail_01",
	"prop_towel_rail_02",
	"prop_towel_small_01",
	"prop_w_fountain_01",
	"prop_amp_01",
	"prop_cctv_02_sm",
	"prop_cctv_cont_01",
	"prop_cctv_cont_03",
	"prop_cctv_cont_04",
	"prop_cctv_cont_05",
	"prop_cctv_cont_06",
	"prop_cctv_unit_01",
	"prop_cctv_unit_02",
	"prop_cctv_unit_05",
	"prop_console_01",
	"prop_cs_dvd_player",
	"prop_cs_keyboard_01",
	"prop_cs_mouse_01",
	"prop_cs_tv_stand",
	"prop_dj_deck_01",
	"prop_dj_deck_02",
	"prop_flatscreen_overlay",
	"prop_ghettoblast_02",
	"prop_hifi_01",
	"prop_keyboard_01a",
	"prop_keyboard_01b",
	"prop_laptop_02_closed",
	"prop_laptop_jimmy",
	"prop_laptop_lester",
	"prop_laptop_lester2",
	"prop_michaels_credit_tv",
	"prop_monitor_01c",
	"prop_monitor_01d",
	"prop_monitor_02",
	"prop_monitor_03b",
	"prop_mouse_01",
	"prop_mouse_01a",
	"prop_mouse_01b",
	"prop_mouse_02",
	"prop_pc_01a",
	"prop_pc_02a",
	"prop_portable_hifi_01",
	"prop_projector_overlay",
	"prop_speaker_01",
	"prop_speaker_02",
	"prop_speaker_03",
	"prop_speaker_05",
	"prop_speaker_06",
	"prop_speaker_07",
	"prop_speaker_08",
	"prop_till_01_dam",
	"prop_till_02",
	"prop_till_03",
	"prop_trailer_monitor_01",
	"prop_trev_tv_01",
	"prop_tt_screenstatic",
	"prop_tv_02",
	"prop_tv_03_overlay",
	"prop_tv_04",
	"prop_tv_05",
	"prop_tv_06",
	"prop_tv_07",
	"prop_tv_cabinet_03",
	"prop_tv_cabinet_04",
	"prop_tv_cabinet_05",
	"prop_tv_flat_01",
	"prop_tv_flat_01_screen",
	"prop_tv_flat_02b",
	"prop_tv_flat_03",
	"prop_tv_flat_03b",
	"prop_tv_flat_michael",
	"prop_vcr_01",
	"prop_white_keyboard",
	"prop_bbq_2",
	"prop_bbq_3",
	"prop_beware_dog_sign",
	"prop_forsalejr2",
	"prop_forsalejr3",
	"prop_forsalejr4",
	"prop_fountain1",
	"prop_fountain2",
	"prop_garden_dreamcatch_01",
	"prop_garden_edging_01",
	"prop_garden_edging_02",
	"prop_garden_zapper_01",
	"prop_gardnght_01",
	"prop_gazebo_03",
	"prop_glf_roller",
	"prop_glf_spreader",
	"prop_gravestones_01a",
	"prop_gravestones_02a",
	"prop_gravestones_03a",
	"prop_gravestones_04a",
	"prop_gravestones_05a",
	"prop_gravestones_06a",
	"prop_gravestones_07a",
	"prop_gravestones_08a",
	"prop_gravestones_09a",
	"prop_gravestones_10a",
	"prop_gravetomb_01a",
	"prop_gravetomb_02a",
	"prop_hedge_trimmer_01",
	"prop_hose_1",
	"prop_hose_2",
	"prop_hose_3",
	"prop_hottub2",
	"prop_lawnmower_01",
	"prop_leaf_blower_01",
	"prop_letterbox_04",
	"prop_outdoor_fan_01",
	"prop_owl_totem_01",
	"prop_poolskimmer",
	"prop_prlg_gravestone_05a_l1",
	"prop_prlg_gravestone_06a",
	"prop_shrub_rake",
	"prop_sign_mallet",
	"prop_spray_backpack_01",
	"prop_sprink_crop_01",
	"prop_sprink_golf_01",
	"prop_sprink_park_01",
	"prop_stickbfly",
	"prop_stickhbird",
	"prop_wateringcan",
	"prop_windmill2",
	"test_prop_gravestones_04a",
	"test_prop_gravestones_05a",
	"test_prop_gravestones_07a",
	"test_prop_gravestones_08a",
	"test_prop_gravestones_09a",
	"test_prop_gravetomb_01a",
	"test_prop_gravetomb_02a",
	"prop_breadbin_01",
	"prop_cleaver",
	"prop_cooker_03",
	"prop_copper_pan",
	"prop_fridge_01",
	"prop_fridge_03",
	"prop_ind_washer_02",
	"prop_kettle",
	"prop_kettle_01",
	"prop_kitch_juicer",
	"prop_kitch_pot_fry",
	"prop_kitch_pot_huge",
	"prop_kitch_pot_lrg",
	"prop_kitch_pot_lrg2",
	"prop_kitch_pot_med",
	"prop_kitch_pot_sm",
	"prop_knife",
	"prop_knife_stand",
	"prop_ladel",
	"prop_metalfoodjar_01",
	"prop_micro_01",
	"prop_micro_02",
	"prop_micro_cs_01",
	"prop_micro_cs_01_door",
	"prop_plate_04",
	"prop_plate_warmer",
	"prop_pot_01",
	"prop_pot_02",
	"prop_pot_03",
	"prop_pot_04",
	"prop_pot_05",
	"prop_pot_06",
	"prop_pot_rack",
	"prop_steam_basket_01",
	"prop_steam_basket_02",
	"prop_tea_urn",
	"prop_toaster_01",
	"prop_toaster_02",
	"prop_utensil",
	"prop_washer_01",
	"prop_washer_02",
	"prop_washer_03",
	"prop_washing_basket_01",
	"prop_whisk",
	"prop_wok",
	"prop_armchair_01",
	"prop_couch_01",
	"prop_couch_03",
	"prop_couch_04",
	"prop_couch_lg_02",
	"prop_couch_lg_05",
	"prop_couch_lg_06",
	"prop_couch_lg_07",
	"prop_couch_lg_08",
	"prop_couch_sm1_07",
	"prop_couch_sm2_07",
	"prop_couch_sm_02",
	"prop_couch_sm_05",
	"prop_couch_sm_06",
	"prop_couch_sm_07",
	"prop_yaught_chair_01",
	"prop_yaught_sofa_01",
	"prop_bin_04a",
	"prop_bin_10a",
	"prop_bin_10b",
	"prop_bin_11a",
	"prop_bin_11b",
	"prop_bin_12a",
	"prop_bin_13a",
	"prop_bin_14a",
	"prop_bin_14b",
	"prop_bin_beach_01d",
	"prop_bin_delpiero",
	"prop_bin_delpiero_b",
	"prop_dumpster_3a",
	"prop_dumpster_3step",
	"prop_dumpster_4a",
	"prop_dumpster_4b",
	"prop_recyclebin_02a",
	"prop_recyclebin_02b",
	"prop_recyclebin_02_c",
	"prop_recyclebin_02_d",
	"prop_recyclebin_03_a",
	"prop_recyclebin_04_a",
	"prop_recyclebin_04_b",
	"prop_recyclebin_05_a",
	"prop_skip_01a",
	"prop_skip_02a",
	"prop_skip_03",
	"prop_skip_04",
	"prop_skip_05a",
	"prop_skip_05b",
	"prop_skip_06a",
	"prop_skip_08a",
	"prop_skip_08b",
	"prop_skip_10a",
	"prop_bandsaw_01",
	"prop_barier_conc_01b",
	"prop_barier_conc_01c",
	"prop_barier_conc_02b",
	"prop_barier_conc_02c",
	"prop_barier_conc_03a",
	"prop_barier_conc_04a",
	"prop_barier_conc_05a",
	"prop_barier_conc_05b",
	"prop_barriercrash_03",
	"prop_barriercrash_04",
	"prop_barrier_wat_01a",
	"prop_barrier_wat_03b",
	"prop_barrier_work01c",
	"prop_cablespool_01a",
	"prop_cablespool_01b",
	"prop_cablespool_02",
	"prop_cablespool_03",
	"prop_cablespool_04",
	"prop_cablespool_05",
	"prop_cablespool_06",
	"prop_cementmixer_01a",
	"prop_cementmixer_02a",
	"prop_conc_sacks_02a",
	"prop_conschute",
	"prop_consign_01c",
	"prop_consign_02a",
	"prop_conslift_base",
	"prop_conslift_brace",
	"prop_conslift_cage",
	"prop_conslift_door",
	"prop_conslift_lift",
	"prop_conslift_rail",
	"prop_conslift_rail2",
	"prop_conslift_steps",
	"prop_cons_crate",
	"prop_cons_plank",
	"prop_cons_ply01",
	"prop_cons_ply02",
	"prop_crosssaw_01",
	"prop_diggerbkt_01",
	"prop_drywallpile_01",
	"prop_drywallpile_02",
	"prop_ducktape_01",
	"prop_etricmotor_01",
	"prop_generator_02a",
	"prop_generator_03a",
	"prop_generator_04",
	"prop_girder_01a",
	"prop_logpile_05",
	"prop_logpile_06",
	"prop_logpile_06b",
	"prop_logpile_07",
	"prop_logpile_07b",
	"prop_log_01",
	"prop_log_02",
	"prop_log_03",
	"prop_medstation_02",
	"prop_medstation_03",
	"prop_medstation_04",
	"prop_metal_plates01",
	"prop_metal_plates02",
	"prop_oiltub_01",
	"prop_oiltub_02",
	"prop_oiltub_03",
	"prop_oiltub_05",
	"prop_oiltub_06",
	"prop_paints_can01",
	"prop_paints_can02",
	"prop_paints_can03",
	"prop_paints_can04",
	"prop_paints_can05",
	"prop_paints_can06",
	"prop_paints_can07",
	"prop_paint_brush01",
	"prop_paint_brush02",
	"prop_paint_brush03",
	"prop_paint_brush04",
	"prop_paint_brush05",
	"prop_paint_roller",
	"prop_paint_spray01a",
	"prop_paint_spray01b",
	"prop_paint_stepl01",
	"prop_paint_stepl01b",
	"prop_paint_stepl02",
	"prop_paint_tray",
	"prop_paint_wpaper01",
	"prop_partsbox_01",
	"prop_pile_dirt_01",
	"prop_pile_dirt_02",
	"prop_pile_dirt_03",
	"prop_pile_dirt_04",
	"prop_pile_dirt_06",
	"prop_pile_dirt_07",
	"prop_pipes_01a",
	"prop_pipes_01b",
	"prop_pipes_03b",
	"prop_pipes_04a",
	"prop_pipes_05a",
	"prop_pipes_conc_01",
	"prop_pipes_conc_02",
	"prop_planer_01",
	"prop_plas_barier_01a",
	"prop_plywoodpile_01a",
	"prop_plywoodpile_01b",
	"prop_rebar_pile01",
	"prop_roadcone01a",
	"prop_roadcone01b",
	"prop_roadcone01c",
	"prop_roadcone02a",
	"prop_roadcone02b",
	"prop_roadcone02c",
	"prop_roadheader_01",
	"prop_scafold_01a",
	"prop_scafold_01c",
	"prop_scafold_01f",
	"prop_scafold_02a",
	"prop_scafold_02c",
	"prop_scafold_03a",
	"prop_scafold_03b",
	"prop_scafold_03c",
	"prop_scafold_03f",
	"prop_scafold_04a",
	"prop_scafold_05a",
	"prop_scafold_06a",
	"prop_scafold_06b",
	"prop_scafold_06c",
	"prop_scafold_07a",
	"prop_scafold_08a",
	"prop_scafold_09a",
	"prop_scafold_frame1a",
	"prop_scafold_frame1b",
	"prop_scafold_frame1c",
	"prop_scafold_frame1f",
	"prop_scafold_frame2a",
	"prop_scafold_frame2b",
	"prop_scafold_frame2c",
	"prop_scafold_frame3a",
	"prop_scafold_frame3c",
	"prop_scafold_rail_01",
	"prop_scafold_rail_02",
	"prop_scafold_rail_03",
	"prop_scafold_xbrace",
	"prop_shuttering01",
	"prop_shuttering02",
	"prop_shuttering03",
	"prop_shuttering04",
	"prop_spraygun_01",
	"prop_staticmixer_01",
	"prop_steps_big_01",
	"prop_tablesaw_01",
	"prop_tool_adjspanner",
	"prop_tool_bench01",
	"prop_tool_bluepnt",
	"prop_tool_box_01",
	"prop_tool_box_02",
	"prop_tool_box_03",
	"prop_tool_box_04",
	"prop_tool_box_05",
	"prop_tool_box_06",
	"prop_tool_box_07",
	"prop_tool_broom",
	"prop_tool_broom2",
	"prop_tool_broom2_l1",
	"prop_tool_cable01",
	"prop_tool_cable02",
	"prop_tool_consaw",
	"prop_tool_drill",
	"prop_tool_fireaxe",
	"prop_tool_hammer",
	"prop_tool_hardhat",
	"prop_tool_jackham",
	"prop_tool_mallet",
	"prop_tool_mopbucket",
	"prop_tool_nailgun",
	"prop_tool_pickaxe",
	"prop_tool_pliers",
	"prop_tool_rake",
	"prop_tool_rake_l1",
	"prop_tool_sawhorse",
	"prop_tool_screwdvr01",
	"prop_tool_screwdvr02",
	"prop_tool_screwdvr03",
	"prop_tool_shovel",
	"prop_tool_shovel006",
	"prop_tool_shovel2",
	"prop_tool_shovel3",
	"prop_tool_shovel4",
	"prop_tool_shovel5",
	"prop_tool_sledgeham",
	"prop_tool_spanner01",
	"prop_tool_spanner02",
	"prop_tool_spanner03",
	"prop_tool_torch",
	"prop_tool_wrench",
	"prop_towercrane_01a",
	"prop_towercrane_02a",
	"prop_towercrane_02b",
	"prop_towercrane_02c",
	"prop_towercrane_02d",
	"prop_towercrane_02e",
	"prop_towercrane_02el",
	"prop_towercrane_02el2",
	"prop_tunnel_liner01",
	"prop_tunnel_liner02",
	"prop_tunnel_liner03",
	"prop_vertdrill_01",
	"prop_wheelbarrow01a",
	"prop_wheelbarrow02a",
	"prop_woodpile_02a",
	"prop_worklight_01a_l1",
	"prop_worklight_03a_l1",
	"prop_worklight_03b_l1",
	"prop_worklight_04a",
	"prop_worklight_04b_l1",
	"prop_worklight_04c_l1",
	"prop_worklight_04d_l1",
	"prop_workwall_01",
	"prop_workwall_02",
	"prop_armenian_gate",
	"prop_arm_gate_l",
	"prop_const_fence01a",
	"prop_const_fence01b",
	"prop_const_fence02a",
	"prop_const_fence02b",
	"prop_const_fence03b",
	"prop_facgate_01",
	"prop_facgate_01b",
	"prop_facgate_02pole",
	"prop_facgate_02_l",
	"prop_facgate_03post",
	"prop_facgate_03_l",
	"prop_facgate_03_ld_l",
	"prop_facgate_03_ld_r",
	"prop_facgate_03_r",
	"prop_facgate_04_l",
	"prop_facgate_04_r",
	"prop_facgate_05_r",
	"prop_facgate_05_r_dam_l1",
	"prop_facgate_05_r_l1",
	"prop_facgate_06_l",
	"prop_facgate_06_r",
	"prop_facgate_07",
	"prop_facgate_07b",
	"prop_facgate_08",
	"prop_facgate_08_frame",
	"prop_facgate_08_ld2",
	"prop_facgate_id1_27",
	"prop_fence_log_01",
	"prop_fence_log_02",
	"prop_fncconstruc_02a",
	"prop_fnclog_01a",
	"prop_fnclog_01b",
	"prop_fncpeir_03a",
	"prop_fncres_02a",
	"prop_fncres_02b",
	"prop_fncres_02c",
	"prop_fncres_02d",
	"prop_fncres_02_gate1",
	"prop_fncres_03gate1",
	"prop_fncres_05c_l1",
	"prop_fncsec_01a",
	"prop_fncsec_01b",
	"prop_fncsec_01crnr",
	"prop_fncsec_01gate",
	"prop_fncsec_01pole",
	"prop_fncsec_02a",
	"prop_fncsec_02pole",
	"prop_fncwood_07gate1",
	"prop_fncwood_11a_l1",
	"prop_fncwood_16a",
	"prop_fncwood_16b",
	"prop_fncwood_16c",
	"prop_fncwood_18a",
	"prop_gatecom_02",
	"prop_gate_airport_01",
	"prop_gate_cult_01_l",
	"prop_gate_cult_01_r",
	"prop_gate_docks_ld",
	"prop_gate_farm_01a",
	"prop_gate_farm_post",
	"prop_gate_frame_01",
	"prop_gate_frame_02",
	"prop_gate_frame_04",
	"prop_gate_frame_05",
	"prop_gate_frame_06",
	"prop_gate_military_01",
	"prop_gate_prison_01",
	"prop_gate_tep_01_l",
	"prop_gate_tep_01_r",
	"prop_ld_balcfnc_01a",
	"prop_ld_balcfnc_02a",
	"prop_ld_balcfnc_02c",
	"prop_lrggate_01c_l",
	"prop_lrggate_01c_r",
	"prop_lrggate_01_l",
	"prop_lrggate_01_pst",
	"prop_lrggate_01_r",
	"prop_lrggate_02_ld",
	"prop_lrggate_03a",
	"prop_lrggate_03b",
	"prop_lrggate_03b_ld",
	"prop_lrggate_04a",
	"prop_lrggate_05a",
	"prop_lrggate_06a",
	"prop_fnccorgm_05a",
	"prop_fnccorgm_05b",
	"prop_fnccorgm_06a",
	"prop_fnccorgm_06b",
	"prop_fnclink_01gate1",
	"prop_fnclink_02gate1",
	"prop_fnclink_02gate2",
	"prop_fnclink_02gate5",
	"prop_fnclink_02gate6_l",
	"prop_fnclink_02gate6_r",
	"prop_fnclink_02gate7",
	"prop_fnclink_03gate1",
	"prop_fnclink_03gate2",
	"prop_fnclink_03gate4",
	"prop_fnclink_03gate5",
	"prop_fnclink_04gate1",
	"prop_fnclink_04h_l2",
	"prop_fnclink_06gate2",
	"prop_fnclink_06gate3",
	"prop_fnclink_06gatepost",
	"prop_fnclink_07gate1",
	"prop_fnclink_07gate2",
	"prop_fnclink_07gate3",
	"prop_fnclink_09gate1",
	"prop_fnclink_10a",
	"prop_fnclink_10b",
	"prop_fnclink_10c",
	"prop_fnclink_10d",
	"prop_fnclink_10e",
	"prop_fncsec_04a",
	"prop_gate_bridge_ld",
	"prop_hobo_stove_01",
	"prop_homeless_matress_01",
	"prop_homeless_matress_02",
	"prop_pizza_box_01",
	"prop_pizza_box_02",
	"prop_rub_bike_01",
	"prop_rub_bike_02",
	"prop_rub_bike_03",
	"prop_rub_busdoor_01",
	"prop_rub_busdoor_02",
	"prop_rub_buswreck_01",
	"prop_rub_buswreck_03",
	"prop_rub_buswreck_06",
	"prop_rub_cabinet",
	"prop_rub_cabinet01",
	"prop_rub_cabinet02",
	"prop_rub_cabinet03",
	"prop_rub_cage01a",
	"prop_rub_carpart_02",
	"prop_rub_carpart_03",
	"prop_rub_carpart_04",
	"prop_rub_chassis_01",
	"prop_rub_chassis_02",
	"prop_rub_chassis_03",
	"prop_rub_cont_01a",
	"prop_rub_cont_01b",
	"prop_rub_cont_01c",
	"prop_rub_flotsam_01",
	"prop_rub_flotsam_02",
	"prop_rub_flotsam_03",
	"prop_rub_frklft",
	"prop_rub_litter_01",
	"prop_rub_litter_02",
	"prop_rub_litter_03",
	"prop_rub_litter_03b",
	"prop_rub_litter_03c",
	"prop_rub_litter_04",
	"prop_rub_litter_04b",
	"prop_rub_litter_05",
	"prop_rub_litter_06",
	"prop_rub_litter_07",
	"prop_rub_litter_09",
	"prop_rub_litter_8",
	"prop_rub_matress_01",
	"prop_rub_matress_02",
	"prop_rub_matress_03",
	"prop_rub_matress_04",
	"prop_rub_monitor",
	"prop_rub_pile_01",
	"prop_rub_pile_02",
	"prop_rub_planks_01",
	"prop_rub_planks_02",
	"prop_rub_planks_03",
	"prop_rub_planks_04",
	"prop_rub_railwreck_1",
	"prop_rub_railwreck_2",
	"prop_rub_railwreck_3",
	"prop_rub_scrap_02",
	"prop_rub_scrap_03",
	"prop_rub_scrap_04",
	"prop_rub_scrap_05",
	"prop_rub_scrap_06",
	"prop_rub_scrap_07",
	"prop_rub_stool",
	"prop_rub_sunktyre",
	"prop_rub_t34",
	"prop_rub_trainers_01",
	"prop_rub_trolley01a",
	"prop_rub_trolley02a",
	"prop_rub_trolley03a",
	"prop_rub_trukwreck_1",
	"prop_rub_trukwreck_2",
	"prop_rub_tyre_01",
	"prop_rub_tyre_02",
	"prop_rub_tyre_03",
	"prop_rub_tyre_dam1",
	"prop_rub_tyre_dam2",
	"prop_rub_tyre_dam3",
	"prop_rub_washer_01",
	"prop_rub_wheel_01",
	"prop_rub_wheel_02",
	"prop_rub_wreckage_3",
	"prop_rub_wreckage_4",
	"prop_rub_wreckage_5",
	"prop_rub_wreckage_6",
	"prop_rub_wreckage_7",
	"prop_rub_wreckage_8",
	"prop_rub_wreckage_9",
	"prop_skid_chair_01",
	"prop_skid_chair_02",
	"prop_skid_chair_03",
	"prop_skid_sleepbag_1",
	"prop_skid_tent_01",
	"prop_skid_tent_01b",
	"prop_skid_tent_03",
	"prop_still",
	"prop_bench_01b",
	"prop_bench_01c",
	"prop_bench_04",
	"prop_bench_05",
	"prop_bench_09",
	"prop_chair_01a",
	"prop_chair_01b",
	"prop_chair_02",
	"prop_chair_03",
	"prop_chair_04a",
	"prop_chair_04b",
	"prop_chair_05",
	"prop_chair_06",
	"prop_chair_07",
	"prop_chair_08",
	"prop_chair_09",
	"prop_chair_10",
	"prop_chair_pile_01",
	"prop_chateau_chair_01",
	"prop_clown_chair",
	"prop_old_deck_chair",
	"prop_old_deck_chair_02",
	"prop_old_wood_chair",
	"prop_old_wood_chair_lod",
	"prop_parasol_01",
	"prop_parasol_01_b",
	"prop_parasol_01_c",
	"prop_parasol_01_down",
	"prop_parasol_02",
	"prop_parasol_02_b",
	"prop_parasol_02_c",
	"prop_parasol_03",
	"prop_parasol_03_b",
	"prop_parasol_03_c",
	"prop_parasol_04e",
	"prop_parasol_04e_lod1",
	"prop_parasol_bh_48",
	"prop_patio_heater_01",
	"prop_patio_lounger1",
	"prop_patio_lounger1b",
	"prop_patio_lounger1_table",
	"prop_patio_lounger_2",
	"prop_patio_lounger_3",
	"prop_picnictable_02",
	"prop_proxy_chateau_table",
	"prop_stool_01",
	"prop_table_02",
	"prop_table_03b_cs",
	"prop_table_04",
	"prop_table_04_chr",
	"prop_table_05",
	"prop_table_05_chr",
	"prop_table_06",
	"prop_table_06_chr",
	"prop_table_07",
	"prop_table_07_l1",
	"prop_table_08",
	"prop_table_08_chr",
	"prop_table_08_side",
	"prop_table_para_comb_04",
	"prop_umpire_01",
	"prop_afsign_amun",
	"prop_afsign_vbike",
	"prop_beer_neon_01",
	"prop_beer_neon_02",
	"prop_beer_neon_03",
	"prop_beer_neon_04",
	"prop_billboard_01",
	"prop_billboard_02",
	"prop_billboard_03",
	"prop_billboard_04",
	"prop_billboard_05",
	"prop_billboard_06",
	"prop_billboard_07",
	"prop_billboard_08",
	"prop_billboard_09",
	"prop_billboard_09wall",
	"prop_billboard_10",
	"prop_billboard_11",
	"prop_billboard_12",
	"prop_billboard_13",
	"prop_billboard_14",
	"prop_billboard_15",
	"prop_billboard_16",
	"prop_gas_01",
	"prop_gas_02",
	"prop_gas_03",
	"prop_gas_04",
	"prop_gas_05",
	"prop_pharm_sign_01",
	"prop_sign_airp_01a",
	"prop_sign_airp_02a",
	"prop_sign_airp_02b",
	"prop_sign_big_01",
	"prop_sign_road_04g_l1",
	"prop_barrel_01a",
	"prop_barrel_02a",
	"prop_barrel_02b",
	"prop_barrel_03a",
	"prop_barrel_03d",
	"prop_boxpile_10a",
	"prop_boxpile_10b",
	"prop_box_ammo01a",
	"prop_box_ammo02a",
	"prop_box_ammo03a_set",
	"prop_box_ammo03a_set2",
	"prop_box_ammo04a",
	"prop_box_ammo05b",
	"prop_box_ammo07a",
	"prop_box_ammo07b",
	"prop_box_guncase_01a",
	"prop_box_guncase_02a",
	"prop_box_guncase_03a",
	"prop_box_tea01a",
	"prop_box_wood05a",
	"prop_box_wood05b",
	"prop_box_wood08a",
	"prop_buckets_02",
	"prop_bucket_01a",
	"prop_bucket_01b",
	"prop_bucket_02a",
	"prop_cntrdoor_ld_l",
	"prop_cntrdoor_ld_r",
	"prop_container_01a",
	"prop_container_01b",
	"prop_container_01c",
	"prop_container_01d",
	"prop_container_01e",
	"prop_container_01f",
	"prop_container_01g",
	"prop_container_01h",
	"prop_container_01mb",
	"prop_container_02a",
	"prop_container_03a",
	"prop_container_03b",
	"prop_container_03mb",
	"prop_container_03_ld",
	"prop_container_04a",
	"prop_container_04mb",
	"prop_container_05mb",
	"prop_container_door_mb_l",
	"prop_container_door_mb_r",
	"prop_container_ld",
	"prop_container_ld2",
	"prop_container_old1",
	"prop_contnr_pile_01a",
	"prop_cratepile_07a_l1",
	"prop_crate_01a",
	"prop_crate_02a",
	"prop_crate_08a",
	"prop_crate_09a",
	"prop_crate_10a",
	"prop_crate_11a",
	"prop_crate_11b",
	"prop_crate_11c",
	"prop_crate_11d",
	"prop_dog_cage_01",
	"prop_dog_cage_02",
	"prop_drop_crate_01",
	"prop_drop_crate_01_set",
	"prop_drop_crate_01_set2",
	"prop_flattrailer_01a",
	"prop_flattruck_01a",
	"prop_fruitstand_b_nite",
	"prop_gascage01",
	"prop_keg_01",
	"prop_mb_crate_01a_set",
	"prop_pallettruck_01",
	"prop_sacktruck_01",
	"prop_sacktruck_02a",
	"prop_shelves_01",
	"prop_shelves_02",
	"prop_shelves_03",
	"prop_truktrailer_01a",
	"prop_warehseshelf01",
	"prop_warehseshelf02",
	"prop_warehseshelf03",
	"prop_watercrate_01",
	"prop_chall_lamp_01",
	"prop_chall_lamp_01n",
	"prop_chall_lamp_02",
	"prop_construcionlamp_01",
	"prop_dt1_13_groundlight",
	"prop_dt1_13_walllightsource",
	"prop_ind_light_01a",
	"prop_ind_light_01b",
	"prop_ind_light_01c",
	"prop_securityvan_lightrig",
	"prop_traffic_rail_1c",
	"prop_traffic_rail_2",
	"prop_walllight_ld_01b",
	"prop_wall_light_08a",
	"prop_wall_light_10a",
	"prop_wall_light_10b",
	"prop_wall_light_10c",
	"prop_wall_light_11",
	"prop_wall_light_12",
	"prop_wall_light_17b",
	"prop_wall_light_18a",
	"prop_warninglight_01",
	"prop_atm_02",
	"prop_atm_03",
	"prop_bikerack_2",
	"prop_bollard_01a",
	"prop_bollard_01b",
	"prop_bollard_01c",
	"prop_bollard_03a",
	"prop_elecbox_03a",
	"prop_elecbox_10",
	"prop_elecbox_12",
	"prop_elecbox_13",
	"prop_elecbox_14",
	"prop_elecbox_15",
	"prop_elecbox_16",
	"prop_elecbox_17",
	"prop_elecbox_18",
	"prop_elecbox_19",
	"prop_elecbox_20",
	"prop_elecbox_21",
	"prop_elecbox_22",
	"prop_elecbox_23",
	"prop_elecbox_24",
	"prop_elecbox_24b",
	"prop_elecbox_25",
	"prop_fire_driser_1a",
	"prop_fire_driser_1b",
	"prop_fire_driser_2b",
	"prop_fire_driser_3b",
	"prop_fire_driser_4a",
	"prop_fire_driser_4b",
	"prop_fire_hosereel",
	"prop_fleeca_atm",
	"prop_gshotsensor_01",
	"prop_mobile_mast_1",
	"prop_mobile_mast_2",
	"prop_parking_sign_06",
	"prop_parking_sign_07",
	"prop_parking_sign_1",
	"prop_parking_sign_2",
	"prop_phonebox_05a",
	"prop_telegraph_01a",
	"prop_telegraph_01b",
	"prop_telegraph_01c",
	"prop_telegraph_01d",
	"prop_telegraph_01e",
	"prop_telegraph_01f",
	"prop_telegraph_01g",
	"prop_telegraph_02a",
	"prop_telegraph_02b",
	"prop_telegraph_03",
	"prop_telegraph_04a",
	"prop_telegraph_04b",
	"prop_telegraph_05a",
	"prop_telegraph_05b",
	"prop_telegraph_05c",
	"prop_telegraph_06a",
	"prop_telegraph_06b",
	"prop_telegraph_06c",
	"prop_telegwall_01a",
	"prop_telegwall_01b",
	"prop_telegwall_02a",
	"prop_telegwall_03a",
	"prop_telegwall_03b",
	"prop_telegwall_04a",
	"prop_tram_pole_double01",
	"prop_tram_pole_double02",
	"prop_tram_pole_double03",
	"prop_tram_pole_roadside",
	"prop_tram_pole_single01",
	"prop_tram_pole_single02",
	"prop_tram_pole_wide01",
	"prop_tyre_rack_01",
	"prop_valet_03",
	"prop_cartwheel_01",
	"prop_cattlecrush",
	"prop_chickencoop_a",
	"prop_feeder1",
	"prop_grain_hopper",
	"prop_handrake",
	"prop_haybailer_01",
	"prop_haybale_01",
	"prop_haybale_02",
	"prop_haybale_stack_01",
	"prop_hunterhide",
	"prop_oldplough1",
	"prop_old_churn_01",
	"prop_old_churn_02",
	"prop_old_farm_01",
	"prop_old_farm_02",
	"prop_potatodigger",
	"prop_roundbailer01",
	"prop_roundbailer02",
	"prop_rural_windmill_l1",
	"prop_rural_windmill_l2",
	"prop_scythemower",
	"prop_side_spreader",
	"prop_snow_bailer_01",
	"prop_snow_barrel_pile_03",
	"prop_snow_bench_01",
	"prop_snow_bin_01",
	"prop_snow_bin_02",
	"prop_snow_cam_03",
	"prop_snow_cam_03a",
	"prop_snow_diggerbkt_01",
	"prop_snow_dumpster_01",
	"prop_snow_elecbox_16",
	"prop_snow_facgate_01",
	"prop_snow_flower_01",
	"prop_snow_flower_02",
	"prop_snow_fnclink_03crnr2",
	"prop_snow_fnclink_03h",
	"prop_snow_fnclink_03i",
	"prop_snow_fncwood_14a",
	"prop_snow_fncwood_14b",
	"prop_snow_fncwood_14c",
	"prop_snow_fncwood_14d",
	"prop_snow_fncwood_14e",
	"prop_snow_fnc_01",
	"prop_snow_gate_farm_03",
	"prop_snow_grain_01",
	"prop_snow_light_01",
	"prop_snow_oldlight_01b",
	"prop_snow_rail_signals02",
	"prop_snow_rub_trukwreck_2",
	"prop_snow_side_spreader_01",
	"prop_snow_streetlight01",
	"prop_snow_streetlight_01_frag_",
	"prop_snow_sub_frame_01a",
	"prop_snow_sub_frame_04b",
	"prop_snow_telegraph_01a",
	"prop_snow_telegraph_02a",
	"prop_snow_telegraph_03",
	"prop_snow_traffic_rail_1a",
	"prop_snow_traffic_rail_1b",
	"prop_snow_trailer01",
	"prop_snow_truktrailer_01a",
	"prop_snow_tyre_01",
	"prop_snow_wall_light_15a",
	"prop_snow_watertower01",
	"prop_snow_watertower01_l2",
	"prop_snow_watertower03",
	"prop_snow_woodpile_04a",
	"prop_sprayer",
	"prop_trailer01",
	"prop_trailer01_up",
	"prop_trough1",
	"prop_waterwheela",
	"prop_waterwheelb",
	"prop_wreckedcart",
	"prop_am_box_wood_01",
	"prop_bush_ivy_01_1m",
	"prop_bush_ivy_01_2m",
	"prop_bush_ivy_01_bk",
	"prop_bush_ivy_01_l",
	"prop_bush_ivy_01_pot",
	"prop_bush_ivy_01_r",
	"prop_bush_ivy_01_top",
	"prop_bush_ivy_02_1m",
	"prop_bush_ivy_02_2m",
	"prop_bush_ivy_02_l",
	"prop_bush_ivy_02_pot",
	"prop_bush_ivy_02_r",
	"prop_bush_ivy_02_top",
	"prop_bush_lrg_01",
	"prop_bush_lrg_01b",
	"prop_bush_lrg_01c",
	"prop_bush_lrg_01d",
	"prop_bush_lrg_01e",
	"prop_bush_lrg_02",
	"prop_bush_lrg_02b",
	"prop_bush_lrg_03",
	"prop_bush_lrg_03b",
	"prop_bush_lrg_04b",
	"prop_bush_lrg_04c",
	"prop_bush_lrg_04d",
	"prop_bush_med_01",
	"prop_bush_med_02",
	"prop_bush_med_03",
	"prop_bush_med_05",
	"prop_bush_med_06",
	"prop_bush_med_07",
	"prop_bush_neat_01",
	"prop_bush_neat_02",
	"prop_bush_neat_03",
	"prop_bush_neat_04",
	"prop_bush_neat_05",
	"prop_bush_neat_06",
	"prop_bush_neat_07",
	"prop_bush_neat_08",
	"prop_bush_ornament_01",
	"prop_bush_ornament_02",
	"prop_bush_ornament_03",
	"prop_bush_ornament_04",
	"prop_creosote_b_01",
	"prop_desert_iron_01",
	"prop_plant_group_01",
	"prop_plant_group_02",
	"prop_plant_group_03",
	"prop_plant_group_04",
	"prop_plant_group_05",
	"prop_plant_group_05b",
	"prop_plant_group_05c",
	"prop_plant_group_05d",
	"prop_plant_group_06a",
	"prop_plant_group_06b",
	"prop_plant_group_06c",
	"prop_skunk_bush_01",
	"prop_bush_grape_01",
	"prop_coral_bush_01",
	"prop_coral_flat_01",
	"prop_coral_flat_01_l1",
	"prop_coral_flat_02",
	"prop_coral_flat_brainy",
	"prop_coral_flat_clam",
	"prop_coral_grass_01",
	"prop_coral_grass_02",
	"prop_coral_kelp_01",
	"prop_coral_kelp_01_l1",
	"prop_coral_kelp_02",
	"prop_coral_kelp_02_l1",
	"prop_coral_kelp_03",
	"prop_coral_kelp_03a",
	"prop_coral_kelp_03b",
	"prop_coral_kelp_03c",
	"prop_coral_kelp_03d",
	"prop_coral_kelp_03_l1",
	"prop_coral_kelp_04",
	"prop_coral_kelp_04_l1",
	"prop_coral_pillar_01",
	"prop_coral_pillar_02",
	"prop_coral_spikey_01",
	"prop_coral_stone_03",
	"prop_coral_stone_04",
	"prop_coral_sweed_01",
	"prop_coral_sweed_02",
	"prop_coral_sweed_03",
	"prop_coral_sweed_04",
	"prop_cora_clam_01",
	"prop_tree_birch_05",
	"prop_veg_corn_01",
	"prop_veg_crop_01",
	"prop_veg_crop_02",
	"prop_veg_crop_04",
	"prop_veg_crop_04_leaf",
	"prop_veg_crop_05",
	"prop_veg_crop_06",
	"prop_veg_crop_orange",
	"prop_veg_crop_tr_01",
	"prop_veg_crop_tr_02",
	"prop_agave_01",
	"prop_agave_02",
	"prop_aloevera_01",
	"prop_bush_dead_02",
	"prop_cat_tail_01",
	"prop_cs_plant_01",
	"prop_grass_dry_02",
	"prop_grass_dry_03",
	"prop_plant_01a",
	"prop_plant_01b",
	"prop_plant_base_01",
	"prop_plant_base_02",
	"prop_plant_base_03",
	"prop_plant_cane_01a",
	"prop_plant_cane_01b",
	"prop_plant_cane_02a",
	"prop_plant_cane_02b",
	"prop_plant_clover_01",
	"prop_plant_clover_02",
	"prop_plant_fern_01a",
	"prop_plant_fern_01b",
	"prop_plant_fern_02a",
	"prop_plant_fern_02b",
	"prop_plant_fern_02c",
	"prop_plant_flower_01",
	"prop_plant_flower_02",
	"prop_plant_flower_03",
	"prop_plant_flower_04",
	"prop_plant_paradise",
	"prop_plant_paradise_b",
	"prop_p_spider_01a",
	"prop_p_spider_01c",
	"prop_p_spider_01d",
	"prop_veg_grass_01_a",
	"prop_veg_grass_01_b",
	"prop_veg_grass_01_c",
	"prop_veg_grass_01_d",
	"prop_veg_grass_02_a",
	"prop_fan_palm_01a",
	"prop_palm_fan_02_a",
	"prop_palm_fan_02_b",
	"prop_palm_fan_03_a",
	"prop_palm_fan_03_b",
	"prop_palm_fan_03_c",
	"prop_palm_fan_03_d",
	"prop_palm_fan_04_a",
	"prop_palm_fan_04_b",
	"prop_palm_fan_04_c",
	"prop_palm_fan_04_d",
	"prop_palm_huge_01a",
	"prop_palm_huge_01b",
	"prop_palm_med_01a",
	"prop_palm_med_01b",
	"prop_palm_med_01c",
	"prop_palm_med_01d",
	"prop_palm_sm_01a",
	"prop_palm_sm_01d",
	"prop_palm_sm_01e",
	"prop_palm_sm_01f",
	"prop_plant_int_02a",
	"prop_plant_int_02b",
	"prop_plant_int_05a",
	"prop_plant_int_05b",
	"prop_plant_int_06a",
	"prop_plant_int_06b",
	"prop_plant_int_06c",
	"prop_pot_plant_02a",
	"prop_pot_plant_02b",
	"prop_pot_plant_02c",
	"prop_pot_plant_02d",
	"prop_pot_plant_03a",
	"prop_pot_plant_04a",
	"prop_pot_plant_05d_l1",
	"prop_pot_plant_bh1",
	"prop_rock_1_a",
	"prop_rock_1_b",
	"prop_rock_1_c",
	"prop_rock_1_d",
	"prop_rock_1_e",
	"prop_rock_1_f",
	"prop_rock_1_g",
	"prop_rock_1_h",
	"prop_rock_1_i",
	"prop_rock_2_a",
	"prop_rock_2_c",
	"prop_rock_2_d",
	"prop_rock_2_f",
	"prop_rock_2_g",
	"prop_rock_3_a",
	"prop_rock_3_b",
	"prop_rock_3_c",
	"prop_rock_3_d",
	"prop_rock_3_e",
	"prop_rock_3_f",
	"prop_rock_3_g",
	"prop_rock_3_h",
	"prop_rock_3_i",
	"prop_rock_3_j",
	"prop_rock_4_c",
	"prop_rock_4_d",
	"rock_4_cl_2_1",
	"rock_4_cl_2_2",
	"prop_snow_bush_01_a",
	"prop_snow_bush_02_a",
	"prop_snow_bush_02_b",
	"prop_snow_bush_03",
	"prop_snow_bush_04",
	"prop_snow_bush_04b",
	"prop_snow_field_01",
	"prop_snow_field_02",
	"prop_snow_field_03",
	"prop_snow_field_04",
	"prop_snow_grass_01",
	"prop_snow_tree_03_e",
	"prop_snow_tree_03_h",
	"prop_snow_tree_03_i",
	"prop_snow_tree_04_d",
	"prop_snow_tree_04_f",
	"prop_snow_t_ml_01",
	"prop_snow_t_ml_02",
	"prop_snow_t_ml_03",
	"prop_rio_del_01",
	"prop_rus_olive",
	"prop_rus_olive_wint",
	"prop_s_pine_dead_01",
	"prop_tree_birch_01",
	"prop_tree_birch_02",
	"prop_tree_birch_03",
	"prop_tree_birch_03b",
	"prop_tree_birch_04",
	"prop_tree_cedar_02",
	"prop_tree_cedar_03",
	"prop_tree_cedar_04",
	"prop_tree_cedar_s_01",
	"prop_tree_cedar_s_02",
	"prop_tree_cedar_s_04",
	"prop_tree_cedar_s_05",
	"prop_tree_cedar_s_06",
	"prop_tree_cypress_01",
	"prop_tree_eng_oak_01",
	"prop_tree_eucalip_01",
	"prop_tree_fallen_01",
	"prop_tree_fallen_02",
	"prop_tree_fallen_pine_01",
	"prop_tree_jacada_01",
	"prop_tree_jacada_02",
	"prop_tree_lficus_02",
	"prop_tree_lficus_03",
	"prop_tree_lficus_05",
	"prop_tree_lficus_06",
	"prop_tree_log_01",
	"prop_tree_log_02",
	"prop_tree_maple_02",
	"prop_tree_maple_03",
	"prop_tree_mquite_01",
	"prop_tree_oak_01",
	"prop_tree_olive_01",
	"prop_tree_pine_01",
	"prop_tree_pine_02",
	"prop_tree_stump_01",
	"prop_w_r_cedar_01",
	"prop_w_r_cedar_dead",
	"w_am_baseball",
	"w_am_baseball_hi",
	"w_am_brfcase",
	"w_am_case",
	"w_am_digiscanner",
	"w_am_digiscanner_hi",
	"w_am_fire_exting",
	"w_am_flare",
	"w_am_flare_hi",
	"w_am_jerrycan",
	"w_ar_advancedrifle",
	"w_ar_advancedrifle_hi",
	"w_ar_advancedrifle_mag1",
	"w_ar_advancedrifle_mag2",
	"w_ar_assaultrifle",
	"w_ar_assaultrifle_hi",
	"w_ar_assaultrifle_mag1",
	"w_ar_assaultrifle_mag2",
	"w_ar_carbinerifle",
	"w_ar_carbinerifle_hi",
	"w_ar_carbinerifle_mag1",
	"w_ar_carbinerifle_mag2",
	"w_at_ar_afgrip",
	"w_at_ar_afgrip_hi",
	"w_at_ar_flsh",
	"w_at_ar_flsh_hi",
	"w_at_ar_supp",
	"w_at_ar_supp_02",
	"w_at_ar_supp_02_hi",
	"w_at_ar_supp_hi",
	"w_at_pi_flsh",
	"w_at_pi_flsh_hi",
	"w_at_pi_supp",
	"w_at_pi_supp_hi",
	"w_at_railcover_01",
	"w_at_railcover_01_hi",
	"w_at_scope_large",
	"w_at_scope_large_hi",
	"w_at_scope_macro",
	"w_at_scope_macro_hi",
	"w_at_scope_max",
	"w_at_scope_max_hi",
	"w_at_scope_medium",
	"w_at_scope_medium_hi",
	"w_at_scope_small",
	"w_at_scope_small_hi",
	"w_at_sr_supp",
	"w_at_sr_supp_hi",
	"w_ex_grenadefrag",
	"w_ex_grenadefrag_hi",
	"w_ex_grenadesmoke",
	"w_ex_molotov",
	"w_ex_molotov_hi",
	"w_ex_pe",
	"w_ex_pe_hi",
	"w_lr_40mm",
	"w_lr_40mm_pu",
	"w_lr_grenadelauncher",
	"w_lr_grenadelauncher_hi",
	"w_lr_rpg",
	"w_lr_rpg_hi",
	"w_lr_rpg_rocket",
	"w_lr_rpg_rocket_pu",
	"w_me_bat",
	"w_me_crowbar",
	"w_me_gclub",
	"w_me_hammer",
	"w_me_knife_01",
	"w_me_nightstick",
	"w_mg_combatmg",
	"w_mg_combatmg_hi",
	"w_mg_combatmg_mag1",
	"w_mg_combatmg_mag2",
	"w_mg_mg",
	"w_mg_mg_hi",
	"w_mg_mg_mag1",
	"w_mg_mg_mag2",
	"w_mg_minigun",
	"w_mg_minigun_hi",
	"w_pi_appistol",
	"w_pi_appistol_hi",
	"w_pi_appistol_mag1",
	"w_pi_appistol_mag2",
	"w_pi_combatpistol",
	"w_pi_combatpistol_hi",
	"w_pi_combatpistol_mag1",
	"w_pi_combatpistol_mag2",
	"w_pi_pistol",
	"w_pi_pistol50",
	"w_pi_pistol50_hi",
	"w_pi_pistol50_mag1",
	"w_pi_pistol50_mag2",
	"w_pi_pistol_hi",
	"w_pi_pistol_mag1",
	"w_pi_pistol_mag2",
	"w_pi_stungun",
	"w_pi_stungun_hi",
	"w_sb_assaultsmg",
	"w_sb_assaultsmg_hi",
	"w_sb_assaultsmg_mag1",
	"w_sb_assaultsmg_mag2",
	"w_sb_microsmg",
	"w_sb_microsmg_hi",
	"w_sb_microsmg_mag1",
	"w_sb_microsmg_mag2",
	"w_sb_smg",
	"w_sb_smg_hi",
	"w_sb_smg_mag1",
	"w_sb_smg_mag2",
	"w_sg_assaultshotgun",
	"w_sg_assaultshotgun_hi",
	"w_sg_assaultshotgun_mag1",
	"w_sg_assaultshotgun_mag2",
	"w_sg_bullpupshotgun",
	"w_sg_bullpupshotgun_hi",
	"w_sg_pumpshotgun",
	"w_sg_pumpshotgun_hi",
	"w_sg_sawnoff",
	"w_sg_sawnoff_hi",
	"w_sr_heavysniper",
	"w_sr_heavysniper_hi",
	"w_sr_heavysniper_mag1",
	"w_sr_sniperrifle",
	"w_sr_sniperrifle_hi",
	"w_sr_sniperrifle_mag1",
};
void wait() {
	WAIT(0);
}


Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
}

void teleport_to_marker(Player target)
{
	Vector3 coords = get_blip_marker();
	Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	}
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 0.3, 0.5, 1.0, 2.0, 3.0, 5.0, 10.0, 15.0, 20.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	if (!groundFound)
	{
		coords.z = 5.0;
	}
	Features::teleporttocoords(target, coords);
}
void teleport_to_markerr()
{
	Vector3 coords = get_blip_marker();

	if (coords.x == 0 && coords.y == 0)
	{
		
		return;
	}

	// get entity to teleport
	Entity e = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	}

	// load needed map region and check height levels for ground existence
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	// if ground not found then set Z in air and give player a parachute
	if (!groundFound)
	{
		coords.z = 1000.0;
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
	}
	//do it
	teleport_to_coords(e, coords);
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return (int)atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}

int TestInt = 0;
bool TestBool = false;
float TestFloat = 0;
bool nig28wen = false;
bool menustart = 1;
bool dropCash = false;
Player player = PLAYER::PLAYER_ID();

void main() {
Menu::Files::StyleSaver::LoadStyles();
	while (true) {
		Menu::Checks::Keys();
		Features::UpdateLoop();
		switch (Menu::Settings::currentMenu) {
		case mainmenu:
		{
			 
			 Menu::Title("Master Menu");
			 Menu::Subtitle("VERSION: 1.48");
			 Menu::MenuOption("自我选项", playermenu);
			 Menu::MenuOption("武器选项", weapon);
			 Menu::MenuOption("线上选项", onlineoptions);
			 Menu::MenuOption("载具选项", vehspawner);
			 Menu::MenuOption("传送选项", teleports);
			 Menu::MenuOption("世界选项", worldoptions);
			 Menu::MenuOption("视觉冲击", versionsoptions);
			 Menu::MenuOption("模型选项", modelObjects);
			 Menu::MenuOption("全副武装", OutfitOptions);
			 Menu::MenuOption("成就解锁", recover);
			 Menu::MenuOption("金钱供给", moneystealth);
			 Menu::MenuOption("其它设置", miscoptions);
			 Menu::MenuOption("菜单设置", settingsmenu);
			 Menu::MenuOption("技术支持", CreditsInfor);
			 

		 }
		 break;
#pragma endregion
#pragma region OLINE OPTIONS
		case onlineoptions:
		{
			Menu::Title("线上选项");
			Menu::Subtitle("OLINE OPTIONS");
			Menu::MenuOption("全局控制", allplayers);
			for (int i = 0; i < 32; ++i) {
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
					Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
				}
			}
		}
		break;
#pragma endregion
#pragma region Money Options
		 case moneystealth:
		 {
			
			 Menu::Title("金钱供给");
			 Menu::Subtitle("MONEY OPTIONS");
			 Menu::Break("~g~---隐形刷钱---");
             //Menu::Bool("15M", Features::stealth15m, [] { Features::Stealth(Features::stealth15m); });
			 //Menu::Bool("12M", Features::stealth12m, [] { Features::Stealth(Features::stealth12m); });
			 //Menu::Bool("10M", Features::stealth10m, [] { Features::Stealth(Features::stealth10m); });
			 //Menu::Bool("600k", Features::stealth600k, [] { Features::Stealth(Features::stealth600k); });
			 //Menu::Bool("250k", Features::stealth250k, [] { Features::Stealth(Features::stealth250k); });
			 //Menu::Bool("120k", Features::stealth120k, [] { Features::Stealth(Features::stealth120k); });
			 //Menu::Bool("50k", Features::stealth50k, [] { Features::Stealth(Features::stealth50k); });
			 Menu::Break("~g~---金钱掉落---");
			 Menu::Bool("金钱雨", Features::moneyrain2k, [] { Features::RainMoney(Features::moneyrain2k); });
			 Menu::Bool("掉落$2500", Features::moneydropp, [] { Features::dildomoneylocal(Features::moneydropp); });
			 Menu::Break("~g~---金钱转账---");
			 Menu::MenuOption("账目变更", moneyoptions);
			 Menu::Break("~g~---删除银行货币---");
			 Menu::Int("金额", Features::amount5, 0, 2147483647, 1000000);
			 //Menu::Bool("移除银行金额", Features::remover, [] { Features::Stealth(Features::remover); });
			 Menu::Break("~g~---添加银行货币---");
			 Menu::Int("金额", Features::amount, 0, 15000000, 1000000);
			 Menu::Bool("兑现支票", Features::giver);
			 

		 }
		 break;
#pragma endregion
#pragma region world Options
		 case worldoptions:
		 {
	
			 Menu::Title("世界选项");
			 Menu::Subtitle("WORLD OPTIONS");
			 Menu::MenuOption("天气选项", weatheroptions);
			 Menu::Int("单机时间控制", timeer, 0, 24);
			 if (Menu::Option("设定时间")) { NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(timeer, 0, 0); }
		 }
		 break;
#pragma endregion
#pragma region Weather Options
		 case weatheroptions:
		 {
			 Menu::Title("天气选项");
			 Menu::Subtitle("WEATHER OPTIONS");
			 if (Menu::Option("晴天")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); }
			 if (Menu::Option("雨天")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing"); }
			 if (Menu::Option("雪天")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight"); }
			 if (Menu::Option("雷雨")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); }
			 if (Menu::Option("暴雪")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); }
			 if (Menu::Option("阴天")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); }
			 if (Menu::Option("沙尘暴")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy"); }
			 if (Menu::Option("雾霾")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog"); }
			 if (Menu::Option("多云")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); }
			 if (Menu::Option("圣诞节")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("XMAS"); }
		 }
		 break;
#pragma region Visions Options
		 case versionsoptions:
		 {
			 
			 Menu::Title("视觉冲击");
			 Menu::Subtitle("VISIONS OPTIONS");
			 if (Menu::Option("关闭")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("DEFAULT"); } //done
			 if (Menu::Option("石头")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("stoned"); } //done
			 if (Menu::Option("橙色")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("REDMIST"); } //done
			 if (Menu::Option("红色")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("DEATH"); } //done
			 if (Menu::Option("可卡因")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_flying_base"); } //done
			 if (Menu::Option("气体燃料")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("DRUG_gas_huffin"); } //done
			 if (Menu::Option("晃动")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_wobbly"); } //done
			 if (Menu::Option("醉酒")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("Drunk"); } //done
			 if (Menu::Option("极乐之地")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("Bloom"); } //done
			 if (Menu::Option("3DM效果")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("PlayerSwitchPulse"); } //done
			 if (Menu::Option("幻觉")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("player_transition"); } //done
			 if (Menu::Option("连杀奖励")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("MP_Killstreak"); } //done
			 if (Menu::Option("低画质")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("cinema_001"); } //done
			 if (Menu::Option("模糊不清")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("CHOP"); } //done
			 if (Menu::Option("白屏")) { GRAPHICS::SET_TIMECYCLE_MODIFIER("BarryFadeOut"); } //done
			 Menu::Bool("夜晚", Features::nightvisionbool, [] {Features::nightvision(Features::nightvisionbool); }); //done
			 Menu::Bool("炎热天气", Features::heatvisionbool, [] {Features::heatvision(Features::heatvisionbool); }); //done
			 Menu::Bool("灯火管制", Features::blackvisionbool, [] {Features::blackvision(Features::blackvisionbool); }); //done

		 }
		 break;
#pragma endregion

#pragma region Weapons Menu
		 case weapon:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_gunclub", "shopui_title_gunclub", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("武器选项");
			 Menu::Subtitle("WEAPONS OPTIONS");
			 if (Menu::Option("获得全部武器")) {
				 uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				 for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					 WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
				 }
			 }
			 Menu::Bool("无限子弹", Features::infammo, [] { Features::noreloadv(Features::infammo); });
			 Menu::Bool("彩虹枪", Features::rbgun, [] { Features::RBGuner(Features::rbgun); });
			 Menu::Bool("一击必杀", Features::osk, [] { Features::OSKR(Features::osk); });
			 Menu::Bool("快速射击", Features::rapidfirer);
			 Menu::Break("---武装兵器---");
			 Menu::Bool("烟花枪", Features::WeaponFirework, [] {Features::featureWeaponFirework(Features::WeaponFirework); }); //done
			 Menu::Bool("钱袋枪", Features::FakeBags, [] {Features::featureFakeBags(Features::FakeBags); }); //done
			 Menu::Bool("火炮枪", Features::WeaponRPG, [] {Features::featureWeaponRPG(Features::WeaponRPG); }); //done
			 Menu::Bool("传送枪", Features::TeleportGun, [] {Features::featureTeleportGun(Features::TeleportGun); }); //done
			 Menu::Bool("坦克枪", Features::RhinoGun, [] {Features::featureRhinoGun(Features::RhinoGun); }); //done
			 Menu::Bool("汽车枪", Features::PantoGun, [] {Features::featurePantoGun(Features::PantoGun); }); //done

		 }
		 break;
#pragma region RecoveryStats
		 case RecoveryStats:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("恢复选项");
			 Menu::Subtitle("解锁选项");
			

			 if (Menu::Option("100%的技能")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);
			 }
			 if (Menu::Option("100% LSC")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RACES_WON"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_1_UNLCK"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_2_UNLCK"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_3_UNLCK"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_4_UNLCK"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_5_UNLCK"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_6_UNLCK"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_7_UNLCK"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONDRIVE"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONNAV"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINSEARACE"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINAIRRACE"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_TURBO_STARTS_IN_RACE"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_RACES_FASTEST_LAP"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_SLIPSTREAMS_IN_RACE"), 100, 1);
			 }
			 if (Menu::Option("删除不好的运动")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_WAS_I_BAD_SPORT"), 0, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), 0, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DESTROYED_PVEHICLES"), 0, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HELPFUL"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_NAME"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_MOTTO"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_STATUS"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_EXPLOITS"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, 1);
			 }
			 if (Menu::Option("解锁所有的衣服")) {
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
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
			 }
			 if (Menu::Option("解锁所有纹身")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMMOSTKILLSSURVIVE"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILL3ANDWINGTARACE"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLBOUNTY"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMREVENGEKILLSDM"), 50, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLSTREAKSDM"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_LAPDANCES"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_SECURITY_CARS_ROBBED"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 1);
			 }
			 if (Menu::Option("解锁所有武器迷彩伪装")) {
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
			 }
			 if (Menu::Option("解锁所有的奖杯")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL_ENEMY_KILLS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_UNARMED_ENEMY_KILLS"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CARS_EXPLODED"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_5STAR_WANTED_AVOIDANCE"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CARS_EXPORTED"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PASS_DB_PLAYER_KILLS"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOST_SPINS_IN_ONE_JUMP"), 5, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_AWD_FM_CR_DM_MADE"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 10, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_LAPDANCES"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOST_ARM_WRESTLING_WINS"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_HAIRCUTS"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_SECURITY_CARS_ROBBED"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_VEHICLES_JACKEDR"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOST_FLIPS_IN_ONE_JUMP"), 5, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_AT_DARTS"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_PASSENGERTIME"), 4, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_TIME_IN_HELICOPTER"), 4, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_3KILLSAMEGUY"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_KILLSTREAK"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_STOLENKILL"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_BIRDIES"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_HOLE_IN_1"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_RACE_LAST_FIRST"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_RACES_FASTEST_LAP"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_ACE"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_STASETWIN"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM6DARTCHKOUT"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_PARACHUTE_JUMPS_20M"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_PARACHUTE_JUMPS_50M"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AIR_LAUNCHES_OVER_40M"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_BUY_EVERY_GUN"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMDRIVEWITHOUTCRASH"), 255, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMCRATEDROPS"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM25DIFFERENTDM"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_5_SET_WINS"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_AWD_FM_CR_PLAYED_BY_PEEP"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_AWD_FM_CR_RACES_MADE"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM25DIFFERENTRACES"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM25DIFITEMSCLOTHES"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLBOUNTY"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMPICKUPDLCCRATE1ST"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMSHOOTDOWNCOPHELI"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILL3ANDWINGTARACE"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMKILLSTREAKSDM"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMMOSTKILLSGANGHIDE"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMMOSTKILLSSURVIVE"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONDRIVE"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONNAV"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMREVENGEKILLSDM"), 50, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINAIRRACE"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINCUSTOMRACE"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINRACETOPOINTS"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINSEARACE"), 25, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBASEJMP"), 25, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_MP0_AWD_FMWINALLRACEMODES"), 1, 1);
				 STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMTATTOOALLBODYPARTS"), 1, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WANTED_LEVEL_TIME5STAR"), 2147483647, 1);
				 STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MP0_LONGEST_WHEELIE_DIST"), 1000, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HEIST_ACH_TRACKER"), -1, 1);
			 }
			 if (Menu::Option("最大零食")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_YUM_SNACKS"), 99999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_HEALTH_SNACKS"), 99999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_EPIC_SNACKS"), 99999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CIGARETTES_BOUGHT"), 99999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_OF_ORANGE_BOUGHT"), 99999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_OF_BOURGE_BOUGHT"), 99999999, 0);
			 }
			 if (Menu::Option("最大烟花")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_WHITE"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_WHITE"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_WHITE"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_WHITE"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_RED"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_RED"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_RED"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_RED"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_BLUE"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_BLUE"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_BLUE"), 999999, 0);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_BLUE"), 999999, 0);
			 }
			 if (Menu::Option("清晰的报告")) {
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_FRIENDLY"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HELPFUL"), 100, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_NAME"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_MOTTO"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_STATUS"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_EXPLOITS"), 0, 1);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, 1);
			 }

		}
		 break;
#pragma endregion
		 case teleportmapmodder:
		 {

			 Menu::Title("Teleport Locations");
			 Menu::Subtitle("LOCATIONS MAP MODDER");
			 if (Menu::Option("Load Map")) {
				 Features::LoadObjects(-173040310, -63.310, -807.672, 324.074, 10.115, -1.606, -39.057);
				 Features::LoadObjects(-173040310, -61.991, -809.437, 324.080, 10.240, -0.023, -47.198);
				 Features::LoadObjects(-173040310, -60.645, -811.082, 324.057, 10.133, 1.512, -55.734);
				 Features::LoadObjects(-173040310, -59.581, -813.104, 324.031, 10.165, -1.249, -64.289);
				 Features::LoadObjects(-173040310, -58.717, -815.180, 324.059, 10.195, 1.010, -76.890);
				 Features::LoadObjects(-173040310, -58.545, -817.588, 324.094, 10.165, -1.249, -88.689);
				 Features::LoadObjects(-173040310, -58.600, -820.030, 324.095, 10.202, -0.939, -100.716);
				 Features::LoadObjects(-173040310, -58.685, -822.631, 324.091, 10.240, -0.023, -111.198);
				 Features::LoadObjects(-173040310, -59.867, -824.503, 324.014, 10.087, 1.798, -121.359);
				 Features::LoadObjects(-173040310, -61.006, -826.811, 323.980, 10.240, -0.023, -129.198);
				 Features::LoadObjects(-173040310, -62.253, -828.803, 324.033, 10.033, 2.081, -140.982);
				 Features::LoadObjects(-173040310, -63.914, -830.848, 324.029, 10.244, 0.0, -149.200);
				 Features::LoadObjects(-173040310, -66.114, -832.423, 324.028, 10.240, -0.023, -155.198);
				 Features::LoadObjects(-173040310, -68.596, -833.791, 324.090, 10.240, -0.023, -163.598);
				 Features::LoadObjects(-173040310, -71.220, -834.365, 324.050, 10.244, 0.0, -174.400);
				 Features::LoadObjects(-173040310, -74.173, -834.563, 324.046, 10.240, -0.023, 172.803);
				 Features::LoadObjects(-173040310, -76.855, -834.062, 323.968, 10.240, -0.023, 162.002);
				 Features::LoadObjects(-173040310, -79.873, -833.314, 323.903, 10.244, 0.0, 153.600);
				 Features::LoadObjects(-173040310, -82.505, -832.156, 323.940, 10.224, -0.650, 142.058);
				 Features::LoadObjects(-173040310, -84.864, -830.536, 323.921, 10.232, 0.410, 134.363);
				 Features::LoadObjects(-173040310, -87.156, -828.847, 323.949, 10.195, -0.961, 126.886);
				 Features::LoadObjects(-173040310, -89.181, -826.946, 324.081, 10.172, 1.226, 114.691);
				 Features::LoadObjects(-173040310, -90.612, -824.327, 324.087, 10.240, -0.023, 106.402);
				 Features::LoadObjects(-173040310, -91.736, -821.541, 324.083, 10.244, 0.0, 97.600);
				 Features::LoadObjects(-173040310, -91.802, -818.927, 324.042, 10.244, 0.0, 86.799);
				 Features::LoadObjects(-173040310, -91.287, -816.063, 324.037, 10.244, 0.0, 75.199);
				 Features::LoadObjects(-173040310, -90.058, -813.289, 323.972, 10.244, 0.0, 63.199);
				 Features::LoadObjects(-173040310, -89.185, -810.593, 324.013, 10.244, 0.0, 54.799);
				 Features::LoadObjects(-173040310, -87.515, -808.001, 324.030, 10.240, -0.023, 42.801);
				 Features::LoadObjects(-173040310, -85.293, -806.048, 323.973, 10.244, 0.0, 34.399);
				 Features::LoadObjects(-173040310, -82.710, -804.429, 324.085, 10.240, -0.023, 21.601);
				 Features::LoadObjects(-173040310, -79.888, -803.569, 324.057, 10.240, -0.023, 9.601);
				 Features::LoadObjects(-173040310, -77.043, -803.021, 324.009, 10.244, 0.0, 1.199);
				 Features::LoadObjects(-173040310, -74.123, -803.101, 324.164, 10.240, -0.023, -8.799);
				 Features::LoadObjects(-173040310, -71.147, -803.314, 324.226, 10.244, 0.0, -17.201);
				 Features::LoadObjects(-173040310, -65.556, -806.089, 324.011, 10.188, -1.082, -31.905);
				 Features::LoadObjects(-173040310, -68.198, -804.730, 324.084, 10.180, -1.154, -25.498);
				 Features::LoadObjects(1212630005, -70.106, -812.107, 325.633, 0.0, 0.0, -32.001);
				 Features::LoadObjects(1212630005, -66.992, -815.072, 325.633, 0.0, 0.0, -61.601);
				 Features::LoadObjects(1212630005, -65.938, -819.004, 325.692, 0.0, 0.0, -89.201);
				 Features::LoadObjects(1212630005, -67.053, -822.961, 325.633, 0.0, 0.0, -120.001);
				 Features::LoadObjects(1212630005, -69.921, -826.093, 325.633, 0.0, 0.0, -147.601);
				 Features::LoadObjects(1212630005, -73.818, -810.980, 325.633, 0.0, 0.0, -8.001);
				 Features::LoadObjects(1212630005, -78.065, -810.927, 325.633, 0.0, 0.0, 17.198);
				 Features::LoadObjects(1212630005, -83.918, -817.211, 325.633, 0.0, 0.0, 75.998);
				 Features::LoadObjects(1212630005, -77.249, -826.769, 325.692, 0.0, 0.0, 158.400);
				 Features::LoadObjects(1212630005, -73.141, -827.029, 325.633, 0.0, 0.0, 179.998);
				 Features::LoadObjects(1212630005, -81.800, -813.259, 325.633, 0.0, 0.0, 48.400);
				 Features::LoadObjects(1212630005, -80.958, -824.657, 325.633, 0.0, 0.0, 144.400);
				 Features::LoadObjects(1212630005, -83.703, -821.398, 325.633, 0.0, 0.0, 113.200);
			 }
			 if (Menu::Option("Maze Bank")) {
				 Vector3 Coords;
				 Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f;
				 TPto(Coords);
			 }
		 }
		 break;
#pragma endregion
#pragma region Teleports
		 case teleports:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("传送选项");
			 Menu::Subtitle("LOCATIONS");
			 Menu::Option("传送到导航点", teleport_to_markerr);
			 Menu::MenuOption("创意地图", teleportmapmodder);
			 Menu::MenuOption("需要加载的地图", ipl);
			 if (Menu::Option("千年山")) {
				 Vector3 Coords;
				 Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
				 TPto(Coords);
			 }
			 if (Menu::Option("迷宫银行")) {
				 Vector3 Coords;
				 Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f;
				 TPto(Coords);
			 }
			 if (Menu::Option("军事基地")) {
				 Vector3 Coords;
				 Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f;
				 TPto(Coords);
			 }
			 if (Menu::Option("赞库多塔")) {
				 Vector3 Coords;
				 Coords.x = -2356.0940; Coords.y = 3248.645; Coords.z = 101.4505;
				 TPto(Coords);
			 }
			 if (Menu::Option("面具工厂")) {
				 Vector3 Coords;
				 Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87;
				 TPto(Coords);
			 }
			 if (Menu::Option("海关边检")) {
				 Vector3 Coords;
				 Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31;
				 TPto(Coords);
			 }
			 if (Menu::Option("军火仓库")) {
				 Vector3 Coords;
				 Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411;
				 TPto(Coords);
			 }
			 if (Menu::Option("国际机场")) {
				 Vector3 Coords;
				 Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f;
				 TPto(Coords);
			 }
			 if (Menu::Option("服装店")) {
				 Vector3 Coords;
				 Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00;
				 TPto(Coords);
			 }
			 if (Menu::Option("大瀑布")) {
				 Vector3 Coords;
				 Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f;
				 TPto(Coords);
			 }
			 if (Menu::Option("FBI")) {
				 Vector3 Coords;
				 Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f;
				 TPto(Coords);
			 }
			 if (Menu::Option("人类实验室")) {
				 Vector3 Coords;
				 Coords.x = 3617.231f; Coords.y = 3739.871f; Coords.z = 28.6901f;
				 TPto(Coords);
			 }
			 if (Menu::Option("管理与保养检查站")) {
				 Vector3 Coords;
				 Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294;
				 TPto(Coords);
			 }
			 if (Menu::Option("桑迪海岸机场")) {
				 Vector3 Coords;
				 Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f;
				 TPto(Coords);
			 }
		 }
		 break;

#pragma region Attach Options
		 case attachoptions:
		 {
			 
			 Menu::Title("附加选项");
			 Menu::Subtitle("ATTACH OPTIONS");
			 if (Menu::Option("金属板")) { Features::attachobjects2("p_oil_slick_01"); }
			 if (Menu::Option("电磁脉冲")) { Features::attachobjects2("hei_prop_heist_emp"); }
			 if (Menu::Option("橙色大球")) { Features::attachobjects2("prop_juicestand"); }
			 if (Menu::Option("野草")) { Features::attachobjects2("prop_weed_01"); }
			 if (Menu::Option("保险柜")) { Features::attachobjects2("p_v_43_safe_s"); }
			 if (Menu::Option("UFO")) { Features::attachobjects2("p_spinning_anus_s"); }
			 if (Menu::Option("坐便器")) { Features::attachobjects2("prop_ld_toilet_01"); }
			 if (Menu::Option("圣诞树")) { Features::attachobjects2("prop_xmas_tree_int"); }
			 if (Menu::Option("风力发电机")) { Features::attachobjects2("prop_windmill_01"); }
			 if (Menu::Option("雷达")) { Features::attachobjects2("prop_air_bigradar"); }
			 if (Menu::Option("异形卵")) { Features::attachobjects2("prop_alien_egg_01"); }
			 if (Menu::Option("卡塔纳")) { Features::attachobjects2("prop_cs_katana_01"); }
			 if (Menu::Option("拳击手套")) { Features::attachobjects2("prop_boxing_glove_01"); }
			 char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };

			 if (Menu::Option("清理所有附加")) {
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
#pragma region Misc Options
		 case miscoptions:
		 {

			 Menu::Title("其它设置");
			 Menu::Subtitle("MISC OPTIONS");
			 Menu::MenuOption("全套装备", OutfitOptions);
			 Menu::MenuOption("游戏异象", versionsoptions);
			 Menu::Bool("显示器 FPS", Features::DisplayFPS, [] { Features::featureDisplayFPS(Features::DisplayFPS); });
			 Menu::Bool("杀死街机角色", Features::killpedsbool);
			 Menu::Bool("引爆街机角色", Features::explodepedsbool);
			 Menu::Bool("引爆街机载具", Features::explodenearbyvehiclesbool);
			 Menu::Bool("删除街机汽车", Features::deletenearbyvehiclesbool);
		 }
		 break;
#pragma endregion
#pragma region Object Options
		 case objectoptions:
		 {
			 
			 Menu::Title("物体选项");
			 Menu::Subtitle("OBJECTS OPTIONS");
			 if (Menu::Option("物体生成"))
				 for (auto car : objs2) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
		 }
		 

		 
		 break;
#pragma endregion
#pragma region All Players
		 case allplayers:
		 {
			 
			 Menu::Title("所有玩家控制");
			 Menu::Subtitle("ALL PLAYERS OPTIONS");
			 Menu::Bool("ESP", Features::esper, [] {});
			 if (Menu::Option("删除所有人的武器")) {
					for (int i = 0; i < 32; i++)
				 {
					 if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
						 if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
						 {
							 Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							 if (!(Features::cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
							 {
								 WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), true);
							 }
						 }
					 }
				 }
			 }
			 if (Menu::Option("所有人持有全部武器")) {

				 for (int i = 0; i < 32; i++)
				 {
					 if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
						 Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
						 if (!(Features::cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
						 {
							 if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
							 {
								 uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
								 for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
									 WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), Weapons[i], 9999, 1);
								 }
							 }
						 }
					 }
				 }
			 }
			 if (Menu::Option("把所有人关在笼中")) {
				 Features::trapall();
			 }
			 if (Menu::Option("崩溃所有人")) {
				 {
					 {
						 for (int i = 0; i < 32; i++)
						 {



							 Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							 Hash crashall = GAMEPLAY::GET_HASH_KEY("v_proc2_temp");
							 STREAMING::REQUEST_MODEL(crashall);
							 while (!STREAMING::HAS_MODEL_LOADED(crashall)) WAIT(0);
							 if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
							 {
								 if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
								 {
									 Vector3 Coords;
									 Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
									 TPto(Coords);
									 Object crashall2 = OBJECT::CREATE_OBJECT(crashall, 0, 0, 0, true, true, false);
									 ENTITY::ATTACH_ENTITY_TO_ENTITY(crashall2, playerHandle, PED::GET_PED_BONE_INDEX(playerHandle, SKEL_Spine_Root), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
								 }
								 STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(crashall);

							 }
						 }
					 }
				 }
			 }
			 if (Menu::Option("所有人从车上踢下来")) { 
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
			 };
			 if (Menu::Option("炸死所有人")) {
				 for (int i = 0; i < 33; i++)
				 {
					 if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
					 {
						 Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
						 FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 100.f);
					 }
				 }
			 }

		 }
		 break;
#pragma endregion
#pragma region Player Menu
		 case playermenu:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("自我选项");
			 Menu::Subtitle("SELF OPTIONS");
			 Menu::MenuOption("防护措施", protectedmenu);
             Menu::MenuOption("角色变换", modelchanger);
			 Menu::MenuOption("动作选项", anim);
			 Menu::MenuOption("自身效果", PTFX);
			 Menu::Bool("自我无敌", Features::playerGodMode, [] { Features::GodMode(Features::playerGodMode); });
			 Menu::Bool("不被通缉", Features::neverwanted, [] { Features::NeverGetWanted(Features::neverwanted); });
			 Menu::Bool("脱离雷达", Features::orbool, [] { Features::OffRadar(Features::orbool); });
			 Menu::Bool("禁用电话", Features::phonedisable, [] { Features::disablephone(); });
			 //Menu::Bool("自我隐身", Features::playerinvisibility, [] { Features::Invisibility(Features::playerinvisibility); });
			 //Menu::Bool("无视存在", Features::playernoragdoll, [] { Features::NoRagdoll(Features::playernoragdoll); });
			 Menu::Bool("超级跳跃", Features::playersuperjump, [] { Features::SuperJump(Features::playersuperjump); });
			 Menu::Bool("快速奔跑", Features::fastrun, [] { Features::RunFast(Features::fastrun); });
			 Menu::Bool("加速游泳", Features::fastswim, [] { Features::SwimFast(Features::fastswim); });
			 Menu::Bool("城市超人", Features::superman, [] { Features::Superman(Features::superman); });
			 Menu::Bool("自由视角", Features::flybool, [] { Features::playerflyer(Features::flybool); });
			 Menu::Bool("高矮变换", Features::betiny, [] { Features::TinyPlayer(Features::betiny); });
			 Menu::Option("洗漱外观", [] { int Ped = PLAYER::PLAYER_PED_ID(); PED::CLEAR_PED_BLOOD_DAMAGE(Ped); PED::RESET_PED_VISIBLE_DAMAGE(Ped); });
			 if (Menu::Option("自取灭亡")) { ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0); }
			 
			 
			 

		 }
		 break;
		 case Credits:
		 {
			 Menu::Title("软件信息");
			 Menu::Subtitle("STATUS/INFORMATIONS");
			 Menu::Option("编程 : ~y~荒陌");
			 Menu::Option("状态 : ~g~未被检测到");
			 Menu::Option("GTA5.exe : ~g~v1.0.1737.1");
			 Menu::Option("支持线上版本 : ~g~1.48");
			 Menu::Option("程序版本: ~g~1.0.0");
			 Menu::Option("发布日期: ~g~Aug 03, 2019");
			 Menu::Option("~HUD_COLOUR_GOLD~俱乐部帐户:");
			 Menu::Option(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()));
		 }
		 break;
		 case CreditsInfor:
		 {
			 Menu::Title("参与人员");
			 Menu::Subtitle("CREDITS");
			 Menu::Option("~r~编程: ~y~荒陌");
		 }
		 break;
#pragma region Outfit Options
		 case OutfitOptions :
		 {
			 
			 Menu::Title("全副武装");
			 Menu::Subtitle("OUTFIT OPTIONS");
			 if (Menu::Option("随机变换")) { PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID()); }
			 if (Menu::Option("配套服装")) { PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true); }
			 Menu::MenuOption("自选服装", OutfitCreator);
			 
		 }
		 break;
#pragma region Outfit Creator
		 case OutfitCreator:
		 {
			 
			 Menu::Title("自选服装");
			 Menu::Subtitle("OUTFIT CREATOR");
			 Menu::Int("帽子", Face_, 0, 55); { PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, Face_, 0, 1); }
			 Menu::Int("眼镜", Glasses_, 0, 23); { PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, Glasses_, 0, 1); }
			 Menu::Int("耳饰", Ears_, 0, 3); { PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, Ears_, 0, 1); }
			 Menu::Int("胸部1", Torso_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, Torso_, 0, 1); }
			 Menu::Int("胸部2", Torso2_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, Torso2_, 0, 1); }
			 Menu::Int("腿部", Legs_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, Legs_, 0, 1); }
			 Menu::Int("手部", Hands_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, Hands_, 0, 1); }
			 Menu::Int("手表", Watches_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, Watches_, 0, 1); }
			 Menu::Int("特殊 1", Special1_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 7, Special1_, 0, 1); }
			 Menu::Int("特殊 2", Special2_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 8, Special2_, 0, 1); }
			 Menu::Int("特殊 3", Special3_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, Special3_, 0, 1); }
			 Menu::Int("其它", Texture_, 0, 50); { PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 10, Texture_, 0, 1); }
			 


		 }
		 break;
#pragma endregion
#pragma region Money Options
		 case moneyoptions:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("账目变更");
			 Menu::Subtitle("TRANSFER MONEY OPTIONS");
			if (Menu::Option("存入银行100万")) { 
						 Features::deposit(1000000);
			 }
			 if (Menu::Option("取走银行100万")) { 
				 Features::withdraw(1000000);
			 }
			 if (Menu::Option("存入银行1000万")) {
				 Features::deposit(10000000);
			 }
			 if (Menu::Option("取走银行1000万")) {
				 Features::withdraw(10000000);
			 }
			 if (Menu::Option("存入银行1个亿")) {
				 Features::deposit(100000000);
			 }
			 if (Menu::Option("取走银行一个亿")) {
				 Features::withdraw(100000000);
			 }
		 }
		 break;
#pragma endregion
#pragma region Model Changer
		 case modelchanger:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("角色变换");
			 Menu::Subtitle("MODEL OPTIONS");
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
#pragma region Model Options
		 case modelObjects:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("物体选项");
			 Menu::Subtitle("MODEL OPTIONS");
			 for (int i = 0; i < ARRAYSIZE(objs2); i++)
			 {
				 if (Menu::Option(objs2[i]))
				 {
					 DWORD model = GAMEPLAY::GET_HASH_KEY(objs2[i]);
					 STREAMING::REQUEST_MODEL(model);
					 while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					 Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
					 Object obj = (OBJECT::CREATE_OBJECT_NO_OFFSET(model, coords.x + 0.5, coords.y, coords.z, 1, 0, 0));
					 latestObj = obj;
					 Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
					 Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
					 ENTITY::SET_ENTITY_LOD_DIST(obj, 696969);
					 
				 }
			 }
		 }
		 break;
#pragma endregion
#pragma region Anim Changer
		 case anim:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("动作效果");
			 Menu::Subtitle("ANIMATIONS OPTIONS");
			 Menu::MenuOption("场景动作", senas);
			 if (Menu::Option("~r~停止 ~w~动作")) { Features::clearanim(); }
			 if (Menu::Option("给予性行为")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); }
			 if (Menu::Option("性行为受益者")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_a"); }
			 if (Menu::Option("脱衣舞表演")) { Features::doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
			 if (Menu::Option("钢管舞表演")) { Features::doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
			 if (Menu::Option("俯卧撑")) { Features::doAnimation("amb@world_human_push_ups@male@base", "base"); }
			 if (Menu::Option("仰卧起坐")) { Features::doAnimation("amb@world_human_sit_ups@male@base", "base"); }
			 if (Menu::Option("庆祝庆贺")) { Features::doAnimation("rcmfanatic1celebrate", "celebrate"); }
			 if (Menu::Option("触电死亡")) { Features::doAnimation("ragdoll@human", "electrocute"); }
			 if (Menu::Option("自取灭亡")) { Features::doAnimation("mp_suicide", "pistol"); }
			 if (Menu::Option("脱衣洗澡")) { Features::doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); }
		 }
		 break;
#pragma endregion
#pragma region sensa Changer
		 case senas:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("场景动作");
			 Menu::Subtitle("SCENARIOS OPTIONS");
			 if (Menu::Option("~r~停止 ~w~动作")) AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
			 if (Menu::Option("狗仔队")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PAPARAZZI", 0, true);
			 if (Menu::Option("毒贩")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
			 if (Menu::Option("喝咖啡")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_AA_COFFEE", 0, true);
			 if (Menu::Option("演奏乐器")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, true);
			 if (Menu::Option("弯屈摆动")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
			 if (Menu::Option("慢跑锻炼")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_JOG_STANDING", 0, true);
			 if (Menu::Option("双筒望远镜")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_BINOCULARS", 0, true);
			 if (Menu::Option("变形")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CLIPBOARD", 0, true);
			 if (Menu::Option("杠铃卧推")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
			 if (Menu::Option("仰卧起坐")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
			 if (Menu::Option("野外烧烤")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_BBQ", 0, true);
			 if (Menu::Option("超人归来")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUPERHERO", 0, true);
			 if (Menu::Option("钓鱼")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_STAND_FISHING", 0, true);
			 if (Menu::Option("安保状态")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
			 if (Menu::Option("吹风机")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
			 if (Menu::Option("电影震撼力")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
			 if (Menu::Option("观测")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_COP_IDLES", 0, true);
			 if (Menu::Option("饮酒")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRINKING", 0, true);
			 if (Menu::Option("高尔夫球运动员")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GOLF_PLAYER", 0, true);
			 if (Menu::Option("焊接")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_WELDING", 0, true);
			 if (Menu::Option("吸烟壶")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SMOKING_POT", 0, true);
			 if (Menu::Option("锤打")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HAMMERING", 0, true);
			 if (Menu::Option("网球")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
			 if (Menu::Option("钻孔")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CONST_DRILL", 0, true);
		 }
		 break;
#pragma endregion
#pragma region Remotes
		 case Remotes:
		 {
			 Menu::Title("远程控制");
			 Menu::Subtitle("REMOTE OPTIONS");

			 if (Menu::Option("观众信息显示")) {
				 uint64_t args[3] = { 111286607, player, 730884144 };
			 }
			 Menu::Bool("消息发布", Features::RemoteOffRadar[Features::Online::selectedPlayer], [] { Features::RemoteOff(Features::RemoteOffRadar[Features::Online::selectedPlayer]); });
			 Menu::Option("MORE SOON!!!");
		 }
		 break;
#pragma endregion
#pragma region Online Menu
		 case onlinemenu_playerlist:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("玩家列表");
			 Menu::Subtitle("PLAYER LIST");
			 Menu::MenuOption("所有玩家", allplayers);
			 for (int i = 0; i < 32; ++i) {
				 if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
					 Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
				 }
			 }
		 }
		 break;
		 case onlinemenu_selected:
		 {
			 
			 Menu::Subtitle("ONLINE PLAYERS");
			 Features::LoadInfoplayer(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
			 Menu::Title(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			 Menu::Option("传送到这个人", [] {Features::Online::TeleportToPlayer(Features::Online::selectedPlayer); });
			 Menu::MenuOption("控制选项", attachoptions);
			 Menu::MenuOption("粒子效果", PTFXO);
			 Menu::MenuOption("远程控制", Remotes);
			 Menu::Bool("玩家发言", Features::TalkingPlayers, [] { Features::featureTalkingPlayers(Features::TalkingPlayers); });
             Menu::Bool("喷泉试射", Features::playerwaterloop[Features::Online::selectedPlayer], [] { Features::WaterLoop(Features::playerwaterloop[Features::Online::selectedPlayer]); });
			 Menu::Bool("火灾附体", Features::playerfireloop[Features::Online::selectedPlayer], [] { Features::FireLoop(Features::playerfireloop[Features::Online::selectedPlayer]); });
			 Menu::Bool("原地冻结", Features::freezed[Features::Online::selectedPlayer], [] { Features::Freezer(Features::freezed[Features::Online::selectedPlayer]); });
			 Menu::Bool("冻结控制", Features::fuckedhandling[Features::Online::selectedPlayer], [] { Features::fuckhandling(Features::fuckedhandling[Features::Online::selectedPlayer]); });
			 Menu::Bool("抖动界面", Features::camshaker[Features::Online::selectedPlayer], [] { Features::shakecam(Features::camshaker[Features::Online::selectedPlayer]); });
			 if (Features::Online::selectedPlayer != PLAYER::PLAYER_ID()) { Menu::Bool("远程观看", Features::spectate[Features::Online::selectedPlayer], [] { Features::specter(Features::spectate[Features::Online::selectedPlayer]); }); }
			 Menu::Bool("循环爆炸", Features::exploder[Features::Online::selectedPlayer], [] { Features::explodeloop(Features::exploder[Features::Online::selectedPlayer]); });
			 Menu::Bool("货币降落", Features::savenewdrop2[Features::Online::selectedPlayer], [] {Features::dildmoney(Features::savenewdrop2[Features::Online::selectedPlayer]); });
			 if (Menu::Option("突发爆炸")) {
				 Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				 FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 1000.f);
			 }
			 if (Menu::Option("把他从车里踢出去")) { 
				 Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				 RequestControlOfEnt(playerPed);
				 AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
				 AI::CLEAR_PED_TASKS(playerPed);
				 AI::CLEAR_PED_SECONDARY_TASK(playerPed);
			 }
			 if (Menu::Option("克隆一个他"))
			 {
				 PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1, 1, 1);
			 }
			if ( Menu::Option("附加到他")) {
				if (player != PLAYER::PLAYER_PED_ID())
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
				}
			}
			if ( Menu::Option("脱离附加")) {
				ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
			}
			if (Menu::Option("把他关在笼中")) {
				Features::trapcage(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
			}
			if (Menu::Option("给他全部武器")) {
				 uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				 for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					 WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), Weapons[i], 9999, 1);
					 WAIT(10);
				 }
			 }
			 if (Menu::Option("删除他全部武器")) {
				 WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
			 }
			 
		 }
		 break;
#pragma endregion
#pragma region Recovery Menu
		 case recover:
		 {
			 
			 Menu::Title("强化功能");
			 Menu::Subtitle("RECOVERY OPTIONS");
			 Menu::MenuOption("金钱交易", moneystealth);
			 Menu::MenuOption("性能解锁", RecoveryStats);
			 if (Menu::Option("清除不良统计")) {
				 STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
				 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
			 }
			 if (Menu::Option("刷级到 88")) {
				 Features::SetRank(88);
			 }
			 if (Menu::Option("刷级到 100")) {
				 Features::SetRank(100);
			 }
			 if (Menu::Option("刷级到 120")) {
				 Features::SetRank(120);
			 }
			 if (Menu::Option("刷级到 200")) {
				 Features::SetRank(200);
			 }
			 if (Menu::Option("刷级到 420")) {
				 Features::SetRank(420);
			 }
			 if (Menu::Option("刷级到 500")) {
				 Features::SetRank(500);
			 }
			 if (Menu::Option("刷级到 600")) {
				 Features::SetRank(600);
			 }
			 if (Menu::Option("刷级到 700")) {
				 Features::SetRank(700);

			 }if (Menu::Option("刷级到 777")) {
				 Features::SetRank(777);
			 }
			 if (Menu::Option("刷级到 800")) {
				 Features::SetRank(800);
			 }
			 if (Menu::Option("刷级到 1000")) {
				 Features::SetRank(1000);
			 }
			 if (Menu::Option("刷级到 1337")) {
				 Features::SetRank(1337);
			 }
			 if (Menu::Option("刷级到 1500")) {
				 Features::SetRank(1500);
			 }
			 if (Menu::Option("刷级到 1800")) {
				 Features::SetRank(1800);
			 }
			 if (Menu::Option("刷级到 2000")) {
				 Features::SetRank(2000);
			 }
			 if (Menu::Option("刷级到 2300")) {
				 Features::SetRank(2300);
			 }
			 if (Menu::Option("刷级到 2500")) {
				 Features::SetRank(2500);
			 }
			 if (Menu::Option("刷级到 3000")) {
				 Features::SetRank(3000);
			 }
			 if (Menu::Option("刷级到 3300")) {
				 Features::SetRank(3300);
			 }
			 if (Menu::Option("刷级到 3500")) {
				 Features::SetRank(3500);
			 }
			 if (Menu::Option("刷级到 4000")) {
				 Features::SetRank(4000);
			 }
			 if (Menu::Option("刷级到 4500")) {
				 Features::SetRank(4500);
			 }
			 if (Menu::Option("刷级到 5000")) {
				 Features::SetRank(5000);
			 }
			 if (Menu::Option("刷级到 5500")) {
				 Features::SetRank(5500);
			 }
			 if (Menu::Option("刷级到 5500")) {
				 Features::SetRank(5500);
			 }
			 if (Menu::Option("刷级到 6000")) {
				 Features::SetRank(6000);
			 }
			 if (Menu::Option("刷级到 6500")) {
				 Features::SetRank(6500);
			 }
			 if (Menu::Option("刷级到 7000")) {
				 Features::SetRank(7000);
			 }
			 if (Menu::Option("刷级到 7500")) {
				 Features::SetRank(7500);
			 }
			 if (Menu::Option("刷级到 8000")) {
				 Features::SetRank(8000);
			 }
		 }
		 break;
#pragma endregion
#pragma region Settings Menu
		 case settingsmenu:
		 {
			 
			 Menu::Title("设置属性");
			 Menu::Subtitle("SETTINGS OPTIONS");
			 Menu::MenuOption("Master Menu", settingsmenu_theme);
			 if (Menu::Option("关闭 GTA V")) exit(0);
			 Menu::Bool("界面颜色", Features::RainbowMenu, [] { Features::rainbowmenu(Features::RainbowMenu); });
			 if (Menu::Option("界面右移 >")) { Menu::Settings::menuX = 0.85f; }
			 if (Menu::Option("界面左移 <")) { Menu::Settings::menuX = 0.15f; }
			 
			
			
			 
		 }
		 break;
		 case protectedmenu:
		 {
			
			 Menu::Title("保护选项");
			 Menu::Subtitle("PROTECTION OPTIONS");
			 Menu::Bool("滥发的电邮保护", Features::votes, [] { Features::kickvotes(); });
			 Menu::Option("MORE SOON!!!");
		 }
		 break;
		 case headerpic:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("标题图像");
			 Menu::Subtitle("HEADER IMAGES");
			 //if (Menu::Option("1")) { Features::headerlist(); }
		 }
		 break;
		 case protection:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("防护模式");
			 Menu::Subtitle("PROTECTIONS OPTIONS");
			 Menu::Bool("风险控制", risky, [] { Features::riskyOptins(risky); });
			 Menu::Bool("隐藏游戏名", stream, [] { Features::riskyOptins(risky); });
		 }
		 break;
		 case settingsmenu_theme:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Master Menu");
			 Menu::Subtitle("THEME MENU OPTIONS");
			 Menu::MenuOption("标题文本", settingsmenu_theme_titletext);
			 Menu::MenuOption("矩形结构", settingsmenu_theme_titlerect);
			 Menu::MenuOption("选项文本", settingsmenu_theme_optiontext);
			 Menu::MenuOption("选项结构", settingsmenu_theme_optionrect);
			 Menu::MenuOption("可视区域", settingsmenu_theme_scroller);
			 if (Menu::Int("滚动延迟", Menu::Settings::keyPressDelay2, 1, 200))
			 {
				 if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					 Menu::Settings::keyPressDelay2 = NumberKeyboard();
				 }
			 }
			 if (Menu::Int("延迟数值", Menu::Settings::keyPressDelay3, 1, 200))
			 {
				 if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					 Menu::Settings::keyPressDelay3 = NumberKeyboard();
				 }
			 }
			 
			 Menu::Option("加载主题", [] { Menu::Files::StyleSaver::LoadStyles(); });
			 Menu::Option("保存主题", [] { Menu::Files::StyleSaver::SaveStyles(); });
		 }
		 break;
		 case settingsmenu_theme_titletext:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("标题文本");
			 Menu::Subtitle("TITLE TEXT OPTIONS");
			 Menu::Int("Red", Menu::Settings::titleText.r, 0, 255);
			 Menu::Int("Green", Menu::Settings::titleText.g, 0, 255);
			 Menu::Int("Blue", Menu::Settings::titleText.b, 0, 255);
			 Menu::Int("Alpha", Menu::Settings::titleText.a, 0, 255);
			 Menu::Int("Font", Menu::Settings::titleText.f, 0, 7);
		 }
		 break; 
		 case settingsmenu_theme_titlerect:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("矩形结构");
			 Menu::Subtitle("TITLE RECT OPTIONS");
			 Menu::Int("Red", Menu::Settings::titleRect.r, 0, 255);
			 Menu::Int("Green", Menu::Settings::titleRect.g, 0, 255);
			 Menu::Int("Blue", Menu::Settings::titleRect.b, 0, 255);
			 Menu::Int("Alpha", Menu::Settings::titleRect.a, 0, 255);
		 }
		 break;
		 case settingsmenu_theme_optiontext:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("选项文本");
			 Menu::Subtitle("OPTIONS TEXT");
			 Menu::Int("Red", Menu::Settings::optionText.r, 0, 255);
			 Menu::Int("Green", Menu::Settings::optionText.g, 0, 255);
			 Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255);
			 Menu::Int("Alpha", Menu::Settings::optionText.a, 0, 255);
			 Menu::Int("Font", Menu::Settings::optionText.f, 0, 7);
		 }
		 break;
		 case settingsmenu_theme_optionrect:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("选项结构");
			 Menu::Subtitle("OPTIONS RECT");
			 Menu::Int("Red", Menu::Settings::optionRect.r, 0, 255);
			 Menu::Int("Green", Menu::Settings::optionRect.g, 0, 255);
			 Menu::Int("Blue", Menu::Settings::optionRect.b, 0, 255);
			 Menu::Int("Alpha", Menu::Settings::optionRect.a, 0, 255);
		 }
		 break;
		 case settingsmenu_theme_scroller:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("可视区域");
			 Menu::Subtitle("OPTIONS RECT");
			 Menu::Int("Red", Menu::Settings::scroller.r, 0, 255);
			 Menu::Int("Green", Menu::Settings::scroller.g, 0, 255);
			 Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255);
			 Menu::Int("Alpha", Menu::Settings::scroller.a, 0, 255);
		 }
		 break;
#pragma endregion

#pragma region Car Stuff
		 case vehicle:
		 {
			 
			 Menu::Title("载具选项");
			 Menu::Subtitle("载具选项");
			 Menu::MenuOption("Los Santos Customs", lsc);
             Menu::MenuOption("Plate Style", plateoptions);
			 Menu::Bool("时速表", Features::Speedometerbool);
			 if (Menu::Bool("车辆无敌", Features::cargodmodebool)) { Features::cargodmode(); }
			 Menu::Bool("发动机一直开启", Features::enginealwaysonbool, [] { Features::enginealwayson(Features::enginealwaysonbool); });
			 Menu::Bool("喇叭加速", Features::boostbool, [] { Features::carboost(Features::boostbool); });
			 Menu::Bool("车辆升天", Features::fcbool, [] { Features::FlyingCarLoop(Features::fcbool); });
			 Menu::Bool("彩虹车辆", Features::rlbool, [] { Features::HasPaintLoop(Features::rlbool); });
			 if (Menu::Option("修复车辆")) {
				 uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				 VEHICLE::SET_VEHICLE_FIXED(Vehicle);
				 VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
				 VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
			 }
			 if (Menu::Option("满改车辆")) {
				 Features::maxvehicle();
			 }
			 if (Menu::Option("修正车辆")) {
				 Features::flipup();
			 }
			 if (Menu::Option("打开车门")) {
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, true, false);
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, true, false);
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 2, true, false);
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 3, true, false);
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 4, true, false);
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 5, true, false);
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 6, true, false);
				 VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 7, true, false);
			 }
			 if (Menu::Option("关闭车门")) {
				 VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
			 }
			 Menu::Float("~t~加速度乘数", Features::accelerationmultiplier, 0, 3, 1); 
			 Menu::Float("~t~刹车乘数", Features::brakesmultiplier, 0, 3, 1); 
			 Menu::Float("~t~悬架高度", Features::suspensionseight, 0, 2, 1); 
			 
		 }
		 break;
#pragma endregion
#pragma region Plate Style
		 case plateoptions:
		 {
			 
			 Menu::Title("Plate Options");
			 Menu::Subtitle("PLATE OPTIONS");
			 Menu::MenuOption("Plate Style", platecolor);
			 if (Menu::Option("Custom Plate Text")) {
				 Ped playerPed = PLAYER::PLAYER_PED_ID();
				 if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) return;
				 GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "", "", "", "", "", "", 9);
				 while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				 if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT() || !PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) return;
				 VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(playerPed, false), GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());

				 }
			 
		 }
		 break;
		 case platecolor:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Plate Style");
			 Menu::Subtitle("PLATE STYLE OPTIONS");
			 if (Menu::Option("Blue On White Plate")) {
				 if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true))
				 {
					 VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0);

				 }
			 }
			 if (Menu::Option("Yellow On Black Plate")) {
				 if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true))
				 {
					 VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 1);

				 }
			 }
			 if (Menu::Option("Yellow On Blue Plate")) {
				 if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true))
				 {
					 VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 2);

				 }
			 }
			 if (Menu::Option("Blue On White 2 Plate")) {
				 if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true))
				 {
					 VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 3);

				 }
			 }
			 if (Menu::Option("Blue On White 3 Plate")) {
				 if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true))
				 {
					 VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 4);

				 }
			 }
			 if (Menu::Option("Yankton Plate")) {
				 if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true))
				 {
					 VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 5);

				 }
			 }

		 }
		 break;
#pragma endregion
#pragma region LSC Stuff
		 case lsc:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("LOS SANTOS CUSTOM");
			 Menu::Subtitle("LOS SANTOS CUSTOM");
			 Menu::MenuOption("Wheels Options", Wheels);
			 Menu::MenuOption("Neons Options", Neons);
			 Menu::MenuOption("Colours Options", Colours);
			 Menu::Int("Armor", Armor_, 0, 6); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);//this is for armor
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Armor_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 16, Armor_, 0);
			 }
			 Menu::Int("Brakes", Brakes_, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Brakes_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 12, Brakes_, 0);
			 }
			 Menu::Int("Transmission", Transmission_, 0, 4); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Brakes_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 12, Brakes_, 0);
			 }
			 if (Menu::Option("Turbo")) {
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 18, 0);
			 
			 }
			 Menu::Int("Bumpers", Bumpers_, 0, 3); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Bumpers_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 2, Bumpers_, 0);
			 }
			 Menu::Int("Hoods", Hoods_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Hoods_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 7, Hoods_, 0);
			 }
			 Menu::Int("Suspension", Suspension_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Suspension_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 15, Suspension_, 0);
			 }
			 Menu::Int("Spoiler", Spoilers_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Spoilers_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 0, Spoilers_, 0);
			 }
			 Menu::Int("SideSkirts", Skirts_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Skirts_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 3, Skirts_, 0);
			 }
			 Menu::Int("Exhaust", Exhaust_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Exhaust_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 4, Exhaust_, 0);
			 }
			 Menu::Int("Grill", Grill_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Grill_);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 6, Grill_, 0);
			 }
			 Menu::Int("Interior", Interior_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Interior_);
			 VEHICLE::REMOVE_VEHICLE_MOD(VehID, Interior_);
			 }
			 Menu::Int("Window Tint", Tint_, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_);
			 VEHICLE::SET_VEHICLE_WINDOW_TINT(VehID, Tint_);
			 }
			 Menu::Int("Horns", horns, 0, 5); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns);
			 VEHICLE::SET_VEHICLE_MOD(VehID, 14, horns, 0);
			 }
			 
		 }
		 break;
		 case Colours:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Colours Options");
			 Menu::Subtitle("COLOURS OPTIONS");
			 Menu::Int("Primary Color", Prim_, 0, 150); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			 VEHICLE::SET_VEHICLE_COLOURS(VehID, Prim_, Sec_);
			 }
			 Menu::Int("Secondary Color", Sec_, 0, 150); { int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			 VEHICLE::SET_VEHICLE_COLOURS(VehID, Prim_, Sec_);
			 }
			 
		 }
		 break;
		 case Wheels: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Wheels");
			 Menu::Subtitle("WHEELS OPTIONS");
			 Menu::MenuOption("Tuner", Tuner); //done
			 Menu::MenuOption("SUV", WheelsSUV); //done
			 Menu::MenuOption("Sport", SportWheels); //done
			 Menu::MenuOption("Offroad", OffroadWheels); //done
			 Menu::MenuOption("HighEnd", HighEnd); //done
			 Menu::MenuOption("Lowrider", LowriderWheels); //done
			 Menu::MenuOption("Muscle", MuscleWheels); //done
			 
			 
		 }
		 break;
		 case Neons: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Neons");
			 Menu::Subtitle("NEONS OPTIONS");
			if (Menu::Option("Enable Xenon")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 Features::ToggleXenon(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
			 }
			if (Menu::Option("Enable Neons"))  {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 0, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 2, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 3, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 4, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 5, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 6, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 7, 1);
			 }
			 if (Menu::Option("Red")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 0, 0);
			 }
			 if (Menu::Option("Green")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 255, 0);
			 }
			 if (Menu::Option("Blue")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 0, 255);
			 }
			 if (Menu::Option("Hot Pink")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 226, 35, 157);
			 }
			 if (Menu::Option("Yellow")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 244, 0);
			 }
			 if (Menu::Option("Orange")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 91, 0);
			 }
			 if (Menu::Option("Aqua")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 40, 255, 255);
			 }
			 if (Menu::Option("White")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 255, 255);
			 }
			 if (Menu::Option("Magenta")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 102, 0, 35);
			 }
			 if (Menu::Option("Purple")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 53, 0, 83);
			 }
			 if (Menu::Option("Dark Green")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 118, 0);
			 }
			 if (Menu::Option("Rose Red")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
				 VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 161, 0, 0);
			 }
		 }
		 break;
		 case MuscleWheels: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Muscle");
			 Menu::Subtitle("MUSCLE OPTIONS");
			 if (Menu::Option("Classic Five")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 0, 0);
			 }
			 if (Menu::Option("Dukes")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 1, 0);
			 }
			 if (Menu::Option("Muscle Freak")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 2, 0);
			 }
			 if (Menu::Option("Kracka")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 3, 0);
			 }
			 if (Menu::Option("Azreal")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 4, 0);
			 }
			 if (Menu::Option("Mecha")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 5, 0);
			 }
			 if (Menu::Option("Black Top")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 6, 0);
			 }
			 if (Menu::Option("Drag SPL")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 7, 0);
			 }
			 if (Menu::Option("Revolver")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 8, 0);
			 }
			 if (Menu::Option("Classic Rod")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 9, 0);
			 }
			 if (Menu::Option("Spooner")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 11, 0);
			 }
			 if (Menu::Option("Five Star")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 12, 0);
			 }
			 if (Menu::Option("Old School")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 13, 0);
			 }
			 if (Menu::Option("El Jefe")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 14, 0);
			 }
			 if (Menu::Option("Mercenary")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 1);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 17, 0);

			 }
		 }
		 break;
		 case LowriderWheels: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Lowrider");
			 Menu::Subtitle("LOWRIDER OPTIONS");
			 if (Menu::Option("Flare")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 0, 0);
			 }
			 if (Menu::Option("Wired")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 1, 0);
			 }
			 if (Menu::Option("Triple Golds")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 2, 0);
			 }
			 if (Menu::Option("Big Worm")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 3, 0);
			 }
			 if (Menu::Option("Seven Fives")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 4, 0);
			 }
			 if (Menu::Option("Split Six")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 5, 0);
			 }
			 if (Menu::Option("Fresh Mesh")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 6, 0);
			 }
			 if (Menu::Option("Lead Sled")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 7, 0);
			 }
			 if (Menu::Option("Turbine")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 8, 0);
			 }
			 if (Menu::Option("Super Fin")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 9, 0);
			 }
			 if (Menu::Option("Classic Rod")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 10, 0);
			 }
			 if (Menu::Option("Dollar")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 11, 0);
			 }
			 if (Menu::Option("Dukes")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 12, 0);
			 }
			 if (Menu::Option("Low Five")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 13, 0);
			 }
			 if (Menu::Option("Gooch")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 2);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 14, 0);

			 }
		 }
	     break;
		 case HighEnd: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("HighEnd");
			 Menu::Subtitle("HIGHEND OPTIONS");
			 if (Menu::Option("Shadow")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 0, 0);
			 }
			 if (Menu::Option("Hypher")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 1, 0);
			 }
			 if (Menu::Option("Blade")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 2, 0);
			 }
			 if (Menu::Option("Diamond")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 3, 0);
			 }
			 if (Menu::Option("Supa Gee")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 4, 0);
			 }
			 if (Menu::Option("Chromatic Z")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 5, 0);
			 }
			 if (Menu::Option("Obey RS")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 7, 0);
			 }
			 if (Menu::Option("GT Chrome")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 8, 0);
			 }
			 if (Menu::Option("Cheetah RR")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 9, 0);
			 }
			 if (Menu::Option("Solar")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 10, 0);
			 }
			 if (Menu::Option("Split Ten")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 11, 0);
			 }
			 if (Menu::Option("Dash VIP")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 12, 0);
			 }
			 if (Menu::Option("LozSpeed Ten")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 13, 0);
			 }
			 if (Menu::Option("Carbon Shadow")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 15, 0);
			 }
			 if (Menu::Option("Carbon S Racer")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 7);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 19, 0);
			 
			 }
		 }
		 break;
		 case WheelsSUV: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("SUV");
			 Menu::Subtitle("SUV OPTIONS");
			 if (Menu::Option("Benefactor")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 1, 0);
			 }
			 if (Menu::Option("Cosmo")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 2, 0);
			 }
			 if (Menu::Option("Royal Six")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 4, 0);
			 }
			 if (Menu::Option("Fagorme")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 5, 0);
			 }
			 if (Menu::Option("Deluxe")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 6, 0);
			 }
			 if (Menu::Option("Iced Out")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 7, 0);
			 }
			 if (Menu::Option("Cognoscenti")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 8, 0);
			 }
			 if (Menu::Option("Supernova")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 10, 0);
			 }
			 if (Menu::Option("Obey RS")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 11, 0);
			 }
			 if (Menu::Option("LozSpeed Baller")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 12, 0);
			 }
			 if (Menu::Option("Extravaganzo")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 13, 0);
			 }
			 if (Menu::Option("Split Six")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 14, 0);
			 }
			 if (Menu::Option("Empowered")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 15, 0);
			 }
			 if (Menu::Option("Sunrise")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 16, 0);
			 }
			 if (Menu::Option("Dash VIP")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 3);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 17, 0);
			 }
		 }
		break;
		 case OffroadWheels: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Offroad");
			 Menu::Subtitle("OFFROAD OPTIONS");
			 if (Menu::Option("Raider")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 0, 0);
			 }
			 if (Menu::Option("Mudslinger")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 1, 0);
			 }
			 if (Menu::Option("Nevis")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 2, 0);
			 }
			 if (Menu::Option("Cairngorm")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 3, 0);
			 }
			 if (Menu::Option("Amazon")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 4, 0);
			 }
			 if (Menu::Option("Challenger")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 5, 0);
			 }
			 if (Menu::Option("Dune Basher")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 6, 0);
			 }
			 if (Menu::Option("Five Star")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 7, 0);
			 }
			 if (Menu::Option("Rock Crawler")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 8, 0);
			 }
			 if (Menu::Option("Mil Spec Steelie")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 4);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 9, 0);
			 }
		 }
		 break;
		 case Tuner: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Tuner");
			 Menu::Subtitle("TUNER OPTIONS");
			 if (Menu::Option("Cosmo")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 0, 0);
			 }
			 if (Menu::Option("Super Mesh")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 1, 0);
			 }
			 if (Menu::Option("Driftmeister")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 4, 0);
			 }
			 if (Menu::Option("El Quatro")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 6, 0);
			 }
			 if (Menu::Option("Dubbed")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 7, 0);
			 }
			 if (Menu::Option("Slideways")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 9, 0);
			 }
			 if (Menu::Option("Countersteer")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 12, 0);
			 }
			 if (Menu::Option("Endo v.2 Dish")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 14, 0);
			 }
			 if (Menu::Option("Choku-Dori")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 16, 0);
			 }
			 if (Menu::Option("Chicane")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 17, 0);
			 }
			 if (Menu::Option("Saisoku")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 18, 0);
			 }
			 if (Menu::Option("Dished Eight")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 19, 0);
			 }
			 if (Menu::Option("Battle VIII")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 22, 0);
			 }
			 if (Menu::Option("Rally Master")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 5);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 23, 0);
			 }
		 }
		break;
		 case SportWheels: {
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Sport");
			 Menu::Subtitle("SPORT OPTIONS");
			 if (Menu::Option("Inferno")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 0, 0);
			 }
			 if (Menu::Option("Deep Five")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 1, 0);
			 }
			 if (Menu::Option("LozSpeed Mk. V")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 2, 0);
			 }
			 if (Menu::Option("Diamond Cut")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 3, 0);
			 }
			 if (Menu::Option("Feroci RR")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 5, 0);
			 }
			 if (Menu::Option("FiftyNine")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 6, 0);
			 }
			 if (Menu::Option("Synthetic Z")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 8, 0);
			 }
			 if (Menu::Option("Organic Type 0")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 9, 0);
			 }
			 if (Menu::Option("GT One")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 11, 0);
			 }
			 if (Menu::Option("S Racer")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 15, 0);
			 }
			 if (Menu::Option("Venum")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 16, 0);
			 }
			 if (Menu::Option("Cosmo")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 17, 0);
			 }
			 if (Menu::Option("Dash VIP")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 18, 0);
			 }
			 if (Menu::Option("Ice Kid")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 19, 0);
			 }
			 if (Menu::Option("Split Six")) {
				 int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				 VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				 VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 0);
				 VEHICLE::SET_VEHICLE_MOD(VehID, 23, 24, 0);
			 }
		 }
		 break;
#pragma endregion
#pragma region Car Spawn
		 case dlcvehicles: {

			 Menu::Title("Vehicle Spawner");
			 Menu::Subtitle("VEHICLE SPAWNER");
			 Menu::MenuOption("走私者运行 DLC 1.40", smugglers_run);
			 Menu::MenuOption("军火走私 DLC 1.41", Gunrunning);
			 Menu::MenuOption("世界末日抢劫 DLC 1.42", DoomsdayHeist);
			 Menu::MenuOption("运动系列 DLC 1.43", VelosesEstilos);
			 Menu::MenuOption("赌场 DLC 1.47", CasinoVehicles);
		 }
		 break;
#pragma endregion
#pragma region Car Spawn
		 case vehspawner: {
			 
			 Menu::Title("Vehicle Spawner");
			 Menu::Subtitle("VEHICLE SPAWNER");
			 Menu::MenuOption("车辆选项", vehicle);
			 Menu::MenuOption("DLC 车辆", dlcvehicles);
			 Menu::MenuOption("超级跑车", Super);
			 Menu::MenuOption("运动车辆", Sports);
			 Menu::MenuOption("经典运动", SportClassic);
			 Menu::MenuOption("越野车", Offroad);
			 Menu::MenuOption("轿车车辆", Sedans);
			 Menu::MenuOption("汽车车辆", Coupes);
			 Menu::MenuOption("肌肉车辆", Muscle);
			 Menu::MenuOption("船", Boats);
			 Menu::MenuOption("商业车辆", Commercial);
			 Menu::MenuOption("小型汽车", Compacts);
			 Menu::MenuOption("自行车", Cycles);
			 Menu::MenuOption("紧急车辆", Emergency);
			 Menu::MenuOption("直升机", Helicopters);
			 Menu::MenuOption("工业车辆", Industrial);
			 Menu::MenuOption("军事车辆", Military);
			 Menu::MenuOption("摩托车", Motorcycles);
			 Menu::MenuOption("飞机", Planes);
			 Menu::MenuOption("服务车辆", Service);
			 Menu::MenuOption("SUV", SUV);
			 Menu::MenuOption("拖车", Trailer);
			 Menu::MenuOption("火车", Trains);
			 Menu::MenuOption("公用车辆", Utility);
			 Menu::MenuOption("货车", Vans);
			 Menu::Bool("刷车进入车内", Features::spawnincar);
			 Menu::Bool("刷出最高等级", Features::spawnmaxed);
			 break;
		 case CasinoVehicles:
			 Menu::Title("Casino");
			 Menu::Subtitle("CASINO DLC 1.47");
			 for (auto car : DiamondDLC) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Super:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Super");
			 Menu::Subtitle("Category Super");
			 for (auto car : Super1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Sports:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Sports");
			 Menu::Subtitle("Category Sports");
			 for (auto car : Sports1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case SportClassic:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Sports Classic");
			 Menu::Subtitle("Category Sports Classic");
			 for (auto car : SportsClassics1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Offroad:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Offroad");
			 Menu::Subtitle("Category Offroad");
			 for (auto car : OffRoad1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Sedans:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Sedans");
			 Menu::Subtitle("Category Sedans");
			 for (auto car : Sedans1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Coupes:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Coupes");
			 Menu::Subtitle("Category Coupes");
			 for (auto car : Coupes1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Muscle:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Muscle");
			 Menu::Subtitle("Category Muscle");
			 for (auto car : Muscle1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Boats:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Boats");
			 Menu::Subtitle("Category Boats");
			 for (auto car : Boats1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Commercial:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Commercial");
			 Menu::Subtitle("Category Commercial");
			 for (auto car : Commercial1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Compacts:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Compacts");
			 Menu::Subtitle("Category Compacts");
			 for (auto car : Compacts1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Cycles:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Cycles");
			 Menu::Subtitle("Category Cycles");
			 for (auto car : Cycles1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Emergency:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Emergency");
			 Menu::Subtitle("Category Emergency");
			 for (auto car : Emergency1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Helicopters:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Helicopters");
			 Menu::Subtitle("Category Helicopters");
			 for (auto car : Helicopters1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Industrial:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Industrial");
			 Menu::Subtitle("Category Industrial");
			 for (auto car : Industrial1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Military:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Military");
			 Menu::Subtitle("Category Military");
			 for (auto car : Military1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Motorcycles:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Motorcycles");
			 Menu::Subtitle("Category Motorcycles");
			 for (auto car : Motorcycles1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Planes:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Planes");
			 Menu::Subtitle("Category Planes");
			 for (auto car : Planes1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Service:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Service");
			 Menu::Subtitle("Category Service");
			 for (auto car : Service1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case SUV:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("SUV");
			 Menu::Subtitle("Category SUV");
			 for (auto car : SUVs1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Trailer:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Trailer");
			 Menu::Subtitle("Category Trailer");
			 for (auto car : Trailer1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Trains:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Trains");
			 Menu::Subtitle("Category Trains");
			 for (auto car : Trains1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Utility:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Utility");
			 Menu::Subtitle("Category Utility");
			 for (auto car : Utility1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Vans:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Vans");
			 Menu::Subtitle("Category Vans");
			 for (auto car : Vans1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case smugglers_run:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Smugglers Run");
			 Menu::Subtitle("Category Smugglers Run");
			 for (auto car : smugglers1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 case Gunrunning:
			 //Menu::DRAW_TEXTURE("shopui_title_clubhousemod", "shopui_title_clubhousemod", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Gunrunning");
			 Menu::Subtitle("Category Gunrunning");
			 for (auto car : Gunrunning1) { Menu::Option(car, [car] { Features::spawn_vehicle(car); }); }
			 break;
		 }
		 case DoomsdayHeist:
			 Menu::Title("Doomsday");
			 Menu::Subtitle("Category Doomsday");
			 for (auto car : Doomsday) { Menu::Option(car, [car] { Features::spawn_vehicle(car); });
			 }
			 break;
		 case VelosesEstilos:
			 Menu::Title("SA Sport Series");
			 Menu::Subtitle("Category SA Sport Series");
			 for (auto car : SportSeries) {
				 Menu::Option(car, [car] { Features::spawn_vehicle(car); });
			 }
			 break;
#pragma endregion
#pragma region Force Options
		 case forcean:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Force Animation");
			 Menu::Subtitle("FORCE ANIMATIONS");
			 if (Menu::Option("~r~Stop ~w~Animation")) { AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)); }
			 if (Menu::Option("Sex Receiver")) { Features::animatePlayer(Features::Online::selectedPlayer, "rcmpaparazzo_2", "shag_loop_poppy"); }
			 if (Menu::Option("Sex Giver")) { Features::animatePlayer(Features::Online::selectedPlayer, "rcmpaparazzo_2", "shag_loop_a"); }
			 if (Menu::Option("Stripper Dance")) { Features::animatePlayer(Features::Online::selectedPlayer, "mini@strip_club@private_dance@part1", "priv_dance_p1"); }
			 if (Menu::Option("Pole Dance")) { Features::animatePlayer(Features::Online::selectedPlayer, "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
			 if (Menu::Option("Push Ups")) { Features::animatePlayer(Features::Online::selectedPlayer, "amb@world_human_push_ups@male@base", "base"); }
			 if (Menu::Option("Sit Ups")) { Features::animatePlayer(Features::Online::selectedPlayer, "amb@world_human_sit_ups@male@base", "base"); }
			 if (Menu::Option("Celebrate")) { Features::animatePlayer(Features::Online::selectedPlayer, "rcmfanatic1celebrate", "celebrate"); }
			 if (Menu::Option("Electrocution")) { Features::animatePlayer(Features::Online::selectedPlayer, "ragdoll@human", "electrocute"); }
			 if (Menu::Option("Suicide")) { Features::animatePlayer(Features::Online::selectedPlayer, "mp_suicide", "pistol"); }
			 if (Menu::Option("Showering")) { Features::animatePlayer(Features::Online::selectedPlayer, "mp_safehouseshower@male@", "male_shower_idle_b"); }
			
		 }
		 break;
#pragma endregion
#pragma region Effect Options
		 case PTFX:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Effects Options");
			 Menu::Subtitle("EFFECTS OPTIONS");
			 //Menu::Bool("Looped", Features::PTLoopedO[PLAYER::PLAYER_ID()]);
			 if (Menu::Option("Clown Appears"))Features::PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
			 if (Menu::Option("Firework 1"))Features::PTFXCALL("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst");
			 if (Menu::Option("Firework 2"))Features::PTFXCALL("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw");
			 if (Menu::Option("Firework 3"))Features::PTFXCALL("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw");
			 if (Menu::Option("Banknotes"))Features::PTFXCALL("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes");
			 if (Menu::Option("Truck Crash"))Features::PTFXCALL("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash");
			 if (Menu::Option("Alien 1"))Features::PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate");
			 if (Menu::Option("Alien 2"))Features::PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport");
			 if (Menu::Option("Electric Box"))Features::PTFXCALL("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
			 if (Menu::Option("Water Splash"))Features::PTFXCALL("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
			 if (Menu::Option("Bubbles"))Features::PTFXCALL("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles");
			 if (Menu::Option("Blood Entry"))Features::PTFXCALL("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry");
			 if (Menu::Option("Sniper Impact"))Features::PTFXCALL("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
			 if (Menu::Option("Dirt Throw"))Features::PTFXCALL("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
			 if (Menu::Option("Blood Stab"))Features::PTFXCALL("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
			 if (Menu::Option("Ped Sliced"))Features::PTFXCALL("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
			 if (Menu::Option("Camera"))Features::PTFXCALL("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
			 if (Menu::Option("Meth Smoke"))Features::PTFXCALL("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
			 if (Menu::Option("Burial Dirt"))Features::PTFXCALL("scr_reburials", "scr_reburials", "scr_burial_dirt");

		 }
		 break;
#pragma endregion
#pragma region Effect Online Options
		 case PTFXO:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Effects Options");
			 Menu::Subtitle("EFFECTS OPTIONS");
			 Menu::Bool("Looped", Features::PTLoopedO[Features::Online::selectedPlayer]);
			 if (Menu::Option("Clown Appears"))Features::PTFXCALLO("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears",Features::Online::selectedPlayer);
			 if (Menu::Option("Firework 1"))Features::PTFXCALLO("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", Features::Online::selectedPlayer);
			 if (Menu::Option("Firework 2"))Features::PTFXCALLO("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw", Features::Online::selectedPlayer);
			 if (Menu::Option("Firework 3"))Features::PTFXCALLO("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw", Features::Online::selectedPlayer);
			 if (Menu::Option("Banknotes"))Features::PTFXCALLO("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes", Features::Online::selectedPlayer);
			 if (Menu::Option("Truck Crash"))Features::PTFXCALLO("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash", Features::Online::selectedPlayer);
			 if (Menu::Option("Alien 1"))Features::PTFXCALLO("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", Features::Online::selectedPlayer);
			 if (Menu::Option("Alien 2"))Features::PTFXCALLO("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", Features::Online::selectedPlayer);
			 if (Menu::Option("Electric Box"))Features::PTFXCALLO("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", Features::Online::selectedPlayer);
			 if (Menu::Option("Water Splash"))Features::PTFXCALLO("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", Features::Online::selectedPlayer);
			 if (Menu::Option("Bubbles"))Features::PTFXCALLO("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles", Features::Online::selectedPlayer);
			 if (Menu::Option("Blood Entry"))Features::PTFXCALLO("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", Features::Online::selectedPlayer);
			 if (Menu::Option("Sniper Impact"))Features::PTFXCALLO("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact", Features::Online::selectedPlayer);
			 if (Menu::Option("Dirt Throw"))Features::PTFXCALLO("core_snow", "core_snow", "cs_mich1_spade_dirt_throw", Features::Online::selectedPlayer);
			 if (Menu::Option("Blood Stab"))Features::PTFXCALLO("scr_michael2", "scr_michael2", "scr_mich2_blood_stab", Features::Online::selectedPlayer);
			 if (Menu::Option("Ped Sliced"))Features::PTFXCALLO("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced", Features::Online::selectedPlayer);
			 if (Menu::Option("Camera"))Features::PTFXCALLO("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera", Features::Online::selectedPlayer);
			 if (Menu::Option("Meth Smoke"))Features::PTFXCALLO("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", Features::Online::selectedPlayer);
			 if (Menu::Option("Burial Dirt"))Features::PTFXCALLO("scr_reburials", "scr_reburials", "scr_burial_dirt", Features::Online::selectedPlayer);


		 }
		 break;
#pragma endregion
#pragma region Force all Options
		 case forceanall:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("Force All Animation");
			 Menu::Subtitle("FORCE ALL ANIMATIONS");
			 if (Menu::Option("Stop Animation")) { Features::clearanimateallPlayer(); }
			 if (Menu::Option("Sex Receiver")) { Features::animateallPlayer("rcmpaparazzo_2", "shag_loop_poppy"); }
			 if (Menu::Option("Sex Giver")) { Features::animateallPlayer("rcmpaparazzo_2", "shag_loop_a"); }
			 if (Menu::Option("Stripper Dance")) { Features::animateallPlayer("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
			 if (Menu::Option("Pole Dance")) { Features::animateallPlayer("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
			 if (Menu::Option("Push Ups")) { Features::animateallPlayer("amb@world_human_push_ups@male@base", "base"); }
			 if (Menu::Option("Sit Ups")) { Features::animateallPlayer("amb@world_human_sit_ups@male@base", "base"); }
			 if (Menu::Option("Celebrate")) { Features::animateallPlayer("rcmfanatic1celebrate", "celebrate"); }
			 if (Menu::Option("Electrocution")) { Features::animateallPlayer("ragdoll@human", "electrocute"); }
			 if (Menu::Option("Suicide")) { Features::animateallPlayer("mp_suicide", "pistol"); }
			 if (Menu::Option("Showering")) { Features::animateallPlayer("mp_safehouseshower@male@", "male_shower_idle_b"); }

		 }
		 break;
#pragma endregion
#pragma region ipl all Options
		 case ipl:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("IPLs");
			 Menu::Subtitle("IPLS MAPS OPTIONS");
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
				 Coords.x = 3360.19f; Coords.y = -4849.67f; Coords.z = 111.8f;
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
#pragma region TP other
		 case tpother:
		 {
			 //Menu::DRAW_TEXTURE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", titlebox, 0.0800f, 0.21f, 0.090f, 0, 255, 255, 255, 255);
			 Menu::Title("传送选项");
			 Menu::Subtitle("TELEPORT OPTIONS");
			 /*if (Menu::Option("Teleport to Me")) {

				 int Me = PLAYER::PLAYER_PED_ID();
				 Vector3 MyPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Me, 0.0, 0.0, 0.0);
				 int selectedPed = Features::Online::selectedPlayer;
				 Features::teleporttocoords(selectedPed, MyPosition);

			 }*/
			 if (Menu::Option("传送到附近车上")) {
				 Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				 for (int i = -1; i < 16; i++)
				 {
					 if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i))
					 {
						 PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, i);
					 }
				 }
			 };
			 Menu::MenuOption("显示位置", teleportso);
		 
		 }
		 break;
#pragma endregion
		}
		Menu::End();
		WAIT(0);
	}
}

void ScriptMain() {
	srand(GetTickCount64());

	main();
}

