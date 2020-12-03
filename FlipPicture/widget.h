#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <FlipView.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void Sequent();
    void Clean();
private:
    Ui::Widget *ui;
    FlipView* m_view;
};

#endif // WIDGET_H
