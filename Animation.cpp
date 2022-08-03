#include "Animation.h"
#include "Model.h"

using namespace std;
using namespace sf;

Animation::Animation() {
	totalFrame = 0;
	currentFrameNumber = 0;
	frameTime = 3;
	frameCounter = 0;
}

Animation::~Animation() {}

void Animation::addAnimation(string firstFileName, int frameNum, float xpos, float ypos) {
	totalFrame = frameNum;

	for (int i = 0; i < totalFrame; i++) {
		unique_ptr<Texture>newTexture = make_unique<Texture>();  //instead of Texture* newTexture = new Texture
		unique_ptr<Sprite>newSprite = make_unique<Sprite>();     //instead of Sprite*newSprite=new Sprite;

		double fileLength = firstFileName.length();
		string subFileName = firstFileName.substr(0, fileLength - 5);
		string fileType = firstFileName.substr(fileLength - 4, 4);

		string fullFileName = subFileName + to_string(i) + fileType;

		newTexture->loadFromFile(fullFileName);
		newSprite->setTexture(*newTexture);

		newSprite->setPosition(xpos, ypos);

		textureList.push_back(move(newTexture));
		spriteList.push_back(move(newSprite));
	}
}

void Animation::render(RenderWindow* window) {
	window->draw(*spriteList[currentFrameNumber]);
}

void Animation::update() {
	if (frameCounter == frameTime){
		currentFrameNumber = (currentFrameNumber + 1) % totalFrame; 
		frameCounter = 0;                                           
	}else{
		frameCounter++;
	}
}

void Animation::frameTimeUpdate(int time) {                          
	frameTime = time;
}
