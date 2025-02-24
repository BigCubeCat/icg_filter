#include "state.hpp"

StateSingleton &StateSingleton::instance() {
  static StateSingleton inst;
  return inst;
}

int StateSingleton::width() const { return m_width; }

int StateSingleton::height() const { return m_height; }

void StateSingleton::setGeometry(int w, int h) {
  m_width = w;
  m_height = h;
}

void StateSingleton::selectFilter(e_filter tool) {
  // тут нужно поставить переменные по умолчанию
}

e_filter StateSingleton::currentFilter() const { return m_selected_filter; }
