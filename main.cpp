//#include "HT.hpp"
#include "HO.hpp"
#include "DNSManager.h"
#include "dnsList.hpp"



bool isPrime(int n)
{
    bool result = true;
    if(n==1){ return false;}
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n % i == 0) result=false;
    }    
    return result;
}

int nextPrime(int n)
{
    for(int i = n+1 ; ; i++)
    {
        if(isPrime(i)) return i;
    } 
}

int prevPrime(int n)
{
    for (int i = n-1; ; i--)
    {
        if (isPrime(i))
        {
            return i;
        }
    }
}

int main(){

	DNSManager mgr;
	dnsList* dl= mgr.getDNSlist();
	HT* ht = mgr.getMaster();
	//cout<<dl->amount<<endl;
	mgr.registerDNS("100.200.300.400"); //has to initiate it as master which was declared as a new;
	//cout<<dl->amount<<endl;
	
	mgr.registerDNS("150.250.350.450");

	//cout<<dl->amount<<endl;
	vector<string> dnsChain;
	dnsChain.push_back("100.200.300.400");
	mgr.registerURL("www.facebook.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.google.com", "195.175.114.195", dnsChain);

	mgr.registerURL("www.facebk.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.gogle.com", "195.175.114.195", dnsChain);
	mgr.registerURL("www.facook.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.googe.com", "195.175.114.195", dnsChain);
	mgr.registerURL("www.facbook.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.gooe.com", "195.175.114.195", dnsChain);
	mgr.registerURL("www.facbook.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.goole.com", "195.175.114.195", dnsChain);
	mgr.registerURL("www.facook.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.google.com", "195.175.114.195", dnsChain);
	mgr.registerURL("www.facebook.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.google.com", "195.175.114.195", dnsChain);
	mgr.registerURL("www.facebook.com", "31.13.93.36", dnsChain);//it has to be in the master

	mgr.registerURL("www.google.com", "195.175.114.195", dnsChain);
	//mgr.registerURL("www.facebok.com", "31.13.93.36", dnsChain);//it has to be in the master

	
	//mgr.registerURL("www.googl.com", "195.175.114.195", dnsChain);



	dnsChain.push_back("150.250.350.450");

	mgr.registerURL("www.intel.com", "195.175.114.11", dnsChain);
	/*//mgr.registerURL("www.intel.com", "195.175.114.10", dnsChain);
	
	//mgr.registerURL("www.google.com", "195.175.114.195", dnsChain);
	//mgr.registerDNS("150.250.350.40");
*/
	
	for(int j=0; j< dl->LISTofDNS.size()-1;j++){
		cout<<"----------------------------------------------"<<endl;
		for(int i= 0; i < dl->LISTofDNS[j]->URLtable->DNS.size();i++)
				cout<<dl->LISTofDNS[j]->URLtable->DNS[i]->url<<endl;
		}




/*for(int i= 0; i < 11;i++) //////
		cout<<dl.LISTofDNS[6]->URLtable->DNS[i]->url<<endl;*/



/*for(int i= 0; i< dl.LISTofDNS.size();i++)
	cout<<dl.LISTofDNS[i]->Exists<<endl;*/



	//cout<<dl.LISTofDNS[10]->dnsIP<<endl;//looking for the elements of the hash table 

//for(int i= 0; i< dl->LISTofDNS.size();i++)
	//dl->LISTofDNS[0]->URLtable = new HT("kjac");


string ip;
int accessCount, hopCount;

ip = mgr.access("www.intel.com", accessCount, hopCount);
	cout<< ht->currentAmount <<endl;
cout<<ip<<endl;

/*for(int j=0;j<11;j++)
	cout<<mgr.getMaster()->DNS[j]->ip<<endl;*/


	int R  , prevIndex = 12;//=0;
	R = prevPrime( prevIndex);
	return 0;
}



//*****************************************************************************************************************************************************************
/*	HT *ht = new HT(); //creatse a vector;




	HO *hooo = new HO();
	//cout<<ht->hbash(*hooo)<<endl;


	//cout<<ht->hash(*hooo, 1)<<endl;
	
//	ht->insert(*hooo , dnsChain); // How can I trensfor these star representations into the Nonstar representations after insertion it is Full Thus 
			//cout<<hooo->isFull<<"Hi"<<endl; //ht->hash(*hooo)<<endl;
	
	HO *h2o = new HO(); //has to creatwe 
	HO *o = new HO();

	h2o->url = "Mello World";
	o->url = "YHKBhis is ";
	//ht->insert(*o , dnsChain);// equivalent to register URL 
	ht->hash(*o,4);
	
	
	ht->insert(*h2o , dnsChain); // How can I trensfor these star representations into the Nonstar representations
	dnsChain.push_back("150.250.350.458");

	ht->insert(*o , dnsChain);
	//ht->DNS[2] = "Hello";

	for(int l=0;l<ht->DNS.size(); l++)
		cout<< ht->DNS[l]->url <<endl; //is oneobject 



*/
//*****************************************************************************************************************************************************************