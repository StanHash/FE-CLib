#ifndef GBAFE_EVENT_H
#define GBAFE_EVENT_H

extern unsigned gEventSlot[];
extern unsigned gEventQueue[];

extern unsigned gEventCounter;

#pragma long_calls

void SetEventCounter(unsigned); //! FE8U = 0x800D589
unsigned GetEventCounter(void); //! FE8U = 0x800D595

#pragma long_calls_off

#endif // GBAFE_EVENT_H
