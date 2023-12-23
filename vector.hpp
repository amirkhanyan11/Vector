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

        class iterator
        {

        public:

            iterator() = delete;
            iterator(T*);
            iterator(const iterator& other) = default;
            
        public:

            // friend std::ostream& operator<< (std::ostream&, const typename vector<T>::iterator&);
            
            iterator& operator++();
            iterator operator++(int);

        public:
            T* m_ptr;
        };


        iterator begin();
        iterator end();

    private:

        size_t m_size = 0;
        size_t m_capacity = 0;
        int* m_arr = nullptr;

        void _resize();
    };

}


#endif