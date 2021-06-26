class Solution {
public:
    
/*
 * Find Kth sorted number in segment l to r.
 */ 
    struct node
    {
        int ls,rs,cnt;
    };
    node tr[20*100001];
    int id,root[100001];
    void update(int &nw,int pr,int s,int e,int pos)
    {
        nw = ++id;
        tr[nw]=tr[pr];
        if(s==e && s==pos)
        {
            tr[nw].cnt ++;
            tr[nw].ls=tr[nw].rs=0;
            return;
        }
        int m = (s+e)/2;
        if(pos<=m)
        {
            update(tr[nw].ls,tr[pr].ls,s,m,pos);
        }
        else
        {
            update(tr[nw].rs,tr[pr].rs,m+1,e,pos);
        }
        tr[nw].cnt=tr[tr[nw].ls].cnt + tr[tr[nw].rs].cnt;
    }
    int query(int r,int s,int e,int x,int y)
    {
        if(s==x && y==e) return tr[r].cnt;
        int m = (s+e)/2;
        if(m>=y) return query(tr[r].ls,s,m,x,y);
        else if(m<x) return query(tr[r].rs,m+1,e,x,y);
        return query(tr[r].ls,s,m,x,m) + query(tr[r].rs,m+1,e,m+1,y);
    }
    vector<int> countSmaller(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        vector<int> ans;
        int id = 1;
        for(auto n: nums) {
            n += 10001;
            update(root[id], root[id-1], 0, 100001, n);
            ans.push_back(query(root[id++], 0, 100001, 0, n-1));
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};