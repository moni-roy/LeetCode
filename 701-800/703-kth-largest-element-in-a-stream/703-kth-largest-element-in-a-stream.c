typedef struct KthLargest {
    int val;
    struct KthLargest *next;
} KthLargest;

KthLargest arr[100100], *root;
int id = 0, n;

int ln, heap[100100];
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int maxChild(int *ar, int l, int r, int x, int y) {
    if (x < l && ar[r] > ar[x]) r = x;
    if (y < l && ar[r] > ar[y]) r = y;
    return r;
}
void heapify(int *ar, int l, int r) {
    int c = maxChild(ar, l, r, 2 * r + 1, 2 * r + 2);
    if (c != r) {
        swap(&ar[c], &ar[r]);
        heapify(ar, l, c);
    }
}
int pop(int *ar, int l) {
    int ret = ar[0];
    ar[0] = ar[l];
    heapify(ar, l, 0);
    return ret;
}
void insert(int *ar, int v, int l) {
    ar[l] = v;
    while (l > 0 && ar[(l - 1) / 2] > ar[l]) {
        swap(&ar[(l - 1) / 2], &ar[l]);
        l = (l - 1) / 2;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int s) {
    root=NULL;
    n = k;
    ln = 0;
    for(int i = 0;i<s;i++){
        insert(heap, nums[i], ln);
        ln++;
        if(ln>n) pop(heap, --ln);
    }
    return root;
}

int kthLargestAdd(KthLargest* obj, int val) {
  insert(heap, val, ln++);
    if(ln>n) pop(heap, --ln);
    return heap[0];
}

void kthLargestFree(KthLargest* obj) {
    obj= NULL;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/