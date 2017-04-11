#include <iostream>
#include <cstdlib>  // exit()
#include <vector>
#include <cstddef>  // size_t
#include <memory>  // std::move()
#include <initializer_list>

template <typename T>
class PriorityQ {
public:
    // constructors
    PriorityQ() : size_(0), heap_(11) { }
    PriorityQ(const PriorityQ<T> &pq) :
            size_(pq.size_),
            heap_(pq.heap_)
        { }
    PriorityQ(PriorityQ<T> &&pq) : size_(pq.size_)
        { heap_ = std::move(pq.heap_); }
    PriorityQ(std::initializer_list<T> il);
    PriorityQ(const std::vector<T> &v);
    
    template <typename Iterator>
    PriorityQ(Iterator first, Iterator last);

    ~PriorityQ()
        { }

    // member functions
    void Insert(const T &val);
    // Need user to test is empty before calls
    T PopMax();
    bool IsEmpty() const;
    std::size_t Size() const;
    void Clear();

    // overload operators
    PriorityQ<T> operator=(const PriorityQ<T> &pq);
    PriorityQ<T> operator=(PriorityQ<T> &&pq);

    // helper function
    void Print() const;

private:
    size_t size_;
    std::vector<T> heap_;

    // help functions used internally
    void PercolateUp(int hole,const T &val);
    void PercolateDown(int hole);
    void BuildHeap();
};

template <typename T>
PriorityQ<T>::PriorityQ(std::initializer_list<T> il)
    :  size_(il.size()), heap_(2 * size_ + 1)
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
void PriorityQ<T>::PercolateUp(int hole, const T &val)
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

template <typename T>
void PriorityQ<T>::Insert(const T &val)
{
    if (size_ == heap_.size() - 1)
        heap_.resize(2 * (size_ + 1));
    ++size_;
    PercolateUp(size_, val);
}

template <typename T>
PriorityQ<T>::PriorityQ(const std::vector<T> &v)
    : size_(v.size()), heap_(2 * size_ + 1)
{
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        heap_[it - v.cbegin() + 1] = *it;
    BuildHeap();
}

template <typename T>
template <typename Iterator>
PriorityQ<T>::PriorityQ(Iterator first, Iterator last)
    : size_(last - first), heap_(2 * size_ + 1)
{
    for (auto it = first; it != last; ++it)
        heap_[it - first + 1] = *it;
    BuildHeap();
}

template <typename T>
T PriorityQ<T>::PopMax()
{
    if (size_ == 0) {
        std::cerr << "Pop to a zero-size priority queue!!!\n";
        exit(EXIT_FAILURE);
    }
    T tmp = heap_[1];
    heap_[1] = heap_[size_];
    --size_;
    PercolateDown(1);
    return tmp;
}

template <typename T>
bool PriorityQ<T>::IsEmpty() const
{
    return size_ == 0;
}

template <typename T>
std::size_t PriorityQ<T>::Size() const
{
    return size_;
}

template <typename T>
void PriorityQ<T>::Clear()
{
    size_ = 0;
}

template <typename T>
PriorityQ<T> PriorityQ<T>::operator=(const PriorityQ<T> &pq)
{
    size_ = pq.size_;
    heap_ = pq.heap_;
}

template <typename T>
PriorityQ<T> PriorityQ<T>::operator=(PriorityQ<T> &&pq)
{
    size_ = pq.size_;
    heap_ = std::move(heap_);
}

template <typename T>
void PriorityQ<T>::Print() const
{
    if (size_ == 0) {
        std::cout << "Empty priority queue.\n";
        return;
    }
    for (int i = 1; i <= size_; ++i)
        std::cout << heap_[i] << " ";
    std::cout << std::endl;
}
