class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            int ans;
            int lenhay = haystack.length();
            int lennee = needle.length();
            if (lennee == 0)
            {
                return 0;
            }
            else if (lennee > lenhay || lenhay==0)
            {
                return -1;
            }
            for (int i = 0; i < lenhay; i++)
            {
                if (haystack[i] != needle[0])
                {
                    continue;
                }
                else
                {

                    if (i + lennee > lenhay)
                    {
                        return -1;
                    }
                    else
                    {
                        bool check = true;
                        int a = 0;
                        for (int j = i; j < i + lennee; j++)
                        {
                            if (haystack[j] != needle[a])
                            {
                                check = false;
                                break;
                            }
                            else
                            {
                                a++;
                            }
                        }
                        if (check)
                        {
                            return i;
                        }
                    }
                }
            }
            return -1;
        }
};