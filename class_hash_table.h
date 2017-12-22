#pragma once
#include <string> 
#include <iostream> 
#include <cstring> 

using namespace std;

struct element_of_table {
	string key = "";
	string value = "";
};

class HashTable {
private:
	element_of_table *mass = new element_of_table[bucket_size];
	int hash(string key);
	string generate_string();
	int bucket_size = 256;
public:
	element_of_table generate_element();
	string get_value(string key);
	void put(element_of_table new_element);
	void del(string key);
	void change_capasity(int new_bucket_size);
};