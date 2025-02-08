#include <iostream>
#include <memory>
#include <vector>

// Iterator Interface
class Iterator {
 public:
  virtual ~Iterator() = default;
  virtual bool has_next() const = 0;
  virtual int next() const = 0;
};

// Concrete Iterator
class ConcreteIterator : public Iterator {
 private:
  std::vector<int> collection;
  mutable size_t position = 0;

 public:
  explicit ConcreteIterator(std::vector<int> items)
      : collection(std::move(items)) {}

  bool has_next() const override { return position < collection.size(); }

  int next() const override { return has_next() ? collection[position++] : -1; }
};

// Aggregate Interface
class Iterable {
 public:
  virtual ~Iterable() = default;
  virtual std::shared_ptr<Iterator> create_iterator() const = 0;
};

// Concrete Collection
class ConcreteCollection : public Iterable {
 private:
  std::vector<int> items;

 public:
  void add_items(const int& items) { this->items.push_back(items); }

  std::shared_ptr<Iterator> create_iterator() const override {
    return std::make_shared<ConcreteIterator>(this->items);
  }
};

// Client Code
int main() {
  ConcreteCollection collection;
  collection.add_items(1);
  collection.add_items(2);
  collection.add_items(3);
  collection.add_items(4);

  std::shared_ptr<Iterator> iterator = collection.create_iterator();
  std::cout << "Iterating through collection..." << std::endl;
  while (iterator->has_next()) {
    std::cout << iterator->next() << " ";
  }
  std::cout << std::endl;
}