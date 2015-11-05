#include <iostream>
#include "string.hpp"

using namespace std;

void foo(const str_demo::string str)
{
    cout << "Enter foo\n";
    cout << str.at(2) << endl;
    cout << "Exit foo\n";
}

int main()
{
//	str_demo::string st1("Hello; how are you!!!");
//	cout << st1.c_str() << endl;
//	st1.at(1) = 'E';
//	cout << st1.c_str() << endl;
//
//	int cn_punct = str_demo::count_punct(st1);
//	cout << cn_punct << endl;
//
//    {
//        cout << str_demo::string::get_count_objects() << endl;
//        str_demo::string st2(st1);
//        foo(st2);
//    if (st1 != st2)
//        {
//            cout << "Strings are not identical\n";
//
//        }
//    }

    str_demo::string str1 = "New str1";
    str_demo::string str2;
    str2 = str1;
    str2[2] = 'H';

    cout << str1 << endl;
    cout << str2 << endl;
    cout << (str1 == str2) <<endl;

    str_demo::string str3;
    str3[3] = 'A';

	return 0;
}
