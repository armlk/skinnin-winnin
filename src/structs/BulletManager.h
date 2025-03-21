#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include "../constants.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Obstacle.h"

typedef struct BulletManager {
  Bullet *bullets;
} BulletManager;

// Foward Dec of player. Update as needed.
struct Player;

BulletManager initBulletManager(void);

void fire(
    BulletManager *bm, float x, float y,
    float firedAngle); // Initializes a bullet and adds it to the bullet array

void updateBullets(
    BulletManager *bm, Obstacle obs[], struct Player *p,
    Enemy enmys[]); // Iterates the bullet array and checks for collisions

void drawBullets(BulletManager *bm); // Draws the bullets
#endif
