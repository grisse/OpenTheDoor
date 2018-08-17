/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>
#include "CommonAPI.h"
#include "Scene.h"
#include "Tools.h"

extern void	GameMainLoop( float	fDeltaTime );

//bainliang
extern int openingSound;  //��ͷ�������� 

extern int clicks;   //�������
extern int SceneState;
extern Scene *b[11];
extern Tools tools;

extern bool checkpointFirstpass;
extern bool checkpointSecondpass;
extern bool checkpointThirdpass;
extern bool checkpointFourthpass;
extern bool checkpointFifthpass;
extern bool checkpointSixthpass;
extern bool checkpointSeventhpass;
extern short rubyCount;//��ʯ����

extern char *secondTexts[5];
extern char *secondTextk[5];
extern char *secondTextz[5];
extern char *secondTexty[5];

extern int stopBLIP;
extern bool gameVoice;

extern bool rubyFirstYes;
extern bool rubySecondYes;
extern bool rubyThirdYes;
extern bool rubyFourthYes;
extern bool rubyFifthYes;
extern bool rubySixthYes;

/////////////////////////////////////////////////////////////////////////////////
//
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMain
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������

public:
	CGameMain();            //���캯��
	~CGameMain();           //��������  

	// Get����
	int				GetGameState()											{ return m_iGameState; }
	
	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	
	// ��Ϸ��ѭ����
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();
	void 			OnMouseMove( const float fMouseX, const float fMouseY );
	void 			OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void 			OnKeyUp( const int iKey );
	void 			OnSpriteColSprite( const char *szSrcName, const char *szTarName );
	void 			OnSpriteColWorldLimit( const char *szName, const int iColSide );
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_