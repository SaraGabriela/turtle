/** @file turtle.h
@author Sara Diaz Oporto
@version Revision 1.1
@brief Clase turtle que permite realizar graficos con un comportamiento similar a turtle python. 
*/

/**
@mainpage
Turtle Python se usa popularmente como una herramienta para aprender a programar.
Este codigo se asemeja a la tortuga de Python, implementado en c++.
Antes de empezar es necesario incluir la clase turtle e instanciar nuestra tortuga.
La tortuga empieza a dibujar desde la coordenada (0,0)
*/

#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <stdio.h>
#include <vector>

/**
* @class   turtle
* @brief   Clase con funcionalidad similar a la tortuga de Python.
* @detail  Definicion de la funciones usadas en la clase.
*/
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

	/** Crear la turtle.
   *Empieza en la coordenada (0,0)
	*/
	turtle();
	~turtle();
	/** Crear una instancia de turtle.
	*Es necesario para empezar a dibujar
	*/
	static void setInstance(turtle * t);

	/** Crea la ventana donde se dibujara la turtle
	*Es necesaria para empezar a dibujar
	*/
	void startTurtle();

	/** Avanzar una distancia determinada
	*  @param dis es la distancia que la tortuga va a recorrer
	*/
	void forward(GLdouble dis);

	/** Que la tortuga gire a la izquierda
	*  @param angle es el angulo que girara hacia la izquierda
	*/
	void left(GLdouble angle);

	/** Que la tortuga gire a la derecha
	*  @param angle es el angulo que girara hacia la derecha
	*/
	void right(GLdouble angle);

	/** Levanta el lapiz de dibujo
	*Mientras el lapiz este arriba, la tortuga no va a dibujar
	*/
	void penup();

	/** Baja el lapiz de dibujo
	*La tortuga va a dibujar solo cuando el lapiz este abajo
	*/
	void pendown();

	/** Cambiar el color del lapiz en RGB. (Por ejemplo: 000 es negro)
	*  @param _r es la cantidad de color rojo (de 0 a 255)
	*  @param _g es la cantidad de color verde (de 0 a 255)
	*  @param _b es la cantidad de color azul (de 0 a 255)
	*/
	void pencolor(float _r, float _g, float _b);

	/** Ir a un punto en el plano
	*  @param dx es la coordenada del punto en x
	*  @param dy es la coordenada del punto en y
	*/
	void go(GLdouble dx, GLdouble dy);

	/** Muestra el dibujo realizado
	*Es necesario para visualizar los graficos realizados. Se ubica al final del documento.
	*/
	void display(); //Dibuja en ventana

};