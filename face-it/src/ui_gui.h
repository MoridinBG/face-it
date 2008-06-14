/********************************************************************************
** Form generated from reading ui file 'gui.ui'
**
** Created: Fri Jun 13 21:41:08 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *imageToSearch;
    QVBoxLayout *vboxLayout;
    QLabel *preview;
    QListWidget *listMatches;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QPushButton *pushSearch;
    QPushButton *pushEditNet;
    QHBoxLayout *hboxLayout1;
    QPushButton *pushLoad;
    QPushButton *pushExit;

    void setupUi(QDialog *Dialog)
    {
    if (Dialog->objectName().isEmpty())
        Dialog->setObjectName(QString::fromUtf8("Dialog"));
    Dialog->resize(705, 528);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
    Dialog->setSizePolicy(sizePolicy);
    gridLayout = new QGridLayout(Dialog);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    imageToSearch = new QLabel(Dialog);
    imageToSearch->setObjectName(QString::fromUtf8("imageToSearch"));
    sizePolicy.setHeightForWidth(imageToSearch->sizePolicy().hasHeightForWidth());
    imageToSearch->setSizePolicy(sizePolicy);
    imageToSearch->setMinimumSize(QSize(435, 400));
    imageToSearch->setScaledContents(true);
    imageToSearch->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(imageToSearch, 0, 0, 1, 1);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    preview = new QLabel(Dialog);
    preview->setObjectName(QString::fromUtf8("preview"));
    preview->setMinimumSize(QSize(0, 200));
    preview->setScaledContents(true);

    vboxLayout->addWidget(preview);

    listMatches = new QListWidget(Dialog);
    listMatches->setObjectName(QString::fromUtf8("listMatches"));
    QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(2);
    sizePolicy1.setHeightForWidth(listMatches->sizePolicy().hasHeightForWidth());
    listMatches->setSizePolicy(sizePolicy1);

    vboxLayout->addWidget(listMatches);


    gridLayout->addLayout(vboxLayout, 0, 1, 3, 1);

    spacerItem = new QSpacerItem(433, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

    gridLayout->addItem(spacerItem, 1, 0, 1, 1);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    pushSearch = new QPushButton(Dialog);
    pushSearch->setObjectName(QString::fromUtf8("pushSearch"));

    hboxLayout->addWidget(pushSearch);

    pushEditNet = new QPushButton(Dialog);
    pushEditNet->setObjectName(QString::fromUtf8("pushEditNet"));

    hboxLayout->addWidget(pushEditNet);


    vboxLayout1->addLayout(hboxLayout);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    pushLoad = new QPushButton(Dialog);
    pushLoad->setObjectName(QString::fromUtf8("pushLoad"));

    hboxLayout1->addWidget(pushLoad);

    pushExit = new QPushButton(Dialog);
    pushExit->setObjectName(QString::fromUtf8("pushExit"));

    hboxLayout1->addWidget(pushExit);


    vboxLayout1->addLayout(hboxLayout1);


    gridLayout->addLayout(vboxLayout1, 2, 0, 1, 1);


    retranslateUi(Dialog);
    QObject::connect(pushExit, SIGNAL(clicked()), Dialog, SLOT(close()));

    QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Face Detector", 0, QApplication::UnicodeUTF8));
    imageToSearch->setText(QString());
    preview->setText(QString());
    pushSearch->setText(QApplication::translate("Dialog", "Search For Faces", 0, QApplication::UnicodeUTF8));
    pushEditNet->setText(QApplication::translate("Dialog", "Edit Network", 0, QApplication::UnicodeUTF8));
    pushLoad->setText(QApplication::translate("Dialog", "Load Image", 0, QApplication::UnicodeUTF8));
    pushExit->setText(QApplication::translate("Dialog", "Exit", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

#endif // UI_GUI_H
