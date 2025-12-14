#pragma once
#include<iostream>
#include <map>
#include <string>
using namespace std;

extern map<string, string> langEN;
extern map<string, string> langVI;
extern map<string, string>* currentLang;

string T(const string& key);
void SetLanguage(const string& lang); 
