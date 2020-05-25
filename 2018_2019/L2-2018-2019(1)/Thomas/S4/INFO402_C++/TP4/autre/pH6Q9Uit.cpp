#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iterator>
#include <initializer_list>
#include <cmath>
#include <cassert>

#define PI 3.14159265
//Je me suis arrêté après avoir terminé la partie 2.
//Faire différents module serait plus propre.
//Je n'ai pas testé ce code sous visual studio. Je compile avec g++ option -std=c++11
using namespace std;

//~ class Point{
	//~ private:
	//~ int x,y;
	//~
	//~ public:
		//~ inline Point():x(0),y(0){}
		//~ inline Point(int a, int b):x(a),y(b){}
		//~ inline Point(const Point &P):x(P.x),y(P.y){}
		//~ inline int getPoint_x()const{ return x;}
		//~ inline int getPoint_y()const{ return y;}
		//~ inline void setPoint_x(int a){this->x=a;}
		//~ inline void setPoint_y(int a){this->y=a;}
//~ };
//!DEBUT POINT.H
	class Point{
	private:
	float x,y;

	public:
		inline Point();
		inline Point(float a, float b);
		inline Point(const Point &P);
		inline float getPoint_x()const;
		inline float getPoint_y()const;
		inline void setPoint_x(float flo);
		inline void setPoint_y(float flo);

		Point& operator =(const Point &P);
};
//!FIN POIN.h
//!DEBUT POINT.cpp
	inline Point::Point():x(0),y(0){}
	inline Point::Point(float a, float b):x(a),y(b){}
	inline Point::Point(const Point &P):x(P.x),y(P.y){}
	inline float Point::getPoint_x()const{ return x;}
	inline float Point::getPoint_y()const{ return y;}
	inline void Point::setPoint_x(float flo){this->x=flo;}
	inline void Point::setPoint_y(float flo){this->y=flo;}

	Point& Point::operator =(const Point &P){
		cout << "Point: operator = " << endl;
		if(this!=&P){
			this->x=P.x;
			this->y=P.y;
		}
		return *this;
	}

	ostream& operator<<(ostream &os ,const Point p){
		os << "( " << p.getPoint_x() <<" , " << p.getPoint_y() <<" )"<< endl;
		return os;
	}

//!FIN DE POINT .cpp
//!DEBUT COLOR.H
class Color{
	public:
	enum color { white, yellow, orange, turquoise, violet, pink, red, green, grey, cyan, blue, brown};//Chap 1 p12

	// tester avec enum color:const char* {black = "black ", ... } // dans main Color c(Color::red);
	private :
	color couleur;
	static const char* name[];

	public:
	inline Color();
	inline Color(color c );
	inline Color(const Color &C );//Ajout non demandé
	void view();
	const char* getColor()const;


};
//!FIN COLOR.H
//!DEBUT COLOR.CPP
	inline Color::Color():couleur(red){};
	inline Color::Color(color c ):couleur(c){cout << "Ccopie" << endl; };
	inline Color::Color(const Color &C ):couleur(C.couleur){cout << "Ccopie" << endl; };//Ajout non demandé
	void Color::view(){ cout << couleur << endl; }
	const char* Color::getColor()const{ return name[couleur];}

const char* Color::name[]={ "white", "yellow", "orange", "turquoise", "violet", "pink", "red", "green", "grey", "cyan", "blue", "brown"};//Chap 1 p12
//!FIN COLOR.CPP
//!DEBUT TRANSFORM.H
class Transform{//Interface ne contient que des méthodes virtuels pures (méthodes implémentés dans les classes qui héritent de cette interface/classe abstraite pure ) n'implémentez JAMAIS une fonction virtuelle pure dans cette même classe
	public:
	virtual void Rotate(float)=0;
	virtual void Translate(float,float)=0;
	virtual void Scale(float)=0;
};
//!FIN TRANSFORM.H
//!DEBUT GEOM2D.H
class Geom2D: public Transform{
	protected:
		Point p;
	public:

	//Constructeurs
	inline Geom2D();//on utilise le constructeur par défaut de Point
	inline Geom2D(float x,float y);//on utilise le constructeur qui prend deux entier de Point
	inline void info();


	inline Point getPoint()const;//modification ici avec erreur dans setter
	inline void setX(float x);
	inline void setY(float y);
	virtual void Translate(float a, float b){p.setPoint_x(p.getPoint_x()+a);p.setPoint_y(p.getPoint_y()+b);}
};
//!FIN GEOM2D.H
//!DEBUT GEOM2D.CPP
	//Constructeurs
	inline Geom2D::Geom2D():p(){}//on utilise le constructeur par défaut de Point
	inline Geom2D::Geom2D(float x,float y):p(x,y){}//on utilise le constructeur qui prend deux entier de Point
	inline void Geom2D::info(){
		cout << "Coordonnées : " << p.getPoint_x() << ", " << p.getPoint_y() << endl;
	}


	inline Point Geom2D::getPoint()const{return p;}//modification ici avec erreur dans setter
	inline void Geom2D::setX(float x){p.setPoint_x(x);}
	inline void Geom2D::setY(float y){p.setPoint_y(y);}

//!FIN GEOM2D.CPP
//!DEBUT FILLPROPERTY.H
class FillProperty{
	protected:
		Color C;
	public:
	//Constructeurs
		inline FillProperty();
		inline FillProperty(const Color &Couleur);

		inline void info();// à suppr juste pour tests
		inline const char* getColor()const;
};
//!FIN FILLPROPERTY.H
//!DEBUT FILLPROPERTY.cpp
	inline FillProperty::FillProperty():C(){}
	inline FillProperty::FillProperty(const Color &Couleur):C(Couleur){}

	inline void FillProperty::info(){cout << C.getColor() << endl;}// à suppr juste pour tests
	inline const char* FillProperty::getColor()const{return C.getColor();}
//!FIN FILLPROPERTY.cpp
//!DEBUT SURFACE.H
class Surface : public Geom2D, public FillProperty{//classe virtuelle à cause de aire et info qui seront réimplémenté dans les objets qui héritent de Surface, ceci dit n'étant pas des fonctions virtuelles pure on doit implémenté info() et aire() aussi dans Surface
	protected:
		float S_rotate;//Utile pour transform()
	public:
	//Constructeurs
		inline Surface();
		inline Surface(float x, float y, const Color& Couleur);
		inline void info();
		virtual double aire(){return 0;}//pas d'air pour l'instant on ne dispose que d'un point et d'une couleur
		virtual void Rotate( float rotation){S_rotate = rotation;}
		inline float getRotate()const;
};
//!FIN SURFACE.H
//!DEBUT SURFACE.cpp
	inline Surface::Surface():Geom2D(),FillProperty(),S_rotate(0){cout << "Surface defaut " << endl;}
	inline Surface::Surface(float x, float y, const Color& Couleur):Geom2D(x,y),FillProperty(Couleur),S_rotate(0){cout << "S_tout spécifier\n" << endl;};
	inline void Surface::info(){
		cout << "Surface : \nCouleur " << C.getColor() << "\nGeom2D (x,y) : ( " << p.getPoint_x() << " , "  << p.getPoint_y() << " )\n" << endl;
	}
	inline float Surface::getRotate()const{return S_rotate;}
//!FIN SURFACE.cpp
//!DEBUT DISC.H
class Disc : public Surface{
	private:
		float rayon;
	public:
	//Constructeurs
		inline Disc();
		inline Disc(float x, float y ,const Color& Couleur, float r);
		inline void info();
		inline float getRayon()const;
		virtual double aire(){return 3.14*rayon*rayon;}//pi*r*r peut mieux faire pour pi
		virtual void Scale(float s){ rayon*=s;};
	};
//!FIN DISC.H
//!DEBUT DISC.cpp
	inline Disc::Disc():Surface(),rayon(100){}
	inline Disc::Disc(float x, float y ,const Color& Couleur, float r):Surface(x,y,Couleur),rayon(r){}
	inline void Disc::info(){
		cout << "Disc : \nCouleur " << C.getColor() << "\nGeom2D (x,y) : ( " << p.getPoint_x() << " , "  << p.getPoint_y() << " )\n" << "Rayon : " << rayon << "\n" << endl;
	}
	inline float Disc::getRayon()const{return rayon;}

//!FIN DISC.cpp

//!DEBUT RECTANGLE.H
class Rectangle : public Surface{
	protected:
		float hauteur;
		float largeur;
	public:
	//Constructeurs
		inline Rectangle();
		inline Rectangle(float x, float y , float h , float l ,const Color& Couleur);
		inline void info();
		inline float getHauteur()const;
		inline float getLargeur()const;
		inline void setHauteur( float h);
		inline void setLargeur( float l);

		virtual double aire(){return hauteur*largeur;}
		virtual void Scale(float s ){hauteur*=s;largeur*=s;}

};
//!FIN RECTANGLE.H

//!DEBUT RECTANGLE.cpp
	inline Rectangle::Rectangle():Surface(),hauteur(100),largeur(200){}
	inline Rectangle::Rectangle(float x, float y , float h , float l ,const Color& Couleur):Surface(x,y,Couleur),hauteur(h),largeur(l){}
	inline void Rectangle::info(){
		cout << "Rectangle : \nCouleur " << C.getColor() << "\nGeom2D (x,y) : ( " << p.getPoint_x() << " , "  << p.getPoint_y() << " )" << "\nHauteur: " << hauteur << "\nLargeur: " << largeur << "\n" << endl;
	}
	inline float Rectangle::getHauteur()const{return hauteur;}
	inline float Rectangle::getLargeur()const{return largeur;}
	inline void Rectangle::setHauteur( float h){this->hauteur = h;}
	inline void Rectangle::setLargeur( float l){this->largeur = l;}

//!FIN RECTANGLE.cpp
//!DEBUT RECTANGLE.H

class Square : public Rectangle{// On utilise uniquement la hauteur pour le carré
	public:
		inline Square();
		inline Square(float x, float y ,float h,const Color& Couleur);
		inline void info();
		virtual double aire(){return hauteur*hauteur;}
		virtual void Scale(float s){hauteur*=s;}
};
//!FIN RECTANGLE.H
//!DEBUT RECTANGLE.CPP
		inline Square::Square():Rectangle(){}
		inline Square::Square(float x, float y ,float h,const Color& Couleur):Rectangle(x,y,h,h,Couleur){}
		inline void Square::info(){
			cout << "Square : \nCouleur " << C.getColor() << "\nGeom2D (x,y) : ( " << p.getPoint_x() << " , "  << p.getPoint_y() << " )\n" << hauteur << "\n" << endl;
		}

//!FIN RECTANGLE.CPP

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! PAS IMPLEMENTER
class LineProperty:public FillProperty{
	//Uniquement des méthodes virtuel=0 PURES

};
class Curve:public LineProperty{
	private:
		Point A,B;
		int largeur;
	public:
		//Constructeurs
		//getters
		inline Point getPointA()const{return A;}
		inline Point getPointB()const{return B;}
		inline int getLargeur()const{return largeur;}
};
class Segment{

};
//!!!!!!!!!!!!!!!!!!!!! Fin des trucs pas implémenté
//!DEBUT SVGSTREAM.H
class SVGstream{
	private:
		string nom;
		ofstream fichier;
	public:
	 	inline SVGstream(string nom,bool PureSvg);
		~SVGstream(){
			if(fichier){
				fichier << "</svg>" << endl;
				fichier.close();
			}
		}

	ostream& operator<<(const string s){//operator définie dans la classe, on a directement acces aux champs
			fichier << s << endl;
			return fichier;
		}
	ostream& operator<<(const Disc D){ // Amélioration de l'appel des Getteur ici ( D.getPoint().getPoint_x() est beaucoup mieux )
		fichier << "<circle cx=\""<< D.getPoint().getPoint_x()  <<"\" cy= \""<< D.getPoint().getPoint_y() <<"\" r= \""<< D.getRayon() <<"\" fill= \""<< D.getColor() << "\"/>" << endl;
		return fichier;
	}
	ostream& operator <<(const Rectangle R){
		if(R.getRotate()!=0){
			fichier << "<rect x=\"" <<  R.getPoint().getPoint_x() <<"\" y=\"" << R.getPoint().getPoint_y() <<"\" width=\"" << R.getHauteur() <<"\" height=\"" << R.getLargeur() <<"\" fill=\"" << R.getColor() << "\" transform=\"rotate("<< R.getRotate() <<","<< R.getPoint().getPoint_x()+ R.getHauteur()/2 << "," << R.getPoint().getPoint_y()+ R.getLargeur()/2 << ")\"/>" << endl;
		}else{
			fichier << "<rect x=\"" << R.getPoint().getPoint_x() <<"\" y=\"" << R.getPoint().getPoint_y() <<"\" width=\"" << R.getHauteur() <<"\" height=\"" << R.getLargeur() <<"\" fill=\"" << R.getColor() <<"\" />" << endl;
		}
		return fichier;
	}
	/*ostream& operator <<(const LineProperty L){//<line x1="20" y1="100" x2="100" y2="20"stroke-width="2" stroke="black"/>
		fichier << "<line x1=\""<< L.getPointA().getPoint_x() <<"\" y1=\""<< L.getPointA().getPoint_y() <<"\" x2=\""<< L.getPointB().getPoint_x() <<"\" y2=\""<< L.getPointB().getPoint_x() <<"\" stroke-width=\""<< L.getLargeur() <<"\" stroke=\""<<L.getColor()<<"\"/>" << endl;
		return fichier;
	}*/
};
//!FIN SVGSTREAM.H
//!DEBUT SVGSTREAM.CPP
	inline SVGstream::SVGstream(string nom,bool PureSvg=true):fichier(nom+".html",ios::out | ios::trunc){
		//~ string s = nom + ".html";
		//~ ofstream fichier(s, ios::out | ios::trunc); // ouverture en écriture avec effacement du fichier ouvert / OU LE CREER SI EXISTE // possible de placer dans chaine d'initialisation
		if(fichier){
			if(!PureSvg){fichier << "<!doctype html>" << endl; }
			fichier << "<svg width=\"1000\" height=\"1000\">" << endl ;
		}
	}
//!FIN SVGSTREAM.CPP
//!FIN TP3
//!DEBUT TP4

//!DEBUT POINTARRAY.H
class PointArray{//avec pointeur
	protected:
	 	size_t taille;
		static const size_t def = 3;
		Point* array;

	public:

	inline PointArray(size_t t);
	inline PointArray();
	inline PointArray(const PointArray &P);
	inline PointArray(const std::initializer_list<float> &list);
	inline PointArray(unsigned int nb_point, Point centre,float rayon, float s);

	~PointArray(){cout << "PointArray: Destructeur" << endl;delete [] array;}
	Point& operator[](const unsigned int &a){
		assert(taille < a);//attention il faut arreter l'execution
		return array[a];
	}
	inline void view();
	inline void translation(float a, float b);
	inline void rotate(float rotation);
	inline void scale(float s);
};
//!FIN POINTARRAY.H

//!DEBUT POINTARRAY.Cpp

	inline PointArray::PointArray(size_t t):taille(t),array(new Point[t]){cout<<"PtArray Ctaille "<<endl;}
	inline PointArray::PointArray():PointArray(def){}
	//J'avais oublié le constructeur par défaut, par conséquent l'allocation mémoire des 10 éléments du tableau ne s'est pas faite, d'ou le segmentation fault
	inline PointArray::	PointArray(const PointArray &P):PointArray(P.taille){
		//memcpy(array,P.array,def*sizeof(Point));On utilise pas memcpy ici c'est uniquement dans le cas d'un BITs (build in type)
		cout << "PointArray Cc" << endl;
		for(size_t i = 0 ; i< P.def ; i++){
			this->array[i] = P.array[i];
		}
	}
	//*******************monvecteur ?

	//*******************CONSTRUCTEUR A PARTIR DUNE LISTE DE POINT
	inline PointArray::PointArray(const std::initializer_list<float> &list):PointArray(list.size()/2){// Stratégie : On passe un nombre pair d'int et on les met dans un point qu'on va ranger au fur et a mesure dans le tableau
		//si le nombre passé est impair on fait quoi ?
		//~ cout << " PointArray : Cinittializer_list"<< endl ;
		//~ cout << "taille de tableau "<< list.size() << endl ;
		float* tableau_entier = new float[list.size()];//ou list list.size()
		Point P;
		size_t j=0;
		for(auto &i : list){// le prof veut faire comme ça mais j'ai pas compris, il veut qu'on fasse un tableau dynamique d'int en plus ?
			tableau_entier[j]=i;
			j++;
		}
		for(size_t k=0,j=0;j<list.size(); j=j+2,k++){
			P.setPoint_x(tableau_entier[j]);
			P.setPoint_y(tableau_entier[j+1]);
			this->array[k]=P;
			//cout << array[k] << endl;
		}

		//cout << array[i] << endl;//**********
		delete [] tableau_entier;
	}
	//*******************CONSTRUCTEUR A PARTIR  et à partir de: un nombre de points n, un centre c et une taille s qui
	//initialise une liste de n points régulièrement répartis sur un cercle de centre c et de rayon r (à savoir
	//les points Pi du PointsArray sont Pi(x,y) = c + r * ( cos[theta(i)], sin[theta(i)] ) où theta(i) =2.pi/n*i et i est dans {0,1,...,n-1}).
	inline PointArray::PointArray(unsigned int nb_point, Point centre,float rayon, float s):PointArray(nb_point){//********************CONVERSION*********************************************
		Point P;
		float teta;
		for(unsigned int i = 0 ; i < nb_point ; i++ ){
			teta = static_cast<float>(2.f*PI*i)/static_cast<float>(nb_point);
			P.setPoint_x( ( centre.getPoint_x()+rayon ) *cos(teta));//Comment regler le problème ?
			P.setPoint_y( ( centre.getPoint_y()+rayon ) *sin(teta));
			this->array[i] = P;
		}
	}
	inline void PointArray::view(){
		for(size_t i = 0 ; i < taille ; i++){
			cout << array[i] << endl;
		}
	}
	inline void PointArray::translation(float a, float b){
		float x,y;
		for(size_t i = 0; i < taille; i++){
			x=array[i].getPoint_x();
			y=array[i].getPoint_y();
			array[i].setPoint_x(x+a);
			array[i].setPoint_y(y+b);
		}
	}
	inline void PointArray::rotate(float rotation){
		float cx=0,
			cy=0;
		//CALCUL DU CENTRE :(Pour le barycentre ou centre de gravité on fait la moyenne des X et la moyenne des Y)
		for(size_t i = 0; i < taille; i++){
			cx=array[i].getPoint_x()+cx;
			cy=array[i].getPoint_y()+cy;
		}
		cx = cx/static_cast<float>(taille);
		cy = cy/static_cast<float>(taille);
		//CALCUL AVEC CENTRE (0,0)
		Point *tableau= new Point[taille];
		float x,y;
		for(size_t i = 0; i < taille; i++){
			x=array[i].getPoint_x();
			y=array[i].getPoint_y();
			tableau[i].setPoint_x(x*cosf(rotation)-y*cosf(rotation));//cosf() renvoit un float ça évite un static_cast en plus
			tableau[i].setPoint_y(x*cosf(rotation)+y*cosf(rotation));

		}
		//On met dans le tableau
		for(size_t i = 0; i < taille ; i++){
			array[i].setPoint_x(cx+tableau[i].getPoint_x()-cx);
			array[i].setPoint_y(cy+tableau[i].getPoint_y()-cx);
		}
		delete [] tableau;
	}
	inline void PointArray::scale(float s){// Scale avec un double serait préférable
		//Calcul du centre
		float cx = 0.f,
			cy = 0.f;
		for(size_t i = 0; i < taille; i++){
			cx=array[i].getPoint_x()+cx;
			cy=array[i].getPoint_y()+cy;
		}
		cx = cx/static_cast<float>(taille);
		cy = cy/static_cast<float>(taille);
		float x,y;
		for(size_t i = 0; i < taille; i++){
			x=array[i].getPoint_x();
			y=array[i].getPoint_y();
			array[i].setPoint_x(cx+s*(x-cx));
			array[i].setPoint_y(cy+s*(y-cy));
		}

	}
//!FIN POINTARRAY.CPP

//!DEBUT ReallocablePointsArray.h
class ReallocatablePointsArray : public PointArray{
	//Le prof m'a dit que ajouter un champ nombre d'element serait mieux. Pour l'assignation, un exemple R1.taille = 10 R2.taille = 3 si on fait R1 = R2 il va falloir delete un tableau de 10 pour en refaire un de trois alors qu'il y a assez de place pour lui mettre 3 element ! Allocation inutile (Pour un )!
	public:
		inline ReallocatablePointsArray();
		inline ReallocatablePointsArray(size_t taille);
		inline ReallocatablePointsArray(const ReallocatablePointsArray &R);
		inline ReallocatablePointsArray(unsigned int nb_point, Point centre,float rayon, float s);
		inline ReallocatablePointsArray(const std::initializer_list<float> &list);
		ReallocatablePointsArray& operator =(const ReallocatablePointsArray R){//Ici
			if(this!=&R){
				delete [] array;
				this->taille = R.taille;
				array = new Point[this->taille];
				memcpy(array,R.array,R.taille*sizeof(int));
				//~ for(size_t i = 0 ; i< R.taille ; i++){
					//~ this->array[i] = R.array[i];
				//~ }
			}
			return *this;
		}
};
//!FIN ReallocablePointsArray.h
//!DEBUT ReallocablePointsArray.cpp

	inline ReallocatablePointsArray::ReallocatablePointsArray():PointArray(){}
	inline ReallocatablePointsArray::ReallocatablePointsArray(size_t taille):PointArray(taille){}//constructeur délégué
	inline ReallocatablePointsArray::ReallocatablePointsArray(const ReallocatablePointsArray &R):PointArray(R.taille){cout << "ReallocablePointArray Cc" << endl;}
	inline ReallocatablePointsArray::ReallocatablePointsArray(unsigned int nb_point, Point centre,float rayon, float s):PointArray(nb_point,centre,rayon,s){}
	inline ReallocatablePointsArray::ReallocatablePointsArray(const std::initializer_list<float> &list):PointArray(list){}

//!FIN ReallocablePointsArray.h
//FIN TP4
int main(){
	Color a;
	Color c = Color::red;
	c.view();
	a.view();
	cout << a.getColor() << endl;
	SVGstream S("fichier",0);
	string chaine = "<circle cx=\"100\" cy=\"100\" r=\"75\" fill=\"red\"/>";
	S << chaine << endl;


	//Geom2D Classe abstraites
	/*Geom2D G;										G.info();
	Geom2D G1(1,2);									G1.info();
	*/
	//FillProperty
	FillProperty F;									F.info();
	FillProperty F1(c);								F1.info();
	FillProperty F2(Color::blue); 					F2.info();
	/*Classe abstraire
	Surface S1;										S1.info();
	Surface S2(500,200,Color::blue);				S2.info();
	*/
	//TEST sur objets concrets
	Disc D(600.6f,100,Color::blue,100);				D.info();
	Disc D2(900,100,Color::turquoise,200);			D2.info();
	D.info();
	S << D << endl;
	S << D2 << endl;
	Rectangle R(500,500,400,100,Color::brown);//Rectangle(int x, int y , int h , int l ,const Color& Couleur):Surface(x,y,Couleur),hauteur(h),largeur(l)
	S << R << endl;
	Square carr;
	Square carr2(100,200,50,Color::grey);
	carr2.Rotate(45);
	S << carr << endl;

	R.Translate(-100,-100);
	R.info();
	carr2.Translate(50,50);
	R.Scale(2);
	R.Rotate(45);
	S << R << endl;
	S << carr2 << endl;
	//*************************Ouverture écriture sur un fichier les test
	//~ string s = "test2.html";
	//~ ofstream fichier(s, ios::out | ios::trunc); // ouverture en écriture avec effacement du fichier ouvert / OU LE CREER SI EXISTE
	//~
	//~ if(fichier)
	//~ {
		//~ string nom = "Xav57";
		//~ int age = 19;
		//~ fichier << "Date de naissance : " << 24 << '/' << 3 << '/' << 1988 << endl;
		//~ fichier << "Bonjour, " << nom << ". Vous avez " << age << " ans.";
		//~ fichier.close();
	//~ }
	//~ else
		//~ cerr << "Impossible d'ouvrir le fichier !" << endl;

	//! TP4
		PointArray A;
	Point P(3,3);
	A[9]= P;
	A[0]=A[9];

	PointArray B(A);
	//Affiche A
	cout << "A :" << endl;
	A.view();
	//Affiche B
	cout << "B :" << endl;
	B.view();

	ReallocatablePointsArray Rarray(2);
	Rarray[1]=P;
	ReallocatablePointsArray Rarray2(Rarray);
	cout << "Reallocable" << endl;
	cout << "Rarray1" << endl;
	Rarray.view();
	cout << "Rarray2" << endl;
	Rarray2.view();
	cout << "Rarray3" << endl;
	ReallocatablePointsArray Rarray3;Rarray3.view();//taille = 10


	//test initializer_list
	auto lise = {1.f,2.f,3.f,4.f,5.f,6.f,7.f,8.f};
	PointArray Parray(lise);
	cout << "Parray" << endl;
	Parray.view();
	Point point(0,0);
	PointArray Parray2(2,point,10,0);//*******************************//PointArray(size_t nb_point, Point centre,size_t rayon, int s):PointArray(nb_point){
	cout << "Parray2" << endl;
	Parray2.view();
	ReallocatablePointsArray Rarray4(lise);//taille = 4
	cout << "Rarray4" << endl;
	Rarray4.view();
	cout << "Rarray4 avant" << endl;
	Rarray4.view();
	Rarray4=Rarray3;
	cout << "Rarray4 après" << endl;
	Rarray4.view();

	return 0;
	}
