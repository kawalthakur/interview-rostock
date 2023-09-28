#!/usr/bin/python3

import random

def calculate_correlation(M, delta_t, eta):
    # Calculate the value of T
    T = (M + 1) * delta_t

    # Initialize variables for the correlation calculation
    correlation_sum = 0.0

    # Calculating the correlation sum
    for j in range(0,M):
        t_j = j * delta_t

        if (t_j - eta) >= 0:
            correlation_sum += (
                0.5 * random.uniform(0, 1) +
                0.4 * random.uniform(0, 1) +
                0.3 * random.uniform(0, 1) +
                0.2 * random.uniform(0, 1) +
                0.1 * random.uniform(0, 1)
            ) * (
                0.5 * random.uniform(0, 1) +
                0.4 * random.uniform(0, 1) +
                0.3 * random.uniform(0, 1) +
                0.2 * random.uniform(0, 1) +
                0.1 * random.uniform(0, 1)
            )
    correlation = (1 / T) * correlation_sum

    return correlation
# given values
M = 10000
delta_t = 1e-2
eta = 0.02

correlation_result = calculate_correlation(M, delta_t, eta)
print(f"R(0.02) = {correlation_result}")
