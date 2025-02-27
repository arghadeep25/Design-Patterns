#include <iostream>
#include <memory>

class Database {
 private:
  Database() = default;

 private:
  ~Database() = default;

 private:
  /**
   * @brief static is used here in order to make the variable persist
   *        for the lifetime of the program ensuring the instance of
   *        the Database class is not destroyed prematurely.
   *
   */
  static std::unique_ptr<Database> m_instance;

 public:
  /**
   * @brief delete the copy constructor. usually copy constructor
   *        in c++ takes the non-const ref. deleting Database &
   *        deletes the const and non-const ref. if const Database
   *        is used, only const will be deleted and non-const will
   *        will still be allowed
   *        Database a; // default constructor
   *        Database b = a // error: copy constructor deleted
   *        const Database c;
   *        Database d = c; // also deleted
   */
  Database(Database &) = delete;

 public:
  /**
   * @brief deletes the copy assignment operator. preventing
   *        assigning one Database object to another. assignment
   *        operator usually takes const ref to ensure the source
   *        object is not modified during assignment. assigning
   *        non const ref doesn't make sense as assignment
   *        doesn't req modifying the source object
   *
   */
  void operator=(const Database &) = delete;

 public:
  /**
   * @brief Get the Instance object. function to ensure that
   *        a single instance of Database is created. if no
   *        previous existence is found, then it will create
   *        an instance
   *
   * @return Database*
   */
  static Database *getInstance() {
    if (!m_instance) m_instance.reset(new Database());
    return m_instance.get();
  }

 public:
  void print() { std::cout << "hello from database" << std::endl; }
};

std::unique_ptr<Database> Database::m_instance = nullptr;

int main() {
  Database *db = Database::getInstance();
  db->print();
}
