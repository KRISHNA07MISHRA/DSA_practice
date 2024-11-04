//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
       data = d;
       left = NULL;
       right = NULL;
    }
    
};

class cmp{
    public:
    
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
    
};

class Solution
{
	public:
	    void solve(Node* node,vector<string>&ans,string temp){
	        if(node->left == NULL && node->right == NULL){
	            ans.push_back(temp);
	            return;
	        }
	        
	        
	        solve(node->left,ans,temp+'0');
	        solve(node->right,ans,temp+'1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    
		    for(int i = 0; i<N; i++){
		        Node* newnode = new Node(f[i]);
		        pq.push(newnode);
		    }
		    
		    
		    while(pq.size()>1){
		        Node* left = pq.top();
		        pq.pop();
		        Node* right = pq.top();
		        pq.pop();
		        
		        
		        Node* newnode = new Node(left->data+right->data);
		        
		        newnode->left = left;
		        newnode->right = right;
		        
		        pq.push(newnode);
		    }
		    
		    
		    vector<string> ans ;
		    Node* node = pq.top();
		    
		    string temp = "";
		    solve(node,ans,temp);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends