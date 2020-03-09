#ifndef C_SET_INT_H
#define C_SET_INT_H
#include <functional>
#include <initializer_list>

class set {
public:
    // ne pas toucher
    using Compare = std::less<int>;
    class iterator;

    // prototype
    set();
    explicit set( const Compare& comp );
    template< class InputIt > set( InputIt first, InputIt last);
    template< class InputIt > set( InputIt first, InputIt last, const Compare& comp = Compare());
    set( const set& other );
    set( set&& other );
    set( std::initializer_list<int> init );
    set( std::initializer_list<int> init, const Compare& comp = Compare());

    ~set();

    set& operator=( const set& other );
    set& operator=( set&& other );
    set& operator=( std::initializer_list<int> ilist );

    bool empty() const;
    size_t size() const;

    void clear();

    std::pair<iterator,bool> insert( const int& value );
    std::pair<iterator,bool> insert( int&& value );
    iterator insert( iterator hint, const int& value );
    iterator insert( iterator hint, int&& value );
    template< class InputIt > void insert( InputIt first, InputIt last );
    void insert( std::initializer_list<int> ilist );


    iterator erase( iterator pos );
    void erase( iterator first, iterator last );
    size_t erase( const int& key );

    void swap( set& other );

    size_t count( const int& key ) const;

    iterator find( const int& key );

    bool contains( const int& key ) const;

    std::pair<iterator,iterator> equal_range( const int& key );
    iterator lower_bound( const int& key );
    iterator upper_bound( const int& key );

    friend bool operator==( const set& lhs, const set& rhs );
    friend bool operator!=( const set& lhs, const set& rhs );
    friend bool operator< ( const set& lhs, const set& rhs );
    friend bool operator<=( const set& lhs, const set& rhs );
    friend bool operator> ( const set& lhs, const set& rhs );
    friend bool operator>=( const set& lhs, const set& rhs );

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

void swap( set& lhs, set& rhs );

#endif //C_SET_H
