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
int			g_iGameState		=	0;		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();


int openingSound;

//int SceneState=0;  //�ؿ�����
Scene *b[11]= {new Scene0(),new Scene01(),new Scene02(),new Scene03(),new Scene1(),new Scene2(),new Scene3(),new Scene4(),new Scene5(),new Scene6(),new Scene7};


//�ؿ��ı���
bool checkpointFirstpass=1;
bool checkpointSecondpass=1;
bool checkpointThirdpass=1;
bool checkpointFourthpass=1;
bool checkpointFifthpass=1;
bool checkpointSixthpass=1;
bool checkpointSeventhpass=1;

short rubyCount=0;

char *secondTexts[5]={"��","��","ʿ","��","ɽ"};
char *secondTextk[5]={"��","��","��","³","��"};
char *secondTextz[5]={"¹","��","��","��","ְ"};
char *secondTexty[5]={"��","��","��","��","Ժ"};

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
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�


//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void GameMainLoop( float	fDeltaTime )
{

	dSetTextValue("rubyNumber",rubyCount);
	dSetTextValue("guanNumber",SceneState-3);
	dSetSpritePosition("rubyNumber",-67.6f,-45.498f);

	switch( g_iGameState )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			g_iGameState	=	2; // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else
			{
				// ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
				g_iGameState	=	0;
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}

//==============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void GameInit()
{
}
//==============================================================================
//
// ÿ����Ϸ������
void GameRun( float fDeltaTime )
{
}
//==============================================================================
//
// ������Ϸ����
void GameEnd()
{
}