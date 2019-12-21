typedef struct Liste Liste;
typedef struct Cellule Cellule;

struct Cellule
{
    int nombre;
    Cellule *suivant;
};

struct Liste
{
    Cellule *tete;
    Cellule *queue;
};