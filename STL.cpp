#include "pch.h"
#include "STL.h"

class A
{
};


void f(const A&) { cout << "lval" << endl; }
void f(A&&) { cout << "rval" << endl; }
template <typename T> void AGoodForwarding(T&& t) { f(std::forward<T>(t)); }

class Product
{
public:
    Product() {}
    Product(int p, string n) : price(p), name(n) {}

public:
    void PrintInformation(string label) { cout << label << ": " << price << ", " << name << endl; }

public:
    int price;
    string name;
};

void fn1(int i1, int i2, int i3, const Product& p)
{
    cout << i1 << endl;
    cout << i2 << endl;
    cout << i3 << endl;
    cout << p.price << ", " << p.name << endl;
}

void fn2(int i1)
{
    cout << i1 << endl;
}

void fn3(int & i1)
{
    ++i1;
}

template <typename T>
class TFunctor
{
public:
    T operator() (const T& t1, const T& t2)
    {
        return t1 + t2;
    }
};

void MyCout(string str)
{
    cout << "string: " << str << endl;
}

class Basket
{
public:
    Basket() {}
    Basket(initializer_list<string> refs) 
    {
        for(string ref : refs)
        {
            references.push_back(ref);
        }
    }

public:
    void AddReference(const string& ref) { references.push_back(ref); }
public:
    void PrintInformation() 
    { 
        for (string ref : references) 
        { 
            cout << ref << endl; 
        } 
    }

public:
    vector<string> references;
};

std::optional<int> GetPrice(const Product& p)
{
    // Non disponible
    if (p.price == 0)
    {
        return {};
    }
    else
    {
        return p.price;
    }
}

ostream& operator<<(ostream& os,
    const chrono::time_point<chrono::system_clock>& t)
{
    const auto tt(chrono::system_clock::to_time_t(t));
    const auto loct(std::localtime(&tt));
    return os << put_time(loct, "%c");
}

class ProductEx
{
public:
    ProductEx() {}
    ProductEx(std::optional<float> p, string n) : price(p), name(n) {}

public:
    void PrintInformation(string label) 
    { 
        cout << label 
            << ": " 
            << (price.has_value() ? price.value() : 0) 
            << ", " << name << endl; }

public:
    std::optional<float> price;
    string name;
};

std::optional<int> GetPrice(const ProductEx& p)
{
    // Non disponible
    if (p.price.has_value() )
    {
        return p.price;
    }
    else
    {
        return {};
    }
}

std::optional<int> GetPrice2(const ProductEx& p)
{
    // Non disponible
    if (p.price.has_value())
    {
        return p.price;
    }
    else
    {
        return std::nullopt;
    }
}

class BackgroundTask
{
public:
    BackgroundTask(const std::string& name, int age) : _name(name), _age(age) {}

    double GetResult() const 
    {
        return _res;
    }

    void operator()()
    {
        std::cout << "Name:" << _name
            << ", Age:" << _age << std::endl;
        _res = 10.52;
    }

private:
    std::string _name;
    int _age = 0;
    double _res = 0.0;
};

std::string _name;
std::mutex _mutex;

void func5()
{
    for (int i = 0; i < 100; i++)
    {
        std::scoped_lock lock(_mutex);
    }
}


void fnSTL()
{
    BackgroundTask task("Lisa", 14);
    std::thread t4(std::ref(task));
    t4.join();
    std::cout << "Result: " << task.GetResult() << endl;
        
    string mys1 = "Lisa";
    string mys2;
    mys2 = std::move(mys1);

    A a1;
    AGoodForwarding(std::move(a1));

    std::pair<int, Product> p1(1, Product(10, "item 1"));
    cout << p1.first << endl;
    cout << p1.second.price << ", " << p1.second.name << endl;
    std::pair<int, Product> p2 = std::make_pair(2, Product(20, "item 2"));
    cout << p2.first << endl;
    cout << p2.second.price << ", " << p2.second.name << endl;

    std::tuple<int, int, int, Product> t1(1, 2, 3, Product(50, "Item 5"));
    cout << std::get<0>(t1) << endl;
    cout << std::get<1>(t1) << endl;
    cout << std::get<2>(t1) << endl;
    cout << std::get<3>(t1).price << ", " << std::get<3>(t1).name << endl;
    auto t2 = std::make_tuple(5, 6, 7, Product(100, "Item 10"));

    auto t3 = std::make_tuple(10, 20, "hello Lisa");
    int i1;
    int i2;
    string s1;
    std::tie(i1, i2, s1) = t3;
    cout << std::get<0>(t3) << endl;
    cout << std::get<1>(t3) << endl;
    cout << std::get<2>(t3) << endl;

    int i3;
    std::tie(i1, i2, i3, std::ignore) = t1;

    std::apply(fn1, t1);

    std::byte b1{ 10 };
    std::byte b2{ 18 };
    std::byte b3 = b1 | b2;
    long l1 = std::to_integer<long>(b3);

    TFunctor<int> myFunctor;
    cout << myFunctor(10, 20) << endl;

    /*
    int tab1[] = { 1, 10, 20, 12, 9, 7 };
    std::sort(begin(tab1), end(tab1), std::greater<int>());
    */

    std::function<void(string)> fn_cout = MyCout;
    fn_cout("Hello Lisa !");
    fn_cout = [](string str) { cout << "Lambda: " << str << endl; };
    fn_cout("Hello Audrey !");

    Product p10(10, "Item 10");
    auto fn10 = std::mem_fn(&Product::PrintInformation);
    fn10(p10, "Info");

    auto list1 = { 1, 2, 3 };

    Basket basket1 = { "A1", "A2", "A3" };
    basket1.PrintInformation();

    Product p11(0, "Item 11"); // Non disponible
    auto res = GetPrice(p11);
    if (res.has_value())
    {
        cout << "price :" << res.value() << endl;
    }

    string sa1 = "Hello Edith !";
    std::any any1 = sa1;
    cout << any1.type().name() << endl;
    string str1 = std::any_cast<string>(any1);
    cout << str1 << endl;

    using seconds = chrono::duration<double>;
    using milliseconds = chrono::duration<double, ratio_multiply<seconds::period, milli>>;
    using microseconds = chrono::duration<double, ratio_multiply<seconds::period, micro>>;

    const auto tic(chrono::steady_clock::now());
    // …
    const auto toc(chrono::steady_clock::now());
    auto resToc = toc - tic;
    cout << resToc.count() << endl;
    cout << setw(12) << "s " << seconds(resToc).count() << endl;
    cout << setw(12) << "ms " << milliseconds(resToc).count() << endl;
    cout << setw(12) << "us " << microseconds(resToc).count() << endl;

    using days = chrono::duration<
        chrono::hours::rep,
        ratio_multiply<chrono::hours::period, ratio<24>>>;    
    auto now = chrono::system_clock::now();
    cout << now << endl;
    cout << now - 5h - 30min << endl;
    cout << now - days{ 2 } << endl;

    string s10;
    cout << typeid(s10).name() << endl;
    // class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);

    v1.insert(v1.begin() + 1, 15);
    for (int elt : v1)
    {
        cout << elt << " ";
    }
    cout << endl;

    std::array<int, 10> arr1;
    std::array<int, 3> arr2{ 1, 2, 3 };

    std::list mylist{ 100, 20, 300, 40, 500, 20 ,100 };
    mylist.sort();
    mylist.unique();
    for (int elt : mylist)
    {
        cout << elt << " ";
    }
    cout << endl;

    std::bitset<10> bit1;
    std::bitset<4> bit2("1010");

    std::map<int, Product> map1{ {1, Product(1, "Item 1")},
        {2, Product(10, "Item 2")},
    };
    map1[3] = Product(30, "Item 3");
    for (std::pair<int, Product> elt : map1)
    {
        cout << elt.first << " ";
        cout << elt.second.price << " " << elt.second.name << endl;
    }

    std::variant<int, float> vif;
    vif = 50;
    int i = std::get<int>(vif);
    cout << i << endl;
    try
    {
        int f = std::get<float>(vif);
        cout << f << endl;
    }
    catch (std::bad_variant_access bva)
    {
        cout << bva.what() << endl;
    }

    cout << "std::invoke..." << endl;
    std::invoke(fn2, 10);
    std::invoke([]() { cout << "c'est un lambda !" << endl; });
    Product product1(250, "XBox One");
    std::invoke(&Product::PrintInformation, product1, "Info");

    //void fn3(int& i1)
    int i4 = 100;
    fn3(std::ref(i4));

    std::vector<int> vi1{ 1, 2, 5, 10, 15, 20 };
    std::vector<int> vi2{ 1, 3, 7, 12, 18, 23 };
    std::sort(vi1.begin(), vi1.end());
    std::sort(vi2.begin(), vi2.end());
    std::vector<int> dest;
    std::merge(vi1.begin(), vi1.end(), vi2.begin(), vi2.end(), std::back_inserter(dest));
    // output
    std::cout << "dest: ";
    std::copy(dest.begin(), dest.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    std::vector<int> viA{ 1, 2, 5, 10, 15, 20 };
    std::vector<int> destA(viA.size());
    auto itA = std::copy_if(viA.begin(), viA.end(), destA.begin(), [](int ii) {
        return (ii % 2 == 0);
        });
    // shrink container to new size
    destA.resize(std::distance(destA.begin(), itA));
    // output
    std::cout << "copy_if dest: ";
    std::copy(destA.begin(), destA.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> viB{ 1, 2, 5, 10, 15, 20 };
    int a10 = std::rand();
    int b10 = std::rand();
    int resmin10 = std::min(a10, b10);
    int resmax10 = std::max(a10, b10);
    std::cout << a10 << ", " << b10 << ": min :" << resmin10 << " : max :" << resmax10 << endl;

    std::vector<int> viC{ 1, 2, 5, 10, 15, 20 };
    int iC = 10;
    if (std::binary_search(viC.begin(), viC.end(), iC))
    {
        cout << "found !" << endl;
    }

    std::vector<int> viD{ 1, 2, 5, 10, 15, 20 };
    std::vector<int> siD{ 5, 10, 15 };
    auto itD = std::search(viD.begin(), viD.end(), siD.begin(), siD.end());
    if (itD != viD.end())
    {
        cout << "found !" << endl;
    }

    std::vector<int> viE{ 5, 10, 15 };
    std::vector<int> viF{ 5, 10, 15 };
    if (std::equal(viE.begin(), viE.end(), viF.begin()))
    {
        cout << "equal !" << endl;
    }

    std::vector<int> viG{ 1, 2, 4, 5, 10, 15 };
    std::fill(viG.begin(), viG.end(), 0);
    // output
    std::cout << "dest: ";
    std::copy(viG.begin(), viG.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> viH{ 1, 2, 5, 10, 15, 20 };
    std::vector<int> viI{ 50, 100, 150 };
    std::copy(viI.begin(), viI.end(), std::back_inserter(viH));
    // output
    std::cout << "copy dest: ";
    std::copy(viH.begin(), viH.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> viJ{ 1, 2, 5, 10, 15, 20 };
    std::reverse(viJ.begin(), viJ.end());
    // output
    std::cout << "reverse dest: ";
    std::copy(viJ.begin(), viJ.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> viK{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto itK = std::partition(viK.begin(), viK.end(), [](int ii) {
        return (ii % 2 == 0);
        });
    // output
    std::cout << "partition dest: ";
    std::copy(viK.begin(), itK, std::ostream_iterator<int>(std::cout, " "));
    std::cout << " * ";
    std::copy(itK, viK.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> viL{ 10, 2, 50, 1, 150, 20, -5, 40 };
    std::sort(viL.begin(), viL.end());
    // output
    std::cout << "sort dest: ";
    std::copy(viL.begin(), viL.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> viM{ 1, 2, 5, 10, 15, 20, 65 };
    std::vector<int> viN{ 10, 65 };
    if (std::includes(viM.begin(), viM.end(), viN.begin(), viN.end()))
    {
        cout << "includes !" << endl;
    }

    std::vector<int> viO{ 1, 2, 5 };
    std::sort(viO.begin(), viO.end());
    do 
    {
        // output
        std::cout << "viO: ";
        std::copy(viO.begin(), viO.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    } 
    while (std::next_permutation(viO.begin(), viO.end()));
    
    
    map<int, string> filles{ {9, "Audrey"}, {13, "Lisa"}, {16, "Edith"} };
    auto nh = filles.extract(13);
    nh.key() = 14; // Anniv le 10 Nov
    filles.insert(std::move(nh));
    // m == { {9, "Audrey"}, {14, "Lisa"}, {16, "Edith"} }

    std::vector<int> vi3{ 1, 2, 5, 10, 15, 20 };
    //std::reverse()
 
    ProductEx p100(100, "Item 100");
    auto res1 = GetPrice(p100);
    if (res1.has_value())
    {
        cout << "price: " << res1.value() << endl;
    }
    auto res2 = GetPrice2(p100);
    if (res2.has_value())
    {
        cout << "price: " << res2.value() << endl;
    }

    int i10 = 10;
    auto lmFn0 = [i10]() { return i10; };
    int resFn0 = lmFn0();
    cout << resFn0 << endl; // 10
    cout << i10 << endl; // 10

    int j10 = 10;
    auto lmFn1 = [&j10]() { ++j10; return j10; };
    int res10 = lmFn1();
    cout << res10 << endl; // 11
    cout << j10 << endl; // 11

    int a2 = 2;
    int a5 = 5;
    auto lmFn2 = [=]() { return a2 + a5; };
    int resFn2 = lmFn2();
    cout << resFn2 << endl; // 7

    int c2 = 2;
    int b5 = 5;
    auto lmFn3 = [&]() { return ((++c2) + (++b5)); };
    int resFn3 = lmFn3();
    cout << resFn3 << endl; // 9
    cout << c2 << ", " << b5 << endl; // 3, 6

    //return;
    
    //std::thread happy_b([]() {
    //    while (true)
    //    {
    //        std::cout << "Happy B. Eric" << endl;
    //        std::cout << "Que les Dieux du NET soient avec toi" << endl;
    //    }});
    //happy_b.join();

    //std::thread happy_b([]() {
    //    while (true)
    //    {
    //        std::cout << "Happy B. Christopher" << endl;
    //        std::cout << "Que les Dieux du C/C++, NET et du Cloud soient avec toi" << endl;
    //    }});
    //happy_b.join();

}

