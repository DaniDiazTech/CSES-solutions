#include<bits/stdc++.h>
using namespace std;

signed main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif // DEBUG
    int n, x; cin >> n >> x;
    vector<int> a, b;
    int m = (n  + 1) /2 , k = n / 2;

    // Divides array in two
    for (int i =0 ;i < m; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for (int i =0 ;i < k; i++){
        int x; cin >> x;
        b.push_back(x);
    }


    vector<long long > l, r;
    for (int mask =0 ; mask < (1 << m); mask++){
        int sum = 0;
        for (int j =0 ; j < m; j++){
            if (sum > x){
                break;
            }
            if (mask & (1 << j)){
                sum += a[j];
            }
        }
        if (sum <= x){
            l.push_back(sum);
        }
    }
    for (int mask =0 ; mask < (1 << k); mask++){
        long long sum = 0;
        for (int j =0 ; j < k; j++){
            if (sum > x){
                break;
            }
            if (mask & (1 << j)){
                sum += b[j];
            }
        }
        if (sum <= x){
            r.push_back(sum);
        }
    }

    long long ans = 0 ;

    sort(r.begin(), r.end());


    for (int i =0 ; i < (int)l.size(); i++){
        long long target = x - l[i];

        auto ft = lower_bound(r.begin(), r.end(), target);
        auto st = upper_bound(r.begin(), r.end(), target);

        if (ft != r.end()){
            if (*ft == target){
                ans += (st - ft);
            }
        }
    }

    cout << ans << endl;
}