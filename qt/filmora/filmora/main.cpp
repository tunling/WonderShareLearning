#include "filmora.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	filmora w;
	w.setWindowFlags(Qt::FramelessWindowHint);
	w.setAttribute(Qt::WA_StyledBackground);
	//w.setAttribute(Qt::WA_TranslucentBackground);
	w.setAttribute(Qt::WA_Hover);
	w.show();
	return a.exec();
}
