/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

void catchColourButtonPress(void)
{
	uint end_col = 134, last_down = 134;

	if (GET_CURRENT_EPISODE() == 2)
	{
		end_col = 137;
		last_down = 128;
	}

	if (menu_forward_pressed())
	{
		item_selected = item_highlighted;
		if (last_selected[3] == 1)
		{
			ColourIndex normal1, normal2;
			GET_CAR_COLOURS(v_modding, &normal1, &normal2);
			CHANGE_CAR_COLOUR(v_modding, item_selected - 1, normal2);
		}
		else if (last_selected[3] == 2)
		{
			ColourIndex normal1, normal2;
			GET_CAR_COLOURS(v_modding, &normal1, &normal2);
			CHANGE_CAR_COLOUR(v_modding, normal1, item_selected - 1);
		}
		else if (last_selected[3] == 3)
		{
			ColourIndex normal1, normal2;
			GET_EXTRA_CAR_COLOURS(v_modding, &normal1, &normal2);
			SET_EXTRA_CAR_COLOURS(v_modding, item_selected - 1, normal2);
		}
		else if (last_selected[3] == 4)
		{
			ColourIndex normal1, normal2;
			GET_EXTRA_CAR_COLOURS(v_modding, &normal1, &normal2);
			SET_EXTRA_CAR_COLOURS(v_modding, normal1, item_selected - 1);
		}

		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
	}

	if (menu_left_pressed(false) && item_highlighted != 1)
	{
		item_highlighted = item_highlighted - 1;
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (menu_right_pressed(false) && item_highlighted != end_col)
	{
		item_highlighted = item_highlighted + 1;
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (menu_up_pressed(false))
	{
		if (item_highlighted <= 7)
			item_highlighted = end_col;
		else if (item_highlighted > 7)
			item_highlighted = item_highlighted - 7;

		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (menu_down_pressed(false))
	{
		if (item_highlighted < last_down)
			item_highlighted = item_highlighted + 7;
		else if (item_highlighted >= last_down)
			item_highlighted = 1;
			
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}

	if (menu_back_pressed())
	{
		inMenu = true;

		menu_items_set = false;

		menu_clean();

		menu_level--;
		
		item_selected = last_selected[menu_level - 1];
		
		item_highlighted = last_selected[3];
		PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_SERVER_HIGHLIGHT");
	}
}

void DrawPalette(void)
{
	uint car_colours_r[138], car_colours_g[138], car_colours_b[138];

	car_colours_r[1] = 10;
	car_colours_g[1] = 10;
	car_colours_b[1] = 10;

	car_colours_r[2] = 37;
	car_colours_g[2] = 37;
	car_colours_b[2] = 39;

	car_colours_r[3] = 101;
	car_colours_g[3] = 106;
	car_colours_b[3] = 121;

	car_colours_r[4] = 88;
	car_colours_g[4] = 89;
	car_colours_b[4] = 90;

	car_colours_r[5] = 156;
	car_colours_g[5] = 161;
	car_colours_b[5] = 163;

	car_colours_r[6] = 150;
	car_colours_g[6] = 145;
	car_colours_b[6] = 140;

	car_colours_r[7] = 81;
	car_colours_g[7] = 84;
	car_colours_b[7] = 89;

	car_colours_r[8] = 63;
	car_colours_g[8] = 62;
	car_colours_b[8] = 69;

	car_colours_r[9] = 165;
	car_colours_g[9] = 169;
	car_colours_b[9] = 167;

	car_colours_r[10] = 151;
	car_colours_g[10] = 149;
	car_colours_b[10] = 146;

	car_colours_r[11] = 118;
	car_colours_g[11] = 123;
	car_colours_b[11] = 124;

	car_colours_r[12] = 90;
	car_colours_g[12] = 87;
	car_colours_b[12] = 82;

	car_colours_r[13] = 173;
	car_colours_g[13] = 176;
	car_colours_b[13] = 176;

	car_colours_r[14] = 132;
	car_colours_g[14] = 137;
	car_colours_b[14] = 136;

	car_colours_r[15] = 148;
	car_colours_g[15] = 157;
	car_colours_b[15] = 159;

	car_colours_r[16] = 164;
	car_colours_g[16] = 167;
	car_colours_b[16] = 165;

	car_colours_r[17] = 88;
	car_colours_g[17] = 88;
	car_colours_b[17] = 83;

	car_colours_r[18] = 164;
	car_colours_g[18] = 160;
	car_colours_b[18] = 150;

	car_colours_r[19] = 175;
	car_colours_g[19] = 177;
	car_colours_b[19] = 177;

	car_colours_r[20] = 109;
	car_colours_g[20] = 108;
	car_colours_b[20] = 110;

	car_colours_r[21] = 100;
	car_colours_g[21] = 104;
	car_colours_b[21] = 106;

	car_colours_r[22] = 82;
	car_colours_g[22] = 86;
	car_colours_b[22] = 97;

	car_colours_r[23] = 140;
	car_colours_g[23] = 146;
	car_colours_b[23] = 154;

	car_colours_r[24] = 91;
	car_colours_g[24] = 93;
	car_colours_b[24] = 94;

	car_colours_r[25] = 189;
	car_colours_g[25] = 190;
	car_colours_b[25] = 198;

	car_colours_r[26] = 182;
	car_colours_g[26] = 182;
	car_colours_b[26] = 182;

	car_colours_r[27] = 100;
	car_colours_g[27] = 100;
	car_colours_b[27] = 100;

	car_colours_r[28] = 226;
	car_colours_g[28] = 6;
	car_colours_b[28] = 6;

	car_colours_r[29] = 150;
	car_colours_g[29] = 8;
	car_colours_b[29] = 0;

	car_colours_r[30] = 107;
	car_colours_g[30] = 0;
	car_colours_b[30] = 0;

	car_colours_r[31] = 97;
	car_colours_g[31] = 16;
	car_colours_b[31] = 9;

	car_colours_r[32] = 74;
	car_colours_g[32] = 10;
	car_colours_b[32] = 10;

	car_colours_r[33] = 115;
	car_colours_g[33] = 11;
	car_colours_b[33] = 11;

	car_colours_r[34] = 87;
	car_colours_g[34] = 7;
	car_colours_b[34] = 7;

	car_colours_r[35] = 38;
	car_colours_g[35] = 3;
	car_colours_b[35] = 6;

	car_colours_r[36] = 158;
	car_colours_g[36] = 0;
	car_colours_b[36] = 0;

	car_colours_r[37] = 20;
	car_colours_g[37] = 0;
	car_colours_b[37] = 2;

	car_colours_r[38] = 15;
	car_colours_g[38] = 4;
	car_colours_b[38] = 4;

	car_colours_r[39] = 15;
	car_colours_g[39] = 8;
	car_colours_b[39] = 10;

	car_colours_r[40] = 57;
	car_colours_g[40] = 25;
	car_colours_b[40] = 29;

	car_colours_r[41] = 85;
	car_colours_g[41] = 39;
	car_colours_b[41] = 37;

	car_colours_r[42] = 76;
	car_colours_g[42] = 41;
	car_colours_b[42] = 41;

	car_colours_r[43] = 116;
	car_colours_g[43] = 29;
	car_colours_b[43] = 40;

	car_colours_r[44] = 109;
	car_colours_g[44] = 40;
	car_colours_b[44] = 55;

	car_colours_r[45] = 115;
	car_colours_g[45] = 10;
	car_colours_b[45] = 39;

	car_colours_r[46] = 100;
	car_colours_g[46] = 13;
	car_colours_b[46] = 27;

	car_colours_r[47] = 98;
	car_colours_g[47] = 11;
	car_colours_b[47] = 28;

	car_colours_r[48] = 115;
	car_colours_g[48] = 24;
	car_colours_b[48] = 39;

	car_colours_r[49] = 171;
	car_colours_g[49] = 152;
	car_colours_b[49] = 143;

	car_colours_r[50] = 32;
	car_colours_g[50] = 32;
	car_colours_b[50] = 44;

	car_colours_r[51] = 68;
	car_colours_g[51] = 98;
	car_colours_b[51] = 79;

	car_colours_r[52] = 46;
	car_colours_g[52] = 91;
	car_colours_b[52] = 32;

	car_colours_r[53] = 30;
	car_colours_g[53] = 46;
	car_colours_b[53] = 50;

	car_colours_r[54] = 48;
	car_colours_g[54] = 79;
	car_colours_b[54] = 69;

	car_colours_r[55] = 77;
	car_colours_g[55] = 98;
	car_colours_b[55] = 104;

	car_colours_r[56] = 94;
	car_colours_g[56] = 112;
	car_colours_b[56] = 114;

	car_colours_r[57] = 25;
	car_colours_g[57] = 56;
	car_colours_b[57] = 38;

	car_colours_r[58] = 45;
	car_colours_g[58] = 58;
	car_colours_b[58] = 53;

	car_colours_r[59] = 51;
	car_colours_g[59] = 95;
	car_colours_b[59] = 63;

	car_colours_r[60] = 71;
	car_colours_g[60] = 120;
	car_colours_b[60] = 60;

	car_colours_r[61] = 147;
	car_colours_g[61] = 163;
	car_colours_b[61] = 150;

	car_colours_r[62] = 154;
	car_colours_g[62] = 167;
	car_colours_b[62] = 144;

	car_colours_r[63] = 38;
	car_colours_g[63] = 55;
	car_colours_b[63] = 57;

	car_colours_r[64] = 76;
	car_colours_g[64] = 117;
	car_colours_b[64] = 183;

	car_colours_r[65] = 70;
	car_colours_g[65] = 89;
	car_colours_b[65] = 122;

	car_colours_r[66] = 93;
	car_colours_g[66] = 126;
	car_colours_b[66] = 141;

	car_colours_r[67] = 59;
	car_colours_g[67] = 78;
	car_colours_b[67] = 120;

	car_colours_r[68] = 61;
	car_colours_g[68] = 74;
	car_colours_b[68] = 104;

	car_colours_r[69] = 109;
	car_colours_g[69] = 122;
	car_colours_b[69] = 136;

	car_colours_r[70] = 22;
	car_colours_g[70] = 34;
	car_colours_b[70] = 72;

	car_colours_r[71] = 39;
	car_colours_g[71] = 47;
	car_colours_b[71] = 75;

	car_colours_r[72] = 78;
	car_colours_g[72] = 104;
	car_colours_b[72] = 129;

	car_colours_r[73] = 106;
	car_colours_g[73] = 122;
	car_colours_b[73] = 140;

	car_colours_r[74] = 111;
	car_colours_g[74] = 130;
	car_colours_b[74] = 151;

	car_colours_r[75] = 14;
	car_colours_g[75] = 49;
	car_colours_b[75] = 109;

	car_colours_r[76] = 57;
	car_colours_g[76] = 90;
	car_colours_b[76] = 131;

	car_colours_r[77] = 32;
	car_colours_g[77] = 75;
	car_colours_b[77] = 107;

	car_colours_r[78] = 43;
	car_colours_g[78] = 62;
	car_colours_b[78] = 87;

	car_colours_r[79] = 54;
	car_colours_g[79] = 65;
	car_colours_b[79] = 85;

	car_colours_r[80] = 108;
	car_colours_g[80] = 132;
	car_colours_b[80] = 149;

	car_colours_r[81] = 77;
	car_colours_g[81] = 93;
	car_colours_b[81] = 96;

	car_colours_r[82] = 64;
	car_colours_g[82] = 108;
	car_colours_b[82] = 143;

	car_colours_r[83] = 19;
	car_colours_g[83] = 69;
	car_colours_b[83] = 115;

	car_colours_r[84] = 16;
	car_colours_g[84] = 80;
	car_colours_b[84] = 130;

	car_colours_r[85] = 56;
	car_colours_g[85] = 86;
	car_colours_b[85] = 148;

	car_colours_r[86] = 0;
	car_colours_g[86] = 28;
	car_colours_b[86] = 50;

	car_colours_r[87] = 89;
	car_colours_g[87] = 110;
	car_colours_b[87] = 135;

	car_colours_r[88] = 34;
	car_colours_g[88] = 52;
	car_colours_b[88] = 87;

	car_colours_r[89] = 32;
	car_colours_g[89] = 32;
	car_colours_b[89] = 44;

	car_colours_r[90] = 245;
	car_colours_g[90] = 137;
	car_colours_b[90] = 15;

	car_colours_r[91] = 145;
	car_colours_g[91] = 115;
	car_colours_b[91] = 71;

	car_colours_r[92] = 142;
	car_colours_g[92] = 140;
	car_colours_b[92] = 70;

	car_colours_r[93] = 170;
	car_colours_g[93] = 173;
	car_colours_b[93] = 142;

	car_colours_r[94] = 174;
	car_colours_g[94] = 155;
	car_colours_b[94] = 127;

	car_colours_r[95] = 150;
	car_colours_g[95] = 129;
	car_colours_b[95] = 108;

	car_colours_r[96] = 122;
	car_colours_g[96] = 117;
	car_colours_b[96] = 96;

	car_colours_r[97] = 157;
	car_colours_g[97] = 152;
	car_colours_b[97] = 114;

	car_colours_r[98] = 152;
	car_colours_g[98] = 149;
	car_colours_b[98] = 134;

	car_colours_r[99] = 156;
	car_colours_g[99] = 141;
	car_colours_b[99] = 113;

	car_colours_r[100] = 105;
	car_colours_g[100] = 30;
	car_colours_b[100] = 59;

	car_colours_r[101] = 114;
	car_colours_g[101] = 42;
	car_colours_b[101] = 63;

	car_colours_r[102] = 124;
	car_colours_g[102] = 27;
	car_colours_b[102] = 68;

	car_colours_r[103] = 34;
	car_colours_g[103] = 25;
	car_colours_b[103] = 24;

	car_colours_r[104] = 127;
	car_colours_g[104] = 105;
	car_colours_b[104] = 86;

	car_colours_r[105] = 71;
	car_colours_g[105] = 53;
	car_colours_b[105] = 50;

	car_colours_r[106] = 105;
	car_colours_g[106] = 88;
	car_colours_b[106] = 83;

	car_colours_r[107] = 98;
	car_colours_g[107] = 68;
	car_colours_b[107] = 40;

	car_colours_r[108] = 125;
	car_colours_g[108] = 98;
	car_colours_b[108] = 86;

	car_colours_r[109] = 170;
	car_colours_g[109] = 157;
	car_colours_b[109] = 132;

	car_colours_r[110] = 123;
	car_colours_g[110] = 113;
	car_colours_b[110] = 94;

	car_colours_r[111] = 171;
	car_colours_g[111] = 146;
	car_colours_b[111] = 118;

	car_colours_r[112] = 99;
	car_colours_g[112] = 92;
	car_colours_b[112] = 90;

	car_colours_r[113] = 201;
	car_colours_g[113] = 201;
	car_colours_b[113] = 201;

	car_colours_r[114] = 214;
	car_colours_g[114] = 218;
	car_colours_b[114] = 214;

	car_colours_r[115] = 159;
	car_colours_g[115] = 157;
	car_colours_b[115] = 148;

	car_colours_r[116] = 147;
	car_colours_g[116] = 163;
	car_colours_b[116] = 150;

	car_colours_r[117] = 156;
	car_colours_g[117] = 156;
	car_colours_b[117] = 152;

	car_colours_r[118] = 167;
	car_colours_g[118] = 162;
	car_colours_b[118] = 143;

	car_colours_r[119] = 15;
	car_colours_g[119] = 106;
	car_colours_b[119] = 137;

	car_colours_r[120] = 161;
	car_colours_g[120] = 153;
	car_colours_b[120] = 131;

	car_colours_r[121] = 163;
	car_colours_g[121] = 173;
	car_colours_b[121] = 198;

	car_colours_r[122] = 155;
	car_colours_g[122] = 139;
	car_colours_b[122] = 128;

	car_colours_r[123] = 132;
	car_colours_g[123] = 148;
	car_colours_b[123] = 171;

	car_colours_r[124] = 158;
	car_colours_g[124] = 164;
	car_colours_b[124] = 171;

	car_colours_r[125] = 134;
	car_colours_g[125] = 68;
	car_colours_b[125] = 110;

	car_colours_r[126] = 226;
	car_colours_g[126] = 6;
	car_colours_b[126] = 6;

	car_colours_r[127] = 71;
	car_colours_g[127] = 120;
	car_colours_b[127] = 60;

	car_colours_r[128] = 215;
	car_colours_g[128] = 142;
	car_colours_b[128] = 16;

	car_colours_r[129] = 42;
	car_colours_g[129] = 119;
	car_colours_b[129] = 161;

	car_colours_r[130] = 66;
	car_colours_g[130] = 31;
	car_colours_b[130] = 33;

	car_colours_r[131] = 111;
	car_colours_g[131] = 103;
	car_colours_b[131] = 95;

	car_colours_r[132] = 252;
	car_colours_g[132] = 38;
	car_colours_b[132] = 0;

	car_colours_r[133] = 252;
	car_colours_g[133] = 109;
	car_colours_b[133] = 0;

	car_colours_r[134] = 255;
	car_colours_g[134] = 255;
	car_colours_b[134] = 255;

	if (GET_CURRENT_EPISODE() == 2)
	{
		car_colours_r[135] = 245;
		car_colours_g[135] = 180;
		car_colours_b[135] = 0;

		car_colours_r[136] = 5;
		car_colours_g[136] = 5;
		car_colours_b[136] = 5;

		car_colours_r[137] = 189;
		car_colours_g[137] = 149;
		car_colours_b[137] = 75;
	}

	float Ipos_x = 0.0895, Ipos_y = 0.0730;
	uint r, g, b;
	uint rows = 0, end_col = 134, last_down = 134;

	if (GET_CURRENT_EPISODE() == 2)
	{
		end_col = 137;
		last_down = 131;
	}

	int I;
	for (I = 1; I <= end_col; I++)
	{
		r = car_colours_r[I], g = car_colours_g[I], b = car_colours_b[I];

		if (I != 1)
		{
			Ipos_x = Ipos_x + 0.0320;
			if (rows == 7)
			{
				Ipos_x = 0.0895;
				Ipos_y = Ipos_y + 0.0320;
				rows = 0;
			}
		}

		if (item_highlighted == I)
			DRAW_RECT(Ipos_x, Ipos_y, 0.0342, 0.0342, 255, 255, 255, 255);

		DRAW_RECT(Ipos_x, Ipos_y, 0.0282, 0.0282, r, g, b, 255);

		rows++;
	}

}