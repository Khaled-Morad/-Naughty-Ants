#pragma once
#include<Model_3DS.h>
class Ant
{
public:
	int x,y,z;
	Model_3DS ant;
	Ant()
	{

	}
	Ant(int a,int b,int c)
	{
		glPushMatrix();
		ant.pos.x=a,
		ant.pos.y=b,
		ant.pos.z=c,
		ant.scale(30);
		draw();
		glPopMatrix();
	}
	void draw()
	{
		ant.Draw();
	}
	



};

