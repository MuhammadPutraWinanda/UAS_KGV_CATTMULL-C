#include <glut.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

float PI = 3.14;
int tpKapalX = -220, tpKapalY = -190, tpPesawatX = -220, tpPesawatY = 200;
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
	case 'W':
		if (tpKapalY <= -175) {
			tpKapalY = tpKapalY + 10;
		}
		break;
	case 'a':
	case 'A':
		if (tpKapalX >= -220) {
			tpKapalX = tpKapalX - 10;
		}
		break;
	case 's':
	case 'S':
		if (tpKapalY >= -175) {
			tpKapalY = tpKapalY - 10;
		}
		break;
	case 'd':
	case 'D':
		if (tpKapalX <= 220) {
			tpKapalX = tpKapalX + 10;
		}
		break;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (tpPesawatX >= -220) {
			tpPesawatX -= 10;
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		if (tpPesawatX <= 240) {
			tpPesawatX += 10;
		}
	}
}


void write(float x, float y, float z, void* font, const char* string)
{
	glColor3f(1, 1, 1);
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}
void background() {
	// koordinat untuk awal pegunungan
	glBegin(GL_POLYGON);
	glColor3ub(102, 255, 102);
	glVertex2i(-320, -60);
	glVertex2i(-320, 100);
	glVertex2i(-320, 20);
	glVertex2i(-50, 140);
	glVertex2i(200, -60);
	glVertex2i(240, 120);
	glVertex2i(320, 20);
	glVertex2i(320, -60);
	glEnd();


	//untuk air laut
	glBegin(GL_POLYGON);
	glColor3ub(36, 72, 199);
	glVertex2i(-320, -120);
	glVertex2i(320, -120);
	glVertex2i(320, -320);
	glVertex2i(-320, -320);
	glEnd();

	//pasir
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 224);
	glVertex2i(-320, -60);
	glVertex2i(320, -60);
	glVertex2i(320, -120);
	glVertex2i(-320, -120);
	glEnd();

	glFlush();
}

void pesawat() {

	glBegin(GL_POLYGON);
	glColor3ub(61, 70, 106);
	glVertex2i(tpPesawatX - 21, tpPesawatY - 2);
	glVertex2i(tpPesawatX - 70, tpPesawatY - 15);
	glVertex2i(tpPesawatX + 20, tpPesawatY - 5);
	glVertex2i(tpPesawatX + 80, tpPesawatY + 8);
	glVertex2i(tpPesawatX + 40, tpPesawatY + 25);
	glVertex2i(tpPesawatX - 70, tpPesawatY + 20);
	glVertex2i(tpPesawatX - 100, tpPesawatY + 45);
	glVertex2i(tpPesawatX - 80, tpPesawatY + 3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2i(tpPesawatX + 40, tpPesawatY + 13);
	glVertex2i(tpPesawatX + 58, tpPesawatY + 15);
	glVertex2i(tpPesawatX + 40, tpPesawatY + 20);
	glVertex2i(tpPesawatX + 25, tpPesawatY + 19);
	glEnd();
	glFlush();

}

//untuk gambar matahari
void matahari() {
	float xp = 50, yp = 300, r = 80, n = 1000, a, x, y;
	glColor3ub(255, 255, 0);
	glBegin(GL_POLYGON);
	a = 6.28 / n; //a = nilai 6.28 dibagi banyak segi
	for (int i = 0; i < n; i++) {
		x = xp + r * cos(i * a);
		y = yp + r * sin(i * a);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}


// koordinat untuk menggambar kapal
void kapal() {

	glBegin(GL_POLYGON);
	glColor3ub(200, 0, 0);
	glVertex2i(tpKapalX - 95, tpKapalY);
	glVertex2i(tpKapalX - 95, tpKapalY - 50);
	glVertex2i(tpKapalX + 80, tpKapalY - 50);
	glVertex2i(tpKapalX + 130, tpKapalY);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2i(tpKapalX + 60, tpKapalY);
	glVertex2i(tpKapalX - 60, tpKapalY + 20);
	glVertex2i(tpKapalX - 50, tpKapalY + 40);
	glVertex2i(tpKapalX - 60, tpKapalY + 30);
	glVertex2i(tpKapalX - 60, tpKapalY);
	glEnd();
	glFlush();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	kapal();
	matahari();
	pesawat();

	if (tpKapalX >= 220) write(-200, -125, 0, GLUT_BITMAP_HELVETICA_18, "Kendaraan Telah Sampai :)");
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("UAS");
	glClearColor(0.62, 0.87, 0.89, 1);
	gluOrtho2D(-320, 320, -320, 320);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return EXIT_SUCCESS;
}