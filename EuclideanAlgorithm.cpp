#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;

//This file runs the Euclidean Algorithm to find the
//greatest common divisor between two values

int main(){
    int n;
    int k;
    cin >> n;
    cin >> k;
    std::list<int> List1;
//    std::list<int> List2;
    if(n > k){
        List1.push_back(n);
        List1.push_back(k);
    }
    else{
        List1.push_back(k);
        List1.push_back(n);
    }
    list<int>::iterator iter1 = --(--List1.end());
    list<int>::iterator iter2 = --List1.end();

    while((*iter1 % *iter2) != 0){
        List1.push_back(*iter1 % *iter2);
//        List2.push_back(*iter1 / *iter2);
        iter1 = --(--List1.end());
        iter2 = --List1.end();
    }
    // list<int>::iterator iter = List1.begin();
    // for(iter = List1.begin(); iter != List1.end(); iter++){
    //     cout << *iter << endl;
    // }
    int q = *iter2;
    cout << "The greatest common divisor of " << n << " and " << k << " is " << q << endl;
}