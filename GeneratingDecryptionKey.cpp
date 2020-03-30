#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;

//This File should be run after running FindingPrimes.cpp and before Decryption.cpp
//The purpose of this file is to generate the decryption key j

int main(){
    int num;
    cout << "enter the first encryption key n: ";
    cin >> num; //Here, you enter in what n is
    int k;
    cout << "enter the second encryption key k: ";
    cin >> k;
    int i1; //This is where the smaller prime is stored
    int i2; //This is where the larger prime is stored

    ifstream file;
    file.open("Primes.txt");
    std::list<int> Primes;
    int q = 0;

    while(q < sqrt(num)){//by the square root law, we only need to check primes up to the square root of n to see if n is prime
        file >> q;
        Primes.push_back(q);
    }
    list<int>::iterator iter = Primes.begin();
    while(iter != Primes.end()){
        if((num % *iter) == 0){
            i1 = *iter;
        }
        iter++;
    }
    i2 = num/i1;
    file.close();
//This is the end of the first part of the code
    int n = (i1-1) * (i2-1);
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
    if(i*n + j*k == 1){
        cout << "The decryption key is " << j << endl;
    }
    else{
        cout << "The decryption key is " << i << endl;
    }
}