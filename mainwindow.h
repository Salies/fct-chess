#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMainWindow>
#include "PlayList.h"
#include "StatusBar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    QWidget* centralWidget;
    QVBoxLayout* centralLayout;
    StatusBar* statusBar;
    void createChessBoard();
    void crateStatusBar();
};
