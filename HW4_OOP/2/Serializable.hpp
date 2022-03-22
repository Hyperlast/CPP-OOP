#pragma once
#include <string>
class Serializable {
public:
	virtual std::string to_string()const = 0;
	virtual void from_string(const std::string&) = 0;
	virtual ~Serializable() = default;
};