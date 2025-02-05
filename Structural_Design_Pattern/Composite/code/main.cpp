#include <iostream>
#include <memory>
#include <vector>

// component - base interface
class FileSystemComponent {
 public:
  virtual ~FileSystemComponent() = default;
  virtual void show_details() const = 0;
};

// leaf - represents a single file
class File : public FileSystemComponent {
 private:
  std::string name;

 public:
  // std::move used to transfer the ownership of the temporary string
  // without making unnecessary copy.
  // if the string or the type is large then it's inefficient. the
  // efficient way to transfer the ownership is using std::move
  explicit File(const std::string &name) : name(std::move(name)) {}
  void show_details() const override {
    std::cout << "File: " << this->name << std::endl;
  }
};

// composite - represents a folder
class Folder : public FileSystemComponent {
 private:
  std::string name;
  std::vector<std::shared_ptr<FileSystemComponent>> children;

 public:
  explicit Folder(const std::string &name) : name(std::move(name)) {}
  void add(std::shared_ptr<FileSystemComponent> component) {
    children.push_back(component);
  }

  void show_details() const override {
    std::cout << "Folder: " << name << std::endl;
    for (const auto &child : children) {
      std::cout << " |-> ";
      child->show_details();
    }
  }
};

// client code
int main() {
  auto file1 = std::make_shared<File>("document.txt");
  auto file2 = std::make_shared<File>("image.png");

  auto folder1 = std::make_shared<Folder>("home");
  folder1->add(file1);
  folder1->add(file2);

  //   folder1->show_details();

  auto folder2 = std::make_shared<Folder>("temp");
  auto file3 = std::make_shared<File>("music.mp3");

  folder2->add(file3);
  folder1->add(folder2);

  folder1->show_details();
}