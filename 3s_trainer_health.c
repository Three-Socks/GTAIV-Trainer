/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

bool re_enable;

void main(void)
{
	SET_PLAYER_INVINCIBLE(GetPlayerIndex(), true);

	while(true)
	{
		WAIT(0);

		if (!re_enable)
		{
			if (!IS_PLAYER_CONTROL_ON(GetPlayerIndex()))
				re_enable = true;
		}
		else if (IS_PLAYER_CONTROL_ON(GetPlayerIndex()))
		{
			SET_PLAYER_INVINCIBLE(GetPlayerIndex(), true);
			re_enable = false;
		}
	}
}