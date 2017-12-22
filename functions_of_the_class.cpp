#include <string> 
#include <iostream> 
#include <cstring> 
#include "class_hash_table.h" 

using namespace std;

const char * ar[] = 
{ "à", "á", "â", "ã", "ä",
  "å", "¸", "æ", "ç", "è", 
  "é", "ê", "ë", "ì", "í", 
  "î", "ï", "ð", "ñ", "ò",
  "ó", "ô", "õ", "ö", "÷", 
  "ø", "ù", "ú", "û", "ü",  
  "ý", "þ", "ÿ" };

string HashTable::generate_string() {
	string s = "";
	int n = rand() % 28 + 1;
	for (int i = 0; i < n; i++) {
		s += ar[rand() % (sizeof ar / sizeof(char *))];
	}
	return s;
}

element_of_table HashTable::generate_element() {
	element_of_table new_element;
	new_element.key = generate_string();
	new_element.value = generate_string();
	return new_element;
}

int HashTable::hash(string key) {
	return ((sizeof(key) + 73) % bucket_size);
}

string HashTable::get_value(string key) {
	for (int i = 0; i < bucket_size; i++) {
		if (mass[i].key == key) {
			return mass[i].value;
		}
	}
	string v = "";
	return v;
}

void HashTable::put(element_of_table new_element) {
	for (int i = 0; i < bucket_size; i++) {
		if (mass[i].key == new_element.key) {
			mass[i].value = new_element.value;
			return;
		}
		if (!sizeof(mass[i].key)) {
			mass[hash(mass[i].key)].key = new_element.key;
			mass[hash(mass[i].key)].value = new_element.value;
			return;
		}
	}
}

void HashTable::del(string key) {
	for (int i = 0; i < bucket_size; i++) {
		if (mass[i].key == key) {
			mass[i].key.clear();
			mass[i].value.clear();
			return;
		}
	}
	return;
}

void HashTable::change_capasity(int new_bucket_size) {
	int buff = bucket_size;
	bucket_size = new_bucket_size;
	element_of_table *new_mass = new element_of_table[new_bucket_size];
	for (int i = 0; i < buff; i++) {
		new_mass[hash(mass[i].key)].key = mass[i].key;
		new_mass[hash(mass[i].key)].value = mass[i].value;
	}
	element_of_table temp = *mass;
	*mass = *new_mass;
	*new_mass = temp;
	delete new_mass;
	return;
}
