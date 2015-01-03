/*
 * A 3x3 moving average filter.  Basically a convolution with a 3x3
 * coefficient matrix all set to ones.
 *
 *    |1 1 1|
 * M =|1 1 1| * 1/9
 *    |1 1 1|
 *
 */


void p_average3x3_32f (const float* x, float* r, int rows, int cols){

    
    int ia, ja;
    float E;
    float *px, *pr;
    
    px = x;
    pr = r;
    
    for (ia=1; ia<=(rows-2); ia++){
	for (ja=1; ja<=(cols-2); ja++){
	    E = 0;	    
	    E += (*px++);     
	    E += (*px++);     
	    E += (*px++);     
	    px += cols - 3;
	    E += (*px++);     
	    E += (*px++);     
	    E += (*px++);     
	    px += cols - 3;
	    E += (*px++);     
	    E += (*px++);     
	    E += (*px++);     
	    px += cols - 3;	    
	    *pr = E / 9; //multiply by (1/9) constant instead	    
	    px += 1 - 3 * cols; // advance mask matrix in one column.
	    pr++;
	}
	px = px + 2; //advance pointer to the beginning of next row.
    }
    
    return;
}