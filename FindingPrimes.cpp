#include <iostream>
#include <fstream>
#include <list>
using namespace std;

//The purpose of this file is to create a file with all
//primes less than or equal to n names Primes.txt
int main(){
    int n = 100000;

    std::list<int> Primes;
    Primes.push_back(2);
    list<int>::iterator iter = Primes.begin();
    int q = 3;
    int flag;
    while(q <= n){
        flag = 1;
        iter = Primes.begin();
        while(iter != Primes.end()){
            if((q % *iter) == 0){
                flag = 0;
            }
            iter++;
        }
        if (flag == 1){
            Primes.push_back(q);
        }
        q++;
    }

    ofstream file_;
    file_.open("Primes.txt");
    for(iter = Primes.begin(); iter != Primes.end(); iter++){
        file_ << *iter << ' ';
    }
    file_.close();
//    std::cin.get();

    return 0;
}






