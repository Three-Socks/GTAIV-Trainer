/**
 * This file is from Three-Socks Menu Library https://bitbucket.org/ThreeSocks/gtaiv-menu-library
 *
 */

#include <natives.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

uint episode;
bool G_disableCellphone_TLAD;
bool G_disableCellphone_TBOGT;
bool G_disableCellphone_GTAIV;

void main(void)
{
	if (episode == 2)
		G_disableCellphone_TBOGT = false;
	else if (episode == 1)
		G_disableCellphone_TLAD = false;
	else if (episode == 0)
		G_disableCellphone_GTAIV = false;

	TERMINATE_THIS_SCRIPT();
}