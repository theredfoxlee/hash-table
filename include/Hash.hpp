#ifndef KJDEV_HASH_HPP
#define KJDEV_HASH_HPP

#include <forward_list>
#include <utility>

template <class K, class V, size_t size, class hash_function>
class Hash
{
private:
  using kv = std::pair<K, V>;
  using data = std::forward_list<kv>;

  hash_function hash_;
  data table_[size];

public:
  void insert(const K &key, const V &value) { table_[index(key)].push_front(kv(key, value)); }
  data get(const K &key) { return table_[index(key)]; }
  bool search(const K &key) { return !table_[index(key)].empty(); }
  void remove(const K &key) { table_[index(key)].remove_if([&key](const kv &p) { return p.first == key; }); }

private:
  size_t index(const K &key) { return hash_(key) % size; }
};

#endif
