//Utilisez std::numeric_limits (vois section 2.3) pour afficher min et max des types entier , meme avec unsigned
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	cout<<"entier signe : \nInt : max="<<numeric_limits<int>::max()<<" ;min="<<numeric_limits<int>::min()<<endl;
	cout<<"Long : max ="<<numeric_limits<long>::max()<<" ;min="<<numeric_limits<long>::min()<<endl;
	cout<<"Long long : max ="<<numeric_limits<long long>::max()<<" ;min="<<numeric_limits<long long>::min()<<endl;
	cout<<"Short : max ="<<numeric_limits<short>::max()<<" ;min="<<numeric_limits<short>::min()<<endl;

	cout<<"\nentier non signe : \nInt : max="<<numeric_limits<unsigned int>::max()<<" ;min="<<numeric_limits<unsigned int>::min()<<endl;
	cout<<"Long : max ="<<numeric_limits<unsigned long>::max()<<" ;min="<<numeric_limits<unsigned long>::min()<<endl;
	cout<<"Long long : max ="<<numeric_limits<unsigned long long>::max()<<" ;min="<<numeric_limits<unsigned long long>::min()<<endl;
	cout<<"Short : max ="<<numeric_limits<unsigned short>::max()<<" ;min="<<numeric_limits<unsigned short>::min()<<endl;
	return 0;
}