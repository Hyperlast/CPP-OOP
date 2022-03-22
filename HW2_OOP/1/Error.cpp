#include "Error.hpp"

Error::Error(const std::string& message)
{
    this->ErrorMessage = message;
}

std::string Error::get_message() const
{
    return this->ErrorMessage;
}