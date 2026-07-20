class Solution {
    bool fun(unordered_map<char,int>ran,unordered_map<char,int>mag){
        for(auto i : ran){
            char c = i.first;
            int freq1 =  i.second;
            int freq2 = mag[c];
            if(freq1 > freq2){
                return false;
            }
        }
        return true;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ran;
        unordered_map<char,int> mag;
        for(int i=0;i<ransomNote.size();i++){
            ran[ransomNote[i]]++;
        }
        for(int j=0;j<magazine.size();j++){
            mag[magazine[j]]++;
        }
        return fun(ran,mag);
    }
};