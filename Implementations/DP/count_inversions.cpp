const int MAX = 3*1e5+4;
ll v[MAX], temp[MAX]; // v is the input array.
// Count inversions b[i] > b[j] while doing MergeSort, in O(n log n).
// It will sort the array. Call count_inversions(0, n-1).
ll count_inversions(int i, int j) { 
    ll mid = (i+j)/2, ans, k, pi = i, pj = mid+1;
    if(i == j) return 0;
    ans = count_inversions(i, mid);
    ans += count_inversions(mid+1, j);
    for(k = 0; k < (j-i+1); k++) {
        if(pi > mid) temp[k] = v[pj++];
        else if(pj > j) temp[k] = v[pi++];
        else if(v[pi] > v[pj]) {ans += mid-pi+1; temp[k] = v[pj++];}
        else temp[k] = v[pi++];
    }
    for(k = 0; k < (j-i+1); k++) v[k+i] = temp[k];
    return ans;
}
