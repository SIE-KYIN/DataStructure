#include "simulation.h"

// if customer come, enque func
void EnqueInfo(ArrayQueue *customer,int arrivalTime, int serviceTime)
{
    ArrayListNode element;

    element.arrivalTime = arrivalTime;
    element.serviceTime = serviceTime;
    element.startTime = -1;
    element.endTime = -1;
    addAQElement(customer, element);
}

// if time is same as specific customer, 
// deque from arrivalqueue and enque to waitqueue
void EnqueWaitList(ArrayQueue *CustomerInfo, ArrayQueue *WaitList)
{
    int arrivalTime = CustomerInfo->qList[CustomerInfo->front].pElement->arrivalTime;
    int serviceTime = CustomerInfo->qList[CustomerInfo->front].pElement->serviceTime;
    ArrayListNode element;

    removeAQElement(CustomerInfo);
    element.arrivalTime = arrivalTime;
    element.serviceTime = serviceTime;
    element.status = arrival;
    addAQElement(WaitList, element);
}

// service work
void StartService(ArrayQueue *WaitList, int time)
{ 
    ArrayListNode *tmp = peekAQElement(WaitList);
    if (tmp == NULL)
        return ;
    if (tmp->endTime == time){
        FinishedService(tmp, WaitList);
        tmp = peekAQElement(WaitList);
    }
    if (tmp->startTime == -1){
        tmp->startTime = time;
        tmp->endTime = tmp->startTime + tmp->serviceTime;
        tmp->status = start;
    }
}

// print current situation
void PrintCurrent(ArrayQueue *pQue)
{
    for (int i = 0; i < pQue->qList->currentElementCount; i++) {
        printf("CustomerArrivalTime : %d\n", pQue->qList->pElement[i].arrivalTime);
    }
}

// end
void FinishedService(ArrayListNode *CurrentCustomer, ArrayQueue *pQue)
{
    CurrentCustomer->status = end;
    printf("ArrivalTime = %d, End Time = %d\n", CurrentCustomer->arrivalTime, CurrentCustomer->endTime);
    removeAQElement(pQue);
}


int main(){
    ArrayQueue *CustomerInfo;
    ArrayQueue *WaitList;
    int time = 0;
    int maxTime = 20;
    int statusService = 0;

    CustomerInfo = createArrayQueue(CustomerCount);
    WaitList = createArrayQueue(CustomerCount);

    EnqueInfo(CustomerInfo, 0, 3);
    EnqueInfo(CustomerInfo, 2, 2);
    EnqueInfo(CustomerInfo, 4, 1);
    EnqueInfo(CustomerInfo, 6, 1);
    EnqueInfo(CustomerInfo, 8, 3);

    printf(">> %d\n", CustomerInfo->qList->currentElementCount);
    while (!(CustomerInfo->qList->currentElementCount == 0 && WaitList->qList->currentElementCount == 0))
    {
        if (CustomerInfo->qList[CustomerInfo->front].pElement->arrivalTime == time) {
            EnqueWaitList(CustomerInfo, WaitList);
        }
        StartService(WaitList, time);
        time++;
    }
    printf("Total Time : %d\n", time);
    return 0;
}