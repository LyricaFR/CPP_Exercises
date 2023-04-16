#pragma once
#include <memory>

namespace uge {

// Put your code for class unique_ptr here !
template <typename T>
class unique_ptr
{
public:
    unique_ptr()
        : _value { nullptr }
    {}

    unique_ptr(T* value)
        : _value { value }
    {}

    unique_ptr(const unique_ptr<T>& other)
    {
        if (other.get() != nullptr)
            _value = new T { *(other._value) };
        else
            _value = nullptr;
    }

    unique_ptr(unique_ptr<T>&& other)
        : _value { other._value }
    {
        other._value = nullptr;
    }

    unique_ptr<T>& operator=(unique_ptr<T>&& other)
    {
        if (this != &other)
        {
            _value       = other._value;
            other._value = nullptr;
        }
        return *this;
    }

    bool operator!=(unique_ptr<T>&& other)
    {
        if (_value != other.get)
        {
            return true;
        }
        return false;
    }

    T* get() const { return _value; }

    T& operator*() { return *_value; }

    ~unique_ptr() { delete _value; }

private:
    T* _value;
};
} // namespace uge