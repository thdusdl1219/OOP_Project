#ifndef LOGOSCENE_H
#define LOGOSCENE_H

#include <QObject>
#include "scene.h"
#include "../qneed.h"

class LogoScene : public Scene
{
    Q_OBJECT
public:
    LogoScene(QObject* parent = 0);
    void setupLogo();
    ~LogoScene();
private:
    Qneed* logo;

public slots:
    void goinit();
};


#endif // LOGOSCENE_H
