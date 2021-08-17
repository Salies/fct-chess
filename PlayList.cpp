#include "PlayList.h"
#include <QHeaderView>

PlayList::PlayList() {
	verticalHeader()->hide();
	setColumnCount(2);
	setRowCount(1);
	setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
	setEditTriggers(QAbstractItemView::NoEditTriggers);

	setColumnWidth(0, 64);
	setColumnWidth(1, 64);
	setMaximumWidth(130);

	setHorizontalHeaderLabels({"Lado", "Jogada"});
}