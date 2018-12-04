
#include <linux/ioctl.h>
#include <asm/ioctl.h>

#define SJA1000_IOC_MAGIC  's'

#define SJA1000_IOCRESET    _IO(SJA1000_IOC_MAGIC, 0)

#define SJA1000_IOCTRANS   _IOW(SJA1000_IOC_MAGIC,  1, int)
#define SJA1000_IOCRECV    _IOWR(SJA1000_IOC_MAGIC,  2, int)
#define SJA1000_IOCBTR     _IOW(SJA1000_IOC_MAGIC,  3, int)
#define SJA1000_IOC_MAXNR 3

