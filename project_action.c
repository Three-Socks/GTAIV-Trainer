/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#pragma once

void project_doAction(void)
{
	menu_items_set = true;

	// Helpers
	uint num_val_selected = menu_item[item_selected].num_val;
	uint mainMenu = last_selected[1];
	uint subMenu = last_selected[2]; 

	if (menu_level == 1)
	{
		// Exit
		if (item_selected == 3)
		{
			menu_shutdown = true;
			return;
		}
	}
	else if (mainMenu == 1)
	{
		if (menu_level == 3)
		{
			if (subMenu == 2) 
				player_appearance_apply();
			else if (subMenu == 3)
				player_accessories_apply();
			else if (subMenu == 5)
				player_health_apply();
			else if (subMenu == 6)
				player_wanted_apply();

			return;
		}
		else if (menu_level == 4)
		{
			if (subMenu == 2)
				player_appearance_vt_apply();
			else if (subMenu == 4)
			{
				if (item_selected <= 4)
					player_weapons_options_apply();
				else
					player_weapons_apply();
			}

			return;
		}
		else if (menu_level == 5)
		{
			if (subMenu == 1)
			{
				if (!model_loaded)
					load_model = num_val_selected;
				else
					player_model_apply();

				return;
			}
		}
	}
	else if (mainMenu == 2)
	{
		// Locate vehicle if not in spawn menu.
		if (subMenu != 1)
		{
			if (!getVehicle())
			{
				project_error(TRAINER_ERROR_ID_LOCATE);
				return;
			}
		}

		if (menu_level == 2)
		{
			if (item_selected == 5)
			{
				gms_fixnwash();
				return;
			}
		}
		else if (menu_level == 3)
		{
			// Vehicle - Upgrade.
			if (subMenu == 2)
			{
				gms_upgrade_apply();
				return;
			}
			// Vehicle - Colour.
			else if (subMenu == 3)
			{
				if (item_selected == 5)
				{
					SET_CAR_COLOUR_COMBINATION(v_modding, num_val_selected - 1);
					return;
				}
				else if (item_selected == 6)
				{
					SET_CAR_LIVERY(v_modding, num_val_selected - 1);
					return;
				}
			}
		}
		else if (menu_level == 4)
		{
			if (subMenu == 4)
			{
				if (last_selected[3] == 1)
				{
					gms_door_apply();
					return;
				}
				else if (last_selected[3] == 2)
				{
					gms_window_apply();
					return;
				}
				else if (last_selected[3] == 3)
				{
					gms_handling_apply();
					return;
				}
				else if (last_selected[3] == 4)
				{
					gms_lights_apply();
					return;
				}
				else if (last_selected[3] == 5)
				{
					gms_health_apply();
					return;
				}
				else if (last_selected[3] == 6)
				{
					gms_misc_apply();
					return;
				}
			}
		}
		else if (menu_level == 5)
		{
			if (subMenu == 1)
			{
				if (!model_loaded)
					load_model = num_val_selected;
				else
					gms_spawn_apply();

				return;
			}
		}
	}

	project_error(TRAINER_ERROR_ID_INVALID);
}

void load_model_prioritized(void)
{
	if (IS_MODEL_IN_CDIMAGE(load_model))
	{
		if (!model_requested)
		{
				PRIORITIZE_STREAMING_REQUEST();
				REQUEST_MODEL(load_model);
				model_requested = true;
		}

		if (HAS_MODEL_LOADED(load_model))
		{
			load_model = 0;
			model_loaded = true;
			model_requested = false;
			project_doAction();
		}
	}
	else
	{
		load_model = 0;
		project_error(TRAINER_ERROR_ID_CDIMAGE);
	}
}