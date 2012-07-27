/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jul 26 13:32:27 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionConfigure;
    QAction *actionStart_Server;
    QAction *actionStart_Game;
    QAction *actionGeneral_Overview;
    QAction *actionAbout;
    QAction *actionCard_Overview;
    QAction *actionEnable_Hotkey;
    QAction *actionAbout_Qt;
    QAction *actionView_Discarded;
    QAction *actionView_distance;
    QAction *actionServerInformation;
    QAction *actionKick;
    QAction *actionReplay;
    QAction *actionSaveRecord;
    QAction *actionFullscreen;
    QAction *actionShow_Hide_Menu;
    QAction *actionSurrender;
    QAction *actionMinimize_to_system_tray;
    QAction *actionRole_assign_table;
    QAction *actionScenario_Overview;
    QAction *actionScript_editor;
    QAction *actionBroadcast;
    QAction *actionAcknowledgement;
    QAction *actionDamage_maker;
    QAction *actionExpand_dashboard;
    QAction *actionGet_card;
    QAction *actionDeath_note;
    QAction *actionRevive_wand;
    QAction *actionCard_editor;
    QAction *actionPC_Console_Start;
    QAction *actionPackaging;
    QAction *actionAI_Melee;
    QAction *actionReplay_file_convert;
    QAction *actionSend_lowlevel_command;
    QAction *actionView_ban_list;
    QAction *actionAbout_fmod;
    QAction *actionAbout_Lua;
    QAction *actionExecute_script_at_server_side;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuCheat;
    QMenu *menuDIY;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        actionConfigure->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../image/system/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon);
        actionStart_Server = new QAction(MainWindow);
        actionStart_Server->setObjectName(QString::fromUtf8("actionStart_Server"));
        actionStart_Game = new QAction(MainWindow);
        actionStart_Game->setObjectName(QString::fromUtf8("actionStart_Game"));
        actionGeneral_Overview = new QAction(MainWindow);
        actionGeneral_Overview->setObjectName(QString::fromUtf8("actionGeneral_Overview"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionCard_Overview = new QAction(MainWindow);
        actionCard_Overview->setObjectName(QString::fromUtf8("actionCard_Overview"));
        actionEnable_Hotkey = new QAction(MainWindow);
        actionEnable_Hotkey->setObjectName(QString::fromUtf8("actionEnable_Hotkey"));
        actionEnable_Hotkey->setCheckable(true);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionView_Discarded = new QAction(MainWindow);
        actionView_Discarded->setObjectName(QString::fromUtf8("actionView_Discarded"));
        actionView_Discarded->setEnabled(false);
        actionView_distance = new QAction(MainWindow);
        actionView_distance->setObjectName(QString::fromUtf8("actionView_distance"));
        actionView_distance->setEnabled(false);
        actionServerInformation = new QAction(MainWindow);
        actionServerInformation->setObjectName(QString::fromUtf8("actionServerInformation"));
        actionServerInformation->setEnabled(false);
        actionKick = new QAction(MainWindow);
        actionKick->setObjectName(QString::fromUtf8("actionKick"));
        actionKick->setEnabled(false);
        actionReplay = new QAction(MainWindow);
        actionReplay->setObjectName(QString::fromUtf8("actionReplay"));
        actionSaveRecord = new QAction(MainWindow);
        actionSaveRecord->setObjectName(QString::fromUtf8("actionSaveRecord"));
        actionSaveRecord->setEnabled(false);
        actionFullscreen = new QAction(MainWindow);
        actionFullscreen->setObjectName(QString::fromUtf8("actionFullscreen"));
        actionShow_Hide_Menu = new QAction(MainWindow);
        actionShow_Hide_Menu->setObjectName(QString::fromUtf8("actionShow_Hide_Menu"));
        actionSurrender = new QAction(MainWindow);
        actionSurrender->setObjectName(QString::fromUtf8("actionSurrender"));
        actionSurrender->setEnabled(false);
        actionMinimize_to_system_tray = new QAction(MainWindow);
        actionMinimize_to_system_tray->setObjectName(QString::fromUtf8("actionMinimize_to_system_tray"));
        actionRole_assign_table = new QAction(MainWindow);
        actionRole_assign_table->setObjectName(QString::fromUtf8("actionRole_assign_table"));
        actionScenario_Overview = new QAction(MainWindow);
        actionScenario_Overview->setObjectName(QString::fromUtf8("actionScenario_Overview"));
        actionScript_editor = new QAction(MainWindow);
        actionScript_editor->setObjectName(QString::fromUtf8("actionScript_editor"));
        actionScript_editor->setEnabled(true);
        actionBroadcast = new QAction(MainWindow);
        actionBroadcast->setObjectName(QString::fromUtf8("actionBroadcast"));
        actionAcknowledgement = new QAction(MainWindow);
        actionAcknowledgement->setObjectName(QString::fromUtf8("actionAcknowledgement"));
        actionDamage_maker = new QAction(MainWindow);
        actionDamage_maker->setObjectName(QString::fromUtf8("actionDamage_maker"));
        actionDamage_maker->setEnabled(true);
        actionExpand_dashboard = new QAction(MainWindow);
        actionExpand_dashboard->setObjectName(QString::fromUtf8("actionExpand_dashboard"));
        actionExpand_dashboard->setCheckable(true);
        actionGet_card = new QAction(MainWindow);
        actionGet_card->setObjectName(QString::fromUtf8("actionGet_card"));
        actionGet_card->setEnabled(true);
        actionDeath_note = new QAction(MainWindow);
        actionDeath_note->setObjectName(QString::fromUtf8("actionDeath_note"));
        actionRevive_wand = new QAction(MainWindow);
        actionRevive_wand->setObjectName(QString::fromUtf8("actionRevive_wand"));
        actionCard_editor = new QAction(MainWindow);
        actionCard_editor->setObjectName(QString::fromUtf8("actionCard_editor"));
        actionPC_Console_Start = new QAction(MainWindow);
        actionPC_Console_Start->setObjectName(QString::fromUtf8("actionPC_Console_Start"));
        actionPackaging = new QAction(MainWindow);
        actionPackaging->setObjectName(QString::fromUtf8("actionPackaging"));
        actionAI_Melee = new QAction(MainWindow);
        actionAI_Melee->setObjectName(QString::fromUtf8("actionAI_Melee"));
        actionReplay_file_convert = new QAction(MainWindow);
        actionReplay_file_convert->setObjectName(QString::fromUtf8("actionReplay_file_convert"));
        actionSend_lowlevel_command = new QAction(MainWindow);
        actionSend_lowlevel_command->setObjectName(QString::fromUtf8("actionSend_lowlevel_command"));
        actionView_ban_list = new QAction(MainWindow);
        actionView_ban_list->setObjectName(QString::fromUtf8("actionView_ban_list"));
        actionAbout_fmod = new QAction(MainWindow);
        actionAbout_fmod->setObjectName(QString::fromUtf8("actionAbout_fmod"));
        actionAbout_Lua = new QAction(MainWindow);
        actionAbout_Lua->setObjectName(QString::fromUtf8("actionAbout_Lua"));
        actionExecute_script_at_server_side = new QAction(MainWindow);
        actionExecute_script_at_server_side->setObjectName(QString::fromUtf8("actionExecute_script_at_server_side"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuCheat = new QMenu(menuBar);
        menuCheat->setObjectName(QString::fromUtf8("menuCheat"));
        menuCheat->setEnabled(false);
        menuDIY = new QMenu(menuBar);
        menuDIY->setObjectName(QString::fromUtf8("menuDIY"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuGame->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuDIY->menuAction());
        menuBar->addAction(menuCheat->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuGame->addAction(actionStart_Game);
        menuGame->addAction(actionStart_Server);
        menuGame->addAction(actionPC_Console_Start);
        menuGame->addAction(actionReplay);
        menuGame->addAction(actionExit);
        menuOptions->addAction(actionConfigure);
        menuOptions->addAction(actionGeneral_Overview);
        menuOptions->addAction(actionCard_Overview);
        menuOptions->addAction(actionScenario_Overview);
        menuOptions->addAction(actionView_ban_list);
        menuOptions->addAction(actionBroadcast);
        menuOptions->addAction(actionAI_Melee);
        menuOptions->addAction(actionReplay_file_convert);
        menuOptions->addSeparator();
        menuOptions->addAction(actionEnable_Hotkey);
        menuOptions->addAction(actionExpand_dashboard);
        menuOptions->addAction(actionView_Discarded);
        menuOptions->addAction(actionView_distance);
        menuOptions->addAction(actionServerInformation);
        menuOptions->addAction(actionSurrender);
        menuOptions->addAction(actionKick);
        menuOptions->addAction(actionSaveRecord);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        menuHelp->addAction(actionAbout_Lua);
        menuHelp->addAction(actionAbout_fmod);
        menuHelp->addAction(actionAcknowledgement);
        menuHelp->addSeparator();
        menuHelp->addAction(actionRole_assign_table);
        menuView->addAction(actionShow_Hide_Menu);
        menuView->addAction(actionFullscreen);
        menuView->addAction(actionMinimize_to_system_tray);
        menuCheat->addAction(actionGet_card);
        menuCheat->addAction(actionDamage_maker);
        menuCheat->addAction(actionDeath_note);
        menuCheat->addAction(actionRevive_wand);
        menuCheat->addAction(actionSend_lowlevel_command);
        menuCheat->addAction(actionExecute_script_at_server_side);
        menuDIY->addAction(actionCard_editor);
        menuDIY->addAction(actionScript_editor);
        menuDIY->addAction(actionPackaging);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sanguosha", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionConfigure->setText(QApplication::translate("MainWindow", "Configure", 0, QApplication::UnicodeUTF8));
        actionStart_Server->setText(QApplication::translate("MainWindow", "Start server", 0, QApplication::UnicodeUTF8));
        actionStart_Server->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionStart_Game->setText(QApplication::translate("MainWindow", "Start game", 0, QApplication::UnicodeUTF8));
        actionStart_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionGeneral_Overview->setText(QApplication::translate("MainWindow", "General overview", 0, QApplication::UnicodeUTF8));
        actionGeneral_Overview->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionCard_Overview->setText(QApplication::translate("MainWindow", "Card overview", 0, QApplication::UnicodeUTF8));
        actionCard_Overview->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionEnable_Hotkey->setText(QApplication::translate("MainWindow", "Enable hotkey", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionView_Discarded->setText(QApplication::translate("MainWindow", "View Discarded", 0, QApplication::UnicodeUTF8));
        actionView_Discarded->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionView_distance->setText(QApplication::translate("MainWindow", "View distance", 0, QApplication::UnicodeUTF8));
        actionView_distance->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionServerInformation->setText(QApplication::translate("MainWindow", "Server information", 0, QApplication::UnicodeUTF8));
        actionKick->setText(QApplication::translate("MainWindow", "Kick", 0, QApplication::UnicodeUTF8));
        actionReplay->setText(QApplication::translate("MainWindow", "Replay", 0, QApplication::UnicodeUTF8));
        actionSaveRecord->setText(QApplication::translate("MainWindow", "Save battle record", 0, QApplication::UnicodeUTF8));
        actionFullscreen->setText(QApplication::translate("MainWindow", "Fullscreen", 0, QApplication::UnicodeUTF8));
        actionFullscreen->setShortcut(QApplication::translate("MainWindow", "Alt+Return", 0, QApplication::UnicodeUTF8));
        actionShow_Hide_Menu->setText(QApplication::translate("MainWindow", "Show/Hide menu", 0, QApplication::UnicodeUTF8));
        actionShow_Hide_Menu->setShortcut(QApplication::translate("MainWindow", "Alt+M", 0, QApplication::UnicodeUTF8));
        actionSurrender->setText(QApplication::translate("MainWindow", "Surrender", 0, QApplication::UnicodeUTF8));
        actionMinimize_to_system_tray->setText(QApplication::translate("MainWindow", "Minimize to system tray", 0, QApplication::UnicodeUTF8));
        actionMinimize_to_system_tray->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0, QApplication::UnicodeUTF8));
        actionRole_assign_table->setText(QApplication::translate("MainWindow", "Role assign table", 0, QApplication::UnicodeUTF8));
        actionScenario_Overview->setText(QApplication::translate("MainWindow", "Scenario overview", 0, QApplication::UnicodeUTF8));
        actionScript_editor->setText(QApplication::translate("MainWindow", "Script editor", 0, QApplication::UnicodeUTF8));
        actionBroadcast->setText(QApplication::translate("MainWindow", "Broadcast ...", 0, QApplication::UnicodeUTF8));
        actionAcknowledgement->setText(QApplication::translate("MainWindow", "Acknowledgement", 0, QApplication::UnicodeUTF8));
        actionDamage_maker->setText(QApplication::translate("MainWindow", "Damage maker", 0, QApplication::UnicodeUTF8));
        actionExpand_dashboard->setText(QApplication::translate("MainWindow", "Expand dashboard", 0, QApplication::UnicodeUTF8));
        actionGet_card->setText(QApplication::translate("MainWindow", "Get card ...", 0, QApplication::UnicodeUTF8));
        actionDeath_note->setText(QApplication::translate("MainWindow", "Death note ...", 0, QApplication::UnicodeUTF8));
        actionRevive_wand->setText(QApplication::translate("MainWindow", "Revive wand ...", 0, QApplication::UnicodeUTF8));
        actionCard_editor->setText(QApplication::translate("MainWindow", "Card editor ...", 0, QApplication::UnicodeUTF8));
        actionCard_editor->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionPC_Console_Start->setText(QApplication::translate("MainWindow", "PC Console Start", 0, QApplication::UnicodeUTF8));
        actionPackaging->setText(QApplication::translate("MainWindow", "Package manager ...", 0, QApplication::UnicodeUTF8));
        actionPackaging->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionAI_Melee->setText(QApplication::translate("MainWindow", "AI Melee", 0, QApplication::UnicodeUTF8));
        actionAI_Melee->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        actionReplay_file_convert->setText(QApplication::translate("MainWindow", "Replay file convert ...", 0, QApplication::UnicodeUTF8));
        actionSend_lowlevel_command->setText(QApplication::translate("MainWindow", "Send lowlevel command ...", 0, QApplication::UnicodeUTF8));
        actionView_ban_list->setText(QApplication::translate("MainWindow", "View ban list", 0, QApplication::UnicodeUTF8));
        actionAbout_fmod->setText(QApplication::translate("MainWindow", "About fmod", 0, QApplication::UnicodeUTF8));
        actionAbout_Lua->setText(QApplication::translate("MainWindow", "About Lua", 0, QApplication::UnicodeUTF8));
        actionExecute_script_at_server_side->setText(QApplication::translate("MainWindow", "Execute script at server side ...", 0, QApplication::UnicodeUTF8));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuCheat->setTitle(QApplication::translate("MainWindow", "Cheat", 0, QApplication::UnicodeUTF8));
        menuDIY->setTitle(QApplication::translate("MainWindow", "DIY", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
