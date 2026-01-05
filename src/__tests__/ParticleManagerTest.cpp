#include <gtest/gtest.h>

#include "core/ParticleManager.hpp"

TEST(ParticleManager, CompilesAndConstructs) {
    ParticleManager manager;
    EXPECT_TRUE(manager.is_empty());
    EXPECT_EQ(manager.size(), 0u);
}
