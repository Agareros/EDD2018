#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listaproducto.h"
#include <iostream>

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

private:
    Ui::MainWindow *ui;
    void updateCustomerTable();
    listaProducto *listaDobleProducto;
   };

#endif // MAINWINDOW_H
