int scprod(int dim, int vec1[], int vec2[]) {
	int result=0.;
	for(int i=0;i<dim;i++) {
		result += (vec1[i] * vec2[i]);
	}
	return result;
}


