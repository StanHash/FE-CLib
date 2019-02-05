#ifndef GBAFE_COMMON_H
#define GBAFE_COMMON_H

#include <stddef.h>
#include <stdint.h>

typedef struct Vector2 Vector2;
typedef struct Vector2U Vector2U;

enum {
	WEATHER_NONE = 0,
	WEATHER_SNOW = 1,
	WEATHER_SNOWSTORM = 2,
	WEATHER_3 = 3,
	WEATHER_RAIN = 4,
	WEATHER_FLAMES = 5,
	WEATHER_SANDSTORM = 6,
	WEATHER_CLOUDS = 7
};

struct Vector2 {
	short x, y;
};

struct Vector2U {
	u16 x, y;
};

#endif // GBAFE_COMMON_H
