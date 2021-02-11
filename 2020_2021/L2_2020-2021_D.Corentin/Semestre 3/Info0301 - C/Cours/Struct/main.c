#include "point.h"


int main() {
  struct point p1,p2;

  p1 = saisir_coord_point();

  saisir_coord_point_1(&p2);

  afficher_coord_point(p1);
  afficher_coord_point(p2);

  printf("La distance L1 entre p1 et p2 = %.4f\n",distance_L1_points(p1,p2));


  return 0;
}
