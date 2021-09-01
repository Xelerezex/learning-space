#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class Deque {
 private:
  vector<T> head, tail;

  T& AtImpl(size_t i) {
    return i < head.size() ? head[head.size() - i - 1] : tail[i - head.size()];
  }

  // Вынужденно дублируем код для случая, если у нас на Deque будет константная
  // ссылка
  // В последующих материалах курса мы узнаем, как избавиться от подобного
  // дублирования кода
  const T& AtImpl(size_t i) const {
    return i < head.size() ? head[head.size() - i - 1] : tail[i - head.size()];
  }

  void CheckIndex(size_t i) const {
    if (i >= Size())
      throw out_of_range("Index is out of range");
  }

 public:
  Deque() = default;

  bool Empty() const {
    return head.empty() && tail.empty();
  }

  size_t Size() const {
    return head.size() + tail.size();
  }

  const T& operator [] (size_t i) const {
    return AtImpl(i);
  }

  T& operator [] (size_t i) {
    return AtImpl(i);
  }

  const T& At(size_t i) const {
    CheckIndex(i);
    return AtImpl(i);
  }

  T& At(size_t i) {
    CheckIndex(i);
    return AtImpl(i);
  }

  const T& Front() const {
    return head.empty() ? tail.front() : head.back();
  }

  T& Front() {
    return head.empty() ? tail.front() : head.back();
  }

  const T& Back() const {
    return tail.empty() ? head.front() : tail.back();
  }

  T& Back() {
    return tail.empty() ? head.front() : tail.back();
  }

  void PushFront(const T& elem) {
    head.push_back(elem);
  }

  void PushBack(const T& elem) {
    tail.push_back(elem);
  }
};
