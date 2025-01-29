#include "Obstacle.h"

#include <stdlib.h>

Obstacle initObstacle(float x, float y, float width, float height,
                      Color color) {
  return (Obstacle){.collider = (Rectangle){x, y, width, height},
                    .color = color};
}

Obstacle initObstacleRec(Rectangle rec, Color color) {
  return (Obstacle){.collider = rec, .color = color};
}

Obstacle *initObstacles(float xCoords[], float yCoords[], float widths[],
                        float heights[], Color colors[]) {
  Obstacle *obstacles = malloc(sizeof(Obstacle) * DEFAULT_ARR_SIZE);
  for (int i = 0; i < DEFAULT_ARR_SIZE; i++) {
    obstacles[i] =
        initObstacle(xCoords[i], yCoords[i], widths[i], heights[i], colors[i]);
  }
  return obstacles;
}

void drawObstacles(Obstacle *obstacles) {
  for (int i = 0; i < DEFAULT_ARR_SIZE; i++) {
    DrawRectangleRec(obstacles[i].collider, obstacles[i].color);
  }
}