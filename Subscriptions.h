#ifndef _SUBSCRIPTIONS_H_
#define _SUBSCRIPTIONS_H_

enum class SubscriptionType { Annihilation, Cell, Display };

// Annihilation	-	The only object that subscribes only to the annihilation of a cell's content is the Score object and other cells
// Cell		-	Cells notify other cells when they are annihilated. This observer type is kept seperate from Annihilation so that cell observers can be easily distingiushed from Score observers
// Display	-	The only object that subscribes to all of the changes experienced by a cell is the display

#endif
