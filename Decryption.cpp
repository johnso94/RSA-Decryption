#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;

//This file runs the decryption process to get the numbers of the unencrypted message

int main(){
    std::list<int> Encrypted;
    int e;
    int j;
    int n;
    int k;
    cout << "Enter the encrypted message, the decryption key j, the first encryption key n and the second encryption key k" << endl;
    cout << "encrypted message: ";
    while((cin >> e)){
        if(e==-1){
            break;
        }
        Encrypted.push_back(e);
        cout << e << endl;
    }
    cout << "j: ";
    cin >> j;
    cout << "n: ";
    cin >> n;
    cout << "k: ";
    cin >> k;
    int n2=0;

    while((pow(10,n2))<k){
        n2++;
    }
    std::list<int> list2;
    list<int>::iterator iter = Encrypted.begin();
    int u;
    while(iter != Encrypted.end()){
        u = (int(pow(*iter,j))%n);
        for(int i = n2-1; i>=0; i--){
            list2.push_back((u/int(pow(10,i)))%10);
        }
        iter++;
    }
    std::list<int> list3;
    iter = list2.begin();
    while(iter != list2.end()){
        int a = *iter;
        iter++;
        int b = *iter;
        iter++;
        n = 10*a + b;
        list3.push_back(n);
    }
    iter = list3.begin();
    while(iter != list3.end()){
        cout << *iter << endl;
        iter++;
    }
    return 0;
}