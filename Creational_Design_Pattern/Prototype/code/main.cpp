#include <iostream>
#include <memory>

// Prototype Interface
class Shape {
 public:
  virtual ~Shape() = default;
  virtual std::shared_ptr<Shape> clone() const = 0;
  virtual void draw() const = 0;
};

// Concrete Prototype: Circle
class Circle : public Shape {
 public:
  Circle(const std::string& color) : color(color) {}
  ~Circle() = default;

  std::shared_ptr<Shape> clone() const override {
    return std::make_shared<Circle>(*this);
  }

  void draw() const override {
    std::cout << "Drawing a " << this->color << " circle" << std::endl;
  }

 private:
  std::string color;
};

// Concrete Prototype: Rectangle
class Rectangle : public Shape {
 public:
  Rectangle(const std::string& color) : color(color) {}
  ~Rectangle() = default;

  std::shared_ptr<Shape> clone() const override {
    return std::make_shared<Rectangle>(*this);
  }

  void draw() const override {
    std::cout << "Drawing a " << this->color << " rectangle" << std::endl;
  }

 private:
  std::string color;
};

class Square {
 public:
  Square(const std::string& color) : color(color) {}
  ~Square() = default;
  void draw() {
    std::cout << "Drawing a " << this->color << " square" << std::endl;
  }

 private:
  std::string color;
};

int main() {
  std::shared_ptr<Shape> circle_proto = std::make_shared<Circle>("Red");
  std::shared_ptr<Shape> rect_proto = std::make_shared<Rectangle>("Green");

  std::shared_ptr<Shape> circle_clone = circle_proto->clone();
  std::shared_ptr<Shape> rect_clone = rect_proto->clone();

  circle_proto->draw();
  rect_proto->draw();

  circle_clone->draw();
  rect_clone->draw();

  Square sq("yellow");
  sq.draw();

  Square sq_1 = sq;
  sq_1.draw();
}
