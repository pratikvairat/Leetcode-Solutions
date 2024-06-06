class Solution {
public:
    void getPrimes(int n, vector<long long>& Primes) {
        for (long long i = 2; i < n; i++) {
            if (Primes[i] == 1) {
                for (long long j = i * i; j < n; j += i) {
                    Primes[j] = 0;
                }
            }
        }
    }
    int countPrimes(int n) {
        vector<long long> Primes(n + 1, 1);
        int ans = 0;
        getPrimes(n, Primes);
        for (long long i = 2; i < n; i++) {
            if (Primes[i] == 1) {
                ans++;
            }
        }

        return ans;
    }
};
