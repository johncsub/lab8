#ifndef _DANIELT_H_
#define _DANIELT_H_

//defined types
typedef float Flt;
struct Vec {
    float x, y, z;
};
typedef Flt Matrix[4][4];
//
struct Shape {
    float width, height;
    float radius;
    Vec center;
};

struct Particle {
    Shape s;
    Vec velocity;
};

struct EMissile {
    Vec pos;
    Vec vel;
    float color[3];
    struct timespec time;
    EMissile() { }
};


struct Game {
    Shape box;
    Particle particle[10];                       
    EMissile *emarr;                                  
    int n;
    int nmissiles;
    Game() {
	emarr = new EMissile[10];
	n = 0;
	nmissiles = 0;
    }
    ~Game() {
	delete [] emarr;
    }
};

extern void eMissileCollision();
extern void createEMissiles(Game *game);
extern void renderEMissiles(Game *game);

#endif 
