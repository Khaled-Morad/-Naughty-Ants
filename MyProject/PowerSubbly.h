#pragma once		// Header File For Windows
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
	// Header File For The Glaux Library
#include <cmath>
#include  "Model_3ds.h"
#include  "3DTexture.h"
#include  "heightMap.h"
#include  "tgaLoader.h"
class PowerSupply
{
public:
	int back, front, left, right, top;
	int flat;
	int flat1;
	int flat2;
	Model_3DS* a;
	
int angle;
	int polygon;

	PowerSupply(){
		angle=0;
	glEnable(GL_TEXTURE_2D);
	back = LoadTexture("flat1.bmp");
	front = LoadTexture("flat1.bmp");
	left = LoadTexture("flat1.bmp");
	right = LoadTexture("flat1.bmp");
	top = LoadTexture("flat1.bmp");
	flat=LoadTexture("flat.bmp");
	flat1=LoadTexture("flat1.bmp");
	flat2=LoadTexture("flat2.bmp");
	polygon=LoadTexture("polygon.bmp");
	a = new Model_3DS();
	a->Load("ant.3ds");



	}
void draw_lines(){
glBegin(GL_POLYGON);
  glVertex3f(1,1,-1);
  glVertex3f(-1,1,-1);
  glVertex3f(-1,1,1);
  glVertex3f(1,1,1);

  glEnd();
}


void draw_cupe(){
	
	glBegin(GL_QUADS);

	
	glTexCoord2d(0,0);	glVertex3f(1,1,-1);
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
void skybox(int x, int y, int z)
{
  glColor3f(1,1,1);

  glTranslated(x,y,z);
  glBindTexture(GL_TEXTURE_2D, polygon);
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

  glBindTexture(GL_TEXTURE_2D, polygon);
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

  glBindTexture(GL_TEXTURE_2D, polygon);
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

  glBindTexture(GL_TEXTURE_2D, polygon);
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

  glBindTexture(GL_TEXTURE_2D, polygon);
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

  glBindTexture(GL_TEXTURE_2D,polygon);
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

void drawCylinder(int nmax, int nmin, float height, float radius)
{
	double M_PI=3.14;
  double MAX = height / nmax;
  double MIN = 2.0 * M_PI / nmin;
  int i, j;

  for (i = 0; i < nmax; ++i) {
    GLfloat z0 = 0.5 * height - i * MAX;
    GLfloat z1 = z0 - MAX;

    glBegin(GL_TRIANGLE_STRIP);
    for (j = 0; j <= nmin; ++j) {
      double a = j * MIN;
      GLfloat x = radius * cos(a);
      GLfloat y = radius * sin(a);
      glNormal3f(x / radius, y / radius, 0.0);
      glTexCoord2f(j / (GLfloat)nmin, i / (GLfloat)nmax);
      glVertex3f(x, y, z0);

      glNormal3f(x / radius, y / radius, 0.0);
      glTexCoord2f(j / (GLfloat)nmin, (i + 1) / (GLfloat)nmax);
      glVertex3f(x, y, z1);
    }
    glEnd();
  }
}

void Turbine(){
	glPushMatrix();
	//glRotated(angle, 0, 0, 1);
	angle+=1;
	glBegin(GL_QUADS);
	//First turbine First pole
	glColor3d(0,0,0);
	glVertex3d(0,0,-5);
	glVertex3d(5.2,-1,-5);
	glVertex3d(9,-5.5,-5);
	glVertex3d(3.2,-3.8,-5);
	//Second turbine First pole
	glColor3d(0,0,0);
	glVertex3d(0,0,-5);
	
	glVertex3d(-3.2,-3.8,-5);
	glVertex3d(-9,-5.5,-5);
	glVertex3d(-4.8,-1,-5);
	//Third turbine First pole
	glColor3d(0,0,0);
	glVertex3d(0,0,-5);
	
	glVertex3d(1.7,4.5,-5);
	glVertex3d(0,10,-5);
	glVertex3d(-1.7,4.5,-5);
	glEnd();
	//glRotated(angle, 0, 0, -1);
	glPopMatrix();
}
void draw()
{
	glRotated(270,0,1,0);
	glScaled(78,100,90.5);
	
	glTranslated(0,0,-11);
	
	//ÇÑÖíÉ 
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,flat1);
	glColor3f(0,1,0);
	glScaled(25,0.01,-11);
	draw_cupe();
	glPopMatrix();

	

	//ãßÚÈ 
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,flat1);
	glColor3f(0.5,0.3,0.7);
	glColor3f(0.329412,0.329412,0.329412);
	glTranslated(10,0,1);
	glScaled(1,2,4);
	draw_cupe();
	glPopMatrix();


	//ÇÓØæÇäÉ//
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,flat);
	glColor3f(1,0,1);
	glRotatef(90,1,0,0);
	glTranslated(16,2,-2);
	glScaled(3,1.5,-1.5);
	drawCylinder(40,40,2,0.6);
	glPopMatrix();


	//ÇÓØæÇäÉ//
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,flat);
	glColor3f(1,0,1);
	glRotatef(90,1,0,0);
	glTranslated(16,-2,-2);
	glScaled(3,1,-1.5);
	drawCylinder(40,40,2,0.6);
	glPopMatrix();


	//ÇÓØæÇäÉ//
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,flat);
	glColor3f(1,0,1);
	glRotatef(90,1,0,0);
	glTranslated(-3,4,-1);
	glScaled(3,1.5,-1.5);
	drawCylinder(40,40,2,0.3);
	glPopMatrix();

	//ÇÓØæÇäÉ//
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,flat);
	glColor3f(1,0,1);
	glRotatef(90,1,0,0);
	glTranslated(-5.5,1,-1);
	glScaled(3,1.5,-1.5);
	drawCylinder(40,40,2,0.3);
	glPopMatrix();


	//ãßÚÈ 
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,polygon);
	glColor3d(0.329412,0.329412,0.329412);
	glTranslated(1,0,1);
	glScaled(1,2,4);
	draw_cupe();
	glPopMatrix();

	//ãßÚÈ 
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4d(0,1,1,0.3);
	//glColor3f(0,1,1);
	glTranslated(5,1,3);
	glScaled(1,1,3);
	draw_cupe();
	glPopMatrix();

	


	//ãßÚÈ 
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslated(-7,1,5);
	glRotated(90,0,1,0);
	glScaled(1,1,2);
	draw_cupe();
	glPopMatrix();

	//ÔÑÇÆØ//
	glPushMatrix();
	glTranslated(0,0,-5);
	glScaled(26,0,0.5);
	glColor3f(0,0,1);
	draw_lines();
	glPopMatrix();

	//ÔÑÇÆØ//
	glPushMatrix();
	glTranslated(-10,-1,0);
	glScaled(0.5,1,-11);
	glColor3f(1,0,0);
	draw_lines();
	glPopMatrix();

	//ÔÑÇÆØ//
	glPushMatrix();
	glTranslated(-12,-1,0);
	glScaled(0.5,1,-11);
	glColor3f(1,1,0);
	draw_lines();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1,-1,-8);
	glScaled(0.7,1,0.7);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4d(0,0,0,0.9);
	draw_lines();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3,-1,-8);
	glScaled(0.7,1,0.7);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4d(0,0,0,0.9);
	draw_lines();
	glPopMatrix();

	glPushMatrix();
	glTranslated(5,-1,-8);
	glScaled(0.7,1,0.7);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4d(0,0,0,0.9);
	draw_lines();
	glPopMatrix();

	//ãßÚÈ ÕÛíÑ//
	glPushMatrix();
	glTranslated(0,0.3,-8);
	glScaled(0.3,0.3,0.7);
	glColor3d(0.329412,0.329412,0.329412);
	draw_cupe();
	glPopMatrix();

	//ãßÚÈ ÕÛíÑ//
	glPushMatrix();
	glTranslated(-4,0.3,-8);
	glScaled(0.3,0.3,0.7);
	glColor3d(0.329412,0.329412,0.329412);
	draw_cupe();
	glPopMatrix();

	//ãßÚÈ ÕÛíÑ//
	glPushMatrix();
	glTranslated(4,0.3,-8);
	glScaled(0.3,0.3,0.7);
	glColor3d(0.329412,0.329412,0.329412);
	draw_cupe();
	glPopMatrix();

	//ãÑæÍÉ//
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,5,-24);
	glScaled(0.5,0.5,0.5);
	Turbine();
	glPopMatrix();

	//Çáäãá
	glPushMatrix();
	glTranslated(-19,0,-4);
	a->scale=0.1;
	a->Draw();	
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4,0,-6);
	glRotated(90,0,1,0);
	a->scale=0.1;
	a->Draw();
	glPopMatrix();


}

//void draw_ants(){
//	glPushMatrix();
//	glTranslated(0,0,b);
//	glTranslated(-7,0,7);
//	
//	b-=0.005;
//	a->scale=0.05;
//	a->Draw();	
//	glPopMatrix();
//
//	glPushMatrix();
//	
//	glTranslated(b,0,0);
//	glTranslated(17,0,-6);
//	glRotated(90,0,1,0);
//	b-=0.005;
//	a->scale=0.05;
//	a->Draw();
//	glPopMatrix();
//}

bool canmove(Camera c)
{
	if(c.Position.z<50&&c.Position.z>-200&&c.Position.x>300&&c.Position.x<1600)// skybox z	
		return 0;
	if(c.Position.x<50||c.Position.x>1950||c.Position.z<-1950||c.Position.z>1950)// skybox x
		return 0;
	if(c.Position.x<623&&c.Position.x>443&&c.Position.z<-414&&c.Position.z>-882)
		return 0;
	if(c.Position.x<954&&c.Position.x>866&&c.Position.z<-401&&c.Position.z>-636)
		return 0;
	

	return 1;
}
};
