#include <iostream>
using namespace std;
template<class type>
class item {
private:
  type data;
  int priority;
public:
  void set_data(type data) { this->data = data; }
  void set_priority(int priority) { this->priority = priority; }
  type get_data() { return data; }
  int get_priority() { return priority; }
};
template<class type>
class PriorityQueue {
public:
  PriorityQueue(int array_size) {
    size = array_size;
    length = 0;
    data = new item<type>[size];
    front = 0;
    rear = size - 1;
  }

  ~PriorityQueue() {
    delete[] data;
  }
  bool is_empty() { // Constant time (O(1))
    return length == 0;
  }

  void enqueue(type val, int priority) { // Linear time (O(N))
    if (is_full()) {
      cout << "Queue is full with size " << size << endl;
      return;
    }
    rear = (rear + 1) % size;
    data[rear].set_data(val);
    data[rear].set_priority(priority);
    length++;
   int index=rear;
      while(index!=front&&data[index].get_priority()<data[(index-1)%size].get_priority()){
          swap(data[index],data[(index-1)%size]);
             index=(index-1)%size;
   }


  }  void dequeue() { // Constant time (O(1))
    if (is_empty()) {
      cout << "Queue is empty" << endl;
      return;
    }

    front = (front + 1) % size;
    length--;
  }

  bool isfind(type value) { // Linear time (O(N))
    for (int i = 0; i < length; i++) {
      int index = (front + i) % size;
      if (value == data[index].get_data()) {
        return true;
      }
    }
    return false;
  }

  void display() { // Linear time (O(N))
    cout << "********all elements**********\n";
    if (is_empty()) {
      cout << "Queue is empty" << endl;
      return;
    }

    for (int i = 0; i < length; i++) {
      int index = (front + i) % size;
      cout << "Item " << i + 1 << " : " << data[index].get_data() << " (priority: " << data[index].get_priority() << ")" << endl;
    }
  }
  bool is_full() { // Constant time (O(1))
    return length == size;
  }
private:
  int size;
  int length;
  item<type> *data;
  int front;
  int rear;
};
int main() {
  PriorityQueue<int> m(100);
   for(int i=0;i<10;i++)
    m.enqueue(i,i-1);
     m.dequeue();
     m.enqueue(100,-100);
     m.display();

    return 0;
}
