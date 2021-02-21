#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, L, D, X, A, B;

struct Drop {
        long long no;
        long long xi;

        bool operator <(const Drop& drop) {
                return xi < drop.xi;
        }
};

Drop arr[100010];

bool isOk(long long num) {
        long long i = 0;
        while (arr[i].no > num) {
                i++;
        }
        if (arr[i].xi>D) {
                return false;
        }
        long long prev = i;
        i++;
        for (i; i < N; i++) {
                if (arr[i].no <= num) {
                        if (arr[i].xi - arr[prev].xi > D) {
                                return false;
                        }
                        prev = i;
                }
        }
        if (L + 1 - arr[prev].xi > D) {
                return false;
        }
        return true;
}

long long binarySearch() {
        long long left = 1, right = N, answer = -1;
        while (left <= right) {
                long long mid = (left + right) / 2;
                if (isOk(mid)) {
                        answer = mid;
                        mid--;
                        right = mid;
                }
                else {
                        mid++;
                        left = mid;
                }
        }
        return answer;
}

void solve() {
    scanf("%lld", &N);
    scanf("%lld", &L);
    scanf("%lld", &D);
    scanf("%lld", &X);
    scanf("%lld", &A);
    scanf("%lld", &B);
    arr[0].no = 1;
    arr[0].xi = X;
    for (long long i = 1; i < N; i++) {
           arr[i].no = i+1;
           long long xi = (arr[i - 1].xi * A + B)%(L+1);
           arr[i].xi = xi;
    }
    sort(arr, arr + N);
    printf("%lld", binarySearch());
}

int main() {
    solve();
}