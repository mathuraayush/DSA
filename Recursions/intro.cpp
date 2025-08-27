// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//priniting 1 to N
void print1toN(int i,int n){
    if(i>n) return;
    cout<<i;
    cout<<endl;
    print1toN(i+1,n);
}
//using backtracking
void print1toNb(int i){
    if(i<1) return;
    print1toNb(i-1);
    cout<<i;
    cout<<endl;
}
// Nto1
void printNto1(int i){
    if(i<1) return;
    cout<<i;
    cout<<endl;
    printNto1(i-1);
}
// using backtracking:
void printNto1b(int i,int n){
    if(i>n) return;
    printNto1b(i+1,n);
    cout<<i;
    cout<<endl;
}
int main() {
    // Write C++ code here
    print1toN(1,5);
    cout<<"Backtracking: "<<endl;
    print1toNb(5);
    cout<<"Nto1: "<<endl;
    printNto1(5);
    cout<<"Backtracking: "<<endl;
    printNto1b(1,5);
    return 0;
}