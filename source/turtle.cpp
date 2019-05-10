/** @file turtle.cpp
@author Sara Diaz Oporto
@version Revision 1.1
@brief Clase turtle que permite realizar graficos con un comportamiento similar a turtle python.
*/

#include "turtle.h"

turtle * turtle::instance = 0;
void turtle::setInstance(turtle * t) {
	instance = t;
}
turtle::turtle()
{
	pen = 0;
	dir = 0;
	vPuntos.push_back(new punto(0, 0, 0));
	x = y = r = g = b = 0;

}


turtle::~turtle()
{
	for (punto * p : vPuntos) {
		delete p;
	}
}

void turtle::forward(GLdouble dis)  // Move forward; draw if pen is down
{
	GLdouble Pi = 3.1415926535897932384626433832795;
	if (dis != 0) {
		dis = dis / 10;
	}

	if (vPuntos.size() > 1) {
		newx = vPuntos[(vPuntos.size()) - 1]->getX() + dis * cos(Pi * dir / 180.0);
		newy = vPuntos[(vPuntos.size()) - 1]->getY() + dis * sin(Pi * dir / 180.0);
	}
	else {
		newx = vPuntos[0]->getX() + dis * cos(Pi * dir / 180.0);
		newy = vPuntos[0]->getY() + dis * sin(Pi * dir / 180.0);
	}

	vPuntos.push_back(new punto(newx, newy, pen));
}

void turtle::go(GLdouble dx, GLdouble dy) {
	dir = 0;
	if (dx != 0) {
		dx = dx / 10;
	}
	if (dy != 0) {
		dy = dy / 10;
	}
	vPuntos.push_back(new punto(dx, dy, pen));
}

void turtle::left(GLdouble angle) {
	dir += angle;
}

void turtle::right(GLdouble angle) {
	left(-1 * angle);
}
void turtle::startTurtle() {
	int argc = 1;
	char *argv[1] = { (char*)"Something" };


	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_ALPHA); 

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Turtle C++");

	//display
}


void turtle::display()
{

	glutDisplayFunc(auxDisplayWrap);
	myInit();
	glutMainLoop();

}


void turtle::myInit() {
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);
	glLineWidth(3.f);
	glOrtho(800, 0, 600, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void turtle::auxDisplayWrap() {
	instance->auxDisplay();
}
void turtle::auxDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
	for (unsigned int i = 1; i < vPuntos.size(); i++) {
		if (vPuntos[i]->getF()) {
			glBegin(GL_LINES);
			glColor3f(r, g, b);
			glVertex2d(vPuntos[i - 1]->getX(), vPuntos[i - 1]->getY());
			glVertex2d(vPuntos[i]->getX(), vPuntos[i]->getY());
			glEnd();
		}
	}
	glFlush();

}


void turtle::penup() {
	pen = 0;
}

void turtle::pendown() {
	pen = 1;
}

void turtle::pencolor(float _r, float _g, float _b) {
	r = _r;
	g = _g;
	b = _b;
}