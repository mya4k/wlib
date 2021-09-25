#ifndef WC_ERROR_H
#define WC_ERROR_H



#ifndef NO_SHORT_NAMES
#	define err		wl_err
#	define error	wl_error
#endif



#define NULLPTR	1	/* Null pointer */
#define EXCSTR	2	/* Excessively long string */



/**
 * \brief	Error
 * \def		wl_err(X)
 * \def		wl_error(X)
 */
#define	wl_err(X)	(wl__err = (X))
#define wl_error(X)	wl_err(X)



extern u8 wl__err;



#endif
