#include "Weapon.h"
// #include "../../build/external/raylib-master/src/raylib.h"

Weapon initWeapon(void) {

  Weapon w = {.damage = DEFAULT_WEAPON_DAMAGE,
              .fireRate = DEFAULT_WEAPON_FIRE_RATE,
              .weight = DEFAULT_WEAPON_WEIGHT,
              .ammo = DEFAULT_WEAPON_AMMO,
              .reloadSpeed = DEFAULT_WEAPON_RELOAD_SPEED,
              .sprite = LoadTexture(DEFAULT_WEAPON_SPRITE),
              .position = (Vector2){0, 0}};
  return w;
};
void updateWeapon(Weapon *w) {
  if (w->ammo == 0) {
    return;
  }
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    fireWeapon(w);
  }
}

void fireWeapon(Weapon *w) {
  // Call to BulletManager
}
