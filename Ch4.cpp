#include "pch.h"
#include "Ch4.h"

void Ch4::PartI()
{
    vector<int> vi{ 1, 2, 3, 4, 5 };
    for (int i : vi)
    {
        cout << i << " ";
    }
    cout << endl;

    string filles = "Edith, Lisa et Maggie";
    const char* cc = filles.c_str();
    printf("%s\n", cc);
}

