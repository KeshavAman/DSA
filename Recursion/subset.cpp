#include<iostream>
#include<vector>
using namespace std;

void subset(vector<int> &arr, vector<int> output, int index, vector<int> &ans){
    //basecase
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    subset(arr,output,index+1,ans);
    //include
    int element = arr[index];
    output.push_back(element);
    subset(arr,output,index+1,ans);

}
vector <int> solve(vector<int>&arr){
    vector<int> output;
    vector<int> ans;
    int index = 0;
    subset(arr,output,index, ans);
    return ans;
}


int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<int> a = solve(arr);
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
  return 0;

}