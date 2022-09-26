typedef pair<int, int> pii;

class SnapshotArray
{

    private:

        int n = 0;
    vector<vector < pii>> m;
    public:

        SnapshotArray(int length)
        {
            m = vector<vector < pii>> (length, vector<pii> (1,
            {
                0,
                0 }));	// every element is 0 in beginning
        }

    void set(int index, int val)
    {

        int x = m[index].size();

        if (m[index][x - 1].second == n)	// if no new snaps were taken after last entry
            m[index][x - 1].first = val;	// then update the last entry
        else
            m[index].push_back({ val,
                n });	// else make a new entry with new snap_id

    }

    int snap()
    {
        n++;
        return n - 1;
    }

    int get(int index, int snap_id)
    {

        int l = 0, h = m[index].size() - 1;

        while (l <= h)
        {
        	// binary search for first index with snap_id equal or lower

            int mid = l + (h - l) / 2;

            if (m[index][mid].second == snap_id)
                return m[index][mid].first;
            else if (m[index][mid].second > snap_id)
                h = mid - 1;
            else
                l = mid + 1;
        }

        return m[index][h].first;
    }
};

/**
 *Your SnapshotArray object will be instantiated and called as such:
 *SnapshotArray* obj = new SnapshotArray(length);
 *obj->set(index,val);
 *int param_2 = obj->snap();
 *int param_3 = obj->get(index,snap_id);
 */