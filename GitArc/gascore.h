#ifndef GASCORE_H
#define GASCORE_H

#include "constants.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QDir>

class GAScore
{
public:
    static GAScore* get();
    void saveScore(int);
    int readBestScore();

private:
    GAScore();
    static GAScore *singleton;
    int bestScore;
    QFile *file;
};

#endif // GASCORE_H
