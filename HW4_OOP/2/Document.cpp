#include "Document.hpp"

Document::Document(const std::string& name, const std::string& location, const std::string& extension) : Object(name,location,extension)
{
}

void Document::write_line(const std::string& line)
{
    this->Doc_Info.push_back(line);
}

std::string Document::read_line()
{
    if (this->Doc_Info.size() < Line)
    {
        throw std::out_of_range("The end of the doc has been reached!");
    }
    this->Line++;
    return this->Doc_Info[Line-2];
}

std::string Document::read_line(const unsigned line)
{
    if ((this->Doc_Info.size() < line) || line<1)
    {
        throw std::out_of_range("This line is not available for reading(out of doc range)!");
    }
    this->Line = line+1;
    return this->Doc_Info[line-1];
}

Object* Document::clone() const
{
    return new Document(*this);
}

bool Document::operator==(const Comparable* RHS) const
{
    const Document* DocPTR = dynamic_cast<const Document*>(RHS);
    if (DocPTR)
    {
        if (DocPTR->Doc_Info.size() != this->Doc_Info.size())
        {
            return false;
        }
        for (unsigned int i = 0; i < this->Doc_Info.size(); ++i)
        {
            if (DocPTR->Doc_Info[i] != this->Doc_Info[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Document::operator!=(const Comparable* RHS) const
{
    const Document* DocPTR = dynamic_cast<const Document*>(RHS);
    if(DocPTR)
    {
        if (DocPTR->Doc_Info.size() != this->Doc_Info.size())
        {
            return true;
        }
        for (unsigned int i = 0; i < this->Doc_Info.size(); ++i)
        {
            if (DocPTR->Doc_Info[i] != this->Doc_Info[i])
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

std::string Document::debug_print() const
{
    std::string debug;
    for (unsigned int i = 0; i < this->Doc_Info.size(); ++i)
    {
        std::string temp = Doc_Info[i];
        std::string temp1 = std::to_string((i + 1));
        debug += "Line ";
        debug += temp1;
        debug += ':';
        debug += temp;
        debug += '\n';
    }
    return debug;
}

std::string Document::to_string() const
{
    std::string Doc;
    Doc += this->name;
    Doc += "\n";
    Doc += this->location;
    Doc += "\n";
    Doc += this->extension;
    Doc += "\n";
    for (unsigned int i = 0; i < this->Doc_Info.size(); ++i)
    {
        Doc += Doc_Info[i];
        Doc += "\n";
    }
    return Doc;
}

void Document::from_string(const std::string& Doc)
{ 
    this->Doc_Info.clear();
    std::string Name;
    std::string Loc;
    std::string Ext;
    int counter=0;
    bool flag = false;
    std::string temp;
    for (unsigned int i = 0; i < Doc.size(); ++i)
    {
        if (counter > 2 && Doc[i] != '\n' && !flag)
        {
            temp += Doc[i];
        }

        if (flag)
        {
            temp = Doc[i];
            flag = false;
        }

        if (counter > 2 && Doc[i] == '\n')
        {
            this->Doc_Info.push_back(temp);
            flag = true;
        }

        if (Doc[i] == '\n')
        {
            counter++;
        }
        if (counter == 0 && Doc[i] != '\n')
        {
            Name += Doc[i];
        }
        if (counter == 1 && Doc[i] != '\n')
        {
            Loc += Doc[i];
        }
        if (counter == 2 && Doc[i] != '\n')
        {
            Ext += Doc[i];
        }
    }
    this->name = Name;
    this->location = Loc;
    this->extension = Ext;
}
