#include "studentindex.h"
#include "ui_studentindex.h"
#include"studentliste.h"
#include"test.h"
#include"updatestudent.h"
#include<QMessageBox>

studentIndex::studentIndex(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studentIndex)
{
    ui->setupUi(this);


    mydb =QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/fekya/OneDrive/Bureau/3iir/s1/studentManager/biblio.db");


    if(!mydb.open()){
        ui->label->setText("failed to open database");
    }
    else {
        ui->label->setText("connected");
    }
}

studentIndex::~studentIndex()
{
    delete ui;
}

void studentIndex::on_pushButton_clicked()
{

    QString uname,psswd;
    uname=ui->nameinput->text();
    psswd=ui->passwordinput->text();
    if(!mydb.isOpen()){

        qDebug()<<"failed to open the database";
        return;
    }
    QSqlQuery q;
    if(q.exec("select * from teacher where first_name='"+uname+"' and password='"+psswd+"'")){
            ui->label->setText("faild");
       int c=0;
       while(q.next()){
           c++;}
       if(c==1){
           ui->label->setText("username and password are correct");
           test add;
           add.setModal(true);
           close();
           add.exec();

       }
        else if(c==0){

            ui->label->setText("username and password are not correct");
        }
        else if(c>1){
            ui->label->setText("duplicate student delete or update one!!");
        }

    }
    else {
            ui->label->setText("failyd");}


    }


void studentIndex::on_pushButton_2_clicked()
{
    QString uname,psswd;
    uname=ui->nameinput->text();
    psswd=ui->passwordinput->text();
    if(!mydb.isOpen()){

        qDebug()<<"failed to open the database";
        return;
    }
    QSqlQuery q;
    if(q.exec("select * from etudiant where first_name='"+uname+"' and password='"+psswd+"'")){
            ui->label->setText("faild");
       int c=0;
       while(q.next()){
           c++;}
       if(c==1){
           ui->label->setText("username and password are correct");
           studentliste add;
           add.setModal(true);
           close();
           add.exec();
       }
        else if(c==0){

            ui->label->setText("username and password are not correct");
        }
        else if(c>1){
            ui->label->setText("duplicate student delete or update one!!");
        }

    }
    else {
            ui->label->setText("faild");}

}

void studentIndex::on_pushButton_3_clicked()
{
    QString uname,psswd;
    uname=ui->nameinput->text();
    psswd=ui->passwordinput->text();
    if(!mydb.isOpen()){

        qDebug()<<"failed to open the database";
        return;
    }
    QSqlQuery q;
    if(q.exec("select * from etudiant where first_name='"+uname+"' and password='"+psswd+"'")){
            ui->label->setText("faild");
       int c=0;
       while(q.next()){
           c++;}
       if(c==1){
           ui->label->setText("username and password are correct");
           updatestudent add;
           add.setModal(true);
           close();
           add.exec();
       }
        else if(c==0){

            ui->label->setText("username and password are  not correct");
        }
        else if(c>1){
            ui->label->setText("duplicate student delete or update one!!");
        }

    }
    else {
            ui->label->setText("faild");}
}

void studentIndex::on_pushButton_4_clicked()
{
    QString uname,psswd,code;
    uname=ui->nameinput->text();
    psswd=ui->passwordinput->text();
    if(!mydb.isOpen()){

        qDebug()<<"failed to open the database";
        return;
    }
    QSqlQuery q;
    if(q.exec("select * from etudiant where first_name='"+uname+"' and password='"+psswd+"'")){
            ui->label->setText("faild");
       int c=0;
       while(q.next()){
           c++;}
       if(c==1){
           code=ui->lineEdit->text();
           ui->label->setText("username and password is correct");
           q.prepare("delete from etudiant where code=:code");
           q.bindValue(":code",code);
           if(!q.exec()){
               QMessageBox::warning(this,tr("failes"),tr("error!!!"));
           }
           else {
                QMessageBox::warning(this,tr("sucess"),tr("The Student has been deleted"));
                ui->label_5->setText("The student number :"+code+" has been deleted");
           }

       }
        else if(c==0){
           ui->label_5->setText("You must sign in first!!!!");
            ui->label->setText("username and password are  not correct");
        }
        else if(c>1){
            ui->label->setText("duplicate student delete one!!");
        }

    }
    else {
            ui->label->setText("faild");}

}
