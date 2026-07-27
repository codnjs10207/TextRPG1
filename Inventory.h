#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
class Inventory {
private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10) : capacity_(capacity), size_(0) {
		pItems_ = new T[capacity_];

	}

	~Inventory() {
		delete[] pItems_;
	}

	Inventory(const Inventory<T>& other) : capacity_(other.capacity_), size_(other.size_) {
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			pItems_[i] = other.pItems_[i];
		}
	}

	Inventory<T>& operator=(const Inventory<T>& other) {
		if (this == &other) return *this;

		delete[] pItems_;

		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; i++) {
			pItems_[i] = other.pItems_[i];
		}
		return *this;
	}

	int GetSize() const { return size_; }
	int GetCapacity() const { return capacity_; }

	void Resize(int newCapacity) {
		if (newCapacity <= capacity_) return;

		T* newItems = new T[newCapacity];

		for (int i = 0; i < size_; i++) {
			newItems[i] = pItems_[i];
		}

		delete[] pItems_;

		pItems_ = newItems;
		int oldCapacity = capacity_;
		capacity_ = newCapacity;
		cout << "-> Inventory auto-expanded! (" << oldCapacity << " -> " << capacity_ << ")" << endl;
	}

	bool AddItem(const T& item) {
		if (size_ >= capacity_) {
			cout << "Adding item... (" << size_ << "/" << capacity_ << " full)" << endl;
			Resize(capacity_ * 2);
		}
		pItems_[size_] = item;
		size_++;
		cout << "-> Item added" << endl << endl;
		return true;
	}

	void RemoveLastItem() {
		if (size_ > 0) {
			size_--;
		}
		else {
			cout << "Inventory is already empty!" << endl;
		}
	}

	void RemoveItemAt(int index) {
		if (index < 0 || index >= size_) return;

		for (int i = index; i < size_ - 1; i++) {
			pItems_[i] = pItems_[i + 1];
		}
		size_--;
	}

	T& operator[](int index) {
		return pItems_[index];
	}

	const T& operator[](int index) const {
		return pItems_[index];
	}

	void PrintAllItems() const {
		if (size_ == 0) {
			cout << "The inventory is empty." << endl;
			return;
		}
		for (int i = 0; i < size_; i++) {
			cout << (i + 1) << ". ";
			pItems_[i].PrintItem();
		}
	}

	void SortItems(bool (*compareFunc)(const T&, const T&)) {
		if (size_ <= 1) return;

		sort(pItems_, pItems_ + size_, compareFunc);
	}
};