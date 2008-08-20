/********************************************************************************
** Form generated from reading ui file 'progress.ui'
**
** Created: Thu Jun 19 15:58:20 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROGRESS_H
#define UI_PROGRESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_Progress
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;

    void setupUi(QDialog *Progress)
    {
    if (Progress->objectName().isEmpty())
        Progress->setObjectName(QString::fromUtf8("Progress"));
    Progress->resize(400, 44);
    gridLayout = new QGridLayout(Progress);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    progressBar = new QProgressBar(Progress);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    progressBar->setValue(50);

    gridLayout->addWidget(progressBar, 0, 0, 1, 1);


    retranslateUi(Progress);

    QMetaObject::connectSlotsByName(Progress);
    } // setupUi

    void retranslateUi(QDialog *Progress)
    {
    Progress->setWindowTitle(QApplication::translate("Progress", "Trained", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Progress);
    } // retranslateUi

};

namespace Ui {
    class Progress: public Ui_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_H
