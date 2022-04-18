#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>//nafi...
//ankita saha
//ankita

unsigned char viewMode = 'd';

//Background skyColor
GLclampf skyColorRed = 0.133;
GLclampf skyColorGreen = 0.585;
GLclampf skyColorBlue = 0.899;

//Cloud color
GLfloat cloudRed=1;
GLfloat cloudGreen=1;
GLfloat cloudBlue=1;


void Sprint( float x, float y, char *st)
{
    int l,i;
    l=strlen( st );
    glColor3f(0.0,1.0,0.0);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);

    }
}

GLfloat sunRayRotate = 0;

GLfloat sunpositionY=0.8;



//rgb(247,207,33)
GLfloat sunRed = 247;
GLfloat sunGreen = 207;
GLfloat sunBlue = 33;



void drawFilledSun(GLfloat x, GLfloat y, GLdouble radius)
{

    //glColor3ub(253, 184, 19);
    //rgb(250,226,1)
    glColor3ub(sunRed, sunGreen, sunBlue);
    double twicePi = 2.0 * 3.142;
    //drawSunRays(radius,x,y);
    glLoadIdentity();
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= 10000; i++)
    {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
        );
    }
    glEnd(); //END
}

void dayToNightAutoTrans()
{
    //rgb(0,17,97)
    if(skyColorRed == 0 && skyColorGreen == 0.0666 && skyColorBlue == 0.38)
    {
        viewMode = 't';
    }

    if(viewMode=='d')
    {
        skyColorRed-= 0.001;
        skyColorGreen-=0.001;
        skyColorBlue-=0.001;

        cloudRed -= 0.001;
        cloudGreen -= 0.001;
        cloudBlue -= 0.001;

        glClearColor(skyColorRed, skyColorGreen, skyColorBlue,0.0);
        glutPostRedisplay();
        if(skyColorBlue<=0 && skyColorRed<=0 && skyColorGreen<=0)
        {
            viewMode = 'n';
        }
    }
    else
    {


        if(skyColorBlue<=0.899)
        {
            skyColorBlue += 0.001;
            if(skyColorGreen<=0.585)
            {
                skyColorGreen+=0.001;
                if(skyColorRed<=0.133)
                {
                    skyColorRed+=0.001;


                    cloudRed += 0.001;
                    cloudGreen += 0.001;
                    cloudBlue += 0.001;
                }
            }
        }
        else
        {

            viewMode='d';

        }

        glClearColor(skyColorRed, skyColorGreen, skyColorBlue,0.0);
        glutPostRedisplay();
    }
}
float cloudPosition=100;

GLfloat peopleNtext = 0;


void update(int value)
{


//day -> night auto transition
    dayToNightAutoTrans();
//cloud movement management

    if(cloudPosition<-150)
    {
        cloudPosition=100;
    }

    //sun and moon positioning

    if(viewMode=='t' || viewMode=='n')
    {
        sunpositionY = 1.1;
        // turn sun into moon
        sunGreen =207;


        //sunRed,sunGreen,sunBlue=255;

    }

    if(viewMode=='d')
    {
        if(peopleNtext>=0)
        {
            peopleNtext-=1;
        }
    }

    glutTimerFunc(10, update, 0);
}


void myInit (void)
{
    glClearColor(skyColorRed, skyColorGreen, skyColorBlue,0.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0.0, 400.0, -70, 380.0);

}

GLfloat cloudAnimSpeed = 0.3;
void danimateCloud()
{
//Cloud 1

    glPushMatrix();

    glTranslatef(50+cloudPosition, 300, 0);

    glBegin(GL_POLYGON);

    glColor3f(cloudRed, cloudGreen, cloudBlue);

    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(35+cloudPosition, 280, 0);

    glBegin(GL_POLYGON);
    glColor3f(cloudRed, cloudGreen, cloudBlue);


    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=25;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }

    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(55+cloudPosition, 280, 0);

    glBegin(GL_POLYGON);
    glColor3f(cloudRed, cloudGreen, cloudBlue);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(40+cloudPosition, 260, 0);

    glBegin(GL_POLYGON);
    glColor3f(cloudRed, cloudGreen, cloudBlue);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();

//cloud 2
    glPushMatrix();
    glTranslatef(350+cloudPosition, 100, 0);
    glPushMatrix();
    glTranslatef(-150+cloudPosition, 180, 0);

    glBegin(GL_POLYGON);
    glColor3f(cloudRed, cloudGreen, cloudBlue);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(-140+cloudPosition, 160, 0);

    glBegin(GL_POLYGON);
    glColor3f(cloudRed, cloudGreen, cloudBlue);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(-120+cloudPosition, 180, 0);

    glBegin(GL_POLYGON);
    glColor3f(cloudRed, cloudGreen, cloudBlue);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(-135+cloudPosition, 200, 0);

    glBegin(GL_POLYGON);
    glColor3f(cloudRed, cloudGreen, cloudBlue);

    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    cloudPosition-=cloudAnimSpeed;
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    drawFilledSun(0,sunpositionY,0.1);
    glPopMatrix();
    sunpositionY-=0.002;
    sunGreen-=0.3;

//clouds here
    danimateCloud();
glPushMatrix();

    glPushMatrix();
    glTranslatef(310+peopleNtext, 33, 0);

    glBegin(GL_POLYGON);
    glColor3ub(225, 227, 104);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A)*3;
        glVertex2f(x,y );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(209, 30, 17);
    glVertex2i (-1, -10);
    glVertex2i (-2, -16);
    glVertex2i (2, -16);
    glVertex2i (1, -10);


//dress

    glColor3f(1.0, 0.0, 1.0);
    glVertex2i (-6, -16);
    glVertex2i (-8, -22);
    glVertex2i (8, -22);
    glVertex2i (6, -16);

    glVertex2i (-4, -22);
    glVertex2i (-5, -32);
    glVertex2i (5, -32);
    glVertex2i (4, -22);

    glColor3ub(23, 18, 3);
    glVertex2i (-3, -33);
    glVertex2i (-3, -80);
    glVertex2i (-1, -80);
    glVertex2i (-1, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-1, -80);
    glVertex2i (-2, -83);
    glVertex2i (-4, -83);
    glVertex2i (-3, -80);

    glColor3ub(23, 18, 3);
    glVertex2i (1, -33);
    glVertex2i (1, -80);
    glVertex2i (3, -80);
    glVertex2i (3, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (1, -80);
    glVertex2i (2, -83);
    glVertex2i (4, -83);
    glVertex2i (3, -80);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2i (-4, 7);
    glVertex2i (-4, 0);
    glVertex2i (4, 0);
    glVertex2i (4, 7);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-2, 13);
    glVertex2i (-4, 7);
    glVertex2i (4, 7);
    glVertex2i (2, 13);


//ear


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-4, 0);
    glVertex2i (-4, -5);
    glVertex2i (-3, -5);
    glVertex2i (-3, 0);

    glVertex2i (4, 0);
    glVertex2i (4, -5);
    glVertex2i (3, -5);
    glVertex2i (3, 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);

    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=1.2;
        float x = r * cos(A);
        float y = r * sin(A)*2;
        glVertex2f(x,y+3 );
    }
    glEnd();


    glPopMatrix();


// Figure 2
    glPushMatrix();
    glTranslatef(330+peopleNtext, 33, 0);

    glBegin(GL_POLYGON);
    glColor3ub(225, 227, 104);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A)*3;
        glVertex2f(x,y );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(209, 30, 17);
    glVertex2i (-1, -10);
    glVertex2i (-2, -16);
    glVertex2i (2, -16);
    glVertex2i (1, -10);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2i (-6, -16);
    glVertex2i (-8, -22);
    glVertex2i (8, -22);
    glVertex2i (6, -16);

    glVertex2i (-4, -22);
    glVertex2i (-5, -32);
    glVertex2i (5, -32);
    glVertex2i (4, -22);

    glColor3ub(23, 18, 3);
    glVertex2i (-3, -33);
    glVertex2i (-3, -80);
    glVertex2i (-1, -80);
    glVertex2i (-1, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-1, -80);
    glVertex2i (-2, -83);
    glVertex2i (-4, -83);
    glVertex2i (-3, -80);

    glColor3ub(23, 18, 3);
    glVertex2i (1, -33);
    glVertex2i (1, -80);
    glVertex2i (3, -80);
    glVertex2i (3, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (1, -80);
    glVertex2i (2, -83);
    glVertex2i (4, -83);
    glVertex2i (3, -80);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2i (-4, 7);
    glVertex2i (-4, 0);
    glVertex2i (4, 0);
    glVertex2i (4, 7);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-2, 13);
    glVertex2i (-4, 7);
    glVertex2i (4, 7);
    glVertex2i (2, 13);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-4, 0);
    glVertex2i (-4, -5);
    glVertex2i (-3, -5);
    glVertex2i (-3, 0);

    glVertex2i (4, 0);
    glVertex2i (4, -5);
    glVertex2i (3, -5);
    glVertex2i (3, 0);

    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);


    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=1.2;
        float x = r * cos(A);
        float y = r * sin(A)*2;
        glVertex2f(x,y+3 );
    }
    glEnd();

    glPopMatrix();


// Figure 3
    glPushMatrix();
    glTranslatef(350+peopleNtext, 33, 0);

    glBegin(GL_POLYGON);
    glColor3ub(225, 227, 104);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A)*3;
        glVertex2f(x,y);
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(209, 30, 17);
    glVertex2i (-1, -10);
    glVertex2i (-2, -16);
    glVertex2i (2, -16);
    glVertex2i (1, -10);

    glColor3f(1.0, 0.1, 0.0);
    glVertex2i (-6, -16);
    glVertex2i (-8, -22);
    glVertex2i (8, -22);
    glVertex2i (6, -16);

    glVertex2i (-4, -22);
    glVertex2i (-5, -32);
    glVertex2i (5, -32);
    glVertex2i (4, -22);

    glColor3ub(23, 18, 3);
    glVertex2i (-3, -33);
    glVertex2i (-3, -80);
    glVertex2i (-1, -80);
    glVertex2i (-1, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-1, -80);
    glVertex2i (-2, -83);
    glVertex2i (-4, -83);
    glVertex2i (-3, -80);

    glColor3ub(23, 18, 3);
    glVertex2i (1, -33);
    glVertex2i (1, -80);
    glVertex2i (3, -80);
    glVertex2i (3, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (1, -80);
    glVertex2i (2, -83);
    glVertex2i (4, -83);
    glVertex2i (3, -80);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2i (-4, 7);
    glVertex2i (-4, 0);
    glVertex2i (4, 0);
    glVertex2i (4, 7);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-2, 13);
    glVertex2i (-4, 7);
    glVertex2i (4, 7);
    glVertex2i (2, 13);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-4, 0);
    glVertex2i (-4, -5);
    glVertex2i (-3, -5);
    glVertex2i (-3, 0);

    glVertex2i (4, 0);
    glVertex2i (4, -5);
    glVertex2i (3, -5);
    glVertex2i (3, 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);


    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=1.2;
        float x = r * cos(A);
        float y = r * sin(A)*2;
        glVertex2f(x,y+3 );
    }
    glEnd();

    glPopMatrix();




// Figure 4

    glPushMatrix();
    glTranslatef(370+peopleNtext, 33, 0);

    glBegin(GL_POLYGON);
    glColor3ub(225, 227, 104);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A)*3;
        glVertex2f(x,y );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(209, 30, 17);
    glVertex2i (-1, -10);
    glVertex2i (-2, -16);
    glVertex2i (2, -16);
    glVertex2i (1, -10);

    glColor3f(1.1, 1.1, 1.1);
    glVertex2i (-6, -16);
    glVertex2i (-8, -22);
    glVertex2i (8, -22);
    glVertex2i (6, -16);

    glVertex2i (-4, -22);
    glVertex2i (-5, -32);
    glVertex2i (5, -32);
    glVertex2i (4, -22);

    glColor3ub(23, 18, 3);
    glVertex2i (-3, -33);
    glVertex2i (-3, -80);
    glVertex2i (-1, -80);
    glVertex2i (-1, -33);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2i (-1, -80);
    glVertex2i (-2, -83);
    glVertex2i (-4, -83);
    glVertex2i (-3, -80);

    glColor3ub(23, 18, 3);
    glVertex2i (1, -33);
    glVertex2i (1, -80);
    glVertex2i (3, -80);
    glVertex2i (3, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (1, -80);
    glVertex2i (2, -83);
    glVertex2i (4, -83);
    glVertex2i (3, -80);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2i (-4, 7);
    glVertex2i (-4, 0);
    glVertex2i (4, 0);
    glVertex2i (4, 7);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-2, 13);
    glVertex2i (-4, 7);
    glVertex2i (4, 7);
    glVertex2i (2, 13);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-4, 0);
    glVertex2i (-4, -5);
    glVertex2i (-3, -5);
    glVertex2i (-3, 0);

    glVertex2i (4, 0);
    glVertex2i (4, -5);
    glVertex2i (3, -5);
    glVertex2i (3, 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);


    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=1.2;
        float x = r * cos(A);
        float y = r * sin(A)*2;
        glVertex2f(x,y+3 );
    }
    glEnd();

    glPopMatrix();


// Figure 5

    glPushMatrix();
    glTranslatef(290+peopleNtext, 33, 0);

    glBegin(GL_POLYGON);
    glColor3ub(225, 227, 104);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A)*3;
        glVertex2f(x,y );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(209, 30, 17);
    glVertex2i (-1, -10);
    glVertex2i (-2, -16);
    glVertex2i (2, -16);
    glVertex2i (1, -10);

    glColor3f(1.0, 1.0, 0.0);
    glVertex2i (-6, -16);
    glVertex2i (-8, -22);
    glVertex2i (8, -22);
    glVertex2i (6, -16);

    glVertex2i (-4, -22);
    glVertex2i (-5, -32);
    glVertex2i (5, -32);
    glVertex2i (4, -22);

    glColor3ub(23, 18, 3);
    glVertex2i (-3, -33);
    glVertex2i (-3, -80);
    glVertex2i (-1, -80);
    glVertex2i (-1, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-1, -80);
    glVertex2i (-2, -83);
    glVertex2i (-4, -83);
    glVertex2i (-3, -80);

    glColor3ub(23, 18, 3);
    glVertex2i (1, -33);
    glVertex2i (1, -80);
    glVertex2i (3, -80);
    glVertex2i (3, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (1, -80);
    glVertex2i (2, -83);
    glVertex2i (4, -83);
    glVertex2i (3, -80);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2i (-4, 7);
    glVertex2i (-4, 0);
    glVertex2i (4, 0);
    glVertex2i (4, 7);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-2, 13);
    glVertex2i (-4, 7);
    glVertex2i (4, 7);
    glVertex2i (2, 13);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-4, 0);
    glVertex2i (-4, -5);
    glVertex2i (-3, -5);
    glVertex2i (-3, 0);

    glVertex2i (4, 0);
    glVertex2i (4, -5);
    glVertex2i (3, -5);
    glVertex2i (3, 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);


    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=1.2;
        float x = r * cos(A);
        float y = r * sin(A)*2;
        glVertex2f(x,y+3 );
    }
    glEnd();

    glPopMatrix();


// Figure 6

    glPushMatrix();
    glTranslatef(270+peopleNtext, 33, 0);

    glBegin(GL_POLYGON);
    glColor3ub(225, 227, 104);


    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A)*3;
        glVertex2f(x,y );
    }
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(209, 30, 17);
    glVertex2i (-1, -10);
    glVertex2i (-2, -16);
    glVertex2i (2, -16);
    glVertex2i (1, -10);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2i (-6, -16);
    glVertex2i (-8, -22);
    glVertex2i (8, -22);
    glVertex2i (6, -16);

    glVertex2i (-4, -22);
    glVertex2i (-5, -32);
    glVertex2i (5, -32);
    glVertex2i (4, -22);

    glColor3ub(23, 18, 3);
    glVertex2i (-3, -33);
    glVertex2i (-3, -80);
    glVertex2i (-1, -80);
    glVertex2i (-1, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-1, -80);
    glVertex2i (-2, -83);
    glVertex2i (-4, -83);
    glVertex2i (-3, -80);

    glColor3ub(23, 18, 3);
    glVertex2i (1, -33);
    glVertex2i (1, -80);
    glVertex2i (3, -80);
    glVertex2i (3, -33);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (1, -80);
    glVertex2i (2, -83);
    glVertex2i (4, -83);
    glVertex2i (3, -80);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2i (-4, 7);
    glVertex2i (-4, 0);
    glVertex2i (4, 0);
    glVertex2i (4, 7);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-2, 13);
    glVertex2i (-4, 7);
    glVertex2i (4, 7);
    glVertex2i (2, 13);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i (-4, 0);
    glVertex2i (-4, -5);
    glVertex2i (-3, -5);
    glVertex2i (-3, 0);

    glVertex2i (4, 0);
    glVertex2i (4, -5);
    glVertex2i (3, -5);
    glVertex2i (3, 0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);


    for(int i=0; i<50; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=1.2;
        float x = r * cos(A);
        float y = r * sin(A)*2;
        glVertex2f(x,y+3 );
    }
    glEnd();

    glPopMatrix();


// Text
    glColor3ub(222, 13, 0);
    glBegin(GL_QUADS);
    glVertex2i(260+peopleNtext, -40);
    glVertex2i(260+peopleNtext, 10);
    glVertex2i(380+peopleNtext, 10);
    glVertex2i(380+peopleNtext, -40);
    glEnd();


    glPushMatrix();
    glTranslatef(30+peopleNtext, 180, 0);
    Sprint(240,-190,text);
    Sprint(240,-210,text2);
    glPopMatrix();

 if(viewMode=='t' || viewMode == 'n')
    {
        if(peopleNtext<=200)
        {
            peopleNtext+=1;
        }
    }
    glFlush();

    glPopMatrix();
    glFlush();
}

// declare mouse function>
void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        //mouse clicked left
        cloudAnimSpeed+=0.1;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        //mouse clicked right
        cloudAnimSpeed-=0.1;
    }
    glutPostRedisplay();

}
int main (int argc, char **argv)
{

    glutInit (&argc, argv);
    glutInitWindowSize (1920, 1080);
    glutCreateWindow ("National Memorial");

    //Display,mouse function
    glutDisplayFunc (myDisplay);
    glutMouseFunc(handleMouse);

    glutTimerFunc(25,update,0);

    myInit();
    glutMainLoop();


    return 0;
}
