#ifndef _ARRAY_H
#define _ARRAY_H
#include <cstring>
#include <cassert>
#include <initializer_list>
#include <iostream>

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
			size_t i=0;
			for(const T &x : array.tab) tab[i++] = x;
		}
		Static<T, N> &operator=(const Static<T, N> &array) {
			if (&array != this)
			    for(size_t i=0;i<N;++i) tab[i] = array.tab[i];
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
        size_t	Size;
		T		*tab;
	public:
		using type = T;
		explicit Fixed(size_t n) : Size(n), tab(n == 0 ? nullptr : new T[n]) {}
		Fixed(const std::initializer_list<T> &list) : Fixed(list.size()) {
			size_t  i = 0;
			for (const T &p : list) tab[i++] = p;
		}
		Fixed(const Fixed<T> &array) : Fixed(array.Size) {
			for (size_t i = 0; i < Size; i++) tab[i] = array.tab[i];
		}
		Fixed<T> &operator=(const Fixed<T> &array) {
			assert(array.Size == Size);
			if (&array != this) 
				for (size_t i = 0; i < Size; i++) tab[i] = array.tab[i];
			return *this;
		}
		~Fixed() { delete[] tab; }
		size_t size() const { return Size; }
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
		using Fixed<T>::Size;
		using Fixed<T>::tab;
	public:
        using type = T;
        size_t size() { return Size; }
        size_t allocated() { return Allocated; }
		Dynamic() : Fixed<T>(0), Allocated(0) {}
		explicit Dynamic(size_t n) : Fixed<T>(n), Allocated(n) {}
		Dynamic(const std::initializer_list<T> &list) :
			Fixed<T>(list), Allocated(Size) {};
		Dynamic(const Dynamic<T> &array) : Fixed<T>(array), Allocated(array.Size) {}
		Dynamic<T> &operator=(const Dynamic<T> &array) {
			if (&array != this) {
				if (Allocated < array.Size) reserve(array.Size);
				for (size_t i = 0; i < Size; i++) tab[i] = array.tab[i];
                Size = array.Size;
			}
			return *this;
		}
        T& operator[](size_t i) {
		    assert(i<Size);
		    return tab[i];
		}
        const T& operator[](size_t i) const {
            assert(i<Size);
		    return tab[i];
		}
		void push_back(const T &p) {
			if (Size == Allocated) reserve(Allocated + AllocGranularity);
			tab[Size++] = p;
		}
		T pop_back() {
			assert(Size > 0);
			--Size;
			return tab[Size];
		}
		void reserve(size_t newsize) {
		    if (newsize < Allocated) return;
            T *tmp = new T[newsize];
            for (size_t i = 0; i < Size; i++) tmp[i] = tab[i];
            delete[] tab;
            tab = tmp;
            Allocated = newsize;
		}
	};

};
#endif