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

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

void main(void)
{
	while(true)
	{
		WAIT(0);
		CLEAR_WANTED_LEVEL(GetPlayerIndex());
		SET_WANTED_MULTIPLIER(0.0);
	}
}