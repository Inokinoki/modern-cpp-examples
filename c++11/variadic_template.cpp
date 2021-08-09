// The ... syntax creates a parameter pack or expands one.
template <typename... T>
struct arity {
    constexpr static int value = sizeof...(T);
};
static_assert(arity<>::value == 0);
static_assert(arity<char, short, int>::value == 3);

int main()
{
    return 0;
}
