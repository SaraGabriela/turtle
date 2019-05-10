Turtle en C++
=========

## Descripción
Código que simula la tortuga de Python haciendo uso de OpenGL. Permite realizar gráficos simples por medio de un plano de coordenadas. Empieza a dibujar en (0,0).

## ¿Cómo se usa?
### 1. Instalar Glut
Referencias para instalar GLUT al usar DevC++:
https://www.quora.com/How-do-I-run-OpenGL-in-DEV-C++
https://www.youtube.com/watch?v=RTk6W67dyR4

Referencias para instalar GLUT al usar Visual Studio:
https://elcodigografico.wordpress.com/2017/07/31/opengl-glut-con-visual-studio-2017/
https://www.youtube.com/watch?v=HKGJrzAuTvU


### 2. Usar la estructura
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

## ¿Cómo dibujar?
### pendown()
Baja el lápiz de dibujo. La tortuga va a dibujar solo cuando el lápiz este abajo.

### penup()
Levanta el lápiz de dibujo. Mientras el lápiz este arriba, la tortuga no va a dibujar.

### forward(distancia)
Dibujará una línea según la distancia indicada. Solo dibuja si el lápiz está abajo, es decir si se llamó antes a pendown(). Si el lápiz está arriba, se moverá sin dibujar.
```c++
	tu->forward(3);
```
### left(ángulo)
La tortuga girará a la izquierda según el ángulo indicado.
```c++
	tu->left(90);
```
### right(ángulo)
La tortuga girará a la derecha según el ángulo indicado.
```c++
	tu->right(90);
```
### go(x,y)
La tortuga se va a dirigir al punto indicado.
```c++
	tu->go(-2,0);
```

### pencolor(r,g,b)
Cambiar el color del dibujo

## Authors
- [Sara Díaz Oporto](https://github.com/SaraGabriela)
