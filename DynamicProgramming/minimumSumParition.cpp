class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; i++){
	        sum = sum+arr[i];
	    }
	    int ans[n+1][sum+1];
	    vector<int>v(sum/2);
	    int mn = INT_MAX;
	    
	    ans[0][0] = true;
	    for(int i=1; i<n+1; i++){
	        ans[i][0] = true;
	    }
	    for(int i=1; i<sum+1; i++){
	        ans[0][i] = false;
	    }
	    for(int i=1; i<n+1; i++){
	        for(int j=1; j<sum+1; j++){
	            if(arr[i-1] <= j){
	                ans[i][j] = ans[i-1][j-arr[i-1]] || ans[i-1][j];
	            }
	            else{
	                ans[i][j] = ans[i-1][j];   
	            }
	        }
	    }
	    for(int i=0; i<=sum/2; i++){
	        if(ans[n][i]){
	            v.push_back(i);
	        }
	    }
	    for(int i=0; i<v.size(); i++){
	        mn = min(mn, sum-2*v[i]);
	    }
	    return mn;
	} 
};
