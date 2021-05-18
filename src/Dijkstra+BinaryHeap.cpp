#include "Dijkstra+BinaryHeap.hpp"
#include <vector>
#include <stdexcept>  // logic_error


#define INF 10000000


namespace itis {

  BinaryHeap::BinaryHeap() {
      data_ = new std::vector<std::pair<int, int>>;
  };


  BinaryHeap::~BinaryHeap(){
    size_ = 0;
    data_ -> clear();
    delete data_;
    data_ = nullptr;
  }


  std::pair<int, int> BinaryHeap::top_item() {
    if (size_ <= 0) {
      throw std::logic_error("No top item");
    }
    return data_ -> at(0);
  }


  std::pair<int, int> BinaryHeap::pop() {
    if (size_ <= 0){
      throw std::logic_error("size_ is 0 and You want to pop -_-");
    }

    size_ -= 1;
    std::pair<int, int> pair_to_return = data_ -> at(0);
    data_ -> at(0) = data_ -> at(size_);
    data_ -> pop_back();

    return_to_normal(0);
    return pair_to_return;
  }


  void BinaryHeap::return_to_normal(int vertex){
    int left_child = vertex * 2 + 1;
    int right_child = vertex * 2 + 2;
    int corrent_vert = vertex;
    if ((left_child < size_) &&
        (data_ -> at(left_child).first <= data_ -> at(right_child).first) &&
        (right_child < size_)){
      swap(corrent_vert, left_child);
      corrent_vert = left_child;
    }
    if ((right_child < size_) &&
        (data_ -> at(right_child).first < data_ -> at(left_child).first) &&
        (left_child < size_)){
      swap(corrent_vert, right_child);
      corrent_vert = right_child;
    }
    if (corrent_vert == vertex){
      return;
    }
    return_to_normal(corrent_vert);
  }


  void BinaryHeap::swap(int first, int second) {
    std::pair<int, int> to_swap = data_ -> at(first);
    data_ -> at(first) = data_ -> at(second);
    data_ -> at(second) = to_swap;
  }


  void BinaryHeap::push_back(std::pair<int, int> new_pair) {
    data_->push_back(new_pair);
    down_up_sort(size_);
    size_ += 1;
  }


  void BinaryHeap::down_up_sort(int index) {
    if (index == 0){
      return;
    }

    int parent = (index - 1)/2;
    if (data_ -> at(parent).first > data_ -> at(index).first) {
      swap(parent, index);
      down_up_sort(parent);
    }
  }


  bool BinaryHeap::empety() {
    return size_ == 0;
  }


  std::vector<int> algoritm_Dijkstra(const std::vector<std::vector<int>>& matrix, int vertex) {
    int vert_in_graph = matrix.size();
    vertex -= 1;
    std::vector<int> d (vert_in_graph, INF);
    d[vertex] = 0;
    BinaryHeap heap = BinaryHeap();
    heap.push_back(std::make_pair(0, vertex));
    std::pair<int, int> highest_pair;

    while (!heap.empety()){
      highest_pair = heap.pop();

      if (highest_pair.first > d[highest_pair.second]){
        continue;
      }

      for (int i = 0; i < vert_in_graph; i++){
        int len = matrix[highest_pair.first][i];
        if ((d[i] > d[highest_pair.first] + len) && (len > 0)){
          d[i] = d[highest_pair.first] + len;
          heap.push_back(std::make_pair(d[i], i));
        }
      }
    }

    return d;
  }


}  // namespace itis
