#include "gascore.h"

GAScore *GAScore::singleton = nullptr;

GAScore::GAScore()
{
    this->bestScore = 0;

    QString path = BEST_SCORE_PATH;
    QDir dir;

    if (!dir.exists(path))
        dir.mkpath(path);

    this->file = new QFile(path + "\\score.txt");

    this->readBestScore();
}

GAScore* GAScore::get()
{
    if (!singleton)
        singleton = new GAScore;
    return singleton;
}

void GAScore::saveScore(int score)
{
    if(score > this->bestScore)
    {
        this->bestScore = score;
        this->file->resize(0);

        QTextStream stream(this->file);
        stream << this->bestScore;
    }
}

int GAScore::getBestScore()
{
    return this->bestScore;
}

GAScore::~GAScore()
{
    delete this->file;
}

void GAScore::readBestScore()
{
    if (!this->file->open(QIODevice::ReadWrite))
    {
        qDebug() << this->file->errorString();
    }

    while (!this->file->atEnd())
    {
        QByteArray line = this->file->readLine().trimmed();
        this->bestScore = line.toInt();
    }
}
