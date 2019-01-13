#include "gaendgamemenu.h"

GAEndGameMenu::GAEndGameMenu(int score, int bestScore)
{
    QGraphicsTextItem endGame("End of the game !", this);
    QGraphicsTextItem scoreUser(QString("Your score : %1").arg(score), this);
    QGraphicsTextItem bestScoreEver(QString("Best score : %1").arg(bestScore), this);

    endGame.setDefaultTextColor(QColor(250, 250, 250));
    scoreUser.setDefaultTextColor(QColor(250, 250, 250));
    bestScoreEver.setDefaultTextColor(QColor(250, 250, 250));

    endGame.setY(300);
    scoreUser.setY(450);
    bestScoreEver.setY(550);

    endGame.setFont(QFont("Times", 60, QFont::Bold));
    scoreUser.setFont(QFont("Times", 40, QFont::Bold));
    bestScoreEver.setFont(QFont("Times", 30, QFont::Bold));

    QPushButton btnQuit("Quit game");
    btnQuit.move(QPoint(0,700));
    this->connect(&btnQuit, &QPushButton::clicked, this, &GAEndGameMenu::close);

    btnQuit.resize(QSize(250,60));
    btnQuit.setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                           "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    QPushButton btnBackToMenu("Menu");
    btnBackToMenu.move(QPoint(300,700));
    this->connect(&btnBackToMenu, &QPushButton::clicked, this, &GAEndGameMenu::toMenu);

    btnBackToMenu.resize(QSize(250,60));
    btnBackToMenu.setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                           "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    QGraphicsTextItem endText(tr("Game designed by : Capocasale Romain, Freiburghaus Jonas and Moulin Vincent - Projet P2 GitArc"), this);
    endText.setY(800);
    endText.setFont(QFont("Times", 15, QFont::Normal));
    endText.setDefaultTextColor(QColor(250, 250, 250));
}

void GAEndGameMenu::toMenu()
{
    emit this->toMenuSig();
}

void GAEndGameMenu::closeGame()
{
    emit this->quitGameSig();
}
