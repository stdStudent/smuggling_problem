#include "smuggle.h"

using std::vector;

// Use std::span()?
template<typename T>
static std::vector<T> slice(std::vector<T>& v, int m, int n)
{
    std::vector<T> vec;
    std::copy(v.begin() + m, v.begin() + n + 1, std::back_inserter(vec));
    return vec;
}

static vector<int> evalWithNegatives(const vector<int>& a)
{
    int tmp{};
    vector<int> result{0};
    for (int i = 0; i < a.size() - 1; ++i) {
        if (a[i] < a[i+1]) {
            tmp = (a[i + 1] - a[i]) * (-1);
            result.emplace_back(tmp);
            result.emplace_back(a[i+2]);
            ++i;
        } else {
            result.emplace_back(a[i+1]);
        }
    }

    // Check the last elem with the first one and add them it to `result`
    if (a.back() < a.front())
        tmp = (a.front() - a.back())*(-1);

    result.front() = tmp;

    return result;
}

vector<int> smuggle(vector<int>& arr)
{
    int size = arr.size();
    auto a = evalWithNegatives(arr);

    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int start = 0;
    int end = 0;
    int s = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    return slice(arr, start-1, end-1);
}
