

float train_x =-700;
void train_animation()
{

    train_x +=0.5;
    if(train_x >=1000)
        train_x = -1500;
    glutPostRedisplay();
}
void train_line()
{
    for(int i=-50; i<=-30; i+=20)
    {
        glPushMatrix();
        glTranslatef(0,0,i);
        glScalef(2000,5,2);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
    }
    //bars
    for(int i=-1000; i<=1000; i+=10)
    {
        glPushMatrix();
        glTranslatef(i,0,-40);
        glScalef(5,2,30);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0.4,0.4);
        glPopMatrix();
    }

}
void train_room()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,11);

    glPushMatrix();
    glTranslatef(0,30,0);
    glScalef(100,50,20);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(0,55,0);
    glScalef(100,1,20);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,30,0);
    glScalef(1,50,20);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();


    for(int l=-1; l<=1; l+=2)
    {
        for(int j=-1; j<=1; j+=2)
        {
            glPushMatrix();
            material_property(0,0,0);
            glTranslatef(l*(100/2-10),10,j*10);
            glScalef(1,1,0.005);
            glutSolidTorus(5,5,16,16);
            glPopMatrix();
        }
    }
}
void train()
{
    train_line();

    glPushMatrix();
    glTranslatef(train_x,0,-40);

    for(int i=-600; i<=0; i+=110)
    {

        glPushMatrix();
        glTranslatef(i-50,30,0);
        glScalef(20,1,2);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0.5,0.2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(i,0,0);
        train_room();
        glPopMatrix();

    }
    train_animation();
    glPopMatrix();
}
