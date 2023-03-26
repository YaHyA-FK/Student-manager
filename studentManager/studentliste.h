#ifndef STUDENTLISTE_H
#define STUDENTLISTE_H
#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"QStandardItem"
#include"studentindex.h"

namespace Ui {
class studentliste;
}

class studentliste : public QDialog
{
    Q_OBJECT

public:
    explicit studentliste(QWidget *parent = nullptr);
    ~studentliste();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::studentliste *ui;
      QSqlDatabase db;
      QStandardItemModel *model;
      studentIndex *p;
};

#endif // STUDENTLISTE_H
