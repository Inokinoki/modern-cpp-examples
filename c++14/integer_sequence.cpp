#include <tuple>
#include <iostream>
#include <array>
#include <utility>

// From https://en.cppreference.com/w/cpp/utility/integer_sequence
// Convert array into a tuple
template<typename Array, std::size_t... I>
auto a2t_impl(const Array& a, std::index_sequence<I...>)
{
    return std::make_tuple(a[I]...);
}

template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N>& a)
{
    return a2t_impl(a, Indices{});
}

int main()
{
    std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{};
    std::make_integer_sequence<int, 20>{};
    std::make_index_sequence<10>{};
    std::index_sequence_for<float, std::iostream, char>{};

    std::array<int, 4> array = {1,2,3,4};

    // convert an array into a tuple
    auto tuple = a2t(array);
    static_assert(std::is_same<decltype(tuple),
                               std::tuple<int, int, int, int>>::value, "");

    return 0;
}
