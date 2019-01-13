#include "gamainmenu.h"
#include "gagame.h"
#include "constants.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

/**
* GAMainMenu
* GAMainMenu constructor
*
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAMainMenu::GAMainMenu(QWidget *parent): QWidget(parent)
{
    this->aboutDialog = nullptr;
    this->rulesDialog = nullptr;
    this->optionsDialog = nullptr;

    this->setWindowTitle(tr("GitArc Menu"));
    this->showFullScreen();
    this->setStyleSheet("QWidget {background-color:rgb(79, 195, 247);}"
                "QPushButton {background-color: transparent; border-radius: 15; border: 4 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
            "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    QLabel *lbImg = new QLabel(this);
    lbImg->setPixmap(QPixmap(":res/img/GitArc.PNG"));
    lbImg->setScaledContents(true);

    QPushButton *btnPlay = new QPushButton(tr("&Play GitArc"), this);
    btnPlay->setFont(QFont(FONT, FONT_SIZE));
    btnPlay->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton *btnOptions = new QPushButton(tr("&Options"), this);
    btnOptions->setFont(QFont(FONT, FONT_SIZE));
    btnOptions->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton *btnRules = new QPushButton(tr("&Rules"), this);
    btnRules->setFont(QFont(FONT, FONT_SIZE));
    btnRules->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton *btnAbout = new QPushButton(tr("&About"), this);
    btnAbout->setFont(QFont(FONT, FONT_SIZE));
    btnAbout->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton *btnQuit = new QPushButton(tr("&Quit Game"), this);
    btnQuit->setFont(QFont(FONT, FONT_SIZE));
    btnQuit->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QLabel *lbInfo = new QLabel(tr("Game designed by : Capocasale Romain, Freiburghaus Jonas and Moulin Vincent"), this);
    lbInfo->setFont(QFont(FONT, FONT_SIZE));
    lbInfo->setStyleSheet("QLabel {color: rgb(250, 250, 250);}");

    //add widget to the layout
    QVBoxLayout *vboxLayout = new QVBoxLayout(this);
    vboxLayout->addWidget(lbImg);
    vboxLayout->addWidget(btnPlay);
    vboxLayout->addWidget(btnOptions);
    vboxLayout->addWidget(btnRules);
    vboxLayout->addWidget(btnAbout);
    vboxLayout->addWidget(btnQuit);
    vboxLayout->addWidget(lbInfo);
    vboxLayout->setAlignment(Qt::AlignCenter);
    vboxLayout->setSpacing(30);
    this->setLayout(vboxLayout);

    this->connect(btnPlay, &QPushButton::clicked, this, &GAMainMenu::showGame);
    this->connect(btnQuit, &QPushButton::clicked, this, &QApplication::quit);
    this->connect(btnAbout, &QPushButton::clicked, this, &GAMainMenu::showAbout);
    this->connect(btnOptions, &QPushButton::clicked, this, &GAMainMenu::showOptions);
    this->connect(btnRules, &QPushButton::clicked, this, &GAMainMenu::showRules);
}

GAMainMenu::~GAMainMenu()
{
    delete this->aboutDialog;
    delete this->optionsDialog;
    delete this->rulesDialog;
}

/**
* GAMainMenu
*
* display the game window
*/
void GAMainMenu::showGame()
{
    this->close();
    GAGame *game = new GAGame();
    Q_UNUSED(game);//use the macro to disable warning
}

/**
* GAMainMenu
*
* display the about modal window
*/
void GAMainMenu::showAbout()
{
    this->aboutDialog = new GAShowAbout();
    this->aboutDialog->show();
}

/**
* GAMainMenu
*
* display the options modal window
*/
void GAMainMenu::showOptions()
{
    this->optionsDialog = new GAShowOptions();
    this->optionsDialog->show();
}

/**
* GAMainMenu
*
* display the rules modal window
*/
void GAMainMenu::showRules()
{
    this->rulesDialog = new GAShowRules();
    this->rulesDialog->show();
}
