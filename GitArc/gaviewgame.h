/**
* This class is a graphic view which contains all the game's grapical item.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVIEWGAME_H
#define GAVIEWGAME_H

#include <QGraphicsView>

class GAVerticalNotes;
class GAHorizontalNotesBar;
class QGraphicsLinearLayout;
class QGraphicsWidget;
class QByteArray;
class QLabel;
class GANote;
class QTimer;
class QPushButton;
class QHBoxLayout;
class QGraphicsTextItem;
class QMediaPlayer;
class GAGameRightPannel;
class GAScore;
class GANoteReader;

class GAViewGame : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewGame(QSize layoutSize,QWidget * _left, QWidget * _right, QMediaPlayer *_mainMusic, QGraphicsView *_parent = nullptr);
    ~GAViewGame();

public slots:
    void drawNoteLine(QByteArray notesLine);
    void timerGame();
    void closeGame();
    void toMenu();
    void pauseGame();
    void resumeGame();

signals:
    void wrongNotePlayed(int);
    void quitGameSig();
    void backToMenuSig();
    void pauseGameSig();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QGraphicsScene *scene;
    GAVerticalNotes *verticalNotes;
    GAHorizontalNotesBar *horizontalNotes;   
    QLabel *left;
    GAGameRightPannel *right;
    QList<QList<GANote*>*> * strips;
    QTimer *gameTimer;
    GAScore *scoreSaver;
    int score;
    int totalCorrectNotes;
    int totalNotes;
    bool isFirst;
    qreal result;
    QPushButton *btnQuit;
    QPushButton *btnBackToMenu;
    QPushButton *btnBackToGame;
    QPushButton *btnBackMenuInPause;
    QGraphicsTextItem *endGame;
    QGraphicsTextItem *scoreUser;
    QGraphicsTextItem *bestScore;
    QGraphicsTextItem *endText;
    QGraphicsTextItem *pauseGameText;
    QGraphicsTextItem *currentScore;
    QGraphicsTextItem *endTextPause;
    GANoteReader *noteReader;
    QMediaPlayer *mainMusic;

    bool isPaused;

    int getChordId(int);
    void displayEndGameMenu();
};

#endif // GAVIEWGAME_H
