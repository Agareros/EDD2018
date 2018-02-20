#include "lecturajson.h"
#include "time.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QTime>


void lecturaJson::fillListFromFile(listaProducto *list, QByteArray json) {
    QJsonDocument doc = QJsonDocument::fromJson(json);
    if(! doc.isArray()){
        QMessageBox::warning(NULL, "JSON Clientes", "Error en el archivo, el elemento raíz debe ser un arreglo");
        return;
    }
    QJsonArray array = doc.array();
    int max = array.size();

    clock_t t;
    t = clock();
    for(int i = 0; i < max; i++) {
        QJsonValueRef ref = array[i];
        if(! ref.isObject())
            continue;
        QJsonObject objeto = ref.toObject();
        QJsonValue codigoJson = objeto["codigo"];
                if(codigoJson.isUndefined() || codigoJson.isNull())
                    continue;
                QJsonValue precioJson = objeto["precio"];
                if(precioJson.isUndefined() || precioJson.isNull() || precioJson.isDouble())
                    continue;
                QJsonValue nombreJson = objeto["nombre"];
                if(nombreJson.isUndefined() || nombreJson.isNull())
                    continue;
                QJsonValue descripcionJson = objeto["descripcion"];
                if(descripcionJson.isUndefined() || descripcionJson.isNull())
                    continue;
                list->insertar(new NodoProducto(codigoJson.toString(), precioJson.toString(), nombreJson.toString(), descripcionJson.toString()));
    }
    t = clock() - t;
    //QString resume = QString::asprintf("Se cargaron correctamente %d de %d registros en %ld ciclos de reloj.", list->size(), max, t);
    QString resume = QString::asprintf("Se cargaron correctamente %d de %d registros en %f milisegundos.", list->tamao(), max, ((double)t / CLOCKS_PER_SEC) * 1000);
    QMessageBox::information(NULL, "Rendimiento lista doble", resume);
}
