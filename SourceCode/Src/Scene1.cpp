#include "Scene1.h"

Scene1::Scene1(){
	init();
}
Scene1::~Scene1(){}

void Scene1::init(){
TextBoxMark=0;
zuanjiYes=0;
showPromptCircleCar=0;
showPromptCircle=0;
clickTextBoxSeven=0;
clickTextBoxFive=0;
clickDrill=0;
clickZuanJian=0;
clickSmallDrill=0;
clickSmallZuanjian=0;
clickZuanji=0;
openBoxYes=0;
clickOpenBox=0;
//clickRuby=0;
clickTextBoxFifteen=0;
clickPromptCircleTrain=0;
showPromptCircleTrain=0;
pwd1=0;
pwd2=0;
pwd3=0;
clickSmallKey1=0;
openTrainYes=0;
openPwdBoxYes=0;
clickKey1=0;
clickPromptCircleTraindoor=0;

}
void Scene1::GameMainLoop(float fTimeDelta){
	if(gameVoice){
		dPlaySound("Tragedy.ogg",1,0.5);
	}
	if(!rubyCount && rubyFirstYes) rubyCount++;

	tools.ShowItems(clickDrill,"Drill","promptCircleDrill","smallDrill",0,0,1);
	tools.ShowItems(clickZuanJian,"ZuanJian","promptCircleZuanJian","smallZuanjian",0,0,1);
	tools.ShowItems(clickDrill&&clickZuanJian,"textBoxSeven","textBoxEight",0,1);

	if(clickTextBoxFive){  //点击后只显示对话框6
		dDeleteSprite("textBoxOne");
		dDeleteSprite("textBoxTwo");
		dDeleteSprite("textBoxThree");
		dDeleteSprite("textBoxFour");
		dDeleteSprite("textBoxFive");
		dSetSpriteVisible("textBoxSix",1);
		dSetSpriteVisible("backButton",1);
	}

	if(dIsSpriteVisible("textBoxSix")){
		dSetSpriteVisible("promptCircleCar",1);
		showPromptCircleCar=1;   //为0时点击无效，进不去汽车
	}

	tools.ShowItems(zuanjiYes,"smallZuanjian","smallDrill","zuanji",0,0,1);
	if(dIsSpriteVisible("zuanji")){
		dSetSpriteVisible("textBoxEight",0);
		dSetSpriteVisible("promptCircleCar",0);
		dSetSpriteVisible("textBoxNine",1);
		dSetSpriteVisible("textBoxTen",1);
		dSetSpriteVisible("backButton3",1);
		dSetSpriteVisible("textBoxSix",0);
		dSetSpriteVisible("promptCircle",1);
		dSetSpriteVisible("backButton",0);
	}
	if(openBoxYes){
		dSetSpriteVisible("openBox",1);
		dDeleteSprite("zuanji");
		dDeleteSprite("textBoxTen");
		dSetSpriteVisible("textBoxNine",0);
		dSetSpriteVisible("promptCircle",0);
		dSetSpriteVisible("textBoxEleven",1);
	}
	if(clickOpenBox){
		dSetSpriteVisible("textBoxEleven",0);
		dSetSpriteVisible("backButton",1);
	}
	if(rubyFirstYes && clickTextBoxFifteen){
		dSetSpriteVisible("ruby",0);
		dDeleteSprite("textBoxFifteen");
		//dSetSpriteVisible("textBoxFifteen",0);
		dSetSpriteVisible("textBoxSixteen",1);
		dSetSpriteVisible("backButton4",1);
		dSetSpriteVisible("promptCircleTrain",1);
		showPromptCircleTrain=1;
	}
	if(clickPromptCircleTrain){
		dSetSpriteVisible("promptCircleTrain",0);
		dSetSpriteVisible("textBoxSixteen",0);
		dSetSpriteVisible("textBoxSeventeen",1);
		dSetSpriteVisible("textBoxEighteen",1);
	}

	//密码部分
	dSetTextValue("pwd1",pwd1);
    dSetTextValue("pwd2",pwd2);
    dSetTextValue("pwd3",pwd3);
	if(pwd1==6 && pwd2==1 && pwd3==2){
		openPwdBoxYes=1;
	}
	if(openPwdBoxYes){
		dSetSpriteVisible("openPwdBox1",1);
		dSetSpriteVisible("key1",1);
		dSetSpriteVisible("textBoxEighteen",0);
		dSetSpriteVisible("textBoxNineteen",1);
	}
	if(clickKey1){
		dSetSpriteVisible("key1",0);
		dSetSpriteVisible("smallKey1",1);
		dSetSpriteVisible("textBoxNineteen",0);
		dSetSpriteVisible("textBoxTwenty",1);
	}

	if(dIsSpriteVisible("smallKey1") && dIsSpriteVisible("textBoxSeventen")){
		dSetSpriteVisible("textBoxSeventeen",0);
		dSetSpriteVisible("textBoxTwentyone",1);
	}
	if(openTrainYes){
		dDeleteSprite("smallKey1");
		dSetSpriteVisible("backButton5",0);
		dSetSpriteVisible("textBoxTwentyone",0);
		dSetSpriteVisible("openTrainDoor",1);
		dSetSpriteVisible("textBoxTwentytwo",1);
	}



}

void Scene1::MouseMove( const float fMouseX, const float fMouseY ){
	
	tools.BiggerSprite(1,"backButton",fMouseX,fMouseY);
	tools.BiggerSprite(1,"backButton3",fMouseX,fMouseY);
	tools.BiggerSprite(1,"backButton4",fMouseX,fMouseY);

	if(tools.SpriteMoveTo(clickZuanji,"zuanji","promptCircleBox",fMouseX,fMouseY,100000)){
		openBoxYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallKey1,"smallKey1","promptCircleTraindoor",fMouseX,fMouseY,100000)){
		openTrainYes=1;	
	}
	if(tools.SpriteMoveTo(clickSmallZuanjian,"smallZuanjian","smallDrill",fMouseX,fMouseY,100000)){
		zuanjiYes=1;
	}
	if(tools.SpriteMoveTo(clickSmallDrill,"smallDrill","smallZuanjian",fMouseX,fMouseY,100000)){
		zuanjiYes=1;
	}
}

void Scene1::MouseClick(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=1;

	if(dIsSpriteVisible("backButton")) { tools.ClickChangeScene("backButton","CheckpointFirst_one.t2d",fMouseX,fMouseY); }
	if(dIsSpriteVisible("backButton3")) { tools.ClickChangeScene("backButton3","CheckpointFirst_one.t2d",fMouseX,fMouseY); }
	if(dIsSpriteVisible("backButton4")) { tools.ClickChangeScene("backButton4","CheckpointFirst_two.t2d",fMouseX,fMouseY); }
	if(dIsSpriteVisible("backButton5")) { tools.ClickChangeScene("backButton5","CheckpointFirst_one.t2d",fMouseX,fMouseY); }

	//设置部分
	tools.Setting(fMouseX,fMouseY);
	tools.SetJixuButton(fMouseX,fMouseY);
	if(tools.SetQuitButton("setRestartButton","CheckpointFirst_one.t2d",4,fMouseX,fMouseY)) init();
	if(tools.SetQuitButton("setXuanzeButton","checkpoint.t2d",1,fMouseX,fMouseY)) init();
	if(tools.SetQuitButton("setQuitButton","GameMainInterface.t2d",0,fMouseX,fMouseY)) init();
	tools.SetGameVoice(fMouseX,fMouseY);

	if(dIsPointInSprite("textBoxOne",fMouseX,fMouseY)){
		TextBoxMark++;
		if(TextBoxMark==1){
			tools.ShowItems(1,"textBoxOne","textBoxTwo",0,1);
		}
		else if(TextBoxMark==2){
			tools.ShowItems(1,"textBoxTwo","textBoxThree",0,1);
		}
		else
		{
			dDeleteSprite("textBoxOne");
			tools.ShowItems(1,"textBoxThree","textBoxFour","promptCircle",0,1,1);
			showPromptCircle=1;    //为0时点击无效，进不去箱子
			TextBoxMark=0;
		}
		
	}

	if(dIsPointInSprite("textBoxFive",fMouseX,fMouseY)){
		clickTextBoxFive=1;
	}

	if(showPromptCircle && dIsPointInSprite("promptCircle",fMouseX,fMouseY)){
		dSetSpriteVisible("promptCircle",0);
		dLoadMap("CheckpointFirst_two.t2d");
	}


	if(showPromptCircleCar && dIsPointInSprite("promptCircleCar",fMouseX,fMouseY)){
		dSetSpriteVisible("promptCircleCar",0);
		dLoadMap("CheckpointFirst_three.t2d");
	}

	if(dIsPointInSprite("Drill",fMouseX,fMouseY)){
		clickDrill=1;
	}
	if(dIsPointInSprite("zuanjian",fMouseX,fMouseY)){
		clickZuanJian=1;
	}
	if(dIsSpriteVisible("smallDrill") && dIsPointInSprite("smallDrill",fMouseX,fMouseY)){
		clickSmallDrill=1;
	}
	if(dIsSpriteVisible("smallZuanjian") && dIsPointInSprite("smallZuanjian",fMouseX,fMouseY)){
		clickSmallZuanjian=1;
	}
	if(dIsSpriteVisible("zuanji") && dIsPointInSprite("zuanji",fMouseX,fMouseY)){
		clickZuanji=1;
	}
	if(dIsSpriteVisible("openBox") && dIsPointInSprite("openBox",fMouseX,fMouseY)){
		clickOpenBox=1;
		dLoadMap("CheckpointFirst_four.t2d");
	}
	if(dIsSpriteVisible("textBoxFourteen") &&  dIsPointInSprite("ruby",fMouseX,fMouseY)){
		dSetSpriteVisible("ruby",0);
		tools.PlaySound(stopBLIP,"ruby.ogg",0,1);
		dDeleteSprite("textBoxFourteen");
		dSetSpriteVisible("textBoxFifteen",1);
		rubyFirstYes=1;
	}
	if(clickOpenBox && dIsPointInSprite("textBoxTwelve",fMouseX,fMouseY)){
		dDeleteSprite("textBoxTwelve");
		dSetSpriteVisible("textBoxThirteen",1);
	}
	if(clickOpenBox && dIsPointInSprite("textBoxThirteen",fMouseX,fMouseY)){
		dDeleteSprite("textBoxThirteen");
		dSetSpriteVisible("textBoxFourteen",1);
	}
	if(dIsSpriteVisible("textBoxFifteen") && dIsPointInSprite("textBoxFifteen",fMouseX,fMouseY)){
		dDeleteSprite("textBoxFifteen");
		clickTextBoxFifteen=1;
	}
	if(showPromptCircleTrain && dIsPointInSprite("promptCircleTrain",fMouseX,fMouseY)){
		dLoadMap("CheckpointFirst_five.t2d");
		clickPromptCircleTrain=1;
	}

	//密码部分
	if(dIsPointInSprite("pwd1",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(pwd1<9)
			pwd1++;
		else
			pwd1=0;
	}
	if(dIsPointInSprite("pwd2",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(pwd2<9)
			pwd2++;
		else
			pwd2=0;		
	}
	if(dIsPointInSprite("pwd3",fMouseX,fMouseY)){
		tools.PlaySound(stopBLIP,"pwdbox.ogg",0,1);
		if(pwd3<9)
			pwd3++;
		else
			pwd3=0;
	}

	if(dIsSpriteVisible("key1") && dIsPointInSprite("key1",fMouseX,fMouseY)){
		clickKey1=1;
	}
	if(dIsSpriteVisible("smallKey1") && dIsPointInSprite("smallKey1",fMouseX,fMouseY)){
		clickSmallKey1=1;
	}
	if(dIsSpriteVisible("textBoxTwentytwo") && dIsPointInSprite("textBoxTwentytwo",fMouseX,fMouseY)){
		dSetSpriteVisible("textBoxTwentytwo",0);
		dSetSpriteVisible("textBoxTwentythree",1);
		dSetSpriteVisible("promptCircleTraindoor",1);
	}
	if(dIsSpriteVisible("promptCircleTraindoor") && dIsPointInSprite("promptCircleTraindoor",fMouseX,fMouseY)){
		checkpointFirstpass=1;
		init();
		dLoadMap("checkpoint.t2d");
		dStopAllSound();
		SceneState=1;
	}


}

void Scene1::MouseUp(const int iMouseType, const float fMouseX, const float fMouseY){
	clicks=0;

	tools.SpriteReturnItembar(clickZuanji,"zuanji",-52.329f,41.417f,1000.f);
	tools.SpriteReturnItembar(clickSmallKey1,"zuanji",-52.329f,41.417f,1000.f);
	tools.SpriteReturnItembar(clickSmallZuanjian,"smallZuanjian",-52.f,41.f,1000.f);
	tools.SpriteReturnItembar(clickSmallDrill,"smallDrill",-23.f,41.f,1000.f);
}


void Scene1::KeyDown(const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress){}

void Scene1::KeyUp(const int iKey){}

void Scene1::SpriteColSprite(const char *szSrcName, const char *szTarName){}