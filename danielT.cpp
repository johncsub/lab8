//Daniel Turack
//Program will control Enemy Missiles


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <X11/Xlib.h>
//#include <X11/Xutil.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include "danielT.h"
// #include "missileCommand.h"

//#include "log.h"
//#include "ppm.h"
//extern "C" {
//	#include "fonts.h"
//}
using namespace std;

/*defined types
typedef float Flt;
typedef float Vec[3];
typedef Flt Matrix[4][4];*/

//macros
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
const float timeslice = 1.0f;
const float gravity = -0.2f;
#define PI 3.141592653589793
#define ALPHA 1
const int MAX_EMISSILES = 10;


//defined types
typedef float Flt;
typedef Flt Matrix[4][4];
//




 

//X Windows variables
//Display *dpy;
//Window win;
//GLXContext glc;


//Setup timers
const double physicsRate = 1.0 / 60.0;
const double oobillion = 1.0 / 1e9;
extern struct timespec timeStart, timeCurrent;
extern struct timespec timePause;
extern double physicsCountdown;
extern double timeSpan;
extern double timeDiff(struct timespec *start, struct timespec *end);
extern void timeCopy(struct timespec *dest, struct timespec *source);
//

// JBC comment to avoid  compilation errors
//int xres=1250, yres=900;
int newMissiles = 1;

/*struct EMissile {
    Vec pos;
    Vec vel;
    float color[3];
    struct timespec time;
    EMissile() { }
};*/

/*void renderEMissile(Game *game);
void eMissileCollision(void);
void createEMissiles(Game *game);*/

void eMissileCollision()
{
    return;
}

void createEMissiles(Game *g)
{

    for (int i=0; i<MAX_EMISSILES; i++) {
	EMissile *e = &g->emarr[g->nmissiles];
// JBC comment to avoid redefinition compilation errors
	e->pos.y = 400;
// JBC comment to avoid redefinition compilation errors
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
