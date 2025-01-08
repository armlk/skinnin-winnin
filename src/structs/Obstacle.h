#include "../../build/external/raylib-master/src/raylib.h"

typedef struct {
  Rectangle collider;
  Texture sprite;
} Obstacle;

Obstacle* initObstacle(void);
