#ifndef TOOOLS_H
#define TOOOLS_H
#include "CommonAPI.h"


class Tools
{
public:
	Tools();
	~Tools();

	void ShowSprite(const char* szName , const float fMouseX, const float fMouseY);
	void ClickChangeScene(const char *szName1,const char *szName2,const float fMouseX, const float fMouseY);
	void ShowItems(const bool mark,const char *szName,const char *smallName,const int sz1,const int sz2);
	void ShowItems(const bool mark,const char *szName1,const char *szName2, const char *szName3,const int sz1,const int sz2,const int sz3);
	void BiggerSprite(bool pass,const char *szName,const float fMouseX, const float fMouseY);
	void SpriteReturnItembar(bool &click , const char *szName, const float fPosX, const float fPosY,const float fSpeed);
	bool SpriteMoveTo(bool &clickyes, const char *szName, const char *szName2,  const float fMouseX, const float fMouseY,float fSpeed);
	void PlaySound(const int &soundId , const char *szName,  const int iLoop, const float fVolume);
	void Setting(const float fMouseX,const float fMouseY);
	void SetJixuButton(const float fMouseX,const float fMouseY);
	bool SetQuitButton(const char *szName,const char *scene,const int state,const float fMoustX,const float fMouseY);
	void SetGameVoice(const float fMoouseX,const float fMouseY);
};



#endif // TOOLS_H