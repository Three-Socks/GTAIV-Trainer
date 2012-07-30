/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
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
	while(true)
	{
		WAIT(0);
		if (episode == 2)
		{
			if (!G_disableCellphone_TBOGT)
				G_disableCellphone_TBOGT = true;
		}
		else if (episode == 1)
		{
			if (!G_disableCellphone_TLAD)
				G_disableCellphone_TLAD = true;
		}
		else if (episode == 0)
		{
			if (!G_disableCellphone_GTAIV)
				G_disableCellphone_GTAIV = true;
		}
	}
}