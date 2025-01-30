#ifndef BULLET_H
#define BULLET_H

#include "../../build/external/raylib-master/src/raylib.h"

#define DEFAULT_BULLET_VELOCITY 15
#define DEFAULT_BULLET_HEIGHT 5
#define DEFAULT_BULLET_WIDTH 3
#define DEFAULT_BULLET_SPRITE "bullet.png"

typedef struct {
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  float angle; // in rad
  bool isActive;
  Texture sprite;
} Bullet;

Bullet initBullet();
void drawBullet(Bullet *b);
void activateBullet(Bullet *b, float x, float y, float angle);
void updateBullet(Bullet *b);

#endif
