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

#pragma once

#include "3s_trainer_vehicle_functions.c"

void gms_upgrade(void)
{

	menu_header = trainer_upgrade;
	char *txt_upgrade[10];
	txt_upgrade[0] = trainer_upgrade0;
	txt_upgrade[1] = trainer_upgrade1;
	txt_upgrade[2] = trainer_upgrade2;
	txt_upgrade[3] = trainer_upgrade3;
	txt_upgrade[4] = trainer_upgrade4;
	txt_upgrade[5] = trainer_upgrade5;
	txt_upgrade[6] = trainer_upgrade6;
	txt_upgrade[7] = trainer_upgrade7;
	txt_upgrade[8] = trainer_upgrade8;
	txt_upgrade[9] = trainer_upgrade9;

	uint I, txt_I;
	for (I = 0; I <= 9; I++)
	{
		bool turnedon = false;
		if (!IS_VEHICLE_EXTRA_TURNED_ON(v_modding, I))
		{
			TURN_OFF_VEHICLE_EXTRA(v_modding, I, false);
			turnedon = true;
		}

		if (IS_VEHICLE_EXTRA_TURNED_ON(v_modding, I))
		{
			txt_I++;
			if (turnedon)
				TURN_OFF_VEHICLE_EXTRA(v_modding, I, true);

			menu_addItem(txt_upgrade[txt_I]);
			menu_addItemNumber(I, 0);
			menu_addItemBool(IS_VEHICLE_EXTRA_TURNED_ON(v_modding, I));
			menu_addAction();
		}
	}

	if (txt_I == 0)
		project_error(TRAINER_ERROR_ID_UPGRADE_NA);

}

void gms_upgrade_apply(void)
{
	uint vehicle_upgrade = menu_item[item_selected].num_val;
	if (IS_VEHICLE_EXTRA_TURNED_ON(v_modding, vehicle_upgrade))
	{
		TURN_OFF_VEHICLE_EXTRA(v_modding, vehicle_upgrade, true);
		menu_item[item_selected].extra_val = false;
	}
	else
	{
		TURN_OFF_VEHICLE_EXTRA(v_modding, vehicle_upgrade, false);
		menu_item[item_selected].extra_val = true;
	}
}

void gms_colour(void)
{
	menu_header = trainer_colour;
	menu_addItem(trainer_colour1);
	menu_addItem(trainer_colour2);
	menu_addItem(trainer_specular1);
	menu_addItem(trainer_specular2);

	uint NumColours;
	GET_NUM_CAR_COLOURS(v_modding, &NumColours);

	if (NumColours > 0)
	{
		menu_addItem(trainer_variation);
		menu_addItemNumber(1, NumColours);
		menu_addAction();
	}

	int NumLiveries;
	GET_NUM_CAR_LIVERIES(v_modding, &NumLiveries);

	if (NumLiveries > 0)
	{
		menu_addItem(trainer_livery);
		menu_addItemNumber(1, NumLiveries);
		menu_addAction();
	}
}

void gms_modify(void)
{
	menu_header = trainer_modify;

	menu_addItem(trainer_doors);
	menu_addItem(trainer_windows);
	menu_addItem(trainer_handling);
	menu_addItem(trainer_lights);
	menu_addItem(trainer_health);
	menu_addItem(trainer_misc);
}

void gms_door(void)
{
	menu_header = trainer_doors;

	menu_addItem(trainer_mode1);
	menu_addAction();

	custom_bool_on = trainer_open;
	custom_bool_off = trainer_closed;

	char *txt_door[6];
	txt_door[0] = trainer_leftfront;
	txt_door[1] = trainer_rightfront;
	txt_door[2] = trainer_leftrear;
	txt_door[3] = trainer_rightrear;
	txt_door[4] = trainer_hood;
	txt_door[5] = trainer_trunk;

	uint I;
	for (I = 0; I <= 5; I++)
	{
		bool turnedon = false;

		float doorangle;
		GET_DOOR_ANGLE_RATIO(v_modding, I, &doorangle);

		if (!IS_CAR_DOOR_DAMAGED(v_modding, I) && doorangle >= 0.5)
			turnedon = true;
		else
			turnedon = false;

		menu_addItem(txt_door[I]);
		menu_addItemNumber(I, 0);
		menu_addItemBool(turnedon);
		menu_addAction();
	}
}

void gms_door_apply(void)
{
	if (item_selected == 1)
	{
		if (COMPARE_STRING(menu_item[item_selected].name, trainer_mode1))
		{
			custom_bool_on = trainer_removed;
			custom_bool_off = "  ";
			menu_item[item_selected].name = trainer_mode2;
			uint I;
			for (I = 0; I <= 5; I++)
			{
				menu_item[I].extra_val = IS_CAR_DOOR_DAMAGED(v_modding, I);
			}
		}
		else
		{
			menu_item[item_selected].name = trainer_mode1;
			custom_bool_on = trainer_open;
			custom_bool_off = trainer_closed;
		}
	}
	else
	{
		if (COMPARE_STRING(menu_item[1].name, trainer_mode1))
		{
			uint door_selected = menu_item[item_selected].num_val;
			float doorangle;
			GET_DOOR_ANGLE_RATIO(v_modding, door_selected, &doorangle);

			if (!IS_CAR_DOOR_DAMAGED(v_modding, door_selected) && doorangle >= 0.5)
			{
				SHUT_CAR_DOOR(v_modding, door_selected);
				menu_item[item_selected].extra_val = false;
			}
			else if (!IS_CAR_DOOR_DAMAGED(v_modding, door_selected) && doorangle == 0 && doorangle <= 0.5)
			{
				OPEN_CAR_DOOR(v_modding, door_selected);
				menu_item[item_selected].extra_val = true;
			}
		}
		else
		{
			uint door_selected = menu_item[item_selected].num_val;
			if (IS_CAR_DOOR_DAMAGED(v_modding, door_selected))
			{
				StoreModify(false, true, false, 0, door_selected, 0);

				FIX_CAR(v_modding);
				menu_item[item_selected].extra_val = false;
				
				ReApplyModify();
			}
			else
			{
				BREAK_CAR_DOOR(v_modding, door_selected, false);
				menu_item[item_selected].extra_val = true;
			}
			float curX, curY, curZ;
			GET_CHAR_COORDINATES(GetPlayerPed(), &curX, &curY, &curZ);
			CLEAR_AREA_OF_OBJECTS(curX, curY, curZ, 5.0);
		}
	}
}

void gms_window(void)
{
	menu_header = trainer_windows;

	custom_bool_on = trainer_removed;
	custom_bool_off = "  ";

	char *txt_window[4];
	txt_window[0] = trainer_leftfront;
	txt_window[1] = trainer_rightfront;
	txt_window[2] = trainer_leftrear;
	txt_window[3] = trainer_rightrear;

	uint I;
	for (I = 0; I <= 3; I++)
	{
		menu_addItem(txt_window[I]);
		menu_addItemNumber(I, 0);
		menu_addItemBool(!IS_VEH_WINDOW_INTACT(v_modding, I));
		menu_addAction();
	}
}

void gms_window_apply(void)
{
	uint window_selected = menu_item[item_selected].num_val;
	if (IS_VEH_WINDOW_INTACT(v_modding, window_selected))
	{
		REMOVE_CAR_WINDOW(v_modding, window_selected);
		menu_item[item_selected].extra_val = true;
	}
	else
	{
		StoreModify(true, false, false, window_selected, 0, 0);

		FIX_CAR(v_modding);
		menu_item[item_selected].extra_val = false;

		ReApplyModify();
	}
}

void gms_handling(void)
{
	menu_header = trainer_handling;

	menu_addItem(trainer_speed);
	menu_addItemNumber(1, 100);
	menu_addAction();

	menu_addItem(trainer_brakes);
	menu_addItemNumber(1, 100);
	menu_addAction();

	menu_addItem(trainer_steering);
	menu_addItemNumber(1, 100);
	menu_addAction();

	menu_addItem(trainer_steerbias);
	menu_addItemNumber(1, 10);
	menu_addAction();
}

void gms_handling_apply(void)
{
	uint handling_selected = menu_item[item_selected].num_val;

	if (item_selected < 4)
	{
		char *script_name;

		if (item_selected == 1)
			script_name = "3s_trainer_speed";
		else if (item_selected == 2)
			script_name = "3s_trainer_brake";
		else if (item_selected == 3)
			script_name = "3s_trainer_steer";

		if (menu_item[item_selected].num_val != 1.0)
		{
			TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(script_name);
			REQUEST_SCRIPT(script_name);
			while (!HAS_SCRIPT_LOADED(script_name))
				WAIT(0);

			START_NEW_SCRIPT_WITH_ARGS(script_name, &handling_selected, 1, 1024);
			MARK_SCRIPT_AS_NO_LONGER_NEEDED(script_name);
		}
		else
		{
			TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(script_name);
		}
	}
	else
		SET_VEHICLE_STEER_BIAS(v_modding, handling_selected);
}

void gms_lights(void)
{
	menu_header = trainer_lights;

	menu_addItem(trainer_headlights);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_hazardlights);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_indicatorlights);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_interiorlight);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_siren);
	menu_addItemBool(IS_CAR_SIREN_ON(v_modding));
	menu_addAction();

	menu_addItem(trainer_alwayssiren);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_taxilight);
	menu_addItemBool(ARE_TAXI_LIGHTS_ON(v_modding));
	menu_addAction();

	menu_addItem(trainer_lightmultiplier);
	menu_addItemNumber(1, 10);
	menu_addAction();
}

void gms_lights_apply(void)
{
	bool light_enabled = menu_item[item_selected].extra_val;
	if (item_selected == 1)
	{
		if (light_enabled)
		{
			FORCE_CAR_LIGHTS(v_modding, 0);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			FORCE_CAR_LIGHTS(v_modding, 2);
			menu_item[item_selected].extra_val = true;
		}
	}
	if (item_selected == 2)
	{
		if (light_enabled)
		{
			SET_VEH_HAZARDLIGHTS(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_VEH_HAZARDLIGHTS(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 3)
	{
		if (light_enabled)
		{
			SET_VEH_INDICATORLIGHTS(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_VEH_INDICATORLIGHTS(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 4)
	{
		if (light_enabled)
		{
			SET_VEH_INTERIORLIGHT(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_VEH_INTERIORLIGHT(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 5)
	{
		if (light_enabled)
		{
			SWITCH_CAR_SIREN(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SWITCH_CAR_SIREN(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 6)
	{
		if (light_enabled)
		{
			SET_SIREN_WITH_NO_DRIVER(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_SIREN_WITH_NO_DRIVER(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 7)
	{
		if (light_enabled)
		{
			SET_TAXI_LIGHTS(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_TAXI_LIGHTS(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 8)
		SET_CAR_LIGHT_MULTIPLIER(v_modding, menu_item[item_selected].num_val);
}

void gms_health(void)
{
	menu_header = trainer_health;

	menu_addItem(trainer_health);
	uint v_health;
	GET_CAR_HEALTH(v_modding, &v_health);
	menu_addItemNumber(v_health, 1000);
	menu_addAction();

	menu_addItem(trainer_enginehealth);
	float v_engine_health = GET_ENGINE_HEALTH(v_modding);
	uint v_numengine_health = FLOOR(v_engine_health);
	menu_addItemNumber(v_numengine_health, 1000);
	menu_addAction();

	menu_addItem(trainer_bulletproof);
	menu_addItemBool(modifyBulletProof);
	menu_addAction();

	menu_addItem(trainer_fireproof);
	menu_addItemBool(modifyFireProof);
	menu_addAction();

	menu_addItem(trainer_explosionproof);
	menu_addItemBool(modifyExplosionProof);
	menu_addAction();

	menu_addItem(trainer_collisionproof);
	menu_addItemBool(modifyCollisionProof);
	menu_addAction();

	menu_addItem(trainer_meleeproof);
	menu_addItemBool(modifyMeleeProof);
	menu_addAction();

	menu_addItem(trainer_strong);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_strongaxles);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_collision);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_damage);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_visibledamage);
	menu_addItemBool(false);
	menu_addAction();

	menu_addItem(trainer_watertight);
	menu_addItemBool(false);
	menu_addAction();
}

void gms_health_apply(void)
{
	bool health_enabled = menu_item[item_selected].extra_val;

	if (item_selected == 1)
		SET_CAR_HEALTH(v_modding, menu_item[item_selected].num_val);
	else if (item_selected == 2)
		SET_ENGINE_HEALTH(v_modding, menu_item[item_selected].num_val);
	else if (item_selected == 3)
	{
		if (modifyBulletProof)
		{
			SET_CAR_PROOFS(v_modding, false, modifyFireProof, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
			modifyBulletProof = false;
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_PROOFS(v_modding, true, modifyFireProof, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
			modifyBulletProof = true;
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 4)
	{
		if (modifyFireProof)
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, false, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
			modifyFireProof = false;
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, true, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
			modifyFireProof = true;
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 5)
	{
		if (modifyExplosionProof)
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, false, modifyCollisionProof, modifyMeleeProof);
			modifyExplosionProof = false;
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, true, modifyCollisionProof, modifyMeleeProof);
			modifyExplosionProof = true;
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 6)
	{
		if (modifyCollisionProof)
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, false, modifyMeleeProof);
			modifyCollisionProof = false;
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, true, modifyMeleeProof);
			modifyCollisionProof = true;
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 7)
	{
		if (modifyMeleeProof)
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, modifyCollisionProof, false);
			modifyMeleeProof = false;
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, modifyCollisionProof, true);
			modifyMeleeProof = true;
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 8)
	{
		if (health_enabled)
		{
			SET_CAR_STRONG(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_STRONG(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 9)
	{
		if (health_enabled)
		{
			SET_VEH_HAS_STRONG_AXLES(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_VEH_HAS_STRONG_AXLES(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 10)
	{
		if (health_enabled)
		{
			SET_CAR_COLLISION(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_COLLISION(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 11)
	{
		if (health_enabled)
		{
			SET_CAR_CAN_BE_DAMAGED(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_CAN_BE_DAMAGED(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 12)
	{
		if (health_enabled)
		{
			SET_CAR_CAN_BE_VISIBLY_DAMAGED(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_CAN_BE_VISIBLY_DAMAGED(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 13)
	{
		if (health_enabled)
		{
			SET_CAR_WATERTIGHT(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_WATERTIGHT(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
}

void gms_misc(void)
{
	menu_addItem(trainer_dirtlevel);
	float v_intensity;
	GET_VEHICLE_DIRT_LEVEL(v_modding, &v_intensity);
	menu_addItemFloat(v_intensity, 16.0);
	menu_addAction();

	menu_addItem(trainer_visible);
	menu_addItemBool(true);
	menu_addAction();

	menu_addItem(trainer_missionvehicle);
	menu_addAction();
}

void gms_misc_apply(void)
{
	bool misc_bool = menu_item[item_selected].extra_val;

	if (item_selected == 1)
		SET_VEHICLE_DIRT_LEVEL(v_modding, menu_item[item_selected].float_val - 1.0);
	else if (item_selected == 2)
	{
		if (misc_bool)
		{
			SET_CAR_VISIBLE(v_modding, false);
			menu_item[item_selected].extra_val = false;
		}
		else
		{
			SET_CAR_VISIBLE(v_modding, true);
			menu_item[item_selected].extra_val = true;
		}
	}
	else if (item_selected == 3)
		SET_CAR_AS_MISSION_CAR(v_modding);
}

void gms_fixnwash(void)
{
	FIX_CAR(v_modding);
	SET_VEHICLE_DIRT_LEVEL(v_modding, 0);
	WASH_VEHICLE_TEXTURES(v_modding, 255);
}