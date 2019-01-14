#include "ganotereader.h"
#include "constants.h"
#include "gasettings.h"
#include <QFile>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>

GANoteReader::GANoteReader(QString fileName, QObject *parent) : QObject(parent)
{
    this->fileName = fileName;
}

void GANoteReader::getNotes()
{
    if(this->noteLineCount < this->partition.count())
    {
        emit nextNotesLine(this->partition[this->noteLineCount++]);
    }
}

void GANoteReader::readPartition()
{
    this->noteLineCount = 0;

    this->readCSVNote();

    this->noteTimer = new QTimer(this);
    noteTimer->setInterval(READ_TIME_INTERVAL - (GASettings::difficulty * 500));
    qDebug() << READ_TIME_INTERVAL - (GASettings::difficulty * 500);
    this->connect(noteTimer, &QTimer::timeout, this, &GANoteReader::getNotes);
    noteTimer->start();
}

void GANoteReader::pauseLecture()
{
    this->noteTimer->stop();
}

void GANoteReader::resumeLecture()
{
    this->noteTimer->start();
}

void GANoteReader::generatePartition()
{
    //remove and crate partiton file
    QFile::remove("..\\GitArc\\res\\partitions\\randomPartition.csv");
    QFile file("..\\GitArc\\res\\partitions\\randomPartition.csv");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);//use for read the file

        //that create a partion of NB_NOTES rows and NUM_NOTES lines
        for(int i = 0; i < NB_NOTES; i++)
        {
            for(int j = 0; j < NUM_NOTES; j++)
            {
                stream << QString::number(QRandomGenerator::global()->generate() % 2);//generate number between 0 and 1
                if(j != NUM_NOTES - 1)//put ';' symbol at the end of the number except for the last
                {
                    stream << ";";
                }
            }
            stream << endl;
        }
    }
    file.close();
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
        QByteArray line = file.readLine().trimmed();
        this->partition.append(line.split(';').join());
    }

    file.close();
}
