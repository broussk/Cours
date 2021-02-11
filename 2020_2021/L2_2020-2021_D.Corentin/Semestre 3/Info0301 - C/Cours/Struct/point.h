#ifndef POINT_H
#define POINT_H

#include<stdio.h>

#define taille 10

struct point
{
  float x;
  float y;
};


struct point saisir_coord_point();
void saisir_coord_point_1(struct point *);
void afficher_coord_point(struct point);
float distance_L1_points(struct point, struct point);


#endif  /* POINT_H */
