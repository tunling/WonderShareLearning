#include "filmora.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	filmora w;
	w.setWindowFlags(Qt::FramelessWindowHint);
	w.show();
	return a.exec();
}
