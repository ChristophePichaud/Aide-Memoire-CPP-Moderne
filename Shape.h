#pragma once

enum class DrawingType
{
    none,
    rectangle,
    carre,
    ellipse
};

class Shape;

#ifdef local
class Shape
{
public:
#ifdef local
    Shape(int x, int y) : _x(x), _y(y)
    {
        _type = DrawingType::none;
    }

    Shape() : Shape(0, 0)
    {
    }
#else
    Shape(int x, int y);
    Shape();
#endif
    virtual ~Shape() {};

public:
    void Draw() { /* ... */ }

public:
    int GetX() { return _x; }
    int GetY() { return _y; }
    DrawingType GetType() { return _type; }
    void SetType(const DrawingType& type) { _type = type; }

private:
    DrawingType _type;
    int _x;
    int _y;
    string _name;
    _GUID _uuid;
};
#elseif local2
class Shape
{
public:
    Shape(int x, int y);
    Shape();
    virtual ~Shape();

public:
    void Draw();

public:
    int GetX() { return _x; }
    int GetY() { return _y; }
    DrawingType GetType() { return _type; }
    void SetType(const DrawingType& type) { _type = type; }

private:
    void InternalBuidlName();

#ifdef v1
private:
    DrawingType _type;
    int _x;
    int _y;
    string _name;
#else
private:
    DrawingType _type = DrawingType::none;
    int _x = 0;
    int _y = 0;
    string _name = "";
#endif
};
#else
class Shape
{
public:
    typedef int COORD;
public:
    Shape(COORD x, COORD y);
    Shape();
    virtual ~Shape();

public:
    void Draw();

public:
    COORD GetX() { return _x; }
    COORD GetY() { return _y; }
    DrawingType GetType() { return _type; }
    void SetType(const DrawingType& type) { _type = type; }

private:
    void InternalBuidlName();

private:
    DrawingType _type = DrawingType::none;
    COORD _x = 0;
    COORD _y = 0;
    string _name = "";
};
#endif

class X1
{
public:
    //../..
    void fn1() const;

private:
    mutable int x;
};

class Rect
{
public:
    constexpr Rect(int left, int top, int right, int bottom) : _left(left), _top(top), _right(right), _bottom(bottom) { }
    int GetLeft() { return _left; }
    int GetTop() { return _top; }
    int GetRight() { return _right; }
    int GetBottom() { return _bottom; }
    void SetLeft(int left) { _left = left; }
    void SetTop(int top) { _top = top; }
    void SetRight(int right) { _right = right; }
    void SetBottom(int bottom) { _bottom = bottom; }

private:
    int _left;
    int _top;
    int _right;
    int _bottom;
};


class Shape2
{
public:
    typedef int COORD;
public:
    Shape2(COORD x, COORD y) : _x(x), _y(y) { }
    virtual ~Shape2() { }

public:
    void Draw() { /* ... */ }
    static float GetZoomFactor() { return _zoomFactor; }
    static void IncZoomFactor() { ++_zoomFactor; }
    static void DecZoomFactor() { --_zoomFactor; }

private:
    COORD _x = 0;
    COORD _y = 0;
    static float _zoomFactor;
    static constexpr float _zoomFactor2 = 2.0f;
};

class Shape3
{
public:
    typedef int COORD;
public:
    Shape3() { }
    Shape3(COORD x, COORD y) : _x(x), _y(y) { }
    Shape3(const Shape3& shape);
    virtual ~Shape3() { }

public:
    Shape3& operator=(const Shape3& shape);

public:
    void Draw() { /* ... */ }
    int GetLeft() { return _x; }
    int GetTop() { return _y; }

private:
    COORD _x = 0;
    COORD _y = 0;
};

class Shape4
{
public:
    typedef int COORD;
public:
    Shape4() = default;
    Shape4(COORD x, COORD y) : _x(x), _y(y) { }
    Shape4(const Shape4& shape) = default;
    ~Shape4() = default;

public:
    Shape4& operator=(const Shape4& shape);

    //...
public:
    void Draw() { /* ... */ }
    int GetLeft() { return _x; }
    int GetTop() { return _y; }

private:
    COORD _x = 0;
    COORD _y = 0;
};

class Shape5
{
public:
    typedef int COORD;
public:
    Shape5() = default;
    Shape5(COORD x, COORD y) : _x(x), _y(y) { }
    Shape5(const Shape5& shape) = delete;
    ~Shape5() = default;

public:
    Shape5& operator=(const Shape4& shape) = delete;

    //...
public:
    void Draw() { /* ... */ }
    int GetLeft() { return _x; }
    int GetTop() { return _y; }

private:
    COORD _x = 0;
    COORD _y = 0;
};

class Shape6
{
public:
    typedef int COORD;
public:
    Shape6() { }
    Shape6(COORD x, COORD y) : _x(x), _y(y) { }
    Shape6(const Shape6&& shape);
    ~Shape6() = default;
    //...
public:
    void Draw() { /* ... */ }
    int GetLeft() { return _x; }
    int GetTop() { return _y; }

private:
    COORD _x = 0;
    COORD _y = 0;
};

class Shape7
{
public:
    typedef int COORD;
public:
    Shape7() { cout << "ctor empty" << endl; }
    Shape7(COORD x, COORD y) : _x(x), _y(y) { cout << "ctro COORD" << endl; }
    Shape7(const Shape7& shape) : _x(shape._x), _y(shape._y) { cout << "ctor copy" << endl; }
    Shape7(Shape7&& shape) noexcept;
    ~Shape7() { }

public:
    Shape7& operator=(const Shape7& shape) noexcept;
    Shape7& operator=(const Shape7&& shape) noexcept;

    //...
public:
    void Draw() { /* ... */ }
    int GetLeft() { return _x; }
    int GetTop() { return _y; }

private:
    COORD _x = 0;
    COORD _y = 0;
};

class ShapeEx;
class Rectangle;

#ifdef local2
class ShapeEx
{
public:
    ShapeEx() { }
    virtual ~ShapeEx() { }

public:
    virtual void Draw() const;
    //virtual static void Draw2() const { }
};
#endif

enum class ShapeType
{
    Rectangle,
    Carre,
    Ellipse
};

class ShapeEx
{
public:
    ShapeEx() { }
    virtual ~ShapeEx() { }

public:
    //static ShapeEx* CreateObject(const ShapeType& type);
    static shared_ptr<ShapeEx> CreateObject(const ShapeType& type);

public:
    virtual void Draw() const = 0;
};


class Rectangle : public ShapeEx
{
public:
    virtual void Draw() const;
};

class Ellipse : public ShapeEx
{
public:
    virtual void Draw() const;
};

#ifdef local2
class Rectangle : public ShapeEx
{
public:
    void Draw() const override;
};
#endif

class ShapeManager final 
{
    //...
};

#ifdef local2
class Forbidden : public ShapeManager
{
};
#endif

