#ifndef _ARRAY_H
#define _ARRAY_H
#include <iostream>
#include <cstring>
#include "SVG.h"

namespace Array {
	template <class T, size_t N> class Static {
	protected:
		T    tab[N];
	public:
		using type = T;
		Static() {};
		Static(const std::initializer_list<T> &list) {
			assert(list.size() <= N);
			size_t  i = 0;
			for (const T &p : list) tab[i++] = p;
		}
		Static(const Static<T, N> &array) {
			// memcpy(tab, array.tab, N*sizeof(T)); // non: faire une copie
			size_t i=0;
			for(const T &x : array.tab) tab[i++] = x;
		}
		Static<T, N> &operator=(const Static<T, N> &array) {
			if (&array != this) memcpy(tab, array.tab, N*sizeof(T));
			return *this;
		}
		size_t size() const { return N; }
		T& operator[](size_t i) { return tab[i]; }
		const T& operator[](size_t i) const { return tab[i]; }
		friend std::ostream& operator<<(std::ostream &stream, const Static<T,N> &array) {
			if (array.size() > 0) {
				stream << array.tab[0];
				for (size_t i = 1; i < array.size(); i++) stream << " " << array.tab[i];
			}
			return stream;
		}
	};

	template <class T> class Fixed {
	protected:
        size_t	len;
		T		*tab;
	public:
		using type = T;
		explicit Fixed(size_t n) : len(n), tab(n == 0 ? nullptr : new T[n]) {}
		Fixed(const std::initializer_list<T> &list) : Fixed(list.size()) {
			size_t  i = 0;
			for (const T &p : list) tab[i++] = p;
		}
		Fixed(const Fixed<T> &array) : Fixed(array.len) {
			for (size_t i = 0; i < len; i++) tab[i] = array.tab[i];
			// if (len > 0) memcpy(tab, array.tab, len*sizeof(T));
		}
		Fixed<T> &operator=(const Fixed<T> &array) {
			assert(array.len == len);
			if (&array != this)
				for (size_t i = 0; i < len; i++) tab[i] = array.tab[i];
			// memcpy(tab, array.tab, len*sizeof(T));
			return *this;
		}
		~Fixed() { if (tab) delete[] tab; }
		size_t size() const { return len; }
		T& operator[](size_t i) { return tab[i]; }
		const T& operator[](size_t i) const { return tab[i]; }
		friend std::ostream& operator<<(std::ostream &stream, const Fixed<T> &array) {
			if (array.size() > 0) {
				stream << array.tab[0];
				for (size_t i = 1; i < array.size(); i++) stream << " " << array.tab[i];
			}
			return stream;
		}
	};

	template <class T> class Dynamic : public Fixed<T> {
	protected:
		static const size_t     DefaultAllocSize = 8;
		static const size_t     AllocGranularity = 8;
		std::size_t				Allocated;
		void realloc(std::size_t newsize) {
			assert(newsize > Allocated);
			T *tmp = new T[newsize];
			for (size_t i = 0; i < len; i++) tmp[i] = tab[i];
			delete[] tab;
			tab = tmp;
			Allocated = newsize;
		}
		using Fixed<T>::len;
		using Fixed<T>::tab;
	public:
        using type = T;
		Dynamic() : Fixed<T>(0), Allocated(0) {}
		explicit Dynamic(size_t n) : Fixed<T>(n), Allocated(n) {}
		Dynamic(const std::initializer_list<T> &list) :
			Fixed<T>(list), Allocated(len) {};
		Dynamic(const Dynamic<T> &array) : Dynamic(array.len) {
			for (size_t i = 0; i < len; i++) tab[i] = array.tab[i];
		}
		Dynamic<T> &operator=(const Fixed<T> &array) {
			if (&array != this) {
				if (Allocated < array.len) realloc(array.len);
				for (size_t i = 0; i < len; i++) tab[i] = array.tab[i];
				len = array.len;
			}
			return *this;
		}
		void Add(const T &p) {
			if (len == Allocated) realloc(Allocated + AllocGranularity);
			tab[len++] = p;
		}
		void Remove(size_t pos) {
			assert(pos < len);
			if (pos < len - 1)
				for (size_t i = pos; i < len-1; i++) tab[i] = tab[i+1];
			// std::memmove(tab + pos, tab + pos + 1, (len - pos - 1));
			--len;
		}
	};

	namespace Geometry {

		template <class T> typename T::type Center(const T &array) {
			assert(array.size() != 0);
			typename T::type center = array[0];
			for (size_t i = 1; i < array.size(); i++) center += array[i];
			center /= float(array.size());
			return center;
		}

		template <class T> void Translate(T &array, const typename T::type &vector) {
			if (array.size() == 0) return;
            for (size_t i = 0; i < array.size(); i++) array[i].translate(vector);
		}

		template <class T> void Scale(T &array, float scaling) {
			if (array.size() == 0) return;
			typename T::type  center = Center(array);
			for (size_t i = 0; i < array.size(); i++) array[i].scale(center, scaling);
		}

		template <class T> void Rotate(T &array, float angle) {
			if (array.size() == 0) return;
			typename T::type  center = Center(array);
			for (size_t i = 0; i < array.size(); i++) array[i].rotate(center,angle);
		}

		template <class T> void FillnGon(T &array, const typename T::type &center, float radius) {
			if (array.size() == 0) return;
			float angle = 2.f * 3.1416f / float(array.size());
			for (size_t i = 0; i < array.size(); i++) array[i].polar(radius,float(i)*angle,center);
		}
	}

	namespace SVG {
		template <class T> void output(::SVG::stream &stream, const T &array) {
			if (array.size() == 0) return;
			stream << array[0];
			for (size_t i = 1; i < array.size(); i++) stream << " " << array[i];
		}
	}

};
#endif
