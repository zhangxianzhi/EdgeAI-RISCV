// See LICENSE for license details.

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include <string.h>
#include "plic/plic_driver.h"
#include "encoding.h"
#include <unistd.h>
#include "stdatomic.h"

#include "data.h"
#include "model.h"

int _getc(char * c){
  int32_t val = (int32_t) UART0_REG(UART_REG_RXFIFO);
  if (val > 0) {
    *c =  val & 0xFF;
    return 1;
  }
  return 0;
}

static void _putc(char c) {
  while ((int32_t) UART0_REG(UART_REG_TXFIFO) < 0);
  UART0_REG(UART_REG_TXFIFO) = c;
}

static void _putdat(uint8_t data) {
  while ((int32_t) UART0_REG(UART_REG_TXFIFO) < 0);
  UART0_REG(UART_REG_TXFIFO) = data;
}
/* uint8_t _getc(uint8_t * data){
  int32_t val = (int32_t) UART0_REG(UART_REG_RXFIFO);
  if (val > 0) {
    *data =  val & 0xFF;
    return 1;
  }
  return 0;
} */
uint8_t _getdata(uint8_t * data){
  int32_t val = (int32_t) UART0_REG(UART_REG_RXFIFO);
  if ((val& 0x8000)>>32 != 1) {
    *data =  val & 0x00FF;
    return 1;
  }
  return 0;
}

int main(int argc, char **argv)
{
	uint8_t i = 0;
	uint16_t j = 0;
	int8_t num = -1;
	uint8_t *uratdata_q;
	for (j = 0; j < 3; j++) {
		num = result(test_data[j]);
		for (i = 0; i < Out; i++){
			printf("%d:%f\n", i, Output[i]);
		}
		printf("predict NO.%d num is: %d\n", j, num);
	}
	j = 0;
	while(1){
		while(1){
			while (!_getdata(uratdata_q);
			if('b' == *uratdata_q){
				while (!_getdata(uratdata_q);
				if('e' == *uratdata_q){
					while (!_getdata(uratdata_q);
					if('g' == *uratdata_q){
						while (!_getdata(uratdata_q);
						if('i' == *uratdata_q){
							while (!_getdata(uratdata_q);
							if('n' == *uratdata_q){
								break;
							}
						}
					}
				}
			}
		}
		while (j < 784) {
			while (!_getdata(uratdata_q);
			test_data[0][j] = *uratdata_q;
			printf("I get %d",test_data[0][j]);
			j++;
		}
		num = result(test_data[0]);
		for (i = 0; i < Out; i++){
			printf("%d:%f\n", i, Output[i]);	
		}	
		printf("predict NO.%d num is: %d\n", j, num);
	}
	return 0;
}
