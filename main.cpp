/*
A simple paint program by
Jehad Mohamed ,@imhighoncoffee
Made for VTU Computer Graphics Mini Project
USAGE: gcc main.cpp -lfreeglut -lopengl32 -lglu32
a.exe
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/freeglut.h>

#define RED 2
#define GREEN 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define YELLOW 7
#define BLACK 8
#define ERASER 9

int ScreenHeight = 600, brushSize=4;
float red=0.0, green=0.0, blue=0.0;
void *font;
void *currentfont;
int fontType,flag=0;
float i,j;
float x2,y2,r,r1=80,r2=5.0,r3=27.5,r4=6,r5=6,x,y,angle,angle_radians,r6=23,r7=2,r8=3,r9=6,r10=18,r11=10,r12=26,r13=14;
int k=0;
int p=0;

// My init function
void myInit(){
    glClearColor(1,1,1,1);
    glColor3f(red,blue,green);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,600);
}

//To write something on the screen
void drawstring(float x,float y,float z,char *string)
{
    char *c;
    glRasterPos3f(x,y,z);
    for(c=string; *c!='\0'; c++)
    {
	   glColor3f(0.0,1.0,1.0);
           glutBitmapCharacter(currentfont,*c);
    }
}

//To set the font of the string
void setFont(void *font)
{
    currentfont=font;
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
        case '-': if(brushSize>1)brushSize--; break;
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

//menu callback function
void menucallback(int option){
    switch(option){
        case 1 : glutLeaveMainLoop(); break;
        default : break;
    }
}

void display_about(void)		//Displaying the first page
{
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(150.0,275.0,0.0,"CG MINI PROJECT ON");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(160,260,0.0,"DIGITAL CANVAS");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(200,200,0,"BY:");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(80,185,0,"JEHAD MOHAMED");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(260,185,0,"4SF16CS060");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(260,170,0,"4SF16CS006");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(80,170,0,"ADITHYA M SUVARNA");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(25,120,0,"SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(165,80,0,"PROJECT GUIDE:");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(150,65,0,"Ms. CHAITRA ACHARYA");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
    drawstring(160,50,0,"ASST. PROFESSOR");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1.0,1.0,1.0);
    drawstring(280,20,0.0,"Right Click for Menu");

    glFlush();
}

void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.7,0.7,0.7,0.0);
    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0.0,400.0,0.0,300.0);
}

// Main Function
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS ); 
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,600);
    glutCreateWindow("Digital Canvas");
    glutDisplayFunc(display_about);
    glutCreateMenu(menucallback);
    glutAddMenuEntry("NEXT",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    init();
    glutMainLoop();
    printf("START");

    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,600);
    glutCreateWindow("Digital Canvas");

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