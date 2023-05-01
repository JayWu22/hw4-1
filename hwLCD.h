/*
 * You can write copyrights rules here. These rules will be copied into the outputs.
 */

/*
 * Generated by erpcgen 1.10.0 on Sat Apr 29 16:08:38 2023.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_hwLCD_h_)
#define _hwLCD_h_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "erpc_version.h"

#if 11000 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

#if !defined(ERPC_TYPE_DEFINITIONS)
#define ERPC_TYPE_DEFINITIONS

#endif // ERPC_TYPE_DEFINITIONS

/*! @brief LCDService identifiers */
enum _LCDService_ids
{
    kLCDService_service_id = 1,
    kLCDService_lcd_locate_id = 1,
    kLCDService_lcd_cls_id = 2,
    kLCDService_lcd_rows_id = 3,
    kLCDService_lcd_columns_id = 4,
    kLCDService_lcd_putc_id = 5,
};

#if defined(__cplusplus)
extern "C" {
#endif

//! @name LCDService
//@{
void lcd_locate(uint8_t lcd);

void lcd_cls(void);

void lcd_rows(void);

void lcd_columns(void);

void lcd_putc(uint8_t lcd);
//@}

#if defined(__cplusplus)
}
#endif

#endif // _hwLCD_h_
