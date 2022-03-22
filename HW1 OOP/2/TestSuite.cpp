#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
{
    this->Suitename = name;
}

void TestSuite::add(const TestCase& Cass)
{
    Cases.push_back(Cass);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
    std::vector<TestCase> Passing;
    for (unsigned int i = 0; i < Cases.size(); ++i)
    {
        if ((Cases[i].getErrorType() == ErrorType::None) || (Cases[i].getErrorType() == ErrorType::Warning))
        {
            Passing.push_back(Cases[i]);
        }
    }
    return Passing;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
    std::vector<TestCase> Failing;
    for(unsigned int i=0;i<Cases.size();++i)
    {
        if ((Cases[i].getErrorType() == ErrorType::BuildFailed) || (Cases[i].getErrorType() == ErrorType::FailedAssertion))
        {
            Failing.push_back(Cases[i]);
        }
    }
    return Failing;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType Err) const
{
    std::vector<TestCase> FilteredCases;
    for (unsigned int i = 0; i < Cases.size(); ++i)
    {
        if (Cases[i].getErrorType() == Err)
        {
            FilteredCases.push_back(Cases[i]);
        }
    }
    return FilteredCases;
}

void TestSuite::removeByErrorType(ErrorType R)
{
    for (unsigned int i = 0; i < this->Cases.size(); ++i)
    {
        if (Cases[i].getErrorType() == R)
        {
            Cases.erase(Cases.begin()+i);
        }
    }
}

std::string TestSuite::getName() const
{
    return this->Suitename;
}

void TestSuite::setName(const std::string& name)
{
    this->Suitename = name;
}
