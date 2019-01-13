#ifndef GAWIDGETSTACK_H
#define GAWIDGETSTACK_H

#include "gamainmenu.h"

#include <QWidget>
#include <QStackedWidget>

class GAWidgetStack : public QWidget
{
    Q_OBJECT
public:
    explicit GAWidgetStack(QWidget *parent = nullptr);

private:
    QStackedWidget *widgetStack;
};

#endif // GAWIDGETSTACK_H
