### 优先队列
#### Definition
PQ是一个优先队列(Priority Queue),如果PQ中的元素都具有一个
优先级,可以向PQ中添加元素;从PQ中弹出元素,每次弹出的元素具有最高优先级.

#### 接口
类型`T`应当是Comparable(使用<来比较),默认实现是最大堆.

构造函数(析构函数):

	template <typename T> // default
	
	// 默认构造函数,元素类型为T
	PriorityQ<T>();
	
	// 拷贝构造函数
	PriorityQ<T>(const PriorityQ<T> &pq);
	// 移动构造函数
	PriorityQ<T>(PriorityQ<T> &&pq);
	
	// 列表初始化构造函数
	PriorityQ<T>(initializer_list<T> il);
	
	// vector初始化构造函数
	PriorityQ<T>(const vecotr<T> &v);
	
	// 从iterator初始化构造函数
	template <typename T, typename Iterator>
	PriorityQ<T>(Iterator first, Iterator last);
	
	~PriorityQ();
	
成员函数:(元素类型简记为value_type)

	// insert val into priority queue
	void Insert(const value_type &val);
	
	// get the maximal priority element and delete it
	value_type PopMax();
	
	// return true if priority queue has no elements in it
	bool IsEmpty() const;
	
	// return size of the priority queue
	size_t Size() const;
		
	// clear the priority queue (after it, size = 0)
	void Clear();
	
	// print elements from left to right, top to down
	void Print() const;
	
运算符重载:

	// 拷贝赋值运算符
	PriorityQ<T> operator=(const PriorityQ &pq);
	// 移动赋值运算符
	PriorityQ<T> operator=(PriorityQ &&pq);

#### 内部细节
内部通过一个vector来存储数据,下标为1的是根节点,通过堆技术来实现.  
私有变量:

	size_t size_;
	vector<T> heap_;
	
私有函数:

	// 从hole节点(作为空节点),开始上滤,找到val的位置并放进去
	void PercolateUp(int hole, T val);
	
	// hole处为开始节点,开始下滤.
	// hole处的值不符合堆的性质,因此要调整位置.
	void PercolateDown(int hole);

	// 当由一组初始值来初始化堆时,将之调整成堆
	void BuildHeap();
