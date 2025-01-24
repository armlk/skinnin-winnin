/*
typedef struct {
  float r;
  float theta;
} Polar;
*/
#include "Polar.h"
#include "../../build/external/raylib-master/src/raylib.h"
#include "math.h"

Vector2 polarToCart(Polar *p) {
  float x = p->r * cos(p->theta);
  float y = p->r * sin(p->theta);
  return (Vector2){x, y};
}
