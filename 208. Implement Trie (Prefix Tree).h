#include "Header.h"

//class Trie{
//
//	unordered_map<char, shared_ptr<Trie>> _umap;
//	bool _end = false;
//
//	/** Inserts a word into the trie. */
//	void insert(string  word) {
//
//		shared_ptr<Trie> node = _umap[word[0]];
//		for (int i = 0; i < word.size(); i++)
//		{
//			if (node == nullptr)
//			{
//				node = make_shared<Trie>();
//				_umap[word[i]] = node;
//			}
//
//			node = node->_umap[word[i]];
//			map
//		}
//
//		if(node)
//			node->_end = true;
//	}
//
//	/** Returns if the word is in the trie. */
//	bool search(string word) {
//
//		shared_ptr<Trie> node = _umap[word[0]];
//		for (int i = 0; i < word.size(); i++)
//		{
//			if (node == nullptr)
//				return false;
//			node = node->_umap[word[i]];
//		}
//
//		if (node && node->_end)
//			return true;
//	}
//
//	/** Returns if there is any word in the trie that starts with the given prefix. */
//	bool startsWith(string prefix) {
//
//		shared_ptr<Trie> node = _umap[prefix[0]];
//		for (int i = 0; i < prefix.size(); i++)
//		{
//			if (node == nullptr)
//				return false;
//			node = node->_umap[prefix[i]];
//		}
//
//		return true;
//	}
//};