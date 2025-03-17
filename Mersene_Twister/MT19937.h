#ifndef MT19937_H
#define MT19937_H

#include <stdint.h>

/** Constants for MT19937 algorithm */
#define MT_N 624
#define MT_M 397
#define MATRIX_A 0x9908b0df   // Constant for tempering
#define UPPER_MASK 0x80000000  // Upper mask
#define LOWER_MASK 0x7fffffff  // Lower mask

/**
 * \brief Structure representing the state of the MT19937 random number generator.
 */
typedef struct {
    uint32_t mt[MT_N]; /**< The state vector array. */
    int index;         /**< The index into the state vector. */
} MT19937;

/**
 * \brief Initializes the MT19937 state with a seed.
 *
 * \param mt Pointer to the MT19937 structure to initialize.
 * \param seed The seed value to initialize the state with.
 */
void mt_seed(MT19937 *mt, uint32_t seed);

/**
 * \brief Generates the next set of random numbers for MT19937.
 *
 * \param mt Pointer to the MT19937 structure.
 */
void mt_generate(MT19937 *mt);

/**
 * \brief Generates a random number using the MT19937 algorithm.
 *
 * \param mt Pointer to the MT19937 structure.
 * \return A 32-bit unsigned random number.
 */
uint32_t mt_random(MT19937 *mt);

uint32_t mt_random_range(MT19937 *mt, uint32_t min, uint32_t max);
#endif // MT19937_H
