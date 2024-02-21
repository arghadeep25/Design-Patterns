#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
 private:
  Singleton(const std::string& value) : m_value(value){};
  static Singleton* m_instance;
  std::string m_value;
  static std::mutex m_mutex;

 public:
  /**
   * @brief Construct a new Singleton object
   *
   * @param other
   */
  Singleton(Singleton& other) = delete;

  /**
   * @brief
   *
   */
  void operator=(const Singleton&) = delete;

  /**
   * @brief Get the Instance object
   *
   * @param value
   * @return Singleton*
   */
  static Singleton* getInstance(const std::string& value) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_instance == nullptr) {
      m_instance = new Singleton(value);
    }
    return m_instance;
  }

  /**
   * @brief
   *
   * @return std::string
   */
  std::string value() const { return this->m_value; }
};

Singleton* Singleton::m_instance = nullptr;
std::mutex Singleton::m_mutex;

void thread_foo() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* singleton = Singleton::getInstance("foo");
  std::cout << singleton->value() << std::endl;
}

void thread_bar() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton* singleton = Singleton::getInstance("bar");
  std::cout << singleton->value() << std::endl;
}

int main() {
  std::thread t1(thread_foo);
  std::thread t2(thread_bar);
  t1.join();
  t2.join();
}