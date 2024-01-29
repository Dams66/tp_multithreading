
#include <cpr/cpr.h>

#include <Eigen/Dense>
#include <chrono>
#include <iostream>
#include <nlohmann/json.hpp>
#include <random>
#include <string>

using json = nlohmann::json;

using namespace std;

class Task {
 public:
  string identifier;
  int size;
  Eigen::MatrixXf a;
  Eigen::VectorXf b;
  Eigen::VectorXf x;
  float time;

  Task(string id, json j, int s = 0) {
    identifier = id;
    from_json(j);
    time = 0;
  }

  void work() {
    const auto start{std::chrono::steady_clock::now()};
    x = a.lu().solve(b);
    const auto end{std::chrono::steady_clock::now()};
    time = chrono::duration<float>(end - start).count();
    cout << "La tache s est terminee en " << time << " secondes." << endl;
  }

  void from_json(json j) {
    // int x, y, i =0;
    size = j["size"];
    size = 2000;
    a = Eigen::MatrixXf::Random(size, size);
    b = Eigen::VectorXf::Random(size);
    /*for (x=0; x<j["size"]; x=x+1){
        for (y=0; y<j["size"]; y=y+1){
            a << j["a"][x][y];
        }
    }

    for (i=0; i<=j["size"]; i=i+1){
        b << j["b"][i];
    }
    */
  }
};

int main() {
  cout << "Travail en cours ... " << endl;
  // cpr::Response r = cpr::Get(cpr::Url{"http://localhost:8000/"});
  json j = json::parse(R"(
  {
    "a": [[0.5669220687361761, 0.053291556453842426, 0.37250599320075095, 0.530936339550374, 0.9981184112595199],
          [0.5669220687361761, 0.053291556453842426, 0.37250599320075095, 0.530936339550374, 0.9981184112595199],
          [0.5669220687361761, 0.053291556453842426, 0.37250599320075095, 0.530936339550374, 0.9981184112595199],
          [0.5669220687361761, 0.053291556453842426, 0.37250599320075095, 0.530936339550374, 0.9981184112595199],
          [0.5669220687361761, 0.053291556453842426, 0.37250599320075095, 0.530936339550374, 0.9981184112595199]],
    "b": [0.5669220687361761, 0.053291556453842426, 0.37250599320075095, 0.530936339550374, 0.9981184112595199],
    "size": 5
  }
)");
  // json j = json::parse(r.text);
  Task task("taskcpp", j);
  task.work();
  return 1;
}
