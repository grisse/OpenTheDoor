#ifndef SCENE6_H
#define SCENE6_H

#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene6:public  Scene
{
public:
    Scene6();
    virtual ~Scene6();

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
	bool clickSixthPipe;
	bool clickSixthTobaccoBag;
	bool clickSixthGuai;
	bool clickSixthChord;
	bool clickSmallSixthPipe;
	bool clickSmallSixthTobaccoBag;
	bool clickSmallSixthGuai;
	bool clickSmallSixthChord;
	bool sixthPipeAndTobaccoYes;
	bool sixthGuaiAndChord;
	bool clickSmallSixthPipeAndTobacco;
	bool clickSmallSixthGuaiAndChord;
	bool sixthPipeHuoYes;
	bool sixDoorKeyYes;
	bool clickSmallSixthPipeHuo;
	bool sixthMirrorOpenYes;
	short pwd1,pwd2,pwd3,pwd4;
	bool openSixthPwdboxYes;
	bool clickSixthWindowKey;
	bool sixthWindowOpenYes;
	bool clickSmallSixthWindowKey;
	bool clickSmallSixthDoorKey;
	bool sixthDoorOpenYes;
};

#endif // SCENE6_H
