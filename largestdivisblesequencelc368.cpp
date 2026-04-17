class Solution {
public:
vector<int>help(vector<int>arr, int n){
    vector<int> dp(n,1);
    int lastindex=0;
    vector<int>hash(n);
    int maxi=1;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if((arr[i])%(arr[prev])==0 && dp[i]<dp[prev]+1){
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
            if (dp[i]> maxi){
            maxi = dp[i];
            lastindex = i;
            }


        }

    }
    vector<int>ans;
    ans.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex = hash[lastindex];
        ans.push_back(arr[lastindex]);
    }
    return ans;

}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return help(nums,n);
        
    }
};