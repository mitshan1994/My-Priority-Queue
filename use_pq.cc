#include <iostream>
#include <vector>
#include "priority_queue.h"

using namespace std;

// need to change all fields to public to use this test function
void original_test();

int main()
{
    PriorityQ<int> pq{1, 2, 3, 5, 4};
    pq.Print();
    
    return 0;
}

void original_test()
{
    // PriorityQ<int> pq{10, 3, 2, 100, 50, 60, 55};
    // for (int i = 1; i <= pq.size_; ++i)
    //     cout << pq.heap_[i] << "  ";
    // cout << endl;
    // pq.Insert(1000);
    // pq.Insert(39);
    // for (int i = 1; i <= pq.size_; ++i)
    //     cout << pq.heap_[i] << "  ";

    // cout << "\n Stage 2:\n";
    // vector<double> v = {1.5, 3, 4, 2, 5, 0, -3, 6};
    // PriorityQ<double> pq2(v);
    // for (int i = 1; i <= pq2.size_; ++i)
    //     cout << pq2.heap_[i] << "  ";
    // cout << endl;

    // PriorityQ<double> pq3(v.begin(), v.end());
    // for (int i = 1; i <= pq3.size_; ++i)
    //     cout << pq3.heap_[i] << "  ";
    // cout << endl;
    // cout << "pq3.PopMax() = " << pq3.PopMax() << endl;
    // for (int i = 1; i <= pq3.size_; ++i)
    //     cout << pq3.heap_[i] << "  ";
}
