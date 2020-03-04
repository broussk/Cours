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
    set( std::initializer_list<int> init )
    set( std::initializer_list<int> init, const Compare& comp = Compare());

    ~set();

    set& operator=( const set& other );
    set& operator=( set&& other );
    set& operator=( std::initializer_list<int> ilist );

    bool empty() const;
    size_t size() const;

    void clear();

    std::pair<iterator,bool> insert( const value_type& value );
    std::pair<iterator,bool> insert( value_type&& value );
    iterator insert( iterator hint, const value_type& value );
    iterator insert( iterator hint, value_type&& value );
    template< class InputIt > void insert( InputIt first, InputIt last );
    void insert( std::initializer_list<int> ilist );


    iterator erase( iterator pos );
    void erase( iterator first, iterator last );
    size_type erase( const key_type& key )

    void swap( set& other );

    size_t count( const Key& key ) const;

    iterator find( const Key& key );

    bool contains( const Key& key ) const;

    std::pair<iterator,iterator> equal_range( const Key& key );
    iterator lower_bound( const Key& key );
    iterator upper_bound( const Key& key );

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
