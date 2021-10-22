#include  "ArrayQueue.h"

#define CustomerCount 5

// if customer come, enque func
void EnqueInfo(ArrayQueue *customer,int arrivalTime, int serviceTime);

// if time is same as specific customer, 
// deque from arrivalqueue and enque to waitqueue
void EnqueWaitList(ArrayQueue *CustomerInfo, ArrayQueue *WaitList);

// service work
void StartService(ArrayQueue *WaitList, int time);

// print current situation
void PrintCurrent(ArrayQueue *pQue);

// end
void FinishedService(ArrayListNode *CurrentCustomer, ArrayQueue *pQue);
