/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
#include "stdio.h"
#include "Scene.h"
#include "Scene0.h"
#include "Scene01.h"
#include "Scene02.h"
#include "Scene03.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include "Scene5.h"
#include "Scene6.h"
#include "Scene7.h"
#include "Tools.h"
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState		=	0;		// 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();


int openingSound;

//int SceneState=0;  //关卡关数
Scene *b[11]= {new Scene0(),new Scene01(),new Scene02(),new Scene03(),new Scene1(),new Scene2(),new Scene3(),new Scene4(),new Scene5(),new Scene6(),new Scene7};


//关卡的变量
bool checkpointFirstpass=1;
bool checkpointSecondpass=1;
bool checkpointThirdpass=1;
bool checkpointFourthpass=1;
bool checkpointFifthpass=1;
bool checkpointSixthpass=1;
bool checkpointSeventhpass=1;

short rubyCount=0;

char *secondTexts[5]={"葛","瑞","士","齐","山"};
char *secondTextk[5]={"朱","文","骁","鲁","科"};
char *secondTextz[5]={"鹿","大","龙","软","职"};
char *secondTexty[5]={"邓","所","春","赛","院"};

bool rubyFirstYes=0;
bool rubySecondYes=0;
bool rubyThirdYes=0;
bool rubyFourthYes=0;
bool rubyFifthYes =0;
bool rubySixthYes=0;


int stopBLIP;

Tools tools;


//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。


//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态. 
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void GameMainLoop( float	fDeltaTime )
{

	dSetTextValue("rubyNumber",rubyCount);
	dSetTextValue("guanNumber",SceneState-3);
	dSetSpritePosition("rubyNumber",-67.6f,-45.498f);

	switch( g_iGameState )
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
		{
			GameInit();
			g_iGameState	=	2; // 初始化之后，将游戏状态设置为进行中
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else
			{
				// 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
				g_iGameState	=	0;
				GameEnd();
			}
		}
		break;

		// 游戏结束/等待按空格键开始
	case 0:
	default:
		break;
	};
}

//==============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void GameInit()
{
}
//==============================================================================
//
// 每局游戏进行中
void GameRun( float fDeltaTime )
{
}
//==============================================================================
//
// 本局游戏结束
void GameEnd()
{
}