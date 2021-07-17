#include "StatusBar.h"

StatusBar::StatusBar() {
	play = new QLabel;
	hash = new QLineEdit;
	play->setText(QStringLiteral("Aguardando início do jogo."));
	play->setStyleSheet("font-size:14px; color: #fff");
	hash->setPlaceholderText("Hash do tabuleiro");
	hash->setStyleSheet("QLineEdit { background: #fff;}");
	addWidget(play);
	addStretch();
	addWidget(hash);
}