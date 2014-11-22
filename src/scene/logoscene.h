#ifndef LOGOSCENE_H
#define LOGOSCENE_H

#include <QObject>
#include "scene.h"

class LogoScene : public Scene
{
    Q_OBJECT
public:
    LogoScene(QObject* parent = 0);
    virtual void action();
    void setupLogo();
    ~LogoScene();
private:
    Qneed* logo;
};

#endif // LOGOSCENE_H
