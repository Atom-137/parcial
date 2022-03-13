
#include <iostream>


using namespace std;

int n;

struct persona {

    char nombre[50];
    char apellido[50];
    char nacionalidad[50];
    int edad;

    //struct persona* sig;
};

//persona aux;
/*
struct cola
{
    persona* delante;
    persona* atras;
};
*/

//void ordenar(persona *);

void ingresarDatos() {

    cout << "Ingrese el numero de personas: " << endl;
    cin >> n;
    const int nSize = 50;
    persona personas[50],  *ptr_persona;
    ptr_persona = personas;

    for (int i = 0; i < n; i++) {

        cout << "Ingrese el nombre: " << endl;
        cin >> (personas+i)->nombre;
        cout << "Ingrese el apellido: " << endl;
        cin >> (personas + i)->apellido;
        cout << "Ingrese la edad: " << endl;
        cin >> (personas + i)->edad;
        cout << "Ingrese la nacionalidad: " << endl;
        cin >> (personas + i)->nacionalidad;
    }

    //Mostrar los datos

    for (int i = 0; i < n; i++) {

        cout << "Nombre: " << endl;
        cout << (personas + i)->nombre;
        cout << "Apellido: " << endl;
        cout << (personas + i)->apellido;
        cout << "Edad: " << endl;
        cout << (personas + i)->edad;
        cout << "Nacionalidad: " << endl;
        cout << (personas + i)->nacionalidad;
    }

   ordenar(personas, n);

}


void ordenar(persona *ptr_persona, int nSize) {

    
    persona aux;

   for (int pasada = 0; pasada < nSize - 1; pasada++)
        {
            for (int k = 0; k < nSize - 1; k++)
            {
                if ((ptr_persona+k) ->edad > (ptr_persona +(k+1))->edad)
                {
                    aux = *(ptr_persona + k);
                    *(ptr_persona + k) = *(ptr_persona + k + 1);
                    *(ptr_persona + k+ 1) = aux;
                }
            }
        }
    mostrarArregloOrdenado(ptr_persona, nSize);

}

void mostrarArregloOrdenado( persona *ptr_personas, int nElementos) {//Mostrando Arreglo ordenado
    cout << "\n\nMostrando Arreglo Ordenado: ";
    for (int i = 0; i < nElementos; i++) {
        cout << ptr_personas + i << " ";
    }
}


int main()
{
    
    ingresarDatos();


}

