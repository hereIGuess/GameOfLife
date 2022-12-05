#include "gamestate.h"

bool GameState::getGameState() { return paused; }

void GameState::setGameState(bool newState) {
	paused = newState;

	if (paused) text = "Paused";
	else text = "Playing";
}

std::string GameState::getText() { return text; }

GameState::GameState() { }
