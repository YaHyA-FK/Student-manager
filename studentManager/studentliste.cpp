#include "studentliste.h"
#include "ui_studentliste.h"
#include<QMessageBox>
studentliste::studentliste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentliste)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/fekya/OneDrive/Bureau/3iir/s1/studentManager/biblio.db");

}

studentliste::~studentliste()
{
    delete ui;
}

void studentliste::on_pushButton_clicked()
{
    if(!db.open()){
         QMessageBox::information(this,tr("failed to open the database"),tr("failed to open the database"));
    }
    else {
        QSqlQuery requete;
        requete.exec("select count(*) from etudiant");
        int l(0);
        while (requete.next()) {
            l=requete.value(0).toInt();
        }

        model= new QStandardItemModel(l,5);
        int row(0);
        requete.exec("select * from etudiant");
        while (requete.next()) {
            for (int j=0;j<6;j++) {
                QStandardItem *ithem =new QStandardItem(requete.value(j).toString());
                model->setItem(row,j,ithem);
            }
            row++;
        }
        model->setHeaderData(0,Qt::Horizontal,"StudentNumber");
        model->setHeaderData(1,Qt::Horizontal,"First Name");
        model->setHeaderData(2,Qt::Horizontal,"Last Name");
        model->setHeaderData(3,Qt::Horizontal,"StudentClass");
        model->setHeaderData(4,Qt::Horizontal,"Adress");
        model->setHeaderData(5,Qt::Horizontal,"Password");

        ui->tableView->setModel(model);
    }
}

void studentliste::on_pushButton_2_clicked()
{
    close();
}

void studentliste::on_pushButton_3_clicked()
{
    p= new studentIndex(this);
    p->show();

}
