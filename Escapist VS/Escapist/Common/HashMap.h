#pragma once

#include"../General.h"

template<typename Key, typename Value>
class HashMap {
private:
	struct Node {
		Node* next_;
		Key key_;
		Value value_;
	};
	using HashCodeFunc = SizeType(*)(const Key&);

	SizeType count_;
	Node** head_;
	HashCodeFunc hashCode_;

public:
	HashMap(SizeType count, HashCodeFunc hashCode) :count_(count), hashCode_(hashCode) {
		assert(count_);
		assert(hashCode_);
		head_ = (Node**)::malloc(count_ * sizeof(Node*));
		assert(head_);
	}

	~HashMap() {
		for (SizeType index = 0; index < count_; ++index) {
			Node* target = head_[index];
			Node* old;
			while (target != nullptr) {
				old = target;
				target = target->next_;
				::free((void*)old);
			}
		}
		::free((void*)head_);
	}

	HashMap<Key, Value>& Put(const Key& key, const Value& value)noexcept {
		assert(head_);
		SizeType index = hashCode_(key) & (count_ - 1);
		if (head_[index]) {
		}
	}

	Value& GetValue(const Key& key) {

	}

	const Value& GetConstValue(const Key& key)const {

	}
};

/*

						SizeType hash = (SizeType)key;
						hash ^= (hash >> 20) ^ (hash >> 12);
						return hash ^ (hash >> 7) ^ (hash >> 4);
						}
*/