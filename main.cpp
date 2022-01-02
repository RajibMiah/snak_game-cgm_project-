#include <GL/gl.h>
#include <GL/glut.h>
#include "grid.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdlib.h>

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver = false;
int score = 0;


void timer(int);
void display();
void reshape(int,int);
void keyboard(int,int,int);
//background color
void init()
{
   glClearColor(0.0,0.0,0.0,1.0);
   initGrid(COLUMNS,ROWS);
}

int main(int argc, char **argv)
{
   PlaySound(TEXT("sound.wav"),NULL,SND_SYNC);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
   glutInitWindowSize(500,500);
   glutCreateWindow("SNAKE_GAME");
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutTimerFunc(0,timer,0);
   glutSpecialFunc(keyboard);
   init();
   glutMainLoop();
   return 0;
}
int index = 0;
void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
   drawGrid();
   drawSnake();
   drawFood();
   glutSwapBuffers();
   if(gameOver)
   {

       char c_score[10];
       itoa(score, c_score,10);
       char text[50] = "Score: ";
       strcat(text,c_score);
       MessageBox(NULL,text, "GAME OVER",0);
       exit(0);

   }

}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);

}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);

}
void keyboard(int key,int,int)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        if(sDirection != DOWN)
            sDirection = UP;
        break;
        case GLUT_KEY_DOWN:
        if(sDirection != UP)
            sDirection = DOWN;
        break;
        case GLUT_KEY_RIGHT:
        if(sDirection != LEFT)
            sDirection = RIGHT;
        break;
        case GLUT_KEY_LEFT:
        if(sDirection != RIGHT)
            sDirection = LEFT;
        break;
    }

}

