#include <vector>
#include <cstddef>  // size_t
#include <memory>  // std::move()
#include <initializer_list>

template <typename T>
class PriorityQ {
public:
    // constructors
    PriorityQ() : size_(0), capacity_(10), heap_(11) { }
    PriorityQ(const PriorityQ<T> &pq) :
            size_(pq.size_),
            capacity_(pq.capacity_),
            heap_(pq.heap_)
        { }
    PriorityQ(PriorityQ<T> &&pq)
        : size_(pq.size_), capacity_(pq.capacity_)
        { heap_ = std::move(pq.heap_); }
    PriorityQ(std::initializer_list<T> il);
    PriorityQ(const std::vector<T> &v);
    
    template <typename Iterator>
    PriorityQ(Iterator first, Iterator last);

    ~PriorityQ()
        { }

    // member functions
    void Insert(const T &val); // insert a literal?
    T PopMax();
    bool IsEmpty() const;
    std::size_t Size() const;
    std::size_t Capacity() const;
    void Clear();

    // overload operators
    PriorityQ<T> operator=(const PriorityQ<T> &pq);
    PriorityQ<T> operator=(PriorityQ<T> &&pq);

//private:
    size_t size_;
    size_t capacity_;
    std::vector<T> heap_;

    // help functions used internally
    void PercolateUp(int hole, T val);
    void PercolateDown(int hole);
    void BuildHeap();
};

template <typename T>
PriorityQ<T>::PriorityQ(std::initializer_list<T> il)
    :  size_(il.size()), capacity_(size_ * 2 + 1),
       heap_(capacity_)
{
    for (auto it = il.begin(); it != il.end(); ++it)
        heap_[it - il.begin() + 1] = *it;
    BuildHeap();    
}

template <typename T>
void PriorityQ<T>::BuildHeap()
{
    for (int i = size_ / 2; i > 0; --i)
        PercolateDown(i);
}

// prerequisite: from hole down, only hole dissatisify
template <typename T>
void PriorityQ<T>::PercolateDown(int hole)
{
    int child;
    T tmp = heap_[hole];
    while (hole * 2 <= size_) {
        child = hole * 2;
        if (child + 1 <= size_ && heap_[child + 1] > heap_[child])
            ++child;
        if (heap_[child] > tmp) {
            heap_[hole] = heap_[child];
            hole = child;
        } else {
            break;
        }
    }
    heap_[hole] = tmp;
}

template <typename T>
void PriorityQ<T>::PercolateUp(int hole, T val)
{
    int parent;
    while (hole / 2 > 0) {
        parent = hole / 2;
        if (heap_[parent] < val) {
            heap_[hole] = heap_[parent];
            hole = parent;
        } else {
            break;
        }
    }
    heap_[hole] = val;
}
