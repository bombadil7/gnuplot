#include <stdio.h>
#include <math.h>

int main(void)
{
    FILE* outfile;
    const double pi = M_PI;
    int i, nSamples = 50;
    double duration = 4*pi;
    double dx = duration / nSamples; 

    outfile = fopen("data.dat", "w");
    for(i = 0; i < nSamples; ++i) {
        fprintf(outfile, "%d %lf\n", i, sin(i*dx));
    }

    fclose(outfile);
    return 0;
}
