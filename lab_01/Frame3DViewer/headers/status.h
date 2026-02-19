#ifndef __STATUS_H__
#define __STATUS_H__

typedef enum 
{
    SUCCESS,
    ERR_MEM,
    ERR_FILE,
    ERR_SCALE,
    ERR_EMPTY,
    ERR_NULL_PTR,
    ERR_UNDEFINED,
    ERR_FIGURE_DATA,
    ERR_OUT_OF_RANGE
} status_t;

#endif