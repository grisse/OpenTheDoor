#include "Scene6.h"


Scene6::Scene6() { 
  init();
}

Scene6::~Scene6() { }

void Scene6::init(){
	clickSixthPipe=0;
	clickSixthTobaccoBag=0;
	clickSixthGuai=0;
	clickSixthChord=0;
	clickSmallSixthPipe=0;
	clickSmallSixthTobaccoBag=0;
	clickSmallSixthGuai=0;
	clickSmallSixthChord=0;
	sixthPipeAndTobaccoYes=0;
	sixthGuaiAndChord=0;
	clickSmallSixthPipeAndTobacco=0;
	clickSmallSixthGuaiAndChord=0;
	sixthPipeHuoYes=0;
	sixDoorKeyYes=0;
	clickSmallSixthPipeHuo=0;
	sixthMirrorOpenYes=0;
	pwd1=0;pwd2=0;pwd3=0;pwd4=0;
	openSixthPwdboxYes=0;
	clickSixthWindowKey=0;
	sixthWindowOpenYes=0;
	clickSmallSixthWindowKey=0;
	clickSmallSixthDoorKey=0;
	sixthDoorOpenYes=0;

}
void Scene6::GameMainLoop(float fTimeDelta){
	
	//改背景音乐
	if(gameVoice){
		dPlaySound("Music.wav",1,0.5);
	}
	
	if(rubySixthYes) dDeleteSprite("ruby");

	tools.ShowItems(clickSixthPipe,"sixthPipe","smallSixthPipe",0,1);
	tools.ShowItems(clickSixthTobaccoBag,"sixthTobaccoBag","smallSixthTobaccoBag",0,1);
	tools.ShowItems(clickSixthGuai,"sixthGuai","smallsixthGuai",0,1);
	tools.ShowItems(clickSixthChord,"sixthChord","smallSixthChord",0,1);
	
	tools.ShowItems(sixthPipeAndTobaccoYes,"smallSixthPipe","smallSixthTobaccoBag","smallSixthPipeAndTobacco",0,0,1);
	tools.ShowItems(sixthPipeHuoYes,"smallSixthPipeAndTobacco","smallSixthPipeHuo",0,1);
	tools.ShowItems(sixthMirrorOpenYes,"smallSixthPipeHuo","sixthMirrorOpen","sixthMirrorOpen2",0,1,1);
	tools.ShowItems(sixthGuaiAndChord,"smallsixthGuai","smallSixthChord","smallSixthGuaiAndChord",0,0,1);

	//密码部分
	dSetTextValue("sixthPwd1",pwd1);
    dSetTextValue("sixthPwd2",pwd2);
    dSetTextValue("sixthPwd3",pwd3);
	dSetTextValue("sixthPwd4",pwd4);
	if(pwd1==2 && pwd2==9 && pwd3==1 && pwd4==4){
		openSixthPwdboxYes=1;
	}

	tools.ShowItems(openSixthPwdboxYes,"sixthPwdboxOpen","sixthWindowKey",1,1);
	tools.ShowItems(clickSixthWindowKey,"sixthWindowKey","smallSixthWindowKey",0,1);
	tools.ShowItems(sixthWindowOpenYes,"smallSixthWindowKey","sixthWindowOpen",0,1);
	tools.ShowItems(sixDoorKeyYes,"smallSixthGuaiAndChord","sixthDoorKey","smallSixthDoorKey",0,0,1);

	tools.ShowItems(sixthDoorOpenYes,"smallSixthDoorKey","sixthDoorOpen",0,1);


}

void Scene6::MouseMove(const float fMouseX, const float fMouseY){
	tools.BiggerSprite(1,"sixthBackButton",fMouseX,fMouseY);
	
	if(tools.SpriteMoveTo(clickSmallSixthPipe,"smallSixthPipe","smallSixthTobaccoBag",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallSixthTobaccoBag")){
		sixthPipeAndTobaccoYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthTobaccoBag,"smallSixthTobaccoBag","smallSixthPipe",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallSixthPipe")){
		sixthPipeAndTobaccoYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthGuai,"smallSixthGuai","smallSixthChord",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallSixthChord")){
		sixthGuaiAndChord=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthChord,"smallSixthChord","smallSixthGuai",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallSixthGuai")){
		sixthGuaiAndChord=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthPipeAndTobacco,"smallSixthPipeAndTobacco","sixthHuo",fMouseX,fMouseY,100000)){
		sixthPipeHuoYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthGuaiAndChord,"smallSixthGuaiAndChord","sixthDoorKey",fMouseX,fMouseY,100000)){
		sixDoorKeyYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthPipeHuo,"smallSixthPipeHuo","sixthMirrorOpen",fMouseX,fMouseY,100000)){
		sixthMirrorOpenYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthWindowKey,"smallSixthWindowKey","sixthWindowTrigger",fMouseX,fMouseY,100000)){
		sixthWindowOpenYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSixthDoorKey,"smallSixthDoorKey","sixthDoorTrigger",fMouseX,fMouseY,100000)){
		sixthDoorOpenYes=1;
	}

}

void Scene6::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){

	clicks=1;
	tools.ClickChangeScene("sixthBackButton","CheckpointSixth_one.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("sixthBackButton7","CheckpointSixth_sixwindow.t2d",fMouseX,fMouseY);

	tools.ClickChangeScene("clickareaSixthBook","CheckpointSixth_twoBook.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSixthStove","CheckpointSixth_threeStove.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSixthMirror","CheckpointSixth_fourMirror.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSixthPwdbox","CheckpointSixth_fivePwdbox.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSixthWindow","CheckpointSixth_sixwindow.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSixthDoor","CheckpointSixth_eightDoor.t2d",fMouseX,fMouseY);
	if(dIsSpriteVisible("sixthWindowOpen"))  tools.ClickChangeScene("sixthWindowOpen","CheckpointSixth_sevenChuanwai.t2d",fMouseX,fMouseY);

	if(dIsPointInSprite("sixthPipe",fMouseX,fMouseY)){
		clickSixthPipe=1;
	}
	if(dIsPointInSprite("sixthTobaccoBag",fMouseX,fMouseY)){
		clickSixthTobaccoBag=1;
	}
	if(dIsPointInSprite("sixthGuai",fMouseX,fMouseY)){
		clickSixthGuai=1;
	}
	if(dIsPointInSprite("sixthChord",fMouseX,fMouseY)){
		clickSixthChord=1;
	}

	if(dIsSpriteVisible("smallSixthPipe") && dIsPointInSprite("smallSixthPipe",fMouseX,fMouseY) ){
		clickSmallSixthPipe=1;
	}
	if(dIsSpriteVisible("smallSixthTobaccoBag") && dIsPointInSprite("smallSixthTobaccoBag",fMouseX,fMouseY) ){
		clickSmallSixthTobaccoBag=1;
	}
	if(dIsSpriteVisible("smallSixthGuai") && dIsPointInSprite("smallSixthGuai",fMouseX,fMouseY) ){
		clickSmallSixthGuai=1;
	}
	if(dIsSpriteVisible("smallSixthChord") && dIsPointInSprite("smallSixthChord",fMouseX,fMouseY) ){
		clickSmallSixthChord=1;
	}
	if(dIsSpriteVisible("smallSixthPipeAndTobacco") && dIsPointInSprite("smallSixthPipeAndTobacco",fMouseX,fMouseY)){
		clickSmallSixthPipeAndTobacco=1;
	}
	if(dIsSpriteVisible("smallSixthGuaiAndChord") && dIsPointInSprite("smallSixthGuaiAndChord",fMouseX,fMouseY)){
		clickSmallSixthGuaiAndChord=1;
	}
	if(dIsSpriteVisible("smallSixthPipeHuo") && dIsPointInSprite("smallSixthPipeHuo",fMouseX,fMouseY)){
		clickSmallSixthPipeHuo=1;
	}
	if(dIsSpriteVisible("sixthWindowKey") && dIsPointInSprite("sixthWindowKey",fMouseX,fMouseY)){
		clickSixthWindowKey=1;
	}
	if(dIsSpriteVisible("smallSixthWindowKey") && dIsPointInSprite("smallSixthWindowKey",fMouseX,fMouseY)){
		clickSmallSixthWindowKey=1;
	}
	if(dIsSpriteVisible("smallSixthDoorKey") && dIsPointInSprite("smallSixthDoorKey",fMouseX,fMouseY)){
		clickSmallSixthDoorKey=1;
	}

		//密码部分
	if(dIsPointInSprite("sixthPwd1",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(pwd1<9)
			pwd1++;
		else
			pwd1=0;
	}
	if(dIsPointInSprite("sixthPwd2",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(pwd2<9)
			pwd2++;
		else
			pwd2=0;		
	}
	if(dIsPointInSprite("sixthPwd3",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(pwd3<9)
			pwd3++;
		else
			pwd3=0;
	}
	if(dIsPointInSprite("sixthPwd4",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(pwd4<9)
			pwd4++;
		else
			pwd4=0;
	}
	if(!rubySixthYes && dIsPointInSprite("ruby",fMouseX,fMouseY)){
		rubyCount++;
		rubySixthYes=1;
	}

	//过关
	if(dIsSpriteVisible("sixthDoorOpen") && dIsPointInSprite("sixthDoorOpen",fMouseX,fMouseY)){
		checkpointSixthpass=1;
		init();
		dLoadMap("checkpoint.t2d");
		dStopAllSound();
		SceneState=1;
	}

	
}

void Scene6::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;

	tools.SpriteReturnItembar(clickSmallSixthPipe,"smallSixthPipe",7.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthTobaccoBag,"smallSixthTobaccoBag",34.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthGuai,"smallSixthGuai",-51.f,44.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthChord,"smallSixthChord",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthPipeAndTobacco,"smallSixthPipeAndTobacco",7.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthGuaiAndChord,"smallSixthGuaiAndChord",-51.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthPipeHuo,"smallSixthPipeHuo",7.f,38.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthWindowKey,"smallSixthWindowKey",6.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSixthDoorKey,"smallSixthDoorKey",-51.f,41.f,1000.f);


}

void Scene6::KeyDown(const int iKey, const int bAltPress, const int bShiftPress, const int bCtrlPress){}

void Scene6::KeyUp( const int iKey ){}

void Scene6::SpriteColSprite(const char *szSrcName, const char *szTarName){}