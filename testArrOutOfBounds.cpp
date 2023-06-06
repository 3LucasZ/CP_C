#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

//NOTE: arr must have sz that is const in order to block bad memory access

int main()
{
  const int N = 10;
  int A [N];
  cout << A[N]<< endl;

  int M = 10;
  int B [M];
  cout << B[M]<< endl;

  int K = 10;
  int* C = new int[K];
  cout << C[K] << endl;

  int P = 10;
  vector<int> D(P);
  cout << D[P] << endl;

  const int Q = 10;
  vector<int> E(Q);
  cout << E[Q] << endl;

  int R = 10;
  const int RR = R;
  int F[RR];
  cout << F[RR] << endl;
}