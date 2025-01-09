#include "Obstacle.h"

Obstacle initObstacle(float x, float y, float width, float height,
                      Color color) {
  return (Obstacle){.collider = (Rectangle){x, y, width, height},
                    .color = color};
}

Obstacle initObstacleRec(Rectangle rec, Color color) {
  return (Obstacle){.collider = rec, .color = color};
}

ObstacleList initObstacles(int numObstacles, float xCoords[], float yCoords[],
                           float widths[], float heights[], Color colors[]) {
  Obstacle *obstacles = malloc(sizeof(Obstacle) * numObstacles);
  ObstacleList obstacleList = (ObstacleList){obstacles, numObstacles};
  for (int i = 0; i < numObstacles; i++) {
    obstacleList.obstacles[i] =
        initObstacle(xCoords[i], yCoords[i], widths[i], heights[i], colors[i]);
  }
  return obstacleList;
}

void drawObstacles(ObstacleList obstacleList) {
  for (int i = 0; i < obstacleList.numObstacles; i++) {
    DrawRectangleRec(obstacleList.obstacles[i].collider,
                     obstacleList.obstacles[i].color);
  }
}