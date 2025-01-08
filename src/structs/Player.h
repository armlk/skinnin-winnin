#include "../../build/external/raylib-master/src/raylib.h"
#include "Weapon.h"
#include <stdbool.h>

#define DEFAULT_PLAYER_HEALTH 100
#define DEFAULT_PLAYER_WEIGHT 0
#define DEFAULT_PLAYER_MOVE_SPEED 10
#define DEFAULT_PLAYER_WIDTH 50
#define DEFAULT_PLAYER_HEIGHT 100
#define DEFAULT_PLAYER_SPRITE "player-sprite.png"

typedef struct {
  float health;
  bool isAlive;
  float weight;
  float moveSpeed;
  Vector2 position;
  Vector2 velocity;
  Rectangle collider;
  Texture sprite;
  Weapon weapon;
} Player;

Player *initPlayer(void);
void updatePlayer(Player *p);
