//Daniel Turack
//Written: April 27, 2016
//Last Modification: May 3, 2016
//Program will control Enemy Missiles


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
		e->vel.y += 0.8;
		//cityChange();
	    }
	}

	//check for collision with floor
	c = &sh->floor;
	if (e->pos.y <= c->center.y+c->height) {
	    e->vel.y += 0.8;
	}

	//check for off screen
	if (e->pos.y < 0.0 || e->pos.y > WINDOW_HEIGHT || e->pos.x < 0.0 || e->pos.x > WINDOW_WIDTH) {
	    game->emarr[i] = game->emarr[game->nmissiles-1];
	    game->nmissiles--;
	}
    }
    return;
}

//initialize enemy missles from top of screen
void createEMissiles(Game *g)
{
    for (int i=g->nmissiles; i<MAX_EMISSILES; i++) {
	EMissile *e = &g->emarr[g->nmissiles];
	e->pos.y = WINDOW_HEIGHT-1;
	e->pos.x = WINDOW_WIDTH-(rand()%WINDOW_WIDTH);
	e->pos.z = 0;
	e->vel.y = -2.0;
	e->vel.x = (rand()%100)*0.01;
	//e->vel.x = (g->nmissiles-(MAX_EMISSILES/2))*0.5;
	e->vel.z = 0;
	e->color[0] = 0.0f;
	e->color[1] = 1.0f;
	e->color[2] = 0.0f;
	g->nmissiles++;
    }
}

//function to be called in main render function to display enemy missiles
void renderEMissiles(Game *g) 
{
    for (int i=0; i<g->nmissiles; i++) {
	EMissile *e = &g->emarr[i];
	glPushMatrix();
	glColor3ub(150, 100, 230);
	glBegin(GL_QUADS);
	glVertex2i(e->pos.x-2, e->pos.y-5);
	glVertex2i(e->pos.x-2, e->pos.y+5);
	glVertex2i(e->pos.x+2, e->pos.y+5);
	glVertex2i(e->pos.x+2, e->pos.y-5);
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
    //glClear(GL_COLOR_BUFFER_BIT);
    r.bot = ypoint - 10;
    r.left = xpoint;
    r.center = 10;
    ggprint8b(&r, 16, 0x00ff0000, "Daniel Turack");
}

