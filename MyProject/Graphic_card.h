#pragma once
#include <windows.h>		// Header File For Windows
#include <fstream>
#include<iostream>
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Model_3ds.h"
#include "3DTexture.h"


class Graphic_card
{
public:
	//Camera MyCamera;
	Model_3DS card , ant;
	GLTexture c1[20];

	int back, front, l, r,top, flor;

	Graphic_card(void)
	{
		glEnable(GL_TEXTURE_2D);
		c1[0].LoadBMP("Images/aaa.bmp");
		c1[1].LoadBMP("Images/cardup.bmp");
		c1[2].LoadBMP("Images/cooler.bmp");
		c1[4].LoadBMP("Images/cap.bmp");
		c1[5].LoadBMP("Images/cuper.bmp");
		c1[6].LoadBMP("Images/w.bmp");
		c1[7].LoadBMP("Images/jak1.bmp");
		c1[8].LoadBMP("Images/jak2.bmp");
		c1[9].LoadBMP("Images/flat.bmp");
		c1[10].LoadBMP("Images/e.bmp");
		c1[11].LoadBMP("Images/face.bmp");

		card = Model_3DS();
		char abc[] = "8400GS.3ds";
		card.Load(abc);
		card.pos.x = 0;
		card.pos.y = 0;
		card.pos.z = -20;
		card.scale = 1.5f;
		back = LoadTexture("Images/other.bmp",255);
		front = LoadTexture("Images/other.bmp",255);
		l = LoadTexture("Images/backe.bmp",255);
		r = LoadTexture("Images/other.bmp",255);
		top = LoadTexture("Images/other.bmp",255);
		flor= LoadTexture("Images/floor.bmp",255);
	}


	void buildMySence(){

	card.Materials[0].tex = c1[1];
	card.Materials[1].tex = c1[0];
	card.Materials[2].tex = c1[10];
	card.Materials[3].tex = c1[10];
	card.Materials[4].tex = c1[4];
	card.Materials[5].tex = c1[4];
	card.Materials[8].tex = c1[4];
	card.Materials[9].tex = c1[5];
	card.Materials[11].tex = c1[6];
	card.Materials[12].tex = c1[4]; 
    card.Materials[10].tex = c1[4];
	card.Materials[13].tex = c1[4];
	card.Materials[14].tex = c1[4];
	card.Materials[15].tex = c1[7];
	card.Materials[16].tex = c1[11];
	card.Materials[17].tex = c1[8];
	card.Materials[18].tex = c1[9];
	card.Materials[19].tex = c1[2];														 
	glTranslatef(600,300,0);

	glRotatef(90,1,0,0);
	card.Draw();
}
	void skybox(int x, int y, int z)
	{
		glColor3f(1,1,1);
//glPushMatrix();
		glTranslatef(x,y,z);
		glBindTexture(GL_TEXTURE_2D, front);
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

		glBindTexture(GL_TEXTURE_2D, back);
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

		glBindTexture(GL_TEXTURE_2D, l);
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

		glBindTexture(GL_TEXTURE_2D, r);
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

		glBindTexture(GL_TEXTURE_2D, top);
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

		glBindTexture(GL_TEXTURE_2D,flor);
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

		buildMySence();
	//lPopMatrix();
		}
		
	bool isOut(Camera MyCamera)
	{
	if (MyCamera.Position.x <= 10500 || MyCamera.Position.x >= 12500 ) 
		return false;	
	if(MyCamera.Position.z <=-1700 || MyCamera.Position.z >= 1700 ) 
		return false;
	/*if( MyCamera.Position.x <= 1295 && MyCamera.Position.x >= 156.72 && MyCamera.Position.z >=-63.4&& MyCamera.Position.z <= 156.4 && MyCamera.Position.y <= 557.8 && MyCamera.Position.y >= 155)
		return false;
*/
	return true;
}
};
