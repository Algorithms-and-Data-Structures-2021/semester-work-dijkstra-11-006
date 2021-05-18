#pragma once
#include <vector>

// Заголовочный файл с объявлением структуры данных

namespace itis {
  ///TODO написать описание методов клса КУЧИ, что они вообще делают и возвращают
  ///TODO ну и про алгоритм Дейкстры не забыть

  std::vector<int> Dijkstra(std::vector<std::vector<int>>);

  struct BinaryHeap{
   private:
    int size_{0};
    std::vector<std::pair<int, int>>* data_{nullptr};

    void down_up_sort(int);

    void return_to_normal(int);

    void swap(int, int);

   public:
    BinaryHeap();

    std::pair<int, int> top_item();

    std::pair<int, int> pop();

    void push_back(std::pair<int, int>);

    bool empety();

    ~BinaryHeap();

    int size() const {
      return size_;
    }
  };
}  // namespace itis