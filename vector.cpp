#include "vector.hpp"
using namespace juju;

template class vector<int>;


template <typename T>
size_t vector<T>::size() const
{
    return m_size;
}

template <typename T>
size_t vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
const T& vector<T>::at(const size_t index) const
{
    if(index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    return m_arr[index];
}

template <typename T>
T& vector<T>::at(const size_t index)
{
    return const_cast<T&>(static_cast<const vector<T>&>(*this).at(index));
}


// Overloaded operators


template <typename T>
const T& vector<T>::operator[](const size_t index) const
{
    return this->at(index);
}

template <typename T>
T& vector<T>::operator[](const size_t index)
{
    
    return const_cast<T&>(static_cast<const vector<T>&>(*this)[index]);
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other)
{
    if (this == &other)
        return *this;

    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;

    delete[] m_arr;

    this->m_arr = new T[m_capacity];

    for (int i = 0; i < m_size; i++)
    {
        m_arr[i] = other.at(i);
    }

    return *this;
}



template <typename T>
vector<T>& vector<T>::operator+=(const vector<T> other)
{
    this->reserve(this->m_size + other.m_size);

    for(int i = 0; i < other.m_size; i++)
    {
        m_arr[m_size + i] = other.at(i);
    }

    m_size += other.m_size;
    
    return *this;
}





template <typename T>
void vector<T>::_resize()
{
    m_capacity = (m_size + 1) * 2;

    T* tmp = new T[m_capacity];

    for (int i = 0; i < m_size; i++)
    {
        tmp[i] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = tmp;

}


template <typename T>
void vector<T>::push_back(const T element)
{
    if(m_size == m_capacity)
        _resize();
    m_arr[m_size++] = element; 
}


template <typename T>
void vector<T>::shrink_to_fit()
{
    m_capacity = m_size;
}


template <typename T>
bool vector<T>::empty() const
{
    return (m_size == 0);
}


template <typename T>
void vector<T>::reserve(const int n)
{
    if (m_capacity < n)
        m_capacity = n;
}


template <typename T>
T& vector<T>::front() const
{
    return m_arr[0];
}

template <typename T>
T& vector<T>::back() const
{
    return m_arr[m_size - 1];
}






// Iterator functions




template <typename T>
typename vector<T>::iterator vector<T>::begin() const noexcept
{
    return vector<T>::iterator(m_arr);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() const noexcept
{
    return vector<T>::iterator(m_arr + m_size);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const noexcept
{
    return vector<T>::const_iterator(m_arr);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const noexcept
{
    return vector<T>::const_iterator(m_arr + m_size);
}



// Iterator Ctors

template <typename T>
vector<T>::iterator::iterator(T* ptr) : m_ptr{ptr} {};


template <typename T>
vector<T>::iterator::iterator(const vector<T>& vec)
{
    this->m_ptr = vec.begin().m_ptr;

}


template <typename T>
T& vector<T>::iterator::operator*() const
{
    return *m_ptr;
}

template <typename T>
bool vector<T>::iterator::operator==(const vector<T>::iterator& other) const
{
    return (this->m_ptr == other.m_ptr);
}

template <typename T>
bool vector<T>::iterator::operator!=(const vector<T>::iterator& other) const
{
    return (this->m_ptr != other.m_ptr);
}



template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator++() noexcept
{
    ++m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator++(int) noexcept
{
    iterator tmp = *this;
    ++m_ptr;
    return tmp;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator--() noexcept
{
    --m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator--(int) noexcept
{
    iterator tmp = *this;
    --m_ptr;
    return tmp;
}



// Const iterator


template <typename T>
vector<T>::const_iterator::const_iterator(const T* ptr) : m_ptr{ptr} {}


// template <typename T>
// vector<T>::const_iterator::const_iterator(const vector<T>::iterator& other) : m_ptr{other.m_ptr} {}


template <typename T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator=(const iterator& other)
{
    this->m_ptr = other.m_ptr;
    return *this;
}


template <typename T>
const T& vector<T>::const_iterator::operator*() const
{
    return *m_ptr;
}

template <typename T>
bool vector<T>::const_iterator::operator==(const vector<T>::const_iterator& other) const
{
    return (this->m_ptr == other.m_ptr);
}

template <typename T>
bool vector<T>::const_iterator::operator!=(const vector<T>::const_iterator& other) const
{
    return (this->m_ptr != other.m_ptr);
}


template <typename T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator++() noexcept
{
    ++m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator++(int) noexcept
{
    const_iterator tmp = *this;
    ++m_ptr;
    return tmp;
}


template <typename T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator--() noexcept
{
    --m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator--(int) noexcept
{
    const_iterator tmp = *this;
    --m_ptr;
    return tmp;
}


// Constructors & Destructor


// Copy ctor
template <typename T>
vector<T>::vector(const vector& other)
{
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->m_arr = new T[m_capacity];

    for (int i = 0; i < m_size; i++)
    {
        m_arr[i] = other.at(i);
    }

}

// Move ctor
template <typename T>
vector<T>::vector(vector&& other)
{
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->m_arr = other.m_arr;
    other.m_arr = nullptr;
}

// initializer list ctor
template <typename T>
vector<T>::vector(std::initializer_list<T> values)
{
    m_capacity = values.size();
    m_arr = new T[m_capacity];

    for (auto i : values)
    {
        this->push_back(i);
    }
}


template <typename T>
vector<T>::~vector()
{
    delete[] m_arr;
    m_arr = nullptr;
}