/********************************************************************************
** Form generated from reading UI file 'generaloverview.ui'
**
** Created: Thu Jul 26 13:32:27 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALOVERVIEW_H
#define UI_GENERALOVERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralOverview
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *generalPhoto;
    QLabel *skillLabel;
    QTextEdit *skillTextEdit;
    QFrame *frame2;
    QVBoxLayout *verticalLayout;
    QFrame *frame1;
    QGridLayout *gridLayout;
    QLineEdit *cvLineEdit;
    QLabel *cvLabel;
    QLineEdit *designerLineEdit;
    QLabel *designerLabel;
    QLabel *illustratorLabel;
    QLineEdit *illustratorLineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *GeneralOverview)
    {
        if (GeneralOverview->objectName().isEmpty())
            GeneralOverview->setObjectName(QString::fromUtf8("GeneralOverview"));
        GeneralOverview->setWindowModality(Qt::NonModal);
        GeneralOverview->resize(945, 611);
        GeneralOverview->setMinimumSize(QSize(945, 550));
        GeneralOverview->setBaseSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(GeneralOverview);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidget = new QTableWidget(GeneralOverview);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);

        horizontalLayout_2->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(GeneralOverview);
        frame->setObjectName(QString::fromUtf8("frame"));
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        generalPhoto = new QLabel(frame);
        generalPhoto->setObjectName(QString::fromUtf8("generalPhoto"));
        generalPhoto->setPixmap(QPixmap(QString::fromUtf8("../image/generals/card/caocao.jpg")));

        verticalLayout_2->addWidget(generalPhoto);

        skillLabel = new QLabel(frame);
        skillLabel->setObjectName(QString::fromUtf8("skillLabel"));

        verticalLayout_2->addWidget(skillLabel);

        skillTextEdit = new QTextEdit(frame);
        skillTextEdit->setObjectName(QString::fromUtf8("skillTextEdit"));
        skillTextEdit->setMaximumSize(QSize(211, 16777215));
        skillTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(skillTextEdit);


        horizontalLayout->addWidget(frame);

        frame2 = new QFrame(GeneralOverview);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        verticalLayout = new QVBoxLayout(frame2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame1 = new QFrame(frame2);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setMinimumSize(QSize(241, 0));
        frame1->setMaximumSize(QSize(271, 91));
        gridLayout = new QGridLayout(frame1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cvLineEdit = new QLineEdit(frame1);
        cvLineEdit->setObjectName(QString::fromUtf8("cvLineEdit"));
        cvLineEdit->setFrame(true);
        cvLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cvLineEdit->setReadOnly(true);

        gridLayout->addWidget(cvLineEdit, 1, 1, 1, 1);

        cvLabel = new QLabel(frame1);
        cvLabel->setObjectName(QString::fromUtf8("cvLabel"));

        gridLayout->addWidget(cvLabel, 1, 0, 1, 1);

        designerLineEdit = new QLineEdit(frame1);
        designerLineEdit->setObjectName(QString::fromUtf8("designerLineEdit"));
        designerLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        designerLineEdit->setReadOnly(true);

        gridLayout->addWidget(designerLineEdit, 0, 1, 1, 1);

        designerLabel = new QLabel(frame1);
        designerLabel->setObjectName(QString::fromUtf8("designerLabel"));

        gridLayout->addWidget(designerLabel, 0, 0, 1, 1);

        illustratorLabel = new QLabel(frame1);
        illustratorLabel->setObjectName(QString::fromUtf8("illustratorLabel"));

        gridLayout->addWidget(illustratorLabel, 2, 0, 1, 1);

        illustratorLineEdit = new QLineEdit(frame1);
        illustratorLineEdit->setObjectName(QString::fromUtf8("illustratorLineEdit"));
        illustratorLineEdit->setFrame(true);
        illustratorLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        illustratorLineEdit->setReadOnly(true);

        gridLayout->addWidget(illustratorLineEdit, 2, 1, 1, 1);


        verticalLayout->addWidget(frame1);

        scrollArea = new QScrollArea(frame2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(271, 16777215));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 241, 506));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        horizontalLayout->addWidget(frame2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(GeneralOverview);

        QMetaObject::connectSlotsByName(GeneralOverview);
    } // setupUi

    void retranslateUi(QDialog *GeneralOverview)
    {
        GeneralOverview->setWindowTitle(QApplication::translate("GeneralOverview", "General Overview", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GeneralOverview", "Nick", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GeneralOverview", "General", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GeneralOverview", "Kingdom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GeneralOverview", "Gender", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("GeneralOverview", "MaxHP", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("GeneralOverview", "Package", 0, QApplication::UnicodeUTF8));
        generalPhoto->setText(QString());
        skillLabel->setText(QApplication::translate("GeneralOverview", "Skill", 0, QApplication::UnicodeUTF8));
        cvLabel->setText(QApplication::translate("GeneralOverview", "CV", 0, QApplication::UnicodeUTF8));
        designerLabel->setText(QApplication::translate("GeneralOverview", "Designer", 0, QApplication::UnicodeUTF8));
        illustratorLabel->setText(QApplication::translate("GeneralOverview", "Illustrator", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GeneralOverview: public Ui_GeneralOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALOVERVIEW_H
