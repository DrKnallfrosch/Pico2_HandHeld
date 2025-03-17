#include "MT19937.h"

/**
 * \brief Initializes the MT19937 state with a seed.
 *
 * This function initializes the internal state array of the MT19937
 * pseudorandom number generator with a given seed. The initialization
 * process ensures that the generator will produce a repeatable sequence
 * of pseudorandom numbers for the same seed.
 *
 * \param mt A pointer to an MT19937 structure that holds the state of the generator.
 * \param seed The seed value used to initialize the generator.
 */
uint32_t mt_random(MT19937 *mt) {
    if (mt->index >= MT_N) {
        mt_generate(mt);
        mt->index = 0;
    }
    uint32_t y = mt->mt[mt->index++];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);
    return y;
}

/**
 * Generates a random number within a specified range using the Mersenne Twister algorithm.
 *
 * @param mt   A pointer to an MT19937 structure, which holds the state of the Mersenne Twister.
 * @param min  The minimum value of the range (inclusive).
 * @param max  The maximum value of the range (exclusive).
 * @return     A random number in the range [min, max).
 */
uint32_t mt_random_range(MT19937 *mt, uint32_t min, uint32_t max) {
    return min + mt_random(mt) % max;
}
