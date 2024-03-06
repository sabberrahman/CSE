#include <iostream>

int main(){
  std::cout << "hello love" << "\n ";
  std::cout << "ki koro love" << std::end ;
  std::cout << "bhatt khaisoo??"
  return 0;
}

// std::endl  $$ "\n"--do the same job

#include <iostream>
using namespace std;

int main(){
  cout << "hello love" << "\n ";
  cout << "ki koro love" << endl ;
  cout << "bhatt khaisoo??"<< endl << "yesss good" << endl;
  return 0;
}

// using namespace std; cut down lines for you

#include <iostream>
using namespace std;

int main(){
   int x;
   cin >> x; //takes input
   cout << "the value of x is :" << x; 
  return 0;
}
// scanf("the value: %d", x) er moto onkta

#include <iostream>
using namespace std;

int main(){
   int x , y;
   cin >> x >> y; //takes  two input
   cout << "the value of x is :" << x << " and y is:"<< y; 
  return 0;
}
/* 32323
2121
the value of x is :32323 and y is:2121 */

#include <iostream>
using namespace std;

int main(){
   int x , y;
   cin >> x >> y; //takes  two input
   cout << "the value of hehhe is :" << x << " and hahah is:"<< y; 
  return 0;
}
// same results


//BASIC STRUCUTURAL FOR C++ 
#include <bits/stdc++.h>
using namespace std;

int main(){
  return 0;
}


//DATA-TYPES
#include <bits/stdc++.h>
using namespace std;

int main(){
  // int , long , long long
  int x = 10;
  long y= 1212121;
  long long z = 15000000;

  //float , double -- for 5.23242425 stuff
   float xy = 5.232;
   float xz = 5;
   double zxu =1.34535;

  return 0;
}

int main(){
  // string-till space
  string s;
  cin >> s; //hay sabby
  cout << s; // hay

  //getline - till line break/enter
  string str;
  getline(cin , str); // hay sabby
  cout << str; // hay sabby
 
 //char - can store all doe?/
  char ch = "s";
  cout << ch ;
  return 0;
}




