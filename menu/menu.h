/**
 * This file is from Three-Socks Menu Library https://bitbucket.org/ThreeSocks/gtaiv-menu-library
 *
 */

#pragma once

#include "menu_locals.h"
#include "menu_consts.h"

#ifdef STYLE == 1
	#include "menu_style_1.c"
#else STYLE == 2
	#include "menu_style_2.c"
#endif

#include "menu_functions.c"