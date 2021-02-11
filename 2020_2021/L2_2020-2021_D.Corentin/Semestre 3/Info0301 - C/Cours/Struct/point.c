#include "point.h"
#include <math.h> 


struct point saisir_coord_point()
{
  struct point p;
  printf ("Donner l'abscisse ");
  scanf("%f",& p.x);
  printf ("Donner l'ordonnee ");
  scanf("%f",& p.y);
 
  return p;
}


void saisir_coord_point_1(struct point * p)
{
  printf ("Donner l'abscisse ");
  scanf("%f",& (*p).x);   // (*p).x  <==> p->x
  printf ("Donner l'ordonnee ");
  scanf("%f",& p->y);  // (*p).y  <==> p->y 
  return ;
}


void afficher_coord_point(struct point p)
{
  printf("Les coordonnees du point sont (%.2f,%.2f)\n",p.x,p.y);

}

float distance_L1_points(struct point p1, struct point p2)
{
  // p1(x,y) et p2(x,y)  => dist_L1(p1,p2)=|p1.x - p2.x|+|p1.y -p2.y|
  return fabsf(p1.x-p2.x)+ fabsf(p1.y-p2.y);

}


