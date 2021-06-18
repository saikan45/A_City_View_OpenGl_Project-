void road_light()
{
    //stand
    glPushMatrix();
    glTranslatef(0,25,0);
    glScalef(1,50,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.3,0.2,0.5);
    glPopMatrix();
    //bar
    glPushMatrix();
    glTranslatef(0,50,0);
    glScalef(1,1,10);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    //bar
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(0,50-2.5,i*4);
        glScalef(1,5,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
    }

    //sphere
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        material_property(1,1,0);
        glTranslatef(0,50-4,i*4);
        glutSolidSphere(2,16,16);
        glPopMatrix();
    }


}

void road()
{

    //1
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);

    glPushMatrix();
    glTranslatef(0,0,-200);
    glScalef(40,1,200);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //road light
    for(int i=-100; i>=-200; i-=50)
    {
        glPushMatrix();
        glTranslatef(0,0,i);
        glRotatef(90,0,1,0);
        road_light();
        glPopMatrix();


    }
    //2
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);

    glPushMatrix();
    glTranslatef(-300,0,-200);
    glScalef(40,1,200);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //road light
    for(int i=-100; i>=-200; i-=50)
    {
        glPushMatrix();
        glTranslatef(-300,0,i);
        glRotatef(90,0,1,0);
        road_light();
        glPopMatrix();
    }


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,9);

    glPushMatrix();
    glTranslatef(50,0,-80);
    glScalef(1500,1,40);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //road light
    for(int i=-600; i<=600; i+=80)
    {
        glPushMatrix();
        glTranslatef(i,0,-80);
        road_light();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(i,-15,-80);
        tub();
        glPopMatrix();

    }

}

void shopping_malls()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,13);

    glPushMatrix();
    glTranslatef(-400,75,-150);
    glScalef(80,150,80);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //2
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

    glPushMatrix();
    glTranslatef(-400,50,-250);
    glScalef(40,100,40);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //3
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);

    glPushMatrix();
    glTranslatef(-400,75,-300);
    glScalef(40,150,40);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
void buiding()
{

    road();
    shopping_malls();


    for(int i=-230; i<=-130; i+=50)
    {
        for(int j=-180; j<=-60; j+=80)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,4);

            glPushMatrix();
            glTranslatef(j,75,i);
            glScalef(40,150,40);
            glTranslatef(-0.5,-0.5,-0.5);
            cube();
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);

            //roof
            glPushMatrix();
            glTranslatef(j,150,i);
            glScalef(40,1,40);
            glTranslatef(-0.5,-0.5,-0.5);
            cube();
            glPopMatrix();
        }


    }
    // building 2
    for(int i=-250; i<=-150; i+=50)
    {
        for(int j=150; j<=310; j+=70)
        {

            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,6);

            glPushMatrix();
            glTranslatef(j,30,i);
            glScalef(40,60,40);
            glTranslatef(-0.5,-0.5,-0.5);
            cube();
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);

            //roof 2
            glPushMatrix();
            glTranslatef(j,60,i);
            glScalef(40,1,40);
            glTranslatef(-0.5,-0.5,-0.5);
            cube();
            glPopMatrix();
        }
    }

}
