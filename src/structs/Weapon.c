#include "Weapon.h"
#include "BulletManager.h"

#include "../../build/external/raylib-master/src/raylib.h"
#include "../../build/external/raylib-master/src/raymath.h"

Weapon initWeapon(BulletManager *beem) {
  Weapon w = {.damage = DEFAULT_WEAPON_DAMAGE,
              .fireRate = DEFAULT_WEAPON_FIRE_RATE,
              .weight = DEFAULT_WEAPON_WEIGHT,
              .ammo = DEFAULT_WEAPON_AMMO,
              .reloadSpeed = DEFAULT_WEAPON_RELOAD_SPEED,
              .sprite = LoadTexture(DEFAULT_WEAPON_SPRITE),
              .position = (Polar){50, 0},
              .bm = beem};
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
  fire(w->bm, w->position.theta, 0,
       0); // THIS FUNCTION IS NOT READY. I NEED TO ACCESS POSITION SOMEHOW.
}

void drawWeapon(Weapon *w, Vector2 center) {
  Vector2 offset = polarToCart(w->position);
  DrawTextureEx(w->sprite, Vector2Add(offset, center),
                w->position.theta * RAD2DEG, 1, WHITE);
}
