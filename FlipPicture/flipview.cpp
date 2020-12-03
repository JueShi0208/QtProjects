#include "flipview.h"
#include <QPainter>
#include <qDebug>



FlipView::FlipView(QWidget *parent):QGraphicsView(parent)
{
    setStyleSheet("background: transparent;border:0px");
    //setAttribute(Qt::WA_TranslucentBackground);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportUpdateMode(FullViewportUpdate);
    setCacheMode(CacheBackground);
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
    m_pScne = new QGraphicsScene();
    this->setScene(m_pScne);
    m_picture = new Picture();
    m_pScne->addItem(m_picture);

}

void FlipView::resizeEvent(QResizeEvent *event)
{
    fitInView(m_picture, Qt::KeepAspectRatioByExpanding);
}

void FlipView::Sequent()
{
    m_picture->Sequent();
}

void FlipView::Clean()
{
    m_picture->Clean();
}
