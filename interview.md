## CPP
### cpp内存对象模型

回答下列sizeof的输出
```
class A {};: sizeof(A) = ?;

class A { virtual Fun(){} };: sizeof(A) = ?;

class A { static int a; };: sizeof(A) = ?;

class A { int a; };: sizeof(A) = ?;

class A { static int a; 
int b; }; sizeof(A) = ?;

class A { static int a; 
int b; void func(); }; sizeof(A) = ?;

class A { std::string a;}  A eg; eg.a = “hello”; sizeof(eg)=?
```
### 基本容器的原理

####  容器底层数据结构
Q: STL中vector, map, set, unordered_map底层的数据结构是?

#### vector原理
有一个类Class Myclass，他的的构造函数会输出字符A；向vector中插入N次（10000）这个对象. 代码如下：

Q1:push_back过程中，触发了多少次内存申请？会输出多少个A？有何方法来优化上面这个操作。
Q2: ref 与 *p的值分别是多少?

```
class A {
	public A(): d(1){
		std::cout << "A" << std::endl;
	}
	int d;
}
vector<A> arr;

A a;
arr.push_back(a);
auto &ref= arr[0];
int* &p= &arr[0];
for (int i = 0; i<1000; i++) {
	arr.push_back(a);
}

```

#### 迭代器原理
Q:Set中存放着1、3~99一共50个元素，it10 = myset.find(10), it9=myset.find(9), 继续插入90~110共20个元素，此时两个it本身是否发生变化，it本身指向的元素是否发生变化？

#### shared_ptr
2.shared_ptr
2.1 为什么要使用shared ptr？
2.2 shared ptr是线程安全吗？
2.3 如何来实现一个shared ptr，简述原理
2.4 如果要实现一个线程安全的shared ptr，需要怎么做？
2.5 shared_ptr 有哪些设计和使用上的缺陷？应该如何避免？（weak ptr）
## Golang

## OS
1.stack和heap有什么区别？
2.内存泄露和crash都有哪些表现，如何排查和避免？
