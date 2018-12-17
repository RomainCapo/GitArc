#ifndef GANOTEREADER_H
#define GANOTEREADER_H

#include <QList>
#include <QObject>

class QFile;
class QDebug;
class QString;
class QByteArray;
class QTimer;

class GANoteReader : public QObject
{
    Q_OBJECT
public:
    explicit GANoteReader(QString filename, QObject *parent = nullptr);
    void readPartition();
    void generatePartition();

public slots:
    void getNotes();

signals:
    void nextNotesLine(QByteArray notesLine);

private:
    QList<QByteArray> partition;
    QString fileName;
    int noteLineCount;
    QTimer *noteTimer;

    void readCSVNote();
};

#endif // GANOTEREADER_H
