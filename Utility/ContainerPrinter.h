#include <iostream>
#include <iterator>
#include <concepts>

template<typename T>
concept isContainer = requires(T a) {
    {a.begin()} -> std::forward_iterator;
    {a.end()} -> std::forward_iterator;
    {a.size()} -> std::convertible_to<std::size_t>;
    requires std::input_iterator<decltype(a.begin())>;
};

template<isContainer T>
std::ostream& operator<<(std::ostream& os, const T& container) {
    for (auto& item : container) {
        os << item << std::endl;
    }
    return os;
}

