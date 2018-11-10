#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <map>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class tictactoe;
class ttt;
}

//Game logic
class ttt{
    int remainingSteps;
    int opponent; // 0 for 0 , 1 for x
    std::map<int,int>isAvail;
 public:
    char Res[3][3];
    ttt():remainingSteps(9),opponent(1){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                Res[i][j] = 'A';
            }
        }
    }
    int getRemainingSteps(){
        return remainingSteps;
    }
    int getOpponent(){
        return opponent;
    }
    bool Ismovable(){
        return (remainingSteps?true:false);
    }
    void checkIfWon(int opponent,QLabel *qlabel){
        char c = getOpponent()?'X':'O';
        int result=0;
        if(Res[0][0]==c && Res[0][1]==c && Res[0][2]==c){
                result = 1;
        }
        else if(Res[1][0]==c && Res[1][1]==c && Res[1][2]==c){
                result = 1;
        }
        else if(Res[2][0]==c && Res[2][1]==c && Res[2][2]==c){
                result = 1;
        }
        else if(Res[0][0]==c && Res[1][0]==c && Res[2][0]==c){
                result = 1;
        }
        else if(Res[0][1]==c && Res[1][1]==c && Res[2][1]==c){
                result = 1;
        }
        else if(Res[0][2]==c && Res[1][2]==c && Res[2][2]==c){
                result = 1;
        }
        else if(Res[0][0]==c && Res[1][1]==c && Res[2][2]==c){
                result = 1;
        }
        else if(Res[0][2]==c && Res[1][1]==c && Res[2][0]==c){
                result = 1;
        }
        if(result){
            qlabel->setText(getOpponent()?"X won":"O won");
            QMessageBox Msgbox;
            Msgbox.setText(getOpponent()?"X won":"O won");
            Msgbox.exec();
        }
        else if(getRemainingSteps()==0){
            qlabel->setText("Match Draw");
            QMessageBox Msgbox;
            Msgbox.setText("Match Draw");
            Msgbox.exec();
        }
    }
    void move(int id, QLabel *qlabel){
        if(Ismovable()){
            if(isAvail.find(id)==isAvail.end()){
                isAvail[id] = opponent;
                remainingSteps--;
                checkIfWon(opponent,qlabel);
                if(opponent)
                    opponent = 0;
                else
                    opponent = 1;
            }
        }
    }
};

class tictactoe : public QMainWindow
{
    Q_OBJECT

public:
    void helper_func(QPushButton *, int);
    ttt ttt_Controller;
    explicit tictactoe(QWidget *parent = nullptr);
    ~tictactoe();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::tictactoe *ui;
};


#endif // TICTACTOE_H
