#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Memento: stores the state of the text editor
class Memento {
 private:
  std::string state;

 public:
  explicit Memento(const std::string &state) : state(std::move(state)) {}
  std::string get_state() const { return this->state; }
};

// Originator
class TextEditor {
 private:
  std::string text;

 public:
  void type(const std::string &words) { this->text += words + " "; }

  void show() const { std::cout << "Editor content: " << text << std::endl; }

  std::shared_ptr<Memento> save() const {
    return std::make_shared<Memento>(this->text);
  }

  void restore(const std::shared_ptr<Memento> &memento) {
    text = memento->get_state();
  }
};

// Caretakers - manages the history of mementos
class History {
 private:
  std::vector<std::shared_ptr<Memento>> history;

 public:
  void add_history(const std::shared_ptr<Memento> &memento) {
    this->history.push_back(memento);
  }

  std::shared_ptr<Memento> get_history(const size_t &index) {
    return this->history.at(index);
  }
};

int main() {
  TextEditor editor;
  History history;

  editor.type("Hello");
  history.add_history(editor.save());

  editor.type("World");
  history.add_history(editor.save());

  editor.show();

  editor.restore(history.get_history(0));
  editor.show();
}