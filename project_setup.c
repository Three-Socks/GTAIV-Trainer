/**
 * This file is from Three-Socks trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

void project_setup(void)
{
	// Start y positioning.
	menu_start_y = 0.0890;
	// Spacing between each item.
	menu_spacing = 0.0400;
	// Max number of items before scrolling.
	menu_max = 14;
	// When to start scrolling.
	menu_start_scrolling = 7;

	startup_script = "3s_trainer_startup";

	inMenu = true;
}

void project_error(uint error_id)
{
	if (menu_item[item_selected].action)
		actionError = true;

	menu_clean();

	// Invalid Menu.
	menu_header = trainer_error;

	if (error_id == TRAINER_ERROR_ID_INVALID)
		menu_addItem(trainer_error_invalid);
	else if (error_id == TRAINER_ERROR_ID_LOCATE)
	{
		menu_addItem(trainer_error_locate);
		menu_addItem(trainer_error_locate_1);
	}
	else if (error_id == TRAINER_ERROR_ID_CDIMAGE)
		menu_addItem(trainer_error_cdimage);
	else if (error_id == TRAINER_ERROR_ID_UPGRADE_NA)
	{
		menu_addItem(trainer_error_upgrade_na);
		menu_addItem(trainer_error_upgrade_na_1);
	}
	else if (error_id == TRAINER_ERROR_ID_APPEARANCE_NA)
		menu_addItem(trainer_error_appearance_na);

	menu_addItem(trainer_error_goback);
	inError = true;

	PLAY_AUDIO_EVENT("FRONTEND_MENU_ERROR");
}