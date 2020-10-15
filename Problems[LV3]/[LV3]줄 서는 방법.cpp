#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long fac(long long n){return n == 1LL ? 1LL : n * fac(n - 1);}

void sol(vector<int> &arr, long long k){
    if(arr.size() == 1) return;
    long long f = fac(arr.size() - 1);
    int i = (k%f ? k/f : (k/f)-1);
    int tmp = arr[i];
    arr.erase(arr.begin() + i);
    sol(arr, k - (f * i));
    arr.insert(arr.begin(),tmp);
}

vector<int> solution(int n, long long k) {
    vector<int> arr;
    for(int i = 1; i <= n; i++) arr.push_back(i);
    sol(arr, k);
    return arr;
}