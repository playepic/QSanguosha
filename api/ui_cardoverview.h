/********************************************************************************
** Form generated from reading UI file 'cardoverview.ui'
**
** Created: Thu Jul 26 13:32:27 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDOVERVIEW_H
#define UI_CARDOVERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CardOverview
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *cardLabel;
    QTextEdit *cardDescriptionBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *malePlayButton;
    QPushButton *femalePlayButton;
    QPushButton *getCardButton;

    void setupUi(QDialog *CardOverview)
    {
        if (CardOverview->objectName().isEmpty())
            CardOverview->setObjectName(QString::fromUtf8("CardOverview"));
        CardOverview->resize(771, 564);
        horizontalLayout_2 = new QHBoxLayout(CardOverview);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidget = new QTableWidget(CardOverview);
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
        tableWidget->setMaximumSize(QSize(491, 16777215));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);

        horizontalLayout_2->addWidget(tableWidget);

        frame = new QFrame(CardOverview);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(221, 521));
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cardLabel = new QLabel(frame);
        cardLabel->setObjectName(QString::fromUtf8("cardLabel"));
        cardLabel->setMinimumSize(QSize(211, 301));
        cardLabel->setMaximumSize(QSize(217, 16777215));

        verticalLayout_2->addWidget(cardLabel);

        cardDescriptionBox = new QTextEdit(frame);
        cardDescriptionBox->setObjectName(QString::fromUtf8("cardDescriptionBox"));
        cardDescriptionBox->setMaximumSize(QSize(217, 16777215));
        cardDescriptionBox->setReadOnly(true);

        verticalLayout_2->addWidget(cardDescriptionBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        malePlayButton = new QPushButton(frame);
        malePlayButton->setObjectName(QString::fromUtf8("malePlayButton"));
        malePlayButton->setMinimumSize(QSize(101, 23));
        malePlayButton->setMaximumSize(QSize(105, 16777215));

        horizontalLayout->addWidget(malePlayButton);

        femalePlayButton = new QPushButton(frame);
        femalePlayButton->setObjectName(QString::fromUtf8("femalePlayButton"));
        femalePlayButton->setMinimumSize(QSize(100, 23));
        femalePlayButton->setMaximumSize(QSize(104, 16777215));

        horizontalLayout->addWidget(femalePlayButton);


        verticalLayout->addLayout(horizontalLayout);

        getCardButton = new QPushButton(frame);
        getCardButton->setObjectName(QString::fromUtf8("getCardButton"));
        getCardButton->setMinimumSize(QSize(209, 23));
        getCardButton->setMaximumSize(QSize(217, 16777215));

        verticalLayout->addWidget(getCardButton);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(CardOverview);

        QMetaObject::connectSlotsByName(CardOverview);
    } // setupUi

    void retranslateUi(QDialog *CardOverview)
    {
        CardOverview->setWindowTitle(QApplication::translate("CardOverview", "Card Overvew", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CardOverview", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CardOverview", "Suit", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CardOverview", "Point", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CardOverview", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CardOverview", "Subtype", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CardOverview", "Package", 0, QApplication::UnicodeUTF8));
        cardLabel->setText(QString());
        malePlayButton->setText(QApplication::translate("CardOverview", "Play (male)", 0, QApplication::UnicodeUTF8));
        femalePlayButton->setText(QApplication::translate("CardOverview", "Play (female)", 0, QApplication::UnicodeUTF8));
        getCardButton->setText(QApplication::translate("CardOverview", "Get this card", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CardOverview: public Ui_CardOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDOVERVIEW_H
