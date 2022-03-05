#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
// first :: 스카이라인의 높이가 변화하는 지점
// second :: 높이
using lines = vector<pair<int,int>>;
struct BUILDING{
    // x1 :: 건물 시작좌표
    // x2 :: 건물 끝 좌표
    // height :: 건물의 높이
    int x1,x2,height;
};

int N;
//입력 함수
vector<BUILDING> input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<BUILDING> buildings(N);
    for(int i=0;i<N;i++){
        BUILDING *tmp = &buildings[i];
        cin>> tmp->x1 >> tmp->height >> tmp->x2;
    }
    return buildings;
}

void append(lines &ans, pair<int,int> p){
    int n=ans.size();
    if(n>0){
        // 높이가 같은경우 -- 연속되는 높이 점은 추가하지 않는다. 
        // (높이가 변화하는 지점과 그 높이를 출력하는 것이 정답이므로)
        if(ans[n-1].second == p.second) return;
        // 위치가 같은경우
        if(ans[n-1].first==p.first){
            ans[n-1].second=p.second;
            return;
        }
    }
    ans.push_back(p);
}

// 좌 우 스카이라인을 합치는 함수 merge sort 응용
lines merge(lines &left, lines &right){
    lines ans;
    // left height
    int h1=0;
    // right height
    int h2=0;
    //left idx
    int i=0;
    //right idx
    int j=0;
    while(i<left.size() && j<right.size()){
        pair<int,int> &u=left[i];
        pair<int,int> &v=right[j];
        if(u.first < v.first){
            int x=u.first;
            h1=u.second;
            int h = max(h1,h2);
            append(ans,make_pair(x,h));
            i++;
        }else{
            int x=v.first;
            h2=v.second;
            int h=max(h1,h2);
            append(ans,make_pair(x,h));
            j++;
        }
    }
    while(i<left.size()) append(ans,left[i++]);
    while(j<right.size()) append(ans,right[j++]);
    return ans;
}

//스카이라인을 구하는 함수
//건물을 좌우로 나누어 스카이라인을 구함

//lines :: pair<int,int>  first:: 높이가 바뀌는 지점 , second:: 높이
lines make_skylines(vector<BUILDING> &buildings, int start, int end){
    //탈출 조건 -- 건물이 1채
    if(start==end){
        lines ans = {
            // 첫 시작점 기준 건물의 높이 반영
            {buildings[start].x1,buildings[start].height}
            // 건물이 끝나는지점에서 0이 되는 것을 반영
            ,{buildings[start].x2,0}
        };
        // 이를 반환하고 끝낸다.
        return ans;
    }

    int mid=(start+end)/2;
    //재귀호출하여 계속 쪼개가며 라인을 구한다.
    lines left=make_skylines(buildings,start,mid);
    lines right=make_skylines(buildings,mid+1,end);
    // 좌우를 합치며 반환
    return merge(left,right);
}

void solution(vector<BUILDING> &buildings){
    sort(buildings.begin(),buildings.end(), [](const BUILDING &u, const BUILDING &v){
        // 건물 시작점, 높이, 건물 순의 기준으로 오름차순 정렬
        return make_tuple(u.x1,u.height,u.x2) < make_tuple(v.x1, v.height, v.x2);
    });
    lines ans=make_skylines(buildings,0,N-1);
    for(pair<int,int> &p : ans) cout<<p.first<<' '<<p.second<<' ';
    cout<<'\n';
}

int main(){
    //(1933)
    // 스카이라인
    // N개의 직사각형 모양의 건물들이 주어졌을 때, 스카이라인을 구해내는 프로그램을 작성하시오.
    // 스카이라인은 건물 전체의 윤곽을 의미한다.
    // 즉, 각각의 건물을 직사각형으로 표현했을 때, 그러한 직사각형들의 합집합을 구하는 문제이다.
    // 예를 들어 직사각형 모양의 건물들이 위와 같이 주어졌다고 하자.
    // 각각의 건물은 왼쪽 x좌표와 오른쪽 x좌표, 그리고 높이로 나타난다.
    // 모든 건물들은 편의상 같은 높이의 지면(땅) 위에 있다고 가정하자.

    // 이미지 참고
    // https://www.acmicpc.net/problem/1933

    // 첫째 줄에 건물의 개수 N(1 ≤ N ≤ 100,000)이 주어진다.
    // 다음 N개의 줄에는 N개의 건물에 대한 정보가 주어진다.
    // 건물에 대한 정보는 세 정수 L, H, R로 나타나는데, 각각 건물의 왼쪽 x좌표, 높이, 오른쪽 x좌표를 의미한다.
    // (1 ≤ L < R ≤ 1,000,000,000, 1 ≤ H ≤ 1,000,000,000)

    // 첫째 줄에 스카이라인을 출력한다.
    // 출력을 할 때에는 높이가 변하는 지점에 대해서, 그 지점의 x좌표와 그 지점에서의 높이를 출력한다.

    //입력
    vector<BUILDING> a = input();
    solution(a);
    return 0;
}