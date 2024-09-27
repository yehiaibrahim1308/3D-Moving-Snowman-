
#include<iostream>
using namespace std;

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
#include<utility>

#include<string>

int delay = 1000 / 75;
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
double shiftXaxis = 0.0;
double shiftZaxis = 0.0;

double shiftCubeX = 0.0;
double shiftCubeZ = 0.0;

double moveSpeed = 0.01;
double snowManMove = 0;

float eyeX = 0;
float eyeY = -0.2;
float eyeZ = -0.5;
float upX = 0;
float upY = 1;
float upZ = 0;

float shiftworldX = 0;
float shiftworldY = 0;
float shiftworldZ = 0;




void color(float R, float G, float B) {
    glColor3f(1.0f*R/255.0, 1.0f*G/255.0, 1.0f*B/255.0);
}

void reshapeFunc(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(0, -1, -1);
    glRotatef(-30, 1, 0, 0);
    gluPerspective(60.0, 2, 1, 50.0);
    glMatrixMode(GL_MODELVIEW);
}


void MyInit(){
    glClearColor(0,0.07,0.05,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Perspective Projection
    glFrustum(-1 , 1 , -1 , 1 , 2 , 10);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,0,0);
}
float angle=0;
void square() {
    glRotatef(angle,1,1,0);
    glPushMatrix();
    glBegin(GL_QUADS);
    //front
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    //back
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    //right
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //left
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    //top
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //bottom
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}
void triangle(){
glPushMatrix ();
glBegin(GL_QUADS);
//front
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,2.0,3.0);
    glVertex3f(0.0,-2.0,3.0);
    glVertex3f(1.0,2.0,3.0);
    glVertex3f(1.0,2.0,3.0);
//right
    glColor3f(1.0,0.0,0.0);
    glVertex3f(1.0,2.0,3.0);
    glVertex3f(0.0,-2.0,3.0);
    glVertex3f(-1,2.0,1.0);
    glVertex3f(-1,2.0,1.0);
    //left
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-1.0,2.0,3.0);
    glVertex3f(0.0,-2.0,3.0);
    glVertex3f(-1,2.0,1.0);
    glVertex3f(-1,2.0,1.0);
    //base
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-1.0,2.0,3.0);
    glVertex3f(1.0,2.0,3.0);
    glVertex3f(-1,2.0,1.0);
    glVertex3f(-1,2.0,1.0);
glEnd ();
glPopMatrix();

}

void snowManAnimate() {
    glPopMatrix();
//lower body
    glPushMatrix();
         glColor3f(1,0,1);
    glTranslated(0+ snowManMove, 0.7, -10);

    glutSolidCube(1);
    glPopMatrix();
//chest

    glPushMatrix();
     glColor3f(1,0,0);
    glTranslated(0 + snowManMove, 1.7, -10 );
    glutSolidCube(1);
    glPopMatrix();
//head//
    glPushMatrix();
     glColor3f(0,0,1);
    glTranslated(0 + snowManMove, 2.5, -10 );
    glutSolidCube(0.6);
    glPopMatrix();
//right eye
    glPushMatrix();
    color(0, 0, 0);
    glTranslated(0.2+ snowManMove, 2.5, -9.7);
   glutSolidSphere(0.08, 20, 20);
    glPopMatrix();
//left eye
    glPushMatrix();
    glTranslated(-0.2 +snowManMove, 2.5, -9.7 );
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();
//nose
    glPushMatrix();
    glTranslated(0.01 + snowManMove, 2.4, -9.6 );
    color(245, 127, 59);
    glutSolidCone(0.08,0.2,10,10);
    glPopMatrix();
//right hand
    glPushMatrix();
    glTranslated(0.5 + snowManMove, 1.8, -10 );
    color(0, 0, 0);
     glRotatef(300, 1, 0, 0);
    glutSolidCone(0.08,1.7,10,10);
    glPopMatrix();
//left hand
    glPushMatrix();
    glTranslated(-0.5 + snowManMove, 1.8, -10 );
    color(0, 0, 0);
    glRotatef(300, 1, 1, 0);
    glutSolidCone(0.08, 1.7, 10, 10);
    glPopMatrix();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(shiftworldX, shiftworldY, shiftworldZ);
    glPushMatrix();
//floor
    glTranslatef(0.0, -2, 0.0);
    glColor3f(0.0,1.0,0.0);
    glScalef(50, 0.5, 50);
    glutSolidCube(0.6);

    glPopMatrix();

//lower body
    glPushMatrix();
         glColor3f(1,0,1);
    glTranslated(0+ shiftXaxis, 0.7, -10+ shiftZaxis);

    glutSolidCube(1);
    glPopMatrix();
//chest

    glPushMatrix();
     glColor3f(1,0,0);
    glTranslated(0 + shiftXaxis, 1.7, -10 + shiftZaxis);
    glutSolidCube(1);
    glPopMatrix();
//head//
    glPushMatrix();
     glColor3f(0,0,1);
    glTranslated(0 + shiftXaxis, 2.5, -10 + shiftZaxis);
    glutSolidCube(0.6);
    glPopMatrix();
//right eye
    glPushMatrix();
    color(0, 0, 0);
    glTranslated(0.2+ shiftXaxis, 2.5, -9.7+ shiftZaxis);
   glutSolidSphere(0.08, 20, 20);
    glPopMatrix();
//left eye
    glPushMatrix();
    glTranslated(-0.2 + shiftXaxis, 2.5, -9.7 + shiftZaxis);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();
//nose
    glPushMatrix();
    glTranslated(0.01 + shiftXaxis, 2.4, -9.6 + shiftZaxis);
    color(245, 127, 59);
    glutSolidCone(0.08,0.2,10,10);
    glPopMatrix();
//right hand
    glPushMatrix();
    glTranslated(0.5 + shiftXaxis, 1.8, -10 + shiftZaxis);
    color(0, 0, 0);
     glRotatef(300, 1,0 , 0);
    glutSolidCone(0.08,1.7,10,10);
    glPopMatrix();
//left hand
    glPushMatrix();
    glTranslated(-0.5 + shiftXaxis, 1.8, -10 + shiftZaxis);
    color(0, 0, 0);
    glRotatef(300, 1, 1, 0);
    glutSolidCone(0.08, 1.7, 10, 10);
    glPopMatrix();

    snowManAnimate();


    triangle();
    square();
    glutSwapBuffers();

}

void idleFunc(void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(delay, timer, 0);


    snowManMove += moveSpeed;
    if (snowManMove > 5 || snowManMove < -5) {
        moveSpeed = -moveSpeed;
    }
    angle =angle+1;
    if(angle<360){
        angle=angle-360;
    }

}
void normalinput(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
       shiftworldZ  ++;
        break;
    case 's':
        shiftworldZ --;
        break;
    case 'd':
        shiftworldX--;
        break;
    case 'a':
        shiftworldX++;
        break;
    case 'q':
        shiftworldY--;
        break;
    case 'e':
        shiftworldY++;
        break;
    }
}
void specialinput(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        shiftXaxis --;
        break;
    case GLUT_KEY_RIGHT:
        shiftXaxis ++;
        break;
    case GLUT_KEY_UP:
        shiftZaxis--;
        break;

    case GLUT_KEY_DOWN:
        shiftZaxis++;
        break;
    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(700, 200);
    glutCreateWindow("Ahmed  Abed 20103379 ");
    glClearColor(1.0, 1.0, 1.0, 0.0);

    MyInit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    glutKeyboardFunc(normalinput);
    glutSpecialFunc(specialinput);
    glutIdleFunc(idleFunc);
    glutTimerFunc(0, timer, 0);

    glClearColor(0, 0.7, 1, 1.0);


    glutMainLoop();

}

