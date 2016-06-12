
#include "Game.h"


Game game;
unsigned int score;

Game::Game() :
		running(false), isGameOver(false), ui(), background(), score(0), mEffectManager(), mEnemyManager() {
}

Game::~Game() {
}

bool Game::init() {

	GD.ClearColorA(255);
	GD.SaveContext();

	return true;
}

void Game::run() {
	running = true;

	player.startTime();//TODO Maybe delete?
	while (running) {

		input.pull();
		update();
		render();

		GD.swap();
		frames++;
	}

}

void Game::update() {
score++;
	timer.update();
	world.update(player.getPosition().x);
	player.update();
	mEnemyManager.update();
	mEffectManager.update();
	cam.follow(player.getPosition(), player.getVelocity());

}

void Game::render() {

	background.render();

	player.render();

	mEnemyManager.render();
	world.render();
	mEffectManager.render();
	ui.render();

}

bool Game::isOver() {
	return isGameOver;
}

void Game::setGameOver() {
	isGameOver = true;
}
