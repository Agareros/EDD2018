#ifndef LISTAPRODUCTO_H
#define LISTAPRODUCTO_H
#include <QString>
#include <QTableWidget>
#include <fstream>
#include <iostream>


class NodoProducto{
private:



public:
    QString Codigo;
    QString Nombre;
    QString Precio;
    QString Descripcion;
    NodoProducto* siguiente;
    NodoProducto* anterior;
    NodoProducto();
    NodoProducto(QString Codigo, QString Precio, QString Nombre, QString Descripcion);
    bool equals(NodoProducto* varios);
    int compare(NodoProducto* varios);
    QString getCodigo();
    QString getNombre();
    QString getDescripcion();
    QString getPrecio();
    void setCodigo(QString Codigo);
    void setNombre(QString Nombre);
    void setDescripcion(QString Descripcion);
    void setPrecio(QString Precio);

};



class listaProducto
{
private:
    int cantidad;
    NodoProducto* inicio;
    NodoProducto* final;
    bool primeraInsercion(NodoProducto* nodo);
    void insertarPrimero(NodoProducto* nodo);
    void insertarFinal(NodoProducto* nodo);
    void insertar(NodoProducto* nodo, NodoProducto* a, NodoProducto* z, int rango);
    void insertarAntes(NodoProducto* nodo, NodoProducto* pivote);
    void insertarDespues(NodoProducto* nodo, NodoProducto* pivote);
      void sameRank(std::stringstream &archivo);

public:
    listaProducto();
    void insertar(NodoProducto* nodo);
    NodoProducto* encontrar(NodoProducto* nodo);
    void editar(NodoProducto* antiguo, NodoProducto* nodo);
    NodoProducto* eliminar(NodoProducto* nodo);
    void limpiar();
    int tamao();
    bool estaVacio();
    void llenarTabla(QTableWidget* tablas);

    //void escribirProducto(std::stringstream &archivo);
    void escribirProducto(QTextStream &archivo);
    void escribirProductos(std::stringstream &archivo);
    void enlistaProductoDOT(std::stringstream &archivo);
    void graficarProducto(listaProducto *listas);
    QString cuerpo();
};

#endif // LISTAPRODUCTO_H
