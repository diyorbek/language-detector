#include "./helpers.h"
#include <cmath>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = filesystem;

vector<string> get_files(string path) {
  vector<string> file_paths;

  for (auto entry : fs::directory_iterator(path)) {
    if (entry.is_regular_file() && entry.path().extension() == ".txt")
      file_paths.push_back(entry.path());
  }

  return file_paths;
}

bool is_valid_char(const char& ch) {
  return ch >= 'a' && ch <= 'z';
}

vector<int> get_character_frequency(string& file_path) {
  ifstream file(file_path);
  vector<int> frequency(26);

  while (file.peek() != EOF) {
    char letter = tolower(file.get());

    if (is_valid_char(letter)) {
      frequency[letter - 'a']++;
    }
  }

  file.close();

  return frequency;
}

vector<float> normalize(vector<int>& input) {
  unsigned int magnitude = 0;
  vector<float> output(input.size());

  for (int value : input) {
    magnitude += pow(value, 2);
  }

  magnitude = sqrt(magnitude);
  for (size_t i = 0; i < input.size(); i++) {
    output[i] = (float)input[i] / magnitude;
  }

  return output;
}

vector<float> create_input_from_text(string text) {
  vector<int> frequency(26);

  for (char ch : text) {
    char letter = tolower(ch);

    if (is_valid_char(letter)) {
      frequency[letter - 'a']++;
    }
  }

  return normalize(frequency);
}

language_map read_languages_data(string path) {
  language_map languages;

  for (auto entry : fs::directory_iterator(path)) {
    if (entry.is_directory()) {
      auto lang_code = entry.path().filename();
      auto file_paths = get_files(entry.path());
      vector<vector<float>> samples;

      for (auto& file_path : file_paths) {
        auto inputs = get_character_frequency(file_path);
        auto normalized = normalize(inputs);

        samples.push_back(normalized);
      }

      languages[lang_code] = samples;
    }
  }

  return languages;
}