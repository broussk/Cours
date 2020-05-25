//
// Created by pasc 2/3/20.
//

#ifndef C_DEQUE_H
#define C_DEQUE_H

template <class T> deque {
public:
    // ne pas toucher
    using value_type = T;
    using size_type = size_t;

    // à implémenter
    deque();
    explicit deque( size_type count );
    deque( size_type count, const T& value );
    template< class InputIt > deque( InputIt first, InputIt last);
    deque( const deque& other );
    deque( deque&& other );
    deque( std::initializer_list<T> init );
    ~deque();

    deque& operator=( const deque& other );
    deque& operator=( deque&& other );
    deque& operator=( std::initializer_list<T> ilist );

    void assign( size_type count, const T& value );
    template< class InputIt > void assign( InputIt first, InputIt last );
    void assign( std::initializer_list<T> ilist );

    T& at( size_type pos );
    const T& at( size_type pos ) const;

    T& operator[]( size_type pos );
    const T& operator[]( size_type pos ) const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    bool empty() const;

    size_t size() const;

    void clear();

    iterator insert( iterator pos, const T& value );
    iterator insert( iterator pos, T&& value );
    void insert( iterator pos, size_type count, const T& value );
    template< class InputIt > void insert( iterator pos, InputIt first, InputIt last);
    iterator insert( const_iterator pos, std::initializer_list<T> ilist );

    template< class... Args > iterator emplace( const_iterator pos, Args&&... args );

    iterator erase( iterator pos );
    iterator erase( iterator first, iterator last );

    void push_back( const T& value );
    void push_back( T&& value );

    template< class... Args > void emplace_back( Args&&... args );

    void pop_back();

    void push_front( const T& value );
    void push_front( T&& value );

    template< class... Args > void emplace_front( Args&&... args );

    void pop_front();

    void resize( size_type count );
    void resize( size_type count, const value_type& value );

    void swap( deque& other );

    template< class U> friend bool operator==( const deque<U>& lhs, const deque<U>& rhs );
    template< class U> friend bool operator!=( const deque<U>& lhs, const deque<U>& rhs );
    template< class U> friend bool operator<(  const deque<U>& lhs, const deque<U>& rhs );
    template< class U> friend bool operator<=( const deque<U>& lhs, const deque<U>& rhs );
    template< class U> friend bool operator>(  const deque<U>& lhs, const deque<U>& rhs );
    template< class U> friend bool operator>=( const deque<U>& lhs, const deque<U>& rhs );

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

template<class T> void swap( deque<T> &lhs, deque<T> &rhs );

#endif //C_DEQUE_H