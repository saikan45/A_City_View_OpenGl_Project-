



/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>


using namespace std;

const double PI = 3.14159265389;


/* GLUT callback Handlers */


int anglex= 0, angley = 0, anglez = 0;          //rotation angles
int window;
int wired=0;
int shcpt=1;
int animat = 0;
const int L=20;
const int dgre=3;
int ncpt=L+1;
int clikd=0;
const int nt = 40;				//number of slices along x-direction
const int ntheta = 20;


GLfloat ctrlpoints[L+1][3] =
{
//    { 0.0, 0.0, 0.0}, { -0.3, 0.5, 0.0},
//    { 0.1, 1.7, 0.0},{ 0.5, 1.5, 0.0},
//    {1.0, 1.5, 0.0}, {1.4, 1.4, 0.0},
//    {1.8, 0.4, 0.0},{2.2, 0.4, 0.0},
//    {2.6, 1.5, 0.0}, {3.0, 1.4, 0.0},
//    {3.4, 1.4, 0.0},{3.8, 1.4, 0.0},
//    {4.2, 1.0, 0.0},{4.6, 1.0, 0.0},
//    {5.0, 1.0, 0.0},{5.4, 1.0, 0.0},
//    {5.8, 0.5, 0.0},{6.2, 0.5, 0.0},
//    {6.6, 0.5, 0.0},{7.2, 0.2, 0.0},
//    {6.8, 0.52, 0.0}

//{6.325,5,0},
//{5.875,4.275,0},
//{5.55,3.8,0},
//{5.5,3,0},
//{5.95,1.725,0},
//{6.525,0.95,0},
//{6.475,-0.6,0},
//{6.05,-1.525,0},
//{5.525,-2.3,0},
//{5.625,-2.95,0},
//{6.125,-3.625,0},
//{5.675,-3.675,0},
//{4.575,-3.55,0},
//{3.425,-3.525,0},
//{2.55,-3.35,0},
//{2.825,-1.65,0},
//{2.9,-1.225,0},
//{2.4,-0.2,0},
//{2.05,1.45,0},
//{2.725,2.65,0},
//{3,3.55,0}
//
//{7.375,2.75,0},
//{6.975,2.375,0},
//{6.6,1.9,0},
//{6.325,1.7,0},
//{5.9,1.525,0},
//{5.35,1.475,0},
//{4.775,1.525,0},
//{4.25,1.675,0},
//{3.675,1.9,0},
//{3.1,2.325,0},
//{2.6,2.775,0},
//{2.075,2.75,0},
//{1.95,1.725,0},
//{1.95,0.625,0},
//{1.95,-0.1,0},
//{2.05,-1.5,0},
//{3.1,-1.7,0},
//{3.35,-1,0},
//{4.25,-0.15,0},
//{5.35,-0.575,0},
//{6.4,-1.45,0},

//{7.75,5.3,0},
//{7.25,4.475,0},
//{6.475,3.225,0},
//{6.15,2.325,0},
//{6.125,0.725,0},
//{6.025,-0.05,0},
//{5.45,-0.2,0},
//{4.7,1.025,0},
//{4.05,1.85,0},
//{3.325,1.5,0},
//{2.975,0.2,0},
//{3.1,-1.4,0},
//{4.075,-2.15,0},
//{5.175,-3.4,0},
//{6.1,-4.475,0},
//{7.4,-5.725,0},
//{8,-5.7,0},
//{7.975,-4.85,0},
//{7.45,-2.9,0},
//{7.325,-1.125,0},
//{7.7,4.85,0},

{8.4,1.825,0},
{7.85,2.65,0},
{7.325,3.3,0},
{6.975,3.675,0},
{6.775,3.375,0},
{6.5,2.775,0},
{6.175,1.85,0},
{6.025,1.4,0},
{5.875,1.075,0},
{5.35,1.05,0},
{4.55,1.05,0},
{3.85,1.025,0},
{3.675,0.2,0},
{3.65,-0.575,0},
{4.4,-0.55,0},
{5.4,-0.375,0},
{5.875,-1.375,0},
{6.475,-2.175,0},
{7.45,-2.325,0},
{7.925,-2.125,0},
{7.925,-0.0999999,0},

};


double ex=0, ey=0, ez=15, lx=0,ly=0,lz=0, hx=0,hy=1,hz=0;

float wcsClkDn[3],wcsClkUp[3];
///////////////////////////////
class point1
{
public:
    point1()
    {
        x=0;
        y=0;
    }
    int x;
    int y;
} clkpt[2];
int flag=0;
GLint viewport[4]; //var to hold the viewport info
GLdouble modelview[16]; //var to hold the modelview info
GLdouble projection[16]; //var to hold the projection matrix info

//////////////////////////
void scsToWcs(float sx,float sy, float wcsv[3] );
void processMouse(int button, int state, int x, int y);
void matColor(float kdr, float kdg, float kdb,  float shiny, int frnt_Back=0, float ambFactor=1.0, float specFactor=1.0);
///////////////////////////

void scsToWcs(float sx,float sy, float wcsv[3] )
{

    GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
    GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

    //glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
    glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
    glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info

    winX = sx;
    winY = (float)viewport[3] - (float)sy;
    winZ = 0;

    //get the world coordinates from the screen coordinates
    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
    wcsv[0]=worldX;
    wcsv[1]=worldY;
    wcsv[2]=worldZ;


}
void processMouse(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(flag!=1)
        {
            flag=1;
            clkpt[0].x=x;
            clkpt[0].y=y;
        }


        scsToWcs(clkpt[0].x,clkpt[0].y,wcsClkDn);
        //cout<<"\nD: "<<x<<" "<<y<<" wcs: "<<wcsClkDn[0]<<" "<<wcsClkDn[1];
        cout<<"{"<<wcsClkDn[0]<<","<<wcsClkDn[1]<<",0},"<<endl;
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
        if (flag==1)
        {
            clkpt[1].x=x;
            clkpt[1].y=y;
            flag=0;
        }
        float wcs[3];
        scsToWcs(clkpt[1].x,clkpt[1].y,wcsClkUp);
        //cout<<"\nU: "<<x<<" "<<y<<" wcs: "<<wcsClkUp[0]<<" "<<wcsClkUp[1];

        clikd=!clikd;
    }
}

//control points
long long nCr(int n, int r)
{
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

//polynomial interpretation for N points
void BezierCurve ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints[i][0];
        y+=coef*ctrlpoints[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);

    //return y;
}

///////////////////////
void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(-Nx,-Ny,-Nz);
}

void curvy()
{
    int i, j;
    float x, y, z, r;				//current coordinates
    float x1, y1, z1, r1;			//next coordinates
    float theta;

    const float startx = 0, endx = ctrlpoints[L][0];
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xy[2];
    BezierCurve( t,  xy);
    x = xy[0];
    r = xy[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    for ( i = 0; i < nt; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        BezierCurve( t,  xy);
        x1 = xy[0];
        r1 = xy[1];

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= ntheta; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            //edge from point at x to point at next x
            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }
            glVertex3f (x1, y1, z1);

            //forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } //for i

}




void showControlPoints()
{
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i <=L; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();
}

void tub()
{
    glPushMatrix();
    material_property(0,1,0);
    glRotatef( 90, 0.0, 0.0, 1.0);
    //glTranslated(-3.5,0,0);
    //glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
    glScalef(2,5,2);
    curvy();
    glPopMatrix();
}

