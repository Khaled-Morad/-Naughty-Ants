/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <texture.h>
#include<math.h>
#include <Model_3DS.h>
#include <GLTexture.h>
#include <iostream>
#include "camera.h"
#include <gltexture.h>
#include "PowerSubbly.h"
#include"Ram.h"
#include"SSD.h"
#include"Graphic_card.h"
#include"Cpu.h"
#include"fire.h"
#include<vector>
using namespace std;


HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Defaultm
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
Camera MyCamera;
Camera c;
Ram r;
Graphic_card g;
PowerSupply p;
SSD s;
Cpu cp;
Model_3DS ant;
fire f;
vector<fire> v;
bool b1=0,b2=0,b3=0,b4=0,b5=0;
int ay1=-100,ay2=-100,ay3=-100,ay4=-100,ay5=-100,ay6=-100;
void camera()
{
	if(keys['W']&&r.canmoveinram(c)) c.MoveForward(40);    
	if(keys['S']) c.MoveForward(-20);
	if(keys['A']&&r.canmoveinram(c)) c.MoveRight(-20);	
	if(keys['D']&&r.canmoveinram(c))  c.MoveRight(20);
	if(keys['X']) c.MoveUpward(20);
	if(keys['Z']) c.MoveUpward(-20);
	if(keys['K']) r.light=1;
	if(keys['L']) r.light=0;
	if(keys[VK_LEFT]) 
		c.RotateY(10);
	if(keys[VK_RIGHT]) c.RotateY(-10);
	if(keys[VK_UP]) c.RotateX(-10);	
	if(keys[VK_DOWN]) c.RotateX(10);
	if(keys['V'])
	{
		float a=c.Position.x,b=c.Position.y,d=c.Position.z+15;
		v.push_back(fire(a,b,d));

	}
	c.Render();
}
void camera2()
{
	if(keys['W']) c.MoveForward(100);    
	if(keys['S']) c.MoveForward(-20);
	if(keys['A']) c.MoveRight(-20);	
	if(keys['D'])  c.MoveRight(20);
	if(keys['X']) c.MoveUpward(20);
	if(keys['Z']) c.MoveUpward(-20);
	if(keys['K']) r.light=1;
	if(keys['L']) r.light=0;
	if(keys[VK_LEFT]) 
		c.RotateY(10);
	if(keys[VK_RIGHT]) c.RotateY(-10);
	if(keys[VK_UP]) c.RotateX(-10);	
	if(keys[VK_DOWN]) c.RotateX(10);
	
	c.Render();
}

void choose()
{
	if(keys['0'])
	{
		c=Camera(1280,820,4250,0);
	}
	if(keys['1']){
		b1=1,b2=0,b3=0,b4=0,b5=0;
		c=Camera(1000,400,1940,0);
	}
	if(keys['2']){
		b1=0,b2=1,b3=0,b4=0,b5=0;
		c=Camera(4300,400,1940,0);
	}
	if(keys['3']){
		b1=0,b2=0,b3=1,b4=0,b5=0;
		c=Camera(11500,980,1900,0);
	}
	if(keys['4']){
		b1=0,b2=0,b3=0,b4=1,b5=0;
		c=Camera(8000,900,1900,0);
	}
	if(keys['5']){b1=0,b2=0,b3=0,b4=0,b5=0;
		c=Camera(14600,900,1900,0);
	}
}

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}
	glViewport(0,0,width,height);						// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,2000000.0f);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int back,front,lefl,right,top,flor;
GLTexture c1[20];

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{

	r=Ram(c);
	g=Graphic_card();
	p=PowerSupply();
	s=SSD();
	cp = Cpu();
	ant.Load("ant.3ds");
	ant.Materials[0].tex.Load("ant.bmp");
	sndPlaySound("Mission- Impossible Fallout Theme [Extended] by Lorne Balfe.wav",SND_ASYNC);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
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

	return TRUE;										// Initialization Went OK
}
void check()
{
	for(int j=0;j<v.size();j++){
		if(v[j].x>-1000&&v[j].x<-760&&v[j].z>0&&v[j].z<500 && v[j].use==0&&ay4==-100)
		{
			ay4=10000;
			v[j].y=10000;
			v[j].use=1;
		}
		else if(v[j].x>-1500&&v[j].x<-1250&&v[j].z>0&&v[j].z<500 && v[j].use==0&&ay6==-100)
		{
			ay6=10000;
			v[j].y=10000;
			v[j].use=1;
		}

		else if(v[j].x>-500&&v[j].x<-300&&v[j].z>0&&v[j].z<500 && v[j].use==0&&ay5==-100)
		{
			ay5=10000;
			v[j].y=10000;
			v[j].use=1;
		}
		 else if(v[j].x>-500&&v[j].x<-300&&v[j].z>-800&&v[j].z<-300 && v[j].use==0&&ay1==-100)
		{
			ay1=10000;
			v[j].y=10000;
			v[j].use=1;
		}
		else if(v[j].x>-1000&&v[j].x<-760&&v[j].z>-800&&v[j].z<-300&&v[j].use==0&&ay2==-100)
		{
			ay2=10000;
			v[j].y=10000;
			v[j].use=1;
		}
		else if(v[j].x>-1500&&v[j].x<-1250&&v[j].z>-800&&v[j].z<-300&&v[j].use==0&&ay3==-100)
		{
			ay3=10000;
			v[j].y=10000;
			v[j].use=1;
		}
		v[j].z-=50;
		v[j].draw();
	}
	
}
void makeAnt(float n, float x, float y, float z) {
	glPushMatrix();
	  ant.pos.x =x;
	  ant.pos.y = y;
	  ant.pos.z = z ;
	  ant.scale = n;
	  glRotated(90,x,0,0);
	  ant.Draw();
	glPopMatrix();
}

float angle=0;
void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
	
	
	glPushMatrix();
	if(b1)
	camera();
	else 
	camera2();
	choose();
	check();
	r.skybox(0,0,0);
	g.skybox(3500,0,0);
	glPushMatrix();
	glRotated(-90,8500,0,0);
	s.skybox(6500,0,0);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,8500,0,0);
	p.skybox(9500,0,0);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,8500,0,0);
	cp.skybox(3000,0,0);
	glPopMatrix();
	

	cout<<" x= "<<c.Position.x;
	cout<<"   y= "<<c.Position.y;
	cout<<"    z= "<<c.Position.z<<endl;
	cout<<ay1<<" " <<ay2<<endl;
	for(float i=-5000;i<=12500;i+=200){
	makeAnt(5,i,40,3000);
	makeAnt(5,i,40,2500);

	}
	makeAnt(10,-5000,ay2,-650);
	makeAnt(10,-4500,ay1,-650);
	makeAnt(10,-5500,ay3,-650);
	makeAnt(10,-5000,ay4,500);//Óæíåä ÝæÞ ÈÇáÊÇÈÚ
	makeAnt(10,-4500,ay5,500);
	makeAnt(10,-5500,ay6,500);
	
	glPopMatrix();
	glFlush();											// Done Drawing The Quad	

    //DO NOT REMOVE THIS
	SwapBuffers(hDC);			
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
			ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}
	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_PAINT: 
			DrawGLScene();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
	
		case WM_TIMER:
			DrawGLScene();
			return 0;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Madhat NeHe Template",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer=SetTimer(hWnd,0,50,(TIMERPROC) NULL);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
	}

	return 0;

}

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine , int nCmdShow)
{
	
	return WinMain(hInstance,hPrevInstance,IpCmdLine,nCmdShow);
}
