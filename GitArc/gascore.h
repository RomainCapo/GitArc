#ifndef GASCORE_H
#define GASCORE_H

#include <QFile>
#include <QString>
#include <QDebug>
#include <QDir>

class GAScore
{
public:
    static GAScore* get();
    void saveScore(int);
    int getBestScore();
    ~GAScore();

private:
    GAScore();
    static GAScore *singleton;
    int bestScore;
    QFile *file;

    void readBestScore();
};

#endif // GASCORE_H
