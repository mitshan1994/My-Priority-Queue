#include <iostream>
#include "priority_queue.h"

using namespace std;

int main()
{
    PriorityQ<int> pq{10, 3, 2, 100, 50, 60, 55};
    for (int i = 1; i <= pq.size_; ++i)
        cout << pq.heap_[i] << "  ";
    cout << endl;

    return 0;
}
