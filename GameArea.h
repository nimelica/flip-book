#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
using namespace sf;

#ifndef GAME_AREA_H
#define GAME_AREA_H

class Model;

class GameArea
{
public:
	//constructor/destructor
	GameArea();
	~GameArea();

	//Public Functions
	void addModel(unique_ptr<Model>newModel);
	void startGameLoop();

private:
	//Window size
	int width = 1000;
	int height = 700;

	//SFML components
	RenderWindow* window;
	Event eventObj;
	Texture backTexture;
	Sprite backSprite;
	ContextSettings settings;

	vector<unique_ptr<Model>>modelList;  

private:
	//Private Functions
	void createEvents();
	void keyboardControl(Event& event);
	void renderGame();
	void createWindow();
	void renderAnimation();
	void renderBackground();
};
#endif

