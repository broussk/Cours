//Determiner le modele de donnees qu'utilise le systeme sur le quel vous êtes en ecrivant un programme
#include <iostream>
using namespace std;

int main(){
	cout << "Mon modele est en "<<sizeof(int)<<"/"<<sizeof(long int)<<"/"<<sizeof(int*)<<"\n je suis en ILP32 endl ;
	return 0;
}