=====================================
Three-Socks Trainer
=====================================

Release topic: http://psx-scene.com/forums/f276/%5Brel%5D-three-socks-trainer-v1-0-beta-104903/ (Infomation/Downloads)

== Project Code Guidelines ==
* No new global vars - Causes random bugs.
* Limit use of WAIT native - Causes draw natives to stop drawing for the duration of the WAIT.

== For Developers: How To Compile ==

The following expects that you already know how to compile and have basic understanding of script modding GTAIV.

You need to compile the following files using scocl individually:

* 3s_trainer.c - Main script launched by "3s_trainer_startup".
* 3s_trainer_brake.c - Vehicle - Modify - Brake.
* 3s_trainer_gexit.c - Modifies global vars to enable mobile phone.
* 3s_trainer_globals.c - Modifies global vars to disable mobile phone.
* 3s_trainer_health.c Player - Health - Invincible.
* 3s_trainer_speed.c Vehicle - Modify - Speed.
* 3s_trainer_startup.c - First script run by ModManager.
* 3s_trainer_steer.c Vehicle - Modify - Steer.

So you should end up with 8 sco's.

== Globalize 3s_trainer_globals.sco & 3s_trainer_gexit.sco ==

3s_trainer_globals.sco & 3s_trainer_gexit.sco on their own won't do anything. They need to be edited in SCOToolbox to modify the game global vars.

Find:

Push 0x0
GlobalVar
RefGet

Replace:

PushD 18
GlobalVar
PushS 100
Add
RefGet

== Script Flags ==

3s_trainer_brake.sco/3s_trainer_speed.sco/3s_trainer_steer.sco needs the script flag #1 ticked in SCOToolbox.