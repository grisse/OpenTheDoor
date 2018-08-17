#include "Tools.h"


int clicks=0;   //点击次数
int SceneState=0;
bool gameVoice=1;

Tools::Tools(){}
Tools::~Tools(){}

//精灵变大函数，注意Pass参数
void Tools::BiggerSprite(bool pass, const char *szName, const float fMouseX, const float fMouseY){
	if(dIsPointInSprite(szName,fMouseX,fMouseY)&&pass==1){
        dSetSpriteScale(szName,1.1f);
    }else{
        dSetSpriteScale(szName,1);
    }
}

//szName1：精灵名字
//szName2：场景名字。即新建场景保存的时候取的名字，必须带小写的后缀 -- xxx.t2d。不用带路径
void Tools::ClickChangeScene(const char *szName1, const char *szName2, const float fMouseX, const float fMouseY){
	if(clicks==1 && dIsPointInSprite(szName1,fMouseX,fMouseY)){
		dLoadMap(szName2);
		clicks=0;
	}
}

void Tools::ShowItems(const bool mark, const char *szName1, const char *szName2,const int sz1,const int sz2){
	if(mark){
		dSetSpriteVisible(szName1,sz1);
		dSetSpriteVisible(szName2,sz2);
	}
}
void Tools::ShowItems(const bool mark, const char *szName1, const char *szName2, const char *szName3,const int sz1,const int sz2,const int sz3){
	if(mark){
		dSetSpriteVisible(szName1,sz1);
		dSetSpriteVisible(szName2,sz2);
		dSetSpriteVisible(szName3,sz3);
	}
}
//
void Tools::ShowSprite(const char *szName, const float fMouseX, const float fMouseY){
	if(dIsPointInSprite(szName,fMouseX,fMouseY)){
		dSetSpriteVisible(szName,1);
	}else{
		dSetSpriteVisible(szName,1);
	}
}


void Tools::SpriteReturnItembar(bool &clickyes , const char *szName, const float fPosX, const float fPosY,const float fSpeed){
	if(clickyes){
		dSpriteMoveTo(szName,fPosX,fPosY,fSpeed,1);
		dShowCursor(1);
		clickyes=false;
	}
}


bool Tools::SpriteMoveTo(bool &clickyes, const char *szName, const char *szName2,  const float fMouseX, const float fMouseY,float fSpeed){
	if(clickyes){
		dShowCursor(0);
		dSpriteMoveTo(szName,fMouseX,fMouseY,fSpeed,1);
		if(dIsPointInSprite(szName2,fMouseX,fMouseY))
			return true;
	}
	return false;
}

void Tools::PlaySound(const int &soundId , const char *szName,  const int iLoop, const float fVolume){
	dStopSound(soundId);
	dPlaySound(szName,iLoop,fVolume);
}
void Tools::Setting(const float fMouseX,const float fMouseY){
	if(clicks && dIsPointInSprite("setting",fMouseX,fMouseY)){
		if(gameVoice) dSetSpriteVisible("gameVoice1",1);
		dSetSpriteVisible("guanNumber",1);
		this->ShowItems(1,"settingBackground","diXguan","setJixuButton",1,1,1);
		this->ShowItems(1,"setRestartButton","setXuanzeButton","setQuitButton",1,1,1);
	}
}
void Tools::SetJixuButton(const float fMouseX,const float fMouseY){
	if(clicks && dIsSpriteVisible("setJixuButton") && dIsPointInSprite("setJixuButton",fMouseX,fMouseY)){
		//dSetSpriteVisible("guanNumber",0);
		this->ShowItems(1,"guanNumber","gameVoice1",0,0);
		this->ShowItems(1,"settingBackground","diXguan","setJixuButton",0,0,0);
		this->ShowItems(1,"setRestartButton","setXuanzeButton","setQuitButton",0,0,0);	
	}
}
bool Tools::SetQuitButton(const char *szName,const char *scene,const int state,const float fMouseX,const float fMouseY){
	if(dIsSpriteVisible(szName) && dIsPointInSprite(szName,fMouseX,fMouseY)){
		dLoadMap(scene);
		dStopAllSound();
		SceneState=state;
		return true;
	}
	return false;
}

void Tools::SetGameVoice(const float fMouseX,const float fMouseY){
	if(dIsSpriteVisible("settingBackground") && dIsPointInSprite("gameVoice1",fMouseX,fMouseY)){
		if(gameVoice){
			gameVoice=0;
			dStopAllSound();
			dSetSpriteVisible("gameVoice1",0);
		}else{
			gameVoice=1;
			dSetSpriteVisible("gameVoice1",1);
		}
	}
}