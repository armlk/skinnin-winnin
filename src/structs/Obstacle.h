#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../../build/external/raylib-master/src/raylib.h"
#include "../constants.h"

typedef struct {
  Rectangle collider;
  Color color;
} Obstacle;

Obstacle initObstacle(float x, float y, float width, float height, Color color);
Obstacle *initObstacles(float xCoords[], float yCoords[], float widths[],
                        float heights[],
                        Color colors[]); // treated as an array
void drawObstacles(Obstacle obstacleList[]);

#endif
