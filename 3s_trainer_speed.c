/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

uint doSpeed;
Vehicle v_doMod;

void init(void)
{
	if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &v_doMod);
}

void DoHandling(void)
{
	if (doSpeed != 1.0 && IS_PLAYER_PLAYING(GetPlayerIndex()))
	{
		if (DOES_VEHICLE_EXIST(v_doMod) && IS_VEH_DRIVEABLE(v_doMod))
		{
			if (IS_CONTROL_PRESSED(2, 40) && !IS_CONTROL_PRESSED(0, 41) && !IS_CONTROL_PRESSED(0, 45) && !IS_CONTROL_PRESSED(0, 44))
			{
				if ((IS_CHAR_IN_ANY_HELI(GetPlayerPed()) || IS_CHAR_IN_ANY_BOAT(GetPlayerPed())) || (IS_VEHICLE_ON_ALL_WHEELS(v_doMod) && !IS_CAR_IN_WATER(v_doMod) && !IS_CAR_IN_AIR_PROPER(v_doMod)))
				{
					APPLY_FORCE_TO_CAR(v_doMod, 0, 0.0000, doSpeed, 0.0000, 0.0000, 0.0000, 0.0000, 0, 1, 1, 1);
				}
			}
		}
		else
		{
			doSpeed = 1.0;
			TERMINATE_THIS_SCRIPT();
		}
	}
}

void main(void)
{
	init();
	while(true)
	{
		WAIT(0);
		if (IS_CHAR_IN_CAR(GetPlayerPed(), v_doMod))
			DoHandling();
	}
}