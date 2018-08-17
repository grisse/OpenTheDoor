#include "Scene4.h"

Scene4::Scene4() {
	init();
}
Scene4::~Scene4() {}

void Scene4::init(){
	clickFourthOildrum=0;
	clickFourthIronhook=0;
	clickFourthWoodenstick=0;
	openFourthJinggai=0;
	fouthTieding1Yes=0;
	fouthTieding2Yes=0;
	clickFourthWoodenboard=0;
	clickSmallFourthOildrum=0;
	clickSmallFourthIronhook=0;
	clickSmallFourthWoodensticlk=0;
	clickSmallFourthWoodenboard=0;
	clickSmallFourthPants=0;
	fourthWoodenboard_PantsYes=0;
	fourthBoard_Pants_oildYes=0;
	clickFourthWoodenboard_Pants=0;
	clickFourthBoard_Pants_oild=0;
	clickFourthPants=0;
	clickSmallFourthTorch=0;
	showFourthFiveLiangYes=0;
	clickFourthKey=0;
	fourthTorchYes=0;
	openFourthDoorYes=0;
}

void Scene4::GameMainLoop(float fTimeDelta){
	//¸Ä±³¾°ÒôÀÖ
	if(gameVoice){
		dPlaySound("Music.wav",1,0.5);
	}

	if(rubyFourthYes) dDeleteSprite("ruby");

	tools.ShowItems(clickFourthOildrum,"fourthOildrum","smallFourthOildrum",0,1);
	tools.ShowItems(clickFourthIronhook,"fourthIronhook","smallFourthIronhook",0,1);
	tools.ShowItems(clickFourthWoodenstick,"fourthWoodenstick","smallFourthWoodensticlk",0,1);
	tools.ShowItems(clickFourthWoodenboard,"fourthWoodenboard","smallFourthWoodenboard",0,1);
	tools.ShowItems(clickFourthPants,"fourthPants","smallFourthPants",0,1);
	tools.ShowItems(openFourthJinggai,"fourthJinggai","fourthJinggaiOpen","smallFourthIronhook",0,1,0);

	if(fouthTieding1Yes){
		dSetSpriteVisible("fouthTieding1",0);
	}
	if(fouthTieding2Yes){
		dSetSpriteVisible("fouthTieding2",0);
	}
	if(fouthTieding1Yes&&fouthTieding2Yes){
		dSetSpriteVisible("smallFourthWoodensticlk",0);
	}
	tools.ShowItems(fourthWoodenboard_PantsYes,"smallFourthWoodenboard","smallFourthPants","smallFourthWoodenboard_Pants",0,0,1);
	tools.ShowItems(fourthBoard_Pants_oildYes,"smallFourthOildrum","smallFourthWoodenboard_Pants","smallFourthBoard_Pants_oild",0,0,1);

	tools.ShowItems(fourthTorchYes,"smallFourthBoard_Pants_oild","smallFourthTorch",0,1);
	if(showFourthFiveLiangYes){
		dSetSpriteVisible("smallFourthTorch",0);
		dSetSpriteVisible("fourthFive_an",0);
		dSetSpriteVisible("fourthFive_liang",1);
		dSetSpriteVisible("fourthKey",1);
	}
	
	tools.ShowItems(clickFourthKey,"fourthKey","smallFourthKey",0,1);
	tools.ShowItems(openFourthDoorYes,"smallFourthKey","fourthdoor",0,1);

}

void Scene4::MouseMove(const float fMouseX, const float fMouseY){

	tools.BiggerSprite(1,"fourthBackButton",fMouseX,fMouseY);

	if(tools.SpriteMoveTo(clickSmallFourthOildrum,"smallFourthOildrum","smallFourthWoodenboard_Pants",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallFourthWoodenboard_Pants")){
		fourthBoard_Pants_oildYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFourthIronhook,"smallFourthIronhook","fourthJinggai",fMouseX,fMouseY,100000)){
		openFourthJinggai=1;
	}
	if(tools.SpriteMoveTo(clickSmallFourthWoodenboard,"smallFourthWoodenboard","smallFourthPants",fMouseX,fMouseY,100000)&& dIsSpriteVisible("smallFourthPants")){
		fourthWoodenboard_PantsYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFourthPants,"smallFourthPants","smallFourthWoodenboard",fMouseX,fMouseY,100000)&& dIsSpriteVisible("smallFourthWoodenboard")){
		fourthWoodenboard_PantsYes=1;
	}
	if(tools.SpriteMoveTo(clickFourthWoodenboard_Pants,"smallFourthWoodenboard_Pants","smallFourthOildrum",fMouseX,fMouseY,100000)&& dIsSpriteVisible("smallFourthOildrum")){
		fourthBoard_Pants_oildYes=1;
	}
	if(tools.SpriteMoveTo(clickFourthBoard_Pants_oild,"smallFourthBoard_Pants_oild","fourthDoorLight",fMouseX,fMouseY,100000)){
		fourthTorchYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFourthTorch,"smallFourthTorch","fourthFive_an",fMouseX,fMouseY,100000)){
		showFourthFiveLiangYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallFourthKey,"smallFourthKey","fourthDoorTrigger",fMouseX,fMouseY,100000)){
		openFourthDoorYes=1;
	}

	if(clickSmallFourthWoodensticlk){
		dShowCursor(0);
		dSpriteMoveTo("smallFourthWoodensticlk",fMouseX,fMouseY,100000,1);
		if(dIsPointInSprite("fouthTieding1",fMouseX,fMouseY)){
			fouthTieding1Yes=1;
		}
		if(dIsPointInSprite("fouthTieding2",fMouseX,fMouseY)){
			fouthTieding2Yes=1;
		}
	}
}

void Scene4::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=1;

	tools.ClickChangeScene("fourthBackButton","CheckpointFourth_one.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaFourthtwo","CheckpointFourth_two.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaFourththree","CheckpointFourth_three.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaFourthfour","CheckpointFourth_four.t2d",fMouseX,fMouseY);
	if(!dIsSpriteVisible("fourthJinggai")) tools.ClickChangeScene("fourthJinggai","CheckpointFourth_five.t2d",fMouseX,fMouseY);

	if(dIsPointInSprite("fourthOildrum",fMouseX,fMouseY)){
		clickFourthOildrum=1;
	}
	if(dIsPointInSprite("fourthIronhook",fMouseX,fMouseY)){
		clickFourthIronhook=1;
	}
	if(dIsPointInSprite("fourthWoodenstick",fMouseX,fMouseY)){
		clickFourthWoodenstick=1;
	}
	if(fouthTieding1Yes && fouthTieding2Yes && dIsPointInSprite("fourthWoodenboard",fMouseX,fMouseY)){
		clickFourthWoodenboard=1;
	}

	if(dIsSpriteVisible("smallFourthOildrum") && dIsPointInSprite("smallFourthOildrum",fMouseX,fMouseY)){
		clickSmallFourthOildrum=1;
	}
	if(dIsSpriteVisible("smallFourthIronhook") && dIsPointInSprite("smallFourthIronhook",fMouseX,fMouseY)){
		clickSmallFourthIronhook=1;
	}
	if(dIsSpriteVisible("smallFourthWoodensticlk") && dIsPointInSprite("smallFourthWoodensticlk",fMouseX,fMouseY)){
		clickSmallFourthWoodensticlk=1;
	}
	if(dIsSpriteVisible("smallFourthWoodenboard") && dIsPointInSprite("smallFourthWoodenboard",fMouseX,fMouseY)){
		clickSmallFourthWoodenboard=1;
	}
	if(dIsSpriteVisible("smallFourthPants") && dIsPointInSprite("smallFourthPants",fMouseX,fMouseY)){
		clickSmallFourthPants=1;
	}
	if(dIsSpriteVisible("smallFourthWoodenboard_Pants") && dIsPointInSprite("smallFourthWoodenboard_Pants",fMouseX,fMouseY)){
		clickFourthWoodenboard_Pants=1;
	}
	if(dIsSpriteVisible("smallFourthBoard_Pants_oild") && dIsPointInSprite("smallFourthBoard_Pants_oild",fMouseX,fMouseY)){
		clickFourthBoard_Pants_oild=1;
	}
	if(dIsPointInSprite("fourthPants",fMouseX,fMouseY)){
		clickFourthPants=1;
	}
	if(dIsSpriteVisible("smallFourthTorch") && dIsPointInSprite("smallFourthTorch",fMouseX,fMouseY)){
		clickSmallFourthTorch=1;
	}
	if(dIsSpriteVisible("fourthKey") && dIsPointInSprite("fourthKey",fMouseX,fMouseY) ){
		clickFourthKey=1;
	}
	if(dIsSpriteVisible("smallFourthKey") && dIsPointInSprite("smallFourthKey",fMouseX,fMouseY)){
		clickSmallFourthKey=1;
	}
	if(!rubyFourthYes && dIsPointInSprite("ruby",fMouseX,fMouseY)){
		rubyCount++;
		rubyFourthYes=1;
	}

	//¹ý¹Ø
	if(dIsSpriteVisible("fourthdoor") && dIsPointInSprite("fourthdoor",fMouseX,fMouseY)){
		checkpointFourthpass=1;
		init();
		dLoadMap("checkpoint.t2d");
		dStopAllSound();
		SceneState=1;
	}
}

void Scene4::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;
	tools.SpriteReturnItembar(clickSmallFourthOildrum,"smallFourthOildrum",-51.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFourthIronhook,"smallFourthIronhook",5.5f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFourthWoodensticlk,"smallFourthWoodensticlk",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFourthWoodenboard,"smallFourthWoodenboard",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFourthPants,"smallFourthPants",6.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickFourthWoodenboard_Pants,"smallFourthWoodenboard_Pants",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickFourthBoard_Pants_oild,"smallFourthBoard_Pants_oild",-50.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFourthTorch,"smallFourthTorch",-50.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallFourthKey,"smallFourthKey",-51.f,41.f,1000.f);
}

void Scene4::KeyDown(const int iKey, const int bAltPress, const int bShiftPress, const int bCtrlPress){}

void Scene4::KeyUp( const int iKey ){}

void Scene4::SpriteColSprite(const char *szSrcName, const char *szTarName){}