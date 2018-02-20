#ifndef LECTURAJSON_H
#define LECTURAJSON_H
#include "listaproducto.h"
#include <iostream>

class lecturaJson
{
public:
    static void fillListFromFile(listaProducto *list, QByteArray json);

};

#endif // LECTURAJSON_H
