void func1() noexcept;        // does not throw
void func2() noexcept(true);  // does not throw
void func3() throw();         // does not throw

void func4() noexcept(false); // may throw

void f() { throw "test"; }  // potentially-throwing
void g() noexcept {
    f();          // valid, even if f throws, call std::terminate
    throw 42;     // valid, call std::terminate
}

int main()
{
    g();
    return 0;
}
