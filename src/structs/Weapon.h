#include "../../build/external/raylib-master/src/raylib.h"

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
} Weapon;

Weapon initWeapon(void);
void updateWeapon(Weapon *w);
