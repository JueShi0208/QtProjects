#include "widget.h"
#include <QApplication>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget();
    w->Sequent();
    w->show();


    //平移动作1
    QPropertyAnimation* m_pos1Animation = new QPropertyAnimation(w, "pos");
    m_pos1Animation->setDuration(500);
    m_pos1Animation->setStartValue(QPoint(100,100));
    m_pos1Animation->setEndValue(QPoint(200, 200));


    //停留动作1 为翻转
    QPropertyAnimation* m_stay1Animation = new QPropertyAnimation(w, "pos");
    m_stay1Animation->setDuration(500);


    //停留动作2 为光影
    QPropertyAnimation* m_stay2Animation = new QPropertyAnimation(w, "pos");
    m_stay2Animation->setDuration(1000);

    //平移动作3
    QPropertyAnimation* m_pos2Animation = new QPropertyAnimation(w, "pos");
    m_pos2Animation->setDuration(500);
    m_pos2Animation->setStartValue(QPoint(200,200));
    m_pos2Animation->setEndValue(QPoint(500, 500));


    //串行动画组
    QSequentialAnimationGroup *m_SeqAnimation = new QSequentialAnimationGroup();

    m_SeqAnimation->addAnimation(m_pos1Animation);
    m_SeqAnimation->addAnimation(m_stay1Animation);
    m_SeqAnimation->addAnimation(m_stay2Animation);
    m_SeqAnimation->addAnimation(m_pos2Animation);

    m_SeqAnimation->start();


    return a.exec();

}
