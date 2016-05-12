//Daniel Turack
//Written: April 27, 2016
//Last Modification Date: May 11, 2016
//Last Modification: Added physics for explosions
//Program will control Enemy Missiles and the resulting collisions


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include "danielT.h"
extern "C" {
#include "fonts.h"
}

using namespace std;


//macros for vectors
#define rnd() (((double)rand())/(double)RAND_MAX)
#define random(a) (rand()%a)
#define VecZero(v) (v)[0]=0.0,(v)[1]=0.0,(v)[2]=0.0
#define MakeVector(x, y, z, v) (v)[0]=(x),(v)[1]=(y),(v)[2]=(z)
#define VecCopy(a,b) (b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2]
#define VecDot(a,b) ((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])

//constants
const int MAX_EMISSILES = 10;


//defined types
typedef float Flt;
typedef Flt Matrix[4][4];
//

//handles missile explosion physics
void eExplosionPhysics(Game *game)
{
	EExplosion *e;
	
	if (game->neexplosions <=0) {
		return;
	}
	for (int m=0; m<game->neexplosions; m++) {
		e = &game->eearr[m];
		e->radius += e->radiusInc;
		e->color[0] *= -1.0;
		e->color[1] = 0.1;
		e->color[2] = 0.1;
		
		if (e->radius >= 50.0) {
			e->radiusInc *= -1.0;
		}
		if (e->radius <= 0.0) {
			game->eearr[m] = game->eearr[game->neexplosions-1];
			game->neexplosions--;	
		}
	}
}

//handles missile movement and collisions
void eMissilePhysics(Game *game, Structures *sh)
{
    EMissile *e;
    Shape *c;

    if (game->nmissiles <=0)
	return;
    for (int i=0; i<game->nmissiles; i++) {
	e = &game->emarr[i];
	e->pos.x += e->vel.x;
	e->pos.y += e->vel.y;

	//check for collision with cities 
	for (int k=0; k<CITYNUM; k++) {
	    c = &sh->city[k];
	    if (e->pos.y <= c->center.y+c->height && e->pos.x <= c->center.x+c->width && e->pos.x >= c->center.x-c->width) {
		//cityChange();
		eMissileExplode(game, i);
	    }
	}

	//check for collision with floor
	c = &sh->floor;
	if (e->pos.y <= c->center.y+c->height) {
	    eMissileExplode(game, i);
	}

	//check for off screen
	if (e->pos.y < 0.0 || e->pos.x <= 0.0 || e->pos.x >= WINDOW_WIDTH) {
	    eMissileExplode(game, i);
	    std::cout << "misoff" << std::endl;
	    //game->emarr[i] = game->emarr[game->nmissiles-1];
	    //game->nmissiles--;
	}
    }
    return;
}



void eMissileExplode(Game *game, int misnum)
{
    EMissile *e = &game->emarr[misnum];
    //create explosion graphic
    createEExplosion(game, e->pos.x, e->pos.y);
    //delete missile
    game->emarr[misnum] = game->emarr[game->nmissiles-1];
    game->nmissiles--;
}

//initialize enemy missles from top of screen
void createEMissiles(Game *g)
{
    float mRatio, endPt;
    for (int i=g->nmissiles; i<MAX_EMISSILES; i++) {
	EMissile *e = &g->emarr[g->nmissiles];
	e->pos.y = WINDOW_HEIGHT-1;
	e->pos.x = WINDOW_WIDTH-(rand()%WINDOW_WIDTH);
	e->pos.z = 0;
	e->vel.y = -2.0;
	//randomize direction of missiles
	if (rand()%2==0) { 
	    e->vel.x = (rand()%100)*0.01*e->vel.y;
	}
	else
	    e->vel.x = (rand()%100)*-0.01*e->vel.y;
	//check for missiles aimed off screen
	//e->angle = asin(e->vel.x/(sqrt(e->vel.y*e->vel.y+e->vel.x*e->vel.x)));
	//if so, reverse direction e->vel.x = e->vel.x*-1.0;
	mRatio = e->vel.y/e->vel.x;
	endPt = e->pos.x + (mRatio*(WINDOW_HEIGHT/e->vel.y));
	if (endPt >=WINDOW_WIDTH-5.0 || endPt <= 5.0) {
		e->vel.x *= -1.0;
		e->vel.x = e->vel.x/2;
	}

	e->vel.z = 0;
	e->color[0] = 0.0f;
	e->color[1] = 1.0f;
	e->color[2] = 0.0f;
	g->nmissiles++;
    }
}

void createEExplosion(Game *g, float x, float y)
{
    EExplosion *e = &g->eearr[g->neexplosions];
    e->pos.y = y;
    e->pos.x = x;
    e->pos.z = 0;
    e->radius = 4.0;
    e->radiusInc = 0.5;
    e->color[0] = 1.0f;
    e->color[1] = 0.0f;
    e->color[2] = 0.0f;
    g->neexplosions++;
}

void renderEMissiles(Game *g)
{
    for (int i=0; i<g->nmissiles; i++) {
	EMissile *e = &g->emarr[i];
	glPushMatrix();
	//glRotatef(e->angle, e->pos.x, e->pos.y, e->pos.z);
	glColor3f(e->color[0], e->color[1], e->color[2]);
	glBegin(GL_QUADS);
	glVertex2i(e->pos.x-1, e->pos.y-6);
	glVertex2i(e->pos.x-3, e->pos.y+6);
	glVertex2i(e->pos.x+3, e->pos.y+6);
	glVertex2i(e->pos.x+1, e->pos.y-6);
	glEnd();
	glPopMatrix();
    }
}

//function to be called in main render function to display enemy missiles
void renderEExplosions(Game *g) 
{
    int tris = 20;
    float twicePi = 2.0f * 3.14159265359;
    for (int i=0; i<g->neexplosions; i++) {
	EExplosion *e = &g->eearr[i];
	glPushMatrix();
	glColor3f(e->color[0], e->color[1], e->color[2]);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(e->pos.x, e->pos.y);
	for (int i=0; i<=tris; i++) {
	    glVertex2f(
		    e->pos.x + (e->radius * cos(i * twicePi/tris)),
		    e->pos.y + (e->radius * sin(i * twicePi/tris))
		    );
	}
	glEnd();
	glPopMatrix();
    }
}

void nameInBox(float xpoint, float ypoint)
{
    float w = 50.0;
    float h = 10.0;
    glColor3ub(100, 140, 100);
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2i(xpoint-w, ypoint-h);
    glVertex2i(xpoint-w, ypoint+h);
    glVertex2i(xpoint+w, ypoint+h);
    glVertex2i(xpoint+w, ypoint-h);
    glEnd();
    glPopMatrix();
    Rect r;    
    r.bot = ypoint - 10;
    r.left = xpoint;
    r.center = 10;
    ggprint8b(&r, 16, 0x00ff0000, "Daniel Turack");
}

