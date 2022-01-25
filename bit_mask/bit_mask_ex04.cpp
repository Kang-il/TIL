#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int LIMIT = 5;
vector<int> gen(int k) {
    vector<int> a(LIMIT);
    for (int i=0; i<LIMIT; i++) {
        a[i] = (k&3);
        k >>= 2;
    }
    return a;
}
void print(vector<vector<pair<int,bool>>> &a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j].first << ' ';
        }
        cout << '\n';
    }
}
int check(vector<vector<int>> &a, vector<int> &dirs) {
    int n = a.size();
    vector<vector<pair<int,bool>>> d(n, vector<pair<int,bool>>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j].first = a[i][j];
        }
    }
    // 0: down, 1: up, 2: left, 3: right
    for (int dir : dirs) {
        bool ok = false;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                d[i][j].second = false;
            }
        }
        while (true) {
            ok = false;
            if (dir == 0) {
                for (int i=n-2; i>=0; i--) {
                    for (int j=0; j<n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i+1][j].first == 0) {
                            d[i+1][j].first = d[i][j].first;
                            d[i+1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i+1][j].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i+1][j].second == false) {
                                d[i+1][j].first *= 2;
                                d[i+1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 1) {
                for (int i=1; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i-1][j].first == 0) {
                            d[i-1][j].first = d[i][j].first;
                            d[i-1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i-1][j].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i-1][j].second == false) {
                                d[i-1][j].first *= 2;
                                d[i-1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 2) {
                for (int j=1; j<n; j++) {
                    for (int i=0; i<n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j-1].first == 0) {
                            d[i][j-1].first = d[i][j].first;
                            d[i][j-1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j-1].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i][j-1].second == false) {
                                d[i][j-1].first *= 2;
                                d[i][j-1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 3) {
                for (int j=n-2; j>=0; j--) {
                    for (int i=0; i<n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j+1].first == 0) {
                            d[i][j+1].first = d[i][j].first;
                            d[i][j+1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j+1].first == d[i][j].first) {
                            if (d[i][j].second == false && d[i][j+1].second == false) {
                                d[i][j+1].first *= 2;
                                d[i][j+1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } 
            if (ok == false) break;
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ans < d[i][j].first) {
                ans = d[i][j].first;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     //(12100)
    // 2048 (Easy)
    // 2048 게임은 4×4 크기의 보드에서 혼자 즐기는 재미있는 게임이다.
    // 이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다.
    // 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다. 
    // 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. 
    // (실제 게임에서는 이동을 한 번 할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 없다)
    // https://www.acmicpc.net/problem/12100 -- 규칙참고
    // 이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다. 
    // 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int k=0; k<(1<<(LIMIT*2)); k++) {
        vector<int> dir = gen(k);
        int cur = check(a, dir);
        if (ans < cur) ans = cur;
    }
    cout << ans << '\n';
    return 0;
}