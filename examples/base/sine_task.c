#include <stdio.h>
#include <pal.h>

int main()
{
    int size = 1;
    float a[3] = { 0.0, 0.5, 1.0 };
    float b[3];
    p_team_t team;
    printf("Running p_sin_32f()\n");
    p_sin_f32(a, b, size,1,team);
    
    return 0;
}
