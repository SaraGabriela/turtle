/** @file main.cpp
@author Sara Diaz Oporto
@version Revision 1.1
@brief Clase turtle que permite realizar graficos con un comportamiento similar a turtle python.
*/
#include <iostream>
#include "turtle.h"

using namespace std;


int main()
{
	turtle * tu = new turtle();
	tu->setInstance(tu);
	tu->startTurtle();
	tu->pendown();
	tu->forward(1);
	tu->left(90);
	tu->forward(1);
	tu->penup();
	tu->left(90);
	tu->forward(1);
	tu->left(90);
	tu->pendown();
	tu->forward(1);
	tu->penup();
	tu->go(-4, 0);
	tu->pendown();
	tu->forward(-1);


	tu->display();
	return 0;
}