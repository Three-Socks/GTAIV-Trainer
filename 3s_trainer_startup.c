/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#include <natives.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "menu/menu_consts.h"

void main(void)
{
	bool load_trainer;

	while(true)
	{
		WAIT(0);

		if (load_trainer)
		{
			if (GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("3s_trainer") == 0)
			{
				REQUEST_SCRIPT("3s_trainer");
				while (!HAS_SCRIPT_LOADED("3s_trainer"))
					WAIT(0);

				START_NEW_SCRIPT("3s_trainer", 1024);
				MARK_SCRIPT_AS_NO_LONGER_NEEDED("3s_trainer");
				TERMINATE_THIS_SCRIPT();
			}
		}

		if ((IS_BUTTON_PRESSED(0, BUTTON_L1) && IS_BUTTON_PRESSED(0, BUTTON_DPAD_UP)) || (IS_GAME_KEYBOARD_KEY_PRESSED(KEY_E) && IS_GAME_KEYBOARD_KEY_PRESSED(KEY_UP_ARROW)))
			load_trainer = true;
	}
	
}