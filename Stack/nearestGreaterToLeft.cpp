#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void neartestGreaterToLeft(vector<int> arr, int n){
    vector<int>ans;
        stack<int>s;
        for(int i=0; i<n; i++){
            if(s.size()==0){
            ans.push_back(-1);
            } 
            else if(s.size()>0 && s.top()>arr[i]){
                ans.push_back(s.top());
            }
            else if(s.size()>0 && s.top()<=arr[i]){
                while(s.size()>0 && s.top()<=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ans.push_back(-1);
                } 
                else if(s.size()>0 && s.top()>arr[i]){
                    ans.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
    print(ans,n);
}

int main(){

    vector<int>arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"Nearest Greater to left -> ";
    neartestGreaterToLeft(arr,n);
    return 0;
}