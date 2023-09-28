#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Stochastic Function 
float phi(float* rand_data)
{
    float phi_t;
    float r0, r1, r2, r3, r4;
    r0 = rand_data[0]; // r(j) 
    r1 = rand_data[1]; // r(j-1)
    r2 = rand_data[2]; // r(j-2)
    r3 = rand_data[3]; // r(j-3)
    r4 = rand_data[4]; // r(j-4)

    phi_t = 0.5*r0 + 0.4*r1 + 0.3*r2 + 0.2*r3 + 0.1*r4 ;
    return phi_t;
}

// Correlation function 
float R(int M, float delta_t, float eta)
{
    float T = (M + 1) * delta_t ;
    float R_integral = 0;
    float phi_t;
    float rand_num[5] = {0,0,0,0,0};
    for(int i = 0 ; i <=M ; i++)
    {
        /* 
           Store generated random numbers at a 
           interval of 5 in a buffer array, since 
           phi used previously generated random numbers. 
           We then pass this array to stochastic 
           function to calculate the value of phi 
        */  

        // Generating random no. from uniform dist.
        rand_num[i%5] = (float)rand() / RAND_MAX;

        phi_t = phi(rand_num);
        
        R_integral += phi_t*phi_t;
    }
   R_integral = (1/T) * R_integral;
   return R_integral;

}

// Another important statement

int main()
{
    // Seeding Random number
    srand(time(0));

    int M = 10000;
    float delta_t = 0.01;
    float eta = 0.02;

    // Calculating the correlation function 
    float R_value = R(M, delta_t, eta);
    printf("R(0.02) =  %f\n",R_value);
    return 0;
}
