template<auto value>
auto f()
{
    return 1;
}

int main()
{
    f<10>();
    return 0;
}
