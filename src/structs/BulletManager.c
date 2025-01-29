#include "BulletManager.h"
#include "Bullet.h"
#include "stdlib.h"

void fire(BulletManager *bm, float x, float y, float firedAngle) {
  Bullet *b = (Bullet *)malloc(sizeof(Bullet));
  *b = initBullet(x, y,
                  firedAngle); // Assuming initBullet returns a Bullet struct
  for (int i = 0; i < DEFAULT_ARR_SIZE; i++) {
    if (bm->bullets[i] == NULL) {
      bm->bullets[i] = b;
      return;
    }
  }
  // might want to add some logic for an error if theres too many bullets
}
