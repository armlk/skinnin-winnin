#include "../../build/external/raylib-master/src/raylib.h"
#include "Weapon.h"
#include <stdbool.h>

struct Player {
  float health;
  bool isAlive;
  float weight;
  float moveSpeed;
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  Texture sprite;
  Weapon weapon;
};

Player *initPlayer(void);
void updatePlayer(Player *p);
