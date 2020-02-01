#include <cstdio>
#include <iostream>
#include <limits>

int main(){
    printf("voici le modele de donnée qu'utilise mon system :\n");
    printf("taille int : %d\n",sizeof(int));
    printf("taille long : %d\n", sizeof(long));
    printf("taille pointeur %d\n",sizeof(int*));
    printf("taille short int : %d\n",sizeof(short int));
    printf("taille long int : %d\n",sizeof(long int));
    printf("taille long long int : %d\n",sizeof(long long int));

    printf("\n\nmax int : %d\n",std::numeric_limits<int>::max());
    printf("min int : %d\n",std::numeric_limits<int>::min());
    printf("max long int : %ld\n",std::numeric_limits<long>::max());
    printf("min long int : %ld\n",std::numeric_limits<long>::min());
    printf("max long long int : %lld\n",std::numeric_limits<long long>::max());
    printf("min long long int : %lld\n",std::numeric_limits<long long>::min());

    printf("\n\nmax unsigned int : %ld\n",std::numeric_limits<unsigned int>::max());
    printf("min unsigned int : %ld\n",std::numeric_limits<unsigned int>::min());
    printf("max unsigned long int : %lld%d\n",std::numeric_limits<unsigned long>::max()/10,std::numeric_limits<unsigned long>::max()%10);
    printf("min unsigned long int : %lld\n",std::numeric_limits<unsigned long>::min());
    printf("max unsigned long long int : %lld%d\n",std::numeric_limits<unsigned long long>::max()/10,std::numeric_limits<unsigned long long>::max()%10);
    printf("min unsigned long long int : %lld\n",std::numeric_limits<unsigned long long>::min());

    //flemme de le faire, en gros faut donner un nombre que long int peut instancier mais pas int et faire pareil avec unsigned
}