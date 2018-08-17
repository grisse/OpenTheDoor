#ifndef SCENE1_H
#define SCENE1_H
#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene1:public  Scene
{
public:
    Scene1();
    virtual ~Scene1();

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
	short TextBoxMark;
	bool showPromptCircleCar;
	bool showPromptCircle;
	bool clickTextBoxSeven;
	bool clickTextBoxFive;
	bool clickDrill;
	bool clickZuanJian;
	bool clickSmallDrill;
	bool clickSmallZuanjian;
	bool clickZuanji;
	bool openBoxYes;
	bool clickOpenBox;
	//bool clickRuby;
	bool clickTextBoxFifteen;
	bool clickPromptCircleTrain;
	bool showPromptCircleTrain;
	short pwd1,pwd2,pwd3;
	bool zuanjiYes;
	bool clickSmallKey1;
	bool openTrainYes;
	bool openPwdBoxYes;
	bool clickKey1;
	bool clickPromptCircleTraindoor;
};

#endif // SCENE1_H
