/**
 * This file is from Three-Socks Menu Library https://bitbucket.org/ThreeSocks/gtaiv-menu-library
 *
 */

#pragma once

// Settings
float menu_start_y, menu_consts_start_y, menu_spacing;
uint menu_max, menu_consts_max, menu_start_scrolling;

Texture arrow_txd, rightarrow_txd;

uint item_highlighted;
uint last_selected[MAX_MENU_LEVLS];
uint item_selected;
uint menu_len;
uint menu_level;

bool reset_counter;
uint press_counter, hold_counter, press_counter_timesby, press_id;

bool menu_items_set;
bool inError;
bool actionError;

char *menu_header;

/*
 name: Display name

 type: 
   0 = text
   1 = num
   2 = float
   3 = bool
   4 = hash
   5 = gxt_hash
*/
typedef struct _menu
{
	char *name;
	uint type;
	uint num_val;
	uint extra_val;
	float float_val;
	bool action;
} menu;

menu menu_item[MAX_MENU_ITEMS];

char *custom_bool_on;
char *custom_bool_off;