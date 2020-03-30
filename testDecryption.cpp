#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;

int main(){
    std::list<int> list2;
    int k = 57618;
    int n1 = 0;
    int j = 3;

    while(int(pow(10,n1))<k){
        n1++;
    }
    cout << n1 << endl;
    list<int>::iterator iter = list2.begin();
    // int u = pow(*iter,j);
    for(int i = n1-1; i>=0; i--){
        list2.push_back((k/int(pow(10,i)))%10);
    }
    for(int x : list2){
        cout << x <<endl;
    }
}