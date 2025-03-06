#ifndef WEAPON_H
#define WEAPON_H

#include "../../build/external/raylib-master/src/raylib.h"
#include "../utils/Polar.h"
#include "BulletManager.h"

#define DEFAULT_WEAPON_DAMAGE 10
#define DEFAULT_WEAPON_FIRE_RATE 1
#define DEFAULT_WEAPON_WEIGHT 2
#define DEFAULT_WEAPON_AMMO 2
#define DEFAULT_WEAPON_RELOAD_SPEED 3
#define DEFAULT_WEAPON_SPRITE "shotgun.png"

typedef struct {
  float damage;
  float fireRate; // in Ms
  float weight;
  unsigned int ammo;
  float reloadSpeed; // in Ms
  Texture sprite;
  Polar position;
  BulletManager *bm;
} Weapon;

Weapon initWeapon(BulletManager *bm);
void updateWeapon(Weapon *w, float angle, Vector2 center);
void fireWeapon(Weapon *w, Vector2 center);
void drawWeapon(Weapon *w, Vector2 center);

#endif
