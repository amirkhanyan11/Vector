#ifndef _VECTOR_
#define _VECTOR_
#include <iostream>

namespace juju
{

    template <class vector>
    class const_vector_iterator;

    // Iterator
    template <typename vector>
    class vector_iterator
    {

    public:

        using valueType = typename vector::valueType;
        using pointerType = valueType*;
        using referenceType = valueType&;

    public:

        friend std::ostream& operator<<(std::ostream& os, const vector_iterator<vector>& it)
        {
            return (os << *it);
        }
        friend class juju::const_vector_iterator<vector>;
        vector_iterator() = default;
        vector_iterator(const vector_iterator&) = default;
        vector_iterator(pointerType);
                
    public:

        vector_iterator& operator++() noexcept;
        vector_iterator operator++(int) noexcept;
        vector_iterator& operator--() noexcept;
        vector_iterator operator--(int) noexcept;
        referenceType operator*() const;
        bool operator==(const vector_iterator& other) const;
        bool operator!=(const vector_iterator& other) const;

    private:
        pointerType m_ptr = nullptr;
    };

    // Const Iterator
    template <class vector>
    class const_vector_iterator
    {

    public:

        friend std::ostream& operator<<(std::ostream& os, const const_vector_iterator<vector>& it)
        {
            return (os << *it);
        }
        using valueType = typename vector::valueType;
        using pointerType = valueType*;
        using referenceType = valueType&;

    public:
        const_vector_iterator() = default;
        const_vector_iterator(const pointerType);
        const_vector_iterator(const vector_iterator<vector>& other) : m_ptr{other.m_ptr} {};
        const_vector_iterator(const const_vector_iterator& other) = default;
        const_vector_iterator& operator++() noexcept;
        const_vector_iterator operator++(int) noexcept;
        const_vector_iterator& operator--() noexcept;
        const_vector_iterator operator--(int) noexcept;
        const_vector_iterator& operator=(const const_vector_iterator<vector>& other);
        const_vector_iterator& operator=(const vector_iterator<vector>& other);
        const referenceType operator*() const;
        bool operator==(const const_vector_iterator& other) const;
        bool operator!=(const const_vector_iterator& other) const;
        
    private:
        const pointerType m_ptr = nullptr;
    };


    // Vector
    template <typename T>
    class vector
    {

    public:

        using valueType = T;
        using iterator = vector_iterator<vector<T>>;
        using const_iterator = const_vector_iterator<vector<T>>;

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
        T& operator[](const size_t);
        vector<T>& operator+=(const vector<T> other);


    public:

        const T& at(const size_t) const;
        T& at(const size_t);

        size_t size() const;
        size_t capacity() const;
        void push_back(const T);
        void shrink_to_fit();
        bool empty() const;
        void reserve(const int);
    
        T& front() const;
        T& back() const;



    public:

        iterator begin() const noexcept;
        iterator end() const noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;


    private:

        size_t m_size = 0;
        size_t m_capacity = 0;
        int* m_arr = nullptr;

        void _resize();
    };

}

template class juju::vector<int>;

#include "vector.hpp"

#endif