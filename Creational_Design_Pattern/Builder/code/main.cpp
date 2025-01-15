#include <iostream>
#include <memory>
#include <vector>

// Defining the product
class House {
 public:
  House() = default;
  ~House() = default;

 public:
  void setWalls(const std::string &material) { this->walls = material; }

  void setRoof(const std::string &material) { this->roof = material; }

  void setDoors(const std::string &material) { this->doors = material; }

  void setWindows(const std::string &material) { this->windows = material; }

  void show() const {
    std::cout << "House Details: " << std::endl;
    std::cout << "Walls: " << this->walls << "\n";
    std::cout << "Roof: " << this->roof << "\n";
    std::cout << "Doors: " << this->doors << "\n";
    std::cout << "Windows: " << this->windows << "\n";
  }

 private:
  std::string walls;
  std::string roof;
  std::string doors;
  std::string windows;
};

// Defining the abstract builder
class HouseBuilder {
 public:
  virtual ~HouseBuilder() = default;

  virtual void buildWalls() = 0;
  virtual void buildRoof() = 0;
  virtual void buildDoors() = 0;
  virtual void buildWindows() = 0;

  virtual std::shared_ptr<House> getHouse() = 0;
};

// Defining concrete wooden house builder
class WoodenBuilder : public HouseBuilder {
 public:
  WoodenBuilder() { house = std::make_shared<House>(); }

 public:
  void buildWalls() override { house->setWalls("Wooden Walls"); }
  void buildRoof() override { house->setRoof("Wooden Roof"); }
  void buildDoors() override { house->setDoors("Wooden Doors"); }
  void buildWindows() override { house->setWindows("Wooden Windows"); }

  std::shared_ptr<House> getHouse() override { return (house); }

 private:
  std::shared_ptr<House> house;
};

// Defining concrete stone house builder
class StoneBuilder : public HouseBuilder {
 public:
  StoneBuilder() { house = std::make_shared<House>(); }

 public:
  void buildWalls() override { house->setWalls("Stone Walls"); }
  void buildRoof() override { house->setRoof("Stone Roof"); }
  void buildDoors() override { house->setDoors("Stone Doors"); }
  void buildWindows() override { house->setWindows("Stone Windows"); }

  std::shared_ptr<House> getHouse() override { return (house); }

 private:
  std::shared_ptr<House> house;
};

// Director
class ConstructionDirector {
 public:
  ConstructionDirector(std::shared_ptr<HouseBuilder> builder) {
    houseBuilder = builder;
  }

 public:
  void constructHouse() {
    houseBuilder->buildWalls();
    houseBuilder->buildRoof();
    houseBuilder->buildDoors();
    houseBuilder->buildWindows();
  }

 private:
  std::shared_ptr<HouseBuilder> houseBuilder;
};

int main() {
  std::shared_ptr<HouseBuilder> woodenHouseBuilder =
      std::make_shared<WoodenBuilder>();
  ConstructionDirector director((woodenHouseBuilder));
  director.constructHouse();
  std::shared_ptr<House> woodenHouse = woodenHouseBuilder->getHouse();
  woodenHouse->show();

  std::shared_ptr<HouseBuilder> stoneHouseBuilder =
      std::make_shared<StoneBuilder>();
  director = stoneHouseBuilder;
  director.constructHouse();
  std::shared_ptr<House> stoneHouse = stoneHouseBuilder->getHouse();
  stoneHouse->show();
}