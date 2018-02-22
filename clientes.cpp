#include "clientes.h"
#include <QString>

Clientes::Clientes()

{
this->cantidad =0;
    this->inicio=NULL;
    this->final=NULL;
}

void Clientes::insertar(NodoCliente *nodo){
    insertarInicio(nodo);
}

void Clientes::insertarInicio(NodoCliente *nodo){
    if(!insertarPrimero(nodo))
    {
        this->final->siguiente = nodo;
        this->final = nodo;
        this->cantidad++;
    }
}

void Clientes::insertarFinal(NodoCliente *nodo){
    if(!insertarPrimero(nodo)){
        nodo->siguiente = this->inicio;
        this->inicio = nodo;
        this->cantidad++;
    }
}

bool Clientes::insertarPrimero(NodoCliente *nodo){
    if(this->inicio == NULL && this->final==NULL){
        this->inicio = nodo;
        this->final = nodo;
        this->cantidad++;
        return true;
    }
    return false;
}


NodoCliente* Clientes::encontrar(NodoCliente *nodo){
    if(this->inicio ==NULL)
        return NULL;
    NodoCliente* temporal = this->inicio;
    while (temporal!=NULL) {
        if(temporal->equals(nodo))
            return temporal;
        temporal = temporal->siguiente;
    }
    return NULL;
}

void Clientes::llenarTablero(QTableWidget *tabla){
    if(this->inicio ==NULL)
        return;
    NodoCliente* temporal = this->inicio;
    tabla->clearContents();
    for(int i=0; temporal !=NULL; i++){
        QTableWidgetItem* nombreObjeto = new QTableWidgetItem(temporal->getNombreCliente());
        QTableWidgetItem* nitObjeto = new QTableWidgetItem(temporal->getNit());
        QTableWidgetItem* listaFacturaObjeto = new QTableWidgetItem(temporal->getListaFactura());
        tabla->setRowCount(i+1);

        tabla->setItem(i, 0, nombreObjeto);
        tabla->setItem(i, 1, nitObjeto);
        tabla->setItem(i, 2, listaFacturaObjeto);
        temporal = temporal->siguiente;
    }
}

void Clientes::editar(NodoCliente *antes, NodoCliente *nodo){

}


NodoCliente* Clientes::eliminar(NodoCliente *nodo){
    if(this->estaVacio())
        return NULL;
    NodoCliente* temporal = this->inicio;
    NodoCliente* anterior =  NULL;
    while (temporal !=NULL) {
        if(temporal->equals(nodo))
            break;
        anterior = temporal;
        temporal = temporal->siguiente;
    }
    if(temporal==NULL)
        return NULL;
    if(anterior==NULL){
        inicio = inicio->siguiente;
    } else{
        anterior->siguiente = temporal->siguiente;
    }
    cantidad--;
    return temporal;
}

bool Clientes::estaVacio(){
    return this->cantidad ==0 || this->inicio == NULL || this->final == NULL;
}

int Clientes::tamao(){
    return this->cantidad;
}

void Clientes::borrar(){
    this->cantidad =0;
    this->inicio =NULL;
    this->final =NULL;
}

NodoCliente::NodoCliente(QString nit, QString nombre, int listafactura){
    this->nit=nit;
    this->nombre=nombre;
    this->listafactura=listafactura;
    this->siguiente=NULL;
}
NodoCliente::NodoCliente(){
    this->nit=="";
    this->nombre="";
    this->listafactura=0;
    this->siguiente=NULL;

}

void NodoCliente::setNit(QString nit){
    this->nit =nit;
}
void NodoCliente::setNombre(QString nombre){
    this->nombre=nombre;
}

void NodoCliente::setListaFactura(int listafactura){
    this->listafactura=listafactura;
}

QString NodoCliente::getNit(){
    return this->nit;
}
QString NodoCliente::getNombreCliente(){
    return this->nombre;
}
int NodoCliente::getListaFactura(){
    return this->listafactura;
}

bool NodoCliente::equals(NodoCliente *otro){
    if(otro==NULL)
        return false;
    if(this->nit==NULL)
        return otro->nit==NULL;
    if(otro->nit==NULL)
        return false;
    return this->nit == otro->nit;
}
