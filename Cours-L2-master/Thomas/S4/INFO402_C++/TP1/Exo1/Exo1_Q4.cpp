/*En utilisant la syntaxe des litteraux (section 2.2d) initialiser des variables de chacun des types entiers (signé et non signé , 8 a 64 bits) 
avec des constantes entieres de facon a ce que la valeur utilisé pour initialiser ne convient pas pour initialiser un entier
avec moins de bits
Exemple=Un entier de 16 bits peut etre initilisé à 512 mais pas un entier en 8 bits*/

#include <iostream>
using namespace std;

int main()
{
	long long int lli=0b1000000000000000000000000000000000000000000000000000000000000000uLL;
	long int li=0b10000000000000000000000000000000L;
	int i= 0b10000000000000000000000000000000U;

	cout<<"long long = "<<lli<<"\nlong = "<<li<<"\nint = "<<i<<endl;
	return 0;
}