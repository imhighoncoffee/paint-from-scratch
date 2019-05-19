//A simple paint program by Jehad Mohamed, @imhighoncoffee

#include<GL/glut.h>
#define RED 2
#define GREEN 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define YELLOW 7
#define BLACK 8
#define ERASER 9

int ScreenHeight = 600, brushSize=3;
float red=0.0, green=0.0, blue=1.0;

// My init function
void MyInit(){
    glClearColor(1,1,1,1);
    glColor3f(red,blue,green);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
}
