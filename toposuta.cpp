#include<bits/stdc++.h>
using namespace std;
static const int MAX=100000;

vector<int> g[MAX];
list<int> out;
bool f[MAX];
int N;
int indeg[MAX];

void bfs(int s){
    stack<int> st;
    st.push(s);
    f[s]=true;
    while(!st.empty()){
        int u=st.top();
        st.pop();
        out.push_back(u);
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            indeg[v]--;
            if(indeg[v]==0&&!f[v]){
                f[v]=true;
                st.push(v);
            }
        }
    }
}

void tsort(){
    for(int i=0;i<N;i++){
        indeg[i]=0;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<g[i].size();j++){
            int v=g[i][j];
            indeg[v]++;
        }
    }

    for(int i=0;i<N;i++){
        if(indeg[i]==0&&!f[i]) bfs(i);
    }
    
    for(list<int>::iterator it=out.begin();it!=out.end();it++){
        cout<<*it<<endl;
    }
}

int main(){
    int s,t,M;
    cin>>N>>M;  
    for(int i=0;i<N;i++) f[i]=false;
    
    for(int i=0;i<M;i++){
        cin>>s>>t;
        g[s].push_back(t);
    }

    tsort();

    return 0;
}