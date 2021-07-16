#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    QWidget* centralWidget;
    QVBoxLayout* centralLayout;
    void createChessBoard();
};
