//Author: Jose Garcia
//Program: joseG.cpp
//Purpose: This program is the background of our project
//

struct Vect {
        float x, y, z;
};

struct Shape {
        float width, height;
        float radius;
        Vect center;
};

struct Structures {
        Shape floor;
        Shape city;
};

extern void renderStruc(Structures *shape);
