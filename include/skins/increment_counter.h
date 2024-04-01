//
// Created by Flynn on 01.04.2024.
//

// Increment the draw counter
// Corresponding boost hack: https://www.boost.org/doc/libs/1_55_0/libs/preprocessor/doc/ref/counter.html

#ifdef COUNTER_HELPER
#undef COUNTER_HELPER
#endif
#define COUNTER_HELPER DRAW_COUNTER + 1
#undef DRAW_COUNTER
#define DRAW_COUNTER COUNTER_HELPER
