#include <stdio.h>
#include <math.h>

int main(void)
{
    FILE* outfile;
    FILE* gnuplot;
    const double pi = M_PI;
    int i, nSamples = 50;
    double duration = 4*pi;
    double dx = duration / nSamples; 

    // Open a pipe to gnuplot
    gnuplot = popen("gnuplot -persis", "w");
    if (!gnuplot)
        return 1;

    // Generate a sinewave and store points into a file
    outfile = fopen("data.dat", "w");
    for(i = 0; i < nSamples; ++i) {
        fprintf(outfile, "%d %lf\n", i, sin(i*dx));
    }
    fclose(outfile);

    // Plot the sinewave in gnuplot
    fprintf(gnuplot, "set yrange [-1.2:1.2]\n");
    fprintf(gnuplot, "plot 'data.dat'\n");
    return 0;
}
