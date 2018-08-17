#ifndef SCENE5_H
#define SCENE5_H

#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene5:public  Scene
{
public:
    Scene5();
    virtual ~Scene5();

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
	bool clickSmallFifthCheese;
	bool clickFifthCheese;
	bool clickFifthCheesedIsPointInSprite;
	bool clickFifthScissors;
	bool clickFifthBowl;
	bool showSmallFifthChefKeyYes;
	bool openFifthBagYes;
	bool clickSmallFifthScissors;
	bool clickSmallFifthBowl;
	bool clickFifthCup;
	bool clickFifthCanzi;
	bool clickFifthCazi;
	bool clickSmallFifthChefKey;
	bool openFifthChefYes;
	bool clickSmallFifthCanzi;
	bool clickSmallFifthCazi;
	bool openFifthDrawerYes;
	bool clickFifthSword;
	bool clickSmallFifthSword;
	bool openFifthBreadYes;
	bool clickSmallFifthCup;
	bool fifthChefWanYes;
	bool clickFifthBigbowl;
	bool clickSmallFifthBigbowl;
	bool fifthCanziAndBigbowl;
	bool clickFifthCanziAndBigbowl;
	bool fifthCanziAndBBowlYes;
	bool fifthBBowlCoverYes;
	bool clickFifthDoorKey;
	bool clickSmallFifthDoorKey;
	bool openFifthDoorYes;
};

#endif // SCENE5_H
