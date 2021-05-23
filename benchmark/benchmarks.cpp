#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <chrono>
#include <sstream>
#include "Dijkstra+BinaryHeap.hpp"


using namespace std;
using namespace itis;


static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};


long long int *check_algoritm(const string path){
  long long int *time_list = new long long int [10];
  for (int i = 0; i < 10; i++) {
    string line = "122";
    auto input_file = ifstream(path);
    vector<vector<int>> matrix;
    vector<int> line_in_matrix;
    basic_string<char> num;
    if (input_file.is_open()) {
      getline(input_file, line);
      while (line != "") {
        stringstream sstream(line);
        string token;
        while(getline(sstream, token, ',')){
          line_in_matrix.push_back(stoi(token));
        }
        matrix.push_back(line_in_matrix);
        line_in_matrix.clear();
        getline(input_file, line);
        if (line == "") {
          break;
        }
      }
    }
    int some_random_vert = 1;

    // начало замерения
    const auto time_point_before = chrono::steady_clock::now();
    // сама функция, нам без разницы от какой вершины считать
    auto len = algoritm_Dijkstra(matrix, some_random_vert);

    const auto time_point_after = chrono::steady_clock::now();
    const auto time_diff = time_point_after - time_point_before;
    const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    time_list[i] = time_elapsed_ns/1000;

    matrix.clear();
    input_file.close();
  }
  return time_list;
}


int main() {
  const auto path_inputfile = string(kProjectPath) + "/dataset/data/main_statistic.csv";
  const auto py_path = "python " + string(kProjectPath) + "/dataset/generate_dataset_csv.py";
  const string delimeter = "/";
  cout << "Run data_creator.py" << endl;
  system(py_path.c_str());
  cout << endl << endl;
  cout << "Path to the 'dataset/' folder: " << string(kDatasetPath) << endl;
  cout << "Path to file: " << path_inputfile << endl;
  ofstream file;
  file.open(path_inputfile);
  if (file.is_open()){
    cout << endl << "File opened successfully" << endl << endl;
    file << "Function"
         << delimeter << "Set"
         << delimeter << "Set size"
         << delimeter << "Run number"
         << delimeter << "Time" <<  endl;
  }

  int *amount = new int [10] {5, 10, 25, 50, 100, 250, 500, 1000, 1500, 2500};
  string folders[10] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
  cout << "data at: " << string(kDatasetPath) + "/database/insert" << endl;
  cout << "start checking" << endl;

  for (int j = 0; j < 10; j++){
    int amount_ = amount[j];
    for (string dir : folders){
      string data_path = string(kDatasetPath)
                         + "/database/insert/" + dir + "/Random_"
                         + to_string(amount[j]) + "x" + to_string(amount[j]) + ".csv";
      long long int* time_list = check_algoritm(data_path);

      for (int i = 0; i < 10; i++){
        file << "Dijkstra"
                    + delimeter + dir
                    + delimeter + to_string(amount_)
                    + delimeter + to_string(i + 1)
                    + delimeter + to_string(time_list[i]) << endl;
      }
    }
  }
  return 0;
}