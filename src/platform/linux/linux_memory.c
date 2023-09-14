#ifdef __linux__

#include "anoptic_memalign.h"
#include <stdlib.h>

// Linux-specific implementation of aligned_malloc as defined in the anoptic_memory API.
void* anoptic_aligned_malloc(size_t size, size_t alignment) {
    void* ptr = NULL;
    if (posix_memalign(&ptr, alignment, size) != 0) {
        return NULL;  // posix_memalign will set errno appropriately
    }
    return ptr;
}

// Linux-specific implementation of aligned_free as defined in the anoptic_memory API.
void anoptic_aligned_free(void* ptr) {
    free(ptr);  // free works for memory allocated by posix_memalign
}



#endif