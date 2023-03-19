#include <functional>
#include <iostream>

int main()
{
    auto&& f = [](){ std::cout << "Hello World!" << std::endl; };
    f();
    return 0;
}
