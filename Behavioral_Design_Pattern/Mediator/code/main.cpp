#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Colleague class (user)
class User;

// Mediator interface
// std::enable_shared_from_this<T> is used so that it allows an object to
// safely crate a std::shared_ptr pointing to itself
class ChatMediator : public std::enable_shared_from_this<ChatMediator> {
 public:
  virtual ~ChatMediator() = default;
  virtual void add_user(const std::shared_ptr<User> &) = 0;
  virtual void send_message(const std::string &,
                            const std::shared_ptr<User> &) = 0;
};

class User : public std::enable_shared_from_this<User> {
 protected:
  std::shared_ptr<ChatMediator> mediator;
  std::string name;

 public:
  virtual ~User() = default;
  explicit User(const std::shared_ptr<ChatMediator> &mediator,
                const std::string &name)
      : mediator(std::move(mediator)), name(std::move(name)) {}
  virtual void send(const std::string &message) {
    std::cout << this->name << ": " << message << std::endl;
    // std::shared_ptr<User>(this) if we do this in the
    // following function, it will work and followed by
    // core dumped error. multiple shared_ptr instance
    // managing the same object which leads to double
    // deletion. as send_message is expecting a message
    // and an user, so it should point to the User
    // shared pointer. this can only be done through
    // shared_from_this()
    mediator->send_message(message, shared_from_this());
  }

  virtual void receive(const std::string &message) {
    std::cout << "received: " << message << std::endl;
  }
};

// Concrete Mediator
class ChatRoom : public ChatMediator {
 private:
  std::vector<std::shared_ptr<User>> users;

 public:
  void add_user(const std::shared_ptr<User> &user) override {
    this->users.push_back(user);
  }

  void send_message(const std::string &message,
                    const std::shared_ptr<User> &sender) override {
    for (const auto &user : this->users) {
      if (user != sender) {
        user->receive(message);
      }
    }
  }
};

int main() {
  std::shared_ptr<ChatRoom> chat_room = std::make_shared<ChatRoom>();

  std::shared_ptr<User> alice = std::make_shared<User>(chat_room, "alice");
  std::shared_ptr<User> bob = std::make_shared<User>(chat_room, "bob");
  std::shared_ptr<User> charlie = std::make_shared<User>(chat_room, "charlie");

  chat_room->add_user(alice);
  chat_room->add_user(bob);
  chat_room->add_user(charlie);

  alice->send("hello everyone");
  bob->send("hi guys");
}