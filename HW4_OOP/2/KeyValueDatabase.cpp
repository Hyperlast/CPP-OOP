#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension):Object(name,location,extension)
{
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
    for (unsigned int i = 0; i < this->Entries.size(); ++i)
    {
        if (Entries[i].first == entry.first)
        {
            throw std::invalid_argument("Entry is already in the Database!");
        }
    }
    this->Entries.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
    for (unsigned int i = 0; i < this->Entries.size(); ++i)
    {
        if (Entries[i].first == key)
        {
            return Entries[i].second;
        }
    }
    throw std::invalid_argument("Key not logged in the Database!");
}

Object* KeyValueDatabase::clone() const
{
    return new KeyValueDatabase(*this);
}

bool KeyValueDatabase::operator==(const Comparable* RHS) const
{
    const KeyValueDatabase* Keyptr = dynamic_cast<const KeyValueDatabase* >(RHS);
    if (Keyptr)
    {
        if (this->Entries.size() != Keyptr->Entries.size())
        {
            return false;
        }

        for (unsigned int i = 0; i < this->Entries.size(); ++i)
        {
            if (this->Entries[i] != Keyptr->Entries[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool KeyValueDatabase::operator!=(const Comparable* RHS) const
{
    const KeyValueDatabase* Keyptr = dynamic_cast<const KeyValueDatabase*>(RHS);
    if (Keyptr)
    {
        if (this->Entries.size() != Keyptr->Entries.size())
        {
            return true;
        }

        for (unsigned int i = 0; i < this->Entries.size(); ++i)
        {
            if (this->Entries[i] != Keyptr->Entries[i])
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

std::string KeyValueDatabase::debug_print() const
{
    std::string temp;
    for (unsigned int i = 0; i < Entries.size(); ++i)
    {
        temp += "{";
        temp += Entries[i].first;
        temp += ':';
        temp += std::to_string(Entries[i].second);
        temp += "}";
        temp += '\n';
    }
    return temp;
}

std::string KeyValueDatabase::to_string() const
{
    std::string Key;
    Key += this->name;
    Key += "\n";
    Key += this->location;
    Key += "\n";
    Key += this->extension;
    Key += "\n";
    for (unsigned int i = 0; i < this->Entries.size(); ++i)
    {
        Key += Entries[i].first;
        Key += ":";
        Key += std::to_string(Entries[i].second);
        Key += "\n";
    }
    return Key;
}

void KeyValueDatabase::from_string(const std::string& Des)
{
    this->Entries.clear();
    std::string Name;
    std::string Loc;
    std::string Ext;
    int counter = 0;
    int counter2 = 0;
    int Second = 0;
    std::string temp;  
    std::pair<std::string, int> TempPair;
    for (unsigned int i = 0; i < Des.size(); ++i)
    {
        if (counter > 2 && counter2 == 1 && Des[i] != '\n' && Des[i] != ':')
        {
            Second = (10 * Second + (Des[i] - '0'));
        }

        if (counter > 2 && counter2 == 0 && Des[i] != '\n'&& Des[i]!=':')
        {
            temp += Des[i];
        }

        if (counter > 2 && Des[i] == ':')
        {
            counter2 = 1;
            TempPair.first = temp;
            temp = "";
        }

        if (counter > 2 && counter2 == 1 && Des[i] == '\n' && Des[i]!= ':')
        {
            counter2 = 0;
            TempPair.second = Second;
            this->Entries.push_back(TempPair);
            Second = 0;
        }

        if (Des[i] == '\n')
        {
            counter++;
        }

        if (counter == 0 && Des[i] != '\n')
        {
            Name += Des[i];
        }

        if (counter == 1 && Des[i] != '\n')
        {
            Loc += Des[i];
        }

        if (counter == 2 && Des[i] != '\n')
        {
            Ext += Des[i];
        }
    }
    this->name = Name;
    this->location = Loc;
    this->extension = Ext;
}
