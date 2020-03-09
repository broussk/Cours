#ifndef C_MAP_INT_H
#define C_MAP_INT_H
#include <functional>
#include <initializer_list>

class map {
public:
    // pour l'exemple
    using Key = int;
    using T = int;
    class iterator;
    class const_iterator;

    // ne pas toucher
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using key_compare = std::less<Key>;

    // à implémenter
    map();
    template< class InputIt > map(InputIt first, InputIt last);
    map( const map& other );
    map( map&& other );
    map( std::initializer_list<value_type> init);
    ~map();

    map& operator=( const map& other );
    map& operator=( map&& other );
    map& operator=( std::initializer_list<value_type> ilist );

    mapped_type& at( const Key& key );
    const mapped_type& at( const Key& key ) const;

    mapped_type& operator[]( const Key& key );
    mapped_type& operator[]( Key&& key );

    bool empty() const;

    size_t size() const;

    void clear();

    std::pair<iterator,bool> insert( const value_type& value );
    std::pair<iterator,bool> insert( value_type&& value );
    iterator insert( iterator hint, const value_type& value );
    iterator insert( iterator hint, value_type&& value );
    template< class InputIt > void insert( InputIt first, InputIt last );
    void insert( std::initializer_list<value_type> ilist );

    void erase( iterator pos );
    void erase( iterator first, iterator last );
    size_t erase( const key_type& key );

    void swap( map& other );

    size_t count( const Key& key ) const;

    iterator find( const Key& key );
    const_iterator find( const Key& key ) const;

    bool contains( const Key& key ) const;

    std::pair<iterator,iterator> equal_range( const Key& key );
    iterator lower_bound( const Key& key );
    iterator upper_bound( const Key& key );

    friend bool operator==( const map& lhs, const map& rhs );
    friend bool operator!=( const map& lhs, const map& rhs );
    friend bool operator< ( const map& lhs, const map& rhs );
    friend bool operator<=( const map& lhs, const map& rhs );
    friend bool operator> ( const map& lhs, const map& rhs );
    friend bool operator>=( const map& lhs, const map& rhs );

    class iterator {
    public:
        explicit iterator();
        iterator(const iterator&);
        iterator& operator++();
        iterator operator++(int);
        bool operator==(iterator other) const;
        bool operator!=(iterator other) const;
        value_type& operator*() const;
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

void swap( map& lhs, map& rhs );

#endif //C_MAP_H
