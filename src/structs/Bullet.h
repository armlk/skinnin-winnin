#ifndef BULLET_H
#define BULLET_H

#include "../../build/external/raylib-master/src/raylib.h"

#define DEFAULT_BULLET_VELOCITY 15
#define DEFAULT_BULLET_HEIGHT 5
#define DEFAULT_BULLET_WIDTH 3

typedef struct {
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  float angle; // in rad
  bool isActive;
} Bullet;

Bullet initBullet();
void drawBullet(Bullet *b);
void activateBullet(Bullet *b, float x, float y, float angle);

#endif
