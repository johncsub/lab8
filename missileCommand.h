/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   missileCommand.h
 * Author: student
 *
 * Created on April 28, 2016, 3:52 PM
 */

// #ifndef MISSILECOMMAND_H
// #define MISSILECOMMAND_H




#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>




//Number of buttons to show on menu
#define BUTTONS 3
//X Position of all buttons
//Divides WINDOW_WIDTH by the number below
#define BUTTON_X 4.25
#define WINDOW_WIDTH  1024
#define WINDOW_HEIGHT 768
// #define WINDOW_WIDTH  1024
// #define WINDOW_HEIGHT 768
#define MAX_PARTICLES 2000
#define GRAVITY 0.1

// #define MAX_PARTICLES 500
#define GRAVITY 0.1

//X Windows variables
extern Display *dpy;
extern Window win;
extern GLXContext glc;

struct Vec {
    float x, y, z;
};


struct Shape {
	float width, height;
	float radius;
	Vec center;
};

  
struct Particle {
	Shape s;
	Vec velocity;
};

struct Structures {
        Shape floor;
        Shape city;
};
 

// struct Game {
//	Shape box[5];
//	Shape circle;
//	Particle particle[MAX_PARTICLES];
//	//JR: This will store the values of the x-pos to be used
//	//		for correct font placement on buttons
//	int buttonSpacer[BUTTONS];
//	//JR: This will be used to return which button the mouse
//	//		is currently on in the menus
//	int mouseOnButton[BUTTONS];
//	int n;
//};

 struct EMissile {
    Vec pos;
    Vec vel;
    float color[3];
    
    // JBC note dont know what it is so just commment for now
    // struct timespec time;
    
    EMissile() { }
};

struct Game {
    
    // JBC comment out
    // Particle particle[10];                       
     Shape box[5];
    //JR: This will store the values of the x-pos to be used
    //      for correct font placement on buttons
    int buttonSpacer[BUTTONS];
    //JR: This will be used to return which button the mouse
    //      is currently on in the menus
    int mouseOnButton[BUTTONS];
    //JR: Will store value for menu if left click was on Exit button
    //      if 1 will exit
    int menuExit;  
    EMissile *emarr;                                  
    int n;
    int nmissiles;
    Game() {
	   emarr = new EMissile[10];
	   n = 0;
	   nmissiles = 0;
       menuExit = 0;
    }
    ~Game() {
	delete [] emarr;
    }
    Particle particle[MAX_PARTICLES];   
};


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

// #endif /* MISSILECOMMAND_H */

