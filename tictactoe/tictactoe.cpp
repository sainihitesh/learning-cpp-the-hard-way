#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QPushButton>
#include <QMessageBox>
#include <string>


void tictactoe::helper_func(QPushButton *qp, int id){
    QString label = qp->text();
    std::string s = label.toStdString();
    if(s.empty()){
      ui->label->setText(ttt_Controller.getOpponent()?"O's turn":"X's turn");
      qp->setText(ttt_Controller.getOpponent()?"X":"O");
      ttt_Controller.move(id,ui->label);
    }
}

tictactoe::tictactoe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tictactoe)
{
    this->setFixedSize(155,230);
    ui->setupUi(this);
}

tictactoe::~tictactoe()
{
    delete ui;
}

void tictactoe::on_pushButton_clicked(){
    ttt_Controller.Res[0][0] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton,0);
}

void tictactoe::on_pushButton_2_clicked(){
    ttt_Controller.Res[0][1] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_2,1);
}

void tictactoe::on_pushButton_3_clicked()
{
    ttt_Controller.Res[0][2] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_3,2);
}

void tictactoe::on_pushButton_7_clicked()
{
    ttt_Controller.Res[1][0] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_7,3);
}


void tictactoe::on_pushButton_8_clicked()
{
    ttt_Controller.Res[1][1] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_8,4);
}

void tictactoe::on_pushButton_9_clicked()
{
    ttt_Controller.Res[1][2] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_9,5);
}


void tictactoe::on_pushButton_4_clicked()
{
    ttt_Controller.Res[2][0] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_4,6);
}

void tictactoe::on_pushButton_5_clicked()
{
    ttt_Controller.Res[2][1] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_5,7);
}


void tictactoe::on_pushButton_6_clicked()
{
    ttt_Controller.Res[2][2] = ttt_Controller.getOpponent()?'X':'O';
    helper_func(ui->pushButton_6,8);
}
