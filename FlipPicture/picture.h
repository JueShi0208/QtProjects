#ifndef PICTURE_H
#define PICTURE_H

#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QGraphicsRotation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QTimerEvent>
#include <QTimer>
#include <QList>

class Picture : public QGraphicsObject
{
    Q_OBJECT
public:
    Picture(QGraphicsItem *parent = Q_NULLPTR);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void Clean();
    void Sequent();
private:
    void Roll();
    void ZoomOut();
    void ZoomIn();
    void timerEvent(QTimerEvent *event);

protected slots:
    void startShadow();
    void stopShadow();
private:
    QPixmap m_pixMap;
    QPixmap m_pixBG;
    QPixmap m_pixShadow;
    QPropertyAnimation*         m_roateAnimation;
    QPropertyAnimation*         m_stayAnimation;
    QParallelAnimationGroup*    m_zoomInAnimation;
    QParallelAnimationGroup*    m_zoomOutAnimation;
    QSequentialAnimationGroup*  m_SeqAnimation;
    QGraphicsRotation*          m_itemRotation;
    QTimer* m_pStartTimer;
    QTimer* m_pKillTimer;
    int m_timeId;
    int m_posx;
    int m_posy;
};

#endif // PICTURE_H
