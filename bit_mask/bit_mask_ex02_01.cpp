#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*


시간초과가 뜨는 방법



*/

bool learn[26];
int count(vector<string> &words){
    int cnt=0;
    for(string word : words){
        bool ok=true;
        for(char c : word){
            if(!learn[c-'a']){
                ok=false;
                break;
            }
        }
        if(ok)cnt++;
    }
    return cnt;
}

int calc(int idx, int K,vector<string> &words){
    if(K<0) return 0;
    if(idx==26) return count(words);
    int ans=0;

    learn[idx]=true;
    int t1=calc(idx+1,K-1,words);
    learn[idx]=false;

    if(ans<t1) ans=t1;

    if(idx!= 'a'-'a' && idx!='n'-'a' && idx != 't'-'a' && idx!='i'-'a' && idx!='c'-'a'){
        t1=calc(idx+1,K,words);
        if(ans<t1) ans=t1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (1062)
    // 가르침 -- 시간 초과가 뜨는 방법
    // 남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다. 
    // 그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 
    // 김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다. 
    // 김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

    // 남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 
    // 남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

    // 첫째 줄에 단어의 개수 N과 K가 주어진다. 
    // N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다.
    // 둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 
    // 단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 
    // 모든 단어는 중복되지 않는다.
    int N,K;
    cin>>N>>K;
    vector<string> words(N);
    for(int i=0;i<N;i++){
        cin>>words[i];
    }
    cout<<calc(0,K,words)<<'\n';
    return 0;
}