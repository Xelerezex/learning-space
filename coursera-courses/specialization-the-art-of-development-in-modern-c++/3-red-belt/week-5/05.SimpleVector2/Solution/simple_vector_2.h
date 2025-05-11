#include <cstdint>
#include <algorithm>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector
{

public:

    explicit SimpleVector() = default;
    explicit SimpleVector(size_t size);
    explicit SimpleVector(const SimpleVector& other);
    explicit SimpleVector(SimpleVector&& other) noexcept; // Конструктор перемещения

    SimpleVector& operator=(SimpleVector&& other) noexcept;
    void operator=(const SimpleVector& other);

    ~SimpleVector();


    T& operator[](size_t index);

    T* begin();
    T* end();
    const T* begin() const;
    const T* end()   const;


    size_t Size() const;
    size_t Capacity() const;
    void PushBack(T value);

    // При необходимости перегрузите
    // существующие публичные методы

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};


template<typename T>
SimpleVector<T>::SimpleVector(size_t size)
    : data(new T[size]),
      size(size),
      capacity(size)
{
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
    : data(new T[other.capacity]),
      size(other.size),
      capacity(other.capacity)
{
    copy(make_move_iterator(other.begin()),
         make_move_iterator(other.end()),
         begin()
    );
}


// Реализация перемещающего конструктора
template <typename T>
SimpleVector<T>::SimpleVector(SimpleVector&& other) noexcept
    : data(other.data)
    , size(other.size)
    , capacity(other.capacity)
{
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

// Реализация перемещающего оператора присваивания
template <typename T>
SimpleVector<T>& SimpleVector<T>::operator=(SimpleVector&& other) noexcept
{
    if (*this == other)
    {
        return *this;
    }

    delete[] data;
    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

template <typename T>
void SimpleVector<T>::operator=(const SimpleVector<T>& other)
{
    if (other.size <= capacity)
    {
        copy(make_move_iterator(other.begin()),
             make_move_iterator(other.end()),
             begin()
        );
        size = other.size;
    } else
    {
        // copy-&-swap paradigm
        SimpleVector<T> tmp(other);     // copy constructor
        swap(tmp.data, data);
        swap(tmp.size, size);
        swap(tmp.capacity, capacity);
    }
}

template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete[] data;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
size_t SimpleVector<T>::Size() const
{
    return size;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const
{
    return capacity;
}

template <typename T>
void SimpleVector<T>::PushBack(T value)
{
    if (size >= capacity)
    {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        copy(make_move_iterator(begin()),
             make_move_iterator(end()),
             new_data
        );
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
    data[size++] = move(value);
}

template <typename T>
T* SimpleVector<T>::begin()
{
    return data;
}

template <typename T>
const T* SimpleVector<T>::begin() const
{
    return data;
}

template <typename T>
T* SimpleVector<T>::end()
{
    return data + size;
}

template <typename T>
const T* SimpleVector<T>::end() const
{
    return data + size;
}
