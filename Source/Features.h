#pragma once

namespace Features {

	void UpdateLoop();

	void BypassOnlineVehicleKick(Vehicle vehicle);

	extern bool Godmode;
	void godmode(bool toggle);

	extern bool Ghostmode;
	void ghostmode(bool toggle);

	extern bool Superjump;
	void superjump(bool toggle);

	extern bool FastRun;
	void fastRun(bool toggle);

	extern bool NoRagdoll;
	void noRagdoll(bool toggle);

	extern bool ExtremeRun;
	void extremeRun(bool toggle);

	extern bool Neverwanted;
	void neverwanted(bool toggle);

	extern bool LoopKill;
	void loopKill(bool toggle);

	extern bool ShakeLobby;
	void shakeLobby(bool toggle);

	extern bool Crash;
	void crash(bool toggle);

	extern bool FreezeA;
	void freeze(bool toggle);

	extern bool AntiFx;
	void antiFx(bool toggle);

	extern bool AntiCrash;
	void antiCrash(bool toggle);

	extern bool Stealtha;
	void stealtha(bool toggle);

	extern bool Stealthb;
	void stealthb(bool toggle);

	extern bool Stealthc;
	void stealthc(bool toggle);

	extern bool Stealthd;
	void stealthd(bool toggle);

	extern bool Stealthe;
	void stealthe(bool toggle);

	extern bool camshaker [32];
	void shakecam(Player target);

	extern bool exploder[32];
	void explodeloop(Player target);

	extern bool flybool;

	void playerflyer(bool toggle);

	extern bool TinyPlayer;
	void tinyPlayer(bool toggle);

	extern bool Free;
	void Freee(bool toggle);

	extern bool 	featureWalk;
	void 	featureWalkk(bool toggle);

	
	void trapcage(Ped ped);

	extern bool OffRadar;
	void offRadar(bool toggle);

	void LoadInfoplayer(char * playerName, Player p);

	void SetRank(int rpvalue);

	extern bool Trigger;

	void TriggerAim(bool toggle);

	extern bool ShootDump;

	extern bool ShootBuz;

	void RBGuner(bool toggle);

	bool cstrcmp(const char * s1, const char * s2);

	extern bool ShootWeaponT;

	extern bool ShootHydra;

	extern bool rainbowmenu;

	void Rainbowmenu(bool toggle);

	void spawn_vehicle(char * toSpawn);

	void spawn_vehicle2(char * toSpawn, Vector3 ourCoords);

	extern bool spectate[32];
	void specter(Player target);

	extern bool Gravity; 
	void GravityGun(bool toggle);

	void attachobjects2(char * object);

	extern int TimePD6;

	extern int TimePD2;

	extern bool para;

	extern bool ShootR; 
	extern bool ShootT;
	extern bool ShootTankR;
	extern bool ShootBall; 
	extern bool ShootMini;
	void ShootMiniGun(bool toggle);
	void ShootBalls(bool toggle);
	void ShootTankRounds(bool toggle);
	void ShootTanks(bool toggle);
	void ShootRocket(bool toggle);

	extern bool boostbool;
	void carboost(bool toggle);

	extern bool dowbool;
	void DriveOnWater(bool toggle);

	extern bool fcbool;
	void FlyingCarLoop(bool toggle);

	extern bool enginealwaysonbool;
	void enginealwayson(bool toggle);

	void flipup();

	void maxvehicle();

	
	extern bool rbgun;


	extern bool Drift;
	void DriftMode(bool toggle);

	extern bool Rainb;
	void Rainbow(bool toggle);

	extern bool Rneon;
	void RainbowNeon(bool toggle);

	void doAnimation(char * anim, char * animid);

	void clearanim();

	void PTFXCALLO(char * call1, char * call2, char * name, Player target);

	Vehicle SpawnVehicle(char * modelg, Vector3 coords, bool tpinto, float heading);

	extern bool PTLoopedO[35];
	void PTLopperO(Player target);

	void RequestControlOfid(Entity netid);

	extern int attachobj[100];

	extern int nuattach;

	extern int Levels[8000];

	void shootAtPed(Player selectedPlayer);

	namespace Online {
		extern int selectedPlayer;
		void TeleportToPlayer(Player player);

		extern bool WaterLoop;
		void waterLoop(Player target);

		extern bool FreezeLoop;
		void FreezeLooop(Player target);

		extern bool Explode;
		void Explodee(Player target);
		
		

	}
	void PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id);
}

