#include "ganotereader.h"
#include <QFile>
#include <QList>
#include <QDebug>
#include <QTimer>

GANoteReader::GANoteReader(QString fileName, QObject *parent) : QObject(parent)
{
    this->fileName = fileName;
}

void GANoteReader::getNotes()
{
    if(this->noteLineCount < this->partition.count())
        emit nextNotesLine(this->partition[this->noteLineCount++]);
}

void GANoteReader::readPartition()
{
    this->noteLineCount = 0;

    this->readCSVNote();

    this->noteTimer = new QTimer(this);
    // FIXME : fréquence d'échantillonage pas en magique
    noteTimer->setInterval(1000);
    this->connect(noteTimer, &QTimer::timeout, this, &GANoteReader::getNotes);
    noteTimer->start();
}

void GANoteReader::readCSVNote()
{
    QFile file(this->fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << file.errorString();
    }

    this->partition.clear();
    while (!file.atEnd())
    {
        // FIXME : Check line is readable
        QByteArray line = file.readLine().trimmed();
        this->partition.append(line.split(';').join());
    }
}
