#include <bits/stdc++.h> 
using namespace std;

//note: void function return nothing , take no parameter unlesss..
void printName(){
    cout << "hayy sr" ; 
}
int main(){
    printName(); //hay sr
  return 0;
}

// note: if we write it this way , we take take para
void PrintName(string name){
    cout << "hay" << name ;
}
int main(){
    string name;
    cin << name; //sabber
    printName(name); // hay sabber

    string name2;
    cin << name2 ; //rahman
    printName(name2); // hay rahman
    return 0;
}

// note: function with return value , in void it wont return insted it will excuate from there just 

 int sum( int num1 , int num2){
    int num3 = num1 + num2;
    return num3 ; // return value , then output 
 }

 void sum(int num1 , int num2){
    int num3 = num1 + num2;
    cout << num3 ; //output
 }

 int main(){
    int num1 , num2 ;
    cin >> num1 >> num2 ;
    int result = sum( num1 , num2);
    cout << result ;
 }

 //note: pass by value . when pass a para value , a copy goes to that function but the original value stay the same in the main(). original memory did not go 
// 10 15 35 10 output!
void sum (int num){
    cout << num; 
    num +=5 ;
    cout << num;
    num += 20;
    cout << num;   
}
int main() {
    int num = 10;
    sum(num); 
    cout << num;
    return 0;
}

// note: pass by reference -- when you dont want tto sent copy and want to change the original value afterword!!
// just add a "&" before the variable . now the result will be --> 10 15 35 35 !!!!
// note: array alway goes with reference
void sum (int &num){}



