class Solution {
public:
    
    vector<string> ans;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    class Trie {
        public:
            Trie *arr[26];
            bool isEnd = false;
    };
    
    void insert(string &word, Trie* root){
        Trie *cur = root;
        for(int i=0; i<word.size(); ++i){
            int idx = word[i]-'a';
            if(!cur->arr[idx]){
                cur->arr[idx] = new Trie();
            }
            cur=cur->arr[idx];
        }
        cur->isEnd = true;
        return;
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        int row = board.size(), col = board[0].size();
        if(x<0 || x>=row || y<0 || y>=col || board[x][y]=='*') return false;
        return true;
    }
    
    void search(vector<vector<char>>& board, int x, int y, Trie* root, string& str){
        if(board[x][y]=='*') return;
        
        int idx = board[x][y]-'a';
        if(!root->arr[idx]) return;
        
        str.push_back(board[x][y]);
        
        char ch = board[x][y];
        board[x][y]='*';
        
        if(root->arr[idx]->isEnd){
            ans.push_back(str);
            root->arr[idx]->isEnd = false;
        }
        
        for(int i=0;i<4;++i){
            int x1 = x+dx[i], y1 = y+dy[i];
            if(isValid(board,x1,y1)) search(board,x1,y1,root->arr[idx],str);
        }
        
        board[x][y]=ch;
        str.pop_back();
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        for(auto &word : words) insert(word,root);
        
        int row = board.size(), col = board[0].size();
        string str="";
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                search(board,i,j,root,str);
            }
        }
        
        return ans;
    }
};