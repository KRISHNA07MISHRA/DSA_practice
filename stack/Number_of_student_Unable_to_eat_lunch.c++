class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int countone = 0;
        int countzero = 0;
        for(int i = 0; i<students.size(); i++){
            if(students[i] == 1){
                countone++;
            }
            else{
                countzero++;
            }
        }

        for(int  i = 0; i<sandwiches.size(); i++){
            if(sandwiches[i] == 0 && countzero == 0){
                return countone;
            }
            else if(sandwiches[i] == 1 && countone == 0){
                return countzero;
            }
            else if(sandwiches[i] == 0){
                countzero--;
            }
            else{
                countone--;
            }
        }
        return 0;
    }
};