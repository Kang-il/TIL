#include <iostream>
#include <vector>
using namespace std;
/*
    Merge Sort 구현

    초기 A 상태 ::: 5 3 2 9 7 4 1 

    1 번 merge 호출 시 A 상태 ::: start :: 0  end :: 1   ||    3 5    3 5 2 9 7 4 1 
    2 번 merge 호출 시 A 상태 ::: start :: 2  end :: 3   || 3 5    2 9    3 5 2 9 7 4 1 
    3 번 merge 호출 시 A 상태 ::: start :: 0  end :: 3   ||    2 3 5 9    2 3 5 9 7 4 1 
    4 번 merge 호출 시 A 상태 ::: start :: 4  end :: 5   || 2 3 5 9    4 7    2 3 5 9 4 7 1 
    5 번 merge 호출 시 A 상태 ::: start :: 4  end :: 6   || 2 3 5 9    1 4 7    2 3 5 9 1 4 7 
    6 번 merge 호출 시 A 상태 ::: start :: 0  end :: 6   ||    1 2 3 4 5 7 9    1 2 3 4 5 7 9 

    최종 A 상태 ::: 1 2 3 4 5 7 9 

*/
vector<int> A;
int cnt=1;
void merge(int start, int end){
    int mid=(start+end)/2;
    int i=start;
    int j=mid+1;
    int k=0;
    vector<int> B(j);

    while(i<=mid && j<=end){
        if(A[i] <= A[j]) B[k++]=A[i++];
        else B[k++]=A[j++];
    }

    while(i<=mid) B[k++]=A[i++];
    while(j<=end) B[k++]=A[j++];

    for(int i=start ; i<=end ; i++){
        A[i]=B[i-start];
    }


    cout<< cnt++ <<" 번 merge 호출 시 A 상태 ::: ";
    cout<< "start :: "<<start<<"  end :: "<<end<<"   || ";
    for(int i=0;i<start;i++){
        cout<<A[i]<<' ';
    }
    cout<<"   ";
    for(int i=start;i<=end;i++){
        cout<<A[i]<<' ';
    }
    cout<< "   ";
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<' ';
    }
    cout<<'\n';
}
void merge_sort(int start, int end){
    //수의 개수가 1개인 경우
    if(start==end) return;

    int mid = (start+end)/2;
    merge_sort(start,mid);
    merge_sort(mid+1,end);

    merge(start,end);
}

int main(){
    A.push_back(5);
    A.push_back(3);
    A.push_back(2);
    A.push_back(9);
    A.push_back(7);
    A.push_back(4);
    A.push_back(1);

    cout<<"초기 A 상태 ::: ";
    for(int i=0;i<7;i++){
        cout<<A[i]<<' ';
    }
    cout<<'\n';

    merge_sort(0,6);

    cout<<"최종 A 상태 ::: ";
    for(int i=0;i<7;i++){
        cout<<A[i]<<' ';
    }
    cout<<'\n';

    return 0;
}