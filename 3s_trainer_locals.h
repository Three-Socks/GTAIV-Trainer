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

#pragma once

// Error ID's
enum eTrainerErrorID
{
	TRAINER_ERROR_ID_UNKNOWN,
	TRAINER_ERROR_ID_INVALID,
	TRAINER_ERROR_ID_LOCATE,
	TRAINER_ERROR_ID_CDIMAGE,
	TRAINER_ERROR_ID_UPGRADE_NA,
	TRAINER_ERROR_ID_APPEARANCE_NA,
	TRAINER_ERROR_ID_SCRIPT
};

bool inMenu;

uint load_model; 
bool model_loaded, model_requested;

char* load_script;
bool script_loaded, script_requested;

uint window_notintact[5], door_damaged[7], door_opened[7];

// Vehicle
Vehicle v_modding;

bool modifyBulletProof;
bool modifyFireProof;
bool modifyExplosionProof;
bool modifyCollisionProof;
bool modifyMeleeProof;