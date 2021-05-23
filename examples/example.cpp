#include <vector>                   // vector
#include <iostream>                 // cout
#include "Dijkstra+BinaryHeap.hpp"  // algoritm_Dijkstra

// юзаем пространства имен, чтобы постоянно не писать "std::" или "itis::"
using namespace itis;
using namespace std;

// тут без комментариев
int main(){

  // создаем граф с помощью матрицы смежности
  vector<vector<int>> matrix = {
      {0,815,960,508,86},
      {529,0,599,467,247},
      {671,969,0,686,744},
      {12,963,440,0,35},
      {465,499,737,996,0},
  };

  // находим количество вершин в графе, оно равно 5
  int matrix_size = matrix.size();

  // назначаем вершину от которой и будем искать расстояния
  int vertex_start = 1;

  // запускаем алгоритм, возвращающий нам массив интов, содержащий на I-ом мете
  // длину от изначально заданной вершины до вершины под номером I
  vector<int> len_to = algoritm_Dijkstra(matrix, vertex_start);

  // выводим расстояния до вершин в +- понятном виде
  for (int i = 0; i < matrix_size; i++){
    cout << "Len to vert number " << to_string(i) << " from vert number 1" << " - " << len_to[i];
    cout << endl;
  }

  // отделяем вывод подсчитанного ручками ответа от работы программы
  cout << endl;

  // выводим наш заранее подсчитанный ответ
  cout << "correct answer is - [0, 585, 823, 508, 86]" << endl;

  return 0;
}