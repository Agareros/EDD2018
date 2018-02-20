#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>;
#include <QPixmap>
#include <QLabel>
#include <QBoxLayout>
#include "lecturajson.h"
#include "iostream"
#include <QMessageBox>
#include "listaproducto.h"
#include "funcion.h"
using namespace std;
QVBoxLayout *lay = new QVBoxLayout();
QLabel *d;
bool yaAbri = false;
bool yaImg = false;
listaProducto *lista = new listaProducto();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->listaDobleProducto = new listaProducto();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->listaDobleProducto;
}

void MainWindow::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(NULL, tr("JSON de Productos"));
    if(fileName.isEmpty())
        return;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QByteArray ba = file.readAll();
    free(this->listaDobleProducto );
    this->listaDobleProducto = NULL;
    this->listaDobleProducto = new listaProducto();
    lecturaJson::fillListFromFile(this->listaDobleProducto, ba);
    this->listaDobleProducto->llenarTabla(ui->tableWidget);
}

void MainWindow::on_insertarBoton_clicked()
{
    QString codigo = ui->insertarCodigo->text();
    QString precio = ui->insertarPrecio->text();
    QString nombre = ui->insertarNombre->text();
    QString descripcion = ui->insertarDescripcion->text();
    NodoProducto* nodo = new NodoProducto(codigo, precio, nombre, descripcion);
    this->listaDobleProducto->insertar(nodo);
    this->updateCustomerTable();
}

void MainWindow::updateCustomerTable(){
    this->listaDobleProducto->llenarTabla(ui->tableWidget);
}



void MainWindow::on_pushButton_clicked()
{
    /*if(escribeProductos())
    {
        QPixmap img("Productos.png");
        QLabel* l = new QLabel();
        d = l;
        l->setPixmap(img);
        l->setFixedSize(img.size());
        l->repaint();
        ui->scrollAreaP->setLayout(lay);

    //imagen(lista->cuerpo(),"producto");

}
*/
    if(escribeProductos()){
        QPixmap img("Productos.png");
        QLabel* l = new QLabel();
        d = l;
        l->setPixmap(img);
        l->setFixedSize(img.size());
        l->repaint();
        lay->addWidget(l);
        ui->scrollAreaP->setLayout(lay);
    }
}

/*/oid MainWindow::ponerimagen(QString codigo){
    QString ruta = "C:\\Users\\Navarro\\Documents\\EDD\\EDD_Practica\\"+codigo+".jpg";
    int w = ui->repo->width();
    int h = ui->repo->height();
    QPixmap msp(ruta.toStdString().c_str());
    ui->repo->setPixmap(msp.scaled(w,h,Qt::KeepAspectRatio));
}/*/
