/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created: Thu Jul 26 13:32:27 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *envTab;
    QGroupBox *audioGroupBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QLabel *setupBgMusicLabel;
    QLineEdit *bgMusicPathLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *browseBgMusicButton;
    QPushButton *resetBgMusicButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *enableEffectCheckBox;
    QCheckBox *enableLastWordCheckBox;
    QCheckBox *enableBgMusicCheckBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *bgmVolumeLabel;
    QSlider *bgmVolumeSlider;
    QWidget *layoutWidget3_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *effectVolumeLabel;
    QSlider *effectVolumeSlider;
    QGroupBox *bgGroupBox;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *backgrounSetupLabel;
    QLineEdit *bgPathLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *browseBgButton;
    QPushButton *resetBgButton;
    QCheckBox *fitInViewCheckBox;
    QCheckBox *circularViewCheckBox;
    QCheckBox *noIndicatorCheckBox;
    QGroupBox *fontSetupGroupBox;
    QPushButton *changeAppFontButton;
    QLabel *appFontLabel;
    QLineEdit *appFontLineEdit;
    QLineEdit *textEditFontLineEdit;
    QPushButton *setTextEditFontButton;
    QLabel *textEditFontLabel;
    QPushButton *setTextEditColorButton;
    QWidget *gameTab;
    QWidget *layoutWidget5;
    QFormLayout *formLayout;
    QLabel *nullificationLabel;
    QSpinBox *nullificationSpinBox;
    QCheckBox *neverNullifyMyTrickCheckBox;
    QCheckBox *minimizecCheckBox;
    QWidget *tab;
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QLabel *smtpServerLabel;
    QLineEdit *smtpServerLineEdit;
    QLabel *senderLabel;
    QLineEdit *senderLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *receiverLabel;
    QLineEdit *receiverLineEdit;
    QCheckBox *onlySaveLordCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QString::fromUtf8("ConfigDialog"));
        ConfigDialog->setWindowModality(Qt::WindowModal);
        ConfigDialog->resize(494, 534);
        tabWidget = new QTabWidget(ConfigDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 471, 461));
        envTab = new QWidget();
        envTab->setObjectName(QString::fromUtf8("envTab"));
        audioGroupBox = new QGroupBox(envTab);
        audioGroupBox->setObjectName(QString::fromUtf8("audioGroupBox"));
        audioGroupBox->setGeometry(QRect(10, 140, 441, 191));
        layoutWidget1 = new QWidget(audioGroupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 421, 71));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        setupBgMusicLabel = new QLabel(layoutWidget1);
        setupBgMusicLabel->setObjectName(QString::fromUtf8("setupBgMusicLabel"));

        verticalLayout_5->addWidget(setupBgMusicLabel);

        bgMusicPathLineEdit = new QLineEdit(layoutWidget1);
        bgMusicPathLineEdit->setObjectName(QString::fromUtf8("bgMusicPathLineEdit"));
        bgMusicPathLineEdit->setReadOnly(true);

        verticalLayout_5->addWidget(bgMusicPathLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        browseBgMusicButton = new QPushButton(layoutWidget1);
        browseBgMusicButton->setObjectName(QString::fromUtf8("browseBgMusicButton"));

        horizontalLayout_2->addWidget(browseBgMusicButton);

        resetBgMusicButton = new QPushButton(layoutWidget1);
        resetBgMusicButton->setObjectName(QString::fromUtf8("resetBgMusicButton"));

        horizontalLayout_2->addWidget(resetBgMusicButton);


        verticalLayout_5->addLayout(horizontalLayout_2);

        layoutWidget2 = new QWidget(audioGroupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 100, 421, 18));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        enableEffectCheckBox = new QCheckBox(layoutWidget2);
        enableEffectCheckBox->setObjectName(QString::fromUtf8("enableEffectCheckBox"));
        enableEffectCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(enableEffectCheckBox);

        enableLastWordCheckBox = new QCheckBox(layoutWidget2);
        enableLastWordCheckBox->setObjectName(QString::fromUtf8("enableLastWordCheckBox"));

        horizontalLayout_3->addWidget(enableLastWordCheckBox);

        enableBgMusicCheckBox = new QCheckBox(layoutWidget2);
        enableBgMusicCheckBox->setObjectName(QString::fromUtf8("enableBgMusicCheckBox"));
        enableBgMusicCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(enableBgMusicCheckBox);

        layoutWidget3 = new QWidget(audioGroupBox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 130, 411, 23));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        bgmVolumeLabel = new QLabel(layoutWidget3);
        bgmVolumeLabel->setObjectName(QString::fromUtf8("bgmVolumeLabel"));

        horizontalLayout_5->addWidget(bgmVolumeLabel);

        bgmVolumeSlider = new QSlider(layoutWidget3);
        bgmVolumeSlider->setObjectName(QString::fromUtf8("bgmVolumeSlider"));
        bgmVolumeSlider->setMaximum(100);
        bgmVolumeSlider->setValue(100);
        bgmVolumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(bgmVolumeSlider);

        layoutWidget3_2 = new QWidget(audioGroupBox);
        layoutWidget3_2->setObjectName(QString::fromUtf8("layoutWidget3_2"));
        layoutWidget3_2->setGeometry(QRect(10, 160, 411, 23));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        effectVolumeLabel = new QLabel(layoutWidget3_2);
        effectVolumeLabel->setObjectName(QString::fromUtf8("effectVolumeLabel"));

        horizontalLayout_6->addWidget(effectVolumeLabel);

        effectVolumeSlider = new QSlider(layoutWidget3_2);
        effectVolumeSlider->setObjectName(QString::fromUtf8("effectVolumeSlider"));
        effectVolumeSlider->setMaximum(100);
        effectVolumeSlider->setValue(100);
        effectVolumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(effectVolumeSlider);

        bgGroupBox = new QGroupBox(envTab);
        bgGroupBox->setObjectName(QString::fromUtf8("bgGroupBox"));
        bgGroupBox->setGeometry(QRect(10, 10, 441, 121));
        layoutWidget4 = new QWidget(bgGroupBox);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 421, 73));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        backgrounSetupLabel = new QLabel(layoutWidget4);
        backgrounSetupLabel->setObjectName(QString::fromUtf8("backgrounSetupLabel"));

        verticalLayout->addWidget(backgrounSetupLabel);

        bgPathLineEdit = new QLineEdit(layoutWidget4);
        bgPathLineEdit->setObjectName(QString::fromUtf8("bgPathLineEdit"));
        bgPathLineEdit->setReadOnly(true);

        verticalLayout->addWidget(bgPathLineEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        browseBgButton = new QPushButton(layoutWidget4);
        browseBgButton->setObjectName(QString::fromUtf8("browseBgButton"));

        horizontalLayout->addWidget(browseBgButton);

        resetBgButton = new QPushButton(layoutWidget4);
        resetBgButton->setObjectName(QString::fromUtf8("resetBgButton"));

        horizontalLayout->addWidget(resetBgButton);


        verticalLayout_2->addLayout(horizontalLayout);

        fitInViewCheckBox = new QCheckBox(bgGroupBox);
        fitInViewCheckBox->setObjectName(QString::fromUtf8("fitInViewCheckBox"));
        fitInViewCheckBox->setGeometry(QRect(10, 100, 151, 16));
        circularViewCheckBox = new QCheckBox(bgGroupBox);
        circularViewCheckBox->setObjectName(QString::fromUtf8("circularViewCheckBox"));
        circularViewCheckBox->setGeometry(QRect(160, 100, 101, 16));
        noIndicatorCheckBox = new QCheckBox(bgGroupBox);
        noIndicatorCheckBox->setObjectName(QString::fromUtf8("noIndicatorCheckBox"));
        noIndicatorCheckBox->setGeometry(QRect(330, 100, 95, 16));
        fontSetupGroupBox = new QGroupBox(envTab);
        fontSetupGroupBox->setObjectName(QString::fromUtf8("fontSetupGroupBox"));
        fontSetupGroupBox->setGeometry(QRect(10, 340, 441, 91));
        changeAppFontButton = new QPushButton(fontSetupGroupBox);
        changeAppFontButton->setObjectName(QString::fromUtf8("changeAppFontButton"));
        changeAppFontButton->setGeometry(QRect(270, 20, 161, 23));
        appFontLabel = new QLabel(fontSetupGroupBox);
        appFontLabel->setObjectName(QString::fromUtf8("appFontLabel"));
        appFontLabel->setGeometry(QRect(10, 20, 96, 16));
        appFontLineEdit = new QLineEdit(fontSetupGroupBox);
        appFontLineEdit->setObjectName(QString::fromUtf8("appFontLineEdit"));
        appFontLineEdit->setEnabled(true);
        appFontLineEdit->setGeometry(QRect(124, 23, 131, 20));
        appFontLineEdit->setReadOnly(true);
        textEditFontLineEdit = new QLineEdit(fontSetupGroupBox);
        textEditFontLineEdit->setObjectName(QString::fromUtf8("textEditFontLineEdit"));
        textEditFontLineEdit->setEnabled(true);
        textEditFontLineEdit->setGeometry(QRect(120, 50, 131, 20));
        textEditFontLineEdit->setReadOnly(false);
        setTextEditFontButton = new QPushButton(fontSetupGroupBox);
        setTextEditFontButton->setObjectName(QString::fromUtf8("setTextEditFontButton"));
        setTextEditFontButton->setGeometry(QRect(270, 50, 71, 23));
        textEditFontLabel = new QLabel(fontSetupGroupBox);
        textEditFontLabel->setObjectName(QString::fromUtf8("textEditFontLabel"));
        textEditFontLabel->setGeometry(QRect(10, 50, 91, 16));
        setTextEditColorButton = new QPushButton(fontSetupGroupBox);
        setTextEditColorButton->setObjectName(QString::fromUtf8("setTextEditColorButton"));
        setTextEditColorButton->setGeometry(QRect(350, 50, 75, 23));
        tabWidget->addTab(envTab, QString());
        gameTab = new QWidget();
        gameTab->setObjectName(QString::fromUtf8("gameTab"));
        layoutWidget5 = new QWidget(gameTab);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 20, 236, 22));
        formLayout = new QFormLayout(layoutWidget5);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        nullificationLabel = new QLabel(layoutWidget5);
        nullificationLabel->setObjectName(QString::fromUtf8("nullificationLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nullificationLabel);

        nullificationSpinBox = new QSpinBox(layoutWidget5);
        nullificationSpinBox->setObjectName(QString::fromUtf8("nullificationSpinBox"));
        nullificationSpinBox->setMinimum(5);
        nullificationSpinBox->setMaximum(15);
        nullificationSpinBox->setValue(8);

        formLayout->setWidget(0, QFormLayout::FieldRole, nullificationSpinBox);

        neverNullifyMyTrickCheckBox = new QCheckBox(gameTab);
        neverNullifyMyTrickCheckBox->setObjectName(QString::fromUtf8("neverNullifyMyTrickCheckBox"));
        neverNullifyMyTrickCheckBox->setGeometry(QRect(10, 60, 239, 16));
        neverNullifyMyTrickCheckBox->setChecked(true);
        minimizecCheckBox = new QCheckBox(gameTab);
        minimizecCheckBox->setObjectName(QString::fromUtf8("minimizecCheckBox"));
        minimizecCheckBox->setGeometry(QRect(10, 90, 241, 16));
        minimizecCheckBox->setChecked(true);
        tabWidget->addTab(gameTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 421, 100));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        smtpServerLabel = new QLabel(layoutWidget);
        smtpServerLabel->setObjectName(QString::fromUtf8("smtpServerLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, smtpServerLabel);

        smtpServerLineEdit = new QLineEdit(layoutWidget);
        smtpServerLineEdit->setObjectName(QString::fromUtf8("smtpServerLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, smtpServerLineEdit);

        senderLabel = new QLabel(layoutWidget);
        senderLabel->setObjectName(QString::fromUtf8("senderLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, senderLabel);

        senderLineEdit = new QLineEdit(layoutWidget);
        senderLineEdit->setObjectName(QString::fromUtf8("senderLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, senderLineEdit);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, passwordLineEdit);

        receiverLabel = new QLabel(layoutWidget);
        receiverLabel->setObjectName(QString::fromUtf8("receiverLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, receiverLabel);

        receiverLineEdit = new QLineEdit(layoutWidget);
        receiverLineEdit->setObjectName(QString::fromUtf8("receiverLineEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, receiverLineEdit);

        onlySaveLordCheckBox = new QCheckBox(tab);
        onlySaveLordCheckBox->setObjectName(QString::fromUtf8("onlySaveLordCheckBox"));
        onlySaveLordCheckBox->setGeometry(QRect(20, 140, 191, 16));
        tabWidget->addTab(tab, QString());
        buttonBox = new QDialogButtonBox(ConfigDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(140, 490, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
#ifndef QT_NO_SHORTCUT
        setupBgMusicLabel->setBuddy(bgMusicPathLineEdit);
        bgmVolumeLabel->setBuddy(bgmVolumeSlider);
        effectVolumeLabel->setBuddy(bgmVolumeSlider);
        backgrounSetupLabel->setBuddy(bgPathLineEdit);
        appFontLabel->setBuddy(appFontLineEdit);
        textEditFontLabel->setBuddy(textEditFontLineEdit);
        nullificationLabel->setBuddy(nullificationSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Config dialog", 0, QApplication::UnicodeUTF8));
        audioGroupBox->setTitle(QApplication::translate("ConfigDialog", "Audio", 0, QApplication::UnicodeUTF8));
        setupBgMusicLabel->setText(QApplication::translate("ConfigDialog", "Setup background music", 0, QApplication::UnicodeUTF8));
        browseBgMusicButton->setText(QApplication::translate("ConfigDialog", "Browse ...", 0, QApplication::UnicodeUTF8));
        resetBgMusicButton->setText(QApplication::translate("ConfigDialog", "Reset", 0, QApplication::UnicodeUTF8));
        enableEffectCheckBox->setText(QApplication::translate("ConfigDialog", "Enable effects", 0, QApplication::UnicodeUTF8));
        enableLastWordCheckBox->setText(QApplication::translate("ConfigDialog", "Enable last word", 0, QApplication::UnicodeUTF8));
        enableBgMusicCheckBox->setText(QApplication::translate("ConfigDialog", "Enable background music", 0, QApplication::UnicodeUTF8));
        bgmVolumeLabel->setText(QApplication::translate("ConfigDialog", "BGM    Volume", 0, QApplication::UnicodeUTF8));
        effectVolumeLabel->setText(QApplication::translate("ConfigDialog", "Effect Volume", 0, QApplication::UnicodeUTF8));
        bgGroupBox->setTitle(QApplication::translate("ConfigDialog", "Background", 0, QApplication::UnicodeUTF8));
        backgrounSetupLabel->setText(QApplication::translate("ConfigDialog", "Setup background", 0, QApplication::UnicodeUTF8));
        browseBgButton->setText(QApplication::translate("ConfigDialog", "Browse ...", 0, QApplication::UnicodeUTF8));
        resetBgButton->setText(QApplication::translate("ConfigDialog", "Reset", 0, QApplication::UnicodeUTF8));
        fitInViewCheckBox->setText(QApplication::translate("ConfigDialog", "Fit in view", 0, QApplication::UnicodeUTF8));
        circularViewCheckBox->setText(QApplication::translate("ConfigDialog", "Circular view", 0, QApplication::UnicodeUTF8));
        noIndicatorCheckBox->setText(QApplication::translate("ConfigDialog", "No indicator", 0, QApplication::UnicodeUTF8));
        fontSetupGroupBox->setTitle(QApplication::translate("ConfigDialog", "Font setup", 0, QApplication::UnicodeUTF8));
        changeAppFontButton->setText(QApplication::translate("ConfigDialog", "Set application font", 0, QApplication::UnicodeUTF8));
        appFontLabel->setText(QApplication::translate("ConfigDialog", "Application font", 0, QApplication::UnicodeUTF8));
        setTextEditFontButton->setText(QApplication::translate("ConfigDialog", "Font ...", 0, QApplication::UnicodeUTF8));
        textEditFontLabel->setText(QApplication::translate("ConfigDialog", "Text edit font", 0, QApplication::UnicodeUTF8));
        setTextEditColorButton->setText(QApplication::translate("ConfigDialog", "Color ...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(envTab), QApplication::translate("ConfigDialog", "Environment", 0, QApplication::UnicodeUTF8));
        nullificationLabel->setText(QApplication::translate("ConfigDialog", "Nullification count down", 0, QApplication::UnicodeUTF8));
        nullificationSpinBox->setSuffix(QApplication::translate("ConfigDialog", " seconds", 0, QApplication::UnicodeUTF8));
        neverNullifyMyTrickCheckBox->setText(QApplication::translate("ConfigDialog", "Never nullify my single target trick", 0, QApplication::UnicodeUTF8));
        minimizecCheckBox->setText(QApplication::translate("ConfigDialog", "Minimize the dialog when server runs", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(gameTab), QApplication::translate("ConfigDialog", "Game", 0, QApplication::UnicodeUTF8));
        smtpServerLabel->setText(QApplication::translate("ConfigDialog", "SMTP Server", 0, QApplication::UnicodeUTF8));
        smtpServerLineEdit->setPlaceholderText(QApplication::translate("ConfigDialog", "SMTP server's address", 0, QApplication::UnicodeUTF8));
        senderLabel->setText(QApplication::translate("ConfigDialog", "Sender", 0, QApplication::UnicodeUTF8));
        senderLineEdit->setPlaceholderText(QApplication::translate("ConfigDialog", "The sender's email address", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("ConfigDialog", "Password", 0, QApplication::UnicodeUTF8));
        passwordLineEdit->setPlaceholderText(QApplication::translate("ConfigDialog", "The password", 0, QApplication::UnicodeUTF8));
        receiverLabel->setText(QApplication::translate("ConfigDialog", "Receiver", 0, QApplication::UnicodeUTF8));
        receiverLineEdit->setPlaceholderText(QApplication::translate("ConfigDialog", "The receiver's email address", 0, QApplication::UnicodeUTF8));
        onlySaveLordCheckBox->setText(QApplication::translate("ConfigDialog", "Only save the record of lord", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConfigDialog", "Contest mode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
