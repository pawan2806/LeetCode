class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        auto light = people.begin(), heavy = people.end() - 1;
        int boats = 0;
        while(light <= heavy) {
            if(*light + *heavy <= limit)
                light++;
            boats++;
            heavy--;
        }
        return boats;
    }
};