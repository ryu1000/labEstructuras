#ifndef CLASE_VECTOR
#define CLASE_VECTOR

class Vector{
	
	public:
	
	Vector(int);
	Vector(const Vector &); // Creo que esto no lo necesito
	
	protected:
	
	float *data;
	int dim;
	
};

#endif
