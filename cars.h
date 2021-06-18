float carx=-300, carz=-90;
bool car_switch=true;


void car()
{
    glPushMatrix();
    glTranslatef(carx,0,carz);
    //upper part
    glPushMatrix();
    glTranslatef(-7.5,10.5,0);
    glScalef(15,10,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    //base
    glPushMatrix();
    glTranslatef(0,8,0);
    glScalef(25,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.3,0.4);
    glPopMatrix();

    //gate
    for(int i=-10; i<=-4; i+=6)
    {
        for(float j=-2.5; j<=2.5; j+=5)
        {
            glPushMatrix();
            glTranslatef(i,12,j);
            glScalef(5,6,1);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.2,0.2,0.2);
            glPopMatrix();
        }
    }



    //wheel
    for(int i=-1; i<=1; i+=2)
    {
        for(int j=-1; j<=1; j+=2)
        {
            glPushMatrix();
            material_property(0.2,0.2,0.2);
            glTranslatef(j*9,4,i*2);
            glutSolidTorus(1,3,16,16);
            glPopMatrix();
        }
    }
    glPopMatrix();
}




void car_animation()
{
    if(carx<=300)
    {

        carx +=0.05;
    }
    if(carx>=300)
    {
        carx = -300;

    }

    glutPostRedisplay();

}
void car_move()
{
    for(int i=1; i<=400; i+=100)
    {
        glPushMatrix();
        glTranslatef(carx+i,0,0);
        car();
        if (car_switch)
        {

            car_animation();
        }
        glPopMatrix();
    }

}
