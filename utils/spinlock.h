typedef char spinlock_t;

#define lock(lock) do { \
    while (__sync_lock_test_and_set(&lock, 1)) { \
        asm volatile ("pause"); \
    } \
} while (0)

#define unlock(lock) do { \
    __sync_lock_release(&lock); \
} while (0)