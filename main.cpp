#include "header.h"

const int window_width = 1200;
const int window_height = 750;

GLfloat eye[] = {-120,200,110};
GLfloat look[] = {-120,200,-1000};

int rot = 0;
bool light_on = false;

unsigned int ID;
#define GL_CLAMP_TO_EDGE 0x812F




void LoadTexture(const char*filename, int rep = 1)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if(rep)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }

    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


void _light()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 50.0, 0, 1.0 };

    glEnable( GL_LIGHT7);
    if(light_on)
    {

        glLightfv( GL_LIGHT7, GL_AMBIENT, light_ambient);
        glLightfv( GL_LIGHT7, GL_DIFFUSE, light_diffuse);
        glLightfv( GL_LIGHT7, GL_SPECULAR, light_specular);
    }
    else
    {
        glLightfv( GL_LIGHT7, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT7, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT7, GL_SPECULAR, no_light);
    }
    glLightfv( GL_LIGHT7, GL_POSITION, light_position);

}

void axes()
{
    float length = 10;
    float width = 0.3;

    // X-axis
    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,width,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,0,0); //RED Line
    glPopMatrix();

    // Y-axis
    glPushMatrix();
    glTranslatef(0,length/2,0);
    glScalef(width,length,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0,1,0); //GREEN Line
    glPopMatrix();

    // Z-axis
    glPushMatrix();
    glTranslatef(0,0,length/2);
    glScalef(width,width,length);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0,0,1); //BLUE Line
    glPopMatrix();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    //for light
    case '1':
        light_on = !light_on;
        break;

    case 't':

        eye[1]++;
        look[1]++;

        break;
    case 'g':

        eye[1]--;
        look[1]--;
        break;
    case 'h':
        look[0]++;
        break;
    case 'f':
        look[0]--;
        break;

    case 'e':
        rot--;
        break;
    case 'r':
        rot++;
        break;
    case 'l':

        eye[0]++;
        look[0]++;

        break;
    case 'j':

        eye[0]--;
        look[0]--;

        break;
    case '+':
        eye[2]--;
        break;
    case 'i':

        eye[2]--;

        break;
    case '-':
        eye[2]++;
        break;
    case 'k':

        eye[2]++;

        break;
    }

    glutPostRedisplay();
}


static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int limx = 8;
    int limy = 6;
    glFrustum(-limx, limx, -limy, limy, 4, 2000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

    gluLookAt(eye[0],eye[1],eye[2], look[0],look[1],look[2], 0,1,0);
    //glViewport(0, 0, window_width, window_height);

    glRotatef(rot, 0,1,0);


    //axes();
    _light();
    floor();
    buiding();
    helicopter();
    car_move();
    train();




    glFlush();
    glutSwapBuffers();
}

string getexepath()
{
    char result[ MAX_PATH ];
    return string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(window_width,window_height);
    glutInitWindowPosition(300,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("city_view-1607045");


    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\helipad.bmp",1);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\shade.bmp",2);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\shade2.bmp",3);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\building1.bmp",4);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\building2.bmp",5);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\building3.bmp",6);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\building4.bmp",7);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\road.bmp",8);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\road1.bmp",9);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\sky.bmp",10);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\train.bmp",11);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\floor.bmp",12);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\mango.bmp",13);
    LoadTexture("C:\\Users\\Admin\\Desktop\\1607045_saikan\\images\\stone_flr.bmp",14);

    glutDisplayFunc(display);
    glutKeyboardFunc(key);

    //_light();
    glShadeModel( GL_SMOOTH );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glutMainLoop();

}
