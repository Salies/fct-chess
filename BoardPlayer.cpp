#include "BoardPlayer.h"
#include <QLabel>

BoardPlayer::BoardPlayer(bool mach) {
	QLabel *lbl = new QLabel, *nome = new QLabel(mach ? QStringLiteral("M�quina") : "Jogador");
	lbl->setPixmap(QPixmap(mach ? ":/fctchess/qrc/machine.png" : ":/fctchess/qrc/player.png"));
	nome->setStyleSheet("font-size: 16px; font-weight:600; color: #fff");

	addWidget(lbl);
	addWidget(nome);
	addStretch();
}