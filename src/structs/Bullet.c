#include "Bullet.h"

Bullet initBullet() {
  Bullet b = {.position = (Vector2){0, 0},
              .velocity = (Vector2){10, 10},
              .collider = (Rectangle){0, 0, DEFAULT_BULLET_WIDTH,
                                      DEFAULT_BULLET_HEIGHT},
              .angle = 0,
              .isActive = false,
              .sprite = LoadTexture(DEFAULT_BULLET_SPRITE)};
  return b;
}

void drawBullet(Bullet *b) {
  DrawTextureEx(b->sprite, b->position, b->angle * RAD2DEG, 1, WHITE);
}

void activateBullet(Bullet *b, float x, float y, float angle) {
  b->position.x = x;
  b->position.y = y;
  b->collider.x = x;
  b->collider.y = y;
  b->angle = angle;
  b->isActive = true;
}

void updateBullet(Bullet *b) {
  b->position.x += b->velocity.x;
  b->position.y += b->velocity.y;
  b->collider.x += b->velocity.x;
  b->collider.y += b->velocity.y;
}
