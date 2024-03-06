// problem: note: imp: todo:

#include <bits/stdc++.h> 
using namespace std;

int main(){
    int age;
    cin >> age;
    if (age >= 18)
    {
        cout << "you are an adult😁";
    } else {
        cout << "you are not an adult😐 ";
    }
    
  return 0;
}



 // problem: grading ifelse
 #include <bits/stdc++.h> 
using namespace std;

int main(){
    int mark;
    cin >> mark;
    if (mark < 25)
    {
        cout << "failed🤡";
    } else if( mark <=40) {
        cout << "C grade🤬";
    } else if( mark <=60) {
        cout << "B grade😐 ";
    } else if( mark <=79) {
        cout << "A grade 😊";
    } else if( mark >= 80) {
        cout << "A+ boyy😘";
    }
    
  return 0;
};
// problem: array 
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int arr[5];
    cin >> arr[0] >> arr[1] >>arr[2] >>arr[3] >> arr[4];

   arr[3] += 10;
   arr[1]= 99;

   cout << arr[3] << endl << arr[1] ;
  return 0;
}
// note: arr[2] will be trewated as like evrey data type 

// problem: 2d array
// arr [2][2] wll have garbage value!" ex-871231232"
// int arr[row] [col] ;
int main(){
   int arr[2][5]; 
   arr [0][4]=23;
   cout << arr[0][4] << arr [2][2] ;
}

//problem: 
// note: str also store every char inTermof indexs
 int main(){
    string s;
    s="sabber";
    int length = s.size();
    cout << s[length - 1 ]; //r
    cout << s[3]; //b
 }

