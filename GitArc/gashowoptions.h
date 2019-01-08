#ifndef GASHOWOPTIONS_H
#define GASHOWOPTIONS_H

#include <QDialog>

class GAShowOptions : public QDialog
{
    Q_OBJECT
public:
    explicit GAShowOptions(QWidget *parent = nullptr);

signals:

public slots:
    void quitOptions();

};

#endif // GASHOWOPTIONS_H
