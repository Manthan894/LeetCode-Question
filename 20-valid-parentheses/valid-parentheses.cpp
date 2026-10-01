class Solution {
public:
    bool isValid(string s) {
        stack<char> stacks;
        int n = s.size();
        if(n%2 != 0){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
                stacks.push(s[i]);
            }
            else{
                if(stacks.empty()){
                    return false;
                }
                if(s[i] == '}'){
                    if(stacks.top() == '{'){
                        stacks.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i] == ')'){
                    if(stacks.top() == '('){
                        stacks.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i] == ']'){
                    if(stacks.top() == '['){
                        stacks.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(!stacks.empty()){
            return false;
        }
        return true;
    }
};