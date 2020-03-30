#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;

//This file checks every value less than or equal to the
//square root of n to see if n is prime

int main(){
    int n;
    cin >> n;

    ifstream file;
    file.open("Primes.txt");
    std::list<int> Primes;
    int q = 0;

    while(q < sqrt(n)){//by the square root law, we only need to check primes up to the square root of n to see if n is prime
        file >> q;
        Primes.push_back(q);
    }
    list<int>::iterator iter = Primes.begin();
    int flag = 1;
    while(iter != Primes.end()){
        if((n % *iter) == 0){
            flag = 0;
        }
        iter++;
    }
    if (flag == 1){
        cout << n << " is Prime\n";
    }
    else{
        cout << n << " is not Prime\n";
    }
    file.close();
//    std::cin.get();

    return 0;
}