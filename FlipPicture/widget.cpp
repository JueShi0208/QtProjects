#include "widget.h"
#include "ui_widget.h"
#include <QLayout>
#include "flipview.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_TransparentForMouseEvents);
    //调试的时候可以关闭一下
    //setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint);
    resize(135,195);
    m_view = new FlipView();
    m_view->setFrameStyle(QFrame::NoFrame);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_view);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::Sequent()
{
    m_view->Sequent();
}

void Widget::Clean()
{
    m_view->Clean();
    this->close();
}
