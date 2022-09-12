
class Ram
{
public:
	int back,front,left,right,top,flor,ram,dd,cc;
	bool light;
	Camera c;
	Ram()
	{

	}
	Ram(Camera cam)
	{
		light=1;
		glEnable(GL_TEXTURE_2D);
		back = LoadTexture("images//s.bmp");
		front = LoadTexture("images//s.bmp");
		left = LoadTexture("images//s.bmp");
		right = LoadTexture("images//s.bmp");
		top = LoadTexture("images//1.bmp");
		flor = LoadTexture("images//cc.bmp");
		ram=LoadTexture("images//z.bmp");
		dd=LoadTexture("photo.bmp");
		cc=LoadTexture("cc.bmp");
		c=cam;
	}
	
void skybox(int x, int y, int z)
{

	glColor3f(1,1,1);
	glTranslated(x,y,z);
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2000, 0, -2000);
	glTexCoord2d(1, 0);
	glVertex3d(2000, 0, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(2000, 1000, -2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2000, 1000, -2000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2000, 0, 2000);
	glTexCoord2d(1, 0);
	glVertex3d(2000, 0, 2000);
	glTexCoord2d(1, 1);
	glVertex3d(2000, 1000, 2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2000, 1000, 2000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2000, 0, 2000);
	glTexCoord2d(1, 0);
	glVertex3d(-2000, 0, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(-2000, 1000, -2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2000, 1000, 2000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
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
	glVertex3d(-2000, 1000, -2000);
	glTexCoord2d(1, 0);
	glVertex3d(2000, 1000, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(2000, 1000, 2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2000, 1000, 2000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,flor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2000, 0, -2000);
	glTexCoord2d(1, 0);
	glVertex3d(-2000,0, 2000);
	glTexCoord2d(1, 1);
	glVertex3d(2000, 0, 2000);
	glTexCoord2d(0, 1);
	glVertex3d(2000, 0, -2000);
	glEnd();

	glPushMatrix();
	ram_slies();
	glPopMatrix();
	allskybox();

}
void ram_slies()
{
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(1,1,1,0.5);
	
	if(!light)
	glColor3ub(83,83,83);
	glBindTexture(GL_TEXTURE_2D,ram);
	//glColor3f(0,1,0);
	glBegin(GL_QUADS);//face
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, -1260);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, -1260);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, -1260);
	glTexCoord2d(1, 0);
	glVertex3d(1500,0, -1260);
	glEnd();

	glBegin(GL_QUADS);//ds face
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, -1100);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, -1100);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, -1100);
	glTexCoord2d(1, 0);
	glVertex3d(1500,0, -1100);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, -1260);
	glTexCoord2d(0, 1);
	glVertex3d(380,0, -1100);
	glTexCoord2d(1, 1);
	glVertex3d(380,500, -1100);
	glTexCoord2d(1, 0);
	glVertex3d(380,500, -1260);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(380, 500, -1260);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, -1100);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, -1100);
	glTexCoord2d(1, 0);
	glVertex3d(1500, 500, -1260);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1500, 0, -1260);
	glTexCoord2d(0, 1);
	glVertex3d(1500,0, -1100);
	glTexCoord2d(1, 1);
	glVertex3d(1500,500, -1100);
	glTexCoord2d(1, 0);
	glVertex3d(1500,500, -1260);
	glEnd();


	
	glPopMatrix();

	///////////////////////////////////////
	
	glBindTexture(GL_TEXTURE_2D,ram);
	glBegin(GL_QUADS);//face
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, 1260);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, 1260);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, 1260);
	glTexCoord2d(1, 0);
	glVertex3d(1500,0, 1260);
	glEnd();


	glBegin(GL_QUADS);//face
	glTexCoord2d(0, 0);
	glVertex3d(380, 180, 1260);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, 1260);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, 1260);
	glTexCoord2d(1, 0);
	glVertex3d(1500,180, 1260);
	glEnd();


	glBegin(GL_QUADS);//ds face
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, 1100);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, 1100);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, 1100);
	glTexCoord2d(1, 0);
	glVertex3d(1500,0, 1100);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, 1260);
	glTexCoord2d(0, 1);
	glVertex3d(380,0, 1100);
	glTexCoord2d(1, 1);
	glVertex3d(380,500, 1100);
	glTexCoord2d(1, 0);
	glVertex3d(380,500, 1260);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(380, 500, 1260);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, 1100);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, 1100);
	glTexCoord2d(1, 0);
	glVertex3d(1500, 500, 1260);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1500, 0, 1260);
	glTexCoord2d(0, 1);
	glVertex3d(1500,0, 1100);
	glTexCoord2d(1, 1);
	glVertex3d(1500,500, 1100);
	glTexCoord2d(1, 0);
	glVertex3d(1500,500, 1260);
	glEnd();

//////////////////////////////////////////
	
	glBindTexture(GL_TEXTURE_2D,ram);
	//glColor3f(1,0,0);
	glBegin(GL_QUADS);//face
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, -160);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, -160);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, -160);
	glTexCoord2d(1, 0);
	glVertex3d(1500,0, -160);
	glEnd();

	glBegin(GL_QUADS);//ds face
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, 0);
	glTexCoord2d(1, 0);
	glVertex3d(1500,0, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(380, 0, -160);
	glTexCoord2d(0, 1);
	glVertex3d(380,0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(380,500, 0);
	glTexCoord2d(1, 0);
	glVertex3d(380,500, -160);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(380, 500, -160);
	glTexCoord2d(0, 1);
	glVertex3d(380,500, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 500, 0);
	glTexCoord2d(1, 0);
	glVertex3d(1500, 500, -160);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1500, 0, -160);
	glTexCoord2d(0, 1);
	glVertex3d(1500,0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1500,500, 0);
	glTexCoord2d(1, 0);
	glVertex3d(1500,500, -160);
	glEnd();

	//////////////////////////////
	genratesquares(420,280,1270);
	genratesquares(675,280,1270);
	genratesquares(1180,280,1270);
	genratesquares(930,280,1270);
	//////////////////////////////
	genratesquares2(1190,160,1030);
	genratesquares2(940,160,1030);
	genratesquares2(690,160,1030);
	genratesquares2(440,160,1030);
	/////////////////////////////
	genratesquares2(1190,160,-1055);
	genratesquares2(940,160,-1055);
	genratesquares2(690,160,-1055);
	genratesquares2(440,160,-1055);
	///////////////////////////////
	genratesquares2(1190,160,-1285);
	genratesquares2(940,160,-1285);
	genratesquares2(690,160,-1285);
	genratesquares2(440,160,-1285);
	//////////////////////////////
	for(int i=420;i<=1460;i+=22)
	{
		genrateyalleo(i,15,1280);
	}
	/////////////////////////////
	for(int i=420;i<=1460;i+=22)
	{
		genrateyalleo(i,190,1280);
	}
	////////////////////////////
	for(int i=450;i<=1460;i+=22)
	{
		genrateyalleo(i,25,-1080);
	}
	//zoom();
	
	glBindTexture(GL_TEXTURE_2D,-1);
}
bool canmoveinram(Camera c)
{
	if(c.Position.z<1000&&c.Position.z>1500&&c.Position.x>1000&&c.Position.x<2000)	//first  ram
		return 0;
	if(c.Position.z<50&&c.Position.z>-200&&c.Position.x>300&&c.Position.x<1600)	// second ram
		return 0;
	if(c.Position.z<50&&c.Position.z>-200&&c.Position.x>300&&c.Position.x<1600)// skybox z	
		return 0;
	if(c.Position.x<-1950||c.Position.x>1950||c.Position.z<-1950||c.Position.z>1950)// skybox x
		return 0;
	return 1;
}
void genratesquares(int x,int y,int z)
{
	for(float l = 0;l<40;l++){
	glColor3ub(50,9,94);
	glBegin(GL_QUADS);
	glVertex3f(x,y,z+l);
	glVertex3f(x+160,y,z+l);
	glVertex3f(x+160,y+220,z+l);
	glVertex3f(x,y+220,z+l);
	glEnd();
	}
}
void genratesquares2(int x,int y,int z)
{
	for(float l = 0;l<40;l++){
	glColor3ub(50,9,94);
	glBegin(GL_QUADS);
	glVertex3f(x,y,z+l);
	glVertex3f(x+160,y,z+l);
	glVertex3f(x+160,y+340,z+l);
	glVertex3f(x,y+340,z+l);
	glEnd();
	}
}
void genrateyalleo(int x,int y,int z)
{
	for(float l = 0;l<20;l++){
	glColor3ub(250,180,0);
	glBegin(GL_QUADS);
	glVertex3f(x,y,z+l);
	glVertex3f(x+20,y,z+l);
	glVertex3f(x+20,y+40,z+l);
	glVertex3f(x,y+40,z+l);
	glEnd();
	}
}
void zoom (Camera c)
{
	glPointSize(10);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex3f(c.Position.x-2,c.Position.y,c.Position.z-10);
	glVertex3f(c.Position.x+2,c.Position.y,c.Position.z-10);
	glEnd();
}
void allskybox()
{
	glBindTexture(GL_TEXTURE_2D,dd);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-25000, -200, -25000);
	glTexCoord2d(1, 0);
	glVertex3d(-25000,-200, 25000);
	glTexCoord2d(1, 1);
	glVertex3d(25000, -200, 25000);
	glTexCoord2d(0, 1);
	glVertex3d(25000, -200, -25000);
	glEnd();
	//////////////////////////////////
	

}



	
};

