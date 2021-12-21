#include "stdafx.h"
#include "Math.h"

using namespace std;


/*
	const char* key1 = "value1";
	jenkins_one_at_a_time_hash_example(key1, strlen(key1));



	//cout << key1 << endl;
	////uint32_t temp_hash = 0;
	//temp_hash += key1[0];
	//cout << temp_hash << endl;

	//temp_hash += temp_hash << 10;
	//cout << temp_hash << endl;

	//temp_hash ^= temp_hash >> 6;
	//cout << temp_hash << endl;









	///hash += hash << 3;
	//hash ^= hash >> 11;
	//hash += hash << 15;

	bool full_debug = 0;

	cout << "\nlooking for " << key1 << " hash\n"; //flavour text
	uint32_t match = jenkins_one_at_a_time_hash(key1, strlen(key1)); //converts to hash
	printf("Found target hash 0x%lX\n", (unsigned long)match);
	uint32_t i = 0;

	do {
		uint32_t hash = jenkins_one_at_a_time_hash(&i, sizeof i);

		if (full_debug) { //output of all the hashes, slower but shows all procedures from the background
		printf("0x%lX = 0x%lX\n", (unsigned long)i, (unsigned long)hash);
		}
		if (hash == match) {
			printf("Found fitting number: 0x%lX = 0x%lX\n\n\n", (unsigned long)i, (unsigned long)hash);
			//lX prints address in hex //unsigned long 0 to 2 bil
			break; //ends the loop
		}
	} while (++i); //constantly continues the loop until it isn't broken, while adding 1 to the interating variable

	*/



	//11101100001110110			;
	//00000011101100001					; 

	//11101111100010111                   ;


uint32_t jenkins_one_at_a_time_hash(const uint8_t* key, size_t length) {
	size_t i = 0;
	uint32_t hash = 0;
	while (i != length) {
		hash += key[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}

uint32_t jenkins_one_at_a_time_hash(const char* key, size_t length) {
	size_t i = 0;
	uint32_t hash = 0;
	while (i != length) {
		hash += key[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}

uint32_t jenkins_one_at_a_time_hash(uint32_t* key, size_t length) {
	size_t i = 0;
	uint32_t hash = 0;
	while (i != length) {
		hash += key[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}


uint32_t jenkins_one_at_a_time_hash_example(const char* key, size_t length) {
	size_t i = 0;
	uint32_t hash = 0;
	uint32_t temp_hash = 0;
	while (i != length) {

		cout << "\ncurrent key: " << key[i] << endl;

		hash += key[i++];

		cout << "new hash: " << hash << endl;

		temp_hash = hash << 10;
		cout << "bit shift left 10: " << temp_hash << endl;
		hash += hash << 10;
		cout << "bit shift left 10 + hash: " << hash << endl;

		temp_hash = hash >> 6;
		cout << "bit shift right 6: " << temp_hash << endl;
		hash ^= hash >> 6;
		cout << "bit shift right 6 + bitwise xor: " << hash << endl;
	}
	temp_hash = hash << 3;;
	cout << "\n\nbit shift left 3: " << temp_hash << endl;
	hash += hash << 3;
	cout << "bit shift left 3 + hash: " << hash << endl;

	temp_hash = hash >> 11;;
	cout << "bit shift right 11: " << temp_hash << endl;
	hash ^= hash >> 11;
	cout << "bit shift left 11 + bitwise xor: " << hash << endl;


	temp_hash = hash << 15;;
	cout << "bit shift right 15: " << temp_hash << endl;
	hash += hash << 15;
	cout << "bit shift left 15 + hash: " << hash << endl << endl;


	printf("Final hex hash: 0x%lX\n\n", (unsigned long)hash);
	return hash;
}


uint32_t reverse_one_at_a_time_hash(const uint8_t* key, size_t length, uint32_t hash) {
	hash *= 0x3FFF8001;  // inverse of hash += hash << 15;
	hash ^= (hash >> 11) ^ (hash >> 22);
	hash *= 0x38E38E39;  // inverse of hash += hash << 3;
	size_t i = length;
	while (i > 0) {
		hash ^= (hash >> 6) ^ (hash >> 12) ^ (hash >> 18) ^ (hash >> 24) ^ (hash >> 30);
		hash *= 0xC00FFC01;  // inverse of hash += hash << 10;
		hash -= key[--i];
	}
	return hash;  // this should return 0 if the original hash was correct
}


