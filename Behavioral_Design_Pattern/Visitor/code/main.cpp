#include <iostream>
#include <memory>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
 public:
  virtual void visit(ConcreteElementA &) = 0;
  virtual void visit(ConcreteElementB &) = 0;
};

// Element Interface
class Element {
 public:
  virtual ~Element() = default;
  virtual void accept(Visitor &visitor) = 0;
};

// Concrete Elements
class ConcreteElementA : public Element {
 public:
  void accept(Visitor &visitor) override { visitor.visit(*this); }

  void operationA() { std::cout << "Operation A" << std::endl; }
};

class ConcreteElementB : public Element {
 public:
  void accept(Visitor &visitor) override { visitor.visit(*this); }

  void operationB() { std::cout << "Operation B" << std::endl; }
};

// Concrete Visitor
class ConcreteVisitor : public Visitor {
 public:
  void visit(ConcreteElementA &) override {
    std::cout << "Visiting concrete element A" << std::endl;
  }

  void visit(ConcreteElementB &) override {
    std::cout << "Visiting concrete element B" << std::endl;
  }
};

// Object Structure
class ObjectStructure {
 private:
  std::vector<std::shared_ptr<Element>> elements;

 public:
  void add_element(std::shared_ptr<Element> element) {
    this->elements.push_back(element);
  }

  void accept(Visitor &visitor) {
    for (const auto &element : this->elements) {
      element->accept(visitor);
    }
  }
};

int main() {
  std::shared_ptr<ConcreteElementA> elem_a =
      std::make_shared<ConcreteElementA>();
  std::shared_ptr<ConcreteElementB> elem_b =
      std::make_shared<ConcreteElementB>();

  ObjectStructure structure;
  structure.add_element(elem_a);
  structure.add_element(elem_b);

  ConcreteVisitor visitor;
  structure.accept(visitor);
}
