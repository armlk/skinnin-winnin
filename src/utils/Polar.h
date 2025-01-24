#include "../../build/external/raylib-master/src/raylib.h"

typedef struct {
  float r;
  float theta; // in rad
} Polar;

Vector2 polarToCart(Polar p);
