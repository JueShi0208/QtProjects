#include "picture.h"
#include <QPainter>

Picture::Picture(QGraphicsItem *parent):QGraphicsObject(parent)
{
    m_pixMap = QPixmap(":/flucard.png");
    m_pixBG = QPixmap(":/flucard.png");
    m_pixShadow = QPixmap (":/shadow.png");
    m_itemRotation = new QGraphicsRotation(this);
    m_itemRotation->setAxis(Qt::YAxis);
    m_itemRotation->setOrigin(QVector3D(boundingRect().width()/2,0,0));
    this->setTransformations(QList<QGraphicsTransform *>()<<m_itemRotation);
    this->setTransformOriginPoint(this->boundingRect().center());

    //缩放和放大需要这个
    QPropertyAnimation* roateAnimation = new QPropertyAnimation(m_itemRotation, "angle");
    roateAnimation->setDuration(500);

    /********************************************************************************/
    //放大
    m_zoomOutAnimation = new QParallelAnimationGroup(this);
    QPropertyAnimation* zoomoutAnimation = new QPropertyAnimation(this,"scale");
    zoomoutAnimation->setDuration(500);
    zoomoutAnimation->setStartValue(0);
    zoomoutAnimation->setKeyValueAt(0.3,0.5);
    zoomoutAnimation->setEndValue(1);
    m_zoomOutAnimation->addAnimation(roateAnimation);
    m_zoomOutAnimation->addAnimation(zoomoutAnimation);
    /********************************************************************************/

    //翻转
    /********************************************************************************/
    qreal qangle = m_itemRotation->angle();
    m_roateAnimation = new QPropertyAnimation(m_itemRotation, "angle");//m_itemRotation
    m_roateAnimation->setDuration(500);
    m_roateAnimation->setStartValue(qangle);
    m_roateAnimation->setEndValue(qangle + 360);
    /********************************************************************************/

    /********************************************************************************/
    //停留一会儿 实现光影
    m_stayAnimation = new QPropertyAnimation(this);
    m_stayAnimation->setDuration(1000);
    m_timeId = 0;

    //m_pStartTimer和m_pKillTimer都是单次触发
    m_pStartTimer = new QTimer(this);
    m_pKillTimer = new QTimer(this);
    m_pStartTimer->singleShot(1000, this, SLOT(startShadow()));//1000毫秒 之后开始timerEvent事件
    m_pKillTimer->singleShot(2000, this, SLOT(stopShadow()));//3000毫秒 之后停止timerEvent事件
    /********************************************************************************/


    //缩放
    /********************************************************************************/
    m_zoomInAnimation = new QParallelAnimationGroup(this);
    QPropertyAnimation* zoominAnimation = new QPropertyAnimation(this,"scale");
    zoominAnimation->setDuration(500);
    zoominAnimation->setStartValue(1);
    zoominAnimation->setKeyValueAt(0.3,0.5);
    zoominAnimation->setEndValue(0);
    m_zoomInAnimation->addAnimation(roateAnimation);
    m_zoomInAnimation->addAnimation(zoominAnimation);

    /********************************************************************************/

    //串行动画
    m_SeqAnimation = new QSequentialAnimationGroup();
    m_SeqAnimation->addAnimation(m_zoomOutAnimation);
    m_SeqAnimation->addAnimation(m_roateAnimation);
    m_SeqAnimation->addAnimation(m_stayAnimation);
    m_SeqAnimation->addAnimation(m_zoomInAnimation);

}

void Picture::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),m_pixMap,QRectF());
}

void Picture::timerEvent(QTimerEvent *event)
{
    //这里实现光影效果

    QPainter painter(&m_pixMap);//m_pixMap
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter.drawPixmap(boundingRect(),m_pixBG,QRectF());//m_pixBG
    painter.drawPixmap(m_posx,m_posy,m_pixShadow);//m_pixBG
    this->update();
    m_posx = m_posx + 10;
    m_posy = m_posy + 10;

}

QRectF Picture::boundingRect() const
{
    QRectF rect;

    rect |= QRectF(0,0,m_pixMap.width(),m_pixMap.height());

    return rect;
}

void Picture::Roll()
{
    //翻转
    m_roateAnimation->start();
}


void Picture::ZoomIn()
{
    m_zoomInAnimation->start();

}
void Picture::ZoomOut()
{

    m_zoomOutAnimation->start();
}

void Picture::Clean()
{
    m_zoomOutAnimation->stop();
    m_zoomInAnimation->stop();
    m_roateAnimation->stop();
    m_stayAnimation->stop();
    m_SeqAnimation->stop();
}

void Picture::Sequent()
{
    m_SeqAnimation->start();
}

void Picture::startShadow()
{
    m_timeId = startTimer(50);//定时器
    m_posx = -80;//-80
    m_posy = -80;//-80
    qDebug() << "startShadow";
}

void Picture::stopShadow()
{
    //if(m_timeId)
    {
        killTimer(m_timeId);
    }
    qDebug() << "stopShadow";
}
