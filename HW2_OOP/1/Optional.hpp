#pragma once
#include "Error.hpp"
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too
enum class Type
{
    ResultType,
    ErrorType,
};

template <typename T>

class Optional {
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;
    Type getType()const;

private:
    T obj;
    Type objType;
};

template<typename T>
Optional<T>::Optional()
{
    this->obj = T();
    this->objType = Type::ResultType;
}
template<>
Optional<Error>::Optional()
{
    this->obj = Error();
    this->objType = Type::ErrorType;
}

template<typename T>
Optional<T>::Optional(const T& value)
{
    this->obj = value;
    this->objType = Type::ResultType;
}

template<>
Optional<Error>::Optional(const Error& value)
{
    this->obj = value;
    this->objType = Type::ErrorType;
}

template<typename T>
bool Optional<T>::is_none() const
{
    if (this-> obj == T())
    {
        return true;
    }
    return false;
}

template<>
bool Optional<Error>::is_none() const
{
    if (this->obj.get_message() == Error().get_message())
    {
        return true;
    }
    return false;
}

template<typename T>
T Optional<T>::get_value() const
{ 
    return this->obj;
}

template<typename T>
Type Optional<T>::getType() const
{
    return this->objType;
}