#include <iostream>
#include <vector>
#include <ctime>
#include <new>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

struct Node_Pair {
  int mult;
  int path_val;
};

struct Path_Pair {
  int mult;
  vector<int> path_val;
};

vector<Node_Pair> second_path;
vector<Path_Pair> path_list;
int multiplier;
vector<int> adjacency_matrix[1000]; 

bool dfs_recurse(vector<int> graph[multiplier], int starting_point, vector<int> path, time_t start, int multiply){
  int path_size = static_cast<int>(path.size());
  if ((starting_point == 0) && (path_size > 0)){
    cout << "Multiplier: " << multiply << " is here" << endl;
    Node_Pair newpair;
    newpair.mult = multiply;
    newpair.path_val = path[1];

    Path_Pair newpath;
    newpath.mult = multiply;
    newpath.path_val = path;
    newpath.path_val.push_back(0);

    second_path.push_back(newpair);
    path_list.push_back(newpath);
    int * myarray = new int[1000000000000]; 
    return true;
  }

  int graph_size = static_cast<int>(graph[starting_point].size());
  for (int i = 0; i < graph_size; i++){
    int index = graph[starting_point][i];
    int size = static_cast<int>(path.size());
    if (((!binary_search(path.begin(), path.end(), index)) || (index == 0)) && (size < 999)){
      if ((time(0) - start) <= 120) {
        vector<int> new_path;
        for (int i=0; i < path.size(); i++) {
          new_path.push_back(path[i]); 
        }
        new_path.push_back(starting_point);
        dfs_recurse(graph, index, new_path, start, multiply);
      } else {
        cout << "No quotient set" << endl;
        int * myarray = new int[1000000000000]; 
        return false;
      }
    } else {
      continue;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> pathways_list;

  int base;
  int missing_number_value;
  int multiplier_val;
  cout << "What do you want your multiplier to be? ";
  cin >> multiplier_val;

  cout << "What do you want your base to be? ";
  cin >> base;

  cout << "How many missing numbers do you want? ";
  cin >> missing_number_value;
  int missing_numbers[missing_number_value];

  for (int i = 0; i < missing_number_value; i++) {
    cout << "Please input a number. ";
    cin >> missing_numbers[i];
  }
  for (int multiplier = 1; multiplier <= multiplier_val; multiplier++) {
    pathways_list.clear();

    double start = time(0);
    for (int carryFrom = 0; carryFrom < multiplier; carryFrom++) {
      for (int read = 0; read < base; read++) {
          int total = carryFrom + (multiplier*read);
          int write = total % base;
          int carryTo = (total-write)/base;

          bool readFound = false;
          bool writeFound = false;

          for (int i = 0; i < missing_number_value; i++) {
            if (missing_numbers[i] == read) {
              readFound = true;
              break;
            }
          }

          for (int i = 0; i < missing_number_value; i++) {
            if (missing_numbers[i] == write) {
              writeFound = true;
              break;
            }
          }

          if (!(readFound || writeFound)) {
                vector<int> v;
                v.push_back(carryFrom);
                v.push_back(carryTo);
                
                bool vectorFound = false;
                for (int i = 0; i < pathways_list.size(); i++) {
                  vector<int> path = pathways_list[i];
                  if (path == v)  {
                    vectorFound = true;
                    break;
                  }
                }

                if (!vectorFound) {
                  pathways_list.push_back(v);
                }
              }
        }
      }
    double start1 = time(0);
    cout << start1 - start << endl;

    vector<int> v;
    fill_n(adjacency_matrix, 1000, v);
    
    for (int i = 0; i < multiplier; i++) {
      vector<int> v;
      adjacency_matrix[i] = v;
    }
    double start4 = time(0);
    cout << start4 - start1 << endl;

    for (int i = 0; i < pathways_list.size(); i++) {
      if (!((pathways_list[i][0] == 0) && (pathways_list[i][1] == 0))) {
        // bool noRepeat = false;
        // for (int j = 0; j < adjacency_matrix[pathways_list[i][0]].size(); j++) {
        //   if (adjacency_matrix[pathways_list[i][0]][j] == pathways_list[i][1]) {
        //     noRepeat = true;
        //     break;
        //   }
        // }
        // if (!noRepeat) {
          adjacency_matrix[pathways_list[i][0]].push_back(pathways_list[i][1]);
        // }
      }
    }

    double start2 = time(0);
    cout << start2 - start4 << endl;

    // for (int i = 1; i < (multiplier + 1); i++) {
    cout << multiplier << ": ";
    
    try {
      vector<int> path;
      time_t ttime = time(0);
      bool recurse = dfs_recurse(adjacency_matrix, 0, path, ttime, multiplier);

      for (int i = 0; i < path_list.size(); i++) {
        cout << path_list[i].mult << ": ";
        for (int j = 0; j < path_list[i].path_val.size(); j++) {
          cout << path_list[i].path_val[j] << " ";
        }
        cout << endl;
      }
    }
    catch (bad_alloc& ba) {
      cout << endl;
    }
    
    double start3 = time(0);
    cout << start3 - start2 << endl;
  }

  for (int i = 0; i < path_list.size(); i++) {
    cout << path_list[i].mult << ": ";
    for (int j = 0; j < path_list[i].path_val.size(); j++) {
      cout << path_list[i].path_val[j] << " ";
    }
    cout << endl;
  }

}
