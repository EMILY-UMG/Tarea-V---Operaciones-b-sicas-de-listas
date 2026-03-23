#include <iostream>
using namespace std;

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

void insertarInicio(Nodo*& lista) {
    Nodo* nuevo = new Nodo;

    cout << "Ingrese carne: ";
    cin >> nuevo->carne;
    cout << "Ingrese nombre: ";
    cin >> nuevo->nombre;
    cout << "Ingrese apellido: ";
    cin >> nuevo->apellido;
    cout << "Ingrese carrera: ";
    cin >> nuevo->carrera;

    nuevo->siguiente = lista;
    lista = nuevo;

    cout << "Estudiante agregado al inicio\n";
}

void insertarFinal(Nodo*& lista) {
    Nodo* nuevo = new Nodo;

    cout << "Ingrese carne: ";
    cin >> nuevo->carne;
    cout << "Ingrese nombre: ";
    cin >> nuevo->nombre;
    cout << "Ingrese apellido: ";
    cin >> nuevo->apellido;
    cout << "Ingrese carrera: ";
    cin >> nuevo->carrera;

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

    cout << "Estudiante agregado al final\n";
}

void mostrar(Nodo* lista) {
    if (lista == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* aux = lista;

    while (aux != NULL) {
        cout << "\nCarné: " << aux->carne << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Apellido: " << aux->apellido << endl;
        cout << "Carrera: " << aux->carrera << endl;
        cout << "-----------------------------\n";

        aux = aux->siguiente;
    }
}

void buscar(Nodo* lista, int carne) {
    if (lista == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* aux = lista;
    bool encontrado = false;

    while (aux != NULL) {
        if (aux->carne == carne) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Apellido: " << aux->apellido << endl;
            cout << "Carrera: " << aux->carrera << endl;
            encontrado = true;
            break;
        }
        aux = aux->siguiente;
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado\n";
    }
}

void eliminar(Nodo*& lista, int carne) {
    if (lista == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* aux = lista;
    Nodo* anterior = NULL;

    while (aux != NULL && aux->carne != carne) {
        anterior = aux;
        aux = aux->siguiente;
    }

    if (aux == NULL) {
        cout << "Estudiante no encontrado\n";
        return;
    }

    if (anterior == NULL) {
        lista = lista->siguiente;
    } else {
        anterior->siguiente = aux->siguiente;
    }

    delete aux;
    cout << "Estudiante eliminado correctamente\n";
}

void liberarLista(Nodo*& lista) {
    Nodo* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->siguiente;
        delete aux;
    }
}

int main() {
    Nodo* lista = NULL;
    int opcion, carne;

    cout << "====================================\n";
    cout << "Nombre: Emily Yamileth Herrera Monterroso\n";
    cout << "Sistema de Gestion de Estudiantes\n";
    cout << "====================================\n";

    do {
        cout << "\nMENU\n";
        cout << "1. Insertar estudiante al inicio\n";
        cout << "2. Insertar estudiante al final\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarInicio(lista);
                break;

            case 2:
                insertarFinal(lista);
                break;

            case 3:
                mostrar(lista);
                break;

            case 4:
                cout << "Ingrese carne a buscar: ";
                cin >> carne;
                buscar(lista, carne);
                break;

            case 5:
                cout << "Ingrese carne a eliminar: ";
                cin >> carne;
                eliminar(lista, carne);
                break;

            case 6:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 6);

    liberarLista(lista);

    return 0;
}