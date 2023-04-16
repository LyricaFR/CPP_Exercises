#include <iostream>

#if false
int main()
{
    // In the following, we ask whether some line compiles.
    // We mean, if we put it here.
}
#endif

template <bool b>
class MyClass
{};

void f1(bool b)
{
    if (b)
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<false> my_class {};
        std::cout << my_class.hello() << std::endl:
        // Note that class MyClass<b> has no hello() method;
    }
}
// Q1:
//  - Does line `f1(true)` compiles ? No
//  - Does line `f1(false)` compiles ? No

/* ========================================================================= */
template <bool b>
void f2()
{
    if (b)
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<b> my_class {};
        std::cout << my_class.hello() << std::endl;
        // Note that class MyClass<b> has no hello() method;
    }
}

// Q2:
//  - Does line `f2<true>()` compiles ?  No
//  - Does line `f2<false>()` compiles ?  No

/* ========================================================================= */
template <bool b>
void f3()
{
    if constexpr (b) // <- difference with f2 is that `constexpr` here
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<b> my_class {};
        std::cout << my_class.hello() << std::endl;
        // Note that class MyClass<b> has no hello() method;
    }
}
// Q3:
//  - Does line `f3<true>()` compiles ?  Yos 
//  - Does line `f3<false>()` compiles ?  No

/* ========================================================================= */
void f4(bool b)
{
    if constexpr (b) // <- difference with f1 is that `constexpr` here
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<false> my_class {};
        std::cout << my_class.hello() << std::endl:
        // Note that class MyClass<b> has no hello() method;
    }
}

// Q4:
//  - Does line `f4(true)` compiles ? Nou
//  - Does line `f3(false)` compiles ?  Nou

/* ========================================================================= */

// Q5: What does `if constexpr` do? What does `constexpr` mean?

// if constexpr evaluate an expression during compilation.
// if the expression is false, the corresponding section isn't generated during compilation.
// constexpr indicates that the expression can be evaluated during compilation.

/* ========================================================================= */
bool f6()
{
    return true;
}

// Q6: The line `f3<f6()>()` does not compile, why and how should the function be
// changed so that it does ?

// f6() cannot be evaluated during compilation. 
// We have to add constexpr to f6's signature.
