#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
  GE_FATAL("Logging test message: %f", 3.14f);
  GE_ERROR("Logging test message: %f", 3.14f);
  GE_WARN("Logging test message: %f", 3.14f);
  GE_INFO("Logging test message: %f", 3.14f);
  GE_DEBUG("Logging test message: %f", 3.14f);
  GE_TRACE("Logging test message: %f", 3.14f);

  GE_ASSERT(1 == 1);
  return 0;
}
