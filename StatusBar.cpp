#include "StatusBar.h"

StatusBar::StatusBar() {
	play = new QLabel;
	//hash = new QLineEdit;
	play->setText("Vez das brancas.");
	play->setStyleSheet("font-size:14px; color: #fff");
	//hash->setPlaceholderText("Hash do tabuleiro");
	//hash->setStyleSheet("QLineEdit { background: #fff;}");
	addWidget(play);
	addStretch();
}

void StatusBar::setSide(bool white) {
	if (white) {
		play->setText("Vez das brancas.");
		return;
	}
	play->setText("Vez das pretas.");
	return;
}

void StatusBar::mate(QString tipo) {
	play->setText(tipo + ". Fim de jogo!");
	return;
}