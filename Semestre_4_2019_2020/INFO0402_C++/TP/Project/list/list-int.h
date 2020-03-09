#ifndef C_LIST_INT_H
#define C_LIST_INT_H
#include <functional>
#include <initializer_list>

class list {
public:
    // ne pas toucher
    using value_type = int;
    class iterator;
    class const_iterator;

    // à implémenter
    list(); //

    explicit list(size_t count);            //
    list(size_t count, const int& value );    //

    template<typename InputIt > list( InputIt first, InputIt last);

    list( const list& other );  //
    list( list&& other );       //

    list( std::initializer_list<int> init );

    ~list();

    list& operator=( const list& other );   //
    list& operator=( list&& other );        //

    void assign( size_t count, const int& value );   //
    template<typename InputIt > void assign( InputIt first, InputIt last );  //

    int& front();     //
    int& back();      //

    const int& back() const;  //
    const int& front() const; //

    bool empty() const;     //
    size_t size() const;    //
    void clear();           //

    iterator insert( const_iterator pos, const int& value );  //
    iterator insert( const_iterator pos, int&& value );
    iterator insert( const_iterator pos, size_t count, const int& value );           //
    template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );  //
    iterator insert( const_iterator pos, std::initializer_list<int> ilist );

    iterator erase( const_iterator pos );
    iterator erase( const_iterator first, const_iterator last );

    void resize( size_t count );                    //
    void resize( size_t count, const int& value);     //

    void push_back( const int& value );     //
    void push_front( const int& value );    //

    void push_back( int&& value );          //
    void push_front( int&& value );         //

    void pop_back();    //
    void pop_front();   //

    void merge( list& other );
    void merge( list&& other );
    void splice(const_iterator pos, list& other);
    void splice(const_iterator pos, list&& other);
    void remove( const int& value );
    void reverse();

    friend bool operator==( list& lhs, list& rhs );
    friend bool operator!=( list& lhs, list& rhs );
    friend bool operator< ( list& lhs, list& rhs );
    friend bool operator<=( list& lhs, list& rhs );
    friend bool operator> ( list& lhs, list& rhs );
    friend bool operator>=( list& lhs, list& rhs );

    void swap( list& other );

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

void swap( list &lhs, list &rhs );

#endif
