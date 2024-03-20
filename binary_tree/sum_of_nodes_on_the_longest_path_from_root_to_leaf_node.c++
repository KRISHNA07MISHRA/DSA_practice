void relate(Node* root, unordered_map<int,int>&mp,int sum,int count){
        if(root == NULL){
            return;
        }
        
        sum += root->data;
        count++;
        
        if(root->left == NULL && root->right == NULL){
            mp[sum] = max(mp[sum],count);
        }
        
        relate(root->left,mp,sum,count);
        relate(root->right,mp,sum,count);
        
        sum -= root->data;
        count--;
        
        
        
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root == NULL){
            return 0;
        }
        unordered_map<int,int> mp;
      
        relate(root,mp,0,0);
        
        priority_queue<pair<int,int>> pq;
        
        for(auto temp:mp){
            int sum = temp.first;
            int length = temp.second;
            
            pq.push({length,sum});
        }
        return pq.top().second;
    }