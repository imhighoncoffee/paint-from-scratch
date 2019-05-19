/*
A simple paint program by
Jehad Mohamed ,@imhighoncoffee
Made for VTU Computer Graphics Mini Project

USAGE: gcc main.cpp -lfreeglut -lopengl32 -lglu32
a.exe
*/
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
float red=0.0, green=0.0, blue=0.0;

// My init function
void myInit(){
    glClearColor(1,1,1,1);
    glColor3f(red,blue,green);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
}

// My display function
void myDisplay(){
    //glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// mouse function to draw pixel
void myMouse(int mx, int my){
    glColor3f(red,green,blue);
    GLint x=mx,y=ScreenHeight-my;
    glRecti(x,y,x+brushSize,y+brushSize);
    glFlush();
}

// keyboard function to control brushsize, clear or exit
void myKeyboard(unsigned char key, int mx, int my){
    switch(key){
        case '+': brushSize++; break;
        case '-': if(brushSize>1)brushSize++; break;
        case 'c':   glClear(GL_COLOR_BUFFER_BIT);
                    glFlush(); break;
        case 'e': exit(-1);
        default: break;
    }
}

//menu callback function
void myMenuCallback(int option){
    switch(option){
        case RED : red=1.0; green= 0.0; blue =0.0; break;
        case BLUE : red=0.0; green= 0.0; blue =1.0; break;
        case GREEN : red=0.0; green= 1.0; blue =0.0; break;
        case YELLOW : red=1.0; green= 1.0; blue =0.0; break;
        case CYAN: red=0.0; green= 1.0; blue =1.0; break;
        case MAGENTA : red=1.0; green= 0.0; blue =1.0; break;
        case BLACK : red=0.0; green= 0.0; blue =0.0; break;
        case ERASER : red=1.0; green= 1.0; blue =1.0; break;
    }
}

// Main Function
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Paint by Jehad && Adi");
    glutDisplayFunc(myDisplay);
    glutMotionFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutCreateMenu(myMenuCallback);
    glutAddMenuEntry("RED",RED);
    glutAddMenuEntry("BLUE",BLUE);
    glutAddMenuEntry("GREEN",GREEN);
    glutAddMenuEntry("MAGENTA",MAGENTA);
    glutAddMenuEntry("CYAN",CYAN);
    glutAddMenuEntry("YELLOW",YELLOW);
    glutAddMenuEntry("BLACK",BLACK);
    glutAddMenuEntry("ERASER",ERASER);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    myInit();
    glutMainLoop();
    return 0;
}