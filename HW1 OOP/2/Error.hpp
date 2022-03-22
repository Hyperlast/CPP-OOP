#pragma once
#include <iostream>

/// ErrorType represents all the different types of errors one might have
/// including the `None` error, which signifies absense of an error.
enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

/// Error represents a potential test error
/// It has a type and an optional message
class Error {
    /// Feel free to add additional private/public methods/fields
private:
    ErrorType Type;
    char* ErrorMessage;

public:
    Error();
    Error(const Error&);
    Error& operator=(const Error&);
    /// Check if the error has a message
    bool hasMessage() const;
    
    void set_Type(const Error&);
    /// Retrieve the message of an error if such exists,
    /// otherwise return the only "safe" invalid pointer :)
    const char* getMessage() const;

    void set_Message(const char*);
    /// Retrieve the type of the error
    ErrorType getType() const;

    /// Create a new error of type None with no message
    /// We will be creating new Errors only via the 4 methods below
    static Error newNone();

    /// Create a new error of type BuildFailed with a message
    static Error newBuildFailed(const char* message);

    /// Create a new error of type Warning with a message
    static Error newWarning(const char* message);

    /// Create a new error of type FailedAssertion with a message
    static Error newFailedAssertion(const char* message);  
    ~Error(); 

}; 
int my_strlen(const char* str);