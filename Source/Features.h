#pragma once

namespace Features {
	void UpdateLoop();
	
	void TPtoWaypoint();

	void riskyOptins(bool toggle);

	extern int TimePD; 


	extern int Levels[8000];

	extern int ExploCh;

	void Freezer(Player target);
	extern bool RainbowMenu;
	void rainbowmenu(bool toggle);
	
	extern bool freezed[35];
	
	extern bool expmeel;
	extern bool fireammo;
	extern bool expammo;
	extern bool rbgun;

	/*extern bool stealth50k;
	extern bool stealth12m;
	extern bool stealth15m;
	extern bool stealth10m;
	extern bool stealth600k;
	extern bool stealth120k;
	extern bool stealth250k;
	extern bool stealth90m;
	extern bool stealth2b;
	extern bool remover;*/
	extern bool stealth2BB;
	extern bool stealth2BC;
	
	//Vehicle spawn_vehicle(char* toSpawn);
	
	//void spawn_vehicle2(char* toSpawn, Vector3 ourCoords);
	
	extern bool hasXenon;
	extern bool hasNeons;
	void ToggleXenon(int VehID);
	extern bool dropmoney2k;
	
	void ToggleNeons(int VehID);

	void BypassOnlineVehicleKick();

	void deathoffradar(bool toggle);

	void Offradarlester();

	void StealthCash4Loop();

	void resetStealth();

	void SET_PLAYER_NAME(const std::string & name);
	
	

	
	

	void spawn_vehicle(char* toSpawn);
	
	//void spawn_vehicle2(char * toSpawn);
	void teleport_to_coords(Entity e, Vector3 coords);
    extern bool Forcefield;
	
	
	

	void OnlinePlayerInfo(char * playerName, Player p);

	void Expmeels(bool toggle);
	void Fireammos(bool toggle);
	void Expammos(bool toggle);
	void RBGuner(bool toggle);

	extern int number;
	void tester(int i);

	Vehicle SpawnVehicle(char* modelg, Vector3 coords, bool tpinto, float heading);

	bool cstrcmp(const char* s1, const char* s2);

	extern bool neverwanted;
	void NeverGetWanted(bool toggle);
	void RequestControlOfid(DWORD netid);
	extern bool fastrun;
	extern bool fastswim;
	void RunFast(bool toggle);
	extern bool FireManMode;
	extern bool DisplayFPS;
	void featureDisplayFPS(bool toggle);
	void FireManModeLoop(bool toggle);
	extern bool GhostRider;
	void featureGhostRider(bool toggle);

	
	
	
	extern bool FPS;
	extern bool TalkingPlayers;
	
	void featureTalkingPlayers(bool toggle);
	void displayFPS(bool toggle);
	void RainMoney(bool toggle);
	extern bool moneyrain2k;
	void SwimFast(bool toggle);
	extern bool osk;
	extern bool superman;
	void OSKR(bool toggle);
	void Superman(bool toggle);

	void SetRank(int rpvalue);
	extern bool shootcash;
	extern bool AttachDetach[35];
	void PTFXCALLO(char *call1, char *call2, char *name, Player target);
	extern bool offradardeath;
	extern bool lesteroff;
	extern bool phonedisable;
	extern bool playerGodMode;
	extern bool newstealth;
	void GodMode(bool toggle);
	extern bool loop_RainbowBoxes;
	extern bool playersuperjump;
	void SuperJump(bool toggle);

	extern bool playeraimbot;
	


	extern bool playerinvisibility;
	void Invisibility(bool toggle);

	extern bool playertenkped;
	void TenKPedMoney(bool toggle);

	extern bool playerfireloop[35];
	void FireLoop(Player target);

	extern bool playerwaterloop[35];
	void WaterLoop(Player target);

	extern bool RemoteOffRadar[35];
	void RemoteOff(Player target);

	extern bool playernoragdoll;
	void NoRagdoll(bool toggle);

	extern int playerWantedLevel;
	void ChangeWanted(int level);
	int GetWanted(Player player);

	void StealthDrop(int amount);

	void StealthDrop2(int amount);

	

	extern bool savenewdrop;
	void cashdrop(bool toggle);

	extern bool savenewdrop2[35];
	void cashdrop2(Player target);

	void disablephone();

	
	extern bool StealthLooptoggle2;
	void StealthLoop2(bool toggle);

	extern int attachobj[100];
	extern int nuattach;
	void attachobjects2(char* object);

	void DeleteEntity(int Handle);

	void animatePlayer(Player target, char* dict, char* anim);
	void animateallPlayer(char* dict, char* anim);
	void clearanimateallPlayer();

	extern bool boostbool;
	void carboost(bool toggle);

	extern bool dowbool;
	void DriveOnWater(bool toggle);

	extern bool fcbool;
	void FlyingCarLoop(bool toggle);

	extern bool infammo;
	void noreloadv(bool toggle);

	extern bool orbool;
	void OffRadar(bool toggle);

	extern bool rlbool;
	void HasPaintLoop(bool toggle);

	extern bool animatednum;
	void numbani(bool toggle);

	extern bool annupla;
	extern char * nu1;
	extern char * nu2;
	extern char * nu3;
	extern char * nu4;

	

	extern int TimePD;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	void LoadInfoplayer(char* playerName, Player p);
		extern int l;
		extern int l1;
		extern int l2;
		extern int l3;
		extern int l4;
		extern int l5;
		extern int l6;

	void teleporttocoords(Player player, Vector3 target);
	
	
	extern bool stealth50k;
	extern bool stealth12m;
	extern bool stealth15m;
	extern bool stealth10m;
	extern bool stealth600k;
	void Stealth(bool toggle);

	void patchEvent(eRockstarEvent e, bool b);
	void defuseEvent(eRockstarEvent e, bool toggle);
	extern bool bypass;
	extern bool votes;
	
	extern bool att;
	
	void WEATHERtacks();
	void WANTEDLEVEL();

	void WANTEDLEVELL();
	
	extern bool WANTED;
	extern bool WEATHER;
	extern bool explosion;
	void moneyBypass();
	
	extern bool profire;
	void antiexplosion();
	void antifire();
	void remoweapons();
	
	extern bool revweapons;
	
	extern bool remote;
	
	extern bool report;
	void inforemote();
	void reattacks();
	
	void kickvotes();

	void antiattacks();

	
	extern bool WANTED_LEVEL;

	
	extern bool RAGDOLL;
	
	extern bool TAUNT;
	
	extern bool NETWORK;
	
	extern bool NETWORKCRC;
	void REQUESTEVENT();
	void PLAYERTAUNT();
	void INCREMENT();
	void NETWORK_CRC();
	void LoadObjects(int Hash, float x, float y, float z, float Pitch, float Roll, float Yaw);
	
	extern bool dropmoney;
	void TeleportMazeBank();
	void MazeBankobjs(int);
	void Airport(int);

	void PlaceObject(Hash ObjHash, float X, float Y, float Z, float Pitch, float Roll, float Yaw, bool Presistant);
	
	void moneydrop(bool toggle);
	void teleportallcoords(Vector3 target);
	void ramWithVeh(Player target);
	void doAnimation(char* anim, char* animid);
	extern bool stealth2500k;
	extern bool flybool;
	void playerflyer(bool toggle);
	extern bool controler;


	void RequestControlOfid(Entity netid);

	void RequestingControl(Entity e);
	
	void playAnimationPlayer(Player player, bool loop, char * dict, char * anim);

	extern bool cargodmodebool;
	void cargodmode();
	extern bool enginealwaysonbool;
	void enginealwayson(bool toggle);
	void flipup();
	void maxvehicle();

	extern bool fuckedhandling[32];
	void fuckhandling(Player player);

	extern bool camshaker[32];
	void shakecam(Player target);

	extern bool exploder[32];
	void explodeloop(Player target);

	extern bool nightvisionbool;
	void nightvision(bool toggle);
	extern bool blackvisionbool;
	void blackvision(bool toggle);
	extern bool heatvisionbool;
	void heatvision(bool toggle);
	void deposit(long amount);
	void withdraw(long amount);

	void animation(char* anim, char* dict);
		void clearanim();

		extern bool esper;
		void esp(Player target);

		void teleportallcoordsns(Vector3 target);

		void SpoofName(std::string name);

		

		void clearbala();

		void TinyPlayer(bool toggle);
		void changeplate();
		void trapcage(Ped ped);
		void trapall();

		extern bool betiny;
		extern bool spectate[32];
		void specter(Player target);
		extern float accelerationmultiplier;
		extern float brakesmultiplier;
		extern float suspensionseight;
		extern float accelerationfloat;
		extern float brakeforcefloat;
		extern float tractionfloat;
		extern float deformfloat;
		extern float upshiftfloat;
		extern float suspensionfloat;
		void updatePhysics();
		void acceleration();
		void brakeforce();
		void traction();
		void deform();
		void upshift();
		void suspension();
		extern bool vehiclegravitybool;
		void vehiclegravity();
		extern bool killpedsbool;
		void killpeds();

		void PTFXCALL(char *call1, char *call2, char *name);
		extern bool Speedometerbool;
		void Speedometer(bool toggle);

		void SetMultipliers();
		extern bool PTLoopedO[35];
		void PTLopperO(Player target);

		extern bool PTLooped;
		
		void StealthRP(Player player);
		void StealthDropende(Player player);
		extern int reamount;
		extern bool StealthLooptoggler[35];
		void StealthLoopre(Player player);
		extern std::string name;
		extern std::string pw;
		extern bool StealthLooptogglerall;
		void StealthLoopreall();

		extern bool rapidfirer;
		void rapidmaker();
		extern bool WeaponFirework;
		void featureWeaponFirework(bool toogle);
		extern bool WeaponRPG;
		void featureWeaponRPG(bool toogle);
		extern bool FakeBags;
		void featureFakeBags(bool toogle);
		extern bool TeleportGun;
		void featureTeleportGun(bool toogle);
		extern bool RhinoGun;
		void featureRhinoGun(bool toogle);
		extern bool PantoGun;
		void featurePantoGun(bool toogle);
		extern int time;
		extern bool explodepedsbool;
		void explodepeds();
		extern bool explodepedsbool;
		void explodepeds();
		extern bool explodenearbyvehiclesbool;
		void explodenearbyvehicles();
		extern bool deletenearbyvehiclesbool;
		void deletenearbyvehicles();

		extern int amount;
		extern int amount5;
		extern int amount6;
		extern int amount2;
		extern int amount3;
		extern bool banked;
		extern bool giver;
		void StealthDropinte();
		extern bool moneydropp;
		void dildomoneylocal(bool toogle);
		extern bool moneydropp2k;
		void dildmoney(bool toogle);

		extern bool spawnincar;
		extern bool spawnmaxed;

		extern bool nStealthLooptogglerall;
		void nStealthLoopreall();
		extern bool nStealthLooptoggler[35];
		void nStealthLoopre(Player player);
		
	
	namespace Online {
		extern int selectedPlayer;
		void TeleportToPlayer(Player player);
		
	}
}


