// ObjectPool.h
#pragma once
#include <vector>
#include <type_traits>

template <typename T>
class ObjectPool
{
public:
    ObjectPool(size_t size);
    ~ObjectPool();

    T& acquire();
    void release(T& elem);

    inline size_t size() const { return elements.size(); };
    size_t available() const { return elements.size() - nInUse; }

    inline bool isFull() const { return available() <= 0; };
    void clear();

    void resize(const std::vector<T>& elems);

private:
    std::vector<T> elements;
    std::vector<bool> useVec;
    size_t nInUse;
};

template<typename T>
inline ObjectPool<T>::ObjectPool(size_t size) : elements(size), useVec(size, false), nInUse(0) {}

template<typename T>
ObjectPool<T>::~ObjectPool() { clear(); }

template<typename T>
T& ObjectPool<T>::acquire()
{
    for (size_t i = 0; i < useVec.size(); ++i) {
        if (!useVec[i]) {
            useVec[i] = true;
            nInUse++;
            return elements[i];
        }
    }
    return *(T*)nullptr; // <-- cuidado, esto es un puntero nulo si T es puntero
}

template<typename T>
void ObjectPool<T>::release(T& elem)
{
    for (size_t i = 0; i < elements.size(); ++i) {
        if (&elements[i] == &elem) {
            useVec[i] = false;
            nInUse--;
            return;
        }
    }
}

template<typename T>
void ObjectPool<T>::clear()
{
    if constexpr (std::is_pointer_v<T>) {
        for (size_t i = 0; i < elements.size(); ++i) {
            if (elements[i]) {
                delete elements[i];
                elements[i] = nullptr;
            }
        }
    }
    elements.clear();
}

template<typename T>
inline void ObjectPool<T>::resize(const std::vector<T>& elems)
{
    elements = elems;
    //elements.resize(elems.size());
    //std::move(elems.cbegin(), elems.cend(), elements);

    if (useVec.size() != elements.size())
        useVec.resize(elements.size(), false);
}
