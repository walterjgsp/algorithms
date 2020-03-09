#ifndef PRODUCT_LAST_K_NUMBERS_HPP_INCLUDED
#define PRODUCT_LAST_K_NUMBERS_HPP_INCLUDED

#include <bits/stdc++.h>

using namespace std;
class ProductOfNumbers {
private:
    vector<int> products;
    
public:
    ProductOfNumbers();
    void add(int num);
    int getProduct(int k);
};

#include "0160_product_last_k_numbers.cpp"

#endif