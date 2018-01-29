#pragma once

#include "Header.h"

/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?*/


//Operations take O(1) time
class LRUCache {

private:

	int _capacity;
	unordered_map<int, pair<int, list<int>::iterator>> _map;
	list<int> _lst;

public:

	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {

		auto itr = _map.find(key);
		if (itr != _map.end())
		{
			_lst.erase(itr->second.second);
			_lst.push_back(key);

			auto it = --_lst.end();
			itr->second.second = it;
			return itr->second.first;
		}
		else
			return -1;

	}

	void put(int key, int value) {

		auto itr = _map.find(key);
		if (itr == _map.end())
		{
			if (_map.size() < _capacity)
			{
				//insert the 'Most recent' element to the list
				_lst.push_back(key);

				//insert the most recent element in the map;
				auto itr = --_lst.end();
				_map.insert(make_pair(key, make_pair(value, itr)));
			}
			else
			{
				//get the 'Least Recent' element from the list and remove this from the map and list;
				int tKey = _lst.front();
				_lst.pop_front();
				_map.erase(tKey);

				//insert the 'Most recent' element to the list
				_lst.push_back(key);

				//insert the most recent element in the map;
				auto itr = _lst.end();
				--itr;
				_map.insert(make_pair(key, make_pair(value, itr)));
			}
		}
		else
		{
			itr->second.first = value;
			_lst.erase(itr->second.second);
			_lst.push_back(key);

			auto it = --_lst.end();
			itr->second.second = it;
		}


	}
};
