

#include <peers/Leecher.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <rathed_leecher_autogen/include/ui_widget.h>


int main(int argc, char *argv[])
{
//    QApplication aplication(argc, argv);
//    Ui_Widget play;
//    QWidget parent;
//
//    play.setupUi(&parent);
//
//    parent.show();
//    parent.setWindowTitle(
//            QApplication::translate("toplevel", "Top-level widget"));
//    return aplication.exec();
////
// a.thread();
    Leecher leecher;
    leecher.run("cc72fc24056ced9ce13a287ca1243d48","/home/rafael/Documentos/musicas_testes/stream_voice.mp3");
//    QMainWindow w;
//
//    QVideoWidget videoWidget(&w);
//    w.setCentralWidget(&videoWidget);
//
//    QMediaPlayer *player = new QMediaPlayer(&w);
//
//    player->setMedia( QUrl::fromLocalFile("/home/rafael/teste.mp3") );
//    player->setVideoOutput(&videoWidget);
//
//    w.show();
//
//    player->play();
//
}
