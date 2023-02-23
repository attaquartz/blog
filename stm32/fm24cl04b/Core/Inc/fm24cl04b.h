#define FM24CL04B_I2C_ADDR			(0xA0)
#define FM24CL04B_PAGE0		        (0x00)
#define FM24CL04B_PAGE1		        (0x02)
#define FM24CL04B_READ_MAXSIZE		(16)

#define HIGHBYTE(x)					(uint8_t)((x >> 8) & 0xFF)
#define LOWBYTE(x)					(uint8_t)(x & 0xFF)

