#ifndef C_SET_H
#define C_SET_H

template<class Key,class Compare = std::less<Key>> class set {
public:
    set();
    explicit set( const Compare& comp );
    template< class InputIt > set( InputIt first, InputIt last);
    template< class InputIt > set( InputIt first, InputIt last, const Compare& comp = Compare());
    set( const set& other );
    set( set&& other );
    set( std::initializer_list<T> init )
    set( std::initializer_list<T> init, const Compare& comp = Compare());

    ~set();

    set& operator=( const set& other );
    set& operator=( set&& other );
    set& operator=( std::initializer_list<T> ilist );

    bool empty() const;
    size_t size() const;

    void clear();

    std::pair<iterator,bool> insert( const value_type& value );
    std::pair<iterator,bool> insert( value_type&& value );
    iterator insert( iterator hint, const value_type& value );
    iterator insert( iterator hint, value_type&& value );
    template< class InputIt > void insert( InputIt first, InputIt last );
    void insert( std::initializer_list<T> ilist );

    template< class... Args > std::pair<iterator,bool> emplace( Args&&... args );

    iterator erase( iterator pos );
    void erase( iterator first, iterator last );
    size_t erase( const key_type& key )

    void swap( set& other );

    size_t count( const Key& key ) const;

    iterator find( const Key& key );

    bool contains( const Key& key ) const;

    std::pair<iterator,iterator> equal_range( const Key& key );
    iterator lower_bound( const Key& key );
    iterator upper_bound( const Key& key );

    template< class Key, class Compare> friend bool operator==( const set<Key,Compare>& lhs, const set<Key,Compare>& rhs );
    template< class Key, class Compare> friend bool operator!=( const set<Key,Compare>& lhs, const set<Key,Compare>& rhs );
    template< class Key, class Compare> friend bool operator< ( const set<Key,Compare>& lhs, const set<Key,Compare>& rhs );
    template< class Key, class Compare> friend bool operator<=( const set<Key,Compare>& lhs, const set<Key,Compare>& rhs );
    template< class Key, class Compare> friend bool operator> ( const set<Key,Compare>& lhs, const set<Key,Compare>& rhs );
    template< class Key, class Compare> friend bool operator>=( const set<Key,Compare>& lhs, const set<Key,Compare>& rhs );

    class iterator {
    public:
        explicit iterator();
        iterator(const iterator&);
        iterator& operator++();
        iterator operator++(int);
        bool operator==(iterator other) const;
        bool operator!=(iterator other) const;
        T& operator*() const;
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
        // T& operator[](int n);
        // const T& operator[](int n) const;
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

template< class Key, class Compare>
void swap( set<Key,Compare>& lhs, set<Key,Compare>& rhs );

#endif //C_SET_H
