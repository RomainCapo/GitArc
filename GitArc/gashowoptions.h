#ifndef GASHOWOPTIONS_H
#define GASHOWOPTIONS_H

#include <QDialog>

class QComboBox;

class GAShowOptions : public QDialog
{
    Q_OBJECT
public:
    explicit GAShowOptions(QWidget *parent = nullptr);

private :
    QComboBox * cbxMusic;
    QComboBox * cbxDifficulty;
signals:

public slots:
    void quitOptions();
    void applyMusic();
};

#endif // GASHOWOPTIONS_H
