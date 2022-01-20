#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void nearestSmallerElement(vector<int> arr, int n){
    vector<int>ans;
    stack<int>st;
    for(int i=0; i<n; i++){
        if(st.size()==0){
            ans.push_back(-1);
        }
        else if(st.size()>0 && st.top()<arr[i]){
            ans.push_back(st.top());
        }
        else if(st.size()>0 && st.top()>=arr[i]){
            while(st.size()>0 && st.top()>=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top()<arr[i]){
                ans.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    print(ans,n);
}

int main(){

    vector<int>arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(8);
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"Nearest Smaller to left -> ";
    nearestSmallerElement(arr,n);
    return 0;
}