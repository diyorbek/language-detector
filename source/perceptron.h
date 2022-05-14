#pragma once

#include <string>
#include <vector>

using namespace std;

class perceptron {
  string label;
  vector<float> weights;
  float bias;
  float learning_rate;

  float calc_net(vector<float> inputs);

 public:
  perceptron(string label,
             int weights_count,
             float initial_bias,
             float learning_rate);

  string get_label();

  int classify(vector<float> inputs);

  float sigmoid(vector<float> inputs);

  void adjust_weights(vector<float> inputs, int answer);
};