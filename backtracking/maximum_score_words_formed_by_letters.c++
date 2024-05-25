class Solution {
public:
    unordered_map<char,int> character;
    unordered_map<int,int> points;
    bool valid(string& st){
        unordered_map<char,int> temp_char = character;
        for(int i = 0; i<st.length(); i++){
            if(temp_char.find(st[i]) == temp_char.end()){
                return false;
                break;
            }
            temp_char[st[i]]--;
            if(temp_char[st[i]] == 0){
                temp_char.erase(st[i]);
            }
        }
        return true;
    }
    void remove(string& st){
        //unordered_map<char,int> temp_char = character;
        for(int i = 0; i<st.length(); i++){
            character[st[i]]--;
            if(character[st[i]] == 0){
                character.erase(st[i]);
            }
        }
    }
    void reverse(string &st){
        for(int i = 0; i<st.length(); i++){
            character[st[i]]++;
            
        }
    }
    void check(unordered_map<string,int>&findscore,vector<string>&words){
        for(int i = 0; i<words.size(); i++){
            int score = 0;
            for(auto j:words[i]){
                score += points[j];
            }
            findscore[words[i]] = score;
        }
    }
    int solve(vector<string>&words,unordered_map<string,int>&findscore,int index){
        if(index>=words.size()){
            return 0;
        }

        int take = 0;
        if(valid(words[index])){
            remove(words[index]);
            take = findscore[words[index]] + solve(words,findscore,index+1);
            reverse(words[index]);
        }
        int nottake = solve(words,findscore,index+1);

        return max(take,nottake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(int i = 0; i<letters.size(); i++){
            character[letters[i]]++;
        }

        char start = 'a';
        for(int i = 0; i<26; i++){
            points[start] = score[i];
            start++;
        }

        unordered_map<string,int> findscore;
        check(findscore,words);

        return solve(words,findscore,0);
    }
};