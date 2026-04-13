Descripcion:
Este programa permite ingresar numeros enteros y los clasifica automaticamente en diferentes estructuras de datos segun su tipo.

Funcionamiento:

Los numeros negativos se guardan en una lista enlazada.
Los numeros pares se guardan en una cola.
Los numeros impares se guardan en una pila.
El numero -1 se usa para finalizar el ingreso de datos.

Estructuras utilizadas:

Nodo:
Es la base de todas las estructuras y contiene un dato y un puntero al siguiente nodo.
Pila:
Funciona con el metodo LIFO (ultimo en entrar, primero en salir).
Permite insertar, eliminar, ver el tope y mostrar los elementos.
Cola:
Funciona con el metodo FIFO (primero en entrar, primero en salir).
Permite insertar, eliminar, ver el frente y mostrar los elementos.
Lista enlazada:
Se utiliza para almacenar numeros negativos.
Permite insertar, mostrar y ordenar los datos.

Validacion:
El programa incluye una funcion que asegura que el usuario solo ingrese numeros enteros validos.

Menu:
El sistema cuenta con un menu con las siguientes opciones:

Ingresar numero
Mostrar pila
Mostrar cola
Mostrar lista
Eliminar de pila
Eliminar de cola
Ver tope de pila
Ver frente de cola
Mostrar estadisticas
Ordenar lista de negativos
Salir

Estadisticas:
El programa lleva el conteo de:

Cantidad de numeros pares
Cantidad de numeros impares
Cantidad de numeros negativos

Memoria:
Antes de finalizar, el programa libera toda la memoria utilizada para evitar errores.

Ejecucion:

Compilar el programa con un compilador de C++
Ejecutarlo
Usar el menu para interactuar

Notas:

El numero -1 no se almacena.
Si una estructura esta vacia, el programa lo indica.
La lista de negativos se puede ordenar en cualquier momento.

Autor:
Rony Barrios
