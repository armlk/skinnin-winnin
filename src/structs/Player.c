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

  int xDirection =
      IsKeyPressed(KEY_D) - IsKeyPressed(KEY_A); // 1 is right; -1 is left
  int yDirection =
      IsKeyPressed(KEY_S) - IsKeyPressed(KEY_W); // 1 is down; -1 is up
  Vector2 direction = (Vector2){xDirection, yDirection};
  Vector2 addedPosition = Vector2Scale(direction, p->moveSpeed);

  p->position = Vector2Add(p->position, addedPosition);
  p->position = Vector2Add(p->position, p->velocity);
}

void drawPlayer(Player *p) {
  DrawTexture(p->texture, p->position.x, p->position.y, WHITE);
}
