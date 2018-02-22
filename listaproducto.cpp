#include "listaproducto.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <fstream>


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
    for(int i=0; i< rango && pivote->siguiente!=this->inicio; i++){
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
    if(pivote->anterior==this->final){
        insertarPrimero(nodo);
    } else {
        pivote->anterior->siguiente=nodo;
        nodo->anterior=pivote->anterior;
        pivote->anterior=nodo;
        nodo->siguiente=pivote;
        cantidad++;
    }
}


void listaProducto::insertarFinal(NodoProducto* nodo){
    nodo->anterior=this->final;
    nodo->siguiente = this->inicio;
    this->inicio->anterior=nodo;
    this->final->siguiente=nodo;
    this->final=nodo;
    this->cantidad++;
}

void listaProducto::insertarDespues(NodoProducto *nodo, NodoProducto *pivote){
    NodoProducto *temporal = pivote->siguiente;
    NodoProducto *temporal2 = this->inicio;
    QString valor1= temporal->getCodigo();
    QString valor2= temporal2->getCodigo();
    if(valor1.compare(valor2)==0){
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


void listaProducto::insertarPrimero(NodoProducto *nodo){
    nodo->siguiente=this->inicio;
    nodo->anterior=this->final;
    this->inicio->anterior=nodo;
    this->final->siguiente=nodo;
    this->inicio=nodo;
    this->cantidad++;
}

bool listaProducto::primeraInsercion(NodoProducto *nodo){
    if(this->inicio == NULL && this->final == NULL){
       nodo->siguiente=nodo;
       nodo->anterior=nodo;
       this->inicio=nodo;
       this->final=nodo;
       this->cantidad++;
       return true;
    }
    return false;
}

void listaProducto::llenarTabla(QTableWidget *tablas){
    if(tamao()==0){
        tablas->clearContents();
    }

    if(this->inicio==NULL)
        return;
    NodoProducto* temporal = this->inicio;
    tablas->clearContents();
    int i=0;
    do {
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
        i++;
    }
    while (temporal!=this->inicio);
}

void listaProducto::llenarCodigo(QTableWidget *tablas){
    if(this->inicio==NULL)
        return;
    NodoProducto * temporal = this->inicio;
    tablas->clear();
    for(int i=0; temporal =NULL; i++){
        QTableWidgetItem* codigoObjeto = new QTableWidgetItem(temporal->getCodigo());
        tablas->setRowCount(i+1);
        tablas->setItem(i,0,codigoObjeto);
        temporal=temporal->siguiente;
    }
}

/*
bool listaProducto::yaExiste(NodoProducto *nodo){
    if(!estaVacio()){
        NodoProducto *temporal = this->inicio->siguiente;
        QString compara;
        while (temporal!=this->inicio) {
            compara =temporal->getCodigo();
            if(nodo->compare(compara)==0)
            {
        return true;
    }
            temporal=temporal->siguiente;
        }
         return false;
    }
    else {
        return false;
    }}
*/

/*void listaProducto::eliminarProducto(QString *codigo){
NodoProducto *auxiliar = this->inicio;
if(auxiliar!=NULL){
    while ((auxiliar->siguiente!=this->inicio)&&(auxiliar->getCodigo().compare(codigo)!=0)&&tamao()==1) {
        auxiliar=auxiliar->siguiente;

    }
    if(auxiliar->getCodigo().compare(codigo)==0){
        i
    }
}
}*/

void listaProducto::eliminarListaProducto(QString nombre){
    NodoProducto *temporal = new NodoProducto();
    NodoProducto *auxiliar = new NodoProducto();
    temporal=this->inicio;
    auxiliar=this->final;
    bool elim=false;
    if(inicio!=NULL){
do{
            if(temporal->getCodigo().compare(nombre)==0 && temporal==this->inicio && tamao()==1){
        auxiliar = this->inicio;
        temporal->siguiente=NULL;
        temporal->anterior=NULL;
        this->inicio=NULL;
        this->final=NULL;
        cantidad=0;
        elim=true;

    }
            if(temporal->getCodigo().compare(nombre)==0 && temporal==this->inicio){
                temporal->anterior->siguiente=temporal->siguiente;
                temporal->siguiente->anterior=temporal->anterior;
                this->inicio=temporal->siguiente;
                elim=true;
            }
            else if (temporal->getCodigo().compare(nombre)==0 && tamao()>1){
                temporal->anterior->siguiente=temporal->siguiente;
                temporal->siguiente->anterior=temporal->anterior;
                elim=true;
            }
            temporal=temporal->siguiente;
           } while (auxiliar!=this->inicio && !elim && tamao()!=0); {
                auxiliar=NULL;
            }

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


void listaProducto::escribirProducto(){
NodoProducto *aux = this->inicio;
    QFile file("out.dot");
    if (!file.open(QFile::WriteOnly | QFile::Text))
return;
    {
     {
        if(this->cantidad>0){

            QTextStream out(&file);
            out << "digraph g {\n";
            out << "node [shape=box];" << "\n";
            out << "label=\"PRODUCTO" << " Productos " << "\";" << "\n";
            out.flush();

            while(aux!=NULL)
            {

                if(aux->siguiente!=NULL)
                {
                    out << "\"CODIGO: " << aux->getCodigo() << " | Nom: " << aux->getNombre() << " | Precio: " << aux->getPrecio() << "\"->\"Codigo: " <<  aux->siguiente->getCodigo() << " | Nombre: " << aux->siguiente->getNombre() << " | Precio: " << aux->siguiente->getPrecio() << "\";" << "\n";
                }
                else
                {
                    out << "\"Codigo: " << aux->getCodigo() << " | Nombre: " << aux->getNombre() << " | Precio: " << aux->getPrecio() << "\";" << "\n";
                }
                aux=aux->siguiente;
            }
            out << "}" << "\n";
            out.atEnd();
            system("dot -Tpng out.dot -o out.png");

        }
        else{

        }
    }
    }
}



