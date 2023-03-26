#ifndef STUDENTINDEX_H
#define STUDENTINDEX_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class studentIndex;
}

class studentIndex : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentIndex(QWidget *parent = nullptr);
    ~studentIndex();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::studentIndex *ui;
     QSqlDatabase mydb;
};

#endif // STUDENTINDEX_H
