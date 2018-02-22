#ifndef LECTURAJSON_H
#define LECTURAJSON_H
#include "listaproducto.h"
#include "clientes.h"
#include <iostream>

class lecturaJson
{
public:
    static void fillListFromFile(listaProducto *list, QByteArray json);
    static void fillListFromFileCliente(Clientes *lista, QByteArray jsonC);
};

#endif // LECTURAJSON_H
