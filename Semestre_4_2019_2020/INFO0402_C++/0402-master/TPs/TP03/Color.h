#ifndef _COLOR_H
#define _COLOR_H
#include "SVGstream.h"
////////////////////////////////////////////////////////////////////////////////////////
class Color {
public:
	enum colortype : uint8_t { red = 0, white, yellow, orange,
		turquoise, violet, pink, green, grey, cyan, blue, brown };
private:
	static const size_t nColor = 12;
	static const char *name[];
	colortype  color;
public:
	inline Color(const colortype &c) : color(c) {}
	// Cc et Ac par défaut
	inline const char *getName() const { return name[color]; }
	inline void set(const colortype &c) { color = c; }
	friend inline std::ostream &operator<<(std::ostream &s, const Color &c) {
		return s << c.getName();
	}
	friend inline SVGstream& operator<<(SVGstream& s, const Color &c) {
		return s << c.getName();
	}
	// cette dernière surcharge est nécessaire
    // malgré la chaine d'héritage SVGstream -> ofstream -> ostream
    // car s << a << b << c; implique operator<<(operator<<(operator<<(s,a),b),c)
    // où tous les premiers arguments (s) sont du même type.
    // Or s'il est possible de construire un ostream à partir d'un SVGstream,
    // impossible de construire un SVGstream à partir d'un ostream.
    // SAUF si aucun chainage n'est jamais fait pour un SVGstream upcasté en ostream.
};

// A placer dans un fichier cpp en cas de compilation séparée.
// Déclaration externe pour le static (automatique si le type est entier)
const char *Color::name[nColor] = { "red", "white", "yellow", "orange", "turquoise",
					"violet", "pink", "green", "grey", "cyan", "blue", "brown" };
// noter l'ADL (argument dependant lookup) pour nColor: n'existe pas dans le contexte global,
// mais comme on définit un objet dans le namespace/class Color, inutile de préciser que
// l'argument est aussi dans ce contexte.
#endif
