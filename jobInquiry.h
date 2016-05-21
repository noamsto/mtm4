//
//  jobInquiry.h
//  MTM4
//
//  Created by Noam Stolero on 20.5.2016.
//  Copyright © 2016 Noam Stolero. All rights reserved.
//

#ifndef jobInquiry_h
#define jobInquiry_h


#include "jobOffer.h"


typedef char*   name;
/*struct to hold job inquiry information*/
typedef struct jobInquiries
{
    int numberOfOffers; /*number of wanted job offers*/
    name company;  /*the name of the company*/
    name position; /*the wanted position*/
    double minSalary;   /*minimum salary*/
    jobOffer* offersList;   /*list of offers to a certain inquiry*/
    
}jobInquiry;


jobInquiry* jobInquiryCreate();
/*create empty job inquiry*/

void jobInquiryGetHotJob();
/*print the last registered job offer*/

void jobInquirySetNumber(jobInquiry* new_inquiry);
/*set the number of wanted job offers*/

void jobInquirySetPosition(jobInquiry* new_inquiry);
/*determine which position to search for*/

void jobInquirySetSalary(jobInquiry* new_inquiry);
/*determine minimum salary to look up*/

void jobInquirySetCompany(jobInquiry* new_inquiry);
/*set company name in job inquiry*/

void jobInquiryPrintAndDestroy(jobInquiry** jobInquiry_print);
/*print all the job offers relevent to the inquiry. according to relevance (from last registered to first). then delete job inquiry*/

void jobInquiryDestroy(jobInquiry** delete_inquiry);
/*delete job inquiry struct (free and turn pointer to null)*/


#endif /* jobInquiry_h */
