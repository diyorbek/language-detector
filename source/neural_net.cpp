#include "./neural_net.h"
#include "./helpers.h"
#include "./perceptron.h"

neural_net::neural_net(char* data_src,
                       float learning_rate,
                       int learning_iterations)
    : _learning_rate(learning_rate), _learning_iterations(learning_iterations) {
  _training_languages = read_languages_data(data_src);

  for (auto language : _training_languages) {
    auto lang_code = language.first;
    _net.push_back(perceptron(lang_code, 26, 0, learning_rate));
  }

  train_neural_net();
}

void neural_net::train_neural_net() {
  for (size_t i = 0; i < _learning_iterations; i++) {
    for (auto language : _training_languages) {
      auto lang_code = language.first;
      auto samples = language.second;

      for (auto sample : samples) {
        for (auto& neuron : _net) {
          int answer = neuron.get_label() == lang_code;

          neuron.adjust_weights(sample, answer);
        }
      }
    }
  }
}

string neural_net::select(vector<float>& input) {
  float max_output = INT_MIN;
  string max_neuron;

  for (auto& neuron : _net) {
    float output = neuron.sigmoid(input);

    if (output > max_output) {
      max_output = output;
      max_neuron = neuron.get_label();
    }
  }

  return max_neuron;
}