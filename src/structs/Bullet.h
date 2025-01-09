#include "../../build/external/raylib-master/src/raylib.h"

#define DEFAULT_BULLET_VELOCITY

typedef struct {
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  float angle; // In Degrees
} Bullet;

Bullet initBullet(float x, float y);
void drawBullet(Bullet *b);
