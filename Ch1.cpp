#include "pch.h"

// dans file1.cpp
extern const int max_objects = 100;

int fn2()
{
    return 20;
}

void ch1_fn1()
{
    long l1 = 10L;
    char a = 'a';
    string s = "a string";

    std::cout << "\tHello World!\n";

#ifdef TOTO
    L'a'     // wide character literal, type is wchar_t
    u8"hi!"  // utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
    42ULL    // unsigned integer literal, type is unsigned long long
    1E-3F    // single-precision floating-point literal, type is float
    3.14159L // extended-precision floating-point literal, type is long double
#endif

    int i = 10;
    char c = 'c';
    string str("Hello Maggie !");

    int a2 = fn2();
    int b1 = 1, c1 = 10, c2 = 100;

#ifdef TOTO
    int price = 10;
    int price = { 10 };
    int price{ 0 };
    int price(0);
#endif
}

void ch1_fn2()
{
    int i = 10;
    int& ai = i;
    ai++;
    cout << i << endl;

    int j = 20;
    int* pj = &j;
    *pj = 30;
    cout << *pj << endl;

    int* p2 = nullptr;
    p2 = &j;
    cout << "0x" << hex << p2 << endl;

    const int c1 = 20;
    int d = 30;
    const int c2 = d;

    cout << dec << max_objects << endl;
}

void ch1_fn3()
{
    constexpr int i = 10;
    constexpr int max = i + 200;
}

void ch1_fn4()
{
    auto str1 = string("Lisa et ") + "Maggie";
    auto f1 = 10 + 1.125;

    vector<string> v{ "Edit", "Lisa", "Maggie" };
    auto it = v.begin();
}

void DisplayPrice(int price)
{
    cout << "le prix est de " << price << endl;
}

void DisplayPrice(double price)
{
    cout << "le prix est de " << price << endl;
}

int Square(int n)
{
    return n * n;
}

constexpr int Square2(int n)
{
    return n * n;
}

constexpr int fn10()
{
    return 10;
}
