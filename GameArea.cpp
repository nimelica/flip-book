#include "GameArea.h"
#include "Model.h"
#include "Animation.h"

using namespace std;
using namespace sf;

int frame = 0;
int counter = 0;
int frameTime = 5;
int numOfSprite = 10;

GameArea::GameArea() {
	createWindow();
	createEvents();
}

GameArea::~GameArea() {
	delete window;
}

void GameArea::createWindow() {
	settings.antialiasingLevel = 8;
	window = new RenderWindow(VideoMode(width, height), "COWBOY GAME", Style::Close | Style::Titlebar, settings);
	window->setFramerateLimit(60);
}

void GameArea::addModel(unique_ptr<Model>newModel) {
	modelList.emplace_back(move(newModel));
}

void GameArea::startGameLoop() {
	while (window->isOpen()){
		createEvents();
		renderGame();
	}
}

void GameArea::createEvents() {
	while (window->pollEvent(eventObj)){
		if (eventObj.type == Event::Closed) {
			window->close();
		}
		else if (eventObj.type == Event::KeyPressed && eventObj.key.code == Keyboard::Escape) {
			window->close();
		}
		keyboardControl(eventObj);
	}
}

void GameArea::keyboardControl(Event& event) {
	if (event.type == Event::KeyPressed){
		if (event.key.code == Keyboard::Left) {
			modelList[0]->run();
		}
		if (event.key.code == Keyboard::Right) {
			modelList[0]->run();
		}
		if (event.key.code == Keyboard::Up) {
			modelList[0]->jump();
		}
		if (event.key.code == Keyboard::Down) {
			modelList[0]->slide();
		}
	}
	if (event.type == Event::KeyReleased) {
		if (event.key.code == Keyboard::Left) {
			modelList[0]->idle();
		}
		if (event.key.code == Keyboard::Right) {
			modelList[0]->idle();
		}
		if (event.key.code == Keyboard::Up) {
			modelList[0]->idle();
		}
		if (event.key.code == Keyboard::Down) {
			modelList[0]->idle();
		}
	}
}

void GameArea::renderGame(){
	//Cleaning
	window->clear(Color::Green);

	//Render
	renderBackground();
	renderAnimation();

	//Display
	window->display();
}

void GameArea::renderAnimation(){
	for (auto& nextModel : modelList){                                          
		nextModel->render(window);
	}
}

void GameArea::renderBackground()
{
	if (backTexture.loadFromFile("spriteFile/forest.jpg") != true) {
		cerr << "Background file not found!\n";
	}
	backSprite.setTexture(backTexture);
	window->draw(backSprite);
}