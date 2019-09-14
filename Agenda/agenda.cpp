#include "agenda.h"

void agenda::generar_agenda(){
    info.open("C://Users//santy//Desktop//Agenda//Agenda.txt",ios::in);
    string texto,nombre,numero;
    getline(info,texto);
    if(texto==""){
        cout<<"No tienes ningun contacto, agrega alguno"<<endl;
        info.close();
         agregar_contactos();
         info.open("C://Users//santy//Desktop//Agenda//Agenda.txt",ios::in);
    }
    info.seekp(0);
    while(!info.eof()){
        getline(info,texto);

        nombre=texto.substr(0,texto.find(":"));
        numero=texto.substr(texto.find(":")+1);
        contactos.insert(pair<string, string>(nombre, numero));
    }
    info.close();
}

void agenda::agregar_contactos(){
    string nombre,numero;
    info.open("C://Users//santy//Desktop//Agenda//Agenda.txt",ios::app);
    cout<<"Porfavor ingrese un nombre";
    getline(cin,nombre);
    cin.ignore();
    cout<<"Porfavor ingrese el numero de telefono perteneciente a "<<nombre<<": ";
    getline(cin,numero);
    cin.ignore();
    contactos.insert(pair<string, string>(nombre, numero));
    info<<nombre<<":"<<numero<<endl;
    info.close();
}

void agenda::imprimir(){
    info.open("C://Users//santy//Desktop//Agenda//Agenda.txt",ios::in);
    string texto;
    while(!info.eof()){
        getline(info,texto);
        for(auto i : texto){
            if(i==':'){
                cout<<"  ";
            }
            cout<<i;
        }
        cout<<endl;
    }
    info.close();

}

void agenda::eliminar_contactos(){
    cout<<"Ingrese el nombre del contacto a eliminar: ";
    string nombre;
    cout<<endl;
    getline(cin,nombre);
    cin.ignore();
    auto it = contactos.find(nombre);
    if (it != contactos.end()){
       contactos.erase (it);
    cout<<"Usuario eliminado con exito"<<endl;
    ofstream salida;
    salida.open("C://Users//santy//Desktop//Agenda//Agenda2.txt",ios::app);
    info.open("C://Users//santy//Desktop//Agenda//Agenda.txt",ios::in);
    string texto;
    while(!info.eof()){
        getline(info,texto);
        if(texto.substr(0,texto.find(':'))!=nombre){
            salida<<texto<<endl;
        }
    }
    info.close();
    salida.close();
    remove("C://Users//santy//Desktop//Agenda//Agenda.txt");
    rename("C://Users//santy//Desktop//Agenda//Agenda2.txt","C://Users//santy//Desktop//Agenda//Agenda.txt");



    }
    else{
        cout<<"El contacto no ha sido eliminado porque no exite"<<endl;
    }

}

void agenda::buscar_contacto(){
    bool t=false;

    string nombre;
    cout<<"Ingrese el nombre del contacto: ";
    getline(cin,nombre);
    cin.ignore();
    cout<<endl;
    info.open("C://Users//santy//Desktop//Agenda//Agenda.txt",ios::in);
    string texto;
    while(!info.eof()){
        getline(info,texto);
        if(texto.substr(0,texto.find(':'))==nombre){
           cout<<"El numero de contacto de "<<nombre<<" es: "<<texto.substr(texto.find(':')+1)<<endl;
           cout<<endl;
           info.close();
           t=true;
           break;

    }

}
    if(t!=true){
    cout<<"No se encontro el contacto"<<endl;}
}


