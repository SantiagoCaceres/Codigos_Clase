#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class agenda{
private:
    map<string, string> contactos;
    fstream info;


public:
    agenda(){

    }
    void generar_agenda();
    void agregar_contactos();
    void eliminar_contactos();
    void ordenar_contactos();
    void buscar_contacto();
    void imprimir();


};

#endif // AGENDA_H
