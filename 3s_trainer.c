/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

//#define PC
#define MAX_MENU_ITEMS 52
#define MAX_MENU_LEVLS 5

// Menu
#include "menu/menu.h"

// Trainer
#include "3s_trainer_lang.h"
#include "3s_trainer_locals.h"

#include "project_setup.c"

#include "3s_trainer_player.c"
#include "3s_trainer_vehicle.c"
#include "3s_trainer_vehicle_spawn.c"
#include "3s_trainer_colour.c"

// Project
#include "project_set.c"
#include "project_action.c"

// Menu
#include "menu/menu_core.c"

void main(void)
{
	menu_core_init();

	project_startup();

	while(true)
	{
		WAIT(0);
		HIDE_HELP_TEXT_THIS_FRAME();

		if (inMenu)
		{
			if (load_model != 0 && !model_loaded)
				load_model_prioritized();

			// Core menu function (Catch button press. Set menu).
			menu_core();

			// Draw background/header/text.
			drawCurvedWindow();

			// Only continue if in menu. 
			// Otherwise drawFrontend will call invalid menu_item.
			if (inMenu)
			{
				drawFrontend();
			
				drawHeader();
				menu_draw();

				if (menu_len > menu_consts_max && item_highlighted > menu_start_scrolling)
					DRAW_SPRITE(arrow_txd, 0.1900, 0.1260, 0.0160, 0.0160, 0, 255, 255, 255, 255);

				if (menu_len > menu_consts_max)
					DRAW_SPRITE(arrow_txd, 0.1900, 0.6890, 0.0160, 0.0160, 180.0000, 255, 255, 255, 255);
			}
		}
		else
		{
			INIT_FRONTEND_HELPER_TEXT();
			DRAW_FRONTEND_HELPER_TEXT("BACK", "INPUT_F_CANCEL", 0);
			DRAW_FRONTEND_HELPER_TEXT("CONFIRM", "INPUT_F_ACCEPT", 0);
			catchColourButtonPress();

			// Stop drawing immediately if in menu.
			if (!inMenu)
			{
				// Draw background/header/text.
				drawCurvedWindow();
				DrawPalette();
			}
		}
	}
}