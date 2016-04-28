// Author:  Jose Reyes
// Date:    April 28, 2016
// Program: joseR.cpp
// Purpose: Draw and create a functioning menu that will allow
//			the user to play, change settings, and exit the game.
#include <GL/glx.h>
#include "joseR.h"

extern void init_opengl(); 

void drawMenu(Game *game)
{
	for (int j = 0; j < BUTTONS; j++) {		
		game->buttonSpacer[j] = 650 - (j*90);
		game->box[j].width = 120;
		game->box[j].height = 25;
		game->box[j].center.x = WINDOW_WIDTH / BUTTON_X;
		game->box[j].center.y = WINDOW_HEIGHT - game->buttonSpacer[j];
		//std::cout << game.box[j].center.y << std::endl;
		//std::cout << game.box[j].center.x << std::endl;
	}
}

void renderMenuObjects(Game *game)
{
	Shape *s;
	init_opengl();
	float w, h;
	for (int i = 0; i < BUTTONS; i++) {
		s = &game->box[i];
		//Button colors based on mouse position
		if (game->mouseOnButton[i] == 1) {
			//Button selected color
			glColor3ub(190,90,190);
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

void mouseOver(int savex, int savey, Game *game)
{
	Shape *s;
	for (int j = 0; j < BUTTONS; j++) {			
		s = &game->box[j];
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