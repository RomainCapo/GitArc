#ifndef GANOTEREADER_H
#define GANOTEREADER_H

class QString;
class QFile;
class QDebug;

class GANoteReader
{
public:
    GANoteReader();
    void readCSVNote(QString filename);
};

#endif // GANOTEREADER_H
