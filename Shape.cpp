#include "pch.h"
#include "Shape.h"

Shape::Shape(int x, int y) : _x(x), _y(y)
{
    _type = DrawingType::none;
    InternalBuidlName();
}

Shape::Shape() : Shape(0, 0)
{
}

Shape::~Shape()
{
}

void Shape::Draw()
{
    cout << "Drawing..." << endl;
}

void Shape::InternalBuidlName()
{
    static int counter = 0;
    ++counter;

    stringstream ss1;
    ss1 << "element_" << counter;
    _name = ss1.str();
}

void X1::fn1() const
{
    //../..
    ++x;
}

float Shape2::_zoomFactor = 1.0f;
constexpr float Shape2::_zoomFactor2;

Shape3::Shape3(const Shape3& shape) : _x(shape._x), _y(shape._y)
{
}

Shape3& Shape3::operator=(const Shape3& shape)
{
    _x = shape._x;
    _y = shape._y;
    return *this;
}

Shape4& Shape4::operator=(const Shape4& shape) = default;

Shape6::Shape6(const Shape6&& shape) : _x(shape._x), _y(shape._y)
{
}

Shape7::Shape7(Shape7&& shape) noexcept : _x(shape._x), _y(shape._y)
{
    cout << "ctor move" << endl;
}

Shape7& Shape7::operator=(const Shape7& shape) noexcept
{
    cout << "operator=" << endl;
    _x = shape._x;
    _y = shape._y;
    return *this;
}

Shape7& Shape7::operator=(const Shape7&& shape) noexcept
{
    cout << "operator= move" << endl;
    _x = shape._x;
    _y = shape._y;
    return *this;
}

#ifdef local2
void ShapeEx::Draw() const
{
    cout << "Drawing..." << endl;
}
#endif

#ifdef local2
ShapeEx* ShapeEx::CreateObject(const ShapeType& type)
{
    ShapeEx* ptrObj = nullptr;
    
    if (type == ShapeType::Rectangle) 
    {
        ptrObj = new Rectangle();
    }
    else if (type == ShapeType::Ellipse)
    {
        ptrObj = new Ellipse();
    }

    return ptrObj;
}
#endif

shared_ptr<ShapeEx> ShapeEx::CreateObject(const ShapeType& type)
{
    shared_ptr<ShapeEx> ptrObj = nullptr;

    if (type == ShapeType::Rectangle)
    {
        ptrObj = make_shared<Rectangle>();
    }
    else if (type == ShapeType::Ellipse)
    {
        ptrObj = make_shared<Ellipse>();
    }

    return ptrObj;
}


void Rectangle::Draw() const
{
    cout << "Drawing Rectangle..." << endl;
}

void Ellipse::Draw() const
{
    cout << "Drawing Ellipse..." << endl;
}



