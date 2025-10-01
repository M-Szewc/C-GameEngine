#include <core/logger.h>
#include <core/asserts.h>

int main(void) {

    GE_FATAL("A test message: %d", 2137);
    GE_ERROR("A test message: %d", 2137);
    GE_WARN("A test message: %d", 2137);
    GE_INFO("A test message: %d", 2137);
    GE_DEBUG("A test message: %d", 2137);
    GE_TRACE("A test message: %d", 2137);

    GE_ASSERT(1 == 0);
    GE_ASSERT_MSG(2 + 2 == 5, "you stupid!");

    return 0;
}