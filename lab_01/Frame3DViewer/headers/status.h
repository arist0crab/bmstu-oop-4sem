#ifndef __STATUS_H__
#define __STATUS_H__

#include <QMessageBox>
#include <QWidget>

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

status_t show_description_message(QWidget *parent);
status_t show_error_message(const status_t status, QWidget *parent);

#endif