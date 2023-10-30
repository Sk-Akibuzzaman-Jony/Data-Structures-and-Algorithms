// https://www.codingninjas.com/studio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=0

#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	deque<int> q;
	deque<int> q2;
	long long ans = 0;

	for(int i = 0; i < k; i++){
		while(!q.empty() && nums[q.back()] <= nums[i]){
			q.pop_back();
		}
		q.push_back(i);

		while(!q2.empty() && nums[q2.back()] >= nums[i]){
			q2.pop_back();
		}
		q2.push_back(i);    
	}

	ans += nums[q.front()] + nums[q2.front()]; 
	for(int i = k; i < n; i++){          
		
		if(!q.empty() && (i-q.front() >= k)){
			q.pop_front();
		}

		if(!q2.empty() && (i-q2.front() >= k)){
			q2.pop_front();
		}
		
		while(!q.empty() && nums[i] >= nums[q.back()]){
			q.pop_back();
		}

		while(!q2.empty() && nums[i] <= nums[q2.back()]){
			q2.pop_back();
		}

		q.push_back(i);
		q2.push_back(i);

		ans += nums[q.front()] + nums[q2.front()];
	}

	return ans;
}
