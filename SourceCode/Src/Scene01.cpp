#include "Scene01.h"

Scene01::Scene01(){}

Scene01::~Scene01() {}

void Scene01::GameMainLoop(float fTimeDelta){
	openingSound= dPlaySound("Music.wav",1,0.5);
	if(checkpointFirstpass==1) //第一关过关后关卡二图标显示
		dSetSpriteVisible("checkpointSecond",1);
	if(checkpointSecondpass==1)
		dSetSpriteVisible("checkpointThird",1);
	if(checkpointThirdpass==1)
		dSetSpriteVisible("checkpointFourth",1);
	if(checkpointFourthpass==1)
		dSetSpriteVisible("checkpointFifth",1);
	if(checkpointFifthpass==1)
		dSetSpriteVisible("checkpointSixth",1);
	if(checkpointSixthpass==1)
		dSetSpriteVisible("checkpointSeventh",1);
}

void Scene01::MouseMove(const float fMouseX, const float fMouseY){
	tools.BiggerSprite(1,"checkpointBackButton",fMouseX,fMouseY);
	tools.BiggerSprite(1,"checkpointFirst",fMouseX,fMouseY);
	tools.BiggerSprite(checkpointFirstpass,"checkpointSecond",fMouseX,fMouseY);
	tools.BiggerSprite(checkpointSecondpass,"checkpointThird",fMouseX,fMouseY);
	tools.BiggerSprite(checkpointThirdpass,"checkpointFourth",fMouseX,fMouseY);
	tools.BiggerSprite(checkpointFourthpass,"checkpointFifth",fMouseX,fMouseY);
	tools.BiggerSprite(checkpointFifthpass,"checkpointSixth",fMouseX,fMouseY);
	tools.BiggerSprite(checkpointSeventhpass,"checkpointSeventh",fMouseX,fMouseY);
}

void Scene01::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=1;
	if(dIsPointInSprite("checkpointBackButton",fMouseX,fMouseY)){
		tools.ClickChangeScene("checkpointBackButton","GameMainInterface.t2d",fMouseX,fMouseY);
		SceneState=0;
	}
	if(dIsSpriteVisible("checkpointFirst")==1 && dIsPointInSprite("checkpointFirst",fMouseX,fMouseY)){
		SceneState=4;
		tools.ClickChangeScene("checkpointFirst","CheckpointFirst_one.t2d",fMouseX,fMouseY);
		dStopAllSound();
	}
	if(dIsSpriteVisible("checkpointSecond")==1 && dIsPointInSprite("checkpointSecond",fMouseX,fMouseY)){
		SceneState=5;
		tools.ClickChangeScene("checkpointSecond","CheckpointSecond_one.t2d",fMouseX,fMouseY);
		dStopAllSound();
	}
	if(dIsSpriteVisible("checkpointThird")==1 && dIsPointInSprite("checkpointThird",fMouseX,fMouseY)){
		tools.ClickChangeScene("checkpointThird","CheckpointThird_one.t2d",fMouseX,fMouseY);
		dStopAllSound();
		SceneState=6;
	}
	if(dIsSpriteVisible("checkpointFourth")==1 && dIsPointInSprite("checkpointFourth",fMouseX,fMouseY)){
		tools.ClickChangeScene("checkpointFourth","CheckpointFourth_one.t2d",fMouseX,fMouseY);
		dStopAllSound();
		SceneState=7;
	}
	if(dIsSpriteVisible("checkpointFifth")==1 && dIsPointInSprite("checkpointFifth",fMouseX,fMouseY)){
		tools.ClickChangeScene("checkpointFifth","CheckpointFifth_one.t2d",fMouseX,fMouseY);
		dStopAllSound();
		SceneState=8;
	}
	if(dIsSpriteVisible("checkpointSixth")==1 && dIsPointInSprite("checkpointSixth",fMouseX,fMouseY)){
		tools.ClickChangeScene("checkpointSixth","CheckpointSixth_one.t2d",fMouseX,fMouseY);
		dStopAllSound();
		SceneState=9;
	}
	if(dIsSpriteVisible("checkpointSeventh")==1 && dIsPointInSprite("checkpointSeventh",fMouseX,fMouseY)){
		tools.ClickChangeScene("checkpointSeventh","CheckpointSeventh_one.t2d",fMouseX,fMouseY);
		dStopAllSound();
		SceneState=10;
	}

	
}

void Scene01::MouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    clicks=0;
}

void Scene01::KeyDown(const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress){}

void Scene01::KeyUp(const int iKey){}

void Scene01::SpriteColSprite(const char *szSrcName, const char *szTarName){}