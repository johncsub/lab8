// Author:   Jose Reyes
// Created:  April 28, 2016
// Modified: May 2, 2016
// Program:  joseR.cpp
// Purpose:  
//	Draw and create a functioning menu that will allow
//	the user to play, change settings, and exit the game.
// Progress: 
//	Menu shapes, text, and shape color change on mouse hover.
//	The exit button will close on click.
//
//
#include <GL/glx.h>
#include "missileCommand.h"
#include "joseR.h"
extern "C" {
	#include "fonts.h"
}

extern void init_opengl(); 

void drawMenu(Game *game)
{
	for (int j = 0; j < BUTTONS; j++) {		
		//game->buttonSpacer[j] = 650 - (j*90);
		game->buttonSpacer[j] = 350 - (j*90);
		game->mButton[j].width = 120;
		game->mButton[j].height = 25;
		game->mButton[j].center.x = WINDOW_WIDTH / BUTTON_X;
		game->mButton[j].center.y = WINDOW_HEIGHT - game->buttonSpacer[j];
	}
}

void renderMenuObjects(Game *game)
{
	Shape *s;
	init_opengl();
	float w, h;
	for (int i = 0; i < BUTTONS; i++) {
		s = &game->mButton[i];
		glColor3ub(128,128,128);
		//Button colors based on mouse position
		if (game->mouseOnButton[i] == 1) {
			//Button selected color
			glColor3ub(190,190,190);
		} else {
			//Button default color
			glColor3ub(128,128,128);
		}
		glPushMatrix();
		glTranslatef(s->center.x, s->center.y, s->center.z);
		w = s->width;
		h = s->height;
		glBegin(GL_QUADS);
		glVertex2i(-w,-h);
		glVertex2i(-w, h);
		glVertex2i( w, h);
		glVertex2i( w,-h);
		glEnd();
		glPopMatrix();
	}
}

void renderMenuText(Game *game)
{
	Rect rt;
	int j = 0;
	rt.bot = WINDOW_HEIGHT - game->buttonSpacer[j] - 10;
	rt.left = WINDOW_WIDTH / BUTTON_X;
	//std::cout << rt.bot << " " << rt.left << std::endl;
	rt.center = 1;
	ggprint16(&rt, 16, 0x00ffffff, "Exit");
	j++;
	rt.bot = WINDOW_HEIGHT - game->buttonSpacer[j] - 10;
	ggprint16(&rt, 16, 0x00ffffff, "Settings");
	j++;
	rt.bot = WINDOW_HEIGHT - game->buttonSpacer[j] - 10;
	ggprint16(&rt, 16, 0x00ffffff, "Play");
}

void mouseOver(int savex, int savey, Game *game)
{
	Shape *s;
	for (int j = 0; j < BUTTONS; j++) {			
		s = &game->mButton[j];
		if (savey >= s->center.y - (s->height) &&
			savey <= s->center.y + (s->height) &&
			savex >= s->center.x - (s->width) &&
			savex <= s->center.x + (s->width)) {
				game->mouseOnButton[j] = 1;
		} else {
			game->mouseOnButton[j] = 0;
		}
	}
}

void menuClick(Game *game)
{
	//Play Button (2)
	//Settings Button (1)
	//Exit Button (0)
	if (game->mouseOnButton[0] == 1){
		//std::cout << "Quitting..." << std::endl;
		game->menuExit = 1;
	}
}
