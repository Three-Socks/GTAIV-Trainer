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

void project_set(void)
{
	menu_items_set = true;

	uint mainMenu = last_selected[1];
	uint subMenu = last_selected[2]; 

	// Main
	if (menu_level == 1)
	{
		// Main
		menu_header = trainer_main;
		menu_addItem(trainer_player);
		menu_addItem(trainer_vehicle);
		menu_addItem(trainer_exit);
		menu_addAction();
		return;
	}
	// Player
	else if (mainMenu == 1)
	{
		if (menu_level == 2)
		{
			// Player
			menu_header = trainer_player;
			menu_addItem(trainer_model_changer);
			menu_addItem(trainer_appearance);
			menu_addItem(trainer_accessories);
			menu_addItem(trainer_weapons);
			menu_addItem(trainer_health);
			menu_addItem(trainer_wanted);

			return;	
		}
		else if (menu_level == 3)
		{
			if (item_selected == 1)
				player_model_gamecat();
			else if (item_selected == 2)
				player_appearance_cat();
			else if (item_selected == 3)
				player_accessories();
			else if (item_selected == 4)
				player_weapons_cat();
			else if (item_selected == 5)
				player_health();
			else if (item_selected == 6)
				player_wanted();

			return;
		}
		// Player - Model Changer
		else if (menu_level == 4)
		{
			if (subMenu == 1)
				player_model_cat();
			else if (subMenu == 2)
				player_appearance_vt(true);
			else if (subMenu == 3)
				player_accessories();
			else if (subMenu == 4)
			{
				player_weapons();

				if (item_selected == 1)
					player_weapons_GTAIV();
				else if (item_selected == 2)
				{
					#ifdef TLAD
						player_weapons_TLAD();
					#endif
					#ifdef TBOGT
						player_weapons_TBOGT();
					#endif
				}
			}

			return;
		}
		else if (menu_level == 5)
		{
			if (subMenu == 1)
			{
				menu_header = trainer_model_changer;
				uint game = last_selected[menu_level - 2];

				player_model_gamecat_set(game);
			}
			return;
		}
	}
	// Vehicle.
	else if (mainMenu == 2)
	{
		// Locate vehicle if not in spawn menu.
		if (menu_level != 2 && subMenu != 1)
		{
			if (!getVehicle())
			{
				project_error(TRAINER_ERROR_ID_LOCATE);
				return;
			}
		}

		if (menu_level == 2)
		{
			// Vehicle
			menu_header = trainer_vehicle;
			menu_addItem(trainer_spawn);
			menu_addItem(trainer_upgrade);
			menu_addItem(trainer_colour);
			menu_addItem(trainer_modify);
			menu_addItem(trainer_fixnwash);
			menu_addAction();

			return;
		}
		else if (menu_level == 3)
		{
			if (item_selected == 1)
			{
				gms_spawn_cat();
				return;
			}
			else if (item_selected == 2)
			{
				gms_upgrade();
				return;
			}
			else if (item_selected == 3)
			{
				gms_colour();
				return;
			}
			else if (item_selected == 4)
			{
				gms_modify();
				return;
			}
		}
		else if (menu_level == 4)
		{
			if (subMenu == 1)
			{
				gms_spawn();
				return;
			}
			else if (subMenu == 3)
			{
				if (item_selected >= 1 && item_selected <= 4)
				{
					inMenu = false;
					menu_len = 14;

					ColourIndex colour_normal1, colour_normal2, colour_extra1, colour_extra2;
					GET_CAR_COLOURS(v_modding, &colour_normal1, &colour_normal2);
					GET_EXTRA_CAR_COLOURS(v_modding, &colour_extra1, &colour_extra2);
					if (last_selected[3] == 1)
						item_highlighted = colour_normal1 + 1;
					else if (last_selected[3] == 2)
						item_highlighted = colour_normal2 + 1;
					else if (last_selected[3] == 3)
						item_highlighted = colour_extra1 + 1;
					else if (last_selected[3] == 4)
						item_highlighted = colour_extra2 + 1;

					return;
				}
			}
			else if (subMenu == 4)
			{
				if (item_selected == 1)
				{
					gms_door();
					return;
				}
				else if (item_selected == 2)
				{
					gms_window();
					return;
				}
				else if (item_selected == 3)
				{
					gms_handling();
					return;
				}
				else if (item_selected == 4)
				{
					gms_lights();
					return;
				}
				else if (item_selected == 5)
				{
					gms_health();
					return;
				}
				else if (item_selected == 6)
				{
					gms_misc();
					return;
				}
			}
		}
		else if (menu_level == 5)
		{
			if (subMenu == 1)
			{
				gms_spawn_list();
				return;
			}
		}
	}

	project_error(TRAINER_ERROR_ID_INVALID);
}

void project_catchFunctionButtonPress(void)
{
	uint mainMenu = last_selected[1];
	uint subMenu = last_selected[2];

	if (menu_left_pressed(false) || menu_right_pressed(false))
	{
		// Reset menu and set max limits for appearance variations/textures.
		if (mainMenu == 1 && subMenu == 2)
		{
			if (menu_level == 4)
			{
				if (item_highlighted == 1)
				{
					uint number_selected = menu_item[1].num_val;
					menu_clean();
					menu_item[1].num_val = number_selected;
					player_appearance_vt(false);
				}
			}
		}
	}

	else if (menu_forward_pressed())
	{
		// Random appearance. Set current.
		if (mainMenu == 1 && subMenu == 2)
		{
			if (menu_level == 4)
			{
				if (item_highlighted == 3)
				{
					menu_clean();
					player_appearance_vt(true);
				}
			}
		}
	}
}