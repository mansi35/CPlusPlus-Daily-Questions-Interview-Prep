// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int low = 0, high = n-1, mid = 0;
        while (mid <= high)  
        {  
            switch (arr[mid])  
            {  
                  
                // mid is 0  
            case 0:  
                swap(arr[low++], arr[mid++]);  
                break;  
                  
                // mid is 1 .  
            case 1:  
                mid++;  
                break;  
                  
                // mid is 2  
            case 2:  
                swap(arr[mid], arr[high--]);  
                break;  
            }  
        }  
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends