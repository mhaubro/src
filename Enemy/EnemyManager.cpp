//Author: MG

#include "EnemyManager.h"
#include "Graphics.h"
#include "GD2.h"
#include "Bullet.h"
#include "Missile.h"

EnemyManager::EnemyManager() :
		enemies(), enemy_number(5) {
}

EnemyManager::~EnemyManager() {
	//Only delete if a new is done. No new.
}

void EnemyManager::update() {
	enemies.updateAll();
	enemies.clean();

	if (enemies.size() < enemy_number + 1) {
		Missile * m = new Missile(generatePosition(), Vector2f());
		enemies.add(m);
	}
}
void EnemyManager::render() {

	GD.RestoreContext();
	GD.Begin(BITMAPS);

	enemies.renderAll();

}

int EnemyManager::size() {
	return enemies.size();
}

EnemyManager::EnemyList::EnemyList() :
LinkedList<Enemy>() {
}
EnemyManager::EnemyList::~EnemyList() {
}

bool EnemyManager::EnemyList::shouldRemove(Node* node){
	return node->mData->isDead();
}

void EnemyManager::EnemyList::updateAll() {
	Node* tmp = mHead;
	while (tmp) {
		tmp->mData->update();
		tmp = tmp->mNext;
	}
}
void EnemyManager::EnemyList::renderAll() {
	Node* tmp = mHead;
	while (tmp) {
		tmp->mData->render();
		tmp = tmp->mNext;
	}
}

bool EnemyManager::EnemyList::firstInternalCollisionForTheRest(Node* current, Enemy* collided) {
	Node* tmp = current->mNext;
	while (tmp) {
		tmp = tmp->mNext;
	}
}

bool EnemyManager::EnemyList::checkBulletCollision(Bullet* bullet) {
	Node* tmp = mHead;
	while (tmp) {
//		if (tmp->mData->checkHit(bullet)) {
//			return true;
//		}
		tmp = tmp->mNext;
	}
	return false;
}

Vector2f EnemyManager::generatePosition() {
	Vector2f startV = Vector2f(cam.getX(), cam.getY());
	int maxX = WORLD_SIZE * CHUNK_SIZE;

	int x = (rand() % (CHUNK_SIZE + CHUNK_SIZE / 2)) + cam.getX();//+ CHUNK_SIZE

	if (rand() % 2 == 0) { //Approx 50 % chance
		x = x * (-1);
	}
	if (x < 0) {
		x += maxX;
	} else if (x >= CHUNK_SIZE * WORLD_SIZE) {
		x -= CHUNK_SIZE * WORLD_SIZE;
	}
	//y is calculated
	float y = world.getHeight(x) + 5 + (rand() % 5);
	Vector2f startPos = Vector2f(x, y);
	return startPos;
}
