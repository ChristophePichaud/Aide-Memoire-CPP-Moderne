#include "pch.h"                                                                                                                                                                                                                                                                                                                                
#include "Ch3.h"

void Ch3::Init()
{
    string str1;
    string str2 = "Edith";
    string str3 = str2;
    string str4(10, 'a');
    string str5("Lisa");
    string str6(str5);
}

int Ch3::Operations()
{
    string str = "Maggie";
    //std::cout << str;
    //std::cin >> str;
    //getline(std::cin, str);
    bool isEmpty = str.empty();
    size_t len = str.size();
    char c1 = str[1];
    string str2 = str + "Lisa";
    string str3 = str2;
    if (str2 == str3)
        ;
    if (str2 != str3)
        ;
    return 0;
}


int Ch3::CharOps()
{
    char c = 'a';
    bool b;
    b = isalnum(c);
    b = isalpha(c);
    b = iscntrl(c);
    b = isdigit(c);
    b = isgraph(c);
    b = islower(c);
    b = isprint(c);
    b = ispunct(c);
    b = isspace(c);
    b = isupper(c);
    b = isxdigit(c);
    c = tolower(c);
    c = toupper(c);

        
    return 0;
}


int Ch3::RangeFor()
{
    string str = "Maggie";
    for (char c : str)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}

//int Ch3::HappyB_Mickael()
//{
//    stringstream s;   
//    s << "Happy B Mickael !" << endl;
//
//    FreshBeer aBlond;
//    aBlond.Open();
//    while (!aBlond.Empty())
//    {
//        devoteam::network::broadcast(ALL, s.str());
//        _sleep(60000);
//    }
//}
