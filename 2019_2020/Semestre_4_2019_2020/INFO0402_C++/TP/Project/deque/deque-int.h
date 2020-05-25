#ifndef C_DEQUE_INT_H
#define C_DEQUE_INT_H
#include <functional>
#include <initializer_list>

class deque {
public:
    // ne pas toucher
    using value_type = int;
    using size_type = size_t;
    class iterator;
    class const_iterator;

    // à implémenter
    deque();
    explicit deque( size_type count );
    deque( size_type count, const int& value );
    template< class InputIt > deque( InputIt first, InputIt last);
    deque( const deque& other );
    deque( deque&& other );
    deque( std::initializer_list<int> init );
    ~deque();

    deque& operator=( const deque& other );
    deque& operator=( deque&& other );
    deque& operator=( std::initializer_list<int> ilist );

    void assign( size_type count, const int& value );
    template< class InputIt > void assign( InputIt first, InputIt last );
    void assign( std::initializer_list<int> ilist );

    int& at( size_type pos );
    const int& at( size_type pos ) const;

    int& operator[]( size_type pos );
    const int& operator[]( size_type pos ) const;

    int& front();
    const int& front() const;

    int& back();
    const int& back() const;

    bool empty() const;

    size_t size() const;

    void clear();

    iterator insert( iterator pos, const int& value );
    iterator insert( iterator pos, int&& value );
    void insert( iterator pos, size_type count, const int& value );
    template< class InputIt > void insert( iterator pos, InputIt first, InputIt last);
    iterator insert( const_iterator pos, std::initializer_list<int> ilist );

    iterator erase( iterator pos );
    iterator erase( iterator first, iterator last );

    void push_back( const int& value );
    void push_back( int&& value );

    void pop_back();

    void push_front( const int& value );
    void push_front( int&& value );

    void pop_front();

    void resize( size_type count );
    void resize( size_type count, const value_type& value );

    void swap( deque& other );

    friend bool operator==( const deque& lhs, const deque& rhs );
    friend bool operator!=( const deque& lhs, const deque& rhs );
    friend bool operator<(  const deque& lhs, const deque& rhs );
    friend bool operator<=( const deque& lhs, const deque& rhs );
    friend bool operator>(  const deque& lhs, const deque& rhs );
    friend bool operator>=( const deque& lhs, const deque& rhs );

        class iterator {
        public:
            explicit iterator();
            iterator(const iterator&);
            iterator& operator++();
            iterator operator++(int);
            bool operator==(iterator other) const;
            bool operator!=(iterator other) const;
            int& operator*() const;
            //// birectionnel
            // iterator& operator--();
            // iterator operator--(int);
            //// random access
            // bool operator<(const iterator&)  const;
            // bool operator<=(const iterator&) const;
            // bool operator>(const iterator&)  const;
            // bool operator>=(const iterator&) const;
            // iterator& operator+=(const int n)
            // iterator& operator-=(const int n)
            // int& operator[](int n);
            // const int& operator[](int n) const;
        };
        iterator begin();  //
        iterator end();    //

        class const_iterator {};
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        class reverse_iterator {};
        reverse_iterator rbegin(); //
        reverse_iterator rend();   //

        class const_reverse_iterator {};
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;


};

void swap( deque &lhs, deque &rhs );

#endif //C_DEQUE_H
