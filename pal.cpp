
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char str[81];
  cin.get(str, 81);
  char str2[81];
  int read = 0;
  int write = 0;
  //Remove all spaces and punctuation
  while (str[read] != '\0') {
    unsigned char ch = str[read];
    if (!isspace(ch) && !ispunct(ch)) {
        str[write] = str[read];
        write++;
    }
    read++;
  }
  str[write] = '\0';
  //Make all characters lowercase
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }

  //Copy the simplifed text to later compare them backwards and forwards
  strcpy(str2, str);
  int start = 0;
  int end = strlen(str) -1;
  //inversing logic
  while (start < end) {
    //creating a temp variable and set that to the start 
    char temp = str[start];
    //set the start char to the end
    str[start] = str[end];
    //then set the end char to the temp and repeat 
    str[end] = temp;
    //increase start variable by one
    start++;
    //decrease the end variable by one
    end--;
    //eventually the 2 variables will meet and the while loop will end.
  }
  cout << str << '\n';
  int value = strcmp(str, str2);
  if (value == 0) {
    cout << "Palindrome";
  } else {
    cout << "Not a palindrome";
  }
  return 0;
}
