//Problem Statement

// Implement the class ProductOfNumbers that supports two methods:

// 1. add(int num)

// Adds the number num to the back of the current list of numbers.
// 2. getProduct(int k)

// Returns the product of the last k numbers in the current list.
// You can assume that always the current list has at least k numbers.
// At any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.
#include "0160_product_last_k_numbers.hpp"
#include <bits/stdc++.h>

using namespace std;

ProductOfNumbers::ProductOfNumbers(){
    products.clear();
}

void ProductOfNumbers::add(int num){
    if(num==0){
        products.clear();
    }else if(products.empty()){
        products.push_back(num);
    }else{
        products.push_back(products.back()*num);
    }
}

int ProductOfNumbers::getProduct(int k){
     if(k>products.size()){
        return 0;
    }else if(k==products.size()){
        return products.back();
    }else{
        int index = products.size()-k-1;
        return products.back()/products[index];
    }
}