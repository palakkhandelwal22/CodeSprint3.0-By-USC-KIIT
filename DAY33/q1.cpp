#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Passenger 
{
    long long priority;
    int arrival;
    long long id;
    bool operator<(const Passenger& other) const 
    {
        if (priority == other.priority)
            return arrival > other.arrival; 
        return priority < other.priority;   
    }
};
int main() 
{
    int N;
    cin >> N;
    priority_queue<Passenger> pq;
    for (int i = 0; i < N; i++) 
    {
        long long id, priority;
        cin >> id >> priority;
        pq.push({priority, i, id});
    }
    while (!pq.empty()) 
    {
        cout << pq.top().id << "\n";
        pq.pop();
    }
    return 0;
}