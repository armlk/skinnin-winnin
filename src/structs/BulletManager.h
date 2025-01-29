#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include "../main.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "Player.h"

typedef struct {
  Bullet *bullets[DEFAULT_ARR_SIZE];
} BulletManager;

void fire(
    BulletManager *bm, float x, float y,
    float firedAngle); // Initializes a bullet and adds it to the bullet array

void updateBullets(
    BulletManager *bm, Obstacle obs[], Player *p,
    Enemy enmys[]); // Iterates the bullet array and checks for collisions

void drawBullets(BulletManager *bm); // Draws the bullets
#endif
