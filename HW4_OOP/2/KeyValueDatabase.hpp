#pragma once
#include "Object.hpp"
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
class KeyValueDatabase : public Object {
private:
    std::vector<std::pair<std::string, int>> Entries;
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    Object* clone()const;

    bool operator==(const Comparable*)const;
    bool operator!=(const Comparable*)const;
    std::string debug_print()const;
    std::string to_string()const;
    void from_string(const std::string&);

};