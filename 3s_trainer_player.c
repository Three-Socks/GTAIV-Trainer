/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 * Three-Socks Trainer
 *
 * @package 3s_trainer
 * @author Three-Socks http://psx-scene.com/forums/members/three-socks/
 * @license LICENSE.txt DON'T BE A DICK PUBLIC LICENSE (DBAD)
 *
 * @version 1.0 FINAL
 */

void player_model_gamecat(void)
{
	menu_header = trainer_model_changer;
	menu_addItem(trainer_gtaiv);
	#ifdef TLAD
		menu_addItem(trainer_tlad);
	#endif
	#ifdef TBOGT
		menu_addItem(trainer_tbogt);
	#endif
}

void player_model_cat(void)
{
	menu_addItem(trainer_story);

	if (item_selected == 1)
	{
		menu_addItem(trainer_story2);
		menu_addItem(trainer_gangs);
		menu_addItem(trainer_malespecific);
		menu_addItem(trainer_malespecific2);
		menu_addItem(trainer_malegeneric);
		menu_addItem(trainer_malegeneric2);
		menu_addItem(trainer_femalespecific);
		menu_addItem(trainer_femalegeneric);
	}
	else if (item_selected == 2)
	{
		#ifdef TLAD
			menu_addItem(trainer_gangs);
			menu_addItem(trainer_lostbuddies);
			menu_addItem(trainer_ambients);
		#endif
		#ifdef TBOGT
			menu_addItem(trainer_gangs);
			menu_addItem(trainer_ambients);
			menu_addItem(trainer_fighters);
			menu_addItem(trainer_mission);
		#endif
	}
}

void player_model_apply(void)
{
	uint player_model = menu_item[item_selected].num_val;

	float curHeading;
	GET_CHAR_HEADING(GetPlayerPed(), &curHeading);

	uint room_key;
	if (IS_INTERIOR_SCENE())
		GET_KEY_FOR_CHAR_IN_ROOM(GetPlayerPed(), &room_key);

	if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &v_modding); 
	else
		v_modding = 0;

	CHANGE_PLAYER_MODEL(GetPlayerIndex(), player_model);
	MARK_MODEL_AS_NO_LONGER_NEEDED(player_model);
	model_loaded = false;

	SET_CHAR_DEFAULT_COMPONENT_VARIATION(GetPlayerPed());
	FORCE_FULL_VOICE(GetPlayerPed());

	if (DOES_VEHICLE_EXIST(v_modding))
		WARP_CHAR_INTO_CAR(GetPlayerPed(), v_modding);

	SET_CHAR_HEADING(GetPlayerPed(), curHeading);

	if (IS_INTERIOR_SCENE())
		SET_ROOM_FOR_CHAR_BY_KEY(GetPlayerPed(), room_key);
}

void player_model_GTAIV_story1(void)
{
	menu_addItemHash("Niko", MODEL_PLAYER);
	menu_addAction();
	menu_addItemHash("Male Multiplayer", MODEL_M_Y_MULTIPLAYER);
	menu_addAction();
	menu_addItemHash("Female Multiplayer", MODEL_F_Y_MULTIPLAYER);
	menu_addAction();
	menu_addItemHash("Anna", MODEL_IG_ANNA);
	menu_addAction();
	menu_addItemHash("Anthony", MODEL_IG_ANTHONY);
	menu_addAction();
	menu_addItemHash("Badman", MODEL_IG_BADMAN);
	menu_addAction();
	menu_addItemHash("Bernie Crane", MODEL_IG_BERNIE_CRANE);
	menu_addAction();
	menu_addItemHash("Bledar", MODEL_IG_BLEDAR);
	menu_addAction();
	menu_addItemHash("Brian", MODEL_IG_BRIAN);
	menu_addAction();
	menu_addItemHash("Brucie", MODEL_IG_BRUCIE);
	menu_addAction();
	menu_addItemHash("Bulgarin", MODEL_IG_BULGARIN);
	menu_addAction();
	menu_addItemHash("Charise", MODEL_IG_CHARISE);
	menu_addAction();
	menu_addItemHash("Charlie UC", MODEL_IG_CHARLIEUC);
	menu_addAction();
	menu_addItemHash("Clarence", MODEL_IG_CLARENCE);
	menu_addAction();
	menu_addItemHash("Dardan", MODEL_IG_DARDAN);
	menu_addAction();
	menu_addItemHash("Darko", MODEL_IG_DARKO);
	menu_addAction();
	menu_addItemHash("Derrick Mc", MODEL_IG_DERRICK_MC);
	menu_addAction();
	menu_addItemHash("Dmitri", MODEL_IG_DMITRI);
	menu_addAction();
	menu_addItemHash("Dwayne", MODEL_IG_DWAYNE);
	menu_addAction();
	menu_addItemHash("Eddie Low", MODEL_IG_EDDIELOW);
	menu_addAction();
	menu_addItemHash("Faustin", MODEL_IG_FAUSTIN);
	menu_addAction();
	menu_addItemHash("Francis Mc", MODEL_IG_FRANCIS_MC);
	menu_addAction();
	menu_addItemHash("French Tom", MODEL_IG_FRENCH_TOM);
	menu_addAction();
	menu_addItemHash("Gordon", MODEL_IG_GORDON);
	menu_addAction();
	menu_addItemHash("Gracie", MODEL_IG_GRACIE);
	menu_addAction();
	menu_addItemHash("Hossan", MODEL_IG_HOSSAN);
	menu_addAction();
	menu_addItemHash("Ilyena", MODEL_IG_ILYENA);
	menu_addAction();
	menu_addItemHash("Isaac", MODEL_IG_ISAAC);
	menu_addAction();
	menu_addItemHash("Ivan", MODEL_IG_IVAN);
	menu_addAction();
	menu_addItemHash("Jay", MODEL_IG_JAY);
	menu_addAction();
	menu_addItemHash("Jason", MODEL_IG_JASON);
	menu_addAction();
	menu_addItemHash("Jeff", MODEL_IG_JEFF);
	menu_addAction();
	menu_addItemHash("Jimmy", MODEL_IG_JIMMY);
	menu_addAction();
	menu_addItemHash("Johnny Biker", MODEL_IG_JOHNNYBIKER);
	menu_addAction();
	menu_addItemHash("Kate Mc", MODEL_IG_KATEMC);
	menu_addAction();
	menu_addItemHash("Kenny", MODEL_IG_KENNY);
	menu_addAction();
	menu_addItemHash("LilJacob", MODEL_IG_LILJACOB);
	menu_addAction();
	menu_addItemHash("LilJacob W", MODEL_IG_LILJACOBW);
	menu_addAction();
	menu_addItemHash("Luca", MODEL_IG_LUCA);
	menu_addAction();
	menu_addItemHash("Luis", MODEL_IG_LUIS);
	menu_addAction();
	menu_addItemHash("Mallorie", MODEL_IG_MALLORIE);
	menu_addAction();
	menu_addItemHash("Ma Mc", MODEL_IG_MAMC);
	menu_addAction();
	menu_addItemHash("Manny", MODEL_IG_MANNY);
	menu_addAction();
	menu_addItemHash("Marnie", MODEL_IG_MARNIE);
	menu_addAction();
	menu_addItemHash("Mel", MODEL_IG_MEL);
	menu_addAction();
	menu_addItemHash("Michael", MODEL_IG_MICHAEL);
	menu_addAction();
	menu_addItemHash("Michelle", MODEL_IG_MICHELLE);
	menu_addAction();
	menu_addItemHash("Mickey", MODEL_IG_MICKEY);
	menu_addAction();
	menu_addItemHash("Packie Mc", MODEL_IG_PACKIE_MC);
	menu_addAction();
	menu_addItemHash("Pathos", MODEL_IG_PATHOS);
	menu_addAction();
}

void player_model_GTAIV_story2(void)
{
	menu_addItemHash("Petrovic", MODEL_IG_PETROVIC);
	menu_addAction();
	menu_addItemHash("Phil Bell", MODEL_IG_PHIL_BELL);
	menu_addAction();
	menu_addItemHash("Playboy X", MODEL_IG_PLAYBOY_X);
	menu_addAction();
	menu_addItemHash("Ray Boccino", MODEL_IG_RAY_BOCCINO);
	menu_addAction();
	menu_addItemHash("Ricky", MODEL_IG_RICKY);
	menu_addAction();
	menu_addItemHash("Roman", MODEL_IG_ROMAN);
	menu_addAction();
	menu_addItemHash("Roman W", MODEL_IG_ROMANW);
	menu_addAction();
	menu_addItemHash("Sarah", MODEL_IG_SARAH);
	menu_addAction();
	menu_addItemHash("Tuna", MODEL_IG_TUNA);
	menu_addAction();
	menu_addItemHash("Vinny Spaz", MODEL_IG_VINNY_SPAZ);
	menu_addAction();
	menu_addItemHash("Vlad", MODEL_IG_VLAD);
	menu_addAction();
}

void player_model_GTAIV_gangs(void)
{
	menu_addItemHash("Gansta 1", MODEL_M_Y_GAFR_LO_01);
	menu_addAction();
	menu_addItemHash("Gansta 2", MODEL_M_Y_GAFR_LO_02);
	menu_addAction();
	menu_addItemHash("Gansta 3", MODEL_M_Y_GAFR_HI_01);
	menu_addAction();
	menu_addItemHash("Gansta 4", MODEL_M_Y_GAFR_HI_02);
	menu_addAction();
	menu_addItemHash("Albanian 1", MODEL_M_Y_GALB_LO_01);
	menu_addAction();
	menu_addItemHash("Albanian 2", MODEL_M_Y_GALB_LO_02);
	menu_addAction();
	menu_addItemHash("Albanian 3", MODEL_M_Y_GALB_LO_03);
	menu_addAction();
	menu_addItemHash("Albanian 4", MODEL_M_Y_GALB_LO_04);
	menu_addAction();
	menu_addItemHash("Biker 1", MODEL_M_M_GBIK_LO_03);
	menu_addAction();
	menu_addItemHash("Biker 2", MODEL_M_Y_GBIK_HI_01);
	menu_addAction();
	menu_addItemHash("Biker 3", MODEL_M_Y_GBIK_HI_02);
	menu_addAction();
	menu_addItemHash("Biker 4", MODEL_M_Y_GBIK02_LO_02);
	menu_addAction();
	menu_addItemHash("Biker 5", MODEL_M_Y_GBIK_LO_01);
	menu_addAction();
	menu_addItemHash("Biker 6", MODEL_M_Y_GBIK_LO_02);
	menu_addAction();
	menu_addItemHash("Irish 1", MODEL_M_Y_GIRI_LO_01);
	menu_addAction();
	menu_addItemHash("Irish 2", MODEL_M_Y_GIRI_LO_02);
	menu_addAction();
	menu_addItemHash("Irish 3", MODEL_M_Y_GIRI_LO_03);
	menu_addAction();
	menu_addItemHash("Jamaican 1", MODEL_M_M_GJAM_HI_01);
	menu_addAction();
	menu_addItemHash("Jamaican 2", MODEL_M_M_GJAM_HI_02);
	menu_addAction();
	menu_addItemHash("Jamaican 3", MODEL_M_M_GJAM_HI_03);
	menu_addAction();
	menu_addItemHash("Jamaican 4", MODEL_M_Y_GJAM_LO_01);
	menu_addAction();
	menu_addItemHash("Jamaican 5", MODEL_M_Y_GJAM_LO_02);
	menu_addAction();
	menu_addItemHash("Korean 1", MODEL_M_Y_GKOR_LO_01);
	menu_addAction();
	menu_addItemHash("Korean 2", MODEL_M_Y_GKOR_LO_02);
	menu_addAction();
	menu_addItemHash("Latin 1", MODEL_M_Y_GLAT_LO_01);
	menu_addAction();
	menu_addItemHash("Latin 2", MODEL_M_Y_GLAT_LO_02);
	menu_addAction();
	menu_addItemHash("Latin 3", MODEL_M_Y_GLAT_HI_01);
	menu_addAction();
	menu_addItemHash("Latin 4", MODEL_M_Y_GLAT_HI_02);
	menu_addAction();
	menu_addItemHash("Mafia 1", MODEL_M_Y_GMAF_HI_01);
	menu_addAction();
	menu_addItemHash("Mafia 2", MODEL_M_Y_GMAF_HI_02);
	menu_addAction();
	menu_addItemHash("Mafia 3", MODEL_M_Y_GMAF_LO_01);
	menu_addAction();
	menu_addItemHash("Mafia 4", MODEL_M_Y_GMAF_LO_02);
	menu_addAction();
	menu_addItemHash("Russian 1", MODEL_M_O_GRUS_HI_01);
	menu_addAction();
	menu_addItemHash("Russian 2", MODEL_M_Y_GRUS_LO_01);
	menu_addAction();
	menu_addItemHash("Russian 3", MODEL_M_Y_GRUS_LO_02);
	menu_addAction();
	menu_addItemHash("Russian 4", MODEL_M_Y_GRUS_HI_02);
	menu_addAction();
	menu_addItemHash("Russian2 1", MODEL_M_M_GRU2_HI_01);
	menu_addAction();
	menu_addItemHash("Russian2 2", MODEL_M_M_GRU2_HI_02);
	menu_addAction();
	menu_addItemHash("Russian2 3", MODEL_M_M_GRU2_LO_02);
	menu_addAction();
	menu_addItemHash("Russian2 4", MODEL_M_Y_GRU2_LO_01);
	menu_addAction();
	menu_addItemHash("Triad 1", MODEL_M_M_GTRI_HI_01);
	menu_addAction();
	menu_addItemHash("Triad 2", MODEL_M_M_GTRI_HI_02);
	menu_addAction();
	menu_addItemHash("Triad 3", MODEL_M_Y_GTRI_LO_01);
	menu_addAction();
	menu_addItemHash("Triad 4", MODEL_M_Y_GTRI_LO_02);
	menu_addAction();
}

void player_model_GTAIV_M_foreground1(void)
{
	menu_addItemHash("Alcoholic", MODEL_M_M_ALCOHOLIC);
	menu_addAction();
	menu_addItemHash("Armoured", MODEL_M_M_ARMOURED);
	menu_addAction();
	menu_addItemHash("Bus Driver", MODEL_M_M_BUSDRIVER);
	menu_addAction();
	menu_addItemHash("Chinatown", MODEL_M_M_CHINATOWN_01);
	menu_addAction();
	menu_addItemHash("Crackhead", MODEL_M_M_CRACKHEAD);
	menu_addAction();
	menu_addItemHash("Doctor Scrubs", MODEL_M_M_DOC_SCRUBS_01);
	menu_addAction();
	menu_addItemHash("Doctor", MODEL_M_M_DOCTOR_01);
	menu_addAction();
	menu_addItemHash("Dodgy Doc", MODEL_M_M_DODGYDOC);
	menu_addAction();
	menu_addItemHash("EE Cook", MODEL_M_M_EECOOK);
	menu_addAction();
	menu_addItemHash("Enforcer", MODEL_M_M_ENFORCER);
	menu_addAction();
	menu_addItemHash("Factory", MODEL_M_M_FACTORY_01);
	menu_addAction();
	menu_addItemHash("Fat Cop", MODEL_M_M_FATCOP_01);
	menu_addAction();
	menu_addItemHash("FBI", MODEL_M_M_FBI);
	menu_addAction();
	menu_addItemHash("FedCo", MODEL_M_M_FEDCO);
	menu_addAction();
	menu_addItemHash("Fire Chief", MODEL_M_M_FIRECHIEF);
	menu_addAction();
	menu_addItemHash("Gun Nut", MODEL_M_M_GUNNUT_01);
	menu_addAction();
	menu_addItemHash("Helipilot", MODEL_M_M_HELIPILOT_01);
	menu_addAction();
	menu_addItemHash("H Porter", MODEL_M_M_HPORTER_01);
	menu_addAction();
	menu_addItemHash("Korea Cook", MODEL_M_M_KOREACOOK_01);
	menu_addAction();
	menu_addItemHash("Lawyer 1", MODEL_M_M_LAWYER_01);
	menu_addAction();
	menu_addItemHash("Lawyer 2", MODEL_M_M_LAWYER_02);
	menu_addAction();
	menu_addItemHash("Loony Black", MODEL_M_M_LOONYBLACK);
	menu_addAction();
	menu_addItemHash("Pilot", MODEL_M_M_PILOT);
	menu_addAction();
	menu_addItemHash("PIndus", MODEL_M_M_PINDUS_01);
	menu_addAction();
	menu_addItemHash("Postal", MODEL_M_M_POSTAL_01);
	menu_addAction();
	menu_addItemHash("Sax Player", MODEL_M_M_SAXPLAYER_01);
	menu_addAction();
	menu_addItemHash("Securityman", MODEL_M_M_SECURITYMAN);
	menu_addAction();
	menu_addItemHash("Seller", MODEL_M_M_SELLER_01);
	menu_addAction();
	menu_addItemHash("Shortorder", MODEL_M_M_SHORTORDER);
	menu_addAction();
	menu_addItemHash("Street Food", MODEL_M_M_STREETFOOD_01);
	menu_addAction();
	menu_addItemHash("Sweeper", MODEL_M_M_SWEEPER);
	menu_addAction();
	menu_addItemHash("Taxi Driver", MODEL_M_M_TAXIDRIVER);
	menu_addAction();
	menu_addItemHash("Telephone", MODEL_M_M_TELEPHONE);
	menu_addAction();
	menu_addItemHash("Tennis", MODEL_M_M_TENNIS);
	menu_addAction();
	menu_addItemHash("Train", MODEL_M_M_TRAIN_01);
	menu_addAction();
	menu_addItemHash("Tramp Black", MODEL_M_M_TRAMPBLACK);
	menu_addAction();
	menu_addItemHash("Trucker", MODEL_M_M_TRUCKER_01);
	menu_addAction();
	menu_addItemHash("Janitor", MODEL_M_O_JANITOR);
	menu_addAction();
	menu_addItemHash("Hotel Foot", MODEL_M_O_HOTEL_FOOT);
	menu_addAction();
	menu_addItemHash("MP MobBoss", MODEL_M_O_MPMOBBOSS);
	menu_addAction();
	menu_addItemHash("Air Worker", MODEL_M_Y_AIRWORKER);
	menu_addAction();
	menu_addItemHash("Barman", MODEL_M_Y_BARMAN_01);
	menu_addAction();
	menu_addItemHash("Bouncer 1", MODEL_M_Y_BOUNCER_01);
	menu_addAction();
	menu_addItemHash("Bouncer 2", MODEL_M_Y_BOUNCER_02);
	menu_addAction();
	menu_addItemHash("Bowl 1", MODEL_M_Y_BOWL_01);
	menu_addAction();
	menu_addItemHash("Bowl 2", MODEL_M_Y_BOWL_02);
	menu_addAction();
	menu_addItemHash("Chinvend", MODEL_M_Y_CHINVEND_01);
	menu_addAction();
	menu_addItemHash("clubfit", MODEL_M_Y_CLUBFIT);
	menu_addAction();
	menu_addItemHash("Construct 1", MODEL_M_Y_CONSTRUCT_01);
	menu_addAction();
	menu_addItemHash("Construct 2", MODEL_M_Y_CONSTRUCT_02);
	menu_addAction();
}

void player_model_GTAIV_M_foreground2(void)
{
	menu_addItemHash("Construct 3", MODEL_M_Y_CONSTRUCT_03);
	menu_addAction();
	menu_addItemHash("Cop", MODEL_M_Y_COP);
	menu_addAction();
	menu_addItemHash("Cop Traffic", MODEL_M_Y_COP_TRAFFIC);
	menu_addAction();
	menu_addItemHash("Courier", MODEL_M_Y_COURIER);
	menu_addAction();
	menu_addItemHash("Cowboy", MODEL_M_Y_COWBOY_01);
	menu_addAction();
	menu_addItemHash("Dealer", MODEL_M_Y_DEALER);
	menu_addAction();
	menu_addItemHash("Drug", MODEL_M_Y_DRUG_01);
	menu_addAction();
	menu_addItemHash("FF Burger", MODEL_M_Y_FF_BURGER_R);
	menu_addAction();
	menu_addItemHash("Cluck", MODEL_M_Y_FF_CLUCK_R);
	menu_addAction();
	menu_addItemHash("RS Cafe", MODEL_M_Y_FF_RSCAFE);
	menu_addAction();
	menu_addItemHash("Tw Cafe", MODEL_M_Y_FF_TWCAFE);
	menu_addAction();
	menu_addItemHash("WS Pizza", MODEL_M_Y_FF_WSPIZZA_R);
	menu_addAction();
	menu_addItemHash("Fireman", MODEL_M_Y_FIREMAN);
	menu_addAction();
	menu_addItemHash("Garbage", MODEL_M_Y_GARBAGE);
	menu_addAction();
	menu_addItemHash("Goon", MODEL_M_Y_GOON_01);
	menu_addAction();
	menu_addItemHash("Gym", MODEL_M_Y_GYMGUY_01);
	menu_addAction();
	menu_addItemHash("Mechanic", MODEL_M_Y_MECHANIC_02);
	menu_addAction();
	menu_addItemHash("Modo", MODEL_M_Y_MODO);
	menu_addAction();
	menu_addItemHash("N Helipilot", MODEL_M_Y_NHELIPILOT);
	menu_addAction();
	menu_addItemHash("Perseus", MODEL_M_Y_PERSEUS);
	menu_addAction();
	menu_addItemHash("Pindus 1", MODEL_M_Y_PINDUS_01);
	menu_addAction();
	menu_addItemHash("Pindus 2", MODEL_M_Y_PINDUS_02);
	menu_addAction();
	menu_addItemHash("Pindus 3", MODEL_M_Y_PINDUS_03);
	menu_addAction();
	menu_addItemHash("Medic", MODEL_M_Y_PMEDIC);
	menu_addAction();
	menu_addItemHash("Prison", MODEL_M_Y_PRISON);
	menu_addAction();
	menu_addItemHash("Prison AOM", MODEL_M_Y_PRISONAOM);
	menu_addAction();
	menu_addItemHash("Roman Cab", MODEL_M_Y_ROMANCAB);
	menu_addAction();
	menu_addItemHash("Runner", MODEL_M_Y_RUNNER);
	menu_addAction();
	menu_addItemHash("Shop Asst", MODEL_M_Y_SHOPASST_01);
	menu_addAction();
	menu_addItemHash("Trooper", MODEL_M_Y_STROOPER);
	menu_addAction();
	menu_addItemHash("Swat", MODEL_M_Y_SWAT);
	menu_addAction();
	menu_addItemHash("Sword Swallow", MODEL_M_Y_SWORDSWALLOW);
	menu_addAction();
	menu_addItemHash("Thief", MODEL_M_Y_THIEF);
	menu_addAction();
	menu_addItemHash("Valet", MODEL_M_Y_VALET);
	menu_addAction();
	menu_addItemHash("Vendor", MODEL_M_Y_VENDOR);
	menu_addAction();
	menu_addItemHash("French Tom", MODEL_M_Y_FRENCHTOM);
	menu_addAction();
	menu_addItemHash("Jim Fitz", MODEL_M_Y_JIM_FITZ);
	menu_addAction();
}

void player_model_GTAIV_M_background1(void)
{
	menu_addItemHash("P Business", MODEL_M_M_PBUSINESS_01);
	menu_addAction();
	menu_addItemHash("Business 1", MODEL_M_Y_BUSINESS_01);
	menu_addAction();
	menu_addItemHash("Business 2", MODEL_M_Y_BUSINESS_02);
	menu_addAction();
	menu_addItemHash("Business 3", MODEL_M_M_BUSINESS_02);
	menu_addAction();
	menu_addItemHash("Business 4", MODEL_M_M_BUSINESS_03);
	menu_addAction();
	menu_addItemHash("Heavy 1", MODEL_M_M_EE_HEAVY_01);
	menu_addAction();
	menu_addItemHash("Heavy 2", MODEL_M_M_EE_HEAVY_02);
	menu_addAction();
	menu_addItemHash("Fat Mob", MODEL_M_M_FATMOB_01);
	menu_addAction();
	menu_addItemHash("Gay Mid", MODEL_M_M_GAYMID);
	menu_addAction();
	menu_addItemHash("Gen Bum", MODEL_M_M_GENBUM_01);
	menu_addAction();
	menu_addItemHash("Loony White", MODEL_M_M_LOONYWHITE);
	menu_addAction();
	menu_addItemHash("Mid Town", MODEL_M_M_MIDTOWN_01);
	menu_addAction();
	menu_addItemHash("HarBron", MODEL_M_M_PHARBRON_01);
	menu_addAction();
	menu_addItemHash("Indus", MODEL_M_M_PINDUS_02);
	menu_addAction();
	menu_addItemHash("Italian 1", MODEL_M_M_PITALIAN_01);
	menu_addAction();
	menu_addItemHash("Italian 2", MODEL_M_M_PITALIAN_02);
	menu_addAction();
	menu_addItemHash("Latin 1", MODEL_M_M_PLATIN_01);
	menu_addAction();
	menu_addItemHash("Latin 2", MODEL_M_M_PLATIN_02);
	menu_addAction();
	menu_addItemHash("Latin 3", MODEL_M_M_PLATIN_03);
	menu_addAction();
	menu_addItemHash("Manhat 1", MODEL_M_M_PMANHAT_01);
	menu_addAction();
	menu_addItemHash("Manhat 2", MODEL_M_M_PMANHAT_02);
	menu_addAction();
	menu_addItemHash("Orient", MODEL_M_M_PORIENT_01);
	menu_addAction();
	menu_addItemHash("Rich", MODEL_M_M_PRICH_01);
	menu_addAction();
	menu_addItemHash("East Euro 1", MODEL_M_O_EASTEURO_01);
	menu_addAction();
	menu_addItemHash("East Euro 2", MODEL_M_M_PEASTEURO_01);
	menu_addAction();
	menu_addItemHash("East Euro 3", MODEL_M_O_PEASTEURO_02);
	menu_addAction();
	menu_addItemHash("East Euro 4", MODEL_M_Y_PEASTEURO_01);
	menu_addAction();
	menu_addItemHash("Hasid", MODEL_M_O_HASID_01);
	menu_addAction();
	menu_addItemHash("Mobster", MODEL_M_O_MOBSTER);
	menu_addAction();
	menu_addItemHash("Harbron", MODEL_M_O_PHARBRON_01);
	menu_addAction();
	menu_addItemHash("Jersey", MODEL_M_O_PJERSEY_01);
	menu_addAction();
	menu_addItemHash("Street", MODEL_M_O_STREET_01);
	menu_addAction();
	menu_addItemHash("Suited", MODEL_M_O_SUITED);
	menu_addAction();
	menu_addItemHash("BoHo", MODEL_M_Y_BOHO_01);
	menu_addAction();
	menu_addItemHash("BoHo Guy", MODEL_M_Y_BOHOGUY_01);
	menu_addAction();
	menu_addItemHash("Bronx", MODEL_M_Y_BRONX_01);
	menu_addAction();
	menu_addItemHash("Chinatown", MODEL_M_Y_CHINATOWN_03);
	menu_addAction();
	menu_addItemHash("Chopshop 1", MODEL_M_Y_CHOPSHOP_01);
	menu_addAction();
	menu_addItemHash("Chopshop 2", MODEL_M_Y_CHOPSHOP_02);
	menu_addAction();
	menu_addItemHash("Dodgy", MODEL_M_Y_DODGY_01);
	menu_addAction();
	menu_addItemHash("Dork", MODEL_M_Y_DORK_02);
	menu_addAction();
	menu_addItemHash("Downtown 1", MODEL_M_Y_DOWNTOWN_01);
	menu_addAction();
	menu_addItemHash("Downtown 2", MODEL_M_Y_DOWNTOWN_02);
	menu_addAction();
	menu_addItemHash("Downtown 3", MODEL_M_Y_DOWNTOWN_03);
	menu_addAction();
	menu_addItemHash("Gay Young", MODEL_M_Y_GAYYOUNG);
	menu_addAction();
	menu_addItemHash("Gen Street 1", MODEL_M_Y_GENSTREET_11);
	menu_addAction();
	menu_addItemHash("Gen Street 2", MODEL_M_Y_GENSTREET_16);
	menu_addAction();
	menu_addItemHash("Gen Street 3", MODEL_M_Y_GENSTREET_20);
	menu_addAction();
	menu_addItemHash("Gen Street 4", MODEL_M_Y_GENSTREET_34);
	menu_addAction();
	menu_addItemHash("Hard Man", MODEL_M_Y_HARDMAN_01);
	menu_addAction();
}

void player_model_GTAIV_M_background2(void)
{
	menu_addItemHash("Harlem 1", MODEL_M_Y_HARLEM_01);
	menu_addAction();
	menu_addItemHash("Harlem 2", MODEL_M_Y_HARLEM_02);
	menu_addAction();
	menu_addItemHash("Harlem 4", MODEL_M_Y_HARLEM_04);
	menu_addAction();
	menu_addItemHash("Hasid", MODEL_M_Y_HASID_01);
	menu_addAction();
	menu_addItemHash("L EastSide", MODEL_M_Y_LEASTSIDE_01);
	menu_addAction();
	menu_addItemHash("Bronx", MODEL_M_Y_PBRONX_01);
	menu_addAction();
	menu_addItemHash("Cool 1", MODEL_M_Y_PCOOL_01);
	menu_addAction();
	menu_addItemHash("Cool 2", MODEL_M_Y_PCOOL_02);
	menu_addAction();
	menu_addItemHash("Harbron", MODEL_M_Y_PHARBRON_01);
	menu_addAction();
	menu_addItemHash("Harlem", MODEL_M_Y_PHARLEM_01);
	menu_addAction();
	menu_addItemHash("Jersey", MODEL_M_Y_PJERSEY_01);
	menu_addAction();
	menu_addItemHash("Latin 1", MODEL_M_Y_PLATIN_01);
	menu_addAction();
	menu_addItemHash("Latin 2", MODEL_M_Y_PLATIN_02);
	menu_addAction();
	menu_addItemHash("Latin 3", MODEL_M_Y_PLATIN_03);
	menu_addAction();
	menu_addItemHash("Manhat 1", MODEL_M_Y_PMANHAT_01);
	menu_addAction();
	menu_addItemHash("Manhat 2", MODEL_M_Y_PMANHAT_02);
	menu_addAction();
	menu_addItemHash("Orient", MODEL_M_Y_PORIENT_01);
	menu_addAction();
	menu_addItemHash("Queens", MODEL_M_Y_PQUEENS_01);
	menu_addAction();
	menu_addItemHash("Rich", MODEL_M_Y_PRICH_01);
	menu_addAction();
	menu_addItemHash("Vill Bo 1", MODEL_M_Y_PVILLBO_01);
	menu_addAction();
	menu_addItemHash("Vill Bo 2", MODEL_M_Y_PVILLBO_02);
	menu_addAction();
	menu_addItemHash("Vill Bo 3", MODEL_M_Y_PVILLBO_03);
	menu_addAction();
	menu_addItemHash("Queens Bridge", MODEL_M_Y_QUEENSBRIDGE);
	menu_addAction();
	menu_addItemHash("Shady", MODEL_M_Y_SHADY_02);
	menu_addAction();
	menu_addItemHash("Skatebike", MODEL_M_Y_SKATEBIKE_01);
	menu_addAction();
	menu_addItemHash("Soho", MODEL_M_Y_SOHO_01);
	menu_addAction();
	menu_addItemHash("Street 1", MODEL_M_Y_STREET_01);
	menu_addAction();
	menu_addItemHash("Street 2", MODEL_M_Y_STREET_03);
	menu_addAction();
	menu_addItemHash("Street 3", MODEL_M_Y_STREET_04);
	menu_addAction();
	menu_addItemHash("Streetblk 1", MODEL_M_Y_STREETBLK_02);
	menu_addAction();
	menu_addItemHash("Streetblk 2", MODEL_M_Y_STREETBLK_03);
	menu_addAction();
	menu_addItemHash("Street Punk 1", MODEL_M_Y_STREETPUNK_02);
	menu_addAction();
	menu_addItemHash("Street Punk 2", MODEL_M_Y_STREETPUNK_04);
	menu_addAction();
	menu_addItemHash("Street Punk 3", MODEL_M_Y_STREETPUNK_05);
	menu_addAction();
	menu_addItemHash("Tough", MODEL_M_Y_TOUGH_05);
	menu_addAction();
	menu_addItemHash("Tourist", MODEL_M_Y_TOURIST_02);
	menu_addAction();
}

void player_model_GTAIV_F_foreground(void)
{
	menu_addItemHash("Maid", MODEL_F_O_MAID_01);
	menu_addAction();
	menu_addItemHash("Binco", MODEL_F_O_BINCO);
	menu_addAction();
	menu_addItemHash("Bank", MODEL_F_Y_BANK_01);
	menu_addAction();
	menu_addItemHash("Doctor", MODEL_F_Y_DOCTOR_01);
	menu_addAction();
	menu_addItemHash("Gym", MODEL_F_Y_GYMGAL_01);
	menu_addAction();
	menu_addItemHash("Burger", MODEL_F_Y_FF_BURGER_R);
	menu_addAction();
	menu_addItemHash("Cluck", MODEL_F_Y_FF_CLUCK_R);
	menu_addAction();
	menu_addItemHash("RSCafe", MODEL_F_Y_FF_RSCAFE);
	menu_addAction();
	menu_addItemHash("Tw Cafe", MODEL_F_Y_FF_TWCAFE);
	menu_addAction();
	menu_addItemHash("WS Pizza", MODEL_F_Y_FF_WSPIZZA_R);
	menu_addAction();
	menu_addItemHash("Hooker 1", MODEL_F_Y_HOOKER_01);
	menu_addAction();
	menu_addItemHash("Hooker 2", MODEL_F_Y_HOOKER_03);
	menu_addAction();
	menu_addItemHash("Nurse", MODEL_F_Y_NURSE);
	menu_addAction();
	menu_addItemHash("Stripper 1", MODEL_F_Y_STRIPPERC01);
	menu_addAction();
	menu_addItemHash("Stripper 2", MODEL_F_Y_STRIPPERC02);
	menu_addAction();
	menu_addItemHash("Waitress", MODEL_F_Y_WAITRESS_01);
	menu_addAction();
}

void player_model_GTAIV_F_background(void)
{
	menu_addItemHash("East Euro 1", MODEL_F_O_PEASTEURO_01);
	menu_addAction();
	menu_addItemHash("East Euro 2", MODEL_F_O_PEASTEURO_02);
	menu_addAction();
	menu_addItemHash("Harbron", MODEL_F_O_PHARBRON_01);
	menu_addAction();
	menu_addItemHash("Jersey", MODEL_F_O_PJERSEY_01);
	menu_addAction();
	menu_addItemHash("Orient", MODEL_F_O_PORIENT_01);
	menu_addAction();
	menu_addItemHash("Rich", MODEL_F_O_RICH_01);
	menu_addAction();
	menu_addItemHash("Business 1", MODEL_F_M_BUSINESS_01);
	menu_addAction();
	menu_addItemHash("Business 2", MODEL_F_M_BUSINESS_02);
	menu_addAction();
	menu_addItemHash("Chinatown", MODEL_F_M_CHINATOWN);
	menu_addAction();
	menu_addItemHash("Business", MODEL_F_M_PBUSINESS);
	menu_addAction();
	menu_addItemHash("East Euro", MODEL_F_M_PEASTEURO_01);
	menu_addAction();
	menu_addItemHash("HarBron", MODEL_F_M_PHARBRON_01);
	menu_addAction();
	menu_addItemHash("Jersey 1", MODEL_F_M_PJERSEY_01);
	menu_addAction();
	menu_addItemHash("Jersey 2", MODEL_F_M_PJERSEY_02);
	menu_addAction();
	menu_addItemHash("Latin 1", MODEL_F_M_PLATIN_01);
	menu_addAction();
	menu_addItemHash("Latin 2", MODEL_F_M_PLATIN_02);
	menu_addAction();
	menu_addItemHash("Manhat 1", MODEL_F_M_PMANHAT_01);
	menu_addAction();
	menu_addItemHash("Manhat 2", MODEL_F_M_PMANHAT_02);
	menu_addAction();
	menu_addItemHash("Orient", MODEL_F_M_PORIENT_01);
	menu_addAction();
	menu_addItemHash("Rich", MODEL_F_M_PRICH_01);
	menu_addAction();
	menu_addItemHash("Business", MODEL_F_Y_BUSINESS_01);
	menu_addAction();
	menu_addItemHash("Dress ", MODEL_F_Y_CDRESS_01);
	menu_addAction();
	menu_addItemHash("Bronx", MODEL_F_Y_PBRONX_01);
	menu_addAction();
	menu_addItemHash("Cool 1", MODEL_F_Y_PCOOL_01);
	menu_addAction();
	menu_addItemHash("Cool 2", MODEL_F_Y_PCOOL_02);
	menu_addAction();
	menu_addItemHash("East Euro", MODEL_F_Y_PEASTEURO_01);
	menu_addAction();
	menu_addItemHash("HarBron", MODEL_F_Y_PHARBRON_01);
	menu_addAction();
	menu_addItemHash("Harlem", MODEL_F_Y_PHARLEM_01);
	menu_addAction();
	menu_addItemHash("Jersey", MODEL_F_Y_PJERSEY_02);
	menu_addAction();
	menu_addItemHash("Latin 1", MODEL_F_Y_PLATIN_01);
	menu_addAction();
	menu_addItemHash("Latin 2", MODEL_F_Y_PLATIN_02);
	menu_addAction();
	menu_addItemHash("Latin 3", MODEL_F_Y_PLATIN_03);
	menu_addAction();
	menu_addItemHash("Manhat 1", MODEL_F_Y_PMANHAT_01);
	menu_addAction();
	menu_addItemHash("Manhat 2", MODEL_F_Y_PMANHAT_02);
	menu_addAction();
	menu_addItemHash("Manhat 3", MODEL_F_Y_PMANHAT_03);
	menu_addAction();
	menu_addItemHash("Orient", MODEL_F_Y_PORIENT_01);
	menu_addAction();
	menu_addItemHash("Queens", MODEL_F_Y_PQUEENS_01);
	menu_addAction();
	menu_addItemHash("Rich", MODEL_F_Y_PRICH_01);
	menu_addAction();
	menu_addItemHash("villBo", MODEL_F_Y_PVILLBO_02);
	menu_addAction();
	menu_addItemHash("Shop 1", MODEL_F_Y_SHOP_03);
	menu_addAction();
	menu_addItemHash("Shop 2", MODEL_F_Y_SHOP_04);
	menu_addAction();
	menu_addItemHash("Shop 3", MODEL_F_Y_SHOPPER_05);
	menu_addAction();
	menu_addItemHash("Socialite", MODEL_F_Y_SOCIALITE);
	menu_addAction();
	menu_addItemHash("Street 1", MODEL_F_Y_STREET_02);
	menu_addAction();
	menu_addItemHash("Street 2", MODEL_F_Y_STREET_05);
	menu_addAction();
	menu_addItemHash("Street 3", MODEL_F_Y_STREET_09);
	menu_addAction();
	menu_addItemHash("Street 4", MODEL_F_Y_STREET_12);
	menu_addAction();
	menu_addItemHash("Street 5", MODEL_F_Y_STREET_30);
	menu_addAction();
	menu_addItemHash("Street 6", MODEL_F_Y_STREET_34);
	menu_addAction();
	menu_addItemHash("Tourist", MODEL_F_Y_TOURIST_01);
	menu_addAction();
	menu_addItemHash("Villbo", MODEL_F_Y_VILLBO_01);
	menu_addAction();
}

#ifdef TLAD
void player_model_TLAD_story(void)
{
	menu_addItemHash("Niko", MODEL_IG_NIKO);
	menu_addAction();
	menu_addItemHash("Ashley", MODEL_IG_ASHLEYA);
	menu_addAction();
	menu_addItemHash("Clay", MODEL_IG_CLAY);
	menu_addAction();
	menu_addItemHash("Malc", MODEL_IG_MALC);
	menu_addAction();
	menu_addItemHash("Billy", MODEL_IG_BILLY);
	menu_addAction();
	menu_addItemHash("Jim Fitz", MODEL_IG_JIM_FITZ);
	menu_addAction();
	menu_addItemHash("Brian J", MODEL_IG_BRIANJ);
	menu_addAction();
	menu_addItemHash("Evan", MODEL_IG_EVAN);
	menu_addAction();
	menu_addItemHash("Terry", MODEL_IG_TERRY);
	menu_addAction();
	menu_addItemHash("Dave Grossman", MODEL_IG_DAVE_GROSSMAN);
	menu_addAction();
	menu_addItemHash("Lost Girl", MODEL_IG_LOSTGIRL);
	menu_addAction();
	menu_addItemHash("Billy Prison", MODEL_IG_BILLYPRISON);
	menu_addAction();
	menu_addItemHash("Marta", MODEL_IG_MARTA);
	menu_addAction();
	menu_addItemHash("Desean", MODEL_IG_DESEAN);
	menu_addAction();
	menu_addItemHash("Matthews", MODEL_IG_MATTHEWS);
	menu_addAction();
	menu_addItemHash("McCornish", MODEL_IG_MCCORNISH);
	menu_addAction();
	menu_addItemHash("Girl 1", MODEL_IG_PGIRL_01);
	menu_addAction();
	menu_addItemHash("Girl 2", MODEL_IG_PGIRL_02);
	menu_addAction();
	menu_addItemHash("Roman", MODEL_IG_ROMAN_E1);
	menu_addAction();
	menu_addItemHash("Trooper", MODEL_IG_STROOPER);
	menu_addAction();
}

void player_model_TLAD_gangs(void)
{
	menu_addItemHash("Angels 1", MODEL_M_Y_GANGELS_01);
	menu_addAction();
	menu_addItemHash("Angels 2", MODEL_M_Y_GANGELS_02);
	menu_addAction();
	menu_addItemHash("Angels 3", MODEL_M_Y_GANGELS_03);
	menu_addAction();
	menu_addItemHash("Angels 4", MODEL_M_Y_GANGELS_04);
	menu_addAction();
	menu_addItemHash("Angels 5", MODEL_M_Y_GANGELS_05);
	menu_addAction();
	menu_addItemHash("Angels 6", MODEL_M_Y_GANGELS_06);
	menu_addAction();
	menu_addItemHash("Angels 7", MODEL_F_Y_GANGELS_01);
	menu_addAction();
	menu_addItemHash("Angels 8", MODEL_F_Y_GANGELS_02);
	menu_addAction();
	menu_addItemHash("Angels 9", MODEL_F_Y_GANGELS_03);
	menu_addAction();
	menu_addItemHash("Lost 1", MODEL_M_Y_GLOST_01);
	menu_addAction();
	menu_addItemHash("Lost 2", MODEL_M_Y_GLOST_02);
	menu_addAction();
	menu_addItemHash("Lost 3", MODEL_M_Y_GLOST_03);
	menu_addAction();
	menu_addItemHash("Lost 4", MODEL_M_Y_GLOST_04);
	menu_addAction();
	menu_addItemHash("Lost 5", MODEL_M_Y_GLOST_05);
	menu_addAction();
	menu_addItemHash("Lost 6", MODEL_M_Y_GLOST_06);
	menu_addAction();
	menu_addItemHash("Lost 7", MODEL_F_Y_GLOST_01);
	menu_addAction();
	menu_addItemHash("Lost 8", MODEL_F_Y_GLOST_02);
	menu_addAction();
	menu_addItemHash("Lost 9", MODEL_F_Y_GLOST_03);
	menu_addAction();
	menu_addItemHash("Lost 10", MODEL_F_Y_GLOST_04);
	menu_addAction();
	menu_addItemHash("Ryders 1", MODEL_M_Y_GRYDERS_01);
	menu_addAction();
	menu_addItemHash("Ryders 2", MODEL_M_Y_GRYDERS_02);
	menu_addAction();
	menu_addItemHash("Ryders 3", MODEL_F_Y_GRYDERS_01);
	menu_addAction();
	menu_addItemHash("Triad 1", MODEL_M_Y_GTRIAD_HI_01);
	menu_addAction();
	menu_addItemHash("Triad 2", MODEL_M_Y_GTRI_02);
	menu_addAction();
}

void player_model_TLAD_buddies(void)
{
	menu_addItemHash("Lost Buddy 1", MODEL_LOSTBUDDY_01);
	menu_addAction();
	menu_addItemHash("Lost Buddy 2", MODEL_LOSTBUDDY_02);
	menu_addAction();
	menu_addItemHash("Lost Buddy 3", MODEL_LOSTBUDDY_03);
	menu_addAction();
	menu_addItemHash("Lost Buddy 4", MODEL_LOSTBUDDY_04);
	menu_addAction();
	menu_addItemHash("Lost Buddy 5", MODEL_LOSTBUDDY_05);
	menu_addAction();
	menu_addItemHash("Lost Buddy 6", MODEL_LOSTBUDDY_06);
	menu_addAction();
	menu_addItemHash("Lost Buddy 7", MODEL_LOSTBUDDY_07);
	menu_addAction();
	menu_addItemHash("Lost Buddy 8", MODEL_LOSTBUDDY_08);
	menu_addAction();
	menu_addItemHash("Lost Buddy 9", MODEL_LOSTBUDDY_09);
	menu_addAction();
	menu_addItemHash("Lost Buddy 10", MODEL_LOSTBUDDY_10);
	menu_addAction();
	menu_addItemHash("Lost Buddy 11", MODEL_LOSTBUDDY_11);
	menu_addAction();
	menu_addItemHash("Lost Buddy 12", MODEL_LOSTBUDDY_12);
	menu_addAction();
	menu_addItemHash("Lost Buddy 13", MODEL_LOSTBUDDY_13);
	menu_addAction();
}

void player_model_TLAD_ambients(void)
{
	menu_addItemHash("Bike Stripper", MODEL_F_Y_BIKESTRIPPER_01);
	menu_addAction();
	menu_addItemHash("E Midtown 1", MODEL_F_Y_EMIDTOWN_01);
	menu_addAction();
	menu_addItemHash("Spretzer", MODEL_M_M_SPRETZER);
	menu_addAction();
	menu_addItemHash("FIB 1", MODEL_M_Y_CIADLC_01);
	menu_addAction();
	menu_addItemHash("FIB 2", MODEL_M_Y_CIADLC_02);
	menu_addAction();
	menu_addItemHash("Doorman 1", MODEL_M_Y_DOORMAN_01);
	menu_addAction();
	menu_addItemHash("Prison", MODEL_M_Y_PRISONDLC_01);
	menu_addAction();
	menu_addItemHash("Prison Guard", MODEL_M_Y_PRISONGUARD);
	menu_addAction();
	menu_addItemHash("Uptown 1", MODEL_F_Y_UPTOWN_01);
	menu_addAction();
	menu_addItemHash("Smartblack", MODEL_M_M_SMARTBLACK);
	menu_addAction();
	menu_addItemHash("HipMale 1", MODEL_M_Y_HIPMALE_01);
	menu_addAction();
	menu_addItemHash("Busiasian", MODEL_M_Y_BUSIASIAN);
	menu_addAction();
	menu_addItemHash("Up East", MODEL_M_M_UPEAST_01);
	menu_addAction();
	menu_addItemHash("BusiAsian", MODEL_F_Y_BUSIASIAN);
	menu_addAction();
	menu_addItemHash("Hispanic 1", MODEL_M_O_HISPANIC_01);
	menu_addAction();
	menu_addItemHash("Hispanic 2", MODEL_M_Y_HISPANIC_01);
	menu_addAction();
	menu_addItemHash("BusiMidEast", MODEL_M_Y_BUSIMIDEAST);
	menu_addAction();
	menu_addItemHash("Bikemech", MODEL_M_Y_BIKEMECH);
	menu_addAction();
	menu_addItemHash("Uptown", MODEL_M_M_UPTOWN_01);
	menu_addAction();
	menu_addItemHash("Gang", MODEL_M_Y_GAYGANG_01);
	menu_addAction();
	menu_addItemHash("Hip", MODEL_M_Y_HIP_02);
	menu_addAction();
	menu_addItemHash("Prison Black", MODEL_M_Y_PRISONBLACK);
	menu_addAction();
	menu_addItemHash("Uptown", MODEL_F_Y_UPTOWN_CS);
	menu_addAction();
}

/*void player_model_TLAD_cutscene(void)
{
	menu_addItemHash("Niko", MODEL_CS_NIKO);
	menu_addAction();
	menu_addItemHash("Andreas", MODEL_CS_ANDREAS);
	menu_addAction();
	menu_addItemHash("Angel Guy", MODEL_CS_ANGELGUY);
	menu_addAction();
	menu_addItemHash("Angus", MODEL_CS_ANGUS);
	menu_addAction();
	menu_addItemHash("Ashley", MODEL_CS_ASHLEYA);
	menu_addAction();
	menu_addItemHash("Billy", MODEL_CS_BILLY);
	menu_addAction();
	menu_addItemHash("Bike Stripper", MODEL_CS_BIKESTRIPPER);
	menu_addAction();
	menu_addItemHash("Brian J", MODEL_CS_BRIANJ);
	menu_addAction();
	menu_addItemHash("Clay", MODEL_CS_CLAY);
	menu_addAction();
	menu_addItemHash("Dave Grossman", MODEL_CS_DAVE_GROSSMAN);
	menu_addAction();
	menu_addItemHash("Desean", MODEL_CS_DESEAN);
	menu_addAction();
	menu_addItemHash("Elizabeta", MODEL_CS_ELIZABETAT);
	menu_addAction();
	menu_addItemHash("Frankie", MODEL_CS_FRANKIE);
	menu_addAction();
	menu_addItemHash("Jason", MODEL_CS_JASON);
	menu_addAction();
	menu_addItemHash("Jim Fitz", MODEL_CS_JIM_FITZ);
	menu_addAction();
	menu_addItemHash("Maitre", MODEL_CS_MAITRE_D);
	menu_addAction();
	menu_addItemHash("Malc", MODEL_CS_MALC);
	menu_addAction();
	menu_addItemHash("Mitch", MODEL_CS_MITCHB);
	menu_addAction();
	menu_addItemHash("Marta", MODEL_CS_MARTA);
	menu_addAction();
	menu_addItemHash("Masseuse", MODEL_CS_MASSEUSE);
	menu_addAction();
	menu_addItemHash("Matthews", MODEL_CS_MATTHEWS);
	menu_addAction();
	menu_addItemHash("McCornish", MODEL_CS_MCCORNISH);
	menu_addAction();
	menu_addItemHash("Paul Lamont", MODEL_CS_PAUL_LAMONT);
	menu_addAction();
	menu_addItemHash("Prison", MODEL_CS_PRISONDLC_01);
	menu_addAction();
	menu_addItemHash("Prison Guard", MODEL_CS_PRISONGUARD);
	menu_addAction();
	menu_addItemHash("Ray Goon", MODEL_CS_RAYGOON);
	menu_addAction();
	menu_addItemHash("Ray Leather", MODEL_CS_RAY_LEATHER);
	menu_addAction();
	menu_addItemHash("Roncero", MODEL_CS_RONCERO);
	menu_addAction();
	menu_addItemHash("Russian Goon", MODEL_CS_RUSSIAN_GOON);
	menu_addAction();
	menu_addItemHash("Russian Goon2", MODEL_CS_RUSSIANGOON2);
	menu_addAction();
	menu_addItemHash("Terry", MODEL_CS_TERRY);
	menu_addAction();
	menu_addItemHash("Skank", MODEL_CS_SKANK);
	menu_addAction();
	menu_addItemHash("Stubbs", MODEL_CS_STUBBS);
	menu_addAction();
	menu_addItemHash("Stubbs Suit", MODEL_CS_STUBBS_SUIT);
	menu_addAction();
}*/
#endif

#ifdef TBOGT
void player_model_TBOGT_story(void)
{
	menu_addItemHash("Ahmad", MODEL_IG_AHMAD);
	menu_addAction();
	menu_addItemHash("Armando", MODEL_IG_ARMANDO);
	menu_addAction();
	menu_addItemHash("Arms Dealer", MODEL_IG_ARMSDEALER);
	menu_addAction();
	menu_addItemHash("Arnaud", MODEL_IG_ARNAUD);
	menu_addAction();
	menu_addItemHash("Banker", MODEL_IG_BANKER);
	menu_addAction();
	menu_addItemHash("Brucie", MODEL_IG_BRUCIE2);
	menu_addAction();
	menu_addItemHash("Bulgarin", MODEL_IG_BULGARIN2);
	menu_addAction();
	menu_addItemHash("Daisy", MODEL_IG_DAISY);
	menu_addAction();
	menu_addItemHash("DeeJay", MODEL_IG_DEEJAY);
	menu_addAction();
	menu_addItemHash("Dessie", MODEL_IG_DESSIE);
	menu_addAction();
	menu_addItemHash("Evan", MODEL_IG_EVAN);
	menu_addAction();
	menu_addItemHash("Gracie", MODEL_IG_GRACIE2);
	menu_addAction();
	menu_addItemHash("Henrique", MODEL_IG_HENRIQUE);
	menu_addAction();
	menu_addItemHash("Issac", MODEL_IG_ISSAC2);
	menu_addAction();
	menu_addItemHash("Johnny", MODEL_IG_JOHNNY2);
	menu_addAction();
	menu_addItemHash("Luis", MODEL_IG_LUIS2);
	menu_addAction();
	menu_addItemHash("Margot", MODEL_IG_MARGOT);
	menu_addAction();
	menu_addItemHash("Mori K", MODEL_IG_MORI_K);
	menu_addAction();
	menu_addItemHash("Mr Santos", MODEL_IG_MR_SANTOS);
	menu_addAction();
	menu_addItemHash("Niko", MODEL_IG_NIKO);
	menu_addAction();
	menu_addItemHash("Oyvey", MODEL_IG_OYVEY);
	menu_addAction();
	menu_addItemHash("Rocco", MODEL_IG_ROCCO);
	menu_addAction();
	menu_addItemHash("Tahir", MODEL_IG_TAHIR);
	menu_addAction();
	menu_addItemHash("Timur", MODEL_IG_TIMUR);
	menu_addAction();
	menu_addItemHash("Tony", MODEL_IG_TONY);
	menu_addAction();
	menu_addItemHash("Tramp", MODEL_IG_TRAMP2);
	menu_addAction();
	menu_addItemHash("Triad", MODEL_IG_TRIAD);
	menu_addAction();
	menu_addItemHash("Troy", MODEL_IG_TROY);
	menu_addAction();
	menu_addItemHash("Vic", MODEL_IG_VIC);
	menu_addAction();
	menu_addItemHash("Vic Girl", MODEL_IG_VICGIRL);
	menu_addAction();
	menu_addItemHash("Vince", MODEL_IG_VINCE);
	menu_addAction();
	menu_addItemHash("Yusef", MODEL_IG_YUSEF);
	menu_addAction();
}

void player_model_TBOGT_gangs(void)
{
	menu_addItemHash("Angels 1", MODEL_M_Y_GANGELS_02);
	menu_addAction();
	menu_addItemHash("Angels 2", MODEL_M_Y_GANGELS_04);
	menu_addAction();
	menu_addItemHash("Lost 1", MODEL_M_Y_GLOST_01);
	menu_addAction();
	menu_addItemHash("Lost 2", MODEL_M_Y_GLOST_02);
	menu_addAction();
	menu_addItemHash("Triad 1", MODEL_M_Y_GTRIAD_HI_01);
	menu_addAction();
	menu_addItemHash("Triad 2", MODEL_M_Y_GTRI_02);
	menu_addAction();
}

void player_model_TBOGT_ambients(void)
{
	menu_addItemHash("AsianClub 1", MODEL_F_Y_ASIANCLUB_01);
	menu_addAction();
	menu_addItemHash("AsianClub 2", MODEL_F_Y_ASIANCLUB_02);
	menu_addAction();
	menu_addItemHash("Clubeuro 1", MODEL_F_Y_CLUBEURO_01);
	menu_addAction();
	menu_addItemHash("DomGirl 1", MODEL_F_Y_DOMGIRL_01);
	menu_addAction();
	menu_addItemHash("E MidTown 1", MODEL_F_Y_EMIDTOWN_02);
	menu_addAction();
	menu_addItemHash("Hostess", MODEL_F_Y_HOSTESS);
	menu_addAction();
	menu_addItemHash("HotChick 1", MODEL_F_Y_HOTCHICK_01);
	menu_addAction();
	menu_addItemHash("HotChick 2", MODEL_F_Y_HOTCHICK_02);
	menu_addAction();
	menu_addItemHash("HotChick 3", MODEL_F_Y_HOTCHICK_03);
	menu_addAction();
	menu_addItemHash("P Girl 1", MODEL_F_Y_PGIRL_01);
	menu_addAction();
	menu_addItemHash("P Girl 2", MODEL_F_Y_PGIRL_02);
	menu_addAction();
	menu_addItemHash("Mid", MODEL_F_Y_SMID_01);
	menu_addAction();
	menu_addItemHash("Trendy", MODEL_F_Y_TRENDY_01);
	menu_addAction();
	menu_addItemHash("Mafia 1", MODEL_M_M_E2MAF_01);
	menu_addAction();
	menu_addItemHash("Mafia 2", MODEL_M_M_E2MAF_02);
	menu_addAction();
	menu_addItemHash("Amir Guard", MODEL_M_Y_AMIRGUARD_01);
	menu_addAction();
	menu_addItemHash("Bathroom", MODEL_M_Y_BATHROOM);
	menu_addAction();
	menu_addItemHash("Bar Maison", MODEL_M_Y_BARMAISON);
	menu_addAction();
	menu_addItemHash("FIB 1", MODEL_M_Y_CIADLC_01);
	menu_addAction();
	menu_addItemHash("FIB 2", MODEL_M_Y_CIADLC_02);
	menu_addAction();
	menu_addItemHash("Club Black", MODEL_M_Y_CLUBBLACK_01);
	menu_addAction();
	menu_addItemHash("Club Euro 1", MODEL_M_Y_CLUBEURO_01);
	menu_addAction();
	menu_addItemHash("Club Euro 2", MODEL_M_Y_CLUBEURO_02);
	menu_addAction();
	menu_addItemHash("Club Euro 3", MODEL_M_Y_CLUBEURO_03);
	menu_addAction();
	menu_addItemHash("Club White", MODEL_M_Y_CLUBWHITE_01);
	menu_addAction();
	menu_addItemHash("Domdrug", MODEL_M_Y_DOMDRUG_01);
	menu_addAction();
	menu_addItemHash("Domguy 1", MODEL_M_Y_DOMGUY_01);
	menu_addAction();
	menu_addItemHash("Domguy 2", MODEL_M_Y_DOMGUY_02);
	menu_addAction();
	menu_addItemHash("Doorman", MODEL_M_Y_DOORMAN_02);
	menu_addAction();
	menu_addItemHash("Russian 1", MODEL_M_Y_E2RUSSIAN_01);
	menu_addAction();
	menu_addItemHash("Russian 2", MODEL_M_Y_E2RUSSIAN_02);
	menu_addAction();
	menu_addItemHash("Russian 3", MODEL_M_Y_E2RUSSIAN_03);
	menu_addAction();
	menu_addItemHash("Gay Black", MODEL_M_Y_GAYBLACK_01);
	menu_addAction();
	menu_addItemHash("Gay Dancer", MODEL_M_Y_GAYDANCER);
	menu_addAction();
	menu_addItemHash("Gay Gang", MODEL_M_Y_GAYGANG_01);
	menu_addAction();
	menu_addItemHash("GayGeneral", MODEL_M_Y_GAYGENERAL_01);
	menu_addAction();
	menu_addItemHash("Gay White", MODEL_M_Y_GAYWHITE_01);
	menu_addAction();
	menu_addItemHash("Guido 1", MODEL_M_Y_GUIDO_01);
	menu_addAction();
	menu_addItemHash("Guido 2", MODEL_M_Y_GUIDO_02);
	menu_addAction();
	menu_addItemHash("MidEast", MODEL_M_Y_MIDEAST_01);
	menu_addAction();
	menu_addItemHash("Uptown", MODEL_M_Y_UPTOWN_01);
	menu_addAction();
}

void player_model_TBOGT_fighters(void)
{
	menu_addItemHash("FightClub 1", MODEL_M_Y_FIGHTCLUB_01);
	menu_addAction();
	menu_addItemHash("FightClub 2", MODEL_M_Y_FIGHTCLUB_02);
	menu_addAction();
	menu_addItemHash("FightClub 3", MODEL_M_Y_FIGHTCLUB_03);
	menu_addAction();
	menu_addItemHash("FightClub 4", MODEL_M_Y_FIGHTCLUB_04);
	menu_addAction();
	menu_addItemHash("FightClub 5", MODEL_M_Y_FIGHTCLUB_05);
	menu_addAction();
	menu_addItemHash("FightClub 6", MODEL_M_Y_FIGHTCLUB_06);
	menu_addAction();
	menu_addItemHash("FightClub 7", MODEL_M_Y_FIGHTCLUB_07);
	menu_addAction();
	menu_addItemHash("FightClub 8", MODEL_M_Y_FIGHTCLUB_08);
	menu_addAction();
}

void player_model_TBOGT_MissionSpecific(void)
{
	menu_addItemHash("Cloe Parker", MODEL_F_Y_CLOEPARKER);
	menu_addAction();
	menu_addItemHash("Dancer", MODEL_F_Y_DANCER_01);
	menu_addAction();
	menu_addItemHash("Joni", MODEL_F_Y_JONI);
	menu_addAction();
	menu_addItemHash("Mafia Union", MODEL_M_M_MAFUNION);
	menu_addAction();
	menu_addItemHash("Celeb Blog", MODEL_M_Y_CELEBBLOG);
	menu_addAction();
	menu_addItemHash("ExSports", MODEL_M_Y_EXSPORTS);
	menu_addAction();
	menu_addItemHash("Mob Party", MODEL_M_Y_MOBPARTY);
	menu_addAction();
	menu_addItemHash("Paparazzi", MODEL_M_Y_PAPARAZZI_01);
	menu_addAction();
	menu_addItemHash("Blue Bros", MODEL_IG_BLUEBROS);
	menu_addAction();
	menu_addItemHash("Jackson", MODEL_IG_JACKSON);
	menu_addAction();
	menu_addItemHash("Napoli", MODEL_IG_NAPOLI);
	menu_addAction();
	menu_addItemHash("Royal", MODEL_IG_ROYAL);
	menu_addAction();
	menu_addItemHash("Spade", MODEL_IG_SPADE);
	menu_addAction();
}

/*void player_model_TBOGT_cutscene(void)
{
	menu_addItemHash("Baz", MODEL_CS_BAZ);
	menu_addAction();
	menu_addItemHash("Jeremy", MODEL_CS_JEREMY);
	menu_addAction();
	menu_addItemHash("Niko", MODEL_CS_NIKO);
	menu_addAction();
	menu_addItemHash("Abdul", MODEL_CS_ABDUL);
	menu_addAction();
	menu_addItemHash("Abodyguard", MODEL_CS_ABODYGUARD);
	menu_addAction();
	menu_addItemHash("Adriana", MODEL_CS_ADRIANA);
	menu_addAction();
	menu_addItemHash("Ahmad", MODEL_CS_AHMAD);
	menu_addAction();
	menu_addItemHash("Armando", MODEL_CS_ARMANDO);
	menu_addAction();
	menu_addItemHash("Arnaud", MODEL_CS_ARNAUD);
	menu_addAction();
	menu_addItemHash("Bathroom", MODEL_CS_BATHROOM);
	menu_addAction();
	menu_addItemHash("Billy 2", MODEL_CS_BILLY2);
	menu_addAction();
	menu_addItemHash("Bulgarin 2", MODEL_CS_BULGARIN2);
	menu_addAction();
	menu_addItemHash("Brucie 2", MODEL_CS_BRUCIE2);
	menu_addAction();
	menu_addItemHash("Daisy", MODEL_CS_DAISY);
	menu_addAction();
	menu_addItemHash("Derrick 2", MODEL_CS_DERRICK2);
	menu_addAction();
	menu_addItemHash("Dessie", MODEL_CS_DESSIE);
	menu_addAction();
	menu_addItemHash("DockGoon", MODEL_CS_DOCKGOON);
	menu_addAction();
	menu_addItemHash("Eugene", MODEL_CS_EUGENE);
	menu_addAction();
	menu_addItemHash("Evan2", MODEL_CS_EVAN2);
	menu_addAction();
	menu_addItemHash("Gparty 1", MODEL_CS_GPARTY_01);
	menu_addAction();
	menu_addItemHash("Gracie 2", MODEL_CS_GRACIE2);
	menu_addAction();
	menu_addItemHash("Henrique", MODEL_CS_HENRIQUE);
	menu_addAction();
	menu_addItemHash("Issac 2", MODEL_CS_ISSAC2);
	menu_addAction();
	menu_addItemHash("Johnny 2", MODEL_CS_JOHNNY2);
	menu_addAction();
	menu_addItemHash("Margot", MODEL_CS_MARGOT);
	menu_addAction();
	menu_addItemHash("Maurice", MODEL_CS_MAURICE);
	menu_addAction();
	menu_addItemHash("Mori_k", MODEL_CS_MORI_K);
	menu_addAction();
	menu_addItemHash("Mr_Santos", MODEL_CS_MR_SANTOS);
	menu_addAction();
	menu_addItemHash("Niko 2", MODEL_CS_NIKO2);
	menu_addAction();
	menu_addItemHash("Oyvey", MODEL_CS_OYVEY);
	menu_addAction();
	menu_addItemHash("Packie 2", MODEL_CS_PACKIE2);
	menu_addAction();
	menu_addItemHash("Papi", MODEL_CS_PAPI);
	menu_addAction();
	menu_addItemHash("Rocco", MODEL_CS_ROCCO);
	menu_addAction();
	menu_addItemHash("Roman2", MODEL_CS_ROMAN2);
	menu_addAction();
	menu_addItemHash("Rus_KN", MODEL_CS_RUS_KN);
	menu_addAction();
	menu_addItemHash("Sharon", MODEL_CS_SHARON);
	menu_addAction();
	menu_addItemHash("Tahir", MODEL_CS_TAHIR);
	menu_addAction();
	menu_addItemHash("Timur", MODEL_CS_TIMUR);
	menu_addAction();
	menu_addItemHash("Tony", MODEL_CS_TONY);
	menu_addAction();
	menu_addItemHash("TonyAq", MODEL_CS_TONYAQ);
	menu_addAction();
	menu_addItemHash("Tramp2", MODEL_CS_TRAMP2);
	menu_addAction();
	menu_addItemHash("Triad", MODEL_CS_TRIAD);
	menu_addAction();
	menu_addItemHash("Troy", MODEL_CS_TROY);
	menu_addAction();
	menu_addItemHash("Vic", MODEL_CS_VIC);
	menu_addAction();
	menu_addItemHash("VicGirl", MODEL_CS_VICGIRL);
	menu_addAction();
	menu_addItemHash("Vince", MODEL_CS_VINCE);
	menu_addAction();
	menu_addItemHash("Yusef", MODEL_CS_YUSEF);
	menu_addAction();
}*/
#endif

void player_model_gamecat_set(uint game)
{
	if (game == 1)
	{
		if (item_selected == 1)
			player_model_GTAIV_story1();
		else if (item_selected == 2)
			player_model_GTAIV_story2();
		else if (item_selected == 3)
			player_model_GTAIV_gangs();
		else if (item_selected == 4)
			player_model_GTAIV_M_foreground1();
		else if (item_selected == 5)
			player_model_GTAIV_M_foreground2();
		else if (item_selected == 6)
			player_model_GTAIV_M_background1();
		else if (item_selected == 7)
			player_model_GTAIV_M_background2();
		else if (item_selected == 8)
			player_model_GTAIV_F_foreground();
		else if (item_selected == 9)
			player_model_GTAIV_F_background();
	}
	else if (game == 2)
	{
		#ifdef TLAD
			if (item_selected == 1)
				player_model_TLAD_story();
			else if (item_selected == 2)
				player_model_TLAD_gangs();
			else if (item_selected == 3)
				player_model_TLAD_buddies();
			else if (item_selected == 4)
				player_model_TLAD_ambients();
		#endif
		#ifdef TBOGT
			if (item_selected == 1)
				player_model_TBOGT_story();
			else if (item_selected == 2)
				player_model_TBOGT_gangs();
			else if (item_selected == 3)
				player_model_TBOGT_ambients();
			else if (item_selected == 4)
				player_model_TBOGT_fighters();
			else if (item_selected == 5)
				player_model_TBOGT_MissionSpecific();
		#endif
	}
}

void player_appearance_cat(void)
{
	menu_header = trainer_appearance;
	/*head
	uppr
	lowr
	suse
	hand
	feet
	jack
	hair
	sus2
	teef*/
	menu_addItem(trainer_randomvariation);
	menu_addAction();
	menu_addItem(trainer_face);
	menu_addItem(trainer_torso);
	menu_addItem(trainer_legs);
	menu_addItem(trainer_hands);
	menu_addItem(trainer_shoes);
	menu_addItem(trainer_hair);
	menu_addItem(trainer_jack);
	menu_addItem(trainer_suse);
	menu_addItem(trainer_suse2);
}

void player_appearance_apply()
{
	if (item_selected == 1)
		SET_CHAR_RANDOM_COMPONENT_VARIATION(GetPlayerPed());
}

void player_appearance_vt(bool getCurrent)
{
	uint component = last_selected[3];

	if (component == 2)
		component = 0;
	else if (component == 3)
		component = 1;
	else if (component == 4)
		component = 2;
	else if (component == 5)
		component = 4;
	else if (component == 6)
		component = 5;
	else if (component == 7)
		component = 7;

	else if (component == 8)
		component = 3;
	else if (component == 9)
		component = 6;
	else if (component == 10)
		component = 8;

	uint num_variations = GET_NUMBER_OF_CHAR_DRAWABLE_VARIATIONS(GetPlayerPed(), component);
	uint num_textures = GET_NUMBER_OF_CHAR_TEXTURE_VARIATIONS(GetPlayerPed(), component, menu_item[1].num_val - 1);

	if (num_variations > 1 || num_textures > 1)
	{
		menu_addItem(trainer_modelvariation);
		if (getCurrent)
			menu_addItemNumber(GET_CHAR_DRAWABLE_VARIATION(GetPlayerPed(), component) + 1, num_variations);
		else
			menu_addItemNumber(menu_item[1].num_val, num_variations);
		menu_addAction();
	}

	if (num_textures > 1)
	{
		menu_addItem(trainer_texturevariation);
		if (getCurrent)
			menu_addItemNumber(GET_CHAR_TEXTURE_VARIATION(GetPlayerPed(), component) + 1, num_textures);
		else
			menu_addItemNumber(1, num_textures);
		menu_addAction();
	}

	if (num_variations < 2 && num_textures < 2)
		project_error(TRAINER_ERROR_ID_APPEARANCE_NA);

}

void player_appearance_vt_apply(void)
{
	uint component = last_selected[3], 
	model_variation = menu_item[1].num_val - 1, 
	texture_variation = menu_item[2].num_val - 1;

	if (component == 2)
		component = 0;
	else if (component == 3)
		component = 1;
	else if (component == 4)
		component = 2;
	else if (component == 5)
		component = 4;
	else if (component == 6)
		component = 5;
	else if (component == 7)
		component = 7;

	else if (component == 8)
		component = 3;
	else if (component == 9)
		component = 6;
	else if (component == 10)
		component = 8;

	if (!inError)
		SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), component, model_variation, texture_variation);
}

void player_accessories(void)
{
	menu_header = trainer_accessories;
	menu_addItem(trainer_head);
	uint prop1;
	GET_CHAR_PROP_INDEX(GetPlayerPed(), false, &prop1);	
	if (prop1 > 1)
		prop1 = prop1 + 2;
	else
		prop1 = 1;
	menu_addItemNumber(prop1, 10);
	menu_addAction();

	menu_addItem(trainer_headtxd);
	menu_addItemNumber(1, 10);
	menu_addAction();

	menu_addItem(trainer_face);
	uint prop2;
	GET_CHAR_PROP_INDEX(GetPlayerPed(), true, &prop2);
	if (prop2 > 1)
		prop2 = prop2 + 2;
	else
		prop2 = 1;
	menu_addItemNumber(prop2, 10);
	menu_addAction();
}

void player_accessories_apply(void)
{
	uint index, type;

	if (item_selected == 3)
	{
		index = menu_item[3].num_val - 2;
		type = 1;
	}
	else
	{
		index = menu_item[1].num_val - 2;
		type = 0;
	}

	if ((item_selected == 1 && menu_item[1].num_val == 1) || (item_selected == 3 && menu_item[3].num_val == 1))
		CLEAR_CHAR_PROP(GetPlayerPed(), type);
	else
		SET_CHAR_PROP_INDEX_TEXTURE(GetPlayerPed(), type, index, menu_item[2].num_val - 1);
}

void player_weapons_cat(void)
{
	menu_header = trainer_weapons;
	menu_addItem(trainer_gtaiv);
	#ifdef TLAD
		menu_addItem(trainer_tlad);
	#endif
	#ifdef TBOGT
		menu_addItem(trainer_tbogt);
	#endif
}

void player_weapons(void)
{
	uint maxAmmo;

	menu_addItem(trainer_allpoor);
	menu_addAction();

	menu_addItem(trainer_alladvanced);
	menu_addAction();

	menu_addItem(trainer_removeall);
	menu_addAction();

	menu_addItem(trainer_maxammocap);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_GRENADE, &maxAmmo);
	bool maxCap;

	if (maxAmmo == 25)
		maxCap = true;

	menu_addItemBool(maxCap);
	menu_addAction();
}

void player_weapons_GTAIV(void)
{
	uint maxAmmo;

	menu_addItem(trainer_baseball);
	menu_addAction();

	menu_addItem(trainer_poolcue);
	menu_addAction();

	menu_addItem(trainer_knife);
	menu_addAction();

	GET_MAX_AMMO(GetPlayerPed(), WEAPON_GRENADE, &maxAmmo);
	bool maxCap;

	if (maxAmmo == 25)
		maxCap = true;

	if (!maxCap)
		ENABLE_MAX_AMMO_CAP(true);

	menu_addItem(trainer_grenade);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_GRENADE, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_molotov);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_MOLOTOV, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_9mm);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_PISTOL, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_deagle);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_DEAGLE, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_pshotgun);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_SHOTGUN, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_shotgun);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_BARETTA, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_mircosmg);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_MICRO_UZI, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_smg);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_MP5, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_ak47);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_AK47, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_m4);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_M4, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_combatsniper);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_M40A1, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_sniperrifle);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_SNIPERRIFLE, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem(trainer_rpg);
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_RLAUNCHER, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	if (!maxCap)
		ENABLE_MAX_AMMO_CAP(false);
}

#ifdef TLAD
void player_weapons_TLAD(void)
{
	uint maxAmmo;

	GET_MAX_AMMO(GetPlayerPed(), WEAPON_GRENADE, &maxAmmo);
	bool maxCap;

	if (maxAmmo == 25)
		maxCap = true;

	if (!maxCap)
		ENABLE_MAX_AMMO_CAP(true);

	menu_addItem("Grenade L");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_1, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Sweeper");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_2, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Pool Cue");
	menu_addItemNumber(1, 1);
	menu_addAction();

	menu_addItem("Sawnoff");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_6, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Semi-Auto");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_7, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Pipe Bomb");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_8, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	if (!maxCap)
		ENABLE_MAX_AMMO_CAP(false);
}
#endif

#ifdef TBOGT
void player_weapons_TBOGT(void)
{
	uint maxAmmo;

	GET_MAX_AMMO(GetPlayerPed(), WEAPON_GRENADE, &maxAmmo);
	bool maxCap;

	if (maxAmmo == 25)
		maxCap = true;

	if (!maxCap)
		ENABLE_MAX_AMMO_CAP(true);

	menu_addItem("Pistol 44");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_9, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Exp AA12");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_10, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("AA12");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_11, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("P90");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_12, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Uzi");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_13, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("M249");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_14, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("DSR-1 Sniper");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_15, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Sticky Bomb");
	GET_MAX_AMMO(GetPlayerPed(), WEAPON_EPISODIC_16, &maxAmmo);
	menu_addItemNumber(maxAmmo, maxAmmo);
	menu_addAction();

	menu_addItem("Parachute");
	menu_addItemNumber(1, 1);
	menu_addAction();

	if (!maxCap)
		ENABLE_MAX_AMMO_CAP(false);
}
#endif

void player_weapons_options_apply(void)
{
	if (item_selected == 1)
		ACTIVATE_CHEAT(0);
	else if (item_selected == 2)
		ACTIVATE_CHEAT(1);
	else if (item_selected == 3)
		REMOVE_ALL_CHAR_WEAPONS(GetPlayerPed());
	else if (item_selected == 4)
	{
		if (menu_item[item_selected].extra_val)
		{
			ENABLE_MAX_AMMO_CAP(false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			ENABLE_MAX_AMMO_CAP(true);
			menu_item[item_selected].extra_val = true;
		}
	}
}

void player_weapons_apply(void)
{
	if (item_selected >= 5)
	{
		uint weapon = item_selected - 4;
		
		if (last_selected[3] == 2)
		{
			#ifdef TLAD
				weapon += 20;

				if (weapon >= 23)
					weapon++;

				if (weapon >= 25)
					weapon++;
			#endif
			#ifdef TBOGT
				weapon += 28;

				if (weapon == 37)
					weapon = 41;
			#endif
		}
		else
		{
			if (weapon >= 6)
				weapon++;

			if (weapon >= 8)
				weapon++;
		}

		GIVE_WEAPON_TO_CHAR(GetPlayerPed(), weapon, menu_item[item_selected].num_val, false);
		SET_CURRENT_CHAR_WEAPON(GetPlayerPed(), weapon, true);
	}
}

void player_health(void)
{
	menu_header = trainer_health;
	menu_addItem(trainer_health);
	uint current_health;
	GET_CHAR_HEALTH(GetPlayerPed(), &current_health);
	menu_addItemNumber(current_health - 100, 100);
	menu_addAction();

	menu_addItem(trainer_addarmour);
	menu_addAction();

	menu_addItem(trainer_removearmour);
	menu_addAction();

	bool invincible;
	if (GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("3s_trainer_health") == 1)
		invincible = true;

	menu_addItem(trainer_invincible);
	menu_addItemBool(invincible);
	menu_addAction();
}

void player_health_apply(void)
{
	bool option_enabled = menu_item[item_selected].extra_val;

	if (item_selected == 1)
		SET_CHAR_HEALTH(GetPlayerPed(), menu_item[item_selected].num_val + 100);
	else if (item_selected == 2)
		ADD_ARMOUR_TO_CHAR(GetPlayerPed(), 100);
	else if (item_selected == 3)
		ADD_ARMOUR_TO_CHAR(GetPlayerPed(), -100);
	else if (item_selected == 4)
	{
		if (option_enabled)
		{
			TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("3s_trainer_health");
			SET_PLAYER_INVINCIBLE(GetPlayerIndex(), false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			if (!script_loaded)
				load_script = "3s_trainer_health";
			else
			{
				TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("3s_trainer_health");
				START_NEW_SCRIPT("3s_trainer_health", 128);
				MARK_SCRIPT_AS_NO_LONGER_NEEDED("3s_trainer_health");
				script_loaded = false;
				menu_item[item_selected].extra_val = true;
			}
		}
	}
}

void player_wanted(void)
{
	menu_header = trainer_wanted;
	menu_addItem(trainer_clearwanted);
	menu_addAction();

	uint wantedLevel;
	STORE_WANTED_LEVEL(GetPlayerIndex(), &wantedLevel);

	if (wantedLevel == 0)
		wantedLevel = 1;

	menu_addItem(trainer_wantedlevel);
	menu_addItemNumber(wantedLevel, 6);
	menu_addAction();

	menu_addItem(trainer_wantedmulti);
	menu_addItemFloat(0, 10);
	menu_addAction();

	bool neverwanted;
	if (GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("3s_trainer_wanted") == 1)
		neverwanted = true;

	menu_addItem(trainer_neverwanted);
	menu_addItemBool(neverwanted);
	menu_addAction();
}

void player_wanted_apply(void)
{
	if (item_selected == 1)
		CLEAR_WANTED_LEVEL(GetPlayerIndex());
	else if (item_selected == 2)
	{
		ALTER_WANTED_LEVEL(GetPlayerIndex(), menu_item[item_selected].num_val);
		APPLY_WANTED_LEVEL_CHANGE_NOW(GetPlayerIndex());
	}
	else if (item_selected == 3)
		SET_WANTED_MULTIPLIER(menu_item[item_selected].float_val);
	else if (item_selected == 4)
	{
		if (menu_item[item_selected].extra_val)
		{
			TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("3s_trainer_wanted");
			SET_WANTED_MULTIPLIER(1.0);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			if (!script_loaded)
				load_script = "3s_trainer_wanted";
			else
			{
				TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("3s_trainer_wanted");
				START_NEW_SCRIPT("3s_trainer_wanted", 128);
				MARK_SCRIPT_AS_NO_LONGER_NEEDED("3s_trainer_wanted");
				script_loaded = false;
				menu_item[item_selected].extra_val = true;
			}
		}
	}
}