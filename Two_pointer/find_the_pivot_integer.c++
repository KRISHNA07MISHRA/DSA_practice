class Solution {
public:
    int pivotInteger(int n) {
        
        int left = 1;
        int right = n;
        int leftsum = left;
        int rightsum = right;

        while(left<right){
            
            if(leftsum<rightsum){
                left +=1;
                leftsum += left;
            }
            else{
                right -= 1;
                rightsum += right; 
            }
        }
        if(leftsum == rightsum){
            return left;
        }
        return -1;
    }
};