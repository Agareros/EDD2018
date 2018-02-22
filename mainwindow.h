#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listaproducto.h"
#include <iostream>
#include "clientes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
       void ponerimagen(QString codigo);
private slots:
    void on_pushButton_9_clicked();

    void on_insertarBoton_clicked();

    void on_pushButton_clicked();

    void on_cargarCliente_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    Ui::MainWindow *uo;
    void updateCustomerTable();
    void updateCustomerTable2();
    listaProducto *listaDobleProducto;
    Clientes *listaClientes;
   };

#endif // MAINWINDOW_H
