#include <iostream>
#include <stdexcept>

#define MaxSize 100
// 定义元素类型，这里假设元素类型为 int
typedef int ElemType;

// 定义顺序表的结构体
typedef struct {
  ElemType *data;  // 存放顺序表元素的数组
  int length;      // 顺序表的当前长度
  int capacity;    // 顺序表的最大容量
} SeqList;

void InitList(SeqList &list, int capacity) {
  list.data = new ElemType[capacity];
  list.length = 0;
  list.capacity = capacity;
}

bool InsertElem(SeqList &list, int index, ElemType elem) {
  if (index < 0 || index > list.length || list.length >= list.capacity) {
    return false;  // 插入位置非法或顺序表已满
  }

  // 从后往前循环
  for (int i = list.length; i > index; i--) {
    // 前项赋值给后项
    list.data[i] = list.data[i - 1];  // 将元素后移
  }
  list.data[index] = elem;
  list.length++;
  return true;
}
// SeqList &list 和 SeqList list 一个是按引用传递，一个是按值传递
// 按值传递：函数内部对参数的修改不会影响到原来的参数；可能会有性能开销，因为需要复制整个参数。
// 按引用传递：函数内部对参数的修改会影响到原来的参数；效率更高，因为不需要复制整个参数。
bool DeleteElem(SeqList &list, int index) {
  if (index < 0 || index >= list.length) {
    return false;
  }
  // 从前往后循环
  for (int i = index; i < list.length - 1; i++) {
    // 后项赋值给前项
    list.data[i] = list.data[i + 1];  // 将元素向前移动
  }
  list.length--;
  return true;
}

// 按值查找（顺序查找）
int LocateElem(SeqList &list, ElemType elem) {
  int i;
  for (i = 0; i < list.length; i++) {
    if (list.data[i] == elem) {
      return i + 1;
    }
  }
  return 0;
}

int FindMinELem(SeqList &list) {
  if (list.length == 0) {
    return -1;
  }
  int minIndex = 0;
  for (int i = 1; i < list.length; i++) {
    if (list.data[i] < list.data[minIndex]) {
      minIndex = i;
    }
  }
  return minIndex;
}

bool DeleteMinElem(SeqList &list) {
  if (list.length == 0) {
    throw std::runtime_error("this list is empty");
  }
  int minIndex = FindMinELem(list);
  int minVal = list.data[minIndex];
  list.data[minIndex] = list.data[list.length - 1];
  list.length--;
  return minVal;
}

void DisplayList(const SeqList &list) {
  for (int i = 0; i < list.length; i++) {
    std::cout << list.data[i] << " ";
  };
  std::cout << std::endl;
}

SeqList ReverseList(SeqList &list) {
  int i = 0;
  int j = list.length - 1;
  while (i < j) {
    int prev = list.data[i];
    list.data[i] = list.data[j];
    list.data[j] = prev;
    i++;
    j--;
  };
  return list;
}

SeqList RemoveAllOccurrences(SeqList &list, int x) {
  int j = 0;
  for (int i = 0; i < list.length; i++) {
    if (list.data[i] != x) {
      list.data[j] = list.data[i];
      j++;
    }
  }
  list.length = j;  // 更新顺序表的长度
  return list;
}

SeqList RemoveRangeList(SeqList &list, int s, int t) {
  if (list.length == 0) {
    throw std::runtime_error("this list is empty");
  };
  for (int i = s; i < t; i++) {
    RemoveAllOccurrences(list, i);
  };
  return list;
}

int main() {
  // SeqList list;
  std::cout << "hello world!!" << std::endl;

  SeqList list;
  InitList(list, 20);
  InsertElem(list, 0, 23);
  InsertElem(list, 1, 0);
  InsertElem(list, 2, 25);
  InsertElem(list, 3, 2);
  InsertElem(list, 4, 15);
  InsertElem(list, 5, 9);
  InsertElem(list, 6, 2);
  DisplayList(list);
  DeleteMinElem(list);
  DisplayList(list);
  ReverseList(list);
  DisplayList(list);
  // RemoveAllOccurrences(list, 2);
  // DisplayList(list);
  RemoveRangeList(list, 0, 10);
  DisplayList(list);
}
