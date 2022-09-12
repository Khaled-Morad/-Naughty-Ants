#pragma once
#include <gl/GL.h>				// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <glut.h>	
#include <glaux.h>
class SSD
{
public:
	int p1,p2;
	int wall,wall1,block;
	Model_3DS* a;
	SSD()
	{
		glEnable(GL_TEXTURE_2D);
		wall=LoadTexture("flat2.bmp");
		wall1=LoadTexture("images//1.bmp");
		block=LoadTexture("block.bmp");
		a = new Model_3DS();
	    a->Load("ant.3ds");
	}

	void skybox(int x, int y, int z)
{
  glColor3f(1,1,1);
  glTranslated(x,y,z);
  glBindTexture(GL_TEXTURE_2D, wall1);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 0, -2000);
  glTexCoord2d(1, 0);
  glVertex3d(2000, 0, -2000);
  glTexCoord2d(1, 1);
  glVertex3d(2000, 1000, -2000);
  glTexCoord2d(0, 1);
  glVertex3d(0, 1000, -2000);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, wall1);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 0, 2000);
  glTexCoord2d(1, 0);
  glVertex3d(2000, 0, 2000);
  glTexCoord2d(1, 1);
  glVertex3d(2000, 1000, 2000);
  glTexCoord2d(0, 1);
  glVertex3d(0, 1000, 2000);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, wall1);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 0, 2000);
  glTexCoord2d(1, 0);
  glVertex3d(0, 0, -2000);
  glTexCoord2d(1, 1);
  glVertex3d(0, 1000, -2000);
  glTexCoord2d(0, 1);
  glVertex3d(0, 1000, 2000);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, wall1);
  glBegin(GL_QUADS);
  glTexCoord2d(1, 0);
  glVertex3d(2000, 0, 2000);
  glTexCoord2d(0, 0);
  glVertex3d(2000, 0, -2000);
  glTexCoord2d(0, 1);
  glVertex3d(2000, 1000, -2000);
  glTexCoord2d(1, 1);
  glVertex3d(2000, 1000, 2000);
  glEnd();

  glBindTexture(GL_TEXTURE_2D, wall1);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 1000, -2000);
  glTexCoord2d(1, 0);
  glVertex3d(2000, 1000, -2000);
  glTexCoord2d(1, 1);
  glVertex3d(2000, 1000, 2000);
  glTexCoord2d(0, 1);
  glVertex3d(0, 1000, 2000);
  glEnd();

  glBindTexture(GL_TEXTURE_2D,wall1);
  glColor3d(0,1,0);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 0, -2000);
  glTexCoord2d(1, 0);
  glVertex3d(0,0, 2000);
  glTexCoord2d(1, 1);
  glVertex3d(2000, 0, 2000);
  glTexCoord2d(0, 1);
  glVertex3d(2000, 0, -2000);
  glEnd();
  draw();
}

void draw_cupe(){
	
	glBegin(GL_QUADS);

	
	glTexCoord2d(0,0);  glVertex3f(1,1,-1);
	glTexCoord2d(1,0); glVertex3f(-1,1,-1);
	glTexCoord2d(1,1); glVertex3f(-1,1,1);
	glTexCoord2d(0,1); glVertex3f(1,1,1);

	
	glTexCoord2d(0,0); glVertex3f(1,-1,1);
	glTexCoord2d(1,0); glVertex3f(-1,-1,1);
	glTexCoord2d(1,1); glVertex3f(-1,-1,-1);
	glTexCoord2d(0,1); glVertex3f(1,-1,-1);

	
	glTexCoord2d(0,0); glVertex3f(1,1,1);
	glTexCoord2d(1,0); glVertex3f(-1,1,1);
	glTexCoord2d(1,1); glVertex3f(-1,-1,1);
	glTexCoord2d(0,1); glVertex3f(1,-1,1);

	
	glTexCoord2d(0,0); glVertex3f(1,-1,-1);
	glTexCoord2d(1,0); glVertex3f(-1,-1,-1);
	glTexCoord2d(1,1); glVertex3f(-1,1,-1);
	glTexCoord2d(0,1); glVertex3f(1,1,-1);

	
	glTexCoord2d(0,0); glVertex3f(-1,1,1);
	glTexCoord2d(1,0); glVertex3f(-1,1,-1);
	glTexCoord2d(1,1); glVertex3f(-1,-1,-1);
	glTexCoord2d(0,1); glVertex3f(-1,-1,1);


	glTexCoord2d(0,0); glVertex3f(1,1,-1);
	glTexCoord2d(1,0); glVertex3f(1,1,1);
	glTexCoord2d(1,1); glVertex3f(1,-1,1);
	glTexCoord2d(0,1); glVertex3f(1,-1,-1);

	glEnd();

}

void draw(){
	glScaled(100,100,100);

	glPushMatrix();
	glTranslated(10,1,9);
	glScaled(7,1,2);
	glBindTexture(GL_TEXTURE_2D,block);
	glColor3d(0.329412,0.329412,0.329412);
//	draw_cupe();
	glPopMatrix();


	glPushMatrix();
	glTranslated(10,1,1);
	glScaled(7,1,2);
	glBindTexture(GL_TEXTURE_2D,block);
	glColor3d(0.329412,0.329412,0.329412);
//	draw_cupe();
	glPopMatrix();


	glPushMatrix();
	glTranslated(10,1,-9);
	glScaled(2,0.5,2);
	glBindTexture(GL_TEXTURE_2D,block);
	glColor3d(0.329412,0.329412,0.329412);
	//draw_cupe();
	glPopMatrix();

	//ַבהדב
	glPushMatrix();
	glTranslated(2,0,-19);
	a->scale=0.05;
	glColor3d(0,0,0);
	a->Draw();	
	glPopMatrix();

	glPushMatrix();
	glTranslated(17,0,-19);
	a->scale=0.05;
	glColor3d(0,0,0);
	a->Draw();	
	glPopMatrix();
}
bool canmoveinram(Camera c)
{
	if(c.Position.z<50&&c.Position.z>-200&&c.Position.x>300&&c.Position.x<1600)// skybox z	
		return 0;
	if(c.Position.x<50||c.Position.x>1950||c.Position.z<-1950||c.Position.z>1950)// skybox x
		return 0;
	if(c.Position.x<1146&&c.Position.x>834&&c.Position.z<-826&&c.Position.z>-1458)// skybox x
		return 0;
	
	return 1;
}
	
};

