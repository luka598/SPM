#pragma once
#include <vector>

namespace lang {
template <typename T> class Buffer {
public:
  Buffer(std::vector<T> _items) : items(_items){};

  size_t left() { return items.size() - index; }

  bool end() { return left() <= 0; }

  bool canPeek(size_t forward) {
    if (forward == 0)
      return false;
    return left() >= forward;
  }

  T peek(size_t forward) {
    if (!canPeek(forward))
      throw "Can't peek when size of items is < forward or forward = 0";
    return items.at(index + forward);
  }

  T peek() { return peek(1); }

  bool canAdvance() { return left() > 0; }

  void advance() { index++; }

  void ad() { return advance(); }

  T at() { return items.at(index); }

  int getIndex() const { return index; }

private:
  size_t index = 0;
  std::vector<T> items;
};

} // namespace lang
