#include "keylist.hpp"
#include "load_file.hpp"

Keylist::Keylist() {
  this->keys = load_keylist();
}

void Keylist::refresh_keys() {
  this->keys = load_keylist();
}

Keylist::~Keylist() {
  delete this->keys;
}