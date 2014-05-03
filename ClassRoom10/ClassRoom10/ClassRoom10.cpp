//	Submitted By:
//	MAHBUB - A - ROB, CSE 023 05362
//	SYED SEFAYET HOSSAIN, ID. CSE 02705586
//	SAJNIN, CSE 04106055
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

#define BLACK 0, 0, 0

//make a global variable -- for tracking the anglular position of camera
double cameraAngle;			//in radian
double cameraAngleDelta;

double cameraHeight;	
double cameraRadius;

double rectAngle;	//in degree

bool canDrawGrid;

static GLuint cubeList;

GLuint texture1, textureBackWallLeft, textureDoor, textureWhiteBoard, textureCeiling;

GLuint texture;

int num_texture = -1;

int lightSwitch = 1;

//diffuse light color variables
GLfloat dlr = 2.1;
GLfloat dlg = 2.1;
GLfloat dlb = 2.1;

//ambient light color variables
GLfloat alr = 0.1;
GLfloat alg = 0.1;
GLfloat alb = 0.1;

//light position variables
GLfloat lx = 0.0;
GLfloat ly = 0.0;
GLfloat lz = 1.0;
GLfloat lw = 0.0;

void light (void) {
	glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glEnable (GL_LIGHT1); //enable LIGHT1, our Ambient Light
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
	glEnable( GL_COLOR_MATERIAL);
	glEnable( GL_NORMALIZE);
	GLfloat DiffuseLight[] = {dlr, dlg, dlb}; //set DiffuseLight [] to the specified values
    GLfloat AmbientLight[] = {alr, alg, alb}; //set AmbientLight [] to the specified values
    glLightfv (GL_LIGHT0, GL_DIFFUSE, DiffuseLight); //change  the light accordingly
    glLightfv (GL_LIGHT1, GL_AMBIENT, AmbientLight); //change  the light accordingly
    GLfloat LightPosition[] = {lx, ly, lz, lw}; //set the LightPosition to the specified values
    glLightfv (GL_LIGHT0, GL_POSITION, LightPosition); //change the light accordingly
}


void chairTable(){


// chair backside blue
	glPushMatrix();

	//glColor3f( .42, .40, .5 );

	//glColor3f(0.2,0.3, 0.2);
	glColor3f(0.2,0.2, 0.3);
	//glColor3f(.5, .190, .164); // mahogony color
	glTranslatef(-75, 0, 10); // x++ = go back from front, y++ = go 100 unit from left to right, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 1, 5, 15.5 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();

// chair seat
	glPushMatrix();
	glColor3f( .73, .55, .43 );
		glTranslatef(-73, 0, 10); // x++ = go back from front, y++ = go 100 unit from left to right, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 4, 4.8, 1 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();

// chair frontside blue, -72+5 = 67, so glTranslateX will be -67
	glPushMatrix();
	glColor3f( .42, .40, .41 );
		glTranslatef(-71.5, 0, 5.8); // x++ = go back from front, y++ = go 100 unit from left to right, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 1, 5, 7.5 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();



	// start table, use seat of the chair as temparary template

	// tabletop color Carmine Red= 100, 0, 22 or Bazaar 60 47 48 
	glPushMatrix();
//	glColor3f( .73,.55,.54 );
	glColor3f( .73, .55, .54 );
			//glColor3f(0.3,0.3, 0.2);

	glTranslatef(-68, 0, 13); // x++ = go back from front, y++ = go 100 unit from left to right, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 5, 8, 1 ); // z++ = scale the height of the wall
		
		glCallList(cubeList);
	glPopMatrix();
	// end of tabletop

	// right side of the table, use right wall, color forest green 13, 55, 13 or fuchsia crayola 76, 33, 76 
	glPushMatrix();
	glColor3f( 0.2,0.2, 0.2 );
		glTranslatef(-68, 3, 7.5); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 5, 1, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
		
	//end right side of the table

	// left side of the table, use right side of the table with TranslateY
	glPushMatrix();
	glColor3f( 0.2,0.2, 0.2 );
		glTranslatef(-68, -3, 7.5); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 5, 1, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
		
	//end right side of the table

	// end table side
}

void teacherTable(){
	// start table, use seat of the chair as temparary template
	// tabletop color Carmine Red= 100, 0, 22 or Bazaar 60 47 48 
	glPushMatrix();
//	glColor3f( .73,.55,.54 );
//	glColor3f( .73, .55, .54 );
		glColor3f(0.2,0.3, 0.2);

		glTranslatef(-68, 0, 13); // x++ = go back from front, y++ = go 100 unit from left to right, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 7, 10, 1 ); // z++ = scale the height of the wall
		
		glCallList(cubeList);
	glPopMatrix();
	// end of tabletop

	// right side of the table, use right wall, color forest green 13, 55, 13 or fuchsia crayola 76, 33, 76 
	glPushMatrix();
	glColor3f( 0.2,0.2, 0.2 );
		glTranslatef(-68, 3, 7.5); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 5, 1, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
		
	//end right side of the table

	// left side of the table, use right side of the table with TranslateY
	glPushMatrix();
	glColor3f( 0.2,0.2, 0.2 );
		glTranslatef(-68, -3, 7.5); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( 5, 1, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();

/*
	// left side of the table, use right side of the table with TranslateY
	glPushMatrix();
	glColor3f( 0.1,0.1, 0.2 );
		glTranslatef(-68, 2, 13); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		glScalef( .4, .4, 6 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
*/


}
void chairTableMiddleRow(){
// call chairTable func
	// chair talbe 1

	glPushMatrix();
		chairTable();
	glPopMatrix();

	// chair talbe 2
	glPushMatrix();
		glTranslatef( 12.0, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

	// chair talbe 3
	glPushMatrix();
		glTranslatef( 24.0, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

	// chair talbe 4
	glPushMatrix();
		glTranslatef( 36.0, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

	// chair talbe 5
	glPushMatrix();
		glTranslatef( 48.0, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

	// chair talbe 6
	glPushMatrix();
		glTranslatef( 60.0, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

		// chair talbe 7
	glPushMatrix();
		glTranslatef( 72.0, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

	// chair talbe 8
	glPushMatrix();
		glTranslatef( 84.0, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

	// chair talbe 9
	glPushMatrix();
		glTranslatef( 12.0*8, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

	// chair talbe 10
	glPushMatrix();
		glTranslatef( 12.0*9, 0.0, 0.0 );
		chairTable();
	glPopMatrix();

}
void frontWall(){

	// front wall, light green
	glPushMatrix();
	glColor3f( .7, .7, 0.7 );
		glTranslatef(100, 0, 6); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		//glRotatef(30.0, 0.0, 1.0, 0.0);
		//glScalef( 200, 95, 5 ); // x++ = scale as it feels the ground as floor, making the floor
		//glScalef( 5, 100, 5 ); // y++ = scale the length of the wall/floor
		glScalef( 5, 200, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
	// end side front wall

}

void floor(){
	
	glPushMatrix();
	glColor3f( 0.8, 0.8, 0.8 );
		glTranslatef(0, 0, 0); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		//glRotatef(30.0, 0.0, 1.0, 0.0);
		glScalef( 200, 90, 5 ); // x++ = scale as it feels the ground as floor, making the floor
		//glScalef( 5, 100, 5 ); // y++ = scale the length of the wall/floor
		//glScalef( 5, 100, 40 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
	// end floor

}

void backWall(){
glPushMatrix();

		glColor4f( .3, .3, .3, .9 );
	glColor3f( .8, .8, 0.8 );
	glColor3f( .7, .7, 0.7 );

		glTranslatef(-100, 0, 6); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		//glRotatef(30.0, 0.0, 1.0, 0.0);
		//glScalef( 200, 95, 5 ); // x++ = scale as it feels the ground as floor, making the floor
		//glScalef( 5, 100, 5 ); // y++ = scale the length of the wall/floor
		glScalef( 5, 200, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
	// end back wall

}

void rightWall(){
	glPushMatrix();
		glColor4f( .8, .8, .8, .9 );
		//glColor4f( .7, .7, .7, .9 );
	glColor3f( .7, .7, 0.7 );

		glTranslatef(0, 100, 6); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -90, -90, 0);  // theta = 0 horizontal
		//glRotatef(30.0, 0.0, 1.0, 0.0);
		//glScalef( 200, 95, 5 ); // x++ = scale as it feels the ground as floor, making the floor
		//glScalef( 5, 100, 5 ); // y++ = scale the length of the wall/floor
		glScalef( 200, 5, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();
	//end right side wall

}

void leftWall(){
	// left side wall
	glPushMatrix();
		glColor4f( .8, .8, .8, .9 );
	glColor3f( .7, .7, 0.7 );

		glTranslatef(0, -100, 6); // x++ = go back from front, y++ = side position, z++ = top to bottom or bottom to top positioning 
		glRotatef(0, -30, -100, 0);  // theta = 0 horizontal
		//glRotatef(30.0, 0.0, 1.0, 0.0);
		//glScalef( 200, 95, 5 ); // x++ = scale as it feels the ground as floor, making the floor
		//glScalef( 5, 100, 5 ); // y++ = scale the length of the wall/floor
		glScalef( 200, 5, 10 ); // z++ = scale the height of the wall

		glCallList(cubeList);
	glPopMatrix();

}



int LoadBitmap(char *filename)
{
    int i, j=0;
    FILE *l_file;
    unsigned char *l_texture;

    BITMAPFILEHEADER fileheader;
    BITMAPINFOHEADER infoheader;
    RGBTRIPLE rgb;

    num_texture++;

    if( (l_file = fopen(filename, "rb"))==NULL) return (-1);

    fread(&fileheader, sizeof(fileheader), 1, l_file);

    fseek(l_file, sizeof(fileheader), SEEK_SET);
    fread(&infoheader, sizeof(infoheader), 1, l_file);

    l_texture = (byte *) malloc(infoheader.biWidth * infoheader.biHeight * 4);
    memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);
	for (i=0; i < infoheader.biWidth*infoheader.biHeight; i++)
    {
            fread(&rgb, sizeof(rgb), 1, l_file);

            l_texture[j+0] = rgb.rgbtRed;
            l_texture[j+1] = rgb.rgbtGreen;
            l_texture[j+2] = rgb.rgbtBlue;
            l_texture[j+3] = 255;
            j += 4;
    }
    fclose(l_file);

    glBindTexture(GL_TEXTURE_2D, num_texture);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

    free(l_texture);

    return (num_texture);

}



void Texture(void)
{
	texture1 =LoadBitmap("f2.bmp");
	textureCeiling = LoadBitmap("whiteTiles3d.bmp");
//	textureCeiling = LoadBitmap("whiteNice.bmp");
	
	//texture1 =LoadBitmap("blackStar.bmp");

//	textureBackWallLeft =LoadBitmap("blurryGreen.bmp");
//	textureBackWallRight = LoadBitmap("blurryGreenCopy.bmp");
	textureDoor = LoadBitmap("doorGlass2.bmp");

//	textureBackWallLeft =LoadBitmap("blackAndWhite.bmp");
	
 	textureBackWallLeft =LoadBitmap("blue2.bmp");
//textureBackWallLeft =LoadBitmap("blue.bmp");
//textureBackWallLeft =LoadBitmap("brick2.bmp");
//textureBackWallLeft =LoadBitmap("blue2.bmp");

//	textureBackWallLeft =LoadBitmap("burned.bmp");

//	textureBackWallLeft =LoadBitmap("artistic.bmp");

	textureWhiteBoard = LoadBitmap("whiteBoard9.bmp");
//	textureBackWallRight = LoadBitmap("artisticCopy.bmp");
// blue.bmp
// whiteNice
// flowerNice
}

void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(BLACK, 0);	//color black
//	glClearColor(.9, .9, .9, 0.0 );	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();
	//light();


	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking?
	//3. Which direction is the camera's UP direction?

	//instead of CONSTANT information, we will define a circular path.
//	gluLookAt(-30,-30,50,	0,0,0,	0,0,1);

	gluLookAt(cameraRadius*cos(cameraAngle), cameraRadius*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//NOTE: the camera still CONSTANTLY looks at the center
	// cameraAngle is in RADIAN, since you are using inside COS and SIN
	
	
	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects
	//rotate this rectangle around the Z axis
	/*
	glPushMatrix();{	//STORE the state
		glRotatef(rectAngle,	0,0,1);	// in DEGREE
		//a simple rectangles
		glColor3f(0.3, 0.4, 0.8);
		glBegin(GL_QUADS);{
			glVertex3f(0,0,30);
			glVertex3f(10,0,30);
			glVertex3f(10,20,30);
			glVertex3f(0,20,30);
		}glEnd();

		///lets draw another one in the XY plane --- i.e. Z = 0
		glColor3f(0.15, 0.2, 0.4);
		glBegin(GL_QUADS);{
			glVertex3f(0,0,0);
			glVertex3f(10,0,0);
			glVertex3f(10,20,0);
			glVertex3f(0,20,0);
		}glEnd();
	}glPopMatrix();		//the effect of rotation is not there now.

*/

	if(lightSwitch==1){
		glEnable(GL_LIGHTING);
		light();		
	}
	else{
		glDisable(GL_LIGHTING);
	}

	// white board front
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureWhiteBoard);

	glPushMatrix();
//			glColor3f(.5, .5, .5);
			glColor3f(.8, .8, .8);

			glTranslatef( 99, -27.3, 55);
			glScalef( 4, 4, 4);
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);{
			glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
			glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
			glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
			glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
			}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
// end whiteBoard

	// back wallTexture
		// back wall left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			glColor4f(9, 3, 3, .75);
	glColor3f(0.5, .5, 0.5);

			glTranslatef( -100, -100, 70);
			glScalef(100, 5, 6);
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

		// backwall right
		glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			
			glColor3f(0.5, .5, 0.5);

			glTranslatef( -100, 0, 70);
			glScalef(100, 5, 6);
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

// end backWallTexture


// Front wall texture front face taken from back wall wall texture
		glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			glColor4f(9, 3, 3, .75);
glColor3f(0.5, .5, 0.5);
			glTranslatef( 100, -100, 70);
			
			glScalef(100, 5, 6);
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			
			glColor3f(0.5, .5, 0.5);
			glTranslatef( 100, 0, 70);
			
			glScalef(100, 5, 6);
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	// end front wall

	// door texture
		// inner side on the back wall
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textureDoor);

		glPushMatrix();
			glColor3f(.8, .8, .8);

			glTranslatef( -99.1, -90, 55);
			
			glScalef(5, 1, 4.5);
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);{
			glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
			glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
			glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
			glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
			}glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		//outer side on the backwall
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textureDoor);

		glPushMatrix();
			glColor3f(.8, .8, .8);
			glTranslatef( -100.1, -90, 55);
			
			glScalef(5, 1, 4.5);
			glRotatef(90, 0, 1, 0);
			glBegin(GL_QUADS);{
			glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
			glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

// end door texture


	
// left wall
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			glColor3f(0.5, .5, 0.5);
			glTranslatef( -100, -100, 0);
			
			glScalef(10, 5, 3.5);
			glRotatef(90, 1, 0, 0);  // x so left side
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

// left wall
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			glColor4f(9, 3, 3, .75);
glColor3f(0.5, .5, 0.5);
			glTranslatef( 0, -100, 0);
			
			glScalef(10, 5, 3.5);
			glRotatef(90, 1, 0, 0);  // x so left side
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

/*
// middle wall divider side face taken from left wall texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			glColor4f(9, 3, 3, .75);
			glTranslatef( -100, 0, 0);
			
			glScalef(10, 5, 3);
			glRotatef(90, 1, 0, 0);  // x so left side
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
// end middle wall texture
*/
// right wall texture
		glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			glColor4f(9, 3, 3, .75);
	glColor3f(0.5, .5, 0.5);

			glTranslatef( -100, 100, 0);
			
			glScalef(10, 5, 3.5);
			glRotatef(90, 1, 0, 0);  // x so left side
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

		glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureBackWallLeft);
	glPushMatrix();
			glColor4f(9, 3, 3, .75);
	glColor3f(0.6, .6, 0.6);
glColor3f(0.5, .5, 0.5);
			glTranslatef( 0, 100, 0);
			
			glScalef(10, 5, 3.5);
			glRotatef(90, 1, 0, 0);  // x so left side
			glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0);	glVertex3f(0,0,0);
		glTexCoord2f(0.0,1.0);	glVertex3f(10,0,0);
		glTexCoord2f(1.0,1.0);	glVertex3f(10,20,0);
		glTexCoord2f(1.0,0.0);	glVertex3f(0,20,0);
		}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// end right wall texture
	
	// Floor Texture
	//an square field
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glPushMatrix();
	glColor3f(0.3, .3, 0.3);
	glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0); glVertex3f(-100,-100,0);
		glTexCoord2f(0.0,1.0); glVertex3f(100,-100,0);
		glTexCoord2f(1.0,1.0); glVertex3f(100,100,0);
		glTexCoord2f(1.0,0.0); glVertex3f(-100,100,0);
	}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// ceiling texture
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureCeiling);
	glPushMatrix();
	glTranslatef(0, 0, 70);
	glColor3f(.6, .61, .6);
	glBegin(GL_QUADS);{
		glTexCoord2f(0.0,0.0); glVertex3f(-100,-100,0);
		glTexCoord2f(0.0,1.0); glVertex3f(100,-100,0);
		glTexCoord2f(1.0,1.0); glVertex3f(100,100,0);
		glTexCoord2f(1.0,0.0); glVertex3f(-100,100,0);
	}glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	//some gridlines along the field
	int i;

	//WILL draw grid IF the "canDrawGrid" is true:

	if(canDrawGrid == true){
		glColor3f(0.3, 0.3, 0.3);	//grey
		glBegin(GL_LINES);{
			for(i=-10;i<=10;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -100, 0);
				glVertex3f(i*10,  100, 0);

				//lines parallel to X-axis
				glVertex3f(-100, i*10, 0);
				glVertex3f( 100, i*10, 0);
			}
		}glEnd();
	}

	// draw the two AXES
	glColor3f(.3, .3, .3);	//ash
	glBegin(GL_LINES);{
		//Y axis
		glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0,  150, 0);

		//X axis
		glColor3f(.3, .3, .3);	//100% white
		glVertex3f(-150, 0, 0);
		glVertex3f( 150, 0, 0);
	}glEnd();


	//FOUR spheres

	//glColor3f(0,0.3,0.8);	//blue

/*
	glPushMatrix();{
		glTranslatef(50,50,30);
		glutWireSphere(10, 20, 20);	//radius, slices(XY), stacks(Z) -- like earth
	}glPopMatrix();


	glPushMatrix();{
		glTranslatef(72,0,13); // x = if plus come to front
		glRotatef(45, 1,1,1);
		glutWireSphere(2, 20, 20);
	}glPopMatrix();

	glColor3f(0.8,0.3,0);
	glPushMatrix();{
		glTranslatef(-50,-50,30);
		glScalef(2, 3, 0.5);
		glutWireSphere(10, 20, 20);
	}glPopMatrix();

	glColor3f(0.7,0.8,0);
	glPushMatrix();{
		glRotatef(45, 1,1,1);
		glScalef(2, 2, 0.5);
		glTranslatef(-50,-50,30);
		glutWireSphere(10, 20, 20);
	}glPopMatrix();
*/

	
	frontWall();
	//floor();
	backWall();
	rightWall();
	leftWall();

	// teacher table
	glPushMatrix();
		glTranslatef(140.0, 0.0, -3.0 );
		//glScalef( 1.1, 1.1, 1.1 );
		teacherTable();
	glPopMatrix();

	// Start: chair table row Middle, Right, Left
	
	// Middle Row: call chairTableMiddleRow() func
	glPushMatrix();
	
		chairTableMiddleRow();
	glPopMatrix();
	// end middle row

	// chairTable right side row : call chairTableMiddleRow() func and make it right side row
	glPushMatrix();
		glTranslatef(0.0, 20.0, 0.0 );
		chairTableMiddleRow();
	glPopMatrix();
	// end right row

	// chairTable right side row 2: call chairTableMiddleRow() func and make it right side row
	glPushMatrix();
		glTranslatef(0.0, 40.0, 0.0 );
		chairTableMiddleRow();
	glPopMatrix();
	// end right row

	// chairTable right side row 3: call chairTableMiddleRow() func and make it right side row
	glPushMatrix();
		glTranslatef(0.0, 60.0, 0.0 );
		chairTableMiddleRow();
	glPopMatrix();
	// end right row

	// chair table left side row
	glPushMatrix();
		glTranslatef(0.0, -20.0, 0.0 );
		chairTableMiddleRow();
	glPopMatrix();
	// end left row

	// chair table left side row 2
	glPushMatrix();
		glTranslatef(0.0, -40.0, 0.0 );
		chairTableMiddleRow();
	glPopMatrix();
	// end left row

		// chair table left side row 3
	glPushMatrix();
		glTranslatef(0.0, -60.0, 0.0 );
		chairTableMiddleRow();
	glPopMatrix();
	// end left row

	//////// ------ NOTE ---- ORDER matters. compare last two spheres!

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Camera

	cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!
	
	//codes for any changes in Models
	
	rectAngle -= 1;

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':	//reverse the rotation of camera
			cameraAngleDelta = -cameraAngleDelta;
			break;

		case '2':	//increase rotation of camera by 10%
			cameraAngleDelta *= 1.1;
			break;

		case '3':	//decrease rotation
			cameraAngleDelta /= 1.1;
			break;

		case '8':	//toggle grids
			canDrawGrid = 1 - canDrawGrid;
			break;

		case 'l':
			lightSwitch = 1;
			break;
		case 'L':
			lightSwitch = 1;
			break;

		case 'k':
			lightSwitch = 0;
			break;
		case 'K':
			lightSwitch = 0;
			break;

		case 27:	//ESCAPE KEY -- simply exit
			exit(0);
			break;

		default:
			break;
	}

   if (key==114) { // r = 114, red
        dlr = 1.0; //change light to red
        dlg = 1.0;
        dlb = 1.0;
    }
   if (key==103) { // g = 103, green
        dlr = 0.0; //change light to green
        dlg = 1.0;
        dlb = 0.0;
    }
  
    if (key==98) { // b = 98, blue
        dlr = 0.0; //change light to blue
        dlg = 0.0;
        dlb = 1.0;
    }
    if (key==87) { // w = 87
        ly += 10.0; //move the light up
    }
    if (key==115) { // s = 115
        ly -= 10.0; //move the light down
    }
    if (key==97) { // a = 97
        lx -= 10.0; //move the light left
    }
    if (key==98) { // d = 98
        lx += 10.0; //move the light right
    }
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			cameraRadius += 10;
			break;
		case GLUT_KEY_UP:		// up arrow key
			if(cameraRadius > 10)
				cameraRadius -= 10;
			break;

		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_LEFT:
			break;

		case GLUT_KEY_PAGE_UP:
			cameraHeight += 10;
			break;
		case GLUT_KEY_PAGE_DOWN:
			cameraHeight -= 10;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				cameraAngleDelta = -cameraAngleDelta;	
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}


void init(){
	//codes for initialization
	cameraAngle = 0;	//// init the cameraAngle
	cameraAngleDelta = 0.0005;
	rectAngle = 0;
	canDrawGrid = true;
	cameraHeight = 40;
	cameraRadius = 120;

	//clear the screen
	glClearColor(BLACK, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);
	
	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance


		cubeList = glGenLists(1);
	glNewList(cubeList, GL_COMPILE);
	glutSolidCube(1.0);
	glEndList();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(1349, 700);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);	//Depth, Double buffer, RGB color

	glutCreateWindow("Author: Mahbub - A - Rob");
	Texture();
	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
