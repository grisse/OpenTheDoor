#ifndef SCENE03_H
#define SCENE03_H
#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene03:public Scene
{
public:
    Scene03();
    virtual ~Scene03();

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

#endif // SCENE03_H
