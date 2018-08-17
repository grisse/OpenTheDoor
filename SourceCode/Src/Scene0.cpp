#include "Scene0.h"


Scene0::Scene0(){}
Scene0::~Scene0(){}

void Scene0::GameMainLoop(float fTimeDelta)
{
	openingSound = dPlaySound("Music.wav",1,0.5);
}

void Scene0::MouseMove(const float fMouseX, const float fMouseY){
	tools.BiggerSprite(1,"StartGameButton",fMouseX,fMouseY);
	tools.BiggerSprite(1,"ContinueGameButton",fMouseX,fMouseY);
	tools.BiggerSprite(1,"GamePlotButton",fMouseX,fMouseY);
	tools.BiggerSprite(1,"GamePlayButton",fMouseX,fMouseY);
}

void Scene0::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
	clicks=1;
	if(dIsPointInSprite("StartGameButton",fMouseX,fMouseY)){
		//开始按钮按下后显示关卡选择界面
		tools.ClickChangeScene("StartGameButton","checkpoint.t2d",fMouseX,fMouseY);
		checkpointFirstpass=0;
		checkpointSecondpass=0;
		checkpointThirdpass=0;
		checkpointFourthpass=0;
		checkpointFifthpass=0;
		checkpointSixthpass=0;
		checkpointSeventhpass=0;
		SceneState=1;
	}
	if(dIsPointInSprite("ContinueGameButton",fMouseX,fMouseY)){
		//继续游戏按钮
		tools.ClickChangeScene("ContinueGameButton","checkpoint.t2d",fMouseX,fMouseY);
        SceneState=1;
	}
	if(dIsPointInSprite("GamePlotButton",fMouseX,fMouseY)){
		//游戏背景按钮
		tools.ClickChangeScene("GamePlotButton","GamePlot.t2d",fMouseX,fMouseY);
        SceneState=2;
	}
	if(dIsPointInSprite("GamePlayButton",fMouseX,fMouseY)){
		//游戏玩法按钮
		tools.ClickChangeScene("GamePlayButton","GamePlay.t2d",fMouseX,fMouseY);
        SceneState=3;
	}
}

void Scene0::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;
}

void Scene0::KeyDown(const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress){}

void Scene0::KeyUp(const int iKey){}

void Scene0::SpriteColSprite(const char *szSrcName, const char *szTarName){}