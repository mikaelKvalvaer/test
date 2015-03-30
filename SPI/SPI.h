#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include <stdbool.h>

#define LAST_TX true
#define NOT_LAST_TX false
#define SPI_MASTER_DUMMY_BYTE 0xFF

typedef enum spi_mode_e
{
	spi_mode_0 = 0, /*!< CPOL = 0, CPHA = 0 */
	spi_mode_1, /*!< CPOL = 0, CPHA = 1 */
	spi_mode_2, /*!< CPOL = 1, CPHA = 0 */
	spi_mode_3 /*!< CPOL = 1, CPHA = 1 */
} spi_mode_t;

typedef enum spi_prescaler_e
{
	spi_prescaler_2 = 0,/*!< OSCCLK/2 */
	spi_prescaler_4, /*!< OSCCLK/4 */
	spi_prescaler_8, /*!< OSCCLK/8 */
	spi_prescaler_16, /*!< OSCCLK/16 */
	spi_prescaler_32, /*!< OSCCLK/32 */
	spi_prescaler_64, /*!< OSCCLK/64 */
	spi_prescaler_128 /*!< OSCCLK/128 */
} spi_prescaler_t;


void spi_init(spi_mode_t mode, spi_prescaler_t scaler);
//return value is the incomming data
uint8_t spi_tranceive(uint8_t dataOut, bool isLastTransfer);
void spi_disable(void);

#endif /*SPI_H_*/