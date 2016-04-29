//Author: Jose Garcia 
//Program: joseG.cpp
//Purpose: This program is my source code for the structures/cities
//
// #pragma once
#include "joseG.h"
#include <GL/glx.h>
extern void initOpengl();
void renderStruc(Structures *shape) {
	initOpengl();
        //floor shape
        shape->floor.width = 512;
        shape->floor.height = 100;
        shape->floor.center.x = 512;
        shape->floor.center.y = 10;

        /*//city shape
        shape.city.width = 30;
        shape.city.height = 50;
        shape.city.center.x = 512;
        shape.city.center.y = 65;
*/

	float w, h/* w2, h2, w3, h3, w4, h4, w5, h5*/;
        //Draw shapes...

        //draw floor
        glColor3ub(255,255,255);
        //s = shape->floor;
        glPushMatrix();
        glTranslatef(shape->floor.center.x, shape->floor.center.y, shape->floor.center.z);
        w = shape->floor.width;
        h = shape->floor.height;
        glBegin(GL_QUADS);
                glVertex2i(-w,-h);
                glVertex2i(-w, h);
                glVertex2i( w, h);
                glVertex2i( w,-h);
        glEnd();
        glPopMatrix();

        /*//draw cities
        Shape *s2;
        glColor3ub(87,87,87);
        s2 = shape.city;
        glPushMatrix();
        glTranslatef(s2.center.x - 200, s2.center.y, s2.center.z);
        w2 = s2.width;
        h2 = s2.height;
        glBegin(GL_QUADS);
                glVertex2i(-w2,-h2);
                glVertex2i(-w2, h2);
                glVertex2i( w2, h2);
                glVertex2i( w2,-h2);
        glEnd();
        glPopMatrix();

        Shape *s3;
        //glColor3ub(87,87,87);
        s3 = shape.city;
        glPushMatrix();
        glTranslatef(s3->center.x - 400, s3->center.y, s3->center.z);
        w3 = s3->width;
        h3 = s3->height;
        glBegin(GL_QUADS);
                glVertex2i(-w3,-h3);
                glVertex2i(-w3, h3);
                glVertex2i( w3, h3);
                glVertex2i( w3,-h3);
        glEnd();
        glPopMatrix();

        Shape *s4;
        //glColor3ub(87,87,87);
        s4 = shapes.city;
        glPushMatrix();
        glTranslatef(s4->center.x + 200, s4->center.y, s2->center.z);
        w4 = s4->width;
        h4 = s4->height;
        glBegin(GL_QUADS);
                glVertex2i(-w4,-h4);
                glVertex2i(-w4, h4);
                glVertex2i( w4, h4);
                glVertex2i( w4,-h4);
        glEnd();
        glPopMatrix();

        Shape *s5;
        //glColor3ub(87,87,87);
        s5 = &shapes->city;
        glPushMatrix();
        glTranslatef(s5->center.x + 400, s5->center.y, s5->center.z);
        w5 = s5->width;
        h5 = s5->height;
        glBegin(GL_QUADS);
                glVertex2i(-w5,-h5);
                glVertex2i(-w5, h5);
                glVertex2i( w5, h5);
                glVertex2i( w5,-h5);
        glEnd();
        glPopMatrix();*/

}
