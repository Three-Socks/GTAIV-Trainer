/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#include <natives.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

bool G_disableCellphone;

void main(void)
{
	while(true)
	{
		WAIT(0);
		if (!G_disableCellphone)
			G_disableCellphone = true;
	}
}