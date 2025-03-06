#include "Player.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../build/external/raylib-master/src/raylib.h"
#include "../../build/external/raylib-master/src/raymath.h"
#include "Weapon.h"

Player initPlayer(BulletManager *bm) {
  Vector2 defaultPos = (Vector2){SCREEN_WIDTH / 2 - DEFAULT_PLAYER_WIDTH / 2,
                                 SCREEN_HEIGHT / 2 - DEFAULT_PLAYER_HEIGHT / 2};

  // TODO: Need a null check for the malloced memory and a way to free it
  Weapon *w = (Weapon *)malloc(sizeof(Weapon));
  Weapon temp = initWeapon(bm);
  *w = temp;

  Player p = (Player){
      .health = DEFAULT_PLAYER_HEALTH,
      .isAlive = true,
      .weight = DEFAULT_PLAYER_WEIGHT,
      .moveSpeed = DEFAULT_PLAYER_MOVE_SPEED,
      .position = defaultPos,
      .velocity = (Vector2){0, 0},
      .collider = (Rectangle){defaultPos.x, defaultPos.y, DEFAULT_PLAYER_WIDTH,
                              DEFAULT_PLAYER_HEIGHT},
      .sprite = LoadTexture(DEFAULT_PLAYER_SPRITE),
      .weapon = w,
  };
  return p;
}

void updatePlayer(Player *p) {
  // Calculates the angle the gun has to be rendered at
  // Y is negated to account for the axis being flipped
  Vector2 mPos = GetMousePosition();
  float angle = atan2f(mPos.y - p->position.y - p->collider.width / 2,
                       mPos.x - p->position.x - p->collider.height / 2);
  updateWeapon(p->weapon, angle);

  if (!p->isAlive) {
    return; // TODO: make a gameOver()
  }

  int xDirection =
      IsKeyDown(KEY_D) - IsKeyDown(KEY_A); // 1 is right; -1 is left
  int yDirection = IsKeyDown(KEY_S) - IsKeyDown(KEY_W); // 1 is down; -1 is up
  Vector2 direction = (Vector2){xDirection, yDirection};
  Vector2 addedPosition = Vector2Scale(direction, p->moveSpeed);

  p->position = Vector2Add(p->position, addedPosition);
  p->position = Vector2Add(p->position, p->velocity);
  p->collider.x = p->position.x;
  p->collider.y = p->position.y;
}

void drawPlayer(Player *p) {
  DrawTexture(p->sprite, p->position.x, p->position.y, WHITE);
  Vector2 center = (Vector2){p->position.x + p->collider.width / 2,
                             p->position.y + p->collider.height / 2};
  drawWeapon(p->weapon, center);
}
