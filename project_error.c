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
	else if (error_id == TRAINER_ERROR_ID_SCRIPT)
		menu_addItem(trainer_error_script);

	menu_addItem(trainer_error_goback);
	inError = true;

	PLAY_AUDIO_EVENT("FRONTEND_MENU_ERROR");
}