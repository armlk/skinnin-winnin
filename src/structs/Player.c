#include "Player.h"
#include "../main.h"
#include "../../build/external/raylib-master/src/raylib.h"

Player *initPlayer(void) {
  Vector2 defaultPos = (Vector2){SCREEN_WIDTH / 2 - DEFAULT_PLAYER_WIDTH / 2,
                                 SCREEN_HEIGHT / 2 - DEFAULT_PLAYER_HEIGHT / 2};
  Player p = {DEFAULT_PLAYER_HEALTH,
              true,
              DEFAULT_PLAYER_WEIGHT,
              DEFAULT_PLAYER_MOVE_SPEED,
              defaultPos,
              (Vector2){0, 0},
              (Rectangle){defaultPos.x, defaultPos.y, DEFAULT_PLAYER_WIDTH,
                          DEFAULT_PLAYER_HEIGHT},
              LoadTexture(DEFAULT_PLAYER_SPRITE),
              InitWeapon()};
  return &p;
}

void updatePlayer(Player *p) {
  if (!p->isAlive) {
    return; // TODO: make a gameOver()
  }

  bool xDirection = IsKeyPressed(KEY_D) - IsKeyPressed(KEY_A);
  bool yDirection = IsKeyPressed(KEY_S) - IsKeyPressed(KEY_W);
  Vector2 direction = (Vector2){xDirection, yDirection};
  Vector2 addedVeclocity = Vector2Scale(direction, p->moveSpeed);
}
