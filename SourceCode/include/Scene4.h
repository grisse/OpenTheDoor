#ifndef SCENE4_H
#define SCENE4_H

#include "LessonX.h"
#include "CommonAPI.h"
#include "Scene.h"

class Scene4:public  Scene
{
public:
    Scene4();
    virtual ~Scene4();

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
	bool clickFourthOildrum;
	bool clickFourthIronhook;
	bool clickFourthWoodenstick;
	bool openFourthJinggai;
	bool fouthTieding1Yes;
	bool fouthTieding2Yes;
	bool clickFourthWoodenboard;
	bool clickSmallFourthOildrum;
	bool clickSmallFourthIronhook;
	bool clickSmallFourthWoodensticlk;
	bool clickSmallFourthWoodenboard;
	bool clickSmallFourthPants;
	bool fourthWoodenboard_PantsYes;
	bool fourthBoard_Pants_oildYes;
	bool clickFourthWoodenboard_Pants;
	bool clickFourthBoard_Pants_oild;
	bool clickFourthPants;
	bool clickSmallFourthTorch;
	bool showFourthFiveLiangYes;
	bool clickFourthKey;
	bool fourthTorchYes;
	bool openFourthDoorYes;
	bool clickSmallFourthKey;
};

#endif // SCENE4_H
