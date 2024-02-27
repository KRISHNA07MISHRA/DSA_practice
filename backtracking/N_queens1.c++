#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<unordered_set>


vector<vector<string>> ans;
int N;

unordered_set<int> column;
unordered_set<int>diagonal;
unordered_set<int>antidiagonal;
bool check(int row, int col , vector<string>&temp){
    for(int i = row-1; i>=0 ; i--){
        if(temp[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row-1, j= col-1; i>=0&& j>=0; i--,j--){
        if(temp[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row-1, j = col+1; i>=0&& j<N; i--,j++){
        if(temp[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
void solve(int row, vector<string>& temp) {
    if (row == N) {
        ans.push_back(temp);
        return;
    }

    for (int col = 0; col < N; col++) {
        int diatraversal = row+col;
        int antitraversal = row-col;

        if(column.find(col) != column.end() || antidiagonal.find(antitraversal) != antidiagonal.end() || diagonal.find(diatraversal) != diagonal.end() ){
            continue;
        }
        column.insert(col);
        antidiagonal.insert(antitraversal);
        diagonal.insert(diatraversal);
        temp[row][col] = 'Q';
        solve(row+1,temp);
        column.erase(col);
        antidiagonal.erase(antitraversal);
        diagonal.erase(diatraversal);
        temp[row][col] = '.';
    }
}

vector<vector<string>> NQueens(int n) {
    N = n;
    vector<string> temp(N, string(N, '.')); // Initialize chessboard with all positions empty

    solve(0, temp);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> ans = NQueens(n);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
