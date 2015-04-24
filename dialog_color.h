#ifndef DIALOG_COLOR_H
#define DIALOG_COLOR_H

#include <QDialog>

namespace Ui {
class dialog_color;
}

class dialog_color : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_color(QWidget *parent = 0);
    ~dialog_color();

public slots:
	void emitvolcol(int);
	void emitwincol(int);

signals:
	void volcol(double);
	void wincol(double);

private:
    Ui::dialog_color *ui;
};

#endif // DIALOG_COLOR_H
