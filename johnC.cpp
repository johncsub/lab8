/* 
 * File:    johnC.cpp
 * Author:  John B. Crossley
 * Program: missileCommand (team Project)
 * Purpose: Functions for firing Dmissiles (defense missiles) up to 
 *          destroy/Stop Emissiles (Enemy Missiles)
 *          
 *          (April 2016)
 *          So far I just change the title bar text with mouse left and 
 *          right buttons to prove I am accessing my functions from 
 *          main file "missileCommand.cpp" and visa-versa
 * 
 *          (05/07/2016)
 *          Added "fireDefenseMissile" (used to be "movement" 
 *          inside "misileCommand.cpp")
 *          
 *          removed the extra empty lines+ from within the functions
 *          (5/5/16)
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>

// extra comment

//#include "missileCommand.h"
#ifndef MISSILECOMMAND_H
#define MISSILECOMMAND_H
#include "missileCommand.h"
#endif



#ifndef _DANIELT_H_
#define _DANIELT_H_
#include "danielT.h"
#endif



using namespace std;

/*
 * 
 */
void changeTitle() 
{
    XStoreName(dpy, win, "335 Lab1 JBC Changed Title to prove a point");
}

//void fireDefenseMissile() 
//{
//    XStoreName(dpy, win, "Missile Fired");
//    std::cout << "JBC Missile Fired" << std::endl;
//}


// Previously called "movement"
void fireDefenseMissile(Game *game)
{
	// eMissilePhysics(game);
	
	DefenseMissile *dMissilePtr;

	if (game->n <= 0)
		return;

	for (int i=0; i<game->n; i++) {
		dMissilePtr = &game->dMissile[i];
		dMissilePtr->s.center.x += dMissilePtr->velocity.x;
		dMissilePtr->s.center.y += dMissilePtr->velocity.y;

		//gravity
		dMissilePtr->velocity.y -= 5;

		//check for collision with shapes...
		Shape *s;
		s = &game->box;
		if (dMissilePtr->s.center.y >= s->center.y - (s->height) &&
		    dMissilePtr->s.center.y <= s->center.y + (s->height) &&
		    dMissilePtr->s.center.x >= s->center.x - (s->width) &&
		    dMissilePtr->s.center.x <= s->center.x + (s->width)) {
				dMissilePtr->velocity.y *= -1.0;
		}

//		//check for off-screen
//		if (dMissilePtr->s.center.y < 0.0) {
//			std::cout << "off screen" << std::endl;
//                        //fireDefenseMissile();
//			game->dMissile[i] = game->dMissile[game->n-1];
//			game->n--;
//		}
	}
}

void makeDefenseMissile(Game *game, int x, int y)
{
	if (game->n >= MAX_PARTICLES)
		return;
	//std::cout << "makeDefenseMissile()" << x << " " << y << std::endl;
	//position of dMissile
	DefenseMissile *dMissilePtr = &game->dMissile[game->n];
	dMissilePtr->s.center.x = x;
	dMissilePtr->s.center.y = y;
	dMissilePtr->velocity.y = 5.0;
	dMissilePtr->velocity.x =  1.0;
	game->n++;
}

