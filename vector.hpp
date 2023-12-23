#ifndef _VECTOR_
#define _VECTOR_
#include <iostream>

namespace juju
{

    template <typename T>
    class vector
    {

    public:

        vector() = default;
        vector(const vector& other);
        vector(vector&& other);
        vector(std::initializer_list<T>);
        ~vector();


    public:

        // Overloaded operators

        vector<T>& operator=(const vector<T>& other);
        const T& operator[](const size_t) const;
        vector<T>& operator+=(const vector<T> other);


    public:

        size_t size() const;
        size_t capacity() const;
        const T& at(const size_t) const;
        void push_back(const T);
        void shrink_to_fit();
        bool empty() const;
        void reserve(const int);
    
        T& front() const;
        T& back() const;



    public:

        // Iterators

        class iterator;
        class const_iterator;

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;


    private:

        size_t m_size = 0;
        size_t m_capacity = 0;
        int* m_arr = nullptr;

        void _resize();
    };




    template <typename T>
    class vector<T>::iterator
    {

    public:

        friend class const_iterator;
        iterator() = default;
        iterator(T*);
        iterator(const iterator& other) = default;
        
    public:

        iterator& operator++();
        iterator operator++(int);
        T& operator*() const;
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;

    private:
        T* m_ptr = nullptr;
    };



    template <typename T>
    class vector<T>::const_iterator
    {

    public:
        const_iterator() = default;
        const_iterator(const T*);
        const_iterator(const vector<T>::iterator& other) : m_ptr{other.m_ptr} {};
        const_iterator(const const_iterator& other) = default;
        const_iterator& operator++();
        const_iterator operator++(int);
        const T& operator*() const;
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
        
    private:
        const T* m_ptr = nullptr;
    };

}


#endif