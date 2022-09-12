#include<iostream>
#include <windows.h>		// Header File For Windows
#include <gl/GL.h>				// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <gl/glut.h>			// Header File For The GLut32 Library
#include <fstream>
#include <math.h>
#include <glaux.h>
#include "Model_3DS.h"
#include "GLTexture.h"

//include lib file

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glut32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"GLAUX.LIB")
class Cpu
{
	
public:
		   
int back, front, leftq, rightq, top,box ,flatp,flat2,flat3,flatp1;
int wall;
int walls,wall1,wall2;
int flat1,flat4;
	Cpu(){

		

	glEnable(GL_TEXTURE_2D);

	front = LoadTexture("front.bmp",255);
	back = LoadTexture("back.bmp",255);
	rightq = LoadTexture("right.bmp",255);
	leftq = LoadTexture("left.bmp",255);
	top = LoadTexture("top.bmp",255);
	box = LoadTexture("box.bmp",255);
	wall1 = LoadTexture("wall1.bmp",255);
	flat1 = LoadTexture("flat1.bmp",255);
	

	}
	
		

void draw_cupe(){
	
	glBegin(GL_QUADS);

	
	  glVertex3f(1,1,-1);
	 glVertex3f(-1,1,-1);
	 glVertex3f(-1,1,1);
	 glVertex3f(1,1,1);

	
	/*glTexCoord2d(0,0);*/ glVertex3f(1,-1,1);
	/*glTexCoord2d(1,0);*/ glVertex3f(-1,-1,1);
	/*glTexCoord2d(1,1);*/ glVertex3f(-1,-1,-1);
	/*glTexCoord2d(0,1);*/ glVertex3f(1,-1,-1);

	
	/*glTexCoord2d(0,0);*/ glVertex3f(1,1,1);
	/*glTexCoord2d(1,0);*/ glVertex3f(-1,1,1);
	/*glTexCoord2d(1,1);*/ glVertex3f(-1,-1,1);
	/*glTexCoord2d(0,1);*/ glVertex3f(1,-1,1);

	
	/*glTexCoord2d(0,0);*/ glVertex3f(1,-1,-1);
	/*glTexCoord2d(1,0);*/ glVertex3f(-1,-1,-1);
	/*glTexCoord2d(1,1);*/ glVertex3f(-1,1,-1);
	/*glTexCoord2d(0,1);*/ glVertex3f(1,1,-1);

	
	/*glTexCoord2d(0,0);*/ glVertex3f(-1,1,1);
	/*glTexCoord2d(1,0);*/ glVertex3f(-1,1,-1);
	/*glTexCoord2d(1,1);*/ glVertex3f(-1,-1,-1);
	/*glTexCoord2d(0,1);*/ glVertex3f(-1,-1,1);


	/*glTexCoord2d(0,0);*/ glVertex3f(1,1,-1);
	/*glTexCoord2d(1,0);*/ glVertex3f(1,1,1);
	/*glTexCoord2d(1,1);*/ glVertex3f(1,-1,1);
	/*glTexCoord2d(0,1);*/ glVertex3f(1,-1,-1);

	glEnd();

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
  glColor3d(1,1,0);
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

  glBindTexture(GL_TEXTURE_2D,flat1);
  glColor3d(0.329412,0.329412,0.329412);
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


  //glPushMatrix();
  //ram_slies();
  //glPopMatrix();

}
void draw(Cpu c)
{
	glScaled(100,100,100);

	glPushMatrix();
	glTranslated(6,-1.1,-4);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10,-1.1,-4);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(14,-1.1,-4);
	glColor3d(0.329412,0.329412,0.329412);
		c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(14,-1.1,-1);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10,-1.1,-1);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(6,-1.1,-1);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(14,-1.1,2);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10,-1.1,2);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(6,-1.1,2);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(14,-1.1,5);
	glColor3d(0.329412,0.329412,0.329412);
c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10,-1.1,5);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();

	glPushMatrix();
	glTranslated(6,-1.1,5);
	glColor3d(0.329412,0.329412,0.329412);
	c.draw_cupe();
	glPopMatrix();
	
	

}
bool canmoveinram(Camera c)
{
	if(c.Position.z<1300&&c.Position.z>1050&&c.Position.x>300&&c.Position.x<1600)	//first  ram
		return 0;
	if(c.Position.z<50&&c.Position.z>-200&&c.Position.x>300&&c.Position.x<1600)	// second ram
		return 0;
	if(c.Position.z<50&&c.Position.z>-200&&c.Position.x>300&&c.Position.x<1600)// skybox z	
		return 0;
	if(c.Position.x<50||c.Position.x>1950||c.Position.z<-1950||c.Position.z>1950)// skybox x
		return 0;
	return 1;
}
};

