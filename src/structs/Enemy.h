#include "../../build/external/raylib-master/src/raylib.h"
#include <stdbool.h>

typedef struct {
  float health;
  bool isAlive;
  float moveSpeed;
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  Texture sprite;
} Enemy;

Enemy initEnemy(void);
void updateEnemy(Enemy *e);
void updateEnemies(Enemy *e[]);
