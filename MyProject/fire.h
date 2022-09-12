#pragma once
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>	
#include<math.h>
class fire
{
public:
	float x,y,z;
	bool use;
	fire(){
		use=0;
	}
	fire(float a,float b,float c)
	{
		x=a,y=b,z=c;
		use=0;
	}
	void draw()
	{
		glColor3f(1,0,0);
		glPointSize(20);
		glBegin(GL_POINTS);
		glVertex3f(x,y,z);
		glEnd();

	}

};

