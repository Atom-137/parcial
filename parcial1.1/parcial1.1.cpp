
#include <iostream>


using namespace std;

int numeroPersonas;
const int tamanioArreglo = 50;

struct persona {

    /*char nombre[50]
    char apellido[50];
    char nacionalidad[50];*/

    string nombre;
    string apellido;
    string nacionalidad;

    int edad;

    struct persona* sgte;

};


struct cola
{
    persona *delante;
    persona *atras;
};


persona personas[tamanioArreglo];

persona * ordenar(persona[]);
void mostrarArregloOrdenado(persona *);
void encolar(struct cola&, persona *, int);
//void encolar(cola& q, string nom, string ap, string nac, int edad, int i);
void muestraCola(struct cola);
string desencolar(struct cola&);


void ingresarDatos() {
    
    struct cola q;
    q.delante = NULL;
    q.atras = NULL;

   cout << "Ingrese el numero de personas: " << endl;
   cin >> numeroPersonas;

   persona* ptr_persona = personas;

    for (int i = 0; i < numeroPersonas; i++) {

        cout << "Ingrese el nombre: " << endl;
        cin >> personas[i].nombre;
        cout << "Ingrese el apellido: " << endl;
        cin >> personas[i].apellido;
        cout << "Ingrese la edad: " << endl;
        cin >> personas[i].edad;
        cout << "Ingrese la nacionalidad: " << endl;
        cin >> personas[i].nacionalidad;

       // encolar(q, personas[i].nombre, personas[i].apellido, personas[i].nacionalidad, personas[i].edad, i);
        encolar(q, ptr_persona+i, i);
    }

    //Mostrar cola

    if (q.delante != NULL) {
        muestraCola(q);
    }
    cout << "Desencolar dato" << endl;
    
    //Desencolar Dato
   
    string dato = desencolar(q);
    cout << "Se desencolo el dato: " << dato << endl;

    //Mostrar cola

    if (q.delante != NULL) {
        muestraCola(q);
    }
   


}

void encolar(struct cola& q, persona *ptr_persona, int i)
{

    struct persona* aux = new(struct persona);
    aux->nombre = ptr_persona ->nombre;
    aux->apellido = ptr_persona ->  apellido;
    aux->nacionalidad = ptr_persona ->nacionalidad;
    aux->edad = ptr_persona->edad;
    aux->sgte = NULL;
    if (q.delante == NULL) {
        q.delante = aux;   // encola el primero elemento
        cout << "Dato #" << i+1 << " encolado " << endl;
        cout << "Nombre : " << aux->nombre << " " << endl;
        system("pause");
        system("cls");

    }
    else {

        (q.atras)->sgte = aux;
        cout << "Dato #" << i + 1 << " encolado " << endl;
        cout << "Nombre : " << aux->nombre << " " << endl;
        system("pause");
        system("cls");
    }
    q.atras = aux;        // puntero que siempre apunta al ultimo elemento


}

void muestraCola(struct cola q)
{
    struct persona* aux;
    struct persona* aux2;

    aux = q.delante;
    aux2 = q.delante;

    while (aux != NULL)
    {
        cout << "   " << aux->nombre;
        cout << "   " << aux->apellido;
        cout << "   " << aux->edad;
        cout << "   " << aux->nacionalidad;
        cout << "\n";
        aux = aux->sgte;
        aux2 = aux2->sgte;
    }

}

string desencolar(struct cola &q)
{
    string num;
    struct persona* aux;

    aux = q.delante;      // aux apunta al inicio de la cola
    num = aux->nombre;
    q.delante = (q.delante)->sgte;
    delete(aux);          // libera memoria a donde apuntaba aux

    return num;
}


/*
persona * ordenar(persona arregloP[]) {


    persona aux;
    persona *ptr_persona = arregloP;

    for (int pasada = 0; pasada < numeroPersonas - 1; pasada++)
    {
        for (int k = 0; k < numeroPersonas - 1; k++)
        {
            if ((ptr_persona + k)->edad >(ptr_persona + (k + 1))->edad)
            {
                aux = *(ptr_persona + k);
                *(ptr_persona + k) = *(ptr_persona + (k + 1));
                *(ptr_persona + (k + 1)) = aux;
            }
        }
    }

    return ptr_persona;
   

}

void mostrarArregloOrdenado(persona* ptr_personas) {//Mostrando Arreglo ordenado
    cout << "\n\nMostrando Arreglo Ordenado: ";
    for (int i = 0; i < numeroPersonas; i++) {
        cout << "\n\nDato " << i + 1<< endl;
        cout << "Nombre: " << (ptr_personas + i)->nombre << " ";
        cout << "Apellido: " << (ptr_personas + i)->apellido << " ";
        cout << "Edad: " << (ptr_personas + i)->edad << " ";
        cout << "Nacionalidad: " << (ptr_personas + i)->nacionalidad << " " << endl;

    }
}

*/
int main()
{
   
    struct cola q;
    ingresarDatos();
   
   /* cout << "Desencolar dato" << endl;
    
   
   string dato = desencolar(q);

    cout << "Se desencolo el dato: " << dato << endl;*/

    //persona *ptr_personaMain = ordenar(personas);
    //mostrarArregloOrdenado(ptr_personaMain);

}

