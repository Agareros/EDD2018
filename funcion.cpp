#include "funcion.h"
#include <sstream>
#include <iostream>
#include <iosfwd>
#include <stdlib.h>
#include <qfile.h>
using namespace std;

listaProducto *listaProductos;
/*bool escribeProductos(){

    QTextStream archivo;
    archivo.open("Productos.dot");
    if(archivo.fail())
    {
        return false;
    }
    else
    {
       listaProductos->escribirProducto(archivo);

        archivo.close();
        system("dot -Tpng Productos.dot -o Productos.png");

        return true;
    }
}*/
bool escribeProductos(){
    std::ofstream archivo;
    archivo.open("Productos.dot");
    if(archivo.fail()){
        return false;
    }
    else {
        listaProductos->escribirProducto();
        archivo.close();
        system("dot -Tpng Productos.dot -o Productos.png");
        return true;
    }

/*
void imagen(QString cuerpo, const QString codigo){
    QTextStream out(&archivo);
    QFile archivo("C:\\Users\\Navarro\\Documents\\EDD\\EDD_Practica\\"+codigo+".txt",ios::out);
    if(!archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    out<<cuerpo;
    archivo.close();
    QString dot = "dot -Tjpg ""C:\\Users\\Navarro\\Documents\\EDD\\EDD_Practica\\" +codigo+".txt -o C:\\Users\\Navarro\\Documents\\EDD\\EDD_Practica\\"+codigo+".jpg";
    system(dot.QString().toStdString().c_str());
    */
}

