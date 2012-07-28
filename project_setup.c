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

	inMenu = true;
}

void project_startup(void)
{
	REQUEST_SCRIPT("3s_trainer_globals");
	while (!HAS_SCRIPT_LOADED("3s_trainer_globals"))
		WAIT(0);

	START_NEW_SCRIPT("3s_trainer_globals", 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("3s_trainer_globals");

	SET_CINEMATIC_BUTTON_ENABLED(false);

#ifdef PC
if (!IS_FONT_LOADED(7))
	LOAD_TEXT_FONT(7);
#else
if (!IS_FONT_LOADED(6))
	LOAD_TEXT_FONT(6);
#endif

	// Mimic cell phone.
	// 0 = work, 1 = crash, 2 = work, 3 = crash 
	WAIT(500);
	CREATE_MOBILE_PHONE(2);

	DISABLE_FRONTEND_RADIO();

	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), true);

	REQUEST_STREAMED_TXD("network", 0);
	while (!HAS_STREAMED_TXD_LOADED("network"))
		WAIT(0);

	arrow_txd = GET_TEXTURE_FROM_STREAMED_TXD("network", "ICON_W_ARROW_UP");
	rightarrow_txd = GET_TEXTURE_FROM_STREAMED_TXD( "network", "ICON_W_ARROW_RIGHT" );

	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
}

void project_shutdown(void)
{
	RELEASE_TEXTURE(arrow_txd);
	RELEASE_TEXTURE(rightarrow_txd);
	MARK_STREAMED_TXD_AS_NO_LONGER_NEEDED("network");

	ENABLE_FRONTEND_RADIO();

	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), false);

	SET_CINEMATIC_BUTTON_ENABLED(true);

	DESTROY_MOBILE_PHONE();

	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("3s_trainer_globals");

	REQUEST_SCRIPT("3s_trainer_gexit");
	while (!HAS_SCRIPT_LOADED("3s_trainer_gexit"))
		WAIT(0);

	START_NEW_SCRIPT("3s_trainer_gexit", 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("3s_trainer_gexit");

	REQUEST_SCRIPT("3s_trainer_startup");
	while (!HAS_SCRIPT_LOADED("3s_trainer_startup"))
		WAIT(0);

	START_NEW_SCRIPT("3s_trainer_startup", 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("3s_trainer_startup");

	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_UNREADY");
	TERMINATE_THIS_SCRIPT();
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
}