#include<GL/glut.h>
#include<math.h>

float pi = 3.14159;
const float PI = 3.14159265358979323846;
    // Adjust the amplitude as needed

void pillarForArch(float x, float y, float z) {

	//glPushMatrix();
	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glColor3f(0.7, 0.7, 0.7);
	glScalef(x, y, z);
	glutSolidCube(1.0);
	//glPopMatrix();


}

void drawDisk(double radius, int n) {

		GLfloat qaBlack[] = { 0.0, 0.0, 0.0 ,1.0 };
		GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0 };

		GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
		GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

		glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBlack);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

		
	double angle = 0;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	for (int c = 0; c <= n; c++) {
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex2d(x, y);
		angle = angle + ((2 * pi) / n);
	}
	glEnd();

}

void drawSinWave(float WAVE_LENGTH,float AMPLITUDE,float height) {

	GLfloat qaBlack[] = { 0.0, 0.0, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);


	const int NUM_POINTS = 200;
	//const float WAVE_LENGTH = 8.0f; // Adjust the wavelength as needed
	//const float AMPLITUDE = 2.5f;
	//height =5
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < NUM_POINTS; ++i) {
		float x = static_cast<float>(i) / NUM_POINTS * WAVE_LENGTH;
		float y = AMPLITUDE * sin(2 * PI * x / WAVE_LENGTH);
		glVertex3f(x, y,0.0);
		glVertex3f(x, -height, 0);
		//glVertex3f(x, y, -1);

	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < NUM_POINTS; ++i) {
		float x = static_cast<float>(i) / NUM_POINTS * WAVE_LENGTH;
		float y = AMPLITUDE * sin(2 * PI * x / WAVE_LENGTH);
		glVertex3f(x, y, 0.0);
		glVertex3f(x, y, -2);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < NUM_POINTS; ++i) {
		float x = static_cast<float>(i) / NUM_POINTS * WAVE_LENGTH;
		float y = AMPLITUDE * sin(2 * PI * x / WAVE_LENGTH);
		glVertex3f(x, y, -2);
		glVertex3f(x, -height, -2);
	}
	glEnd();

	glPushMatrix();
	glColor3f(0.0, 0, 0);
	glTranslatef(2, 1.5, 0.01);
	drawDisk(0.4, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0, 0);
	glTranslatef(1, 0, 0.01);
	drawDisk(0.4, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0, 0);
	glTranslatef(3, 0, 0.01);
	drawDisk(0.4, 32);
	glPopMatrix();


	glFlush();
}

void drawCloudWall(int times, float wavelength, float amplitude, float height) {
	for (int i = 0; i < times; i++) {
		drawSinWave(wavelength, amplitude, height);
		glTranslatef(7.98, 0, 0);
		//drawSinWave();
	}
	
}

void drawCylinder(float radius, float height) {

	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	float angle = 0;
	float num = 24;
	//glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= num; i++) {
		float x = radius * cos(angle);
		float z = radius * sin(angle);
		glVertex3f(x, 0, z);
		glVertex3f(x, height, z);
		angle += (2 * pi) / num;
	}
	glEnd();
}

void drawSphere() {

	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGold);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGold);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glutSolidSphere(0.5, 100, 100);

}

void drawLamp() {


	glPushMatrix();
	drawCylinder(0.5, 6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 6, 0);
	pillarForArch(2.5, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.1, 6.5, 0);
	drawSphere();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.1, 6.5, 0);
	drawSphere();
	glPopMatrix();

	

}

void drawRoofBrown() {

	GLfloat qaBrown[] = { .150, 0.075, 0.0,1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0 ,1.0};

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaBrown);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBrown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(12.5, 0, 7.5);
	glVertex3f(-12.5, 0, 7.5);
	glVertex3f(-10, 1.5, 5);
	glEnd();
	

	
	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(12.5, 0, 7.5);
	glVertex3f(12.5, 0, -7.5);
	glVertex3f(10, 1.5, -5);
	glEnd();
	

	
	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, -5);
	glVertex3f(12.5, 0, -7.5);
	glVertex3f(-12.5, 0, -7.5);
	glVertex3f(-10, 1.5, -5);
	glEnd();
	

	
	glBegin(GL_POLYGON);
	glVertex3f(-10, 1.5, -5);
	glVertex3f(-12.5, 0, -7.5);
	glVertex3f(-12.5, 0, 7.5);
	glVertex3f(-10, 1.5, 5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(7.5, 5, 0);
	glVertex3f(-7.5, 5, 0);
	glVertex3f(-10, 1.5, 5);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(10, 1.5, -5);
	glVertex3f(7.5, 5, 0);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, -5);
	glVertex3f(-10, 1.5, -5);
	glVertex3f(-7.5, 5, 0);
	glVertex3f(7.5, 5, 0);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(-10, 1.5, -5);
	glVertex3f(-10, 1.5, 5);
	glVertex3f(-7.5, 5, 0);
	glEnd();
	
}

void drawRoofGold() {

	glPushMatrix();
	GLfloat qaGold[] = { 1.0, 0.843, 0.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGold);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGold);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(12.5, 0, 7.5);
	glVertex3f(-12.5, 0, 7.5);
	glVertex3f(-10, 1.5, 5);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(12.5, 0, 7.5);
	glVertex3f(12.5, 0, -7.5);
	glVertex3f(10, 1.5, -5);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, -5);
	glVertex3f(12.5, 0, -7.5);
	glVertex3f(-12.5, 0, -7.5);
	glVertex3f(-10, 1.5, -5);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(-10, 1.5, -5);
	glVertex3f(-12.5, 0, -7.5);
	glVertex3f(-12.5, 0, 7.5);
	glVertex3f(-10, 1.5, 5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(7.5, 5, 0);
	glVertex3f(-7.5, 5, 0);
	glVertex3f(-10, 1.5, 5);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, 5);
	glVertex3f(10, 1.5, -5);
	glVertex3f(7.5, 5, 0);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(10, 1.5, -5);
	glVertex3f(-10, 1.5, -5);
	glVertex3f(-7.5, 5, 0);
	glVertex3f(7.5, 5, 0);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(-10, 1.5, -5);
	glVertex3f(-10, 1.5, 5);
	glVertex3f(-7.5, 5, 0);
	glEnd();

}




void DrawWall(double x,double y)
{

	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0};
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0};

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
	
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex3f(x / 2,y,0);
	glVertex3f(-x / 2,y,0);
	glVertex3f(-x / 2,0,0);
	glVertex3f(x / 2,0,0);
	glEnd();


}

void drawStrcture_1() {

	glPushMatrix();
	glTranslatef(0, 0, 5);
	DrawWall(20, 15);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	DrawWall(20, 15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(.150, 0.075, 0.0);
	glTranslatef(0, 13.5, 0);
	drawRoofBrown();
	glPopMatrix();

	glPushMatrix();
	glColor3f(.150, 0.075, 0.0);
	glTranslatef(0, 7.5, 0);
	drawRoofBrown();
	glPopMatrix();
	

	//stils on the front
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-9, 1, 5);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-7, 1, 5);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-5, 1, 5);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-3, 1, 5);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-1, 1, 5);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(1, 1, 5);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(3, 1, 5);
	drawCylinder(0.25, 7.5);
	glPopMatrix();






	//stils on the side
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(10, 1, 4);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(10, 1, 2);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(10, 1, 0);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(10, 1, -2);
	drawCylinder(0.25, 7.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(10, 1, -4);
	drawCylinder(0.25, 7.5);
	glPopMatrix();



}

void drawStrcture_2() {

	glPushMatrix();
	glTranslatef(0, 0, 5);
	DrawWall(20, 17);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	DrawWall(20, 17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 17);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 15.5, 0);
	glColor3f(.150, 0.075, 0.0);
	drawRoofBrown();
	glPopMatrix();

	// 2 windows on the side
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(10, 9, 2);
	glScalef(0.5, 1, 1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(10, 9, -2);
	glScalef(0.5, 1, 1);
	glutSolidCube(1.0);
	glPopMatrix();




}

void drawStrcture_3() {

	glPushMatrix();
	glTranslatef(0, 0, 5);
	DrawWall(20, 10);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	DrawWall(20, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 8.5, 0);
	glColor3f(.150, 0.075, 0.0);
	drawRoofBrown();
	glPopMatrix();

	//window slits along the lenth
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(9, 7, 5);
	glScalef(0.7, 1.2, 0.05);

	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(7, 7, 5);
	glScalef(0.7, 1.2, 0.05);

	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(5, 7, 5);
	glScalef(0.7, 1.2, 0.05);

	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(3, 7, 5);
	glScalef(0.7, 1.2, 0.05);

	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(1, 7, 5);
	glScalef(0.7, 1.2, 0.05);

	glutSolidCube(1.0);
	glPopMatrix();
}

void drawStrcture_4() {

	glPushMatrix();
	glTranslatef(0, 0, 5);
	DrawWall(10, 27);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(5, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	DrawWall(10, 27);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 27);
	glPopMatrix();

	glPushMatrix();
	glColor3f(.150, 0.075, 0.0);
	glTranslatef(0, 25.5, 0);
	glScalef(0.5, 1, 1);
	drawRoofBrown();
	
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-3, 24, 5);
	glScalef(2, 2, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(3, 24, 5);
	glScalef(2, 2, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();
	
}

void drawStrcture_5() {

	glPushMatrix();
	glTranslatef(0, 0, 5);
	DrawWall(20, 32);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -5);
	DrawWall(20, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10, 0, 0);
	glRotatef(90, 0, 1, 0);
	DrawWall(10, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 30.5, 0);
	glColor3f(.150, 0.075, 0.0);
	drawRoofBrown();
	glPopMatrix();
}

void structure_6() {


	//glColor3f(1.0, 0.843, 0.0);
	glTranslatef(0, 22.5, 0);
	drawRoofGold();
	glPopMatrix();

}




void drawDoor() {
	//glRotatef(90, 0, 1, 0);
	float x = 0.25;
	glColor3f(1, 1, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0.75, 0);
	glVertex3f(-x, 0.75, 0);
	glVertex3f(-x, 0, 0);
	glEnd();

	glTranslatef(0, 0.75, 0);
	drawDisk(0.25, 32);
	glPopMatrix();



}

void drawDoorsInOctagon(float radius) {
	int sides = 8;

	for (int i = 0; i <= sides; ++i) {
		float angle = 2.0f * 3.1415926f * i / sides + 22.5;
		float x = radius * cosf(angle);
		float z = radius * sinf(angle);

		glPushMatrix();
		glTranslatef(x, 0, z);
		glRotatef(90+45*i, 0, 1, 0);
		drawDoor();
		glPopMatrix();

	}
	glEnd();
}



void drawCone(float radius, float height) {

	GLfloat qaWhite[] = { 1.0,1.0,1.0,1.0 };
	GLfloat qaBrown[] = { 0.478,0.3098,0.145,1.0 };
	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	int numSegments = 8;
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaBrown);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBrown);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, height, 0.0f); // Apex of the cone
	for (int i = 0; i <= numSegments; ++i) {
		float theta = (2.0f * pi * float(i)) / float(numSegments);
		float x = radius * cosf(theta);
		float z = radius * sinf(theta);
		glVertex3f(x, 0.0f, z);
	}
	glEnd();
}

void drawOctagonOuter(float radius, float height) {
	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
	
	//glRotatef(22.5, 0, 1, 0);
	int sides = 8;

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; ++i) {
		float angle = 2.0f * 3.1415926f * i / sides;
		float x = radius * cosf(angle);
		float z = radius * sinf(angle);
		glVertex3f(x, 0, z);
		glVertex3f(x, height, z);


	}
	glEnd();
}

void drawOctagonInner(float radius, float height) {
	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 0.8, 0.8 ,0.8,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	//glRotatef(22.5, 0, 1, 0);
	int sides = 8;

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; ++i) {
		float angle = 2.0f * 3.1415926f * i / sides;
		float x = radius * cosf(angle);
		float z = radius * sinf(angle);
		glVertex3f(x, 0, z);
		glVertex3f(x, height, z);


	}
	glEnd();
}

void drawstils(float radius, float height) {

	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0 ,1.0,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
	int sides = 8;

	for (int i = 0; i <= sides; ++i) {
		float angle = 2.0f * 3.1415926f * i / sides;
		float x = radius * cosf(angle);
		float z = radius * sinf(angle);

		glPushMatrix();
		glTranslatef(x, height, z);
		drawCylinder(0.25, 2.0);
		glPopMatrix();

	}
	glEnd();
}

void drawOctagonStructure() {

	//glRotatef(22.5, 0, 1, 0);
	glPushMatrix();
	glColor3f(.150, 0.075, 0.0);
	glTranslatef(0, 10, 0);
	drawCone(3.0, 3.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(.150, 0.075, 0.0);
	glTranslatef(0, 7, 0);
	drawCone(9.0, 5.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	drawOctagonOuter(9.0, 5.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, -4, 0);
	drawOctagonOuter(11.0, 6.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.255, 0.253, 0.208);
	glTranslatef(0.0, 5.0, 0.0);
	drawOctagonInner(6.5, 3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);

	drawstils(8.5, 5);
	glPopMatrix();

	
}



void ex_1() {
	
	glPushMatrix();
	glTranslatef(-12, 0, -17);
	glScalef(3, 1, 1.5);
	drawStrcture_1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-6, 0, -25);
	glScalef(3, 1, 1.5);
	drawStrcture_2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(10, 0, -35);
	glScalef(1, 1.6, 1);
	glRotatef(90, 0, 1, 0);
	drawStrcture_3();
	glPopMatrix();

	
	//6
	/*glPushMatrix();
	glTranslatef(-2, 0, -35);
	glRotatef(90, 0, 1, 0);
	structure_6();
	glPopMatrix()*/;



	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(10, 0, -50);
	drawStrcture_4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12, 0, -60);
	glScalef(3, 1, 1.5);
	drawStrcture_5();
	glPopMatrix();

	glTranslatef(5, 0, 0);
	drawOctagonStructure();


}

void drawWalk(){
		
	glPushMatrix();

	GLfloat qaGold[] = { 1.0, 0.843, 0.0 ,1.0 };
	GLfloat qaWhite[] = { 0.8, 0.8 ,0.8,1.0 };

	GLfloat qaLowAmbient[] = { 0.2,0.2,0.2,1.0 };
	GLfloat qaFullAmbient[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glBegin(GL_POLYGON);
	glVertex3f(-2, -6.95, 20);
	glVertex3f(7, -6.95, 20);
	glVertex3f(7, -6.95, 100);
	glVertex3f(-2, -6.95, 100);
	glEnd();
	glPopMatrix();

	

}

void walkWithLamp() {
	for (float i = 30; i < 100; i += 10) {
		glPushMatrix();
		glTranslatef(7, -6.95, i);
		drawLamp();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2, -6.95, i);
		drawLamp();
		glPopMatrix();
	}
	
}



void steps() {

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, 2, 4);
	glScalef(4, 4, 12);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(0, 0,10 );
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 4, 0);
	glVertex3f(-2, 0, 0);
	glVertex3f(-2, 0, 5);
	glVertex3f(2, 0, 5);
	glVertex3f(2, 4, 0);
	glVertex3f(2, 0, 0);
	glVertex3f(2, 0, 5);

	glEnd();
}

void arch() {

	glPushMatrix();
	glTranslatef(7.5, 10, 7.5);
	pillarForArch(5, 20, 5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.5, 10, -7.5);
	pillarForArch(5, 20, 5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.5, 10, 7.5);
	pillarForArch(5, 20, 5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.5, 10, -7.5);
	pillarForArch(5, 20, 5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 20, 0);
	pillarForArch(20, 5, 20);
	glPopMatrix();
}


void complete_structure() {

	//front cloud wall right
	glPushMatrix();
	glTranslatef(-40.0, -5, 20);
	drawCloudWall(18,8,2.5,3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-208.5, -5, 20);
	drawCloudWall(20, 8, 2.5, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100, -5, 20);
	glRotatef(90, 0, 1, 0);
	drawCloudWall(3, 8, 2.5, 3);
	glPopMatrix();
	

	//back cloud wall
	glPushMatrix();
	glTranslatef(-42.5, 0, 0);
	drawCloudWall(19,8,2.5,10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-208.5, 0, 0);
	drawCloudWall(20, 8, 2.5, 10);
	glPopMatrix();

	drawWalk();
	walkWithLamp();

	glScalef(1.5, 1.5, 1.5);
	ex_1();

	

	glPushMatrix();
	glTranslatef(-35.5, -7, 0);
	glScalef(1.5, 1.5, 1);

	steps();
	glPopMatrix();

	
	glTranslatef(-35.5, -3, 3);
	glScalef(0.25, 0.4, 0.5);
	arch();
	

	
}