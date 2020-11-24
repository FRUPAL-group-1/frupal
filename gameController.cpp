//impliments all of the gameController functions

#include "gameController.h"


GameController::GameController()
{
}
GameController::~GameController()
{
}
bool GameController::update()
{
  displayFrame(maps.map, hero.herox, hero.heroy, maps.discarded, hero.binocular);
}