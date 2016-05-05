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

using namespace std;


//macros for vectors
#define rnd() (((double)rand())/(double)RAND_MAX)
#define random(a) (rand()%a)
#define VecZero(v) (v)[0]=0.0,(v)[1]=0.0,(v)[2]=0.0
#define MakeVector(x, y, z, v) (v)[0]=(x),(v)[1]=(y),(v)[2]=(z)
#define VecCopy(a,b) (b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2]
#define VecDot(a,b)	((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])
#define VecSub(a,b,c) (c)[0]=(a)[0]-(b)[0]; \
			     (c)[1]=(a)[1]-(b)[1]; \
(c)[2]=(a)[2]-(b)[2]
//constants
const int MAX_EMISSILES = 10;


//defined types
typedef float Flt;
typedef Flt Matrix[4][4];
//

/*void eMissileCollision()
{
    return;
}*/
//initialize emeny missles from top of screen
void createEMissiles(Game *g)
{

    for (int i=0; i<MAX_EMISSILES; i++) {
	EMissile *e = &g->emarr[g->nmissiles];
	e->pos.y = 400;
	e->pos.x = 400;
	e->pos.z = 0;
	e->vel.y = 0.05;
	e->vel.x = -0.02;
	e->vel.z = 0;
	e->color[0] = 1.0f;
	e->color[1] = 0.0f;
	e->color[2] = 1.0f;
	g->nmissiles++;
    }
}

//function to be called in main render function to display enemy missiles
void renderEMissiles(Game *g) {
    for (int i=0; i<g->nmissiles; i++) {
	EMissile *e = &g->emarr[i];
	glPushMatrix();
	glColor3ub(150, 100, 230);
        glBegin(GL_QUADS);
        glVertex2i(e->pos.x+2, e->pos.y-2);
        glVertex2i(e->pos.x-2, e->pos.y+2);
        glVertex2i(e->pos.x+2, e->pos.y+2);
        glVertex2i(e->pos.x-2, e->pos.y-2);
	glEnd();
	glPopMatrix();
    }
}
