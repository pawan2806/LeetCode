class Solution {
public:
    string ans;
    string decodeString(string s) {
        int len=s.length();
        if(len<=3){
            return s;
        }
        stack<int> intst;
        stack<string> strst;
        int ptr=0;
        string ans="";
        string res="";
        while(ptr<len){
            char present=s[ptr];
            if((present-'0'>=0) && (present-'0'<=9)){
                int num=0;
                while((present-'0'>=0) && (present-'0'<=9)){
                    
                    num=num*10 + present-'0';
                    ptr++;
                    present=s[ptr];
                    
                }
                intst.push(num);
            } else if(present=='['){
                strst.push(res);
                res="";
                ptr++;
            } else if(present==']'){
                string gg=strst.top();
                strst.pop();
                int num=intst.top();
                intst.pop();
                for(int count=1;count<=num;count++){
                    gg+=res;
                }
                res=gg;
                ptr++;
            } else {
                res+=s[ptr];
                ptr++;
            }
        }
        
        
        
        return res;
        
        
    }
};