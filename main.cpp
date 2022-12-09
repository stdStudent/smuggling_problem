#include <iostream>
#include <vector>

#include "smuggle.h"

using namespace std;

template<typename T>
static void print(std::vector<T> const& v)
{
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> a{ 7, 3, 33, 87, 24, 28, 12, 17 };
    print(smuggle(a));

    return 0;
}
