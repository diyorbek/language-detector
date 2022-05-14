#include "./perceptron.h"
#include <cmath>

using namespace std;

perceptron::perceptron(string label,
                       int weights_count,
                       float initial_bias,
                       float learning_rate)
    : label(label), bias(initial_bias), learning_rate(learning_rate) {
  weights = vector<float>(weights_count);
}

string perceptron::get_label() {
  return label;
}

float perceptron::calc_net(vector<float> inputs) {
  if (inputs.size() != weights.size())
    return 0;

  float sum = 0;
  for (size_t i = 0; i < weights.size(); i++) {
    sum += inputs[i] * weights[i];
  }

  return sum;
}

int perceptron::classify(vector<float> inputs) {
  auto net = calc_net(inputs);

  return net >= 0 ? 1 : 0;
}

float perceptron::sigmoid(vector<float> inputs) {
  auto net = calc_net(inputs);

  return 1. / (1 + pow(M_E, -1 * net));
}

void perceptron::adjust_weights(vector<float> inputs, int answer) {
  int guess = classify(inputs);
  int error = answer - guess;

  if (!error)
    return;

  for (size_t i = 0; i < weights.size(); i++) {
    weights[i] += error * learning_rate * inputs[i];
  }

  bias -= error * learning_rate;
}
