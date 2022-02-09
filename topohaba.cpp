#include<bits/stdc++.h>
using namespace std;

//下準備
static const int MAX=100000;

vector<int> g[MAX]; //グラフ
list<int> out; //答え
bool f[MAX]; //行った場所判定
int N; //ノードの数
int indeg[MAX]; //根の数

//bfs
void bfs(int s){
    queue<int> q; //訪問
    q.push(s);
    f[s]=true; //行ったことにする
    while(!q.empty()){
        int u=q.front();
        q.pop();
        out.push_back(u); //一番後ろが決まる
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i]; //現在地から行ける場所
            indeg[v]--; //根を減らす
            if(indeg[v]==0&&!f[v]){
                f[v]=true; //行ったことにする
                q.push(v); //次の場所
            }
        }
    }
}

void tsort(){

    //根のカウント
    for(int i=0;i<N;i++){
        indeg[i]=0;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<g[i].size();j++){
            int v=g[i][j];
            indeg[v]++;
        }
    }

    //bfs
    for(int i=0;i<N;i++){
        if(indeg[i]==0&&!f[i]) bfs(i);
    }
    
    //出力
    for(list<int>::iterator it=out.begin();it!=out.end();it++){
        cout<<*it<<endl;
    }
}

int main(){
    int s,t,M;
    cin>>N>>M;
    
    //行った場所の初期化
    for(int i=0;i<N;i++) f[i]=false;
    
    //入力
    for(int i=0;i<M;i++){
        cin>>s>>t;
        g[s].push_back(t);
    }

    //ソート本体
    tsort();

    return 0;
}