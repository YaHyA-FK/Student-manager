#include "addstudent.h"
#include "ui_addstudent.h"
#include<QMessageBox>


addstudent::addstudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstudent)
{
    ui->setupUi(this);
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/fekya/OneDrive/Bureau/studentManager/biblio.db");


    if(!db.open()){
         QMessageBox::information(this,tr("failed to open the database"),tr("failed to open the database"));
    }
    else {
    QMessageBox::information(this,tr("connected"),tr("connected"));    }
}

addstudent::~addstudent()
{
    delete ui;
}




void addstudent::on_submit_clicked()
{

    QMessageBox::information(this,tr("insertion effectuer"),tr("l"));
   QString fname,lname,p,classe,adresse;
   fname=ui->lineEdit->text();
   lname=ui->lineEdit_2->text();
   adresse=ui->lineEdit_3->text();
   p=ui->lineEdit_5->text();
   classe=ui->comboBox->currentText();
   if(!db.open()){
        QMessageBox::information(this,tr("failed to open the database"),tr("failed to open the database"));
   }
   QSqlQuery q;


   if(q.exec("insert into etudiant(first-name,last-name,adresse,class,password) values("+fname+","+lname+","+adresse+","+classe+","+p+")")){
       QMessageBox::information(this,tr("insertion effectuer"),tr("les donnes sont bien sauvegarder"));
   }
   else {
       QMessageBox::information(this,tr("error insertion"),tr("error!!!"));}
}

