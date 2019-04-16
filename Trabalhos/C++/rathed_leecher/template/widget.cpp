/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableView *playlistView;
    QLabel *currentTrack;
    QProgressBar *progressBar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_add;
    QToolButton *btn_previous;
    QToolButton *btn_play;
    QToolButton *btn_pause;
    QToolButton *btn_stop;
    QToolButton *btn_next;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(482, 300);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        playlistView = new QTableView(Widget);
        playlistView->setObjectName(QString::fromUtf8("playlistView"));
        playlistView->setGeometry(QRect(10, 90, 441, 201));
        currentTrack = new QLabel(Widget);
        currentTrack->setObjectName(QString::fromUtf8("currentTrack"));
        currentTrack->setGeometry(QRect(140, 70, 161, 16));
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 40, 451, 20));
        progressBar->setValue(24);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 10, 414, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_add = new QToolButton(widget);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/buttons/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon);

        horizontalLayout->addWidget(btn_add);

        btn_previous = new QToolButton(widget);
        btn_previous->setObjectName(QString::fromUtf8("btn_previous"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/buttons/skip-previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_previous->setIcon(icon1);

        horizontalLayout->addWidget(btn_previous);

        btn_play = new QToolButton(widget);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/buttons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon2);

        horizontalLayout->addWidget(btn_play);

        btn_pause = new QToolButton(widget);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/buttons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause->setIcon(icon3);

        horizontalLayout->addWidget(btn_pause);

        btn_stop = new QToolButton(widget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/buttons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_stop->setIcon(icon4);

        horizontalLayout->addWidget(btn_stop);

        btn_next = new QToolButton(widget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/buttons/skip-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon5);

        horizontalLayout->addWidget(btn_next);

        horizontalSpacer = new QSpacerItem(238, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Simple Audio Player", nullptr));
        currentTrack->setText(QString());
        btn_previous->setText(QApplication::translate("Widget", "...", nullptr));
        btn_play->setText(QApplication::translate("Widget", "...", nullptr));
        btn_pause->setText(QApplication::translate("Widget", "...", nullptr));
        btn_stop->setText(QApplication::translate("Widget", "...", nullptr));
        btn_next->setText(QApplication::translate("Widget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WIDGET_H
