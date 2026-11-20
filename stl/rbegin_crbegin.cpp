#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 4, 8, 16};
    std::vector<std::string> fruits{"orange", "apple", "raspberry"};
    std::vector<char> empty;

    // Print vector nums.
    std::for_each(nums.crbegin(), nums.crend(),
                  [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';

    // Sum all integers in the vector nums, printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.crbegin(), nums.crend(), 0) << '\n';

    // Print the last fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "Last fruit: " << *fruits.crbegin() << '\n';

    if (empty.crbegin() == empty.crend())
        std::cout << "vector ‘empty’ is indeed empty.\n";

    // Modify the last element in nums.
    *nums.rbegin() = 32;
    assert(*nums.crbegin() == 32);
}

