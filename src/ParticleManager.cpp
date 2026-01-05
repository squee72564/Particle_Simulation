#include "ParticleManager.hpp"

#include <cassert>

bool ParticleManager::is_empty() const noexcept {
  assert(pos_.empty() == acc_.empty());
  assert(acc_.empty() == vel_.empty());

  return pos_.empty();
}

size_t ParticleManager::size() const noexcept {
  assert(pos_.size() == acc_.size());
  assert(acc_.size() == vel_.size());

  return pos_.size();
}

size_t ParticleManager::max_size() const noexcept {
  assert(pos_.max_size() == acc_.max_size());
  assert(acc_.max_size() == vel_.max_size());

  return pos_.max_size();
}

void ParticleManager::reserve(size_t new_cap) {
  pos_.reserve(new_cap);
  vel_.reserve(new_cap);
  acc_.reserve(new_cap);
}

size_t ParticleManager::capacity() const noexcept {
  assert(pos_.capacity() == acc_.capacity());
  assert(acc_.capacity() == vel_.capacity());

  return pos_.capacity();
}

void ParticleManager::clear() noexcept {
  pos_.clear();
  vel_.clear();
  acc_.clear();
}

void ParticleManager::pop_back() {
  pos_.pop_back();
  vel_.pop_back();
  acc_.pop_back();
}

ParticleRef ParticleManager::operator[](size_t i) {
  return {pos_[i], vel_[i], acc_[i]};
}

const ParticleConstRef ParticleManager::operator[](size_t i) const {
  return {pos_[i], vel_[i], acc_[i]};
}
