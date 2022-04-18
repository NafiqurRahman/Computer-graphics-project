#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>//propa.............
#include<windows.h>//nafi...

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
        glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(40, 30);
    glVertex2i (180, 62);

    glVertex2i (180, 62);
    glVertex2i (320, 30);

    glVertex2i (320, 30);
    glVertex2i (40, 30);

    glEnd();



//trin 1 main
    glColor3f(0.6, 0.6, 0.6) ;
    glBegin(GL_POLYGON);

    glVertex2i(43, 30);
    glVertex2i (317, 30);

    glVertex2i (317, 30);
    glVertex2i (180, 60);

    glVertex2i (180, 60);
    glVertex2i (43, 30);

    glEnd();



//trn2
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(60, 30);
    glVertex2i (180, 102);

    glVertex2i (180, 102);
    glVertex2i (300, 30);

    glVertex2i (300, 30);
    glVertex2i (60, 30);
    glEnd();


//trn2 main
    glColor3f(0.4, 0.4, 0.4) ;
    glBegin(GL_POLYGON);

    glVertex2i(62, 30);
    glVertex2i (180, 100);

    glVertex2i (180, 100);
    glVertex2i (298, 30);

    glVertex2i (298, 30);
    glVertex2i (62, 30);

    glEnd();


//trn3
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(80, 30);
    glVertex2i (180, 152);

    glVertex2i (180, 152);
    glVertex2i (280, 30);

    glVertex2i (280, 30);
    glVertex2i (80, 30);

    glEnd();



//trn3 main
    glColor3f(0.4, 0.4, 0.4) ;
    glBegin(GL_POLYGON);

    glVertex2i(81, 30);
    glVertex2i (180, 150);

    glVertex2i (180, 150);
    glVertex2i (279, 30);

    glVertex2i (279, 30);
    glVertex2i (81, 30);

    glEnd();



//trn 4
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(100, 30);
    glVertex2i (180, 202);

    glVertex2i (180, 202);
    glVertex2i (260, 30);

    glVertex2i (260, 30);
    glVertex2i (100, 30);

    glEnd();



//trn4 main
    glColor3f(0.4, 0.4, 0.4) ;
    glBegin(GL_POLYGON);

    glVertex2i(101, 30);
    glVertex2i (180, 200);

    glVertex2i (180, 200);
    glVertex2i (259, 30);

    glVertex2i (259, 30);
    glVertex2i (101, 30);

    glEnd();



//trn 5

    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(120, 30);
    glVertex2i (180, 252);

    glVertex2i (180, 252);
    glVertex2i (240, 30);

    glVertex2i (240, 30);
    glVertex2i (120, 30);

    glEnd();



//trn5 main
    glColor3f(0.4, 0.4, 0.4) ;
    glBegin(GL_POLYGON);

    glVertex2i(121, 30);
    glVertex2i (180, 250);

    glVertex2i (180, 250);
    glVertex2i (239, 30);

    glVertex2i (239, 30);
    glVertex2i (121, 30);

    glEnd();



//trn 6
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(140, 30);
    glVertex2i (180, 302);

    glVertex2i (180, 302);
    glVertex2i (220, 30);

    glVertex2i (220, 30);
    glVertex2i (140, 30);

    glEnd();



//trn6 main
    glColor3f(0.4, 0.4, 0.4) ;
    glBegin(GL_POLYGON);

    glVertex2i(141, 30);
    glVertex2i (180, 300);

    glVertex2i (180, 300);
    glVertex2i (219, 30);

    glVertex2i (219, 30);
    glVertex2i (141, 30);

    glEnd();



//trn 7
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(160, 30);
    glVertex2i (180, 351);

    glVertex2i (180, 351);
    glVertex2i (200, 30);

    glVertex2i (200, 30);
    glVertex2i (160, 30);

    glEnd();




//trn7 main
    glColor3f(0.4, 0.4, 0.4) ;
    glBegin(GL_POLYGON);

    glVertex2i(161, 30);
    glVertex2i (180, 350);

    glVertex2i (180, 350);
    glVertex2i (199, 30);

    glVertex2i (199, 30);
    glVertex2i (161, 30);

    glEnd();




//middle line.
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(167, 145);
    glVertex2i (167, 148);

    glVertex2i (167, 148);
    glVertex2i (193, 148);

    glVertex2i (193, 148);
    glVertex2i (193, 145);

    glVertex2i (193, 145);
    glVertex2i (167, 145);

    glEnd();




//under train main
    glColor3f(0.3, 0.3, 0.3) ;
    glBegin(GL_POLYGON);

    glVertex2i(168, 145);
    glVertex2i (180, 91);

    glVertex2i (180, 91);
    glVertex2i (192, 145);

    glVertex2i (192, 145);
    glVertex2i(168, 145);


    glEnd();




//upper train main
    glColor3f(0.3, 0.3, 0.3)  ;
    glBegin(GL_POLYGON);

    glVertex2i(168, 148);
    glVertex2i (180, 197);

    glVertex2i (180, 197);
    glVertex2i (192, 148);

    glVertex2i (192, 148);
    glVertex2i(168, 148);

    glEnd();




//low train
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_POLYGON);

    glVertex2i(160, 30);
    glVertex2i (180, 44);

    glVertex2i (180, 44);
    glVertex2i (200, 30);

    glVertex2i (200, 30);
    glVertex2i(160, 30);

    glEnd();



//low train main
    glColor3f(0.7, 0.3, 0.2) ;
    glBegin(GL_POLYGON);

    glVertex2i(162, 30);
    glVertex2i (180, 42);

    glVertex2i (180, 42);
    glVertex2i (198, 30);

    glVertex2i (198, 30);
    glVertex2i(162, 30);


    glEnd();



//Middle line top to bottom
    glColor3f(1.0, 1.0, 1.0) ;
    glBegin(GL_LINES);

    glVertex2i (180, 44);
    glVertex2i (180, 91);

    glVertex2i (180, 197);
    glVertex2i (180, 350);

    glEnd();
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
