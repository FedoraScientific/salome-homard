/********************************************************************************
** Form generated from reading UI file 'CreateCase.ui'
**
** Created: Wed Jan 15 08:42:35 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATECASE_H
#define CREATECASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCase
{
public:
    QGridLayout *gridLayout_3;
    QWidget *WName;
    QGridLayout *gridLayout_2;
    QLabel *Name;
    QLineEdit *LEName;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *hboxLayout;
    QLabel *Directory;
    QPushButton *PushDir;
    QLineEdit *LEDirName;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QLabel *Mesh;
    QPushButton *PushFichier;
    QLineEdit *LEFileName;
    QSpacerItem *spacerItem1;
    QGroupBox *GBTypeConf;
    QHBoxLayout *hboxLayout2;
    QRadioButton *RBConforme;
    QRadioButton *RBNonConforme;
    QSpacerItem *spacerItem2;
    QGroupBox *GBTypeNoConf;
    QHBoxLayout *hboxLayout3;
    QRadioButton *RB1NpM;
    QRadioButton *RB1NpA;
    QRadioButton *RBQuelconque;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout4;
    QCheckBox *CBBoundaryD;
    QCheckBox *CBBoundaryA;
    QSpacerItem *spacerItem4;
    QGroupBox *GBBoundaryD;
    QGridLayout *gridLayout;
    QPushButton *PBBoundaryDiEdit;
    QPushButton *PBBoundaryDiNew;
    QComboBox *CBBoundaryDi;
    QSpacerItem *spacerItem5;
    QPushButton *PBBoundaryDiHelp;
    QGroupBox *GBBoundaryA;
    QFormLayout *formLayout;
    QTableWidget *TWBoundary;
    QGridLayout *gridLayout1;
    QPushButton *PBBoundaryAnEdit;
    QPushButton *PBBoundaryAnNew;
    QPushButton *PBBoundaryAnHelp;
    QSpacerItem *spacer;
    QCheckBox *CBAdvanced;
    QGroupBox *GBAdvancedOptions;
    QGridLayout *gridLayout2;
    QCheckBox *CBPyramid;
    QSpacerItem *spacer_3;
    QSpacerItem *spacer_4;
    QLabel *Comment;
    QSpacerItem *verticalSpacer;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout3;
    QPushButton *buttonHelp;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QSpacerItem *spacer_2;

    void setupUi(QDialog *CreateCase)
    {
        if (CreateCase->objectName().isEmpty())
            CreateCase->setObjectName(QString::fromUtf8("CreateCase"));
        CreateCase->resize(601, 1100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateCase->sizePolicy().hasHeightForWidth());
        CreateCase->setSizePolicy(sizePolicy);
        CreateCase->setMinimumSize(QSize(600, 320));
        CreateCase->setSizeIncrement(QSize(1, 1));
        CreateCase->setBaseSize(QSize(600, 320));
        CreateCase->setAutoFillBackground(true);
        gridLayout_3 = new QGridLayout(CreateCase);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        WName = new QWidget(CreateCase);
        WName->setObjectName(QString::fromUtf8("WName"));
        gridLayout_2 = new QGridLayout(WName);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Name = new QLabel(WName);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout_2->addWidget(Name, 0, 0, 1, 1);

        LEName = new QLineEdit(WName);
        LEName->setObjectName(QString::fromUtf8("LEName"));

        gridLayout_2->addWidget(LEName, 0, 1, 1, 1);


        gridLayout_3->addWidget(WName, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(199, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Directory = new QLabel(CreateCase);
        Directory->setObjectName(QString::fromUtf8("Directory"));

        hboxLayout->addWidget(Directory);

        PushDir = new QPushButton(CreateCase);
        PushDir->setObjectName(QString::fromUtf8("PushDir"));
        PushDir->setAutoDefault(false);

        hboxLayout->addWidget(PushDir);

        LEDirName = new QLineEdit(CreateCase);
        LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
        LEDirName->setMinimumSize(QSize(382, 21));

        hboxLayout->addWidget(LEDirName);


        gridLayout_3->addLayout(hboxLayout, 1, 0, 1, 6);

        spacerItem = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(spacerItem, 2, 2, 1, 2);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Mesh = new QLabel(CreateCase);
        Mesh->setObjectName(QString::fromUtf8("Mesh"));

        hboxLayout1->addWidget(Mesh);

        PushFichier = new QPushButton(CreateCase);
        PushFichier->setObjectName(QString::fromUtf8("PushFichier"));
        PushFichier->setAutoDefault(false);

        hboxLayout1->addWidget(PushFichier);

        LEFileName = new QLineEdit(CreateCase);
        LEFileName->setObjectName(QString::fromUtf8("LEFileName"));
        LEFileName->setMinimumSize(QSize(382, 21));

        hboxLayout1->addWidget(LEFileName);


        gridLayout_3->addLayout(hboxLayout1, 3, 0, 2, 6);

        spacerItem1 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(spacerItem1, 4, 3, 1, 3);

        GBTypeConf = new QGroupBox(CreateCase);
        GBTypeConf->setObjectName(QString::fromUtf8("GBTypeConf"));
        hboxLayout2 = new QHBoxLayout(GBTypeConf);
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        RBConforme = new QRadioButton(GBTypeConf);
        RBConforme->setObjectName(QString::fromUtf8("RBConforme"));
        RBConforme->setChecked(true);

        hboxLayout2->addWidget(RBConforme);

        RBNonConforme = new QRadioButton(GBTypeConf);
        RBNonConforme->setObjectName(QString::fromUtf8("RBNonConforme"));

        hboxLayout2->addWidget(RBNonConforme);


        gridLayout_3->addWidget(GBTypeConf, 5, 0, 1, 2);

        spacerItem2 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(spacerItem2, 6, 3, 1, 1);

        GBTypeNoConf = new QGroupBox(CreateCase);
        GBTypeNoConf->setObjectName(QString::fromUtf8("GBTypeNoConf"));
        hboxLayout3 = new QHBoxLayout(GBTypeNoConf);
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        RB1NpM = new QRadioButton(GBTypeNoConf);
        RB1NpM->setObjectName(QString::fromUtf8("RB1NpM"));

        hboxLayout3->addWidget(RB1NpM);

        RB1NpA = new QRadioButton(GBTypeNoConf);
        RB1NpA->setObjectName(QString::fromUtf8("RB1NpA"));

        hboxLayout3->addWidget(RB1NpA);

        RBQuelconque = new QRadioButton(GBTypeNoConf);
        RBQuelconque->setObjectName(QString::fromUtf8("RBQuelconque"));

        hboxLayout3->addWidget(RBQuelconque);


        gridLayout_3->addWidget(GBTypeNoConf, 7, 0, 1, 6);

        spacerItem3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(spacerItem3, 8, 3, 1, 3);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        CBBoundaryD = new QCheckBox(CreateCase);
        CBBoundaryD->setObjectName(QString::fromUtf8("CBBoundaryD"));

        hboxLayout4->addWidget(CBBoundaryD);

        CBBoundaryA = new QCheckBox(CreateCase);
        CBBoundaryA->setObjectName(QString::fromUtf8("CBBoundaryA"));

        hboxLayout4->addWidget(CBBoundaryA);


        gridLayout_3->addLayout(hboxLayout4, 9, 0, 1, 4);

        spacerItem4 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(spacerItem4, 10, 3, 1, 1);

        GBBoundaryD = new QGroupBox(CreateCase);
        GBBoundaryD->setObjectName(QString::fromUtf8("GBBoundaryD"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(GBBoundaryD->sizePolicy().hasHeightForWidth());
        GBBoundaryD->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(GBBoundaryD);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PBBoundaryDiEdit = new QPushButton(GBBoundaryD);
        PBBoundaryDiEdit->setObjectName(QString::fromUtf8("PBBoundaryDiEdit"));
        PBBoundaryDiEdit->setAutoDefault(false);

        gridLayout->addWidget(PBBoundaryDiEdit, 0, 3, 1, 1);

        PBBoundaryDiNew = new QPushButton(GBBoundaryD);
        PBBoundaryDiNew->setObjectName(QString::fromUtf8("PBBoundaryDiNew"));
        PBBoundaryDiNew->setAutoDefault(false);

        gridLayout->addWidget(PBBoundaryDiNew, 0, 2, 1, 1);

        CBBoundaryDi = new QComboBox(GBBoundaryD);
        CBBoundaryDi->setObjectName(QString::fromUtf8("CBBoundaryDi"));
        CBBoundaryDi->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(CBBoundaryDi, 0, 0, 1, 1);

        spacerItem5 = new QSpacerItem(40, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem5, 0, 1, 1, 1);

        PBBoundaryDiHelp = new QPushButton(GBBoundaryD);
        PBBoundaryDiHelp->setObjectName(QString::fromUtf8("PBBoundaryDiHelp"));
        PBBoundaryDiHelp->setAutoDefault(false);

        gridLayout->addWidget(PBBoundaryDiHelp, 0, 4, 1, 1);


        gridLayout_3->addWidget(GBBoundaryD, 11, 0, 1, 6);

        GBBoundaryA = new QGroupBox(CreateCase);
        GBBoundaryA->setObjectName(QString::fromUtf8("GBBoundaryA"));
        GBBoundaryA->setMinimumSize(QSize(548, 200));
        formLayout = new QFormLayout(GBBoundaryA);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        TWBoundary = new QTableWidget(GBBoundaryA);
        if (TWBoundary->columnCount() < 1)
            TWBoundary->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TWBoundary->setHorizontalHeaderItem(0, __qtablewidgetitem);
        TWBoundary->setObjectName(QString::fromUtf8("TWBoundary"));
        TWBoundary->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        TWBoundary->setShowGrid(true);
        TWBoundary->setRowCount(0);
        TWBoundary->setColumnCount(1);

        formLayout->setWidget(0, QFormLayout::LabelRole, TWBoundary);

        gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
        gridLayout1->setContentsMargins(0, 0, 0, 0);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        PBBoundaryAnEdit = new QPushButton(GBBoundaryA);
        PBBoundaryAnEdit->setObjectName(QString::fromUtf8("PBBoundaryAnEdit"));
        PBBoundaryAnEdit->setAutoDefault(false);

        gridLayout1->addWidget(PBBoundaryAnEdit, 1, 0, 1, 1);

        PBBoundaryAnNew = new QPushButton(GBBoundaryA);
        PBBoundaryAnNew->setObjectName(QString::fromUtf8("PBBoundaryAnNew"));
        PBBoundaryAnNew->setAutoDefault(false);

        gridLayout1->addWidget(PBBoundaryAnNew, 0, 0, 1, 1);

        PBBoundaryAnHelp = new QPushButton(GBBoundaryA);
        PBBoundaryAnHelp->setObjectName(QString::fromUtf8("PBBoundaryAnHelp"));
        PBBoundaryAnHelp->setAutoDefault(false);

        gridLayout1->addWidget(PBBoundaryAnHelp, 2, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout1);


        gridLayout_3->addWidget(GBBoundaryA, 12, 0, 1, 6);

        spacer = new QSpacerItem(239, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(spacer, 13, 0, 1, 2);

        CBAdvanced = new QCheckBox(CreateCase);
        CBAdvanced->setObjectName(QString::fromUtf8("CBAdvanced"));

        gridLayout_3->addWidget(CBAdvanced, 14, 0, 1, 1);

        GBAdvancedOptions = new QGroupBox(CreateCase);
        GBAdvancedOptions->setObjectName(QString::fromUtf8("GBAdvancedOptions"));
        gridLayout2 = new QGridLayout(GBAdvancedOptions);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        CBPyramid = new QCheckBox(GBAdvancedOptions);
        CBPyramid->setObjectName(QString::fromUtf8("CBPyramid"));

        gridLayout2->addWidget(CBPyramid, 0, 0, 1, 1);


        gridLayout_3->addWidget(GBAdvancedOptions, 15, 0, 1, 1);

        spacer_3 = new QSpacerItem(128, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(spacer_3, 15, 4, 1, 2);

        spacer_4 = new QSpacerItem(239, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(spacer_4, 16, 0, 1, 2);

        Comment = new QLabel(CreateCase);
        Comment->setObjectName(QString::fromUtf8("Comment"));

        gridLayout_3->addWidget(Comment, 17, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 18, 0, 1, 1);

        GroupButtons = new QGroupBox(CreateCase);
        GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
        gridLayout3 = new QGridLayout(GroupButtons);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        buttonHelp = new QPushButton(GroupButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
        buttonHelp->setAutoDefault(false);

        gridLayout3->addWidget(buttonHelp, 0, 4, 1, 1);

        buttonApply = new QPushButton(GroupButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
        buttonApply->setAutoDefault(false);

        gridLayout3->addWidget(buttonApply, 0, 1, 1, 1);

        buttonOk = new QPushButton(GroupButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(false);

        gridLayout3->addWidget(buttonOk, 0, 0, 1, 1);

        buttonCancel = new QPushButton(GroupButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setAutoDefault(false);

        gridLayout3->addWidget(buttonCancel, 0, 2, 1, 1);


        gridLayout_3->addWidget(GroupButtons, 19, 0, 1, 5);

        spacer_2 = new QSpacerItem(128, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(spacer_2, 19, 5, 1, 1);


        retranslateUi(CreateCase);

        CBBoundaryDi->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CreateCase);
    } // setupUi

    void retranslateUi(QDialog *CreateCase)
    {
        CreateCase->setWindowTitle(QApplication::translate("CreateCase", "Create a case", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateCase", "Name", 0, QApplication::UnicodeUTF8));
        Directory->setText(QApplication::translate("CreateCase", "Directory", 0, QApplication::UnicodeUTF8));
        PushDir->setText(QString());
        Mesh->setText(QApplication::translate("CreateCase", "Mesh", 0, QApplication::UnicodeUTF8));
        PushFichier->setText(QString());
        GBTypeConf->setTitle(QApplication::translate("CreateCase", "Conformity type", 0, QApplication::UnicodeUTF8));
        RBConforme->setText(QApplication::translate("CreateCase", "Conformal", 0, QApplication::UnicodeUTF8));
        RBNonConforme->setText(QApplication::translate("CreateCase", "Non conformal", 0, QApplication::UnicodeUTF8));
        GBTypeNoConf->setTitle(QApplication::translate("CreateCase", "Non conformal option", 0, QApplication::UnicodeUTF8));
        RB1NpM->setText(QApplication::translate("CreateCase", "1 hanging node per mesh", 0, QApplication::UnicodeUTF8));
        RB1NpA->setText(QApplication::translate("CreateCase", "1 node per edge", 0, QApplication::UnicodeUTF8));
        RBQuelconque->setText(QApplication::translate("CreateCase", "Free", 0, QApplication::UnicodeUTF8));
        CBBoundaryD->setText(QApplication::translate("CreateCase", "Discrete boundary", 0, QApplication::UnicodeUTF8));
        CBBoundaryA->setText(QApplication::translate("CreateCase", "Analytical boundary", 0, QApplication::UnicodeUTF8));
        GBBoundaryD->setTitle(QApplication::translate("CreateCase", "Discrete boundary", 0, QApplication::UnicodeUTF8));
        PBBoundaryDiEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
        PBBoundaryDiNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
        PBBoundaryDiHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
        GBBoundaryA->setTitle(QApplication::translate("CreateCase", "Analytical boundary", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = TWBoundary->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CreateCase", "a_virer", 0, QApplication::UnicodeUTF8));
        PBBoundaryAnEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
        PBBoundaryAnNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
        PBBoundaryAnHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
        CBAdvanced->setText(QApplication::translate("CreateCase", "Advanced options", 0, QApplication::UnicodeUTF8));
        GBAdvancedOptions->setTitle(QApplication::translate("CreateCase", "Advanced options", 0, QApplication::UnicodeUTF8));
        CBPyramid->setText(QApplication::translate("CreateCase", "Authorized pyramids", 0, QApplication::UnicodeUTF8));
        Comment->setText(QApplication::translate("CreateCase", " No comment.", 0, QApplication::UnicodeUTF8));
        GroupButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("CreateCase", "Help", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateCase", "Apply", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("CreateCase", "OK", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateCase", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateCase: public Ui_CreateCase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATECASE_H
