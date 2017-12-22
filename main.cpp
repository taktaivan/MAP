#include "class_hash_table.h"

int main(){
	HashTable HT;
	for (int j = 0; j < rand() % 10 + 1; j++)
		HT.put(HT.generate_element());
	system("PAUSE");
	return 0;
}