#pragma once
#include <QtWidgets/QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
class StatusBar : public QHBoxLayout
{
public:
	QLabel* play;
	QLineEdit* hash;
	StatusBar();
	//void setPlay(bool mach, Play play);
	void setWait(bool mach);
};

