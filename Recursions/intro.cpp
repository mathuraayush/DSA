// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
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
// Sum of First n number
//Backtracking
int sumN(int n){
  if(n<1) return 0;
  return n+sumN(n-1);
    }
//Forward    
int sumFwd(int n,int i=1){
    if(i>n) return 0;
    return i+sumFwd(n,i+1);
} 
//Backtrack
int factorial(int n){
  if(n<1) return 1;
  return n*factorial(n-1);
    } 
// Forward
int factorialFwd(int n,int i=1){
    if(i>n) return 1;
    return i*factorialFwd(n,i+1);
}   
//Swap helper
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
// Backtracking Version: 
void rev(vector<int> &a,int n){
    if(n<(a.size())/2) return;
    rev(a,n-1);
    swap(a[n],a[(a.size())-n-1]);
}
// Normal 
void r(vector<int> &a,int left,int right){
    if(left>=right) return;
    swap(a[left],a[right]);
    r(a,left+1,right-1);
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
    cout<<"Sum: "<<endl;
    int sum=sumN(5);
    cout<<sum;
    cout<<endl;
    cout<<"Sum: "<<endl;
    int s=sumFwd(5);
    cout<<s<<endl;
    cout<<"Factorial: "<<endl;
    int f=factorial(5);
    cout<<f<<endl;
    cout<<"Factorial Fwd: "<<endl;
    int fwd=factorial(5);
    cout<<fwd<<endl;
    cout<<"Original Vector: 1 2 3 4 5"<<endl;
    vector<int> a={1,2,3,4,5,};
    cout<<"Reversed Vector: ";
    rev(a,a.size());
    for(auto i:a){
         cout<<i<<" ";
    }
    cout<<endl;
       cout<<"Original Vector: 15 30 45 60 75"<<endl;
    vector<int> b={15,30,45,60,75};
    cout<<"Reversed Vector: ";
    r(b,0,a.size()-1);
    for(auto i:b){
         cout<<i<<" ";
    }

}