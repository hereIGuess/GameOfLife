#pragma once
#include <string>

class GameState {
private:
	bool paused = true;
	std::string text = "Paused";

public:
	bool getGameState();

	void setGameState(bool newState);

	std::string getText();

	GameState();
};