#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count(int mask, vector<int> &words){
    int cnt=0;
    for(int word : words){
        if((word & ((1<<26)-1-mask))==0){
            cnt+=1;
        }
    }
    return cnt;
}

int calc(int idx, int K, int mask,vector<int> &words){
    if(K<0) return 0;
    if(idx==26) return count(mask,words);
    int ans=0;

    int t1=calc(idx+1,K-1,mask|(1<<idx),words);
    if(ans<t1) ans=t1;
    if(idx!= 'a'-'a' && idx!='n'-'a' && idx != 't'-'a' && idx!='i'-'a' && idx!='c'-'a'){
        t1=calc(idx+1,K,mask,words);
        if(ans<t1) ans=t1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //// (1062)
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


    //알파뱃 26가지
    // 26 C k
    // 2^26 = 67108864
    // 모든단어 anta 로 시작
    // tica 로 끝난다.
    // antic -- 항상 포함되어야 한다.
    // 21 C k-5
    // 2^21 -- k-5개의 글자를 고르는 시간
    // K개의 글자로만 이루어진 단어의 개수를 고르는 문제
    // 각각의 단어에 대해서 모든 글자를 검사
    // 시간복잡도 :: N*15
    // 2^21*50*15 == 157286400 -- 너무 길어 시간단축을 해야한다.

    // 각 단어를 구성하고있는 알파벳이 무엇인지 알아야 한다.
    // 번호로 저장.
    // word[i]= i번째 단어를 구성하고있는 알파벳을 비트마스크로!!
    int N,K;
    cin>>N>>K;
    vector<int> words(N);
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(char c : s){
            words[i]|=(1<<(c-'a'));
        }
    }
    cout<<calc(0,K,0,words)<<'\n';
    return 0;
}