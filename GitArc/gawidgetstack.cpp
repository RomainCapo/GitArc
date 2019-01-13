#include "gawidgetstack.h"


GAWidgetStack::GAWidgetStack(QWidget *parent) : QWidget(parent)
{
    this->widgetStack = new QStackedWidget(this);
    this->widgetStack->addWidget(new GAMainMenu(this));
    this->setStyleSheet(QWidget {background-color:rgb(79, 195, 247);}");
}
