#include "Bullet.h"
#include "../../build/external/raylib-master/src/raylib.h"

Bullet initBullet(float x, float y, float firedAngle) {
  Bullet b = {
      .position = (Vector2){x, y},
      .velocity = (Vector2){10, 10},
      .collider =
          (Rectangle){x, y, DEFAULT_BULLET_WIDTH, DEFAULT_BULLET_HEIGHT},
      .angle = firedAngle,
  };
  return b;
}
