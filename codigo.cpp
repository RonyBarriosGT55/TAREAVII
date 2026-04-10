#include <iostream>
#include <limits>

using namespace std;

// ======================================================
// ESTRUCTURA DEL NODO
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// ======================================================
// FUNCIONES DE VALIDACION
int leerEntero() {
    int numero;

    while (true) {
        cin >> numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero entero: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numero;
        }
    }
}

// ======================================================
// FUNCIONES DE PILA
void push(Nodo*& tope, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
}

bool pop(Nodo*& tope, int& eliminado) {
    if (tope == NULL) {
        return false;
    }

    Nodo* temp = tope;
    eliminado = temp->dato;
    tope = tope->siguiente;
    delete temp;
    return true;
}

bool peekPila(Nodo* tope, int& valor) {
    if (tope == NULL) {
        return false;
    }

    valor = tope->dato;
    return true;
}

void mostrarPila(Nodo* tope) {
    if (tope == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    cout << "Pila (impares): ";
    Nodo* aux = tope;

    while (aux != NULL) {
        cout << aux->dato;
        if (aux->siguiente != NULL) {
            cout << " -> ";
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

// ======================================================
// FUNCIONES DE COLA
void enqueue(Nodo*& frente, Nodo*& fin, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

bool dequeue(Nodo*& frente, Nodo*& fin, int& eliminado) {
    if (frente == NULL) {
        return false;
    }

    Nodo* temp = frente;
    eliminado = temp->dato;
    frente = frente->siguiente;

    if (frente == NULL) {
        fin = NULL;
    }

    delete temp;
    return true;
}

bool peekCola(Nodo* frente, int& valor) {
    if (frente == NULL) {
        return false;
    }

    valor = frente->dato;
    return true;
}

void mostrarCola(Nodo* frente) {
    if (frente == NULL) {
        cout << "La cola esta vacia.\n";
        return;
    }

    cout << "Cola (pares): ";
    Nodo* aux = frente;

    while (aux != NULL) {
        cout << aux->dato;
        if (aux->siguiente != NULL) {
            cout << " -> ";
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

// ======================================================
// FUNCIONES DE LISTA ENLAZADA
void insertarLista(Nodo*& lista, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void mostrarLista(Nodo* lista) {
    if (lista == NULL) {
        cout << "La lista de negativos esta vacia.\n";
        return;
    }

    cout << "Lista (negativos): ";
    Nodo* aux = lista;

    while (aux != NULL) {
        cout << aux->dato;
        if (aux->siguiente != NULL) {
            cout << " -> ";
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

// Ordenar lista enlazada de forma ascendente
void ordenarListaNegativos(Nodo*& lista) {
    if (lista == NULL || lista->siguiente == NULL) {
        return;
    }

    Nodo* i;
    Nodo* j;
    int temp;

    for (i = lista; i != NULL; i = i->siguiente) {
        for (j = i->siguiente; j != NULL; j = j->siguiente) {
            if (i->dato > j->dato) {
                temp = i->dato;
                i->dato = j->dato;
                j->dato = temp;
            }
        }
    }
}

// ======================================================
// LIMPIEZA DE MEMORIA
void liberarEstructura(Nodo*& cabeza) {
    Nodo* temp;

    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// ======================================================
// MENU
void mostrarMenu() {
    cout << "\nRony Alexander Barrios Borrayo\n";
    cout << "\n9911 99 127\n";
     cout << "\n=========== MENU ===========\n";
    cout << "1. Ingresar numero\n";
    cout << "2. Mostrar pila\n";
    cout << "3. Mostrar cola\n";
    cout << "4. Mostrar lista\n";
    cout << "5. Eliminar de pila\n";
    cout << "6. Eliminar de cola\n";
    cout << "7. Ver tope de pila\n";
    cout << "8. Ver frente de cola\n";
    cout << "9. Mostrar estadisticas\n";
    cout << "10. Ordenar lista de negativos\n";
    cout << "11. Salir\n";
    cout << "Seleccione una opcion: ";
}

// ======================================================
// FUNCION PRINCIPAL
// ======================================================
int main() {
    Nodo* tope = NULL;      // pila
    Nodo* frente = NULL;    // cola
    Nodo* fin = NULL;       // cola
    Nodo* lista = NULL;     // lista enlazada

    int opcion;
    int numero;
    int eliminado;
    int valor;
    int cantidadPares = 0;
    int cantidadImpares = 0;
    int cantidadNegativos = 0;

    cout << "=============================================\n";
    cout << "  SISTEMA DE CLASIFICACION DE NUMEROS\n";
    cout << "  Estudiante: ESCRIBA_AQUI_SU_NOMBRE\n";
    cout << "=============================================\n";

    do {
        mostrarMenu();
        opcion = leerEntero();

        switch (opcion) {
            case 1:
                cout << "\nIngrese un numero (-1 para finalizar ingreso): ";
                numero = leerEntero();

                if (numero == -1) {
                    cout << "Ingreso finalizado por el valor especial -1.\n";
                } else if (numero < 0) {
                    insertarLista(lista, numero);
                    cantidadNegativos++;
                    cout << "Numero negativo insertado en la lista.\n";
                } else if (numero % 2 == 0) {
                    enqueue(frente, fin, numero);
                    cantidadPares++;
                    cout << "Numero par insertado en la cola.\n";
                } else {
                    push(tope, numero);
                    cantidadImpares++;
                    cout << "Numero impar insertado en la pila.\n";
                }
                break;

            case 2:
                mostrarPila(tope);
                break;

            case 3:
                mostrarCola(frente);
                break;

            case 4:
                mostrarLista(lista);
                break;

            case 5:
                if (pop(tope, eliminado)) {
                    cout << "Elemento eliminado de la pila: " << eliminado << endl;
                } else {
                    cout << "No se puede eliminar. La pila esta vacia.\n";
                }
                break;

            case 6:
                if (dequeue(frente, fin, eliminado)) {
                    cout << "Elemento eliminado de la cola: " << eliminado << endl;
                } else {
                    cout << "No se puede eliminar. La cola esta vacia.\n";
                }
                break;

            case 7:
                if (peekPila(tope, valor)) {
                    cout << "Tope de la pila: " << valor << endl;
                } else {
                    cout << "La pila esta vacia.\n";
                }
                break;

            case 8:
                if (peekCola(frente, valor)) {
                    cout << "Frente de la cola: " << valor << endl;
                } else {
                    cout << "La cola esta vacia.\n";
                }
                break;

            case 9:
                cout << "\n===== ESTADISTICAS =====\n";
                cout << "Cantidad de pares: " << cantidadPares << endl;
                cout << "Cantidad de impares: " << cantidadImpares << endl;
                cout << "Cantidad de negativos: " << cantidadNegativos << endl;
                break;

            case 10:
                ordenarListaNegativos(lista);
                cout << "Lista de negativos ordenada correctamente.\n";
                mostrarLista(lista);
                break;

            case 11:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 11);

    // Liberar toda la memoria antes de salir
    liberarEstructura(tope);
    liberarEstructura(frente);
    liberarEstructura(lista);

    cout << "Memoria liberada correctamente.\n";
    return 0;
}
