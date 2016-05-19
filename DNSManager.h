#include <string>
#include <iostream>
#include "HO.hpp"
#include "HT.hpp"
#include "dnsList.hpp"

using namespace std;

#ifndef __DNSManager_h__
#define __DNSManager_h__



// YOU ARE EXPECTED TO IMPLEMENT THE CLASS BELOW AS WELL AS
// ANY OTHER NECESSARY CLASS (SUCH AS THE HASH TABLE CLASS) AND
// AUXILIARY STRUCTURES THAT YOU NEED.


class DNSManager
{
    public:
        // DO NOT MODIFY ANYTHING IN THE PUBLIC PART. WHEN TESTING YOUR
        // CODES, WE WILL OVERWRITE THE PUBLIC PART WITH WHAT IS GIVEN
        // IN THIS FILE. ANY MODIFICATIONS THAT YOU MAKE WILL BE LOST.

        DNSManager();

        void registerDNS(const std::string& dnsIP);

        //void deleteDNS(const std::string& dnsIP);

        void registerURL(const std::string& url,
                         const std::string& ip, 
                         const std::vector<std::string>&);

        //void deleteURL(const std::string& url);

        std::string access(const std::string& url,
                           int& accessCount,
                           int& hopCount);
/*
        void mergeDNS(const std::string& dnsIP1,
                      const std::string& dnsIP2);*/
          dnsList* getDNSlist(){
              return dlist;
          }
          HT* getURLlist(){
            return URLtable;
          }
          HT* getMaster(){
            return masterDNS;
          }
          
    private:
      dnsList *dlist;
      HT *URLtable;/// = new HO();
      HT *masterDNS;
      double LoadFactor;


        // YOU MAY FREELY MODIFY THE PRIVATE PART OF THIS CLASS WHAT DO i want to put here?
};




//***************************************************************************************************************************************************
string DNSManager::access(const std::string& url,
                           int& accessCount,
                           int& hopCount)
{
  // if master DNS was deleted return Not Found//
 
  int URLidx = masterDNS->hash(url); // index of url in masterDNS
  int DNSidx = 0;
  string unrealIp = masterDNS->DNS[URLidx]->ip; //that ib is emty thus the facebook wasn't saved in that table

  string realIp = "Not Found";
  HT *tembTable = masterDNS;

  if(tembTable->DNS[URLidx]->isReal==true){
    realIp = unrealIp;
    return realIp;
  }


  //else
  while(!tembTable->DNS[URLidx]->isReal){ //leaves the loob when finds a table with a real ib adress of that URL OK
   // cout<<"HERE";
    DNSidx = dlist->hash(unrealIp);//id in dns list 
    tembTable = dlist->LISTofDNS[DNSidx]->URLtable; //gives us an Ib corresponding to that URL and hases to give an index  eqate to that table
    //change tabel
   
    URLidx = tembTable->hash(url); //finds the index of the google in that table 
    unrealIp = tembTable->DNS[URLidx]->ip;
    //return Not FOund if nothing was found or some tables were deleted

  }

  realIp = unrealIp;
  
  //realIp = tembTable->DNS[URLidx]->ip;
    return realIp;
}


//***************************************************************************************************************************************************
void DNSManager::registerURL( const std::string& url,
                         const std::string& ip ,const vector<std::string>& dnsChain)
{ 

  int hashIdx;
  int idx;

    hashIdx = dlist->hash(dnsChain.back()); //hash  "100.200.300.400"
   // dlist->LISTofDNS[hashIdx]->URLtable = new HT(dnsChain.back());
    URLtable = dlist->LISTofDNS[hashIdx]->URLtable;//this may be a master URL too!  was initiated as amaster;
    LoadFactor = dlist->LISTofDNS[hashIdx]->URLtable->currentAmount/(double) dlist->LISTofDNS[hashIdx]->URLtable->tableSize;

    

    if(LoadFactor> 0.5){
      cout<<"HERE";
         URLtable =  URLtable->rehash(URLtable);
    }
    //cout<<hashIdx<<dnsChain.back()<< "URL index Of DNS tabel"<<endl;
    
    idx = URLtable->hash(url); //find 
    URLtable->DNS[idx]->isReal = true;
    URLtable->DNS[idx]->url = url; //publicace
    URLtable->DNS[idx]->ip = ip;//place

  //}

  //HO *HachObj = new HO(url, ip);

  int nthTable = dnsChain.size()-1;//2// tbledaki son elemanina ulasabilecek if 2 1
  nthTable--; //
  //int hashIdx;
  if(dnsChain.size()>1)//size at least 2 0
  while(nthTable >-1)
      {
        hashIdx = dlist->hash(dnsChain[nthTable]); //find am empty space for new Hash

        URLtable = dlist->LISTofDNS[hashIdx]->URLtable;//place it there OCCUPY = true
        //URLtable = dnsChain.back();
        idx = URLtable->hash(url); //find 
        URLtable->DNS[idx]->url = url; //place
        URLtable->DNS[idx]->ip = dnsChain[nthTable+1];//place
        nthTable--;
      }

}
//***************************************************************************************************************************************************


void DNSManager::registerDNS(const std::string& dnsIP){
  int indx;

        if(dlist->amount == 0) // if
          {
            dlist->amount++;
            indx = dlist->hash(dnsIP);// "100.200.300.400"
            //cout<<indx<<dnsIP<<endl;
            dlist->LISTofDNS[indx]->URLtable = masterDNS;
            dlist->LISTofDNS[indx]->dnsIP = dnsIP;
            return;
          }

    else// (dlist->amount  > 1 )
    {
        dlist->amount++;
        URLtable = new HT(dnsIP);//assign this HT to some  Hash table 
        indx = dlist->hash(dnsIP);
        dlist->LISTofDNS[indx]->URLtable = URLtable;
        dlist->LISTofDNS[indx]->dnsIP = dnsIP; //ip of a DNS that it refers to !!!
      }
}
//***************************************************************************************************************************************************
DNSManager::DNSManager(){
 dlist = new dnsList;
 masterDNS = new HT("empty"); 
 //HT *URLtable = new HT();

//create ONE dns Table;

}

//***************************************************************************************************************************************************

#endif // __DNSManager_h__
