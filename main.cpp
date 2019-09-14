#include <iostream>
#include "agenda.h"

using namespace std;


int main()
{

    agenda miagenda;
    miagenda.generar_agenda();
    miagenda.imprimir();
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
    cout<<"Agrega un nuevo contacto"<<endl<<endl;
    miagenda.agregar_contactos();
    miagenda.imprimir();
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
    cout<<"Elimina un contacto: "<<endl;
    miagenda.eliminar_contactos();
    miagenda.imprimir();
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
    cout<<"Busca un contacto"<<endl;
    miagenda.buscar_contacto();
    cout<<"Gracias por usar el servicio"<<endl;

}

