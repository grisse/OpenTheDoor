#ifndef SCENE02_H
#define SCENE02_H

#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene02:public Scene
{
public:
    Scene02();
    virtual ~Scene02();

    virtual void GameMainLoop(float fTimeDelta );
    virtual void MouseMove( const float fMouseX, const float fMouseY );
    virtual void MouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
    virtual void MouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
    virtual void KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress );
    virtual void KeyUp( const int iKey );
    virtual void SpriteColSprite( const char *szSrcName, const char *szTarName );

protected:

private:
};

#endif // SCENE02_H
