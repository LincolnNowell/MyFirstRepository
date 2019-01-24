#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    int player_turn = 1;
    int player_id = 1;
    bool is_tie;
    bool is_win;
    char board[3][3] = {'*','*','*',
                        '*','*','*',
                        '*','*','*'};
    bool tie(char board[3][3]);

    bool win(char board[3][3]);

    void TieGame(bool Game_Status);

    void EndGame(bool Game_Status);
};

#endif // MAINWINDOW_H
