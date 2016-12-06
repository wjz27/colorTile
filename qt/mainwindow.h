#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void nextStage();
    void previousStage();
    void setup();
    QColor genColor();
    QColor genColor(int delta);

private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_previous_clicked();

    void on_pushButton_quit_clicked();

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    int m_size;
    int m_targRow;
    int m_targColumn;
    int m_tableWigetSize;
};

#endif // MAINWINDOW_H
