#include "Player.h"
#include "../../build/external/raylib-master/src/raylib.h"
#include "../../build/external/raylib-master/src/raymath.h"
#include "../main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Player initPlayer() {
  Vector2 defaultPos = (Vector2){SCREEN_WIDTH / 2 - DEFAULT_PLAYER_WIDTH / 2,
                                 SCREEN_HEIGHT / 2 - DEFAULT_PLAYER_HEIGHT / 2};

  // TODO: Need a null check for the malloced memory and a way to free it
  Weapon *w = (Weapon *)malloc(sizeof(Weapon));
  Weapon temp = initWeapon();
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
  float angle = atan2f(-(mPos.x - p->position.x), mPos.y - p->position.y);
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
}

void drawPlayer(Player *p) {
  DrawTexture(p->sprite, p->position.x, p->position.y, WHITE);
  drawWeapon(p->weapon, p->position);
}
