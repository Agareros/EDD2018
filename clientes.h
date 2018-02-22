#ifndef CLIENTES_H
#define CLIENTES_H
#include "factura.h"
#include <QTableWidget>
#include <QString>

class NodoCliente{
  public:
    NodoCliente* siguiente;
    NodoCliente();
    NodoCliente(QString nit, QString nombre, int listafactura);

    bool equals(NodoCliente *otro);
    QString getNit();
    QString getNombreCliente();
    int getListaFactura();
    void setNit(QString nit);
    void setNombre(QString nombre);
    void setListaFactura(int listafactura);
    QString nombre;
    QString nit;

    int listafactura;
private:

};

class Clientes
{
public:
    Clientes();
    void insertar(NodoCliente* nodo);
    NodoCliente* encontrar(NodoCliente* nodo);
    void editar (NodoCliente* antes, NodoCliente*nodo);
    NodoCliente *eliminar(NodoCliente* nodo);
    void borrar();
    int tamao();
    bool estaVacio();
    void llenarTablero(QTableWidget* tabla);
        Clientes *buscaCliente(QString nit);

private:
    int cantidad;
    NodoCliente* inicio;
    NodoCliente* final;
    bool insertarPrimero(NodoCliente* nodo);
    void insertarInicio(NodoCliente *nodo);
    void insertarFinal(NodoCliente *nodo);

};

#endif // CLIENTES_H
