#include "../../build/external/raylib-master/src/raylib.h"
#include <stdbool.h>

#define DEFAULT_ENEMY_HEALTH 100
#define DEFAULT_ENEMY_MOVE_SPEED 3
#define DEFAULT_ENEMY_SPRITE "enemy.png"
#define DEFAULT_ENEMY_WIDTH 50
#define DEFAULT_ENEMY_HEIGHT 100

typedef struct {
  float health;
  bool isAlive;
  float moveSpeed;
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  Texture sprite;

} Enemy;

Enemy initEnemy(float x, float y);
void updateEnemy(Enemy *e);
void updateEnemies(Enemy *e[]);
