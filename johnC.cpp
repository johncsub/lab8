/* 
 * File:    johnC.cpp
 * Author:  John B. Crossley
 * Program: missileCommand (team Project)
 * Purpose: Functions for firing Dmissiles (defense missiles) up to 
 *          destroy/Stop Emissiles (Enemy Missiles)
 *          
 *          So far I just change the title bar text with mouse left and 
 *          right buttons to prove I am accessing my functions from 
 *          main file "missileCommand.cpp" and visa-versa
 *          
 *          removed the extra empty lines from within the functions
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
#include "missileCommand.h"

using namespace std;

/*
 * 
 */
void changeTitle() 
{
    XStoreName(dpy, win, "335 Lab1 JBC Changed Title to prove a point");
}

void fireDefenseMissile() 
{
    XStoreName(dpy, win, "Missile Fired");
    std::cout << "JBC Missile Fired" << std::endl;
}
