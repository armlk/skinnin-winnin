#include "Enemy.h"
#include "../../build/external/raylib-master/src/raylib.h"
#include <stdbool.h>
Enemy initEnemy(float x, float y) {
  Enemy e = {.health = DEFAULT_ENEMY_HEALTH,
             .isAlive = true,
             .sprite = LoadTexture(DEFAULT_ENEMY_SPRITE),
             .collider =
                 (Rectangle){x, y, DEFAULT_ENEMY_WIDTH, DEFAULT_ENEMY_HEIGHT}};
  return e;
}
