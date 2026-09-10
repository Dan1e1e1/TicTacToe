#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char str[20];
  char str2[20];
  char str3[20];
  cin.get(str, 20);
  cin.get();
  int start = 0;
  int end = strlen(str) - 1;
  //inversing logic
  while (start < end) {
    //creating a temp variable and set that to the start 
    char temp = str[start];
    //set the start char to the end
    str[start] = str[end];
    //then set the end char to the temp and repeat 
    str[end] = str[temp];
    //increase start variable by one
    start++;
    //decrease the end variable by one
    end--;
    //eventually the 2 variables will meet and the while loop will end.
  }
  cout << str2 << endl;

  return 0;
}
