#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
namespace Ui {
class addstudent;
}

class addstudent : public QDialog
{
    Q_OBJECT

public:
    explicit addstudent(QWidget *parent = nullptr);
    ~addstudent();

private slots:
    void on_pushButton_clicked();

    void on_submit_clicked();

private:
    Ui::addstudent *ui;
    QSqlDatabase db;

};

#endif // ADDSTUDENT_H
