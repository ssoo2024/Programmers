#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define mod 1000000007L

int solution(int n) {
	vector<long long> arr(n + 1);
	if (n & 1)  return 0;
	arr[1] = 2;
	arr[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		arr[i] = ((3LL * arr[i - 2]) % mod) + 2;
		for (int j = 2; j <= i - 4; j += 2) {
			arr[i] = (arr[i] + (2LL * arr[j])) % mod;
		}
	}
	return (int)arr[n];
}