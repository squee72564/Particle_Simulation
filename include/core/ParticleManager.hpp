#ifndef PARTICLE_MANAGER_HPP
#define PARTICLE_MANAGER_HPP

#include <vector>
#include <glm/vec2.hpp>

struct ParticleRef {
    glm::vec2& pos;
    glm::vec2& vel;
    glm::vec2& acc;
};

struct ParticleConstRef {
    const glm::vec2& pos;
    const glm::vec2& vel;
    const glm::vec2& acc;
};

class ParticleManager {
public:
    ParticleManager() = default;
    ~ParticleManager() = default;

    bool is_empty() const noexcept;

    size_t size() const noexcept;

    size_t max_size() const noexcept;

    void reserve(size_t new_cap);

    size_t capacity() const noexcept;

    void clear() noexcept;

    template <typename P, typename V, typename A>
    void push_back(P&& p, V&& v, A&& a);

    void pop_back();

    [[nodiscard]] ParticleRef operator[](size_t i);
    [[nodiscard]] const ParticleConstRef operator[](size_t i) const;

private:
    std::vector<glm::vec2> pos_, vel_, acc_;
};

template <typename P, typename V, typename A>
void ParticleManager::push_back(P&& p, V&& v, A&& a)
{
    pos_.push_back(std::forward<P>(p));
    vel_.push_back(std::forward<V>(v));
    acc_.push_back(std::forward<A>(a));
}

#endif // PARTICLE_MANAGER_HPP
