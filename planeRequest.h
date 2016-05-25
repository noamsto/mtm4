//
//  planeRequest.h
//  MTM4
//
//  Created by Noam Stolero on 20.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//

#ifndef planeRequest_h
#define planeRequest_h

#define PLANENUMBER 4
#define DAY 24
#define N /*number of fields*/


typedef enum{TAKEOFF,LANDING}action;
typedef enum{FALSE,TRUE}boolean;
typedef int time;


/*struct to hold request information*/
typedef struct planeRequests
{
    /*  fields  */
    char[PLANENUMBER]   number;
    time                hours;
    action              reqStatus;
}planeRequest;

/*struct to hold the request to take off according to relevance. queue based*/
typedef struct requestQueues
{
    /*  fileds  */
    planeRequest*   head;
    planeRequest*   tail;
    int             size;
}requestQueue;


planeRequest* create_request();
/*create a new request*/

boolean is_field_clear(/*matrix*/);
/*check if there is an available field to land/takeoff*/

void clear_request(planeRequest*);
/*remove request from data base*/

void landed(planeRequest**,planeRequest*);
/*plane has succesfully landed*/

void took_off(requestQueue*,planeRequest*);
/*plane has finished taking off succesfully*/

void add_takeOff_request(requestQueue*,planeRequest*);
/*add take off request to data base*/

void add_landing_request(planeRequest**,planeRequest*);
/*add landing request to data base*/

#endif /* planeRequest_h */
