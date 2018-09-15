## 算法练习（C）

> 此仓库是本人在看《算法》一书的过程中学习到的相关知识以及调试的代码库，代码主要用的是 C 语言，涉及以下算法：

### 排序算法
+ 选择排序
+ 冒泡排序
+ 插入排序（需要交换元素）
+ 插入排序（不需要交换元素）
+ 希尔排序
+ 归并排序
+ 快速排序

### 双端链表
+ 创建链表
+ 链表节点插入
+ 链表节点修改
+ 删除指定节点
+ 查询指定节点
+ 从链头遍历
+ 从链尾遍历

### 树
+ 二叉树的创建
+ 二叉树的插入
+ 二叉树的查询
+ 二叉树的修改
+ 二叉树的删除
+ 二叉树的先序遍历

### 字典
字典的哈希实现主要是参考[write-a-hash-table](jamesroutley/write-a-hash-table)，原作者写得挺好的，通俗易懂，所以我花了点时间把这篇文章翻译成了中文版：[young/write-a-hash-table](https://github.com/yigger/write-a-hash-table/blob/master/.translations/cn/README.md)

+ 字典创建
+ 新增键值对
+ 修改相应的键的值
+ 字典查询
+ 删除键
+ 字典扩容与缩减容量
+ 计算 hashcode

### 测试相关

[Cpputest](#user-content-使用-cpputest-测试-c-语言)

## 执行
```
mkdir build

cmake ..

make && make test
```

### 使用 cpputest 测试 C 语言
> cpputest 是一个用于测试 c++ 的库，但是同时也支持 C 的单元测试，用法也是十分简单，安装就不介绍了，请移步到 https://github.com/cpputest/cpputest

下面通过本项目简单介绍一下怎么进行测试

1. 在根路径下创建一个文件夹， `mkdir test`
2. 创建测试文件 grapTest.cpp ，下面会用来测试图的相关函数
3. 创建文件 graph_test.c 
```
file: graph_test.c
// 需要引入
#include "CppUTest/TestHarness_c.h"
// 引入需要的头文件
#include "graph.h"

// 定义待测试的变量
static Graph graph;
static int stat;

// 定义测试组为 GraphTest 的 before_script (有需要可定义，无需要不定义也可)
TEST_GROUP_C_SETUP(GraphTest) {
  // 以下代码将会在测试用例 调用前 执行
  stat = createGraph(&graph);
};

// 定义测试组为 GraphTest 的 after_script (同上)
TEST_GROUP_C_TEARDOWN(GraphTest) {
  // 在所有测试用例调用完 之后 执行
  destroy(graph);
};

// 定义第一个测试，用来校验 graph 是否可以正常初始化
TEST_C(GraphTest, InitGraph) {
  // 创建一个图的数据结构
  stat = createGraph(&graph);
  // 判断是否创建成功
  CHECK_EQUAL_C_INT(OK, stat);

  // 判断方法：
  CHECK_EQUAL_C_BOOL(expected,actual);
  CHECK_EQUAL_C_INT(expected,actual);
  CHECK_EQUAL_C_UINT(expected,actual);
  CHECK_EQUAL_C_LONG(expected,actual);
  CHECK_EQUAL_C_ULONG(expected,actual);
  CHECK_EQUAL_C_LONGLONG(expected,actual);
  CHECK_EQUAL_C_ULONGLONG(expected,actual);
  CHECK_EQUAL_C_REAL(expected,actual,threshold);
  CHECK_EQUAL_C_CHAR(expected,actual);
  CHECK_EQUAL_C_UBYTE(expected,actual);
  CHECK_EQUAL_C_SBYTE(expected,actual);
  CHECK_EQUAL_C_STRING(expected,actual);
  CHECK_EQUAL_C_POINTER(expected,actual); /* v3.8 */
  CHECK_EQUAL_C_BITS(expected, actual, mask); /* v3.8, pending */
  FAIL_TEXT_C(text);
  FAIL_C();
  CHECK_C(condition);
  CHECK_C_TEXT(condition, text);
};
```

以上，已经定义好了我们的图数据结构的第一个测试用例，下面通过 graphTest.cpp 进行调用（因为 cpputest 属 c++ 框架，不能直接运行 graph_test.c）

```
file: graphTest.cpp
// 引入 cpputest 所需文件
#include "CppUTest/TestHarness_c.h"
#include "CppUTest/CommandLineTestRunner.h"

// 触发 graph_test.c 编写的 before_script / after_script
TEST_GROUP_C_WRAPPER(GraphTest) {
  TEST_GROUP_C_SETUP_WRAPPER(GraphTest);
  TEST_GROUP_C_TEARDOWN_WRAPPER(GraphTest);
};

// 触发 graph_test.c 编写的 InitGraph 测试用例
TEST_C_WRAPPER(GraphTest, InitGraph);

// 如果需要定义更多，在下面继续编写就可以了，但需要先到 graph_test.c 进行编写相应的测试
TEST_C_WRAPPER(GraphTest, addNode);
TEST_C_WRAPPER(GraphTest, addEdge);
...

// 最后，执行所有测试
int main(int argc, char **argv)
{
  return RUN_ALL_TESTS(argc, argv);
}

```
