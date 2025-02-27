#include <iostream>
#include <memory>

// Abstract Handler
class Handler {
 protected:
  std::shared_ptr<Handler> next;

 public:
  virtual ~Handler() = default;
  void set_next(const std::shared_ptr<Handler> &next_handler) {
    next = next_handler;
  }

  virtual void handle_request(int level) {
    if (next) next->handle_request(level);
  }
};

// Concrete Handler
class JuniorSupport : public Handler {
 public:
  void handle_request(int level) override {
    if (level <= 1)
      std::cout << "Junior Support: Handling Request at level: " << level
                << std::endl;
    else if (next)
      next->handle_request(level);
  }
};

class SeniorSupport : public Handler {
 public:
  void handle_request(int level) override {
    if (level <= 2)
      std::cout << "Senior Support: Handling Request at level: " << level
                << std::endl;
    else if (next)
      next->handle_request(level);
  }
};

class ManagerSupport : public Handler {
 public:
  void handle_request(int level) override {
    std::cout << "Manager Support: Handling Request at level: " << level
              << std::endl;
  }
};

int main() {
  std::shared_ptr<Handler> junior = std::make_shared<JuniorSupport>();
  std::shared_ptr<Handler> senior = std::make_shared<SeniorSupport>();
  std::shared_ptr<Handler> manager = std::make_shared<ManagerSupport>();

  junior->set_next(senior);
  senior->set_next(manager);

  std::cout << "Client sending request at level 1" << std::endl;
  junior->handle_request(1);
  std::cout << "Client sending request at level 2" << std::endl;
  junior->handle_request(2);
  std::cout << "Client sending request at level 3" << std::endl;
  junior->handle_request(3);
}
