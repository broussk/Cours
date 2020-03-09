#include <cstdio>
#include <cassert>
#include <iostream>
#include <iomanip>
class Minute;
class Hour;

class Second { //  assert(v < 60);
private:
	static const size_t spm = 60;
	size_t  s;
public:
	Second() : s(0) {}
	Second(size_t v) : s(v) {}
	Second(const Second &S) : s(S.s%spm) {};
	size_t get() const { return s; }
	void set(size_t v) { s = v; }
	friend std::ostream& operator<< (std::ostream& stream, const Second& S) {
		return stream << S.s << "s";
	}
	friend bool operator==(const Second& s1, const Second& s2) { return (s1.s == s2.s);	}
	friend bool operator<(const Second& s1, const Second& s2) { return (s1.s < s2.s); }
};

class Minute {
private:
	static const size_t spm = 60;
	static const size_t mph = 60;
	size_t  m;
public:
	Minute() : m(0) {}
	Minute(size_t v) : m(v) {}
	Minute(const Second &S) : m((S.get()/spm)%mph) {};
	Minute(const Minute &M) : m(M.m % mph) {};
	size_t get() const { return m; }
	Second seconds() const { return m * spm; }
	void set(size_t v) { m = v; }
	friend std::ostream& operator<< (std::ostream& stream, const Minute& M) {
		return stream << M.m << "m";
	}
	friend bool operator==(const Minute& m1, const Minute& m2) { return (m1.m == m2.m);	}
	friend bool operator<(const Minute& m1, const Minute& m2) { return (m1.m < m2.m); }
};

class Hour {
private:
	static const size_t mph = 60;
	static const size_t spm = 60;
	size_t  h;
public:
	Hour() : h(0) {}
	Hour(size_t v) : h(v) {}
	Hour(const Second &v) : h(v.get()/(spm*mph)) {}
	Hour(const Minute &v) : h(v.get()/mph) {}
	Hour(const Hour &v) : h(v.h) {}
	size_t get() const { return h; }
	Minute minutes() const { return h * mph; }
	void set(size_t v) { h = v; }
	friend std::ostream& operator<< (std::ostream& stream, const Hour& H) {
		return stream << H.h << "h";
	}
	friend bool operator==(const Hour& h1, const Hour& h2) { return (h1.h == h2.h);	}
	friend bool operator<(const Hour& h1, const Hour& h2) { return (h1.h < h2.h); }
};

class Time {
private:
	Second s;
	Minute m;
	Hour   h;
public:
	Time() : h(0), m(0), s(0) {}
	Time(size_t u, size_t v, size_t w) : h(u), m(v), s(w) {}
	Time(const Second &v) : s(v), m(v), h(v) {}
	Time(const Minute &v) : s(0), m(v), h(v) {}
	Time(const Hour &v) : s(0), m(0), h(v) {}
	Time(const Time &v) : s(v.s), m(v.m), h(v.m) {}	
	Second seconds() const { return s.get() + m.seconds().get() + h.minutes().seconds().get();  }
	Minute minutes() const { return m.get() + h.minutes().get(); }
	Hour hours() const { return h;  }
	friend std::ostream& operator<< (std::ostream& stream, const Time& t) {
		return stream << t.h << t.m << t.s;
	}
	friend bool operator==(const Time& t1, const Time& t2) {
		return (t1.h == t2.h) && (t1.m == t2.m) && (t1.s == t2.s);
	}
	friend bool operator<(const Time &t1, const Time &t2) {
		if (t1.h < t2.h) return true;
		else if (t2.h < t1.h) return false;
		else if (t1.m < t2.m) return true;
		else if (t2.m < t1.m) return false;
		else if (t1.s < t2.s) return true;
		else return false;
	}
	friend Time operator-(const Time &t1, const Time &t2) {
		size_t  x1 = t1.seconds().get(), x2 = t2.seconds().get();
		return Time(Second(x1 < x2 ? x2 - x1 : x1 - x2));
	}
};

int main() {
	Hour h(4);
	Time t1(4, 9, 4), t2(7, 5, 7);
	std::cout << t1 << " " << t2 << std::endl;
	Time dt = t2 - t1;
	std::cout << dt << std::endl;
	getchar();
}
