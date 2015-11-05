#ifndef FRIENDCLASS1_H
#define FRIENDCLASS1_H

#include <iostream>
#include "..\string.hpp";

namespace str_demo
{
class FriendClass1
{
    public:
        FriendClass1();
        virtual ~FriendClass1();
        void foo(str_demo::string& s)
        {
            std::cout << s.data_ << std::endl;
        }
    protected:
    private:
};

}
#endif // FRIENDCLASS1_H
