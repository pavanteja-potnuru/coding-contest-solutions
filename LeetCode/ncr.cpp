
#define MODULO 1000000007
#define N 999
int ncr[N][N];
int getNcr(int n, int r) {
    if(n<r) return -1;
    if(n==r || r==0) {
        ncr[n][r] = 1;
    } else if(ncr[n][r] == 0) {
        ncr[n][r] = getNcr(n-1, r-1) + getNcr(n-1, r);
    }

    return ncr[n][r]%MODULO;
}