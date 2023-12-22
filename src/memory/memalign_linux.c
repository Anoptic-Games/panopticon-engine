/* SPDX-FileCopyrightText: 2023 Anoptic Game Engine Authors
 *
 * SPDX-License-Identifier: LGPL-3.0 */
/*  == Anoptic Game Engine v0.0000001 == */

#ifdef __linux__

#include "anoptic_memalign.h"
#include <stdlib.h>
#include <stdio.h>


// Linux-specific implementation of aligned_malloc as defined in the ano_memory API.
void* ano_aligned_malloc(size_t size, size_t alignment) {
    void* ptr = NULL;

    // Ensure the alignment is at least sizeof(void*)
	if (alignment < sizeof(void *))
   		alignment = sizeof(void *);

	int result = posix_memalign(&ptr, alignment, size);
    if (result != 0) {
		fprintf(stderr, "posix_memalign error: %d\n", result);
        return NULL;  // posix_memalign will set errno appropriately
    }
    return ptr;
}

// Linux-specific implementation of aligned_free as defined in the ano_memory API.
void ano_aligned_free(void* ptr) {
    free(ptr);  // free works for memory allocated by posix_memalign
}

#endif