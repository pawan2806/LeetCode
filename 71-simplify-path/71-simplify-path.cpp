class Solution
{
    public:
        string simplifyPath(string path)
        {

            string temp = "";
            path = path + "/";
            stack<string> s;
            int n = path.length();
            for (int i = 0; i < n; i++)
            {
                if (path[i] == '/')
                {
                    if (temp == "..")
                    {
                        if (s.size())
                        {
                            s.pop();
                        }
                    }
                    else if (temp != "" && temp != ".")
                    {
                        s.push(temp);
                    }
                    temp = "";
                }
                else
                {
                    temp += path[i];
                }
            }
            if (temp != "" && temp != ".")
            {
                s.push(temp);
            }
            temp = "";
            temp+="/";
            vector<string> ans;
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
            reverse(ans.begin(), ans.end());
            for(int i=0;i<ans.size();i++){
                temp+=ans[i];
                if(i!=ans.size()-1){
                    temp+="/";
                }
            }

            return temp;

           	//        	// get current part: without /
           	//         string front;
           	//         int i = 1;
           	//         while(i < path.size() && path[i] != '/') front.push_back(path[i++]);

           	//        	// check . ..
           	//         if(front == "." || front.empty()) {}
           	//         else if(front == "..") {
           	//            	// popping back the directory
           	//             while(!out.empty() && out.back() != '/') out.pop_back();
           	//            	// popping back the redundent backslash
           	//             while(!out.empty() && out.back() == '/') out.pop_back();
           	//         } else {
           	//            	// concatenate the front part of the remained input string with the output path
           	//            	// join with backslash
           	//             out = out + "/" + front;
           	//         }
           	//         return simplify(path.substr(i), out);
           	//     }

           	//     string simplifyPath(string path) {
           	//         string out;
           	//         simplify(path, out);
           	//         return out.empty() ? "/" : out;
        }
};