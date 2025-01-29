#ifndef OBSTACLE_H
#define OBSTACLE_H

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
ObstacleList initObstacles(int numObstacles, float xCoords[], float yCoords[],
                           float widths[], float heights[],
                           Color colors[]);  // treated as an array
void drawObstacles(ObstacleList obstacleList);

#endif