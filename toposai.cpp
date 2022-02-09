#include<bits/stdc++.h>
using namespace std;

//下準備
static const int MAX=100000;

vector<int> G[MAX]; //グラフ
list<int> out; //出力用
bool V[MAX]; //行った場所判定
int N; //ノードの数

//bfs
void dfs(int u){
    V[u]=true;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!V[v]) dfs(v);
    }
    //行き止まり
    out.push_front(u);
}

int main(){
    int s,t,M;
    cin>>N>>M;
    int l[N]={}; 

    //行った場所の初期化  
    for(int i=0;i<N;i++) V[i]=false;
    
    //入力
    for(int i=0;i<M;i++){
        cin>>s>>t;
        G[s].push_back(t);
        l[s-1]++;
    }
    //bfsへの
    for(int i=0;i<N;i++){                                                                        
        if(!V[i]) dfs(i);
    }
    //出力
    for(list<int>::iterator it=out.begin();it!=out.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}