#ifndef _SUBSCRIPTIONS_H_
#define _SUBSCRIPTIONS_H_

enum class SubscriptionType { Display, Annihilation };

// Display	-	The only object that subscribes to all of the changes experienced by a cell is the display
// Annihilation	-	The only object that subscribes only to the annihilation of a cell's content is the Score object

#endif
