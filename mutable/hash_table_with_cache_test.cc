#include <iostream>
#include <string>
#include <mutex>
template <typename KeyT, typename ValueT> class HashTableWithCache {

public:
  ValueT LookUp(const KeyT &key) const { // const this ptr
    if (last_key_ == key) {
      return last_value_;
    }
    auto value = LookUpInternal(key);

    // change member
    last_value_ = value;
    last_key_ = key;

    return value;
  }

  KeyT LastKey() const { return last_key_; }

private:
  // just show
  ValueT LookUpInternal(const KeyT &key) const { return ValueT{}; }

private:
  mutable KeyT last_key_; // cache last query
  mutable ValueT last_value_;
};


template <typename KeyT, typename ValueT> class SafeHashTableWithCache {

public:
  ValueT LookUp(const KeyT &key) const { // const this ptr

    std::lock_guard<std::mutex> lock(m_);

    if (last_key_ == key) {
      return last_value_;
    }
    auto value = LookUpInternal(key);

    // change member
    last_value_ = value;
    last_key_ = key;

    return value;
  }

  KeyT LastKey() const { return last_key_; }

private:
  // just show
  ValueT LookUpInternal(const KeyT &key) const { return ValueT{}; }

private:
  mutable std::mutex m_;
  mutable KeyT last_key_; // cache last query
  mutable ValueT last_value_;
};

int main(void) {

  HashTableWithCache<std::string, int> table;
  table.LookUp("hello");
  std::cout << table.LastKey() << "\n";
  return 0;
}
