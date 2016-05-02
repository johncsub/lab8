// Author:  Jose Reyes
// Date:    April 28, 2016
// Program: joseR.cpp
// Purpose: Draw and create a functioning menu that will allow
//			the user to play, change settings, and exit the game.
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
		game->buttonSpacer[j] = 650 - (j*90);
		game->box[j].width = 120;
		game->box[j].height = 25;
		game->box[j].center.x = WINDOW_WIDTH / BUTTON_X;
		game->box[j].center.y = WINDOW_HEIGHT - game->buttonSpacer[j];
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

void menuClick(Game *game)
{
	//Exit Button
	if (game->mouseOnButton[0] == 1){
		std::cout << "test" << std::endl;
		game->menuExit = 1;
	}
}

// Function Locations
// ------------------------------
// drawMenu(&game) should be in: int main(void)
// 	before the infinite loop for "start animation"
//
// mouseOver(savex, savey, game) should be in: void check_mouse(...)
//	Should be at the end of the code that checks if the mouse moved.
//  The code itself is below:
//
//	if (savex != e->xbutton.x || savey != e->xbutton.y) {
//		savex = e->xbutton.x;
//		//JR: Changed to correctly get mouse y location
//		savey = WINDOW_HEIGHT - e->xbutton.y;
//		if (++n < 10)
//			return;
//		//JR: Function to detect when a mouse is on a button
//		//	Using collision detection to tell when the mouse is on
//		//	a specific button in our menu.
//		mouseOver(savex, savey, game);
//	}
//
// renderMenuObjects(game) and renderMenuText(game) should be in
//	the void render(Game *game) function.
//