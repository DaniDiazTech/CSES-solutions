// Created by @DaniDiazTech
#include <bits/stdc++.h>
using namespace std;

struct KMP{ // KMP automaton
  string p; // pattern
  int n;
  vector<int> prev;
  KMP(string &pat) : p(pat), n((int)pat.size()), prev(n + 1){
    for (int i = 1; i < n; i++){
      prev[i + 1] = nxt(prev[i], p[i]);
    }
  }

  int nxt(int i, char ch){
    for (;i > 0; i = prev[i]) if (i < n && p[i] == ch) return i + 1;
    return p[0] == ch;
  }

  int match(string &s){
    int i = 0;
    int cnt =0 ;
    for (char ch: s){
      i = nxt(i, ch);
      if (i == n) cnt++;
    }
    return cnt;
  }

};


signed main(){
  string s, p; cin >> s >> p;
  KMP kmp = KMP(p);
  cout << kmp.match(s) << endl;
}