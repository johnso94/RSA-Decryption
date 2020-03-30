#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;

//This file runs the Euclidean Algorithm then runs it in reverse to find the
//x and y such that ax + by = c for some a, b, c. (if there are x and y which
//make the statement true)

int main(){
    int n;
    int k;
    int c;
    cout << "Enter integers a, b, c to get a solution x, y such that ax + by = c" << endl;
    cout << "int a: ";
    cin >> n;
    cout << "int b: ";
    cin >> k;
    cout << "int c: ";
    cin >> c;
    std::list<int> List1;
    std::list<int> List2;
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
        List2.push_back(*iter1 / *iter2);
        iter1 = --(--List1.end());
        iter2 = --List1.end();
    }
    int mult = c / (*iter2);
    // list<int>::iterator iter = List1.begin();
    // for(iter = List1.begin(); iter != List1.end(); iter++){
    //     cout << *iter << endl;
    // }
    iter2 = --List2.end();
    iter1 = --List2.begin();
    int i = 1;
    int j = -(*iter2);
    iter2--;
    while(iter2 != iter1){
        i -= *iter2 * j;
        iter2--;
        if(iter2 != iter1){
            j -= *iter2 * i;
            iter2--;
        }
    }
    i *= mult;
    j *= mult;
    if(i*n + j*k == c){
        cout << "(" << i << ") " << n << " + (" << j << ") " << k << " = " << c << endl;
    }
    else{
        cout << "(" << j << ") " << n << " + (" << i << ") " << k << " = " << c << endl;
    }
}