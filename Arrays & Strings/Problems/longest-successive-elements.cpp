// https://www.codingninjas.com/studio/problems/longest-successive-elements_6811740

int longestSuccessiveElements(vector<int>&a) {
    sort(a.begin(), a.end());
    int maxi = 0;
    int num = a[0];
    int count = 1;
    for(int i = 1; i < a.size(); i++){
        if(a[i] == a[i-1]) continue;
        if(a[i]-a[i-1] != 1){
            count = 1;
        } else {
            count++;
        }
        maxi = max(maxi, count);
    }
    return maxi;
}
