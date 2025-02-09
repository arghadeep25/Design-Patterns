#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

// Iterator Interface
class Iterator {
 public:
  virtual ~Iterator() = default;
  virtual bool has_next() const = 0;
  virtual int next() = 0;
};

// Concrete Iterator
class ConcreteIterator : public Iterator {
 private:
  std::vector<int> collection;
  size_t position = 0;

 public:
  explicit ConcreteIterator(std::vector<int> items)
      : collection(std::move(items)) {}

  bool has_next() const override { return position < collection.size(); }

  int next() override { return has_next() ? collection[position++] : -1; }
};

// Aggregate Interface
class Iterable {
 public:
  virtual ~Iterable() = default;
  virtual std::shared_ptr<Iterator> create_iterator() const = 0;
};

// Concrete Collection
class ConcreteCollection : public Iterable {
 private:
  std::vector<int> items;

 public:
  void add_items(const int& items) { this->items.push_back(items); }

  std::shared_ptr<Iterator> create_iterator() const override {
    return std::make_shared<ConcreteIterator>(this->items);
  }
};

class PlaylistIterator {
 public:
  virtual ~PlaylistIterator() = default;
  virtual bool has_next() const = 0;
  virtual std::string next() const = 0;
};

class ConcretePlaylistIterator : public PlaylistIterator {
 private:
  std::vector<std::string> songs;
  mutable size_t index = 0;

 public:
  explicit ConcretePlaylistIterator(const std::vector<std::string>& songs)
      : songs(std::move(songs)) {}

  bool has_next() const override { return index < this->songs.size(); }

  std::string next() const override {
    return has_next() ? this->songs[this->index++] : "No more songs";
  }
};

class Playlist {
 public:
  virtual ~Playlist() = default;
  virtual std::shared_ptr<PlaylistIterator> create_iterator() const = 0;
};

class MusicPlayList : public Playlist {
 private:
  std::vector<std::string> songs;

 public:
  void add_songs(const std::string& song) { this->songs.push_back(song); }

  std::shared_ptr<PlaylistIterator> create_iterator() const override {
    return std::make_shared<ConcretePlaylistIterator>(this->songs);
  }
};

// Client Code
int main() {
  ConcreteCollection collection;
  collection.add_items(1);
  collection.add_items(2);
  collection.add_items(3);
  collection.add_items(4);

  std::shared_ptr<Iterator> iterator = collection.create_iterator();
  std::cout << "Iterating through collection..." << std::endl;
  while (iterator->has_next()) {
    std::cout << iterator->next() << " ";
  }
  std::cout << std::endl;

  MusicPlayList playlist;
  playlist.add_songs("Imagine Dragons");
  playlist.add_songs("Linkin Park");
  playlist.add_songs("Coldplay");

  std::shared_ptr<PlaylistIterator> playlist_iterator =
      playlist.create_iterator();

  std::cout << "Playing Songs..." << std::endl;
  while (playlist_iterator->has_next()) {
    std::cout << playlist_iterator->next() << std::endl;
  }
}