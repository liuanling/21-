#include "sys.h"
#ifndef __LED_H
#define __LED_H

void LED_Init(void);
void LED_Turn(void);

#define LED_R PDout(14)
#define LED_G PCout(8)
#define LED_B PDout(15)

#define ON 1
#define OFF 0

#endif
