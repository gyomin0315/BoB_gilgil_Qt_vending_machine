#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

//int money =0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::ifElse()
{
    if(money<100)
    {
        ui->pbCoffee->setEnabled(false);
    }
    else
    {
        ui->pbCoffee->setEnabled(true);
    }
    if(money<150)
    {
        ui->pbTea->setEnabled(false);
    }
    else
    {
        ui->pbTea->setEnabled(true);
    }
    if(money<200)
    {
        ui->pbMilk->setEnabled(false);
    }
    else
    {
        ui->pbMilk->setEnabled(true);
    }
}

void Widget::changeMoney(int diff)
{

    money += diff;
    ui->lcdNumber->display(money);
    ifElse();

}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_Reset_clicked()
{

    QMessageBox mb;

    int moneyLeft = 0;

    int numberOf500 = money/500;
    moneyLeft = money - numberOf500*500;
    auto str500 = "500won : " + QString::number(numberOf500);

    int numberOf100 = moneyLeft/100;
    moneyLeft = moneyLeft - numberOf100*100;
    auto str100 = "100won : " + QString::number(numberOf100);

    int numberOf50 = moneyLeft/50;
    moneyLeft = moneyLeft - numberOf50*50;
    auto str50 = "50won : " + QString::number(numberOf50);

    int numberOf10 = moneyLeft/10;
    auto str10 = "10won : " + QString::number(numberOf10);

    auto strAll = str500 + "\n" + str100 + "\n" + str50 + "\n" + str10;

    mb.information(this,"Change",strAll,"Press to get change");

    money = {0};
    ui->lcdNumber->display(money);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);

}

