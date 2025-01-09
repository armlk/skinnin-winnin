#include "../../build/external/raylib-master/src/raylib.h"

typedef struct {
  Rectangle collider;
  Color color;
} Obstacle;

typedef struct {
  Obstacle *obstacles;
  int numObstacles;
} ObstacleList;

Obstacle initObstacle(float x, float y, float width, float height, Color color);
ObstacleList initObstacles(int numObstacles);  // treated as an array
void drawObstacles(ObstacleList obstacleList);