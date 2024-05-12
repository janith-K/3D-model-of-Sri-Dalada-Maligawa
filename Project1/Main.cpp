#include<GL/glut.h>
#include<math.h>
#include<SOIL2.h>
#include <stdio.h>

#include"codes.h"


unsigned char* image;
GLuint tex1;
float width, height;

#define IMAGE_ROWS 64      // Texture image rows and columns
#define IMAGE_COLS 64

GLubyte imageData[IMAGE_ROWS][IMAGE_COLS][3];
//GLubyte image;
GLfloat skyTextureId;

void loadTexture(const char* filename) {
	// Generate a texture ID
	glGenTextures(1, &tex1);

	// Bind the texture
	glBindTexture(GL_TEXTURE_2D, tex1);

	// Set texture parameters (optional)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	// Load the image data into the texture
	int width, height, channels;
	unsigned char* image = SOIL_load_image(filename, &width, &height, &channels, SOIL_LOAD_RGBA);

	if (image) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		SOIL_free_image_data(image); // Free the image data after it's loaded into the texture
	}
	else {
		// Handle error loading the image
		fprintf(stderr, "Error loading texture: %s\n", SOIL_last_result());
	}

	// Unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);
}





//variables to move the outermost frame(to move all the rendered environmet)
GLfloat movex = 0.0f;
GLfloat movey = 0.0f;
GLfloat movez = 0.0f;

//varua+iables to rotate the outermost frame
GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;

//variables to move the camera
GLfloat camX = 0.0f;
GLfloat camY = 0.0f;
GLfloat camZ = 0.0f;

//constexpr float PI = 3.14159265358979323846;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	

	

}



void drawGrid() {
	GLfloat step = 1.0f;
	GLint line;

	glBegin(GL_LINES);
	for (line = -100; line <= 100; line += step) {
		glVertex3f(line, -0.0, 100);
		glVertex3f(line, -0.0, -100);

		glVertex3f(100, -0.0, line);
		glVertex3f(-100, -0.0, line);
	}
	glEnd();
}

void drawAxes() {

	glBegin(GL_LINES);

	glLineWidth(1.5);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-200, 0, 0);
	glVertex3f(200, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -200, 0);
	glVertex3f(0, 200, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -200);
	glVertex3f(0, 0, 200);

	glEnd();
}











void setLighting() {
	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[] = { 0.0, 1.0, -.5, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

void drawSkyWithTexture() {
	loadTexture("sky.jpg");
	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(450.0f, 150.0f, 450.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(450.0f, 150.0f, -450.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-450.0f, 150.0f, -450.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-450.0f, 150.0f, 450.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void drawBackSkyWithTexture() {
	loadTexture("sky.jpg");
	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-400.0f, 150.0f, -400.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(400.0f, 150.0f, -400.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(400.0f, 0.0f, -400.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-400.0f, 0.0f, -400.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void drawRightSkyWithTexture() {
	loadTexture("sky.jpg");
	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(400.0f, 150.0f, -400.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(400.0f, 150.0f, 400.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(400.0f, 0.0f, 400.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(400.0f, 0.0f, -400.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void drawLeftSkyWithTexture() {
	loadTexture("sky.jpg");
	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-400.0f, 150.0f, -400.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-400.0f, 150.0f, 400.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-400.0f, 0.0f, 400.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-400.0f, 0.0f, -400.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void drawGrassWithTexture() {
	loadTexture("grass.jpg");

	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-450, -7, 30);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(450, -7, 30);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(450, -7, 400);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-450, -7, 400);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void drawGroundWithTexture() {
	loadTexture("gray.jpg");

	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-450, -7, 30);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(450, -7, 30);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(450, -7, -450);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-450, -7, -450);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void drawWaterWithTexture() {
	loadTexture("water.jpg");

	glBindTexture(GL_TEXTURE_2D, tex1);
	glBegin(GL_QUADS);

	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(100, -6.95, 20);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(100, -6.95, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-200, -6.95, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-200, -6.95, 20);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}





void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	// camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
	gluLookAt(0.0f + camX, 2.0f + camY, 10.0f + camZ, 0, 0, 0, 0, 1, 0);

	glTranslatef(movex, movey, movez);
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	setLighting();
	
	//Draw a grid on the xz plane
	glColor3f(1, 1, 1);
	
	drawSkyWithTexture();
	drawBackSkyWithTexture();
	drawRightSkyWithTexture();
	drawLeftSkyWithTexture();
	drawGroundWithTexture();
	drawGrassWithTexture();
	drawWaterWithTexture();
	complete_structure();
	
	glPopMatrix();
	glFlush();

	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Define the Perspective projection frustum 
	// (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
	gluPerspective(120.0, aspect_ratio, 1.0, 700.0);

}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 1;
	if (key == GLUT_KEY_DOWN)
		camY -= 1;
	if (key == GLUT_KEY_LEFT)
		rotY += 5;
	if (key == GLUT_KEY_RIGHT)
		rotY -= 5;


	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'w')
		movez += 0.5f;
	if (key == 's')
		movez -= 0.5f;
	if (key == 'd')
		movex += 0.5f;
	if (key == 'a')
		movex -= 0.5f;
	if (key == 'e')
		movey += 0.5f;
	if (key == 'q')
		movey -= 0.5f;

	glutPostRedisplay();

}

int main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sri Dalada Maligawa 3D");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}