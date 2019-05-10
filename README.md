Turtle en C++
=========

## Descripción
Código que simula la tortuga de Python haciendo uso de OpenGL. Permite realizar gráficos simples por medio de un plano de coordenadas. Empieza a dibujar en (0,0).

##¿Cómo se usa?
##1. Instalar OpenGL

##2. Usar la estructura
Primero se crea una instancia del objeto que se va a dibujar y se crea la ventana donde se va a dibujar.
```c++
	turtle * tu = new turtle();
	tu->setInstance(tu);
	tu->startTurtle();
```
Luego, ingresa lo que la tortuga va a dibujar.

Finalmente mostramos el dibujo realizado.
```c++
	tu->display();
```

Debe quedar así:
```c++
int main()
{
	turtle * tu = new turtle();
	tu->setInstance(tu);
	tu->startTurtle();

	//tu código va aquí

	tu->display();
	return 0;
}
```
¡Y listo! Permite realizar dibujos de un modo sencillo. Para un ejemplo, ejecuta main.cpp de la carpeta source.