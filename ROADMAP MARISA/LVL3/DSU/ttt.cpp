int64_t binpow(int64_t a, int64_t b, int64_t mod) {
    int64_t res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

bool check(int64_t n, int64_t a, int64_t d, int s) {
    int64_t x = binpow(a, d, n);
    if (x == 1 || x == n - 1) return true;
    for (int r = 1; r < s; ++r) {
        x = (__int128)x * x % n;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrimeRM(int64_t n) {
    if (n < 2) return false;
    for (int64_t p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
        if (n % p == 0) return n == p;
    int64_t d = n - 1;
    int s = 0;
    while (d % 2 == 0) { d /= 2; ++s; }
    for (int64_t a : {2, 3, 5, 7, 11, 13, 17})
        if (!check(n, a, d, s)) return false;
    return true;
}