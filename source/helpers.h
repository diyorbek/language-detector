#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<string, vector<vector<float>>> language_map;

vector<string> get_files(string path);

bool is_valid_char(const char& ch);

vector<int> get_character_frequency(string& file_path);

vector<float> normalize(vector<int>& input);

vector<float> create_input_from_text(string text);

language_map read_languages_data(string path);