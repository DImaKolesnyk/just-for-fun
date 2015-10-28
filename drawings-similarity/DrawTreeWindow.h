#ifndef DRAWTREEWINDOW_H
#define DRAWTREEWINDOW_H

#include <QMainWindow>

namespace Ui {
class DrawTreeWindow;
}

class DrawTreeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawTreeWindow(QWidget *parent = 0);
    ~DrawTreeWindow();

private:
    Ui::DrawTreeWindow *ui;
};

#endif // DRAWTREEWINDOW_H
