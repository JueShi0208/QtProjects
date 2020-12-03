#include <QApplication>
#include "svgaplayer.h"
#include "svgagdicanvas.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	SvgaPlayer player;
	SvgaGDICanvas w;
	w.setFixedSize(500, 500);
	player.setCanvas(&w);
	player.setLoops(true);
	player.play("test.svga");


    /*可以注释这几行 来观察现象 */
    w.setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.setAttribute(Qt::WA_TransparentForMouseEvents);
    /***/
	w.show();

	return app.exec();
}
