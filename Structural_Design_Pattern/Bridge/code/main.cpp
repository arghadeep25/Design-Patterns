#include <iostream>
#include <memory>

// Implementation: Renderer (bridge interface)
class Renderer {
 public:
  virtual ~Renderer() = default;
  virtual void render_shape(const std::string&) const = 0;
};

// OpenGL renderer
class OpenGLRenderer : public Renderer {
 public:
  void render_shape(const std::string& shape) const override {
    std::cout << "Rendering Shape: " << shape << " using OpenGL" << std::endl;
  }
};

// DirectX renderer
class DirectXRenderer : public Renderer {
 public:
  void render_shape(const std::string& shape) const override {
    std::cout << "Rendering Shape: " << shape << " using DirectX" << std::endl;
  }
};

// Abstraction Shape
class Shape {
 protected:
  std::shared_ptr<Renderer> renderer_ptr;

 public:
  explicit Shape(std::shared_ptr<Renderer> renderer) : renderer_ptr(renderer) {}
  virtual ~Shape() = default;
  virtual void draw() const = 0;
};

// Concrete abstraction: Rectangle
class Rectangle : public Shape {
 public:
  // inheriting the constructor of the base class Shape to avoid manual
  // defining of constructor in Rectangle to pass Renderer* dependency.
  // if not used then we need to add the following line
  // Rectangle(std::shared_ptr<Renderer> renderer) : Shape(renderer) {}
  using Shape::Shape;
  void draw() const override { renderer_ptr->render_shape("rectangle"); }
};

// Concrete abstraction: Square
class Square : public Shape {
 public:
  using Shape::Shape;
  void draw() const override { renderer_ptr->render_shape("square"); }
};

// Concrete abstraction: Circle
class Circle : public Shape {
 public:
  using Shape::Shape;
  void draw() const override { renderer_ptr->render_shape("circle"); }
};

int main() {
  std::shared_ptr<Renderer> opengl_renderer =
      std::make_shared<OpenGLRenderer>();
  std::shared_ptr<Renderer> directx_renderer =
      std::make_shared<DirectXRenderer>();

  std::shared_ptr<Circle> circle = std::make_shared<Circle>(opengl_renderer);
  std::shared_ptr<Rectangle> rectangle =
      std::make_shared<Rectangle>(directx_renderer);
  std::shared_ptr<Square> square = std::make_shared<Square>(opengl_renderer);
  circle->draw();
  rectangle->draw();
  square->draw();
  square = std::make_shared<Square>(directx_renderer);
  square->draw();
}
