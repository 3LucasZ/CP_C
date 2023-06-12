#include<iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>

using namespace std;

int main() {
    set<int> A;
    unordered_set<int> uA;
    multiset<int> B;
    unordered_multiset<int> uB;
    map<int,int> C;
    unordered_map<int,int> uC;
    
    int N = 2000000;

    std::chrono::steady_clock::time_point tA = std::chrono::steady_clock::now();
    for (int i=0;i<N;i++){
        int nxt = rand() % N;
        A.insert(nxt);
    }

    std::chrono::steady_clock::time_point tuA = std::chrono::steady_clock::now();
    for (int i=0;i<N;i++){
        int nxt = rand() % N;
        uA.insert(nxt);
    }

    std::chrono::steady_clock::time_point tB = std::chrono::steady_clock::now();
    for (int i=0;i<N;i++){
        int nxt = rand() % N;
        B.insert(nxt);
    }

    std::chrono::steady_clock::time_point tuB = std::chrono::steady_clock::now();
    for (int i=0;i<N;i++){
        int nxt = rand() % N;
        uB.insert(nxt);
    }

    std::chrono::steady_clock::time_point tC = std::chrono::steady_clock::now();
    for (int i=0;i<N;i++){
        int nxt = rand() % N;
        C[nxt]++;
    }

    std::chrono::steady_clock::time_point tuC = std::chrono::steady_clock::now();
        for (int i=0;i<N;i++){
        int nxt = rand() % N;
        uC[nxt]++;
    }

    std::chrono::steady_clock::time_point tf = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (tuA - tA).count() << "[ms]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (tB - tuA).count() << "[ms]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (tuB - tB).count() << "[ms]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (tC - tuB).count() << "[ms]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (tuC - tC).count() << "[ms]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (tf - tuC).count() << "[ms]" << std::endl;
}