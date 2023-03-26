#include "test.h"
#include "ui_test.h"
#include<QMessageBox>
#include"studentindex.h"


test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/fekya/OneDrive/Bureau/3iir/s1/studentManager/biblio.db");

}

test::~test()
{
    delete ui;
}

void test::on_pushButton_clicked()
{
     QString filier=ui->comboBox_3->currentText();
      QString year=ui->comboBox_2->currentText();
     QString fname,lname,p,adresse;
     fname=ui->lineEdit->text();
     lname=ui->lineEdit_2->text();
     adresse=ui->lineEdit_3->text();
     p=ui->lineEdit_4->text();
     if(fname=="" || lname=="" || p=="" || filier=="choose one ..." || year=="choose one ..."){
         ui->label->setText("fields are empty!!!");
     }
     else{
     if(!db.open()){
          QMessageBox::information(this,tr("failed to open the database"),tr("failed to open the database"));
     }
     QSqlQuery q;
    q.prepare("insert into etudiant(first_name,last_name,adresse,class,password) values(:fname,:lastname,:adresse,:classe,:password)");
    q.bindValue(":fname",fname);
    q.bindValue(":lastname",lname);
    q.bindValue(":classe",filier+" "+year);
    q.bindValue(":adresse",adresse);

    q.bindValue(":password",p);

     if(q.exec()){
         QMessageBox::information(this,tr("sucess"),tr("Student has been added secessfully"));
     }
     else {
         QMessageBox::information(this,tr("error insertion"),tr("error!!!"));}
     }
}

void test::on_pushButton_2_clicked()
{
    close();

}



void test::on_pushButton_3_clicked()
{
        p= new studentIndex(this);
        p->show();


}
