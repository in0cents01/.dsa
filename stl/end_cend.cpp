 
#include <bits/stdc++.h> 

int main()
{
    std::vector<int> nums{1, 2, 4, 8, 16};
    std::vector<std::string> fruits{"orange", "apple", "raspberry"};
    std::vector<char> empty;

    // Print vector nums.
    std::for_each(nums.cbegin(), nums.cend(),
                  [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';

    // Sum all integers in the vector nums, printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.cbegin(), nums.cend(), 0) << '\n';

    // Print the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.cbegin() << '\n';

    if (empty.cbegin() == empty.cend())
        std::cout << "vector ‘empty’ is indeed empty.\n";

    // Modify the first element in nums.
    *nums.begin() = 32;
    assert(*nums.cbegin() == 32);
}
