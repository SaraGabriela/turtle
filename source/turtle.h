#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <stdio.h>
#include <vector>


using namespace std;

class turtle
{
private:
	bool pen;
	GLdouble dir;
	GLdouble x;
	GLdouble y;
	GLdouble newx;
	GLdouble newy;
	float r;
	float g;
	float b;

	class punto {
	private:
		GLdouble x;
		GLdouble y;
		bool flag;
	public:
		punto(GLdouble _x= 0, GLdouble _y=0, bool _f=0) {
			x = _x;
			y = _y;
			flag = _f;
		}
		GLdouble getX() {
			return x;
		}
		GLdouble getY() {
			return y;
		}
		bool getF() {
			return flag;
		}
	};

	vector <punto *> vPuntos;
	
	static turtle * instance;

	static void auxDisplayWrap();
	virtual void auxDisplay();
	void myInit(); //Caracteristicas por default
public:
	static void setInstance(turtle * t);
	turtle();
	~turtle();
	void startTurtle();
	void display(); //Dibuja en ventana
	void forward(GLdouble dis);
	void left(GLdouble angle);
	void right(GLdouble angle);
	void penup();
	void pendown();
	void pencolor(float _f, float _g, float _b);
	void go(GLdouble dx, GLdouble dy);

};

/*
class turtleDo
{
private:
	static void displayT();
public:
	turtleDo();
	static turtle * T;
	void draw();
	void Tstart();
	void Tpenup();
	void Tpendown();
	void Tforward(GLdouble d);
};*/
