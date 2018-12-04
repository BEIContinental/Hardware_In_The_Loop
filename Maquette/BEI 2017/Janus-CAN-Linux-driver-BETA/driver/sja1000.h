
#define SJA1000_MAX_IRQ 20	/* max. number of interrupts handled in ISR */

/* SJA1000 registers - manual section 6.4 (Pelican Mode) */
#define REG_MOD		0x00
#define REG_CMR		0x01
#define REG_SR		0x02
#define REG_IR		0x03
#define REG_IER		0x04
#define REG_ALC		0x0B
#define REG_ECC		0x0C
#define REG_EWL		0x0D
#define REG_RXERR	0x0E
#define REG_TXERR	0x0F
#define REG_ACCC0	0x10
#define REG_ACCC1	0x11
#define REG_ACCC2	0x12
#define REG_ACCC3	0x13
#define REG_ACCM0	0x14
#define REG_ACCM1	0x15
#define REG_ACCM2	0x16
#define REG_ACCM3	0x17
#define REG_RMC		0x1D
#define REG_RBSA	0x1E

/* Common registers - manual section 6.5 */
#define REG_BTR0	0x06
#define REG_BTR1	0x07
#define REG_OCR		0x08
#define REG_CDR		0x1F

#define REG_FI		0x10
#define SFF_BUF		0x13
#define EFF_BUF		0x15

#define FI_FF		0x80
#define FI_RTR		0x40

#define REG_ID1		0x11
#define REG_ID2		0x12
#define REG_ID3		0x13
#define REG_ID4		0x14

#define CAN_RAM		0x20

/* mode register */
#define MOD_RM		0x01
#define MOD_LOM		0x02
#define MOD_STM		0x04
#define MOD_AFM		0x08
#define MOD_SM		0x10

/* commands */
#define CMD_SRR		0x10
#define CMD_CDO		0x08
#define CMD_RRB		0x04
#define CMD_AT		0x02
#define CMD_TR		0x01

/* interrupt sources */
#define IRQ_BEI		0x80
#define IRQ_ALI		0x40
#define IRQ_EPI		0x20
#define IRQ_WUI		0x10
#define IRQ_DOI		0x08
#define IRQ_EI		0x04
#define IRQ_TI		0x02
#define IRQ_RI		0x01
#define IRQ_ALL		0xFF
#define IRQ_OFF		0x00

/* status register content */
#define SR_BS		0x80
#define SR_ES		0x40
#define SR_TS		0x20
#define SR_RS		0x10
#define SR_TCS		0x08
#define SR_TBS		0x04
#define SR_DOS		0x02
#define SR_RBS		0x01

#define SR_CRIT (SR_BS|SR_ES)

/* ECC register */
#define ECC_SEG		0x1F
#define ECC_DIR		0x20
#define ECC_ERR		6
#define ECC_BIT		0x00
#define ECC_FORM	0x40
#define ECC_STUFF	0x80
#define ECC_MASK	0xc0

/* clock divider register */
#define CDR_CLKOUT_MASK 0x07
#define CDR_CLK_OFF     0x08 /* Clock off (CLKOUT pin) */
#define CDR_RXINPEN     0x20 /* TX1 output is RX irq output */
#define CDR_CBP         0x40 /* CAN input comparator bypass */
#define CDR_PELICAN     0x80 /* PeliCAN mode */

/* output control register */
#define OCR_MODE_BIPHASE  0x00
#define OCR_MODE_TEST     0x01
#define OCR_MODE_NORMAL   0x5E
#define OCR_MODE_CLOCK    0x03
#define OCR_MODE_MASK     0x07
#define OCR_TX0_INVERT    0x04
#define OCR_TX0_PULLDOWN  0x08
#define OCR_TX0_PULLUP    0x10
#define OCR_TX0_PUSHPULL  0x18
#define OCR_TX1_INVERT    0x20
#define OCR_TX1_PULLDOWN  0x40
#define OCR_TX1_PULLUP    0x80
#define OCR_TX1_PUSHPULL  0xc0
#define OCR_TX_MASK       0xfc
#define OCR_TX_SHIFT      2

struct sja1000_platform_data {
        u32 clock;      /* CAN bus oscillator frequency in Hz */

        u8 ocr;         /* output control register */
        u8 cdr;         /* clock divider register */
};


/*
 * Flags for sja1000priv.flags
 */
#define SJA1000_CUSTOM_IRQ_HANDLER 0x1

#define MAXQ 100

/*
 * SJA1000 private data structure
 */
struct sja1000_priv {
	struct can_frame cf;
	int txrxflag;
	u8 BTR0;
	u8 BTR1;
	/* FIFO */
	unsigned long Q[MAXQ+1][12];
	int Front;
	int Rear;
	/* the lower-layer is responsible for appropriate locking */
	u8 (*read_reg) (const struct sja1000_priv *priv, int reg);
	void (*write_reg) (const struct sja1000_priv *priv, int reg, u8 val);
	void (*pre_irq) (const struct sja1000_priv *priv);
	void (*post_irq) (const struct sja1000_priv *priv);

	struct cdev cdev;
	const char *dev_name;
	void __iomem *reg_base;	 /* ioremap'ed address to registers */
	int irq;
	unsigned long irq_flags; /* for request_irq() */

	u16 flags;		/* custom mode flags */
	u8 ocr;			/* output control register */
	u8 cdr;			/* clock divider register */
};

struct can_bittime {
       uint32_t brp;
       uint8_t prop_seg;
       uint8_t phase_seg1;
       uint8_t phase_seg2;
       uint8_t sjw;
       uint32_t tq;
       uint32_t error;
       int sampl_pt;
};

struct can_bittiming_const {
       char name[32];
       int prop_seg_min;
       int prop_seg_max;
       int tseg1_min;
       int tseg1_max;
       int tseg2_min;
       int tseg2_max;
       int sjw_max;
       int brp_min;
       int brp_max;
       int brp_inc;
       void (*printf_btr)(struct can_bittime *bt, int hdr);
};
