int Connexion(int x , int y){
    for ( int i = 1; i <= a;i++){
        // pour chaque arc du tableau
        if (arbre[i][1] == x && arbre[i][2] == y)    ||  (arbre[i][1] == y && arbre[i][2] == x){
            return 1;
        }
        return 0;
    }

    }
    void parcourir(int x){
    int c;
    int[] ccf[x] = c;
    // pour tout noeud différent de x
   for (int i =0 ;i<x ;i++){
// si y n'a pas été visité et il existe un arc entre x et y:
    if ccf[i] == 0 AND  (Connexion(x, y) == 1{
        parcourir(y);}
    }
