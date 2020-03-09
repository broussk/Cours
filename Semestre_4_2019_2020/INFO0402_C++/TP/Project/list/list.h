
template<typename T> class list {
public:
    // ne pas toucher
    using value_type = T;

    // à implémenter
    list(); //

    explicit list(size_t count);            //
    list(size_t count, const T& value );    //

    template<typename InputIt > list( InputIt first, InputIt last);

    list( const list& other );  //
    list( list&& other );       //

    list( std::initializer_list<T> init );

    ~list();

    list& operator=( const list& other );   //
    list& operator=( list&& other );        //

    void assign( size_t count, const T& value );   //
    template<typename InputIt > void assign( InputIt first, InputIt last );  //

    T& front();     //
    T& back();      //

    const T& back() const;  //
    const T& front() const; //

    bool empty() const;     //
    size_t size() const;    //
    void clear();           //

    iterator insert( const_iterator pos, const T& value );  //
    iterator insert( const_iterator pos, T&& value );
    iterator insert( const_iterator pos, size_t count, const T& value );           //
    template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );  //
    iterator insert( const_iterator pos, std::initializer_list<T> ilist );
    template< class... Args > iterator emplace( const_iterator pos, Args&&... args );

    iterator erase( const_iterator pos );
    iterator erase( const_iterator first, const_iterator last );
    template< class... Args > iterator emplace( const_iterator pos, Args&&... args );

    void resize( size_t count );                    //
    void resize( size_t count, const T& value);     //

    void push_back( const T& value );     //
    void push_front( const T& value );    //

    void push_back( T&& value );          //
    void push_front( T&& value );         //

    template< class... Args > void emplace_back( Args&&... args );
    template< class... Args > void emplace_front( Args&&... args );

    void pop_back();    //
    void pop_front();   //

    void merge( list& other );
    void merge( list&& other );
    void splice(const_iterator pos, list& other);
    void splice(const_iterator pos, list&& other);
    void remove( const T& value );
    void reverse();

    friend bool operator==<>( list& lhs, list& rhs );
    friend bool operator!=<>( list& lhs, list& rhs );
    friend bool operator< <>( list& lhs, list& rhs );
    friend bool operator<=<>( list& lhs, list& rhs );
    friend bool operator> <>( list& lhs, list& rhs );
    friend bool operator>=<>( list& lhs, list& rhs );

    void swap( list& other );

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

template<class T> void swap( list<T> &lhs, list<T> &rhs );
