#pragma once

class GameState {
private:
	bool paused = true;
	std::string text = "Paused";

public:
	bool getGameState() {
		return paused;
	}

	void setGameState(bool newState) {
		paused = newState;
		if (paused) text = "Paused";
		else text = "Playing";
	}

	std::string getText() {
		return text;
	}

	GameState() { }
};