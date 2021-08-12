consteval int sqrt(int n) {
    return n * n;
}

constexpr int sqrt1(int n) {
    return n * n;
}

int main()
{
    constexpr int r = sqrt(100); // OK
    constexpr int x = 100;
    int x2 = 100;
    // sqrt(x2);        // ERROR: the value of 'x' is not usable in a constant expression
    int r2 = sqrt(x);   
    int x3 = 100;
    int r3 = sqrt1(x3); // OK if `sqr` were a `constexpr` function

    return 0;
}