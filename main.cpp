#include "SFML/Graphics.hpp"
#include "GameArea.h"
#include "Model.h"
#include <memory>

using namespace std;
using namespace sf;


int main()
{
	string txtFileName("Cowboy.txt");

	unique_ptr<GameArea>newGameArea = make_unique<GameArea>();

	newGameArea->addModel(make_unique<Model>(txtFileName));
	newGameArea->startGameLoop();

	return 0;
}