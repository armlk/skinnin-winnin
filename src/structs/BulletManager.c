#include "BulletManager.h"
#include "Bullet.h"
#include "stdlib.h"
#include <stdlib.h>

BulletManager initBulletManager(void) {
  Bullet *bulletArray = (Bullet *)malloc(DEFAULT_ARR_SIZE * sizeof(Bullet));
  BulletManager bm = (BulletManager){.bullets = bulletArray};
  return bm;
}

void fire(BulletManager *bm, float x, float y, float firedAngle) {
  // Iterates through the bullets array until there is an open slot
  for (int i = 0; i < DEFAULT_ARR_SIZE; i++) {
    if (!bm->bullets[i].isActive) {
      activateBullet(&bm->bullets[i], x, y, firedAngle);
      return;
    }
  }
  // might want to add some logic for an error if theres too many bullets
}

void drawBullets(BulletManager *bm) {
  for (int i = 0; i < DEFAULT_ARR_SIZE; i++) {
    if (bm->bullets[i].isActive)
      drawBullet(&bm->bullets[i]);
  }
}
