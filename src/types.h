struct Analogs {
	unsigned int LX;
	unsigned int LY;
	unsigned int RX;
	unsigned int RY;
};

#define BTN_L1 0
#define BTN_L2 1
#define BTN_R1 2
#define BTN_R2 3
#define BTN_L3 4
#define BTN_R3 5
#define BTN_UP 6
#define BTN_DOWN 7
#define BTN_LEFT 8
#define BTN_RIGHT 9
#define BTN_TRIANGLE 10
#define BTN_CROSS 11
#define BTN_SQUARE 12
#define BTN_CIRCLE 13
#define BTN_SELECT 14
#define BTN_START 15


struct PS2Keys {
	char digitalKeys[16];
	Analogs analogKeys;
};


#define printPS2Keys(keys) \
	Serial.print(" L1:"); \
	Serial.print(keys.digitalKeys[BTN_L1]); \
	Serial.print(" L2:"); \
	Serial.print(keys.digitalKeys[BTN_L2]); \
	Serial.print(" R1:"); \
	Serial.print(keys.digitalKeys[BTN_R1]); \
	Serial.print(" R2:"); \
	Serial.print(keys.digitalKeys[BTN_R2]); \
	Serial.print( "L3:"); \
	Serial.print(keys.digitalKeys[BTN_L3]); \
	Serial.print(" R3:"); \
	Serial.print(keys.digitalKeys[BTN_R3]); \
	Serial.print(" UP:"); \
	Serial.print(keys.digitalKeys[BTN_UP]); \
	Serial.print(" DOWN:"); \
	Serial.print(keys.digitalKeys[BTN_DOWN]); \
	Serial.print(" LEFT:"); \
	Serial.print(keys.digitalKeys[BTN_LEFT]); \
	Serial.print(" RIGHT:"); \
	Serial.print(keys.digitalKeys[BTN_RIGHT]); \
	Serial.print(" TRIANGLE:"); \
	Serial.print(keys.digitalKeys[BTN_TRIANGLE]); \
	Serial.print(" CROSS:"); \
	Serial.print(keys.digitalKeys[BTN_CROSS]); \
	Serial.print(" SQUARE:"); \
	Serial.print(keys.digitalKeys[BTN_SQUARE]); \
	Serial.print(" CIRCLE:"); \
	Serial.print(keys.digitalKeys[BTN_CIRCLE]); \
	Serial.print(" SELECT:"); \
	Serial.print(keys.digitalKeys[BTN_SELECT]); \
	Serial.print(" START:"); \
	Serial.print(keys.digitalKeys[BTN_START]); \
	Serial.print(" LX:"); \
	Serial.print(keys.analogKeys.LX); \
	Serial.print(" LY:"); \
	Serial.print(keys.analogKeys.LY); \
	Serial.print(" RX:"); \
	Serial.print(keys.analogKeys.RX); \
	Serial.print(" RY:"); \
	Serial.print(keys.analogKeys.RY); \
	Serial.println();


