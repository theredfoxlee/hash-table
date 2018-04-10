#include <iostream>
#include <string>
#include "Hash.hpp"

struct hash_function
{
  size_t operator()(const std::string & str)
  {
    size_t sum = 0;

    for (char c : str)
      sum += static_cast<size_t>(c);

    return sum;
  }
};

int main()
{
  constexpr size_t size = 20;
  
  kjdev::Hash<std::string, std::string, size, hash_function> hash;

  hash.insert("Doe", "John");
  hash.insert("eDo", "Jane");

  std::cout << (hash.search("Doe") ? "true" : "flase") << '\n';

  auto list = hash.get("Doe");
  for (auto entry : list)
    std::cout << entry.first << '\n';

  hash.remove("Doe");
  std::cout << "After remove of Doe" << '\n';

  list = hash.get("Doe");
  for (auto entry : list)
    std::cout << entry.first << '\n';
}
