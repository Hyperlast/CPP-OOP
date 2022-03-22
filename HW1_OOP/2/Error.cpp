#include "Error.hpp"
#include "cstring"
int my_strlen(const char* str)
{
    unsigned int i = 0;
    for (; str[i] != '\0'; ++i);
    return i;
}
bool Error::hasMessage() const
{
    if (this->Type == ErrorType::None)
    {
        return false;
    }
    return true;
}


void Error::set_Type(const Error& r )
{
    this->Type = r.getType();
}

const char* Error::getMessage() const
{
    if (this->Type == ErrorType::None)
    {
        return nullptr;
    }

    return this->ErrorMessage;
}

void Error::set_Message(const char* s)
{
    delete[] ErrorMessage;
    if (s == nullptr)
    {
        ErrorMessage = new char[1];
        ErrorMessage[0] = '\0';
    }
    else
    {
        ErrorMessage = new char[my_strlen(s) + 1];
        strcpy_s(this->ErrorMessage, my_strlen(s) + 1, s);
    }
}

ErrorType Error::getType() const
{
    return this->Type;
}

Error Error::newNone()
{   
    Error NoneError;
    NoneError.Type=ErrorType::None;
    NoneError.ErrorMessage=nullptr;
    return NoneError;
}

Error Error::newBuildFailed(const char* message)
{
    Error BFailed;
    BFailed.Type = ErrorType::BuildFailed;
    BFailed.ErrorMessage = new char[my_strlen(message) + 1];
    strcpy_s(BFailed.ErrorMessage, my_strlen(message) + 1, message);
    return BFailed;
}

Error Error::newWarning(const char* message)
{
    Error Warn;
    Warn.Type = ErrorType::Warning;
    Warn.ErrorMessage = new char[my_strlen(message) + 1];
    strcpy_s(Warn.ErrorMessage, my_strlen(message) + 1, message);
    return Warn;
}

Error Error::newFailedAssertion(const char* message)
{
    Error FAssertion;
    FAssertion.Type = ErrorType::FailedAssertion;
    FAssertion.ErrorMessage = new char[my_strlen(message)+1];
    strcpy_s(FAssertion.ErrorMessage, my_strlen(message) + 1, message);
    return FAssertion;
}

Error::Error()
{
    this->Type = ErrorType::None;
    this->ErrorMessage = new char[1];
    ErrorMessage[0] = '\0';
}

Error::Error(const Error& Copy)
{
    this->Type = Copy.Type;
    if (Copy.ErrorMessage == nullptr)
    {
        ErrorMessage = new char[1];
        ErrorMessage[0] = '\0';
    }
    else
    {
        ErrorMessage = new char[my_strlen(Copy.ErrorMessage) + 1];
        strcpy_s(this->ErrorMessage, my_strlen(Copy.ErrorMessage) + 1, Copy.ErrorMessage);
    }

}

Error& Error::operator=(const Error& rhs)
{
    if (this != &rhs)
    {
        delete[] ErrorMessage;
        this->Type = rhs.Type;
        ErrorMessage = new char[my_strlen(rhs.ErrorMessage) + 1];
        strcpy_s(this->ErrorMessage, my_strlen(rhs.ErrorMessage) + 1, rhs.ErrorMessage);
    }
    return *this;
}

Error::~Error()
{
    delete[] ErrorMessage;
}






