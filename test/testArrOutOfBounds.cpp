#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

//NOTE: i hate arrays out of bounds!!!
//NOTE: NOT ANYMORE WITH SANITIZERS HAHAHA

int main()
{
  // const int N = 10;
  // int A [N];
  // cout << A[N+10]<< endl; 
  // cout << A[-10] << endl;

  // int M = 10;
  // int B [M];
  // cout << B[M+10]<< endl;

  // int K = 10;
  // int* C = new int[K];
  // cout << C[K+10] << endl;

  int P = 10;
  vector<int> D(P);
  cout << D[P+10] << endl;

  const int Q = 10;
  vector<int> E(Q);
  cout << E[Q+10] << endl;

  int R = 10;
  const int RR = R;
  int F[RR];
  cout << F[RR+10] << endl;

  return 0;
}