#ifndef _ARRAY_H
#define _ARRAY_H
#include <cstring>
#include <cassert>
#include <initializer_list>
#include <iostream>

namespace Array {
	template <class T, size_t N> class Static {
	protected:
		T    Data[N];
	public:
		using type = T;
		Static() {};
		Static(const std::initializer_list<T> &list) {
			assert(list.size() <= N);
            for(size_t i=0;i<list.size();++i) Data[i] = list[i];
		}
		Static(const Static<T, N> &array) {
            for(size_t i=0;i<N;++i) Data[i] = array.Data[i];
		}
        Static(Static<T, N> &&array) {
            for(size_t i=0;i<N;++i) Data[i] = std::move(array.Data[i]);
        }
		Static<T, N> &operator=(const Static<T, N> &array) {
			if (&array != this)
			    for(size_t i=0;i<N;++i) Data[i] = array.Data[i];
			return *this;
		}
        Static<T, N> &operator=(Static<T, N> &&array) {
            for(size_t i=0;i<N;++i) Data[i] = std::move(array.Data[i]);
            return *this;
        }
		size_t size() const { return N; }
		T& operator[](size_t i) { return Data[i]; }
		const T& operator[](size_t i) const { return Data[i]; }
		friend std::ostream& operator<<(std::ostream &stream, const Static<T,N> &array) {
			if (array.size() > 0) {
				stream << array.Data[0];
				for (size_t i = 1; i < array.size(); i++) stream << " " << array.Data[i];
			} 
			return stream;
		}
		template <class U, size_t M> friend bool operator==(const Static<U,M> &x1, const Static<U,M> &x2) {
		    if (&x1 == &x2) return true;
            for (size_t i = 1; i < M; i++) if (x1.Data[i] != x2.Data[i]) return false;
            return true;
		}
	};

	template <class T> class Fixed {
	protected:
        size_t	Size;
		T		*Data;
	public:
        size_t size() const { return Size; }
		using type = T;
		explicit Fixed(size_t n) : Size(n), Data(n == 0 ? nullptr : new T[n]) {}
		Fixed(const std::initializer_list<T> &list) : Fixed(list.size()) {
            for(size_t i=0;i<list.size();++i) Data[i] = list[i];
		}
		Fixed(const Fixed<T> &array) : Fixed(array.Size) {
			for (size_t i = 0; i < Size; i++) Data[i] = array.Data[i];
		}
        Fixed(Fixed<T> &&array) : Size(array.Size), Data(array.Data) {
		    array.Size = 0;
		    array.Data = nullptr;
        }
		Fixed<T> &operator=(const Fixed<T> &array) {
			assert(array.Size == Size);
			if (&array != this) 
				for (size_t i = 0; i < Size; i++) Data[i] = array.Data[i];
			return *this;
		}
        Fixed<T> &operator=(Fixed<T> &&array) {
		    swap(*this,array);
            return *this;
        }
		~Fixed() { delete[] Data; }
		T& operator[](size_t i) { return Data[i]; }
		const T& operator[](size_t i) const { return Data[i]; }
		friend std::ostream& operator<<(std::ostream &stream, const Fixed<T> &array) {
			if (array.size() > 0) {
				stream << array.Data[0];
				for (size_t i = 1; i < array.size(); i++) stream << " " << array.Data[i];
			}
			return stream;
		}
		friend inline void swap(Fixed &x1, Fixed &x2) {
            std::swap(x1.Size,x2.Size);
            std::swap(x1.Data,x2.Data);
		}
        template <class U> friend bool operator==(const Fixed<U> &x1, const Fixed<U> &x2) {
            if (&x1 == &x2) return true;
            if (x1.Size != x2.Size) return false;
            if (x1.Data == x2.Data) return false; // si pointe vers la même chose: les tableaux sont corrompus
            for (size_t i = 1; i < x1.Size; i++) if (x1.Data[i] != x2.Data[i]) return false;
            return true;
        }
	};

	template <class T> class Dynamic {
	protected:
		static const size_t     DefaultAllocSize = 8;
		static const size_t     AllocGranularity = 8;
        T		                *Data;
		std::size_t				Size,Allocated;
        void allocate(size_t n) {
            Data = reinterpret_cast<T*>(:: operator new(n * sizeof(T)));
            Allocated = n;
        }
        void destroy() {
            for (size_t i = 0; i < Size; i++) Data[i].~T();
            Size = 0;
        }
	public:
        using type = T;
        size_t size() const { return Size; }
        size_t allocated() const { return Allocated; }
		Dynamic() : Size(0), Data(nullptr), Allocated(0) {}
		explicit Dynamic(size_t n) : Size(0) { allocate(n); }
		Dynamic(const std::initializer_list<T> &list) : Dynamic(list.size()) {
            for(size_t i=0;i<list.size();++i)
                new(&Data[i]) T(list[i]);
            Size = list.size();
		}
        Dynamic(const Dynamic<T> &array) : Dynamic(array.size()) {
            for(size_t i=0;i<array.size();++i)
                new(&Data[i]) T(array.Data[i]);
            Size = array.size();
		}
        Dynamic(Dynamic<T> &&array) : Data(array.Data), Size(array.Size), Allocated(array.Allocated) {
            array.Size = array.Allocated = 0;
            array.Data = nullptr;
        }
		~Dynamic() {
            destroy();
            ::operator delete(Data);
            Size = Allocated = 0;
		}
		Dynamic<T> &operator=(const Dynamic<T> &array) {
			if (&array != this) {
				if (Allocated < array.Size) {
				    destroy();
				    ::operator delete(Data);
				    allocate(array.Size);
				}
                if (Size < array.Size) {
                    for (size_t i = 0; i < Size; i++) Data[i] = array.Data[i];
                    for (size_t i = Size; i < array.Size; i++) new(&Data[i]) T(array.Data[i]);
                } else {
                    for (size_t i = 0; i < array.Size; i++) Data[i] = array.Data[i];
                    for (size_t i = array.Size; i < Size; i++) Data[i].~T();
                }
                Size = array.Size;
			}
			return *this;
		}
        Dynamic<T> &operator=(Dynamic<T> &&array) {
            swap(*this,array);
            return *this;
        }
        void reserve(size_t alloc) {
            if (alloc < Allocated) return;
            T  *tmp = Data;
            allocate(alloc);
            for(size_t i=0;i<Size;++i) Data[i] = std::move(tmp[i]);
            ::operator delete(tmp);
        }
        T& operator[](size_t i) {
		    assert(i<Size);
		    return Data[i];
		}
        const T& operator[](size_t i) const {
            assert(i<Size);
		    return Data[i];
		}
		void push_back(const T &p) {
			if (Size == Allocated) reserve(Allocated + AllocGranularity);
			Data[Size++] = p;
		}
        void push_back(T &&p) {
            if (Size == Allocated) reserve(Allocated + AllocGranularity);
            Data[Size++] = std::move(p);
        }
		T&& pop_back() {
            if (Size == 0) {
                static T dummy;
                return std::move(dummy);
            } else {
                --Size;
                return std::move(Data[Size]);
            }
		}
        friend inline void swap(Dynamic &x1, Dynamic &x2) {
            std::swap(x1.Data,x2.Data);
            std::swap(x1.Size,x2.Size);
            std::swap(x1.Allocated,x2.Allocated);
        }
        template <class U> friend bool operator==(const Dynamic<U> &x1, const Dynamic<U> &x2) {
            if (&x1 == &x2) return true;
            if (x1.Size != x2.Size) return false;
            if (x1.Data == x2.Data) return false; // si pointe vers la même chose: les tableaux sont corrompus
            for (size_t i = 1; i < x1.Size; i++) if (x1.Data[i] != x2.Data[i]) return false;
            return true;
        }
	};

};
#endif