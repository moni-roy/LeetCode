class Solution {
public:
    struct unionFind{
        int par[10001],ran[10001];
        unionFind(int n){
            for(int i=0;i<=n;i++){
                par[i]=i;
                ran[i]=1;
            }
        }
        int root(int x){
            return (x==par[x])?x:par[x]=root(par[x]);
        }
        int comSize(int x){
            int y = root(x);
            return ran[y];
        }
        void connect(int x,int y){
            int xx = root(x),yy = root(y);
            if(xx==yy) return;
            if(ran[xx]>=ran[yy]) par[yy]=xx,ran[xx]+=ran[yy];
            else par[xx]=yy,ran[yy]+=ran[xx];
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unionFind uf(1001);
        for(auto e: edges) {
            if(uf.root(e[0]) == uf.root(e[1])) return e;
            uf.connect(e[0], e[1]);
        }
        return {};
    }
};