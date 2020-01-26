// Books.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Ch1.h"
#include "Ch3.h"
#include "Ch4.h"
#include "Shape.h"
#include "Employe.h"
#include "STL.h"

int main()
{
    std::cout << "Hello World!\n";
    ch1_fn1();
    ch1_fn2();
    ch1_fn3();

    Ch3 ch3;
    ch3.Init();
    ch3.Operations();
    ch3.RangeFor();

    Ch4 ch4;
    ch4.PartI();

    Shape ms1(10, 10);
    ms1.SetType(DrawingType::rectangle);
    ms1.Draw();
    
    Shape sh2;

    X1 x1;
    x1.fn1();
    
    Shape2 shape2(10, 20);
    float z = shape2.GetZoomFactor();
    cout << z << endl;
    shape2.IncZoomFactor();
    z = shape2.GetZoomFactor();
    cout << z << endl;

    Shape2 shape2bis(100, 200);
    z = shape2bis.GetZoomFactor();
    cout << z << endl;

    Shape3 a(10, 20);
    Shape3 b(a);
    cout << b.GetLeft() << ", " 
        << b.GetTop() << endl;

    Shape3 c(20, 40);
    Shape3 d = c;
    cout << d.GetLeft() << ", " 
        << d.GetTop() << endl;
    Shape3 d2;
    d2 = d;
    cout << d2.GetLeft() << ", "
        << d2.GetTop() << endl;

    Shape4 e(200, 400);
    Shape4 f = e;
    cout << f.GetLeft() << ", "
        << f.GetTop() << endl;

    Shape5 g(200, 400);
    //Shape5 h = g;
    //cout << h.GetLeft() << ", "
    //    << h.GetTop() << endl;
  
    int ra1 = 10;
    int&& ra2 = std::move(ra1);

    cout << "Shape7" << endl;
    Shape7 s70;
    Shape7& s71 = s70;
    Shape7&& s80 = std::move(s70);
    s80 = std::move(s70);
    Shape7 s90(s80);
    Shape7 s91(10, 20);
    Shape7 s100(std::move(s91));

    Rectangle r1;
    r1.Draw();

    ShapeEx& shape1 = r1;
    shape1.Draw();

    ShapeEx* ptr;
#ifdef local2
    ShapeEx sh1;
    ptr = &sh1;
    ptr->Draw();
#endif
    Rectangle r2;
    ptr = &r2;
    ptr->Draw();

#ifdef local2
    ShapeEx* ptrE = ShapeEx::CreateObject(ShapeType::Ellipse);
    ptrE->Draw();
    delete ptrE;

    ShapeEx* ptrR = ShapeEx::CreateObject(ShapeType::Rectangle);
    ptrR->Draw();
    delete ptrR;
#endif

    shared_ptr<ShapeEx> ptrE = ShapeEx::CreateObject(ShapeType::Ellipse);
    ptrE->Draw();

    shared_ptr<ShapeEx> ptrR = ShapeEx::CreateObject(ShapeType::Rectangle);
    ptrR->Draw();

  
    // STL - Part II
    fnSTL();

    DisplayPrice(10);
    DisplayPrice(25.401);
    cout << Square(5) << endl;

    cout << "sizeof(bool)" << sizeof(bool) << endl;
    cout << "sizeof(char)" << sizeof(char) << endl;
    cout << "sizeof(wchar_t)" << sizeof(wchar_t) << endl;
    cout << "sizeof(short int)" << sizeof(short int) << endl;
    cout << "sizeof(int)" << sizeof(int) << endl;
    cout << "sizeof(float)" << sizeof(float) << endl;
    cout << "sizeof(double)" << sizeof(double) << endl;

    constexpr int ii = 10 + 50 + 80;

    const char* cptr = "Hello Maggie";
    char* ptr2 = const_cast<char*>(cptr);
    //const char* cptr2 = const_cast<char*>(ptr);

    /******************************************/
    /* Enter the Blog - Entrez sur notre blog */
    /******************************************/

    /**************/
    /* Good night */
    /**************/


    return 0;
}
