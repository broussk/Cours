#include <cassert>
#include "GeomBase.h"

// mot-clé pour l'initialisation
Default	defaut;
None	none;
Empty	empty;

////////////////////////////////////////////////////////////////////////////////////////
// classe de base de Color
const char *Color::name[] = { "red", "white", "yellow", "orange", "turquoise",
						"violet", "pink", "green", "grey", "cyan", "blue", "brown", "none" };
const Color::colortype Color::defaut;

namespace Geom2D {
	////////////////////////////////////////////////////////////////////////////////////////
	// classe de base de Geom2D
	Base::~Base() = default;

}
