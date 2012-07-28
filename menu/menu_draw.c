/**
 * This file is from Three-Socks Menu Library https://bitbucket.org/ThreeSocks/gtaiv-menu-library
 *
 */

#pragma once

void set_up_draw(float width, float height, uint r, uint g, uint b, uint a)
{
#ifdef PC
	SET_TEXT_FONT(7);
#else
	SET_TEXT_FONT(6);
#endif
	SET_TEXT_BACKGROUND(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
	SET_TEXT_EDGE(0, 0, 0, 0, 255);

	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_SCALE(width, height);
	SET_TEXT_PROPORTIONAL(1);

	SET_TEXT_JUSTIFY(0);
	SET_TEXT_CENTRE(0);
	SET_TEXT_RIGHT_JUSTIFY(0);

}

float draw_text_width(char *gxtName, float x, float y, char *val)
{
	float result;
	result = GET_STRING_WIDTH_WITH_STRING(gxtName, val);
	DISPLAY_TEXT_WITH_LITERAL_STRING(x, y, gxtName, val);
	return result;
}

void draw_number(char *gxtName, float x, float y, int val)
{
	DISPLAY_TEXT_WITH_NUMBER(x, y, gxtName, val);
}

void draw_float(char *gxtName, float x, float y, float val, uint dp)
{
	DISPLAY_TEXT_WITH_FLOAT(x, y, gxtName, val, dp);
}

void drawHeader()
{
	float x, y, x2, y2;

	//if (GET_IS_HIDEF())
	//{
		x = 0.0103;
		y = 0.0960 - 0.0120;
	/*}
	else
	{
		x = 0.0303;
		y = 0.116 - 0.0120;
	}*/

	set_up_draw(0.3500, 0.4775, 255, 255, 255, 255);
	DISPLAY_TEXT_WITH_LITERAL_STRING(0.0826, 0.0710, "STRING", menu_header);
	DRAW_RECT(x + (0.35 * 0.50000000), (y + -0.00370000) + 0.03450000, (0.2250 - 0.01000000) - 0.01000000, 0.00300000, 255, 255, 255, 255);
}

void drawCurvedWindow(void)
{
	float x, y, x2, y2;

	//if (GET_IS_HIDEF())
	//{
		x = 0.0700;
		y = 0.0640 - 0.0120;
	/*}
	else
	{
		x = 0.0900;
		y = 0.0840 - 0.0120;
	}*/

	if (menu_len > menu_consts_max)
		y2 = 0.09 + (menu_consts_max * 0.04);
	else
		y2 = 0.09 + (menu_len * 0.04);
                                   //0.35
	DRAW_CURVED_WINDOW(x, y, 0.2300, y2, 245);
}

void drawFrontend(void)
{
	INIT_FRONTEND_HELPER_TEXT();

	if (menu_level == 1)
		DRAW_FRONTEND_HELPER_TEXT("LEAVE", "INPUT_F_CANCEL", 0);
	else
		DRAW_FRONTEND_HELPER_TEXT("BACK", "INPUT_F_CANCEL", 0);
	
	if (menu_item[item_highlighted].action)
		DRAW_FRONTEND_HELPER_TEXT("CONFIRM", "INPUT_F_ACCEPT", 0);
	else
		DRAW_FRONTEND_HELPER_TEXT("KYB_ENTER", "INPUT_F_ACCEPT", 0);

	if (menu_item[item_highlighted].type == 1 || menu_item[item_highlighted].type == 2)
		DRAW_FRONTEND_HELPER_TEXT("SCROLL", "PAD_DPAD_LR", 0);
}