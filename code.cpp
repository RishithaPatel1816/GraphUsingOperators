#include <bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> mat;
    int vertices;
    int edges;
    public:
        Graph(int n,int m){
            vertices=n;
            edges=m;
            mat.resize(n);
            for(int i=0;i<n;i++){
                mat[i].resize(n);
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){mat[i][j]=0;}
            }
        }
        int getval(int i,int j){
            if(i>=0 && i<vertices && j>=0 && j<vertices){return mat[i][j];}
            return 0;
        }
        int getvert(){return vertices;}
        void resizeMatrix(int newvert){
            mat.resize(newvert, vector<int>(newvert, 0));
            vertices=newvert;
            return;
        }
        void operator+(Graph& g2){
            int m=g2.getvert();
            if(vertices<m){
                resizeMatrix(m);            
                for(int i=0;i<m;i++){
                    for(int j=0;j<m;j++){
                        if(g2.getval(i,j)==1){
                            mat[i][j]=1;
                        }
                    }
                }
            }
            else{
               // vertices>=m
                for(int i=0;i<m;i++){
                    for(int j=0;j<m;j++){
                        if(g2.getval(i,j)==1){
                            mat[i][j]=1;
                        }
                    }
                }
            }    
            //will just modify the original graph
            return;
        }
        void operator-(Graph & g2){
            int m=g2.getvert();
            if(vertices<m){
                resizeMatrix(m);
                for(int i=0;i<vertices;i++){
                    for(int j=0;j<vertices;j++){
                        mat[i][j]=mat[i][j]&g2.getval(i,j);
                    }
                }
            }
            else{
               // vertices>=m
                for(int i=0;i<vertices;i++){
                    for(int j=0;j<vertices;j++){
                        mat[i][j]=mat[i][j]&g2.getval(i,j);
                    }
                }
            }    
            //will just modify the original graph
            return;
        }
        void operator!(){
            //we want to find the complement
            //all will remain the same but
            //1 becomes zero and zero becomes one
            for(int i=0;i<vertices;i++){
                for(int j=0;j<vertices;j++){
                    if(mat[i][j]==1){mat[i][j]=0;}
                    else if(i==j){
                        //do nothing
                    }
                    else{
                        mat[i][j]=1;
                    }
                }
            }
            return;
        }
        void add_edge(int u,int v){
            mat[u][v]=1;mat[v][u]=1;return;
        }
        void remove_edge(int u,int v){
            mat[u][v]=0;mat[v][u]=0;return;
        }
        int getedges(){return edges;}
        bool dfs(int u,int v,vector<bool>& visited){
            if(u==v){return true;}
            visited[u]=true;
            for(int i=0;i<vertices;i++){
                if(mat[u][i]==1 && !visited[i]){
                    if(dfs(i,v,visited)){return true;}
                }
            }
            return false;
        }
        bool isReachable(int u ,int v){
            //we will find way from u to v
            //using recusrion
            vector<bool>visited(vertices,false);
            return dfs(u,v,visited);
        }
    friend ostream& operator<<(ostream& stream,Graph & g1);
    friend istream& operator>>(istream& stream,Graph & g1);
};

istream& operator>>(istream& stream,Graph & g1){
    //int v=g1.getvert();
    int e=g1.getedges();
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g1.add_edge(a,b);
    }
    return stream;
}

ostream& operator<<(ostream& stream,Graph & g1){
    int v=g1.getvert();
    //int e=g1.getedges();
    for(int i=0;i<v;i++){
        cout<<"Vertex "<<i<<": ";
        for(int j=0;j<v;j++){
            if(g1.mat[i][j]==1){cout<<j<<" ";}
        }
        cout<<endl;
    }
    return stream;
}

int main(){
    string s;
    cin>>s;
    if(s=="Graph"){
        int n;int m;
        cin>>n;cin>>m;
        Graph g(n,m);
        cin>>g;
        cin>>s;
        while(s!="end"){
            if(s=="isReachable"){
                int u,v;
                cin>>u>>v;
                if(g.isReachable(u,v)){cout<<"Yes"<<endl;}
                else{cout<<"No"<<endl;}
            }
            else if(s=="complement"){
                !g;
            }
            else if(s=="printGraph"){
                cout<<g;
            }
            else if(s=="add_edge"){
                int u,v;
                cin>>u>>v;
                g.add_edge(u,v);
            }
            else if(s=="remove_edge"){
                int u,v;
                cin>>u>>v;
                g.remove_edge(u,v);
            }
            else if(s=="union"){
                //we will have to create a new graph
                string x;cin>>x;
                if(x=="Graph"){
                    int a,b;cin>>a>>b;
                    Graph g2(a,b);
                    //take the graph input
                    cin>>g2;
                    g+g2;
                }
            }
            else if(s=="intersection"){
                //we will have to create a new graph
                string x;cin>>x;
                if(x=="Graph"){
                    int a,b;cin>>a>>b;
                    Graph g2(a,b);
                    //take the graph input
                    cin>>g2;
                    g-g2;
                }
            }
            cin>>s;
        }
        
    }
}
