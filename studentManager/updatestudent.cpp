#include "updatestudent.h"
#include "ui_updatestudent.h"
#include<QMessageBox>

updatestudent::updatestudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updatestudent)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/fekya/OneDrive/Bureau/3iir/s1/studentManager/biblio.db");
}

updatestudent::~updatestudent()
{
    delete ui;
}

void updatestudent::on_pushButton_clicked()
{
    QString code,fname,lname,password,adresse,classe,passwordconfirmation;
    code=ui->lineEdit->text();
    fname=ui->lineEdit_2->text();
    lname=ui->lineEdit_3->text();
    adresse=ui->lineEdit_5->text();
    password=ui->lineEdit_6->text();
    classe=ui->lineEdit_4->text();
    passwordconfirmation=ui->lineEdit_7->text();
    if(!db.open()){
         QMessageBox::information(this,tr("failed to open the database"),tr("failed to open the database"));
    }
    QSqlQuery q;
   q.prepare("update etudiant set first_name=:fname,last_name=:lastname,adresse=:adresse,class=:classe,password=:password where code=:code");
   q.bindValue(":fname",fname);
   q.bindValue(":lastname",lname);
   q.bindValue(":classe",classe);
   q.bindValue(":adresse",adresse);
    q.bindValue(":code",code);
   q.bindValue(":password",password);

    if(q.exec()){
        QMessageBox::information(this,tr("Success"),tr("The Information has been changed ;"));
    }
    else {
        QMessageBox::warning(this,tr("error"),tr("error!!!"));}
}

void updatestudent::on_pushButton_2_clicked()
{
    close();
}

void updatestudent::on_pushButton_3_clicked()
{
    p= new studentIndex(this);
    p->show();
}
