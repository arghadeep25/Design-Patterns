#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

// Flyweight: Stores shared tree data
class TreeType {
 private:
  std::string name;
  std::string color;
  std::string texture;

 public:
  TreeType(const std::string &name, const std::string &color,
           const std::string &texture)
      : name(std::move(name)),
        color(std::move(color)),
        texture(std::move(texture)) {}

  void render(const int &x, const int &y) {
    std::cout << "Rendering tree [" << name << "] with color [" << color
              << "] and texture [" << texture << "] at position (" << x << ", "
              << y << ")" << std::endl;
  }
};

// Flyweight Factory: Manages shared tree types
class TreeFactory {
 private:
  std::unordered_map<std::string, std::shared_ptr<TreeType>> tree_types;

 public:
  std::shared_ptr<TreeType> get_tree_type(const std::string &name,
                                          const std::string &color,
                                          const std::string &texture) {
    std::string key = name + "_" + color + "_" + texture;
    if (tree_types.find(key) == tree_types.end()) {
      tree_types[key] = std::make_shared<TreeType>(name, color, texture);
    }
    return tree_types[key];
  }
};

// Unshared Flyweight: Tree instance with unique position
class Tree {
 private:
  int x, y;
  std::shared_ptr<TreeType> type;

 public:
  Tree(const int &x, const int &y, const std::shared_ptr<TreeType> type)
      : x(std::move(x)), y(std::move(y)), type(std::move(type)) {}

  void draw() { type->render(x, y); }
};

// Client Code
int main() {
  TreeFactory factory;

  std::vector<std::shared_ptr<Tree>> trees;
  trees.push_back(std::make_shared<Tree>(
      10, 20, factory.get_tree_type("Oak", "Green", "BarkTexture")));
  trees.push_back(std::make_shared<Tree>(
      15, 30, factory.get_tree_type("Pine", "Dark Green", "PineTexture")));
  trees.push_back(std::make_shared<Tree>(
      50, 60,
      factory.get_tree_type("Oak", "Green", "BarkTexture")));  // Reused Oak

  for (const auto &tree : trees) {
    tree->draw();
  }
}
