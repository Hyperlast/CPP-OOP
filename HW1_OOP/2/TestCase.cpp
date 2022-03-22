#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error)
{
    this->CaseError.set_Message(error.getMessage());
    this->CaseError.set_Type(error);
    this->CaseName = name;
}

std::string TestCase::getName() const
{
    return this->CaseName;
}

bool TestCase::isPassing() const
{
    if ((this->CaseError.getType() == ErrorType::BuildFailed) || (this->CaseError.getType() == ErrorType::FailedAssertion))
    {
        return false;
    }
    return true;
}

bool TestCase::hasError() const
{
    if (this->CaseError.getType() == ErrorType::None)
    {
        return false;
    }
    return true;
}

ErrorType TestCase::getErrorType() const
{
    return this->CaseError.getType();
}

std::string TestCase::getErrorMessage() const
{
    std::string s(this->CaseError.getMessage());
    return s;
}
