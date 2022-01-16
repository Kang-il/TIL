#include <iostream>
#include <vector>
using namespace std;
int go(vector<int> &a) {
    int n = a.size();
    if (n == 2) return 0;
    int ans = 0;
    for (int i=1; i<n-1; i++) {
        int energy = a[i-1]*a[i+1];
        vector<int> b(a);
        b.erase(b.begin()+i);
        energy += go(b);
        if (ans < energy) {
            ans = energy;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*
    (16198)
    에너지 모으기
    N개의 에너지 구슬이 일렬로 놓여져 있고, 에너지 구슬을 이용해서 에너지를 모으려고 한다.
    i번째 에너지 구슬의 무게는 Wi이고, 에너지를 모으는 방법은 다음과 같으며, 반복해서 사용할 수 있다.

    1. 에너지 구슬 하나를 고른다. 고른 에너지 구슬의 번호를 x라고 한다. 
       단, 첫 번째와 마지막 에너지 구슬은 고를 수 없다.
    2. x번째 에너지 구슬을 제거한다.
    3. Wx-1 × Wx+1의 에너지를 모을 수 있다.
    4. N을 1 감소시키고, 에너지 구슬을 1번부터 N번까지로 다시 번호를 매긴다. 번호는 첫 구슬이 1번, 다음 구슬이 2번, ... 과 같이 매겨야 한다.
    
    N과 에너지 구슬의 무게가 주어졌을 때, 모을 수 있는 에너지 양의 최댓값을 구하는 프로그램을 작성하시오.
    */
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << go(a) << '\n';
    return 0;
}