#include "../../build/external/raylib-master/src/raylib.h"

struct Obstacle {
  Rectangle collider;
  Texture sprite;
};

Obstacle *initObstacle(void);
