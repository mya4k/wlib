#include <wl/dynamic.h>
#include <wl/array.h>



/**
 * \brief 	Dynamic Array Allocate
 * \def		void* dal(const U32 elmSize, const U32 elmCount)
 * \param	elmSize		Size of an element in bytes
 * \param	elmCount	Number of the elements
 * \return	Pointer to the struct holding metadata of the Dinamic array 
 */
void* _dal(const U32 elmSize, const U32 elmCount) {
	const U32 allocated = 2*elmSize*elmCount;
	Da* meta = (Da*)hal(allocated + sizeof(Da));

	if_likely (meta) {
		meta->allocated = allocated;
		meta->elmSize = meta->elmSize;
		meta->elmCount = elmCount;
	}

	return meta;
}

/**
 * \brief 	Dynamic Array Reallocate 
 * \fn		const void* drl(const void* array, const U32 elmCount)
 * \param	elmSize		Size of an element in bytes
 * \param	elmCount	Number of the elements
 * \return	Pointer to the struct holding metadata of the reallocated Dinamic 
 * array 
 */
void* _dra(void* meta, const U32 elmCount) {
	const U32 allocated = 2*meta->elmSize*elmCount;
	meta = (Da*)hra(meta, allocated + sizeof(Da));

	if_likely (meta) {
		meta->allocated = allocated;
		meta->elmCount = elmCount;
	}

	return meta;
}

void* _daa(Da* meta, void* appendData, const U32 count) {
	U32 newCount = meta->elmCount+count;

	if_unlikely (meta->allocated < meta->elmSize*newCount) {
		meta = dam(dra(meta, newCount));

		if_unlikely (meta == dam(NULL)) return NULL;
	}

	ano(appendData, count*meta->elmSize, dad(meta));

	return meta;
}
