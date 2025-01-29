#include "Weapon.h"

#include "../../build/external/raylib-master/src/raylib.h"
#include "../../build/external/raylib-master/src/raymath.h"

Weapon initWeapon(void) {
  Weapon w = {
      .damage = DEFAULT_WEAPON_DAMAGE,
      .fireRate = DEFAULT_WEAPON_FIRE_RATE,
      .weight = DEFAULT_WEAPON_WEIGHT,
      .ammo = DEFAULT_WEAPON_AMMO,
      .reloadSpeed = DEFAULT_WEAPON_RELOAD_SPEED,
      .sprite = LoadTexture(DEFAULT_WEAPON_SPRITE),
      .position = (Polar){50, 0},
  };
  return w;
};
void updateWeapon(Weapon *w, float angle) {
  w->position.theta = angle;
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    fireWeapon(w);
  }
}

void fireWeapon(Weapon *w) {
  if (w->ammo == 0) {
    return;
  }
  // Call to BulletManager
}

void drawWeapon(Weapon *w, Vector2 playerPosition) {
  Vector2 offset = polarToCart(w->position);
  DrawTextureEx(w->sprite, Vector2Add(offset, playerPosition),
                w->position.theta * RAD2DEG, 1, WHITE);
}
