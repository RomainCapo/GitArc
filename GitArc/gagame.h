#ifndef GAGAME_H
#define GAGAME_H

#include "gaviewmainmenu.h"

#include <QWidget>

class QHBoxLayout;
class QLabel;

class GAGame : public QWidget
{
    Q_OBJECT
public:
    explicit GAGame(QWidget *parent = nullptr);

public slots:
    void quitGame();
};

#endif // GAGAME_H
