/********************************************************************************
** Form generated from reading ui file 'networkeditor.ui'
**
** Created: Fri Jun 13 21:41:08 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NETWORKEDITOR_H
#define UI_NETWORKEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

class Ui_NetworkEditor
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *label;
    QSpinBox *spinInputNeurons;
    QVBoxLayout *vboxLayout2;
    QLabel *label_4;
    QSpinBox *spinHiddenLayers;
    QVBoxLayout *vboxLayout3;
    QLabel *label_3;
    QSpinBox *spinOutputNeurons;
    QVBoxLayout *vboxLayout4;
    QLabel *label_2;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem1;
    QLabel *imagePreview;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout1;
    QLabel *label_6;
    QLabel *labelFaces;
    QSpacerItem *spacerItem3;
    QListWidget *listFaces;
    QHBoxLayout *hboxLayout2;
    QPushButton *pushAddFaces;
    QPushButton *pushRemoveFaces;
    QHBoxLayout *hboxLayout3;
    QLabel *label_7;
    QLabel *labelNonFaces;
    QSpacerItem *spacerItem4;
    QListWidget *listNonFaces;
    QHBoxLayout *hboxLayout4;
    QPushButton *pushAddNonFaces;
    QPushButton *pushRemoveNonFaces;
    QHBoxLayout *hboxLayout5;
    QVBoxLayout *vboxLayout6;
    QHBoxLayout *hboxLayout6;
    QLabel *label_5;
    QSpacerItem *spacerItem5;
    QDoubleSpinBox *spinLearningRate;
    QHBoxLayout *hboxLayout7;
    QLabel *label_8;
    QSpacerItem *spacerItem6;
    QDoubleSpinBox *spinMomentum;
    QHBoxLayout *hboxLayout8;
    QLabel *label_9;
    QSpacerItem *spacerItem7;
    QDoubleSpinBox *spinError;
    QVBoxLayout *vboxLayout7;
    QHBoxLayout *hboxLayout9;
    QLabel *label_10;
    QSpacerItem *spacerItem8;
    QSpinBox *spinWidth;
    QHBoxLayout *hboxLayout10;
    QLabel *label_11;
    QSpacerItem *spacerItem9;
    QSpinBox *spinHeight;
    QSpacerItem *spacerItem10;
    QSpacerItem *spacerItem11;
    QHBoxLayout *hboxLayout11;
    QPushButton *pushCommit;
    QPushButton *pushDone;
    QVBoxLayout *vboxLayout8;
    QHBoxLayout *hboxLayout12;
    QPushButton *pushTrain;
    QPushButton *pushRandomize;
    QHBoxLayout *hboxLayout13;
    QPushButton *pushToXML;
    QPushButton *pushFromXML;

    void setupUi(QDialog *NetworkEditor)
    {
    if (NetworkEditor->objectName().isEmpty())
        NetworkEditor->setObjectName(QString::fromUtf8("NetworkEditor"));
    NetworkEditor->resize(700, 656);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(NetworkEditor->sizePolicy().hasHeightForWidth());
    NetworkEditor->setSizePolicy(sizePolicy);
    gridLayout = new QGridLayout(NetworkEditor);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox_2 = new QGroupBox(NetworkEditor);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout1 = new QGridLayout(groupBox_2);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    label = new QLabel(groupBox_2);
    label->setObjectName(QString::fromUtf8("label"));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicy1);

    vboxLayout1->addWidget(label);

    spinInputNeurons = new QSpinBox(groupBox_2);
    spinInputNeurons->setObjectName(QString::fromUtf8("spinInputNeurons"));
    QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(spinInputNeurons->sizePolicy().hasHeightForWidth());
    spinInputNeurons->setSizePolicy(sizePolicy2);
    spinInputNeurons->setMaximum(9999);

    vboxLayout1->addWidget(spinInputNeurons);


    vboxLayout->addLayout(vboxLayout1);

    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    label_4 = new QLabel(groupBox_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    vboxLayout2->addWidget(label_4);

    spinHiddenLayers = new QSpinBox(groupBox_2);
    spinHiddenLayers->setObjectName(QString::fromUtf8("spinHiddenLayers"));
    sizePolicy2.setHeightForWidth(spinHiddenLayers->sizePolicy().hasHeightForWidth());
    spinHiddenLayers->setSizePolicy(sizePolicy2);
    spinHiddenLayers->setMaximum(9999);

    vboxLayout2->addWidget(spinHiddenLayers);


    vboxLayout->addLayout(vboxLayout2);

    vboxLayout3 = new QVBoxLayout();
    vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
    label_3 = new QLabel(groupBox_2);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    vboxLayout3->addWidget(label_3);

    spinOutputNeurons = new QSpinBox(groupBox_2);
    spinOutputNeurons->setObjectName(QString::fromUtf8("spinOutputNeurons"));
    sizePolicy2.setHeightForWidth(spinOutputNeurons->sizePolicy().hasHeightForWidth());
    spinOutputNeurons->setSizePolicy(sizePolicy2);
    spinOutputNeurons->setMaximum(9999);

    vboxLayout3->addWidget(spinOutputNeurons);


    vboxLayout->addLayout(vboxLayout3);

    vboxLayout4 = new QVBoxLayout();
    vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
    label_2 = new QLabel(groupBox_2);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
    label_2->setSizePolicy(sizePolicy);

    vboxLayout4->addWidget(label_2);


    vboxLayout->addLayout(vboxLayout4);


    gridLayout1->addLayout(vboxLayout, 0, 0, 1, 1);

    spacerItem = new QSpacerItem(107, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout1->addItem(spacerItem, 1, 0, 1, 1);


    gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

    vboxLayout5 = new QVBoxLayout();
    vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
    groupBox = new QGroupBox(NetworkEditor);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout2 = new QGridLayout(groupBox);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem1);

    imagePreview = new QLabel(groupBox);
    imagePreview->setObjectName(QString::fromUtf8("imagePreview"));
    QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(imagePreview->sizePolicy().hasHeightForWidth());
    imagePreview->setSizePolicy(sizePolicy3);
    imagePreview->setMinimumSize(QSize(128, 128));
    imagePreview->setMaximumSize(QSize(128, 128));
    imagePreview->setScaledContents(true);

    hboxLayout->addWidget(imagePreview);

    spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem2);


    gridLayout2->addLayout(hboxLayout, 0, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    hboxLayout1->addWidget(label_6);

    labelFaces = new QLabel(groupBox);
    labelFaces->setObjectName(QString::fromUtf8("labelFaces"));

    hboxLayout1->addWidget(labelFaces);

    spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem3);


    gridLayout2->addLayout(hboxLayout1, 1, 0, 1, 1);

    listFaces = new QListWidget(groupBox);
    listFaces->setObjectName(QString::fromUtf8("listFaces"));
    QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(listFaces->sizePolicy().hasHeightForWidth());
    listFaces->setSizePolicy(sizePolicy4);

    gridLayout2->addWidget(listFaces, 2, 0, 1, 1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    pushAddFaces = new QPushButton(groupBox);
    pushAddFaces->setObjectName(QString::fromUtf8("pushAddFaces"));

    hboxLayout2->addWidget(pushAddFaces);

    pushRemoveFaces = new QPushButton(groupBox);
    pushRemoveFaces->setObjectName(QString::fromUtf8("pushRemoveFaces"));

    hboxLayout2->addWidget(pushRemoveFaces);


    gridLayout2->addLayout(hboxLayout2, 3, 0, 1, 1);

    hboxLayout3 = new QHBoxLayout();
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    label_7 = new QLabel(groupBox);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    hboxLayout3->addWidget(label_7);

    labelNonFaces = new QLabel(groupBox);
    labelNonFaces->setObjectName(QString::fromUtf8("labelNonFaces"));

    hboxLayout3->addWidget(labelNonFaces);

    spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    hboxLayout3->addItem(spacerItem4);


    gridLayout2->addLayout(hboxLayout3, 4, 0, 1, 1);

    listNonFaces = new QListWidget(groupBox);
    listNonFaces->setObjectName(QString::fromUtf8("listNonFaces"));
    sizePolicy4.setHeightForWidth(listNonFaces->sizePolicy().hasHeightForWidth());
    listNonFaces->setSizePolicy(sizePolicy4);

    gridLayout2->addWidget(listNonFaces, 5, 0, 1, 1);

    hboxLayout4 = new QHBoxLayout();
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    pushAddNonFaces = new QPushButton(groupBox);
    pushAddNonFaces->setObjectName(QString::fromUtf8("pushAddNonFaces"));

    hboxLayout4->addWidget(pushAddNonFaces);

    pushRemoveNonFaces = new QPushButton(groupBox);
    pushRemoveNonFaces->setObjectName(QString::fromUtf8("pushRemoveNonFaces"));

    hboxLayout4->addWidget(pushRemoveNonFaces);


    gridLayout2->addLayout(hboxLayout4, 6, 0, 1, 1);

    hboxLayout5 = new QHBoxLayout();
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    vboxLayout6 = new QVBoxLayout();
    vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
    hboxLayout6 = new QHBoxLayout();
    hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    hboxLayout6->addWidget(label_5);

    spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    hboxLayout6->addItem(spacerItem5);

    spinLearningRate = new QDoubleSpinBox(groupBox);
    spinLearningRate->setObjectName(QString::fromUtf8("spinLearningRate"));
    spinLearningRate->setMaximum(0.99);
    spinLearningRate->setSingleStep(0.05);
    spinLearningRate->setValue(0.25);

    hboxLayout6->addWidget(spinLearningRate);


    vboxLayout6->addLayout(hboxLayout6);

    hboxLayout7 = new QHBoxLayout();
    hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
    label_8 = new QLabel(groupBox);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    hboxLayout7->addWidget(label_8);

    spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    hboxLayout7->addItem(spacerItem6);

    spinMomentum = new QDoubleSpinBox(groupBox);
    spinMomentum->setObjectName(QString::fromUtf8("spinMomentum"));
    spinMomentum->setMaximum(0.99);
    spinMomentum->setSingleStep(0.05);
    spinMomentum->setValue(0.75);

    hboxLayout7->addWidget(spinMomentum);


    vboxLayout6->addLayout(hboxLayout7);

    hboxLayout8 = new QHBoxLayout();
    hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
    label_9 = new QLabel(groupBox);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    hboxLayout8->addWidget(label_9);

    spacerItem7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    hboxLayout8->addItem(spacerItem7);

    spinError = new QDoubleSpinBox(groupBox);
    spinError->setObjectName(QString::fromUtf8("spinError"));
    spinError->setSingleStep(0.01);
    spinError->setValue(0.06);

    hboxLayout8->addWidget(spinError);


    vboxLayout6->addLayout(hboxLayout8);


    hboxLayout5->addLayout(vboxLayout6);

    vboxLayout7 = new QVBoxLayout();
    vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
    hboxLayout9 = new QHBoxLayout();
    hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
    label_10 = new QLabel(groupBox);
    label_10->setObjectName(QString::fromUtf8("label_10"));

    hboxLayout9->addWidget(label_10);

    spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    hboxLayout9->addItem(spacerItem8);

    spinWidth = new QSpinBox(groupBox);
    spinWidth->setObjectName(QString::fromUtf8("spinWidth"));
    spinWidth->setValue(20);

    hboxLayout9->addWidget(spinWidth);


    vboxLayout7->addLayout(hboxLayout9);

    hboxLayout10 = new QHBoxLayout();
    hboxLayout10->setObjectName(QString::fromUtf8("hboxLayout10"));
    label_11 = new QLabel(groupBox);
    label_11->setObjectName(QString::fromUtf8("label_11"));

    hboxLayout10->addWidget(label_11);

    spacerItem9 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    hboxLayout10->addItem(spacerItem9);

    spinHeight = new QSpinBox(groupBox);
    spinHeight->setObjectName(QString::fromUtf8("spinHeight"));
    spinHeight->setValue(22);

    hboxLayout10->addWidget(spinHeight);


    vboxLayout7->addLayout(hboxLayout10);

    spacerItem10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout7->addItem(spacerItem10);


    hboxLayout5->addLayout(vboxLayout7);


    gridLayout2->addLayout(hboxLayout5, 7, 0, 1, 1);


    vboxLayout5->addWidget(groupBox);

    spacerItem11 = new QSpacerItem(335, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

    vboxLayout5->addItem(spacerItem11);

    hboxLayout11 = new QHBoxLayout();
    hboxLayout11->setObjectName(QString::fromUtf8("hboxLayout11"));
    pushCommit = new QPushButton(NetworkEditor);
    pushCommit->setObjectName(QString::fromUtf8("pushCommit"));

    hboxLayout11->addWidget(pushCommit);

    pushDone = new QPushButton(NetworkEditor);
    pushDone->setObjectName(QString::fromUtf8("pushDone"));

    hboxLayout11->addWidget(pushDone);


    vboxLayout5->addLayout(hboxLayout11);


    gridLayout->addLayout(vboxLayout5, 0, 1, 2, 1);

    vboxLayout8 = new QVBoxLayout();
    vboxLayout8->setObjectName(QString::fromUtf8("vboxLayout8"));
    hboxLayout12 = new QHBoxLayout();
    hboxLayout12->setObjectName(QString::fromUtf8("hboxLayout12"));
    pushTrain = new QPushButton(NetworkEditor);
    pushTrain->setObjectName(QString::fromUtf8("pushTrain"));

    hboxLayout12->addWidget(pushTrain);

    pushRandomize = new QPushButton(NetworkEditor);
    pushRandomize->setObjectName(QString::fromUtf8("pushRandomize"));

    hboxLayout12->addWidget(pushRandomize);


    vboxLayout8->addLayout(hboxLayout12);

    hboxLayout13 = new QHBoxLayout();
    hboxLayout13->setObjectName(QString::fromUtf8("hboxLayout13"));
    pushToXML = new QPushButton(NetworkEditor);
    pushToXML->setObjectName(QString::fromUtf8("pushToXML"));

    hboxLayout13->addWidget(pushToXML);

    pushFromXML = new QPushButton(NetworkEditor);
    pushFromXML->setObjectName(QString::fromUtf8("pushFromXML"));

    hboxLayout13->addWidget(pushFromXML);


    vboxLayout8->addLayout(hboxLayout13);


    gridLayout->addLayout(vboxLayout8, 1, 0, 1, 1);


    retranslateUi(NetworkEditor);

    QMetaObject::connectSlotsByName(NetworkEditor);
    } // setupUi

    void retranslateUi(QDialog *NetworkEditor)
    {
    NetworkEditor->setWindowTitle(QApplication::translate("NetworkEditor", "Dialog", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("NetworkEditor", "Network Architecture", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("NetworkEditor", "Input Neurons", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("NetworkEditor", "Hidden Layers", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("NetworkEditor", "Output Neurons", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("NetworkEditor", "Hidden Neurons", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("NetworkEditor", "Training Parameters", 0, QApplication::UnicodeUTF8));
    imagePreview->setText(QString());
    label_6->setText(QApplication::translate("NetworkEditor", "Faces:", 0, QApplication::UnicodeUTF8));
    labelFaces->setText(QApplication::translate("NetworkEditor", "(0)", 0, QApplication::UnicodeUTF8));
    pushAddFaces->setText(QApplication::translate("NetworkEditor", "Add", 0, QApplication::UnicodeUTF8));
    pushRemoveFaces->setText(QApplication::translate("NetworkEditor", "Remove", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("NetworkEditor", "NonFaces:", 0, QApplication::UnicodeUTF8));
    labelNonFaces->setText(QApplication::translate("NetworkEditor", "(0)", 0, QApplication::UnicodeUTF8));
    pushAddNonFaces->setText(QApplication::translate("NetworkEditor", "Add", 0, QApplication::UnicodeUTF8));
    pushRemoveNonFaces->setText(QApplication::translate("NetworkEditor", "Remove", 0, QApplication::UnicodeUTF8));
    pushRemoveNonFaces->setShortcut(QApplication::translate("NetworkEditor", "Alt+R", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("NetworkEditor", "Learning Rate:", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("NetworkEditor", "Momentum:", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("NetworkEditor", "Targeted Error:", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("NetworkEditor", "Width:", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("NetworkEditor", "Height:", 0, QApplication::UnicodeUTF8));
    pushCommit->setText(QApplication::translate("NetworkEditor", "Commit", 0, QApplication::UnicodeUTF8));
    pushDone->setText(QApplication::translate("NetworkEditor", "Done", 0, QApplication::UnicodeUTF8));
    pushTrain->setText(QApplication::translate("NetworkEditor", "Train Network", 0, QApplication::UnicodeUTF8));
    pushRandomize->setText(QApplication::translate("NetworkEditor", "Randomize", 0, QApplication::UnicodeUTF8));
    pushToXML->setText(QApplication::translate("NetworkEditor", "Export to XML", 0, QApplication::UnicodeUTF8));
    pushFromXML->setText(QApplication::translate("NetworkEditor", "Import from XML", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(NetworkEditor);
    } // retranslateUi

};

namespace Ui {
    class NetworkEditor: public Ui_NetworkEditor {};
} // namespace Ui

#endif // UI_NETWORKEDITOR_H
