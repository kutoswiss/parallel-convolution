
/**
 * Structure filter_st 
 * The convolution filter structure is composed
 * typedef filter_t
 */
typedef struct filter_st{
	int size; /**< integer type for the size of the matrix (always a square size */
	int* matrix; /**< Pointer to an integer to store the matrix on a one dimension array*/
}filter_t;

void set_identity_filter(filter_t* f);
void set_edge_filter(filter_t* f);
void print_filter(filter_t* f);
void free_filter(filter_t* f);