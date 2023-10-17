class UnionFind {   
public:
    int components;
    vector<int> parents;

    UnionFind(int n) {
        parents = vector(n, 0);
        components = n;
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }
    
    bool join(int parent, int child) {
        int parentParent = find(parent);
        int childParent = find(child);
        
        if (childParent != child || parentParent == childParent) {
            return false;
        }
        
        components--;
        parents[childParent] = parentParent;
        return true;
    }
    
    int find(int node) {
        return parents[node] = parents[node] != node ? find(parents[node]) : parents[node];
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
         UnionFind uf(n);
        for (int node = 0; node < n; node++) {
            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children) {
                if (child == -1) {
                    continue;
                }
                
                if (!uf.join(node, child)) {
                    return false;
                }
            }
        }
        
        return uf.components == 1;
    }
};