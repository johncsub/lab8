/* 
 * File:    johnBC.cpp
 * Author:  John B. Crossley
 * Program: missileCommand (team Project)
 * Purpose: Functions for firing Dmissiles (defense missiles) up to 
 *          destroy/Stop Emissiles (Enemy Missiles)
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

//X Windows variables
extern Display *dpy;
extern Window win;
extern GLXContext glc;


using namespace std;

/*
 * 
 */
void fireDefenseMissile(void) 
{
    XStoreName(dpy, win, "335 Lab1 JBC Changed LMB for particle");

    
}

