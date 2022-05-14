#include "./helpers.h"
#include "./perceptron.h"

using namespace std;

class neural_net {
  language_map _training_languages;
  vector<perceptron> _net;
  float _learning_rate;
  int _learning_iterations;

  void train_neural_net();

 public:
  neural_net(char* data_src, float learning_rate, int learning_iterations);
  string select(vector<float>& input);
};