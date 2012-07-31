/**
 * This file is from Three-Socks Menu Library https://bitbucket.org/ThreeSocks/gtaiv-menu-library
 *
 */

#pragma once

void menu_core_init(void)
{
	item_highlighted = 1;
	menu_level = 1;
	press_counter = 2;
	press_counter_timesby = 1;

	project_setup();
	menu_consts_start_y = menu_start_y;
	menu_consts_max = menu_max;

	REQUEST_SCRIPT("menu_globals");
	while (!HAS_SCRIPT_LOADED("menu_globals"))
		WAIT(0);

	uint episode = GET_CURRENT_EPISODE();

	START_NEW_SCRIPT_WITH_ARGS("menu_globals", &episode, 1, 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("menu_globals");

	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
}

void menu_core_shutdown(void)
{
	draw_shutdown();

	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("menu_globals");

	REQUEST_SCRIPT("menu_gexit");
	while (!HAS_SCRIPT_LOADED("menu_gexit"))
		WAIT(0);

	uint episode = GET_CURRENT_EPISODE();

	START_NEW_SCRIPT_WITH_ARGS("menu_gexit", &episode, 1, 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("menu_gexit");

	REQUEST_SCRIPT(startup_script);
	while (!HAS_SCRIPT_LOADED(startup_script))
		WAIT(0);

	START_NEW_SCRIPT(startup_script, 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED(startup_script);

	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_UNREADY");
	TERMINATE_THIS_SCRIPT();
}

void menu_core_catchButtonPress(void)
{
	if (menu_up_pressed(true) && !inError)
	{
		if (item_highlighted == 1)
			item_highlighted = menu_len;
		else
		{
			item_highlighted--;

			if (menu_len > menu_consts_max && item_highlighted > (menu_start_scrolling - 1))
			{
				menu_start_y += menu_spacing;
				menu_max--;
			}
		}

		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (menu_down_pressed(true) && !inError)
	{
		if (item_highlighted == menu_len)
		{
			item_highlighted = 1;
			menu_start_y = menu_consts_start_y;
			menu_max = menu_consts_max;
		}
		else
		{
			item_highlighted++;

			if (menu_len > menu_consts_max && item_highlighted > menu_start_scrolling)
			{
				menu_start_y -= menu_spacing;
				menu_max++;
			}
		}

		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (menu_left_pressed(true) && !inError)
	{
		if (menu_item[item_highlighted].type == 1)
		{
			if (menu_item[item_highlighted].num_val == 1)
				menu_item[item_highlighted].num_val = menu_item[item_highlighted].extra_val;
			else
				menu_item[item_highlighted].num_val = menu_item[item_highlighted].num_val - 1;

			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_OPTION_CHANGE");
		}
		else if (menu_item[item_highlighted].type == 2)
		{
			if (menu_item[item_highlighted].float_val == 1.0)
				menu_item[item_highlighted].float_val = menu_item[item_highlighted].extra_val;
			else
				menu_item[item_highlighted].float_val = menu_item[item_highlighted].float_val - 0.100;

			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_OPTION_CHANGE");
		}
	}

	if (menu_right_pressed(true) && !inError)
	{
		if (menu_item[item_highlighted].type == 1)
		{
			if (menu_item[item_highlighted].num_val == menu_item[item_highlighted].extra_val)
				menu_item[item_highlighted].num_val = 1;
			else
				menu_item[item_highlighted].num_val = menu_item[item_highlighted].num_val + 1;
				
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_OPTION_CHANGE");
		}
		else if (menu_item[item_highlighted].type == 2)
		{
			if (menu_item[item_highlighted].float_val == menu_item[item_highlighted].extra_val)
				menu_item[item_highlighted].float_val = 1.0;
			else
				menu_item[item_highlighted].float_val = menu_item[item_highlighted].float_val + 0.100;
			
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_OPTION_CHANGE");
		}

	}

	if (menu_forward_pressed() && press_counter_timesby < 2 && !inError)
	{
		// Set the selected item.
		item_selected = item_highlighted;

		if (menu_item[item_selected].action)
			project_doAction();
		else
		{
			// Reset the items set. So the new items can be set.
			menu_items_set = false;

			// Remember the last highlighted so we can hightlight back to it.
			last_selected[menu_level] = item_selected;

			// Reset the highlighted item. 
			item_highlighted = 1;

			menu_clean();
			
			// Next level.
			menu_level++;
		}

		if (menu_item[item_selected].action)
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
		else
			PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (menu_back_pressed())
	{
		// Don't do anything if we are on the main menu.
		if (menu_level != 1)
		{
			// Reset the items set. So the new items can be set.
			menu_items_set = false;

			menu_clean();

			if (!actionError)
				// Go back one level.
				menu_level--;

			item_selected = last_selected[menu_level - 1];

			if (inError)
			{
				if (actionError)
					actionError = false;

				inError = false;
			}
		}
		else 
			menu_core_shutdown();

		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (reset_counter)
	{
		press_counter = 2;
		reset_counter = false;
	}
}

void menu_core(void)
{
	if (menu_shutdown)
		menu_core_shutdown();

	menu_core_catchButtonPress();

	project_catchFunctionButtonPress();

	if (!menu_items_set)
	{
		project_set();

		// Set the highlighted item to the last item selected.
		if (menu_back_pressed() && last_selected[menu_level] != 0)
		{
			if (last_selected[menu_level] <= menu_len)
				item_highlighted = last_selected[menu_level];
			else
				item_highlighted = menu_len;

			last_selected[menu_level] = 0;
			
			if (menu_len > menu_consts_max && item_highlighted > menu_start_scrolling)
			{
				uint I;
				for (I = (menu_start_scrolling + 1); I <= item_highlighted; I++)
				{
					menu_start_y -= menu_spacing;
					menu_max++;
				}
			}
		}
	}

	// catchAfterMenuSetButtonPress
	if (menu_up_pressed(false))
	{
		if (menu_len > menu_consts_max && item_highlighted == menu_len)
		{
			menu_start_y = (menu_consts_start_y) - ((menu_len - menu_start_scrolling) * menu_spacing);
			menu_max = menu_len + menu_start_scrolling;
		}
	}
}