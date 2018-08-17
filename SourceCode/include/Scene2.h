#ifndef SCENE2_H
#define SCENE2_H

#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene2:public  Scene
{
public:
    Scene2();
    virtual ~Scene2();

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
	bool clickSecondCrutch;
	bool clickSecondHammer;
	bool clickSmallSecondhammer;
	bool clickSmallSecondcrutch;
	bool openWindowYes;
	//char *secondTexts[5];
	//char *secondTextk[5];
	//char *secondTextz[5];
	//char *secondTexty[5];
	short secondTextsindex;
	short secondTextkindex;
	short secondTextzindex;
	short secondTextyindex;
	bool clickSmallSecondknife;
	bool clickSmallsecondKnifeAndHammer;
	bool clickSecondKnife;
	bool hammerAndKnifeYes;
	bool openDeskYes;
	bool clickSecondKey;
	bool clickSmallSecondkey;
	bool openSecondDoorYes;
};

#endif // SCENE2_H
