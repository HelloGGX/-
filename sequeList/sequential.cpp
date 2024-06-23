#include <iostream>

#define MaxSize 100
// 定义元素类型，这里假设元素类型为 int
typedef int ElemType;

// 定义顺序表的结构体
typedef struct {
    ElemType* data; // 存放顺序表元素的数组
    int length;     // 顺序表的当前长度
    int capacity;   // 顺序表的最大容量
} SeqList;

bool InsertElem(SeqList& list, int index, ElemType elem){
   if(index < 0 || index > list.length || list.length >= list.capacity){
    return false;// 插入位置非法或顺序表已满
   }
   for(int i = list.length; i > index; i--){
    list.data[i] = list.data[i - 1]; // 将元素后移
   }
   list.data[index] = elem;
   list.length++;
   return true;
}

int main(){
   // SeqList list;
    std::cout << "hello world!!" << std::endl;
}
