#include <iostream>
#include "source/helpers.h"
#include "source/neural_net.h"
#include "source/perceptron.h"

using namespace std;

int main() {
  char training_src[] = "./data";
  float learning_rate = 0.2;
  int learning_iterations = 5;

  neural_net net(training_src, learning_rate, learning_iterations);

  while (true) {
    string text;
    cout << "Enter text in one line:\n";
    getline(cin, text);

    auto input = create_input_from_text(text);
    auto lang_code = net.select(input);

    cout << "Text language: " << lang_code << "\n\n";
  }

  return 0;
}
