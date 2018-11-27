#include "ganotereader.h"
#include <QString>
#include <QFile>
#include <QList>
#include <QDebug>

GANoteReader::GANoteReader()
{
}

void GANoteReader::readCSVNote(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << file.errorString();
    }

    QList<QByteArray> partition;
    while (!file.atEnd())
    {
        // FIXME : Check line is readable
        QByteArray line = file.readLine().trimmed();
        partition.append(line.split(';').join());
    }

    qDebug() << partition;
}
