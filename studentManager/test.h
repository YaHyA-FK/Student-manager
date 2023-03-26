#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"studentindex.h"
namespace Ui {
class test;
}

class test : public QDialog
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);
    ~test();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::test *ui;
    QSqlDatabase db;
    studentIndex *p;
};

#endif // TEST_H
