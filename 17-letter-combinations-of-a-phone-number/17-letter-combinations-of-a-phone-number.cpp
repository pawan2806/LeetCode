class Solution {
public:
    vector<string> ans;
map<int, string> m;


void util(string A, int start, string gg){
    if(start==A.length()){
        ans.push_back(gg);
        return ;
    }
    int x=A[start]-'0';
    string temp=m[x];
        
        for(int j=0;j<temp.length();j++){
          
            util(A, start+1, gg+temp[j]);
            //gg=gg.substr(gg.length()-1);
        }

}
    vector<string> letterCombinations(string digits) {
         m[0]="0";
    m[1]="1";
    m[2]="abc";
m[3]="def"; 
m[4]="ghi"; 
m[5]="jkl";m[6]="mno"; m[7]="pqrs"; m[8]="tuv";m[9]="wxyz"; 
    ans.clear();
   if(digits.length()==0){
       return ans;
   }
    util(digits, 0, "");
    //sort(ans.begin(), ans.end());
    return ans;
    }
};