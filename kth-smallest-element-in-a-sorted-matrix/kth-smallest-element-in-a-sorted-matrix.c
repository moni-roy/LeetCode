#define MX 200000
int ln, heap[MX];
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int maxChild(int *ar, int l, int r, int x, int y) {
    if (x < l && ar[r] < ar[x]) r = x;
    if (y < l && ar[r] < ar[y]) r = y;
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
    while (l > 0 && ar[(l - 1) / 2] < ar[l]) {
        swap(&ar[(l - 1) / 2], &ar[l]);
        l = (l - 1) / 2;
    }
}

int kthSmallest(int** matrix, int s, int* c, int k){
    ln = 0;
    for(int i = 0;i<s;i++){
        for(int j = 0;j<c[i];j++){
           insert(heap, matrix[i][j], ln++);
            if(ln>k) pop(heap, --ln);
        }
    }
    return heap[0];
}

