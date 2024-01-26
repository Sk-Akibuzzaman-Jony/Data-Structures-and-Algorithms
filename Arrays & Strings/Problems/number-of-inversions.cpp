// https://www.codingninjas.com/studio/problems/number-of-inversions_6840276

int cnt = 0; // global variables are not encouraged in interviews
void merge(vector<int>& a, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left < mid+1 && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        } else {
            temp.push_back(a[right]);
            cnt += (mid-left+1);
            right++;
        }
    }

    while(left < mid+1){
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        a[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& a, int low, int high){
    if(low >= high) return;
    int mid = low+(high-low)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}

int numberOfInversions(vector<int>&a, int n) {
    mergeSort(a, 0, n-1);
    return cnt;
}
