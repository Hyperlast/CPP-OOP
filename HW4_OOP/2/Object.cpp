#include "Object.hpp"

Object::Object(const std::string& name, const std::string& location, const std::string& extension) : name(name), location(location),extension(extension)
{
}

std::string Object::get_name() const
{
    return this->name;
}

std::string Object::get_location() const
{
    return this->location;
}

std::string Object::get_extension() const
{
    return this->extension;
}

std::string Object::get_fullpath() const
{
    //<location>/<name>.<extension> 
    return (this->location + '/' + this->name + '.' + this->extension);
}

bool Object::operator==(const Comparable*) const
{
    return false;
}

bool Object::operator!=(const Comparable*) const
{
    return false;
}

std::string Object::debug_print() const
{
    return std::string();
}

std::string Object::to_string() const
{
    return std::string();
}

void Object::from_string(const std::string& from)
{
}
