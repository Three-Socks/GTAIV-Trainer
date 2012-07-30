/**
 * This file is from Three-Socks Menu Library https://bitbucket.org/ThreeSocks/gtaiv-menu-library
 *
 */

#pragma once

void menu_hold_pressed(uint p_id)
{
	uint button1;
	uint button2;

	if (p_id == 1)
	{
		button1 = BUTTON_DPAD_UP;
		button2 = KEY_UP_ARROW;
	}
	else if (p_id == 2)
	{
		button1 = BUTTON_DPAD_DOWN;
		button2 = KEY_DOWN_ARROW;
	}
	else if (p_id == 3)
	{
		button1 = BUTTON_DPAD_LEFT;
		button2 = KEY_LEFT_ARROW;
	}
	else if (p_id == 4)
	{
		button1 = BUTTON_DPAD_RIGHT;
		button2 = KEY_RIGHT_ARROW;
	}

	if (IS_BUTTON_PRESSED(0, button1) || IS_GAME_KEYBOARD_KEY_PRESSED(button2))
	{
		press_id = p_id;
		if (hold_counter > 40)
		{
			press_counter_timesby++;
			hold_counter = 0;
		}

		hold_counter++;
		press_counter++;
		press_counter *= press_counter_timesby;
	}
	else if (press_id == p_id)
	{
		press_counter_timesby = 1;
		hold_counter = 0;
	}
}

bool menu_up_pressed(bool counter)
{
	if ((IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_UP) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_UP_ARROW))
	 || (press_counter > 6 && (IS_BUTTON_PRESSED(0, BUTTON_DPAD_UP) || IS_GAME_KEYBOARD_KEY_PRESSED(KEY_UP_ARROW))))
	{
		reset_counter = true;
		return true;
	}
	
	if (counter)
		menu_hold_pressed(1);

	return false;
}

bool menu_down_pressed(bool counter)
{
	if ((IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_DOWN_ARROW))
	 || (press_counter > 6 && (IS_BUTTON_PRESSED(0, BUTTON_DPAD_DOWN) || IS_GAME_KEYBOARD_KEY_PRESSED(KEY_DOWN_ARROW))))
	{
		reset_counter = true;
		return true;
	}

	if (counter)
		menu_hold_pressed(2);

	return false;
}

bool menu_left_pressed(bool counter)
{
	if ((IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_LEFT) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_LEFT_ARROW))
	 || (press_counter > 6 && (IS_BUTTON_PRESSED(0, BUTTON_DPAD_LEFT) || IS_GAME_KEYBOARD_KEY_PRESSED(KEY_LEFT_ARROW))))
	{
		reset_counter = true;
		return true;
	}

	if (counter)
		menu_hold_pressed(3);

	return false;
}

bool menu_right_pressed(bool counter)
{
	if ((IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_RIGHT) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_RIGHT_ARROW))
	 || (press_counter > 6 && (IS_BUTTON_PRESSED(0, BUTTON_DPAD_RIGHT) || IS_GAME_KEYBOARD_KEY_PRESSED(KEY_RIGHT_ARROW))))
	{
		reset_counter = true;
		return true;
	}

	if (counter)
		menu_hold_pressed(4);

	return false;
}

bool menu_forward_pressed(void)
{
	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_X) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_ENTER))
		return true;

	return false;
}

bool menu_back_pressed(void)
{
	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_O) || IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_BACKSPACE))
		return true;

	return false;
}

// Adds a menu item.
void menu_addItem(char* item_text)
{
	menu_len++;
	menu_item[menu_len].name = item_text;
}

void menu_addItemNumber(uint item_num, uint item_max)
{
	menu_item[menu_len].num_val = item_num;
	menu_item[menu_len].extra_val = item_max;
	menu_item[menu_len].type = 1;
}

void menu_addItemFloat(float item_float, uint item_max)
{
	menu_item[menu_len].float_val = item_float;
	menu_item[menu_len].extra_val = item_max;
	menu_item[menu_len].type = 2;
}

void menu_addItemBool(bool item_bool)
{
	menu_item[menu_len].extra_val = item_bool;
	menu_item[menu_len].type = 3;
}

void menu_addItemHash(char* item_text, uint item_hash)
{
	menu_len++;
	menu_item[menu_len].name = item_text;
	menu_item[menu_len].num_val = item_hash;
	menu_item[menu_len].type = 4;
}

void menu_addItemGXTHash(uint item_gxt_hash)
{
	menu_len++;
	menu_item[menu_len].num_val = item_gxt_hash;
	menu_item[menu_len].type = 5;
}

// Adds the action param to the last set menu.
void menu_addAction(void)
{
	menu_item[menu_len].action = true;
}

// Draws the menu.
void menu_draw(void)
{
	uint d_r = 137, d_g = 137, d_b = 137, 
	h_r = 251, h_g = 162, h_b = 6;
	//h_r = 206, h_g = 160, h_b = 22;

	float pos_x = 0.0826, 

	toggle_pos_x = 0.2500, 

	menu_width = 0.3100, menu_height = 0.4550;

	uint r, g, b, a = 255;
	int I;
	float Ipos_y = menu_start_y;

	for (I = 1; I <= menu_len; I++)
	{
		Ipos_y = Ipos_y + menu_spacing;
		if (I <= menu_max && Ipos_y > (menu_consts_start_y + 0.0100))
		{
			r = d_r;
			g = d_g;
			b = d_b;

			if (item_highlighted == I && !inError)
			{
				r =  h_r;
				g =  h_g;
				b =  h_b;
			}

			set_up_draw(menu_width, menu_height, r, g, b, a);

			if (menu_item[I].type == 5)
				DISPLAY_TEXT_WITH_LITERAL_STRING(pos_x, Ipos_y, "STRING", GET_STRING_FROM_TEXT_FILE(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(menu_item[I].num_val)));
			else
				DISPLAY_TEXT_WITH_LITERAL_STRING(pos_x, Ipos_y, "STRING", menu_item[I].name);

			if (menu_item[I].type == 1 || menu_item[I].type == 2)
			{
				float left_pos_x, main_pos_x;

				if (menu_item[I].type == 2)
				{
					if (menu_item[I].float_val >= 10.0)
					{
						left_pos_x = 0.2260;
						main_pos_x = 0.2370;
					}
					else if (menu_item[I].float_val < 10.0)
					{
						left_pos_x = 0.2370;
						main_pos_x = 0.2470;
					}
				}
				else
				{
					if (menu_item[I].num_val < 10)
					{
						left_pos_x = 0.2530;
						main_pos_x = 0.2630;
					}

					if (menu_item[I].num_val >= 10)
					{
						left_pos_x = 0.2430;
						main_pos_x = 0.2520;
					}

					if (menu_item[I].num_val >= 100)
					{
						left_pos_x = 0.2270;
						main_pos_x = 0.2380;
					}

					if (menu_item[I].num_val >= 1000)
					{
						left_pos_x = 0.2200;
						main_pos_x = 0.2300;
					}
				}

				DRAW_SPRITE(rightarrow_txd, left_pos_x, Ipos_y + 0.0150, 0.0160, 0.0160, 180.0000, r, g, b, a);
				set_up_draw(menu_width, menu_height, r, g, b, a);
				if (menu_item[I].type == 1)
					DISPLAY_TEXT_WITH_NUMBER(main_pos_x, Ipos_y, "NUMBR", menu_item[I].num_val);
				else if (menu_item[I].type == 2)
					DISPLAY_TEXT_WITH_FLOAT(main_pos_x, Ipos_y, "NUMBR", menu_item[I].float_val, 1);
				DRAW_SPRITE(rightarrow_txd, 0.2850, Ipos_y + 0.0150, 0.0160, 0.0160, 0.0000, r, g, b, a);
			}
			else if (menu_item[I].type == 3)
			{
				if (menu_item[I].extra_val)
				{
					set_up_draw(menu_width, menu_height, h_r, h_g, h_b, a);
					char *txt_on;
					if (!COMPARE_STRING(custom_bool_on, " "))
					{
						toggle_pos_x = 0.2000;
						txt_on = custom_bool_on;
					}
					else
						txt_on = menu_on;
					DISPLAY_TEXT_WITH_LITERAL_STRING(toggle_pos_x, Ipos_y, "STRING", txt_on);
				}
				else
				{
					set_up_draw(menu_width, menu_height, d_r, d_g, d_b, a);
					char *txt_off;
					if (!COMPARE_STRING(custom_bool_off, " "))
					{
						toggle_pos_x = 0.2000;
						txt_off = custom_bool_off;
					}
					else
						txt_off = menu_off;
					DISPLAY_TEXT_WITH_LITERAL_STRING(toggle_pos_x, Ipos_y, "STRING", txt_off);
				}
			}
		}
	}
}

void menu_clean(void)
{
	int I;
	for (I = 1; I < (menu_len + 1); I++)
	{
		menu_item[I].name = " ";
		menu_item[I].type = 0;
		menu_item[I].num_val = 1;
		menu_item[I].extra_val = 0;
		menu_item[I].float_val = 1.0;
		menu_item[I].action = false;
	}

	custom_bool_on = " ";
	custom_bool_off = " ";

	// Reset menu_start_y & menu_max
	menu_start_y = menu_consts_start_y;
	menu_max = menu_consts_max;

	// Reset menu_len.
	menu_len = 0;
}