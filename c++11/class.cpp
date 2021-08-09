#include <iostream>

class Parent
{
protected:
    int age {30};
public:
    Parent() = default;         // Use the default constructor
    Parent(Parent&) = delete;   // Copy constructor is not allowed by adding `delete`
    virtual void print()
    {
        std::cerr << "[PARENT] print age: " << age << std::endl;
    }
};

class ChildBranchA : public Parent
{
public:
    ChildBranchA() = default;

    virtual void print() override
    {
        std::cerr << "[BranchA] print " << age << std::endl;
    }
};

class ChildBranchB : public Parent
{
public:
    ChildBranchB() = default;
    ChildBranchB(ChildBranchB &b) { this->age = b.age; }

    virtual void print() final
    {
        std::cerr << "[BranchB] print " << age << std::endl;
    }
};

class GrandChildFinal final: public ChildBranchA, ChildBranchB
{
public:
    // Constructors can now call other constructors in *the same class* using an initializer list.
    GrandChildFinal(int _age) { ChildBranchA::age = _age; ChildBranchB::age = -_age; }
    GrandChildFinal() : GrandChildFinal(3) {}

    // error: virtual function ‘virtual void GrandChildFinal::print()’ overriding final function
    // virtual void print()
    // {
    //     std::cerr << "[GrandChildFinal] print" << std::endl;
    // }
};

// error: cannot derive from ‘final’ base ‘GrandChildFinal’ in derived type ‘GrandGrandChild’
// class GrandGrandChild: public GrandChildFinal
// {
// };

int main()
{
    ChildBranchA ca;
    ca.print();
    ChildBranchB cb;
    cb.print();

    GrandChildFinal gcf;
    // Ambiguous: gcf.print();
    ChildBranchB *gcfb = (ChildBranchB *)&gcf;
    gcfb->print();
    ChildBranchA *gcfa = (ChildBranchA *)&gcf;
    gcfa->print();
    Parent *p = (Parent *)gcfb;
    p->print(); // B
    p = (Parent *)gcfa;
    p->print(); // A
    // error: use of deleted function ‘Parent::Parent(Parent&)’
    // Parent p_copy(*p);
    // ChildBranchA ca_copy(ca);
    ChildBranchB cb_copy(cb);

    return 0;
}
