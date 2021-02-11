#include <stdio.h>
#include <math.h>

typedef struct {
  double x;
  double y;
}Point;

typedef struct {​​​​
  Point point_gauche;
  Point point_droit;
}​​​​Rect;

void POINTshow(Point * p){​​​​
    printf("[%f %f]\n", p->x,p->y);
}​​​​

double POINTdist(Point * p){
  return sqrt(((p->x - p->x)*(p->x - p->x))+((p->y - p->y)*(p->y - p->y)));
}

public int POINTeq(Point *a, Point *b){​​​​
  return (a->x - b->x<0.000001) && (a->y - b->y<0.000001) ? : 1 : 0;
}​​​​

int main(void) {
  Point test = {.25,.75};
  POINTshow(test);
  return 0;
}
