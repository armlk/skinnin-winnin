#include "../../build/external/raylib-master/src/raylib.h"

#define DEFAULT_BULLET_VELOCITY 15
#define DEFAULT_BULLET_HEIGHT 5
#define DEFAULT_BULLET_WIDTH 3

typedef struct {
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  float angle; // In Degrees
} Bullet;

Bullet initBullet(float x, float y, float firedAngle);
void drawBullet(Bullet *b);
