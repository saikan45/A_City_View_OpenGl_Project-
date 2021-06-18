

void floor()
{
    //left
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,14);

    glPushMatrix();
    glTranslatef(-420,0,-200);
    glScalef(200,1,200);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //middle
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,12);

    glPushMatrix();
    glTranslatef(-150,0,-200);
    glScalef(260,1,200);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //right
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,12);

    glPushMatrix();
    glTranslatef(220,-1,-200);
    glScalef(400,1,200);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
