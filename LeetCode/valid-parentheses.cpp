class Solution {
public:
    bool isValid(string s) {
        stack<char>k;
        for(char i:s) {
            if(i == '(' || i == '[' || i == '{') {
                k.push(i);
            }
            else if(!k.empty()) {
                if(i == ')'){
                    if(k.top() == '(') {
                        k.pop();
                    }
                    else return false;
                }
                else if(i == ']'){
                    if(k.top() == '[') {
                        k.pop();
                    }
                    else return false;
                }
                else if(i == '}'){
                    if(k.top() == '{') {
                        k.pop();
                    }
                    else return false;
                }
            }
            else return false;
        }
        return k.empty();
    }
};
