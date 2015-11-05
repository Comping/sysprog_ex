#pragma once

#include <iostream>
#include <cstring>

namespace str_demo
{
	//class FriendClass1;

	class string
	{
	public:
		string();
		virtual ~string();
		static int& get_count_objects();
	private:
		char* data_;
		static int count_objects;
        friend int count_punct(const str_demo::string& str);
	public:
	    string(const char* str);
		string(const string& rhs);

		string& operator = (const string& rhs);

		char& at(int i);
		char& operator [] (int i);
		const char& operator [] (int i)const;
		const char& at(int i) const;
		int length() const;
		char* c_str();

		friend bool operator == (const string& rhs, const string& lhs);
		friend bool operator != (const string& rhs, const string& lhs);
		friend std::ostream& operator << (std::ostream& os, const string& rhs);

        string& operator + (const string& rhs);
	};

    int count_punct(const str_demo::string& str);
    bool operator == (const string& rhs, const string& lhs);
    bool operator != (const string& rhs, const string& lhs);
    std::ostream& operator << (std::ostream& os, const string& rhs);

}
