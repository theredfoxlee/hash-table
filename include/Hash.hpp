#ifndef KJDEV_HASH_HPP
#define KJDEV_HASH_HPP

#include <forward_list>
#include <utility>

template <class K, class V, size_t size, class hash_function>
class Hash
{
private:
  using data = std::forward_list<std::pair<K, V>>;

  hash_function hash_;
  data table_[size];

public:
  void insert(const K &key, const V &value) { table_[index(key)].push_front(std::pair<K, V>(key, value)); }
  data get(const K &key) { return table_[index(key)]; }
  bool search(const K &key) { return !table_[index(key)].empty(); }
  void remove(const K &key) 
  {
    table_[index(key)].remove_if(                                                                               
        [&key](const std::pair<K, V> &kv) { return kv.first == key; });
  }

private:
  size_t index(const K &key) { return hash_(key) % size; }
};

#endif
