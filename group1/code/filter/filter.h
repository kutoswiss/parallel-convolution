
typedef struct filter_st{
	int size;
	int** matrix;
}filter_t;

void set_identity_filter(filter_t* f);