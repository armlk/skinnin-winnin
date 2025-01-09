#include "Obstacle.h"

Obstacle initObstacle(float x, float y, float width, float height,
                      Color color) {
  Obstacle o =
      (Obstacle){.collider = (Rectangle){x, y, width, height}, .color = color};
  return o;
}

Obstacle *initObstacles(int numObstacles) {
  Obstacle *obstacles = malloc(sizeof(Obstacle) * (numObstacles));
  for (int i = 0; i < numObstacles; i++) {
    obstacles[i] = initObstacle(100, 0, 100, 200, DARKGRAY);
  }
  return obstacles;
}

void drawObstacles(ObstacleList obstacleList) {
  for (int i = 0; i < obstacleList.numObstacles; i++) {
    DrawRectangleRec(obstacleList.obstacles[i].collider,
                     obstacleList.obstacles[i].color);
  }
}