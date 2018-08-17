#include "Scene5.h"

Scene5::Scene5() {
	init();
}

Scene5::~Scene5() {}

void Scene5::init(){
	clickSmallFifthCheese=0;
	clickFifthCheese=0;
	clickFifthCheesedIsPointInSprite=0;
	clickFifthScissors=0;
	clickFifthBowl=0;
	showSmallFifthChefKeyYes=0;
	openFifthBagYes=0;
	clickSmallFifthScissors=0;
	clickSmallFifthBowl=0;
	clickFifthCup=0;
	clickFifthCanzi=0;
	clickFifthCazi=0;
	clickSmallFifthChefKey=0;
	openFifthChefYes=0;
	clickSmallFifthCanzi=0;
	clickSmallFifthCazi=0;
	openFifthDrawerYes=0;
	clickFifthSword=0;
	clickSmallFifthSword=0;
	openFifthBreadYes=0;
	clickSmallFifthCup=0;
	fifthChefWanYes=0;
	clickFifthBigbowl=0;
	clickSmallFifthBigbowl=0;
	fifthCanziAndBigbowl=0;
	clickFifthCanziAndBigbowl=0;
	fifthCanziAndBBowlYes=0;
	fifthBBowlCoverYes=0;
	clickFifthDoorKey=0;
	clickSmallFifthDoorKey=0;
	openFifthDoorYes=0;
}
void Scene5::GameMainLoop(float fTimeDelta){
	if(gameVoice){
		dPlaySound("Music.wav",1,0.5);
	}
	if(rubyFifthYes) dDeleteSprite("ruby");

	tools.ShowItems(clickFifthCheese,"fifthCheese","smallFifthCheese",0,1);
	tools.ShowItems(clickFifthCup,"fifthCup","smallFifthCup",0,1);
	tools.ShowItems(clickFifthScissors,"fifthScissors","smallFifthScissors",0,1);
	tools.ShowItems(clickFifthBowl,"fifthBowl","smallFifthBowl",0,1);
	tools.ShowItems(showSmallFifthChefKeyYes,"smallFifthBowl","smallFifthChefKey",0,1);
	tools.ShowItems(clickFifthCanzi,"fifthCanzi","smallFifthCanzi",0,1);
	tools.ShowItems(clickFifthCazi,"fifthCazi","smallFifthCazi",0,1);
	tools.ShowItems(openFifthChefYes,"smallFifthChefKey","fifthChefOpen",0,1);
	tools.ShowItems(fifthChefWanYes,"smallFifthCup","fifthChefWan",0,1);

	tools.ShowItems(clickFifthDoorKey,"fifthDoorKey","smallFifthDoorKey",0,1);
	tools.ShowItems(openFifthDoorYes,"smallFifthDoorKey","fifthDoorOpen",0,1);
	tools.ShowItems(openFifthBagYes,"smallFifthScissors","fifGoodBag",0,0);
	tools.ShowItems(openFifthDrawerYes,"smallFifthCazi","fifthDrawer","fifthSword",0,1,1);
	
	tools.ShowItems(clickFifthSword,"fifthSword","smallFifthSword",0,1);
	tools.ShowItems(openFifthBreadYes,"smallFifthSword","fifthBread",0,0);
	tools.ShowItems(fifthChefWanYes,"fifthChefDong","fifthBigbowl",1,1);

	tools.ShowItems(clickFifthBigbowl,"fifthBigbowl","smallFifthBigbowl",0,1);
	tools.ShowItems(fifthCanziAndBigbowl,"smallFifthCanzi","smallFifthBigbowl","fifthCanziAndBigbowl",0,0,1);

	tools.ShowItems(fifthCanziAndBBowlYes,"fifthCanziAndBigbowl","fifthCanziAndBBowl",0,1);

	if(fifthBBowlCoverYes){
		dSetSpriteVisible("fifthCanziAndBBowl",0);
		dSetSpriteVisible("fifthMouse",0);
		dSetSpriteVisible("smallFifthCheese",0);
		dSetSpriteVisible("fifthBBowlCover",1);
	}

}

void Scene5::MouseMove(const float fMouseX, const float fMouseY){
	tools.BiggerSprite(1,"fifthBackButton",fMouseX,fMouseY);

	if(tools.SpriteMoveTo(clickSmallFifthCheese,"smallFifthCheese","fifthCanziAndBBowl",fMouseX,fMouseY,100000) && dIsSpriteVisible("fifthCanziAndBBowl")){
		fifthBBowlCoverYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthScissors,"smallFifthScissors","fifGoodBag",fMouseX,fMouseY,100000)){
		openFifthBagYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthBowl,"smallFifthBowl","fifGoodBag",fMouseX,fMouseY,100000) && !dIsSpriteVisible("fifGoodBag")){
		showSmallFifthChefKeyYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthChefKey,"smallFifthChefKey","fifthChefTrigger",fMouseX,fMouseY,100000)){
		openFifthChefYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthCanzi,"smallFifthCanzi","smallFifthBigbowl",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallFifthBigbowl")){
		fifthCanziAndBigbowl=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthCazi,"smallFifthCazi","fifthDrawerTrigger",fMouseX,fMouseY,100000) ){
		openFifthDrawerYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthSword,"smallFifthSword","fifthBread",fMouseX,fMouseY,100000) ){
		openFifthBreadYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthCup,"smallFifthCup","fifthChefWan",fMouseX,fMouseY,100000) ){
		fifthChefWanYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthBigbowl,"smallFifthBigbowl","smallFifthCanzi",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallFifthCanzi")){
		fifthChefWanYes=1;
	}
	if(tools.SpriteMoveTo(clickFifthCanziAndBigbowl,"fifthCanziAndBigbowl","fifthEight",fMouseX,fMouseY,100000) ){
		fifthCanziAndBBowlYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFifthDoorKey,"smallFifthDoorKey","fifthDoorTrigger",fMouseX,fMouseY,100000) ){
		openFifthDoorYes=1;
	}

}

void Scene5::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=1;
	
	tools.ClickChangeScene("fifthBackButton","CheckpointFifth_one.t2d",fMouseX,fMouseY);

	tools.ClickChangeScene("clickareaFifthTable","CheckpointFifth_twotable.t2d",fMouseX,fMouseY); //桌面
	tools.ClickChangeScene("clickareaFifthDrawer","CheckpointFifth_threedrawer.t2d",fMouseX,fMouseY);//抽屉
	tools.ClickChangeScene("clickareaFifthFour","CheckpointFifth_four.t2d",fMouseX,fMouseY); //放剪刀的
	tools.ClickChangeScene("clickareaFifthfive","CheckpointFifth_five.t2d",fMouseX,fMouseY);  //米袋
	tools.ClickChangeScene("clickareaFifthsix","CheckpointFifth_six.t2d",fMouseX,fMouseY);  //cazi
	tools.ClickChangeScene("clickareaFifthseven","CheckpointFifth_seven.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaFifthEight","CheckpointFifth_eight.t2d",fMouseX,fMouseY); //老鼠洞
	tools.ClickChangeScene("clickareaFifthNine","CheckpointFifth_nine.t2d",fMouseX,fMouseY); //门

	
	if(dIsPointInSprite("fifthCheese",fMouseX,fMouseY)){
		clickFifthCheese=1;
	}
	if(dIsPointInSprite("smallFifthCheese",fMouseX,fMouseY)){
		clickSmallFifthCheese=1;
	}

	if(!dIsSpriteVisible("fifthBread") && dIsPointInSprite("fifthCup",fMouseX,fMouseY)){
		clickFifthCup=1;
	}
	if(dIsPointInSprite("fifthScissors",fMouseX,fMouseY)){
		clickFifthScissors=1;
	}
	if(dIsPointInSprite("fifthBowl",fMouseX,fMouseY)){
		clickFifthBowl=1;
	}
	if(dIsPointInSprite("fifthCanzi",fMouseX,fMouseY)){
		clickFifthCanzi=1;
	}
	if(dIsPointInSprite("fifthCazi",fMouseX,fMouseY)){
		clickFifthCazi=1;
	}
	if(dIsSpriteVisible("fifthSword") && dIsPointInSprite("fifthSword",fMouseX,fMouseY)){
		clickFifthSword=1;
	}

	if(dIsSpriteVisible("smallFifthScissors") && dIsPointInSprite("smallFifthScissors",fMouseX,fMouseY)){
		clickSmallFifthScissors=1;
	}
	if(dIsSpriteVisible("smallFifthBowl") && dIsPointInSprite("smallFifthBowl",fMouseX,fMouseY)){
		clickSmallFifthBowl=1;
	}
	if(dIsSpriteVisible("smallFifthChefKey") && dIsPointInSprite("smallFifthChefKey",fMouseX,fMouseY)){
		clickSmallFifthChefKey=1;
	}
	if(dIsSpriteVisible("smallFifthCanzi") && dIsPointInSprite("smallFifthCanzi",fMouseX,fMouseY)){
		clickSmallFifthCanzi=1;
	}
	if(dIsSpriteVisible("smallFifthCazi") && dIsPointInSprite("smallFifthCazi",fMouseX,fMouseY)){
		clickSmallFifthCazi=1;
	}
	if(dIsSpriteVisible("smallFifthSword") && dIsPointInSprite("smallFifthSword",fMouseX,fMouseY)){
		clickSmallFifthSword=1;
	}
	if(dIsSpriteVisible("smallFifthCup") && dIsPointInSprite("smallFifthCup",fMouseX,fMouseY)){
		clickSmallFifthCup=1;
	}
	if(dIsSpriteVisible("fifthBigbowl") && dIsPointInSprite("fifthBigbowl",fMouseX,fMouseY)){
		clickFifthBigbowl=1;
	}
	if(dIsSpriteVisible("smallFifthBigbowl") && dIsPointInSprite("smallFifthBigbowl",fMouseX,fMouseY)){
		clickSmallFifthBigbowl=1;
	}
	if(dIsSpriteVisible("fifthCanziAndBigbowl") && dIsPointInSprite("fifthCanziAndBigbowl",fMouseX,fMouseY)){
		clickFifthCanziAndBigbowl=1;
	}
	if(!dIsSpriteVisible("fifthMouse") && dIsPointInSprite("fifthDoorKey",fMouseX,fMouseY)){
		clickFifthDoorKey=1;
	}
	if(dIsSpriteVisible("smallFifthDoorKey")&&dIsPointInSprite("smallFifthDoorKey",fMouseX,fMouseY)){
		clickSmallFifthDoorKey=1;
	}

	if(!rubyFifthYes && dIsPointInSprite("ruby",fMouseX,fMouseY)){
		rubyCount++;
		rubyFifthYes=1;
	}

	//过关
	if(dIsSpriteVisible("fifthDoorOpen") && dIsPointInSprite("fifthDoorOpen",fMouseX,fMouseY)){
		checkpointFifthpass=1;
		init();
		dLoadMap("checkpoint.t2d");
		dStopAllSound();
		SceneState=1;
	}
	
}

void Scene5::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;

	tools.SpriteReturnItembar(clickSmallFifthCheese,"smallFifthCheese",-51.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthScissors,"smallFifthScissors",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthBowl,"smallFifthBowl",6.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthChefKey,"smallFifthChefKey",-22.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthCanzi,"smallFifthCanzi",34.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthCazi,"smallFifthCazi",61.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthSword,"smallFifthSword",62.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthCup,"smallFifthCup",61.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthBigbowl,"smallFifthBigbowl",5.5f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthBigbowl,"smallFifthBigbowl",5.5f,41.f,1000.f);
	tools.SpriteReturnItembar(clickFifthCanziAndBigbowl,"fifthCanziAndBigbowl",-22.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFifthDoorKey,"smallFifthDoorKey",-51.f,41.f,1000.f);

}

void Scene5::KeyDown(const int iKey, const int bAltPress, const int bShiftPress, const int bCtrlPress){}

void Scene5::KeyUp( const int iKey ){}

void Scene5::SpriteColSprite(const char *szSrcName, const char *szTarName){}