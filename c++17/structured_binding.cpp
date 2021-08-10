#include <tuple>
#include <array>

using Coordinate = std::pair<int, int>;
Coordinate origin() {
  return Coordinate{0, 0};
}

int main()
{
    const auto [ x, y ] = origin();
    x; // == 0
    y; // == 0
    auto t = std::make_tuple(1, 2, 3, 4);
    const auto [e1, e2, e3, e4] = t;
    return 0;
}