#include <iostream>
#include <memory>

// Strategy Interface
class NavigationStrategy {
 public:
  virtual ~NavigationStrategy() = default;
  virtual void calculate_route() const = 0;
};

// Concrete Strategies
class CarNavigation : public NavigationStrategy {
 public:
  void calculate_route() const override {
    std::cout << "Calculating Route for cars" << std::endl;
  }
};

class BikeNavigation : public NavigationStrategy {
 public:
  void calculate_route() const override {
    std::cout << "Calculating Route for bikes" << std::endl;
  }
};

class WalkNavigation : public NavigationStrategy {
 public:
  void calculate_route() const override {
    std::cout << "Calculating Route for walking" << std::endl;
  }
};

// Context Class
class NavigationContext {
 private:
  std::shared_ptr<NavigationStrategy> strategy;

 public:
  void set_strategy(const std::shared_ptr<NavigationStrategy>& strategy) {
    this->strategy = strategy;
  }

  void navigate() const {
    if (strategy)
      this->strategy->calculate_route();
    else
      std::cout << "No navigation strategy selected" << std::endl;
  }
};

int main() {
  NavigationContext navigation;
  std::shared_ptr<CarNavigation> car_navigation =
      std::make_shared<CarNavigation>();
  std::shared_ptr<BikeNavigation> bike_navigation =
      std::make_shared<BikeNavigation>();
  std::shared_ptr<WalkNavigation> walk_navigation =
      std::make_shared<WalkNavigation>();

  navigation.set_strategy(car_navigation);
  navigation.navigate();

  navigation.set_strategy(bike_navigation);
  navigation.navigate();

  navigation.set_strategy(walk_navigation);
  navigation.navigate();
}
