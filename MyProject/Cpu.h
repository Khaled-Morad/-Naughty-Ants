#include<iostream>
#include <windows.h>		// Header File For Windows
#include <gl/GL.h>				// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <gl/glut.h>			// Header File For The GLut32 Library
#include <fstream>
#include <math.h>
#include <glaux.h>
#include "Model_3DS.h"
//#include "GLTexture.h"

//include lib file

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glut32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"GLAUX.LIB")

float b=0.0;
class Cpu
{
	
public:
		   
int back, front, leftq, rightq, top,box ,flatp,flat2,flat3,flatp1;
int wall;
int walls,wall1,wall2;
int flat1,flat4,fllat;

Model_3DS* a;
	Cpu(){

	glEnable(GL_TEXTURE_2D);

	front = LoadTexture("cpu//front.bmp",255);
	back = LoadTexture("cpu//back.bmp",255);
	rightq = LoadTexture("cpu//right.bmp",255);
	leftq = LoadTexture("cpu//left.bmp",255);
	top = LoadTexture("cpu//top.bmp",255);
	box = LoadTexture("cpu//box.bmp",255);
	wall1 = LoadTexture("cpu//wall1.bmp",255);
	wall2 = LoadTexture("cpu//88.bmp",255);
	flat1 = LoadTexture("cpu//99.bmp",255);
	fllat = LoadTexture("cpu//99.bmp",255);
	
	a = new Model_3DS();
	a->Load("ant.3ds");

	}
	
		

void draw_cupe(){
	
	glBegin(GL_QUADS);

	
	  glVertex3f(1,1,-1);
	 glVertex3f(-1,1,-1);
	 glVertex3f(-1,1,1);
	 glVertex3f(1,1,1);

	
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

  glBindTexture(GL_TEXTURE_2D,fllat);
  //glColor3d(0.329412,0.329412,0.329412);
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
void draw_lines(){
glBegin(GL_POLYGON);
  glVertex3f(1,1,-1);
  glVertex3f(-1,1,-1);
  glVertex3f(-1,1,1);
  glVertex3f(1,1,1);

  glEnd();
}
void draw()
{
	//glScaled(100,100,100);

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(6,1.1,-4);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(10,1.1,-4);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(14,1.1,-4);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(14,1.1,-1);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(10,1.1,-1);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(6,1.1,-1);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(14,1.1,2);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(10,1.1,2);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(6,1.1,2);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	////ÔÝÇÝíÉ
	//glPushMatrix();
	//glTranslated(14.1,-1,6.5);
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	//glColor4d(0,0,0,0.3);
	//draw_lines();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(14,1.1,5);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	////ÔÝÇÝíÉ
	//glPushMatrix();
	//glTranslated(10,-1,6.5);
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	//glColor4d(0,0,0,0.9);
	//draw_lines();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(10,1.1,5);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();

	////ÔÝÇÝíÉ
	//glPushMatrix();
	//glTranslated(5.9,-1,6.5);
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	//glColor4d(0,0,0,0.9);
	//draw_lines();
	//glPopMatrix();

	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, wall2);
	//glTranslated(6,1.1,5);
	//glColor3d(0,1,0);
	//draw_cupe();
	//glPopMatrix();


	////Çáäãá
	//glPushMatrix();
	//glTranslated(1,0,1);
	//a->scale=0.05;
	//glColor3d(0,0,0);
	//a->Draw();	
	//glPopMatrix();

	//glPushMatrix();
	//glTranslated(8,0,1);
	//a->scale=0.05;
	//glColor3d(0,0,0);
	//a->Draw();	
	//glPopMatrix();

	//glPushMatrix();
	//glTranslated(12.5,0,1);
	//a->scale=0.05;
	//glColor3d(0,0,0);
	//a->Draw();	
	//glPopMatrix();


	//glPushMatrix();
	//glTranslated(19,0,1);
	//a->scale=0.05;
	//glColor3d(0,0,0);
	//a->Draw();	
	//glPopMatrix();

	//
	//

}
//void draw_ants(){
//	glPushMatrix();
//    glTranslated(0,0,b);
//	b-=0.005;
//	glTranslated(1,0,4);
//	a->scale=0.05;
//	glColor3d(0,0,0);
//	a->Draw();	
//	glPopMatrix();
//
//	glPushMatrix();
//    glTranslated(0,0,b);
//	b-=0.005;
//	glTranslated(7.5,0,4);
//	a->scale=0.05;
//	glColor3d(0,0,0);
//	a->Draw();	
//	glPopMatrix();
//
//	glPushMatrix();
//    glTranslated(0,0,b);
//	b-=0.005;
//	glTranslated(12.5,0,4);
//	a->scale=0.05;
//	glColor3d(0,0,0);
//	a->Draw();	
//	glPopMatrix();
//
//	glPushMatrix();
//    glTranslated(0,0,b);
//	b-=0.005;
//	glTranslated(19,0,4);
//	a->scale=0.05;
//	glColor3d(0,0,0);
//	a->Draw();	
//	glPopMatrix();
//
//	
//}

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

