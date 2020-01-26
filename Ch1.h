#pragma once

// dans file1.h
extern const int max_objects;

void ch1_fn1();
void ch1_fn2();
void ch1_fn3();

struct Produit
{
    int prix;
    int ref;
};

typedef Produit* ProduitPtr;

void ch1_fn4();

void DisplayPrice(int price);
void DisplayPrice(double price);

int Square(int n);
constexpr int Square2(int n);
constexpr int fn10();

