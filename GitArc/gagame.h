#ifndef GAGAME_H
#define GAGAME_H

#include <QWidget>

class QHBoxLayout;
class QLabel;

class GAGame : public QWidget
{
    Q_OBJECT
public:
    explicit GAGame(QWidget *parent = nullptr);
};

#endif // GAGAME_H
