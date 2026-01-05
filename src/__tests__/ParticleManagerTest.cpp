#include <vector>

#include <glm/vec2.hpp>
#include <gtest/gtest.h>

#include "core/ParticleManager.hpp"

using v2 = glm::vec2;
constexpr auto vec1 = v2(1.9f, 2.8f);
constexpr auto vec2 = v2(3.7f, 4.6f);
constexpr auto vec3 = v2(5.5f, 6.4f);

TEST(ParticleManager, Init) {
    ParticleManager manager;
    EXPECT_TRUE(manager.is_empty());
    EXPECT_EQ(manager.size(), 0uz);
}

TEST(ParticleManager, PushBack) {
    ParticleManager manager;
    
    manager.push_back(
        vec1,vec2,vec3
    );

    EXPECT_EQ(manager.size(), 1uz);

    const auto& [p, v, a] = manager[0];

    EXPECT_EQ(p, vec1);
    EXPECT_EQ(v, vec2);
    EXPECT_EQ(a, vec3);
}

TEST(ParticleManager, PopBack) {
    ParticleManager manager;
    
    manager.push_back(
        vec1,vec2,vec3
    );
    EXPECT_EQ(manager.size(), 1uz);

    manager.pop_back();
    EXPECT_EQ(manager.size(), 0uz);
}

TEST(ParticleManager, IsEmpty) {
    ParticleManager manager;
    EXPECT_TRUE(manager.is_empty());
    
    manager.push_back(
        vec1,vec2,vec3
    );

    EXPECT_FALSE(manager.is_empty());

    manager.pop_back();
    EXPECT_TRUE(manager.is_empty());
}

TEST(ParticleManager, Size) {
    ParticleManager manager;
    EXPECT_EQ(manager.size(), 0uz);
    
    for (auto i{0uz}; i < 100uz; ++i) {
        manager.push_back(
            vec1,vec2,vec3
        );
    }

    EXPECT_EQ(manager.size(), 100uz);
}

TEST(ParticleManager, Clear) {
    ParticleManager manager;
    
    for (auto i{0uz}; i < 100uz; ++i) {
        manager.push_back(
            vec1,vec2,vec3
        );
    }

    manager.clear();
    EXPECT_EQ(manager.size(), 0uz);
}


TEST(ParticleManager, ReserveCapacity) {
    ParticleManager manager;

    const auto RESERVE_SIZE{ 1024uz };

    manager.reserve( RESERVE_SIZE );
    EXPECT_GE(manager.capacity(), RESERVE_SIZE);
}

TEST(ParticleManager, MaxSize) {
    ParticleManager manager;
    EXPECT_EQ(manager.max_size(), std::vector<v2>{}.max_size());
}


