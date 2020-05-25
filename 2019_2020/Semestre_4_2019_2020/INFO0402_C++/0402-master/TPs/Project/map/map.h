#ifndef C_MAP_H
#define C_MAP_H

template<class Key, class T, class Compare = std::less<Key>> class map {
public:
    // ne pas toucher
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const K>;
    using key_compare = Comp
    // à implémenter
    map();
    explicit map( const Compare& comp );
    template< class InputIt > map(InputIt first, InputIt last, const Compare& comp = Compare());
    map( const map& other );
    map( map&& other );
    map( std::initializer_list<value_type> init, const Compare& comp = Compare());
    ~map();

    map& operator=( const map& other );
    map& operator=( map&& other );
    map& operator=( std::initializer_list<T> ilist );

    T& at( const Key& key );
    const T& at( const Key& key ) const;

    T& operator[]( const Key& key );
    T& operator[]( Key&& key );

    bool empty() const;

    size_t size() const;

    void clear();

    std::pair<iterator,bool> insert( const T& value );
    std::pair<iterator,bool> insert( T&& value );
    iterator insert( iterator hint, const T& value );
    iterator insert( iterator hint, T&& value );
    template< class InputIt > void insert( InputIt first, InputIt last );
    void insert( std::initializer_list<T> ilist );

    template< class... Args > std::pair<iterator,bool> emplace( Args&&... args );

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

    template< class Key, class T, class Compare> friend bool operator==( const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs );
    template< class Key, class T, class Compare> friend bool operator!=( const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs );
    template< class Key, class T, class Compare> friend bool operator< ( const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs );
    template< class Key, class T, class Compare> friend bool operator<=( const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs );
    template< class Key, class T, class Compare> friend bool operator> ( const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs );
    template< class Key, class T, class Compare> friend bool operator>=( const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs );

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

template< class Key, class T, class Compare> void swap( map<Key,T,Compare>& lhs, map<Key,T,Compare>& rhs );

#endif //C_MAP_H
