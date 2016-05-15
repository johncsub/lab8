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
 *          5/13-14
 *          Added missile firing to mouse coords from 0,0 ONLY!
 *          Still need to make it fire from other locations
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

extern void dMissileExplode(Game *game, int dMissilenumber);

/*
 * 
 */
void changeTitle() 
{
    XStoreName(dpy, win, "335 Lab1 JBC Changed Title to prove a point");
}


// Previously called "movement"
// void renderDefenseMissile(Game *game, double xStart, double yStart)
void renderDefenseMissile(Game *game)
{
    DefenseMissile *dMissilePtr;
    float w, h;
    
    for (int i=0; i<game->numberDefenseMissiles; i++) {
        Vec *c = &game->dMissile[i].shape.center;
        w = 5;
        h = 5;
        glColor3f(game->dMissile[i].color[0],
                game->dMissile[i].color[1], 
                game->dMissile[i].color[2]);
//        glColor3f(&game->dMissile[i].color[0], 
//                    &game->dMissile[i].color[1], 
//                    &game->dMissile[i].color[2]);
        glBegin(GL_QUADS);
            glVertex2i(c->x-w, c->y-h);
            glVertex2i(c->x-w, c->y+h);
            glVertex2i(c->x+w, c->y+h);
            glVertex2i(c->x+w, c->y-h);
        glEnd();
        glPopMatrix();
    }
    

    if (game->numberDefenseMissiles <= 0)
        return;

    for (int i=0; i<game->numberDefenseMissiles; i++) {
        dMissilePtr = &game->dMissile[i];


//        // shape.center refers to the Shape's "s" center's position
//        // IE the position of the center of that particular Shape
//        dMissilePtr->shape.center.x += dMissilePtr->velocity.x;
//        dMissilePtr->shape.center.y += dMissilePtr->velocity.y;
            

        
        if (dMissilePtr->destinationY >= dMissilePtr->shape.center.y ) {
        // shape.center refers to the Shape's "s" center's position
        // IE the position of the center of that particular Shape
        dMissilePtr->shape.center.x += dMissilePtr->velocity.x;
        dMissilePtr->shape.center.y += dMissilePtr->velocity.y;
            
        } else {
            // game->numberDefenseMissiles--;
            dMissileExplode(game, i);
            
        }

    }
}


void createDefenseMissileExplosion(Game *game, float x, float y)
{
    DExplosion * defExplosion = 
        &game->defExplArray[game->numDefExplosions];
//    EExplosion *e = &g->eearr[g->neexplosions];
    
    defExplosion->pos.y = y;
    defExplosion->pos.x = x;
    defExplosion->pos.z = 0;
    defExplosion->radius = 4.0;
    defExplosion->radiusInc = 0.5;
    defExplosion->color[0] = 0.0f;
    defExplosion->color[1] = 255.0f;
    defExplosion->color[2] = 0.0f;
    
    // game->neexplosions++;
}



void dMissileExplode(Game *game, int dMissilenumber)
{
    // DefenseMissile *dMissilePtr = &game->dMissile[dMissilenumber];
    
    //delete defense missile
    game->dMissile[dMissilenumber] = 
        game->dMissile[game->numberDefenseMissiles - 1];

//    createDefenseMissileExplosion (game, dMissilePtr->shape.center.x, 
//        dMissilePtr->shape.center.y);

    game->numberDefenseMissiles--;
}

//function to be called in main render function to display enemy missiles
void renderDefExplosions(Game *game) 
{
    int tris = 20;
    float twicePi = 2.0f * 3.14159265359;
    for (int i=0; i < game->numDefExplosions; i++) {
	DExplosion * defExplosion = &game->defExplArray[i];
	glPushMatrix();
	glColor3f(defExplosion->color[0], defExplosion->color[1],
            defExplosion->color[2]);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(defExplosion->pos.x, defExplosion->pos.y);
	for (int i=0; i<=tris; i++) {
	    glVertex2f(
		defExplosion->pos.x + (defExplosion->radius * 
                    cos(i * twicePi/tris)),
		defExplosion->pos.y + (defExplosion->radius * 
                    sin(i * twicePi/tris))
            );
	}
	glEnd();
	glPopMatrix();
    }
}


// 5/14 changes to make missile firing work
// seems OK now... :-)
void makeDefenseMissile(Game *game, int x, int y)
{

    if (game->numberDefenseMissiles >= MAX_D_MISSILES)
        return;
	//std::cout << "makeDefenseMissile()" << x << " " << y << std::endl;
	
	DefenseMissile *dMissilePtr = 
                &game->dMissile[game->numberDefenseMissiles];
        dMissilePtr->shape.width = 10;
        dMissilePtr->shape.height = 10;
        dMissilePtr->shape.radius = 10;

        dMissilePtr->color[0] = 0;
        dMissilePtr->color[1] = 255;
        dMissilePtr->color[2] = 0;

        dMissilePtr->destinationX = x;
        dMissilePtr->destinationY = y;
        
        
        // set speed of missile
        // 0.5 is a good start, 0.25 seemed a bit to slow & 5.0 
        // seemed insanely fast
        float missileSpeed = 0.75;
        
        // set start position of missile
        // Works now @ 2pm 05/14/16
        float xStart = 500.0;
        float yStart = 50.0;
        dMissilePtr->shape.center.x = xStart;
        dMissilePtr->shape.center.y = yStart;
        
//        // set target of missile from mouse coords
//        float xMissileTarget = x;
//        float yMissileTarget = y;

        // do the math to find X,Y coords of mouse to pass to 
        // missile as target
        float dx = dMissilePtr->destinationX - xStart;
        float dy = dMissilePtr->destinationY - yStart;
        float dist = sqrt(dx*dx + dy*dy);
        dx /= dist;
        dy /= dist;
        float missileVelocityX = 0;
        float missileVelocityY = 0;

//        missileVelocityX = xStart + missileSpeed * dx;
        missileVelocityX = missileSpeed * dx;
        missileVelocityY = missileVelocityY + missileSpeed * dy;

        // Velocity is a vector quantity that refers to 
        // the rate at which an object changes its position.
        // The diff between X & Y determines the angle
        dMissilePtr->velocity.y = missileVelocityY;
        dMissilePtr->velocity.x = missileVelocityX;

        game->numberDefenseMissiles++;
}

