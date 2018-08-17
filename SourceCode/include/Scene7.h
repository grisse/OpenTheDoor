#ifndef SCENE7_H
#define SCENE7_H

#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"
#include "Tools.h"

class Scene7:public  Scene
{
public:
    Scene7();
    virtual ~Scene7();

    virtual void GameMainLoop(float fTimeDelta );
    virtual void MouseMove( const float fMouseX, const float fMouseY );
    virtual void MouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
    virtual void MouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
    virtual void KeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress );
    virtual void KeyUp( const int iKey );
    virtual void SpriteColSprite( const char *szSrcName, const char *szTarName );
	virtual void init();


protected:

private:
	bool clickSeventhBottle;
	bool clickSeventhMugun;
	bool clickSeventhGuanzi;
	bool clickSmallSeventhBottle;
	bool clickSmallSeventhMugun;
	bool clickSmallSeventhGuanzi;
	bool openSeventhMirrorYes;
	bool openSeventhToiletYes;
};

#endif // SCENE7_H
