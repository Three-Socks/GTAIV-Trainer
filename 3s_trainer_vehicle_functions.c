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

bool getVehicle(void)
{
	if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
	{
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &v_modding);
		return true;
	}

	return false;
}

void StoreModify(bool notwindow, bool notbreak, bool notopen, uint itemwindow, uint itembreak, uint itemopen)
{
	int window_I;
	for (window_I = 0; window_I < 4; window_I++)
	{
		if (notwindow)
		{
			if (!IS_VEH_WINDOW_INTACT(v_modding, window_I) && window_I != itemwindow)
			{
				window_notintact[window_I] = 1;
			}
			else
			{
				window_notintact[window_I] = 0;
			}
		}
		else
		{
			if (!IS_VEH_WINDOW_INTACT(v_modding, window_I))
			{
				window_notintact[window_I] = 1;
			}
			else
			{
				window_notintact[window_I] = 0;
			}
		}
	}

	int door_I;
	for (door_I = 0; door_I < 6; door_I++)
	{
		if (notbreak)
		{
			if (IS_CAR_DOOR_DAMAGED(v_modding, door_I) && door_I != itembreak)
			{
				door_damaged[door_I] = 1;
			}
			else
			{
				door_damaged[door_I] = 0;
			}
		}
		else
		{
			if (IS_CAR_DOOR_DAMAGED(v_modding, door_I))
			{
				door_damaged[door_I] = 1;
			}
			else
			{
				door_damaged[door_I] = 0;
			}
		}
		
		float doorangle;
		GET_DOOR_ANGLE_RATIO(v_modding, door_I, &doorangle);

		if (notopen)
		{
			if (!IS_CAR_DOOR_DAMAGED(v_modding, door_I) && doorangle >= 0.5000 && door_I != itemopen)
			{
				door_opened[door_I] = 1;
			}
			else
			{
				door_opened[door_I] = 0;
			}
		}
		else
		{
			if (!IS_CAR_DOOR_DAMAGED(v_modding, door_I) && doorangle >= 0.5000)
			{
				door_opened[door_I] = 1;
			}
			else
			{
				door_opened[door_I] = 0;
			}
		}
	}

}

void ReApplyModify(void)
{
	// Re-Apply broken/open doors & windows.
	int door_I;
	for (door_I = 0; door_I < 6; door_I++)
	{
		if (door_damaged[door_I] == 1)
		{
			BREAK_CAR_DOOR(v_modding, door_I, false);
		}

		if (door_opened[door_I] == 1)
		{
			OPEN_CAR_DOOR(v_modding, door_I);
		}
	}

	int window_I;
	for (window_I = 0; window_I < 4; window_I++)
	{
		if (window_notintact[window_I] == 1)
		{
			REMOVE_CAR_WINDOW(v_modding, window_I);
		}
	}
	float curX, curY, curZ;
	GET_CHAR_COORDINATES(GetPlayerPed(), &curX, &curY, &curZ);
	CLEAR_AREA_OF_OBJECTS(curX, curY, curZ, 5.0000);
}