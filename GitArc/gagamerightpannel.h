#ifndef GAGAMERIGHTPANNEL_H
#define GAGAMERIGHTPANNEL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class GAGameRightPannel : public QWidget
{
    Q_OBJECT

public:
    explicit GAGameRightPannel(QWidget *parent = nullptr);
    void setScore(int);
    void setTotalNote(int);
    void setTotalCorrectNote(int);

private:
    QLabel *lbScore;
    QLabel *lbTotalNote;
    QLabel *lbTotalCorrectNote;
};

#endif // GAGAMERIGHTPANNEL_H
