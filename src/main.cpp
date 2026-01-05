#include <print>
#include <glm/vec2.hpp>
#include "core/ParticleManager.hpp"

 using v2 = glm::vec2;

int main(int argc, char* argv[]) {
    ParticleManager p_manager;

    for (auto i{0uz}; i < 100uz; ++i) {
        p_manager.push_back(
            v2{i, 0.0f},
            v2{0.0f, i},
            v2{i, i}
        );
    }

    for (auto i{0uz}; i < p_manager.size(); ++i) {
        const auto& [p,v,a] = p_manager[i];
        std::println(
            "({:.2},{:.2})\t({:.2},{:.2})\t({:.2},{:.2})",
            p.x, p.y, v.x, v.y, a.x, a.y
        );
    }

    return 0;
}
