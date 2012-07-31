/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#pragma once

// Error ID's
enum eGenvareErrorID
{
	TRAINER_ERROR_ID_UNKNOWN,
	TRAINER_ERROR_ID_INVALID,
	TRAINER_ERROR_ID_LOCATE,
	TRAINER_ERROR_ID_CDIMAGE,
	TRAINER_ERROR_ID_UPGRADE_NA,
	TRAINER_ERROR_ID_APPEARANCE_NA,
};

bool inMenu;

uint load_model; 
//model_wait

bool model_loaded, model_requested;

uint window_notintact[5], door_damaged[7], door_opened[7];

// Vehicle
Vehicle v_modding;

bool modifyBulletProof;
bool modifyFireProof;
bool modifyExplosionProof;
bool modifyCollisionProof;
bool modifyMeleeProof;