#include "filmora.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// ¶ÁÈ¡QSSÎÄ¼þ
	QFile file("wqss.qss");
	if (file.open(QFile::ReadOnly)) 
	{
		QString styleSheet = QLatin1String(file.readAll());
		a.setStyleSheet(styleSheet);
		file.close();
	}
	else
	{
		QMessageBox::warning(NULL, "warning", "Open failed", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}

	filmora w;
	w.setWindowFlags(Qt::FramelessWindowHint);
	w.setAttribute(Qt::WA_StyledBackground);
	// w.setAttribute(Qt::WA_TranslucentBackground);
	w.setAttribute(Qt::WA_Hover);
	w.show();
	return a.exec();
}
