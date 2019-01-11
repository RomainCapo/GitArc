#include "gashowoptions.h"
#include "constants.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>

GAShowOptions::GAShowOptions(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("Options"));
    this->setFixedSize(1000, 500);
    this->setStyleSheet("QWidget {background-color:#0277BD; color:white;}"
                        "QPushButton {background-color: transparent; border-radius: 15; border: 4 solid #E1F5FE; color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                        "QPushButton:hover { background-color: rgb(129, 212, 250);}"
                        "QComboBox {background-color:white; color:black;}");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *lblInfo = new QLabel("Options", this);
    lblInfo->setFont(QFont(FONT, FONT_SIZE));

    QComboBox *cbxMusic = new QComboBox(this);
    cbxMusic->addItem("A$ap Ferg - New Level");
    cbxMusic->addItem("Desiigner - Panda");
    cbxMusic->addItem("50 Cent - P.I.M.P");
    cbxMusic->setFont(QFont(FONT, FONT_SIZE));

    QPushButton * btnApply = new QPushButton("Apply music change", this);
    btnApply->setFont(QFont(FONT, FONT_SIZE));
    btnApply->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton * btnQuit = new QPushButton("Quit Options", this);
    btnQuit->setFont(QFont(FONT, FONT_SIZE));
    btnQuit->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    mainLayout->addWidget(lblInfo);
    mainLayout->addWidget(cbxMusic);
    mainLayout->addWidget(btnApply);
    mainLayout->addWidget(btnQuit);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(50);
    this->setLayout(mainLayout);

    this->connect(btnQuit, &QPushButton::clicked, this, &GAShowOptions::quitOptions);
}

void GAShowOptions::quitOptions()
{
    this->close();
}
