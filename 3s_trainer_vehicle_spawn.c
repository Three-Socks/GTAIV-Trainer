/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

void gms_spawn_cat(void)
{
	menu_header = trainer_spawn;
	menu_addItem(trainer_gtaiv);
	if (GET_CURRENT_EPISODE() == 1 || GET_CURRENT_EPISODE() == 2)
	{
		menu_addItem(trainer_tlad);
		menu_addItem(trainer_tbogt);
	}
}

void gms_spawn(void)
{
	if (item_selected == 1)
	{
		menu_addItem(trainer_sports);
		menu_addItem(trainer_musclevintage);
		menu_addItem(trainer_twodoors);
		menu_addItem(trainer_fourdoor);
		menu_addItem(trainer_fourdoor2);
		menu_addItem(trainer_beater);
		menu_addItem(trainer_spv);
		menu_addItem(trainer_ci);
		menu_addItem(trainer_ci2);
		menu_addItem(trainer_emergency);
		menu_addItem(trainer_service);
		menu_addItem(trainer_motorcycles);
		menu_addItem(trainer_boats);
		menu_addItem(trainer_aircraft);
	}
	else if (item_selected == 2)
	{
		menu_addItem(trainer_cars);
		menu_addItem(trainer_motorcycles);
		menu_addItem(trainer_motorcycles2);
	}
	else if (item_selected == 3)
	{
		menu_addItem(trainer_cars);
		menu_addItem(trainer_cars2);
		menu_addItem(trainer_motorcycles);
		menu_addItem(trainer_boats);
		menu_addItem(trainer_aircraft);
	}
}

void gms_spawn_apply(void)
{
	uint vehicle_model = menu_item[item_selected].num_val;

	GET_CAR_CHAR_IS_USING(GetPlayerPed(), &v_modding);

	//GET_CHAR_SPEED(Ped ped, float *pValue);

	float curSpeed, curHeading, curX, curY, curZ;
	if (DOES_VEHICLE_EXIST(v_modding))
	{
		GET_CAR_SPEED(v_modding, &curSpeed);
		GET_CAR_HEADING(v_modding, &curHeading);
		GET_CAR_COORDINATES(v_modding, &curX, &curY, &curZ);
		DELETE_CAR(&v_modding);
	}
	else
	{
		GET_CHAR_HEADING(GetPlayerPed(), &curHeading);
		GET_CHAR_COORDINATES(GetPlayerPed(), &curX, &curY, &curZ);
	}

	CREATE_CAR(vehicle_model, curX, curY, curZ, &v_modding, true);
	SET_CAR_HEADING(v_modding, curHeading);
	SET_CAR_COORDINATES(v_modding, curX, curY, curZ);

	SET_HAS_BEEN_OWNED_BY_PLAYER(v_modding, true);
	SET_NEEDS_TO_BE_HOTWIRED(v_modding, false);
	SET_CAR_ENGINE_ON(v_modding, true, true);

	if (IS_THIS_MODEL_A_HELI(vehicle_model))
		SET_HELI_BLADES_FULL_SPEED(v_modding);

	MARK_MODEL_AS_NO_LONGER_NEEDED(vehicle_model);
	model_loaded = false;
	//model_wait = 0;

	WARP_CHAR_INTO_CAR(GetPlayerPed(), v_modding);

	if (IS_INTERIOR_SCENE())
	{
		float cGroundZ;
		GET_GROUND_Z_FOR_3D_COORD(curX, curY, curZ, &cGroundZ);
		SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), curX, curY, cGroundZ);
		LOAD_SCENE(curX, curY, curZ);
	}
	
	if (curSpeed != 0)
		SET_CAR_FORWARD_SPEED(v_modding, curSpeed);
}

void gms_spawn_list(void)
{
	if (last_selected[3] == 1)
	{
		if (item_selected == 1)
		{
			menu_addItemGXTHash(MODEL_BANSHEE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_COMET);
			menu_addAction();
			menu_addItemGXTHash(MODEL_COQUETTE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FELTZER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_INFERNUS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SULTAN);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SULTANRS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SUPERGT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TURISMO);
			menu_addAction();
		}
		else if (item_selected == 2)
		{
			menu_addItemGXTHash(MODEL_BUCCANEER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DUKES);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FACTION);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MANANA);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PEYOTE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_RUINER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SABRE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SABREGT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_STALION);
			menu_addAction();
			menu_addItemGXTHash(MODEL_VIGERO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_VIRGO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_VOODOO);
			menu_addAction();
		}
		else if (item_selected == 3)
		{
			menu_addItemGXTHash(MODEL_BLISTA);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FORTUNE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FUTO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SENTINEL);
			menu_addAction();
			menu_addItemGXTHash(MODEL_URANUS);
			menu_addAction();
		}
		else if (item_selected == 4)
		{
			menu_addItemGXTHash(MODEL_ADMIRAL);
			menu_addAction();
			menu_addItemGXTHash(MODEL_CHAVOS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_COGNOSCENTI);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DF8);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DILETTANTE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_EMPEROR);
			menu_addAction();
			menu_addItemGXTHash(MODEL_ESPERANTO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FEROCI);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HAKUMAI);
			menu_addAction();
			menu_addItemGXTHash(MODEL_INGOT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_INTRUDER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_LOKUS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MARBELLA);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MERIT);
			menu_addAction();
		}
		else if (item_selected == 5)
		{
			menu_addItemGXTHash(MODEL_ORACLE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PINNACLE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PMP600);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PREMIER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PRES);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PRIMO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_ROM);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SCHAFTER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SOLAIR);
			menu_addAction();
			menu_addItemGXTHash(MODEL_STRATUM);
			menu_addAction();
			menu_addItemGXTHash(MODEL_STRETCH);
			menu_addAction();
			menu_addItemGXTHash(MODEL_VINCENT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_WASHINGTON);
			menu_addAction();
			menu_addItemGXTHash(MODEL_WILLARD);
			menu_addAction();
		}
		else if (item_selected == 6)
		{
			menu_addItemGXTHash(MODEL_EMPEROR2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SABRE2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_VIGERO2);
			menu_addAction();
		}
		else if (item_selected == 7)
		{
			menu_addItemGXTHash(MODEL_BOBCAT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_CAVALCADE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FXT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_E109);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HABANERO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HUNTLEY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_LANDSTALKER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MINIVAN);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MOONBEAM);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PATRIOT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PERENNIAL);
			menu_addAction();
			menu_addItemGXTHash(MODEL_RANCHER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_REBLA);
			menu_addAction();
		}
		else if (item_selected == 8)
		{
			menu_addItemGXTHash(MODEL_AIRTUG);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BENSON);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BIFF);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BOXVILLE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BURRITO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FLATBED);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FEROCI2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PERENNIAL2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FORKLIFT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BURRITO2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MRTASTY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MULE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PACKER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PHANTOM);
			menu_addAction();
		}
		else if (item_selected == 9)
		{
			menu_addItemGXTHash(MODEL_PONY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_RIPLEY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_STOCKADE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SPEEDO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_STEED);
			menu_addAction();
			menu_addItemGXTHash(MODEL_YANKEE);
			menu_addAction();
		}
		else if (item_selected == 10)
		{
			menu_addItemGXTHash(MODEL_AMBULANCE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_NSTOCKADE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FBI);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FIRETRUK);
			menu_addAction();
			menu_addItemGXTHash(MODEL_NOOSE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_POLPATRIOT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_POLICE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_POLICE2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PSTOCKADE);
			menu_addAction();
		}
		else if (item_selected == 11)
		{
			menu_addItemGXTHash(MODEL_BUS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_CABBY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_ROMERO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TAXI);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TAXI2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TRASH);
			menu_addAction();
		}
		else if (item_selected == 12)
		{
			menu_addItemGXTHash(MODEL_FAGGIO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BOBBER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HELLFURY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_NRG900);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PCJ);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SANCHEZ);
			menu_addAction();
			menu_addItemGXTHash(MODEL_ZOMBIEB);
			menu_addAction();
		}
		else if(item_selected == 13)
		{
			menu_addItemGXTHash(MODEL_DINGHY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_JETMAX);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MARQUIS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PREDATOR);
			menu_addAction();
			menu_addItemGXTHash(MODEL_REEFER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SQUALO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TROPIC);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TUGA);
			menu_addAction();
		}
		else if (item_selected == 14)
		{
			menu_addItemGXTHash(MODEL_ANNIHILATOR);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TOURMAV);
			menu_addAction();
			menu_addItemGXTHash(MODEL_MAVERICK);
			menu_addAction();
			menu_addItemGXTHash(MODEL_POLMAV);
			menu_addAction();
		}
	}
	else if (last_selected[3] == 2)
	{
		if (item_selected == 1)
		{
			menu_addItemGXTHash(MODEL_GBURRITO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SLAMVAN);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TOWTRUCK);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PACKER2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_PBUS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_YANKEE2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_RHAPSODY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_REGINA);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TAMPA);
			menu_addAction();
		}
		else if (item_selected == 2)
		{
			menu_addItemGXTHash(MODEL_ANGEL);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BATI);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BATI2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DAEMON);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DIABOLUS);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DOUBLE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DOUBLE2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HAKUCHOU);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HAKUCHOU2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HEXER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_INNOVATION);
			menu_addAction();
			menu_addItemGXTHash(MODEL_LYCAN);
			menu_addAction();
			menu_addItemGXTHash(MODEL_NIGHTBLADE);
			menu_addAction();
			menu_addItemGXTHash(MODEL_REVENANT);
			menu_addAction();
		}
		else if (item_selected == 3)
		{
			menu_addItemGXTHash(MODEL_WAYFARER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_WOLFSBANE);
			menu_addAction();
		}
	}
	else if (last_selected[3] == 3)
	{
		if (item_selected == 1)
		{
			menu_addItemGXTHash(MODEL_SLAMVAN);
			menu_addAction();
			menu_addItemGXTHash(MODEL_CADDY);
			menu_addAction();
			menu_addItemGXTHash(MODEL_APC);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SUPERD);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SUPERD2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SERRANO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SERRANO2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BUFFALO);
			menu_addAction();
			menu_addItemGXTHash(MODEL_AVAN);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SCHAFTER2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SCHAFTER3);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BULLET);
			menu_addAction();
			menu_addItemGXTHash(MODEL_TAMPA);
			menu_addAction();
			menu_addItemGXTHash(MODEL_CAVALCADE2);
			menu_addAction();
		}
		else if (item_selected == 2)
		{
			menu_addItemGXTHash(MODEL_F620);
			menu_addAction();
			menu_addItemGXTHash(MODEL_LIMO2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_POLICE3);
			menu_addAction();
			menu_addItemGXTHash(MODEL_POLICEW);
			menu_addAction();
			menu_addItemGXTHash(MODEL_POLICE4);
			menu_addAction();
		}
		else if (item_selected == 3)
		{
			menu_addItemGXTHash(MODEL_POLICEB);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HEXER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FAGGIO2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BATI2);
			menu_addAction();
			menu_addItemGXTHash(MODEL_VADER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_AKUMA);
			menu_addAction();
			menu_addItemGXTHash(MODEL_HAKUCHOU);
			menu_addAction();
			menu_addItemGXTHash(MODEL_DOUBLE);
			menu_addAction();
		}
		else if (item_selected == 4)
		{
			menu_addItemGXTHash(MODEL_SMUGGLER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_FLOATER);
			menu_addAction();
			menu_addItemGXTHash(MODEL_BLADE);
			menu_addAction();
		}
		else if (item_selected == 5)
		{
			menu_addItemGXTHash(MODEL_BUZZARD);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SWIFT);
			menu_addAction();
			menu_addItemGXTHash(MODEL_SKYLIFT);
			menu_addAction();
		}
	}
}