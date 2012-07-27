/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created: Thu Jul 26 13:32:27 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QGroupBox *groupBox;
    QLabel *avatarLabel;
    QLabel *avatarPixmap;
    QPushButton *changeAvatarButton;
    QPushButton *detectLANButton;
    QPushButton *clearHistoryButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *hostLabel;
    QComboBox *hostComboBox;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QListWidget *avatarList;
    QPushButton *cancelButton;
    QPushButton *connectButton;
    QCheckBox *reconnectionCheckBox;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName(QString::fromUtf8("ConnectionDialog"));
        ConnectionDialog->setWindowModality(Qt::WindowModal);
        ConnectionDialog->resize(826, 325);
        groupBox = new QGroupBox(ConnectionDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 271, 271));
        avatarLabel = new QLabel(groupBox);
        avatarLabel->setObjectName(QString::fromUtf8("avatarLabel"));
        avatarLabel->setGeometry(QRect(10, 100, 42, 16));
        avatarPixmap = new QLabel(groupBox);
        avatarPixmap->setObjectName(QString::fromUtf8("avatarPixmap"));
        avatarPixmap->setGeometry(QRect(20, 140, 100, 100));
        avatarPixmap->setMinimumSize(QSize(100, 100));
        avatarPixmap->setScaledContents(true);
        changeAvatarButton = new QPushButton(groupBox);
        changeAvatarButton->setObjectName(QString::fromUtf8("changeAvatarButton"));
        changeAvatarButton->setGeometry(QRect(150, 230, 111, 23));
        detectLANButton = new QPushButton(groupBox);
        detectLANButton->setObjectName(QString::fromUtf8("detectLANButton"));
        detectLANButton->setGeometry(QRect(140, 100, 121, 23));
        clearHistoryButton = new QPushButton(groupBox);
        clearHistoryButton->setObjectName(QString::fromUtf8("clearHistoryButton"));
        clearHistoryButton->setGeometry(QRect(140, 130, 121, 23));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 17, 251, 74));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        hostLabel = new QLabel(layoutWidget);
        hostLabel->setObjectName(QString::fromUtf8("hostLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, hostLabel);

        hostComboBox = new QComboBox(layoutWidget);
        hostComboBox->setObjectName(QString::fromUtf8("hostComboBox"));
        hostComboBox->setEditable(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, hostComboBox);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, passwordLineEdit);

        avatarList = new QListWidget(ConnectionDialog);
        avatarList->setObjectName(QString::fromUtf8("avatarList"));
        avatarList->setGeometry(QRect(290, 10, 531, 301));
        avatarList->setIconSize(QSize(80, 80));
        avatarList->setMovement(QListView::Static);
        avatarList->setViewMode(QListView::IconMode);
        cancelButton = new QPushButton(ConnectionDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(210, 290, 71, 23));
        connectButton = new QPushButton(ConnectionDialog);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(120, 290, 75, 23));
        reconnectionCheckBox = new QCheckBox(ConnectionDialog);
        reconnectionCheckBox->setObjectName(QString::fromUtf8("reconnectionCheckBox"));
        reconnectionCheckBox->setGeometry(QRect(20, 290, 95, 16));
#ifndef QT_NO_SHORTCUT
        nameLabel->setBuddy(nameLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(ConnectionDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), ConnectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QApplication::translate("ConnectionDialog", "Connection setup", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ConnectionDialog", "Connection setup", 0, QApplication::UnicodeUTF8));
        avatarLabel->setText(QApplication::translate("ConnectionDialog", "Avatar:", 0, QApplication::UnicodeUTF8));
        avatarPixmap->setText(QString());
        changeAvatarButton->setText(QApplication::translate("ConnectionDialog", "Change avatar", 0, QApplication::UnicodeUTF8));
        detectLANButton->setText(QApplication::translate("ConnectionDialog", "Detect LAN ...", 0, QApplication::UnicodeUTF8));
        clearHistoryButton->setText(QApplication::translate("ConnectionDialog", "Clear history", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ConnectionDialog", "Name:", 0, QApplication::UnicodeUTF8));
        hostLabel->setText(QApplication::translate("ConnectionDialog", "Host:", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("ConnectionDialog", "Password:", 0, QApplication::UnicodeUTF8));
        passwordLineEdit->setPlaceholderText(QApplication::translate("ConnectionDialog", "Only used in contest", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ConnectionDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("ConnectionDialog", "Connect", 0, QApplication::UnicodeUTF8));
        reconnectionCheckBox->setText(QApplication::translate("ConnectionDialog", "Reconnection", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
