float fan_rt = 0,h_rot =0;
float h_pos_x = 1110, h_pos_y = 500, h_pos_z = -1200;
bool h_flagx = true, h_flagy = false, h_flagz = true;
bool h_last_flagx = false, h_last_flagy = false, h_last_flagz = false;
void fan_rotation()
{
    fan_rt = fan_rt+1;
    if(fan_rt>360)
        fan_rt =0;
    glutPostRedisplay();
}


void fan()
{
    float base = 5;

    glPushMatrix();
    glRotatef(fan_rt,0,1,0);

    //fan-cap
    int cap_rot = 0;
    for(int i=0; i<100; i++)
    {
        glPushMatrix();
        glTranslatef(0,base/4,0);
        glRotatef(cap_rot,0,1,0);
        glScalef(base/4,base*2,base/4);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.373, 0.620, 0.627);
        glPopMatrix();
        cap_rot+=5;
    }

    //round-base
    int base_rot = 0;
    for (int i=0; i<100; i++)
    {
        glPushMatrix();
        //glTranslatef(0,top_width-(6*top_height),0);
        glRotatef(base_rot,0,1,0);
        glScalef(base,base/4,base);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.804, 0.361, 0.361);
        glPopMatrix();
        base_rot+=5;
    }
    //fan-leg
    for(int i=0; i<=2; i++)
    {
        glPushMatrix();
        glRotatef(120*i,0,1,0);
        glTranslatef((3*base)+base/2,base/8,0);
        glScalef(6*base,0.002*base,base);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.5, 0.4, 0.545);
        glPopMatrix();
    }

    fan_rotation();
    glPopMatrix();

}

void helipad()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);

    glPushMatrix();
    glTranslatef(60,0,-150);
    glScalef(50,1,50);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
void heli_last_ani(int val)
{
    if(h_last_flagy)
    {
        //cout<<"herte"<<endl;
        h_pos_y +=0.08;
        if(h_rot>0)
            h_rot -=0.1;
        if(h_pos_y>=250)
        {
            h_last_flagy = false;
            h_last_flagx = true;
            h_last_flagz =true;
        }

    }
    if(h_last_flagx)
    {
        h_pos_x -=0.5;
        h_rot -=0.04;
        h_pos_y +=0.01;
        if(h_pos_x<=-700)
            h_last_flagx = false;

    }
    if(h_last_flagz)
    {
        h_pos_z -=0.1;
        h_pos_y +=0.01;
        if(h_pos_z<=-1500)
            h_last_flagz = false;

    }

    glutPostRedisplay();
}
void next_ani(int val)
{
    h_last_flagy = true;
}
void heli_animation()
{
    if(h_flagx)
    {
        h_pos_x -=0.5;
        h_pos_y -=0.1;
        if(h_pos_x<=60)
        {
            h_flagx = false;
            h_flagy = true;

        }

    }
    if(h_flagz)
    {
        h_pos_z +=0.5;
        h_pos_y -=0.1;
        if(h_rot<=90)
            h_rot +=0.05;
        if(h_pos_z>=-150)
            h_flagz = false;
    }
    if(h_flagy)
    {

        if(h_pos_y>20)
        {
            h_pos_y -=0.05;

        }
        if(h_pos_y<=20)
        {
            glutTimerFunc(4000,next_ani,1);
            //h_last_flagy = true;
            h_flagy = false;
        }

    }

    glutPostRedisplay();
}
void helicopter()
{
    helipad();

    glPushMatrix();

    glTranslatef(h_pos_x,h_pos_y,h_pos_z);
    glRotatef(h_rot,0,1,0);


    glPushMatrix();
    material_property(0.5,0.7,0.7);
    glScalef(2,1,1);
    glutSolidSphere(10,16,16);
    glPopMatrix();

    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

    glPushMatrix();
    material_property(1,1,1);
    glTranslatef(5,2,0);
    glScalef(2,1,1);
    glutSolidSphere(10,16,16);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glDisable(GL_TEXTURE_GEN_T);


    //door
    glPushMatrix();
    glTranslatef(0,0,9.5);
    glScalef(5,10,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.2,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2,10.5);
    glScalef(3,3,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    //back pipe
    glPushMatrix();
    glTranslatef(40,0,0);
    glScalef(40,2,2);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,5,0);
    glScalef(2,10,2);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0,0);
    glPopMatrix();

    //supporter
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*5,-10,0);
        glScalef(2,1,20);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0,0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,-20,i*10);
        glScalef(20,1,2);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0.5,0);
        glPopMatrix();
        for(int j=-1; j<=1; j+=2)
        {
            glPushMatrix();
            glTranslatef(i*5,-15,j*9);
            glScalef(2,10,2);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0.5,0.5);
            glPopMatrix();
        }

    }


    //uper fan
    glPushMatrix();
    glTranslatef(0,20,0);
    glRotatef(180,1,0,0);
    fan();
    glPopMatrix();

    //back fan
    glPushMatrix();
    glTranslatef(50,0,3);
    glRotatef(90,-1,0,0);
    glScalef(0.3,0.3,0.3);
    fan();
    glPopMatrix();

    heli_animation();
    heli_last_ani(1);
    glPopMatrix();
}
