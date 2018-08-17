#include "Scene2.h"

Scene2::Scene2(){
	init();
}
Scene2::~Scene2(){}

void Scene2::init(){
	secondTextsindex=0;
	secondTextkindex=0;
	secondTextzindex=0;
	secondTextyindex=0;
	//secondTexts[5]={"葛","瑞","士","齐","山"};
	//secondTextk[5]={"朱","文","骁","鲁","科"};
	//secondTextz[5]={"鹿","大","龙","软","职"};
	//secondTexty[5]={"邓","所","春","赛","院"};
	clickSecondKnife=0;
	clickSmallSecondknife=0;
	clickSmallsecondKnifeAndHammer=0;
	hammerAndKnifeYes=0;
	openDeskYes=0;
	clickSecondKey=0;
	clickSmallSecondkey=0;
	openSecondDoorYes=0;
	clickSecondCrutch=0;
	clickSecondHammer=0;
	clickSmallSecondhammer=0;
	clickSmallSecondcrutch=0;
	openWindowYes=0;
}

void Scene2::GameMainLoop(float fTimeDelta){
	if(gameVoice){
		dPlaySound("BeiJiaErHuPan.ogg",1,0.5);
	}
	if(rubySecondYes)  dDeleteSprite("ruby");
	dSetTextString("secondtexts",secondTexts[secondTextsindex]);
	dSetTextString("secondtextk",secondTextk[secondTextkindex]);
	dSetTextString("secondtextz",secondTextz[secondTextzindex]);
	dSetTextString("secondtexty",secondTexty[secondTextyindex]);

	tools.ShowItems(clickSecondCrutch,"secondCrutch","smallSecondcrutch",0,1);
	tools.ShowItems(clickSecondHammer,"secondHammer","smallSecondhammer",0,1);
	tools.ShowItems(openWindowYes,"smallSecondcrutch","openWindowshow",0,1);

	if(secondTexts[secondTextsindex]=="山" && secondTextk[secondTextkindex]=="科" && secondTextz[secondTextzindex]=="职" && secondTexty[secondTextyindex]=="院"){
		dSetSpriteVisible("openSecondPwdbox",1);
		dSetSpriteVisible("secondKnife",1);
	}
	tools.ShowItems(clickSecondKnife,"secondKnife","smallSecondknife",0,1);
	tools.ShowItems(hammerAndKnifeYes,"smallSecondhammer","smallSecondknife","smallsecondKnifeAndHammer",0,0,1);
	tools.ShowItems(openDeskYes,"smallsecondKnifeAndHammer","secondOpenDesk",0,0);
	tools.ShowItems(clickSecondKey,"secondKey","smallSecondkey",0,1);
	tools.ShowItems(openSecondDoorYes,"smallSecondkey","secondDoor","secondDooropen",0,0,1);
}

void Scene2::MouseMove(const float fMouseX, const float fMouseY){
	tools.BiggerSprite(1,"secondBackButton",fMouseX,fMouseY);

	if(tools.SpriteMoveTo(clickSmallSecondcrutch,"smallSecondcrutch","secondWindowTrigger",fMouseX,fMouseY,100000) ){
		openWindowYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSecondhammer,"smallSecondhammer","smallSecondknife",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallSecondknife")){
		hammerAndKnifeYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSecondknife,"smallSecondknife","smallSecondhammer",fMouseX,fMouseY,100000) && dIsSpriteVisible("smallSecondhammer")){
		hammerAndKnifeYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallsecondKnifeAndHammer,"smallsecondKnifeAndHammer","secondOpenDesk",fMouseX,fMouseY,100000) ){
		openDeskYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallSecondkey,"smallSecondkey","secondDoorTrigger",fMouseX,fMouseY,100000) ){
		openSecondDoorYes=1;
	}
}

void Scene2::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=1;

	tools.ClickChangeScene("secondBackButton","CheckpointSecond_one.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSecondsofa","CheckpointSecond_twosofa.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSecondwindow","CheckpointSecond_threewindow.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSeconddesk","CheckpointSecond_fivedesk.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSeconddoor","CheckpointSecond_sixdoor.t2d",fMouseX,fMouseY);
	tools.ClickChangeScene("clickareaSecondpwdbox","CheckpointSecond_fourpwdbox.t2d",fMouseX,fMouseY);

	//设置部分
	tools.Setting(fMouseX,fMouseY);
	tools.SetJixuButton(fMouseX,fMouseY);
	if(tools.SetQuitButton("setRestartButton","CheckpointSecond_one.t2d",5,fMouseX,fMouseY)) init();
	if(tools.SetQuitButton("setXuanzeButton","checkpoint.t2d",1,fMouseX,fMouseY)) init();
	if(tools.SetQuitButton("setQuitButton","GameMainInterface.t2d",0,fMouseX,fMouseY)) init();
	tools.SetGameVoice(fMouseX,fMouseY);

	if(dIsPointInSprite("secondCrutch",fMouseX,fMouseY)){
		clickSecondCrutch=1;
	}
	if(dIsPointInSprite("secondHammer",fMouseX,fMouseY)){
		clickSecondHammer=1;
	}
	if(dIsSpriteVisible("smallSecondcrutch") && dIsPointInSprite("smallSecondcrutch",fMouseX,fMouseY)){
		clickSmallSecondcrutch=1;
	}
	if(dIsSpriteVisible("smallSecondhammer") && dIsPointInSprite("smallSecondhammer",fMouseX,fMouseY)){
		clickSmallSecondhammer=1;
	}
	if(dIsSpriteVisible("smallSecondknife") && dIsPointInSprite("smallSecondknife",fMouseX,fMouseY)){
		clickSmallSecondknife=1;
	}
	if(dIsSpriteVisible("smallsecondKnifeAndHammer") && dIsPointInSprite("smallsecondKnifeAndHammer",fMouseX,fMouseY)){
		clickSmallsecondKnifeAndHammer=1;
	}
	if(dIsSpriteVisible("smallSecondkey") && dIsPointInSprite("smallSecondkey",fMouseX,fMouseY)){
		clickSmallSecondkey=1;
	}
	if(openDeskYes && !rubySecondYes && dIsPointInSprite("ruby",fMouseX,fMouseY)){
		rubySecondYes=1;
		rubyCount++;
	}

	//密码
	if(dIsPointInSprite("secondtexts",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(secondTextsindex<4)
			secondTextsindex++;
		else
			secondTextsindex=0;
	}
	if(dIsPointInSprite("secondtextk",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(secondTextkindex<4)
			secondTextkindex++;
		else
			secondTextkindex=0;
	}
	if(dIsPointInSprite("secondtextz",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(secondTextzindex<4)
			secondTextzindex++;
		else
			secondTextzindex=0;
	}
	if(dIsPointInSprite("secondtexty",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(secondTextyindex<4)
			secondTextyindex++;
		else
			secondTextyindex=0;
	}
	if(dIsSpriteVisible("secondKnife") && dIsPointInSprite("secondKnife",fMouseX,fMouseY)){
		clickSecondKnife=1;
	}
	if(openDeskYes && dIsPointInSprite("secondKey",fMouseX,fMouseY)){
		clickSecondKey=1;
	}

	
	//提示
	if(dIsPointInSprite("clickareaPrompt",fMouseX,fMouseY)){
		dSetSpriteVisible("secondPrompt",1);
	}

	//过关
	if(dIsSpriteVisible("secondDooropen") && dIsPointInSprite("secondDooropen",fMouseX,fMouseY)){
		checkpointSecondpass=1;
		init();
		dLoadMap("CheckpointThird_one.t2d");
		dStopAllSound();
		SceneState=6;
	}

}

void Scene2::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;


	tools.SpriteReturnItembar(clickSmallSecondcrutch,"smallSecondcrutch",-24.f,43.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSecondhammer,"smallSecondhammer",-49.5f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSecondknife,"smallSecondknife",-23.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallsecondKnifeAndHammer,"smallsecondKnifeAndHammer",-54.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallSecondkey,"smallSecondkey",-51.f,41.f,1000.f);


	//提示
	if(dIsPointInSprite("clickareaPrompt",fMouseX,fMouseY)){
		dSetSpriteVisible("secondPrompt",0);
	}

}

void Scene2::KeyDown(const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress){}
void Scene2::KeyUp(const int iKey){}
void Scene2::SpriteColSprite(const char *szSrcName, const char *szTarName){}