#pragma once

class GameState {
private:
	bool paused;

public:
	bool getGameState() {
		return paused;
	}

	void setGameState(bool newState) {
		paused = newState;
	}

	GameState() {
		paused = true;
	}
};