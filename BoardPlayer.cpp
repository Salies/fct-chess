#include "BoardPlayer.h"

BoardPlayer::BoardPlayer(bool mach) {
	QLabel *lbl = new QLabel, *nome = new QLabel(mach ? QStringLiteral("Jogador 2") : "Jogador 1");
	lbl->setPixmap(QPixmap(mach ? ":/fctchess/qrc/machine.png" : ":/fctchess/qrc/player.png"));
	nome->setStyleSheet("font-size: 16px; font-weight:600; color: #fff");
	capturadas = new QLabel("");
	capturadas->setStyleSheet("color: #fff; font-size:14px");

	addWidget(lbl);
	addWidget(nome);
	addWidget(capturadas);
	addStretch();
}

void BoardPlayer::setCapturas(QString s) {
	QString a = capturadas->text();
	a += s;
	capturadas->setText(a);
}

void BoardPlayer::resetCapturas() {
	capturadas->setText("");
}