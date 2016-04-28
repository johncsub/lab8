#ifndef _JOSER_H_
#define _JOSER_H_

#define WINDOW_WIDTH  1024
#define WINDOW_HEIGHT 768
#define MAX_PARTICLES 2000
#define GRAVITY 0.1
//Number of buttons to show on menu, grows from bottom
#define BUTTONS 3
//X Position of all buttons
//Divides WINDOW_WIDTH by the number below
#define BUTTON_X 4.25

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

struct Game {
	Shape box[5];
	Shape circle;
	Particle particle[MAX_PARTICLES];
	//JR: This will store the values of the x-pos to be used
	//		for correct font placement on buttons
	int buttonSpacer[BUTTONS];
	//JR: This will be used to return which button the mouse
	//		is currently on in the menus
	int mouseOnButton[BUTTONS];
	int n;
};

//Function Prototypes
extern void drawMenu(Game *game);
extern void mouseOver(int x, int y, Game *game);
extern void renderMenuObjects(Game *game);


#endif