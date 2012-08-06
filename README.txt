= Three-Socks Trainer =

Release thread: http://psx-scene.com/forums/f276/%5Brel%5D-three-socks-trainer-v1-0-beta-104903/ (Information/Downloads)

----

= For Developers =

== How To Compile ==

The following expects that you already know how to compile and have basic understanding of script modding GTAIV.

Download the latest menu library: https://bitbucket.org/ThreeSocks/gtaiv-menu-library/

You need to compile the following files using scocl individually:

* 3s_trainer.c - Main script launched by "3s_trainer_startup".
* 3s_trainer_brake.c - Vehicle - Modify - Brake.
* 3s_trainer_health.c Player - Health - Invincible.
* 3s_trainer_wanted.c Player - Wanted - Never Wanted.
* 3s_trainer_speed.c Vehicle - Modify - Speed.
* 3s_trainer_startup.c - First script run by ModManager.
* 3s_trainer_steer.c Vehicle - Modify - Steer.

So you should end up with 7 sco's.

== menu_globals.sco & menu_gexit.sco ==

menu_globals.sco and menu_gexit.sco have been modified to change the game globals in SCOToolbox. So you need to use the .sco's found in the trainer release thread.

== Script Flags ==

3s_trainer_brake.sco/3s_trainer_speed.sco/3s_trainer_steer.sco needs the script flag #1 ticked in SCOToolbox.