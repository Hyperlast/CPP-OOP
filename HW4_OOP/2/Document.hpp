#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Object.hpp"
#include <stdexcept>

class Document : public Object{
private:
    std::vector<std::string> Doc_Info;
    unsigned Line = 1;

public:
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);

    Object* clone()const;

    bool operator==(const Comparable*)const;
    bool operator!=(const Comparable*)const;
    std::string debug_print()const;
    std::string to_string()const;
    void from_string(const std::string&); 
};