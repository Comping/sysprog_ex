#include "string.hpp"
#include <cstring>

namespace str_demo
{
    int string::count_objects = 0;

	string::string()
        : data_(0)
	{
	    ++count_objects;
	    data_ = NULL;
	}


	string::~string()
	{
		if (this->data_)
			delete[] data_;

        --count_objects;
	}

	string& string::operator = (const string& rhs)
	{
        if (this == &rhs)//protect of self-
            return *this;
        if (data_)//clear data_ field
            delete[] data_;
        data_ = new char [rhs.length() + 1];
        std::strcpy(data_, rhs.data_);
        data_[rhs.length()] = '\0';
        return *this;
	}


	string::string(const char* data_)
	{
		this->data_ = new char[std::strlen(data_) + 1];
		std::strcpy(this->data_, data_);
		this->data_[std::strlen(data_)] = '\0';
		++count_objects;
		std::cout << this << std::endl;
	}


	string::string(const string& rhs)
	{
		data_ = new char[std::strlen(rhs.data_) + 1];
		std::strcpy(data_, rhs.data_);
		data_[std::strlen(rhs.data_)] = '\0';
		++count_objects;
		std::cout << this << std::endl;
	}


	const char& string::at(int i) const
	{
		return this->data_[i];
	}

	char& string::at(int i)
	{
		return this->data_[i];
	}

    char& string::operator[] (int i)
    {
        return data_[i];
    }

    const char& string::operator[] (int i) const
    {
        return data_[i];
    }

	int string::length() const
	{
		return std::strlen(data_);
	}


	char* string::c_str()
	{
		return data_;
	}

	int& string::get_count_objects()
	{
        return count_objects;
	}

    int count_punct(const str_demo::string& str)
    {
        int cn_punct = 0;
        for (int i = 0; i < std::strlen(str.data_); ++i)
        {
            if (std::ispunct(str.data_[i]))
                ++cn_punct;
        }

        return cn_punct;

    }

    bool operator == (const string& rhs, const string& lhs)
    {
        return std::strcmp(rhs.data_, lhs.data_) == 0;
    }

    bool operator != (const string& rhs, const string& lhs)
    {
        return std::strcmp(rhs.data_, lhs.data_);
    }

    std::ostream& operator << (std::ostream& os, const string& rhs)
    {
        os << rhs.data_;
        return os;
    }
}
