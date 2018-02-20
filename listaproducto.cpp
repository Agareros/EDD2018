#include "listaproducto.h"
#include <QString>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
listaProducto::listaProducto()
{
this->cantidad=0;
    this->inicio=NULL;
    this->final=NULL;
}

void listaProducto::insertar(NodoProducto *nodo){
    if(primeraInsercion(nodo))
        return;
    insertar(nodo, this->inicio, this->final, this->cantidad);
}

void listaProducto::insertar(NodoProducto *nodo, NodoProducto *a, NodoProducto *z, int rango){
    int izquierda = nodo->compare(a);
    int derecha = nodo->compare(z);
    if(izquierda < 0){
        insertarAntes(nodo,a);
        return;
    }
    if(derecha > 0){
        insertarDespues(nodo, z);
        return;
    }
    if(derecha==0 || izquierda==0){
        return;
    }
    rango = rango/2;
    NodoProducto* pivote = a;
    for(int i=0; i< rango && pivote!=NULL && pivote->siguiente!=NULL; i++){
        pivote = pivote->siguiente;
    }
    int centrar = nodo->compare(pivote);
    if(centrar < 0){
        if(pivote->anterior==a){
            insertarAntes(nodo,pivote);
            return;
        }
        insertar(nodo, a, pivote, rango+1);
    } else if (centrar > 0){
        if(pivote->siguiente ==z){
            insertarDespues(nodo, pivote);
            return;
        }
        insertar(nodo, pivote, z, rango+1);
    }
    else {

    }

    }

void listaProducto::insertarAntes(NodoProducto *nodo, NodoProducto *pivote){
    if(pivote->anterior==NULL){
        insertarPrimero(nodo);
    } else {
        pivote->anterior->siguiente=nodo;
        nodo->anterior=pivote->anterior;
        pivote->anterior=nodo;
        nodo->siguiente=pivote;
        cantidad++;
    }
}

void listaProducto::insertarDespues(NodoProducto *nodo, NodoProducto *pivote){
    if(pivote->siguiente==NULL){
insertarFinal(nodo);
    }
    else {
        pivote->siguiente->anterior=nodo;
        nodo->siguiente=pivote->siguiente;
        pivote->siguiente=nodo;
        nodo->anterior=pivote;
        cantidad++;
    }
    }

void listaProducto::insertarFinal(NodoProducto* nodo){
    this->final->siguiente=nodo;
    nodo->anterior = this->final;
    this->final = nodo;
    this->cantidad++;
}

void listaProducto::insertarPrimero(NodoProducto *nodo){
    nodo->siguiente=this->inicio;
    this->inicio->anterior=nodo;
    this->inicio = nodo;
    this->cantidad++;
}

bool listaProducto::primeraInsercion(NodoProducto *nodo){
    if(this->inicio == NULL && this->final == NULL){
        this->inicio=nodo;
        this->final=nodo;
        this->cantidad++;
        return true;
    }
    return false;
}

void listaProducto::llenarTabla(QTableWidget *tablas){
    if(this->inicio==NULL)
        return;
    NodoProducto* temporal = this->inicio;
    tablas->clearContents();
    for(int i=0; temporal!= NULL; i++){
        QTableWidgetItem* codigoObjeto = new QTableWidgetItem(temporal->getCodigo());
        QTableWidgetItem* precioObjeto = new QTableWidgetItem(temporal->getPrecio());
        QTableWidgetItem* nombreObjeto = new QTableWidgetItem(temporal->getNombre());
        QTableWidgetItem* descripcionObjeto = new QTableWidgetItem(temporal->getDescripcion());
        tablas->setRowCount(i+1);
        tablas->setItem(i,0,codigoObjeto);
        tablas->setItem(i,1,precioObjeto);
        tablas->setItem(i,2,nombreObjeto);
        tablas->setItem(i,3,descripcionObjeto);
        temporal=temporal->siguiente;
    }
}

void listaProducto::editar(NodoProducto *antiguo, NodoProducto *nodo){

}

bool listaProducto::estaVacio(){
    return this->cantidad ==0 || this->inicio==NULL || this->final==NULL;
}

int listaProducto::tamao(){
    return this->cantidad;
}
void listaProducto::limpiar(){
    this->cantidad=0;
    this->inicio = NULL;
    this->final =NULL;
}

NodoProducto::NodoProducto(){
    this->Codigo="";
    this->Nombre="";
    this->Precio="";
    this->Descripcion="";
    this->anterior=NULL;
    this->siguiente=NULL;
}

NodoProducto::NodoProducto(QString Codigo, QString Precio, QString Nombre, QString Descripcion){
    this->Codigo=Codigo;
    this->Precio=Precio;
    this->Nombre=Nombre;
    this->Descripcion=Descripcion;
    this->anterior=NULL;
    this->siguiente=NULL;
}

void NodoProducto::setCodigo(QString Codigo){
    this->Codigo=Codigo;
}
void NodoProducto::setDescripcion(QString Descripcion){
    this->Descripcion=Descripcion;
}

void NodoProducto::setNombre(QString Nombre){
    this->Nombre=Nombre;
}

void NodoProducto::setPrecio(QString Precio){
    this->Precio=Precio;
}

QString NodoProducto::getCodigo(){
    return this->Codigo;
}
QString NodoProducto::getDescripcion(){
    return this->Descripcion;
}
QString NodoProducto::getNombre(){
    return this->Nombre;
}
QString NodoProducto::getPrecio(){
    return this->Precio;
}


int NodoProducto::compare(NodoProducto *varios){
    if(varios==NULL)
        return -1;
    if(this->Codigo==NULL)
        return varios->Codigo == NULL ? 0 : 1;
    if(varios->Codigo==NULL)
        return -1;
    return this->Codigo.compare(varios->Codigo);
}

bool NodoProducto::equals(NodoProducto *varios){
    if(varios==NULL)
        return false;
    if(this->Codigo==NULL)
        return varios->Codigo ==NULL;
    if(varios->Codigo==NULL)
        return false;
    return this->Codigo == varios->Codigo;
}

void listaProducto::escribirProducto(QTextStream &archivo){
    archivo << "digraph g{" << std::endl;
    archivo << "node [shape=box];" << std::endl;
    archivo << "label=\"PRODUCTO" << " Productos " << "\";" << std::endl;
    NodoProducto *aux = this->inicio->siguiente;
    while(aux!=NULL)
        {
            if(aux->siguiente!=NULL)
            {
                archivo << "\"CODIGO: " << aux->Codigo<< " | Nom: " << aux->Nombre << " | Precio: " << aux->siguiente->Precio << "\"->\"Codigo: " <<  aux->siguiente->Codigo << " | Nombre: " << aux->siguiente->Nombre << " | Precio: " << aux->siguiente->Precio << "\";" << std::endl;
            }
            else
            {
                archivo << "\"Codigo: " << aux->Codigo << " | Nombre: " << aux->Nombre << " | Precio: " << aux->Precio << "\";" << std::endl;
            }
            aux = aux->siguiente;
        }

    archivo << "}" << std::endl;
}


/*/void listaProducto::escribirProducto(std::ofstream &archivo){
    archivo << "digraph g{" << std::endl;
    archivo << "node [shape=box];" << std::endl;
    archivo << "label=\"PRODUCTO" << " Productos " << "\";" << std::endl;
    NodoProducto *aux = this->inicio->siguiente;
    while(aux!=NULL)
        {
            if(aux->siguiente!=NULL)
            {
                archivo << "\"CODIGO: " << aux->Codigo<< " | Nom: " << aux->Nombre.toStdString() << " | Precio: " << aux->siguiente->Precio << "\"->\"Codigo: " <<  aux->siguiente->Codigo.toStdString() << " | Nombre: " << aux->siguiente->Nombre.toStdString() << " | Precio: " << aux->siguiente->Precio.toStdString() << "\";" << std::endl;
            }
            else
            {
                archivo << "\"Codigo: " << aux->Codigo << " | Nombre: " << aux->Nombre << " | Precio: " << aux->Precio.toStdString() << "\";" << std::endl;
            }
            aux = aux->siguiente;
        }

    archivo << "}" << std::endl;
}
/*/
/*
listaProducto::graficarProducto(listaProducto *listas){
    QString grafica = "digraph G{\n";
    int contar =1;
    NodoProducto *auxiliar = listas->inicio;
    while (auxiliar->siguiente!=NULL && contador<6) {
        QTextStream ms;
        ms<<auxiliar;
        QString puntero1 =

    }
}
*/

/*/
QString listaProducto::cuerpo(){
    QString cuerpo="";
    if(this->inicio!=NULL){
        NodoProducto *auxiliar = this->inicio;
        while (auxiliar!=NULL) {
            cuerpo +=auxiliar->Codigo + ";\n";
            if(auxiliar->siguiente!=NULL){
                cuerpo +=auxiliar->Codigo + " -> " + auxiliar->siguiente->Nombre + ";\n";
            }
            auxiliar = auxiliar->siguiente;
        }
    }
    return cuerpo;
}
*/
