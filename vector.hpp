#ifndef _VECTOR_
#define _VECTOR_
#include <iostream>

namespace juju
{

    // Iterator
    template <class vector>
    class vector_iterator
    {

    public:

        using valueType = class vector::valueType;
        using pointerType = valueType*;
        using referenceType = valueType&;

    public:

        friend class const_vector_iterator;
        vector_iterator() = default;
        vector_iterator(pointerType);
        vector_iterator(const vector_iterator&) = default;
                
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

        using valueType = class vector::valueType;
        using pointerType = valueType*;
        using referenceType = valueType&;

    public:
        const_vector_iterator() = default;
        const_vector_iterator(const pointerType);
        const_vector_iterator(const vector_iterator& other) : m_ptr{other.m_ptr} {};
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
        const T* m_ptr = nullptr;
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

        // Iterators

        //class iterator;
        //class const_iterator;

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




    // template <typename T>
    // class vector<T>::iterator
    // {

    // public:

    //     friend class const_iterator;
    //     iterator() = default;
    //     iterator(T*);
    //     iterator(const iterator&) = default;
    //     iterator(const vector<T>&);
        
    // public:

    //     iterator& operator++() noexcept;
    //     iterator operator++(int) noexcept;
    //     iterator& operator--() noexcept;
    //     iterator operator--(int) noexcept;
    //     T& operator*() const;
    //     bool operator==(const iterator& other) const;
    //     bool operator!=(const iterator& other) const;

    // private:
    //     T* m_ptr = nullptr;
    // };



    // template <typename T>
    // class vector<T>::const_iterator
    // {

    // public:
    //     const_iterator() = default;
    //     const_iterator(const T*);
    //     const_iterator(const vector<T>::iterator& other) : m_ptr{other.m_ptr} {};
    //     const_iterator(const const_iterator& other) = default;
    //     const_iterator& operator++() noexcept;
    //     const_iterator operator++(int) noexcept;
    //     const_iterator& operator--() noexcept;
    //     const_iterator operator--(int) noexcept;
    //     const_iterator& operator=(const iterator& other);
    //     const T& operator*() const;
    //     bool operator==(const const_iterator& other) const;
    //     bool operator!=(const const_iterator& other) const;
        
    // private:
    //     const T* m_ptr = nullptr;
    // };

}


#endif