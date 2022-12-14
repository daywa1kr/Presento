#pragma once
#include "AnimatedTex.h"
#include "InputMgr.h"
#include "GUI.h"

class Button : public Texture {
protected:
	Texture* tex;
	Texture* hovering;
	bool highlight = false;
	InputMgr* input;
	float x;
	float y;
	bool wasClicked = false;

public:
	bool isSelected = false;

public:
	Button(std::string filename, int w, int h, int posx, int posy, bool highlighted = false);
	~Button();

	bool WasClicked();
	void SetClicked(bool b);
	void Update();
	void Render();

protected:
	bool Intersect();
};

class CheckBox : public Button {
private:
	Texture* check;
	Texture* title;

public:
	bool off = true;

public:
	CheckBox(std::string text, int x, int y);
	~CheckBox();

	void Update();
	void Render();

};

class Panel :public GameEntity {
private:
	Texture* panel;
	Texture* background;
	Button* exit;	
	bool wasClosed = false;

protected:
	std::map<std::string, Texture*> textures;
	std::map<std::string, Button*> buttons;
	std::map<std::string, AnimatedTex*> animations;

public:

	bool WasClosed();
	void SetClosed();
	void SetAllClicked(bool b);

	Vector2 GetSize();

	Panel(Vector2 pos=Vector2(Graphics::Instance()->winWidth*0.5f, Graphics::Instance()->winHeight*0.5f));
	~Panel();

	void AddButton(std::string key, std::string filename, bool b, int posx, int posy, int w, int h);
	void AddTexture(std::string key, std::string filename, float posx, float posy);
	void AddText(std::string key, std::string font, std::string text, int size, float posx, float posy, SDL_Color color = { 83,126,57,255 });
	void AddAnimation(std::string key, std::string filename, int x, int y, int w, int h, int frameC, float animationSpeed, AnimatedTex::anim_d animationDir, float posx, float posy);

	Texture* GetTextureByKey(std::string key);
	Button* GetButtonByKey(std::string Key);
	AnimatedTex* GetAnimationByKey(std::string key);

	void Update();
	void Render();
};

class SpeechBox : public Panel{
private:
	Texture* panel;
	bool renderAll = true;

public:
	SpeechBox(Vector2 pos = Vector2(Graphics::Instance()->winWidth * 0.5f, Graphics::Instance()->winHeight-48.0f), bool allRender=true);
	~SpeechBox();

	void Update();
	void Render();

};

class PopUp : public Panel {
private:
	Texture* panel;

public:
	PopUp(Vector2 pos = Vector2((float)Graphics::Instance()->winWidth-135.0f, 60.0f));
	~PopUp();

	void Update();
	void Render();

};