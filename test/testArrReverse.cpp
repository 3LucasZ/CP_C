#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

//NOTE: arr must have sz that is const in order to access begin, end

int main()
{
  const int SIZE = 10;
  int arr [SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  reverse(begin(arr), begin(arr)+SIZE);
  for (int i=0;i<SIZE;i++) std::cout << arr[i] << ", ";
  cout << endl;

  int N = 10;
  int tmp [N];
  //cout << begin(tmp) << endl; ###errors out, since N is not const
}