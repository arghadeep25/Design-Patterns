#include <iostream>
#include <memory>

// Abstract Class
class Beverage {
 public:
  virtual ~Beverage() = default;

  void prepare() {
    this->boil_water();
    this->brew();
    this->add_extras();
    this->pour();
  }

 protected:
  void boil_water() { std::cout << "Boiling water..." << std::endl; }

  void pour() { std::cout << "Pouring beverage..." << std::endl; }

  virtual void brew() = 0;
  virtual void add_extras() = 0;
};

// Concrete Class: Tea
class Tea : public Beverage {
 protected:
  void brew() override { std::cout << "Adding tea leaves..." << std::endl; }

  void add_extras() override { std::cout << "Adding lemon..." << std::endl; }
};

// Concrete Class: Coffee
class Coffee : public Beverage {
 protected:
  void brew() override { std::cout << "Adding coffee grains..." << std::endl; }

  void add_extras() override {
    std::cout << "Adding milk and sugar..." << std::endl;
  }
};

int main() {
  std::shared_ptr<Beverage> tea = std::make_shared<Tea>();
  std::shared_ptr<Beverage> coffee = std::make_shared<Coffee>();

  std::cout << "Preparing Tea" << std::endl;
  tea->prepare();
  std::cout << "Preparing Coffee" << std::endl;
  coffee->prepare();
}
