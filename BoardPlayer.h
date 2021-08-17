#pragma once
#include <QtWidgets/QHBoxLayout>
#include <QLabel>
class BoardPlayer : public QHBoxLayout
{
public:
	BoardPlayer(bool mach);
	QLabel* capturadas;
	void setCapturas(QString s);
	void resetCapturas();
};

