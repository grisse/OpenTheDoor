#include "Scene3.h"

Scene3::Scene3() {
	init();
}

Scene3::~Scene3() {}

void Scene3::init(){
	clickThirdKnife=0;
	clickThirdWrench=0;
	clickThirdShovel=0;
	clickRedValveMake=0;
	clickGreenValveMake=0;
	clickBlueValveMake=0;
	clickOrangeValveMake=0;
	clickSmallThirdKnife=0;
	clickSmallThirdShovel=0;
	clickSmallThirdWrench=0;
	openBagYes=0;
	carbonAndShovelYes=0;
	OpenLuziYes=0;
	clickSmallShovelCarbon=0;
	clickSmallThirdTiegan=0;
	clickThirdTiegan=0;
	openThirdDoorYes=0;
	clickOrangeGuanzi=0;
	clickBlueGuanzi=0;
	changeGuanziYes=0;
}

void Scene3::GameMainLoop(float fTimeDelta){
	//∏ƒ±≥æ∞“Ù¿÷
	if(gameVoice){
		dPlaySound("Music.wav",1,0.5);
	}

	if(rubyThirdYes) dDeleteSprite("ruby");

	tools.ShowItems(clickThirdKnife,"thirdKnife","smallThirdKnife",0,1);
	tools.ShowItems(clickThirdWrench,"thirdWrench","smallThirdWrench",0,1);
	tools.ShowItems(clickThirdShovel,"thirdShovel1","thirdShovel2","smallThirdShovel",0,0,1);
	tools.ShowItems(clickThirdTiegan,"thirdTiegan","smallThirdTiegan",0,1);
	tools.ShowItems(openBagYes,"thirdGoodBag","smallThirdKnife","thirdCarbon",0,0,1);
	tools.ShowItems(carbonAndShovelYes,"thirdCarbon","smallThirdShovel","smallShovelCarbon",0,0,1);

	if(OpenLuziYes){
		dDeleteSprite("clickareaThirdfour");
		dSetSpriteVisible("thirdLuziOpen",1);
	}
	tools.ShowItems(openThirdDoorYes,"smallThirdTiegan","thirdQiangOpen",0,0);
	tools.ShowItems(changeGuanziYes,"smallThirdWrench","thirdBackButton3",0,0);

	if(changeGuanziYes && clickOrangeGuanzi && clickBlueGuanzi){
		dSpriteMoveTo("blueGuanzi",7.5,-6.0,1000.0,1);
		dSpriteMoveTo("orangeGuanzi",-29.0,-6.0,1000.0,1);
		dSetSpriteVisible("thirdBackButton3",1);
	}

	//if(!clickRedValveMake) dSetSpriteVisible("redValveUp",1);
	//if(!clickGreenValveMake) dSetSpriteVisible("greenValveRight",1);
	//if(!clickOrangeValveMake) dSetSpriteVisible("orangeValveRight",1);
	//if(!clickBlueValveMake) dSetSpriteVisible("blueValveDown",1);
	//clickRedValveMake==1 && clickGreenValveMake==1 && clickOrangeValveMake==2 && clickBlueValveMake==1
	


}

void Scene3::MouseMove(const float fMouseX, const float fMouseY){

	tools.BiggerSprite(1,"thirdBackButton",fMouseX,fMouseY);
	tools.BiggerSprite(1,"thirdBackButton5",fMouseX,fMouseY);
	tools.BiggerSprite(1,"thirdBackButton3",fMouseX,fMouseY);

	if(tools.SpriteMoveTo(clickSmallThirdKnife,"smallThirdKnife","thirdGoodBag",fMouseX,fMouseY,100000)){
		openBagYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallThirdShovel,"smallThirdShovel","thirdCarbon",fMouseX,fMouseY,100000) && dIsSpriteVisible("thirdCarbon")){
		carbonAndShovelYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallThirdTiegan,"smallThirdTiegan","thirdQiangOpen",fMouseX,fMouseY,100000)){
		openThirdDoorYes=1;
	}

	if(clickSmallShovelCarbon){
		dShowCursor(0);
		dSpriteMoveTo("smallShovelCarbon",fMouseX,fMouseY,100000,1);
		if(dIsPointInSprite("thirdLuziTrigger",fMouseX,fMouseY)){
			dLoadMap("CheckpointThird_seven.t2d");
		}
	}
	if(clickSmallThirdWrench){
		dShowCursor(0);
		dSpriteMoveTo("smallThirdWrench",fMouseX,fMouseY,100000,1);
		if(dIsPointInSprite("orangeGuanzi",fMouseX,fMouseY) || dIsPointInSprite("blueGuanzi",fMouseX,fMouseY)){
			changeGuanziYes=1;
		}
	}
	
	if(dIsSpriteVisible("redValveLeft") && dIsSpriteVisible("greenValveDown") && dIsSpriteVisible("orangeValveRight") && dIsSpriteVisible("blueValveRight") 
		&&(dIsPointInSprite("redValveLeft",fMouseX,fMouseY) || dIsPointInSprite("greenValveLeft",fMouseX,fMouseY) || dIsPointInSprite("orangeValveLeft",fMouseX,fMouseY) || dIsPointInSprite("blueValveLeft",fMouseX,fMouseY))){
			OpenLuziYes=1;
			dLoadMap("CheckpointThird_openLuzi.t2d");
	}
}

void Scene3::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=1;

	tools.ClickChangeScene("thirdBackButton","CheckpointThird_one.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("thirdBackButton5","CheckpointThird_four.t2d",fMouseX,fMouseY);
	if(dIsSpriteVisible("thirdBackButton3")) tools.ClickChangeScene("thirdBackButton3","CheckpointThird_one.t2d",fMouseX,fMouseY);

	tools.ClickChangeScene("clickareaThirdtwo","CheckpointThird_two.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaThirdthree","CheckpointThird_three.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaThirdfour","CheckpointThird_four.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaThirdfive","CheckpointThird_five.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaThirdsix","CheckpointThird_six.t2d",fMouseX,fMouseY);

	if(dIsSpriteVisible("thirdLuziOpen")) tools.ClickChangeScene("thirdLuziOpen","CheckpointThird_openLuzi.t2d",fMouseX,fMouseY);
	
	if(!rubyThirdYes && dIsPointInSprite("ruby",fMouseX,fMouseY)){
		rubyCount++;
		rubyThirdYes=1;
	}

	if(dIsSpriteVisible("thirdKnife") && dIsPointInSprite("thirdKnife",fMouseX,fMouseY)){
		clickThirdKnife=1;
	}
	if(dIsSpriteVisible("thirdWrench") && dIsPointInSprite("thirdWrench",fMouseX,fMouseY)){
		clickThirdWrench=1;  
	}
	if(dIsSpriteVisible("thirdShovel2") && dIsPointInSprite("thirdShovel2",fMouseX,fMouseY)){
		clickThirdShovel=1;  
	}
	if(dIsPointInSprite("thirdTiegan",fMouseX,fMouseY)){
		clickThirdTiegan=1;
	}

	if(dIsSpriteVisible("smallThirdKnife") && dIsPointInSprite("smallThirdKnife",fMouseX,fMouseY)){
		clickSmallThirdKnife=1;
	}
	if(dIsSpriteVisible("smallThirdShovel") && dIsPointInSprite("smallThirdShovel",fMouseX,fMouseY)){
		clickSmallThirdShovel=1;
	}
	if(dIsSpriteVisible("smallThirdWrench") && dIsPointInSprite("smallThirdWrench",fMouseX,fMouseY)){
		clickSmallThirdWrench=1;
	}
	if(dIsSpriteVisible("smallShovelCarbon") && dIsPointInSprite("smallShovelCarbon",fMouseX,fMouseY)){
		clickSmallShovelCarbon=1;
	}

	if(dIsSpriteVisible("smallThirdTiegan") && dIsPointInSprite("smallThirdTiegan",fMouseX,fMouseY)){
		clickSmallThirdTiegan=1;
	}

	if(changeGuanziYes && dIsPointInSprite("orangeGuanzi",fMouseX,fMouseY)){
		clickOrangeGuanzi=1;
	}
	if(changeGuanziYes && dIsPointInSprite("blueGuanzi",fMouseX,fMouseY)){
		clickBlueGuanzi=1;
	}


	if(dIsPointInSprite("redValveUp",fMouseX,fMouseY)){
		dStopSound(stopBLIP);
		dPlaySound("valve.ogg",0,1);
		clickRedValveMake++;
		if(clickRedValveMake==1){
			dSetSpriteVisible("redValveUp",0);
			dSetSpriteVisible("redValveRight",1);
		}
		else if(clickRedValveMake==2){
			dSetSpriteVisible("redValveRight",0);
			dSetSpriteVisible("redValveDown",1);
		}
		else if(clickRedValveMake==3){
			dSetSpriteVisible("redValveDown",0);
			dSetSpriteVisible("redValveLeft",1);
		}else{
			dSetSpriteVisible("redValveLeft",0);
			dSetSpriteVisible("redValveUp",1);
			clickRedValveMake=0;
		}

	}

	if(dIsPointInSprite("greenValveRight",fMouseX,fMouseY)){
		dStopSound(stopBLIP);
		dPlaySound("valve.ogg",0,1);
		clickGreenValveMake++;
		if(clickGreenValveMake==1){
			dSetSpriteVisible("greenValveRight",0);
			dSetSpriteVisible("greenValveDown",1);
		}
		else if(clickGreenValveMake==2){
			dSetSpriteVisible("greenValveDown",0);
			dSetSpriteVisible("greenValveLeft",1);
		}
		else if(clickGreenValveMake==3){
			dSetSpriteVisible("greenValveLeft",0);
			dSetSpriteVisible("greenValveUp",1);
		}else{
			dSetSpriteVisible("greenValveUp",0);
			dSetSpriteVisible("greenValveRight",1);
			clickGreenValveMake=0;
		}
	}
	if(dIsPointInSprite("orangeValveRight",fMouseX,fMouseY)){
		dStopSound(stopBLIP);
		dPlaySound("valve.ogg",0,1);
		clickOrangeValveMake++;
		if(clickOrangeValveMake==1){
			dSetSpriteVisible("orangeValveRight",0);
			dSetSpriteVisible("orangeValveDown",1);
		}
		else if(clickOrangeValveMake==2){
			dSetSpriteVisible("orangeValveDown",0);
			dSetSpriteVisible("orangeValveLeft",1);
		}
		else if(clickOrangeValveMake==3){
			dSetSpriteVisible("orangeValveLeft",0);
			dSetSpriteVisible("orangeValveUp",1);
		}else{
			dSetSpriteVisible("orangeValveUp",0);
			dSetSpriteVisible("orangeValveRight",1);
			clickOrangeValveMake=0;
		}
	}
	if(dIsPointInSprite("blueValveDown",fMouseX,fMouseY)){
		dStopSound(stopBLIP);
		dPlaySound("valve.ogg",0,1);
		clickBlueValveMake++;
		if(clickBlueValveMake==1){
			dSetSpriteVisible("blueValveDown",0);
			dSetSpriteVisible("blueValveLeft",1);
		}
		else if(clickBlueValveMake==2){
			dSetSpriteVisible("blueValveLeft",0);
			dSetSpriteVisible("blueValveUp",1);
		}
		else if(clickBlueValveMake==3){
			dSetSpriteVisible("blueValveUp",0);
			dSetSpriteVisible("blueValveRight",1);
		}else{
			dSetSpriteVisible("blueValveRight",0);
			dSetSpriteVisible("blueValveDown",1);
			clickBlueValveMake=0;
		}
	}

	//Ω· ¯
	if(dIsSpriteVisible("thirdQiangOpen")==0 && dIsPointInSprite("thirdQiangOpen",fMouseX,fMouseY)){
		checkpointThirdpass=1;
		init();


		dLoadMap("checkpoint.t2d");
		dStopAllSound();
		SceneState=1;
	}

} 

void Scene3::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;

	tools.SpriteReturnItembar(clickSmallThirdKnife,"smallThirdKnife",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallThirdShovel,"smallThirdShovel",-50.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallShovelCarbon,"smallShovelCarbon",-52.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallThirdTiegan,"smallThirdTiegan",-50.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallThirdWrench,"smallThirdWrench",6.f,41.f,1000.f);
}

void Scene3::KeyDown(const int iKey, const int bAltPress, const int bShiftPress, const int bCtrlPress){}

void Scene3::KeyUp( const int iKey ){}

void Scene3::SpriteColSprite(const char *szSrcName, const char *szTarName){}