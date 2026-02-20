#include "status.h"
#include "description.h"


status_t show_error_message(const status_t status, QWidget *parent)
{
    switch (status)
    {
        case SUCCESS:
            break;

        case ERR_MEM:
            QMessageBox::critical(parent, ErrorMessage::ERR_MEM_TITLE, ErrorMessage::ERR_MEM_TEXT);
            break;

        case ERR_FILE:
            QMessageBox::critical(parent, ErrorMessage::ERR_FILE_TITLE, ErrorMessage::ERR_FILE_TEXT);
            break;

        case ERR_SCALE:
            QMessageBox::critical(parent, ErrorMessage::ERR_SCALE_TITLE, ErrorMessage::ERR_SCALE_TEXT);
            break;

        case ERR_EMPTY:
            QMessageBox::critical(parent, ErrorMessage::ERR_EMPTY_TITLE, ErrorMessage::ERR_EMPTY_TEXT);
            break;

        case ERR_NULL_PTR:
            QMessageBox::critical(parent, ErrorMessage::ERR_NULL_PTR_TITLE, ErrorMessage::ERR_NULL_PTR_TEXT);
            break;

        case ERR_UNDEFINED:
            QMessageBox::critical(parent, ErrorMessage::ERR_UNDEFINED_TITLE, ErrorMessage::ERR_UNDEFINED_TEXT);
            break;

        case ERR_FIGURE_DATA:
            QMessageBox::critical(parent, ErrorMessage::ERR_FIGURE_DATA_TITLE, ErrorMessage::ERR_FIGURE_DATA_TEXT);
            break;

        case ERR_OUT_OF_RANGE:
            QMessageBox::critical(parent, ErrorMessage::ERR_OUT_OF_RANGE_TITLE, ErrorMessage::ERR_OUT_OF_RANGE_TEXT);
            break;
    }

    return SUCCESS;
}

status_t show_description_message(QWidget *parent)
{
    QMessageBox::information(parent, Description::TITLE,  Description::ABOUT_PROGRAM);
    return SUCCESS;
}