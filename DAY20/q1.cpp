#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache
{
    int capacity;
    list<pair<long long, long long>> cache;
    unordered_map<long long,
                  list<pair<long long, long long>>::iterator> mp;
public:
    LRUCache(int cap)
    {
        capacity = cap;
    }
    long long get(long long key)
    {
        if(mp.find(key) == mp.end())
            return -1;
        auto it = mp[key];
        long long value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();
        return value;
    }
    void put(long long key, long long value)
    {
        if(mp.find(key) != mp.end())
        {
            cache.erase(mp[key]);
        }
        else if(cache.size() == capacity)
        {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};
int main()
{
    int capacity;
    cin >> capacity;
    int q;
    cin >> q;
    LRUCache lru(capacity);
    while(q--)
    {
        string op;
        cin >> op;
        if(op == "PUT")
        {
            long long key, value;
            cin >> key >> value;
            lru.put(key, value);
        }
        else if(op == "GET")
        {
            long long key;
            cin >> key;
            cout << lru.get(key) << endl;
        }
    }
    return 0;
}