#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const T&)const;
    bool operator==(const Error&) const;

private:
    Optional<T> Res;
    Optional<Error> ResError;
};

template<typename T>
Result<T>::Result()
{
    this->Res = T();
    this->ResError = Error();
}

template<typename T>
Result<T>::Result(const T& result)
{
    this->Res = result;
}
template<typename T>
Result<T>::Result(const std::string& error_message)
{
    Optional<Error> temp(error_message);
    this->ResError = temp;
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
    return this->Res.get_value();
}
template<typename T>
Optional<Error> Result<T>::get_error() const
{ 
    return this->ResError.get_value();
}

template<typename T>
bool Result<T>::operator==(const T&) const
{
    if (this->Res.is_none())
    {
        return false;
    }
    
    if (this->Res.getType() == Type::ResultType)
    {
        return true;
    }

    return false;
}
template<typename T>
bool Result<T>::operator==(const Error&) const
{
    if (this->ResError.is_none())
    {
        return false;
    }

    if (this->ResError.getType() == Type::ErrorType)
    {
        return true;
    }

    return false;
}
