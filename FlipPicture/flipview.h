#ifndef FLIPVIEW_H
#define FLIPVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "picture.h"

//视图
class FlipView : public QGraphicsView
{
    Q_OBJECT
public:
    FlipView(QWidget *parent = Q_NULLPTR);
    void resizeEvent(QResizeEvent *event);
    void Sequent();
    void Clean();
private:
    QGraphicsScene* m_pScne;   //场景
    Picture*        m_picture; //图片Item
};

#endif // FLIPVIEW_H
