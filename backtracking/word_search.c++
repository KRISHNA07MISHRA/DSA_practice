class Solution {
public:
    bool find(int i , int j , vector<vector<char>>&board,string &word,int index){

        if(index == word.length()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j] == '$' || board[i][j] != word[index]){
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '$';

        bool flag = find(i+1,j,board,word,index+1)||

                    find(i,j+1,board,word,index+1)||

                    find(i-1,j,board,word,index+1)||

                    find(i,j-1,board,word,index+1);

        board[i][j] = ch;


        return flag;



    }
    bool exist(vector<vector<char>>& board, string word) {
        

        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j] == word[0]  && find(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};