#ifndef UPDATESTUDENT_H
#define UPDATESTUDENT_H
#include <QDialog>
#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"studentindex.h"

namespace Ui {
class updatestudent;
}

class updatestudent : public QDialog
{
    Q_OBJECT

public:
    explicit updatestudent(QWidget *parent = nullptr);
    ~updatestudent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::updatestudent *ui;
    QSqlDatabase db;
    studentIndex *p;
};

#endif // UPDATESTUDENT_H
