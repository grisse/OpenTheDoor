#ifndef SCENE3_H
#define SCENE3_H

#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene3:public  Scene
{
public:
    Scene3();
    virtual ~Scene3();

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
	bool clickThirdKnife;
	bool clickThirdWrench;
	bool clickThirdShovel;
	short clickRedValveMake;
	short clickGreenValveMake;
	short clickBlueValveMake;
	short clickOrangeValveMake;
	bool clickSmallThirdKnife;
	bool clickSmallThirdShovel;
	bool openBagYes;
	bool carbonAndShovelYes;
	bool OpenLuziYes;
	bool clickSmallShovelCarbon;
	bool clickSmallThirdWrench;
	bool clickSmallThirdTiegan;
	bool clickThirdTiegan;
	bool openThirdDoorYes;
	bool clickOrangeGuanzi;
	bool clickBlueGuanzi;
	bool changeGuanziYes;
};

#endif // SCENE3_H
