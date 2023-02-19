class RandomizedSet
{
    ///Time Complexity O(1)
    ///Space Complexity O(N)
public:
    vector<int> v;
    unordered_map<int,int> mp;
    int i;
    RandomizedSet()
    {
        i=-1;
    }
    bool insert(int val)
    {
        if(mp.find(val) == mp.end())
        {
            v.push_back(val);
            i++;
            mp[val] = i;
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if(i >= 0 && mp.find(val) != mp.end())
        {
            int idx = mp[val];
            swap(v[idx], v[i]);
            mp[v[idx]] = idx;
            mp.erase(val);
            v.pop_back();
            i--;
            return true;
        }
        return false;
    }
    int getRandom()
    {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
