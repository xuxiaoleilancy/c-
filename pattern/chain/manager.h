#ifndef _manager_h
#define _manager_h
#include <iostream>

#include <string.h>
#include <stdlib.h>

using namespace std;

class Manager
{
public:
	Manager(Manager *manager, string name):m_manager(manager), m_name(name){} 
	virtual void DealWithRequest( string name , int num){}

protected:  
    Manager *m_manager;  
    string m_name; 
};

class CommonManager : public Manager
{
public:
	CommonManager(Manager *manager, string name):Manager(manager,name) {} 
	virtual void DealWithRequest(string name , int num){
		if(num < 500) //经理职权之内  
        {  
            cout<<"经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;  
        }  
        else  
        {  
            cout<<"经理"<<m_name<<"无法处理，交由总监处理"<<endl;  
            m_manager->DealWithRequest(name, num);  
        } 
	}
};

//总监  
class Majordomo: public Manager  
{  
public:  
    Majordomo(Manager *manager, string name):Manager(manager,name) {}  
    void DealWithRequest(string name, int num)   
    {  
        if(num < 1000) //总监职权之内  
        {  
            cout<<"总监"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;  
        }  
        else  
        {  
            cout<<"总监"<<m_name<<"无法处理，交由总经理处理"<<endl;  
            m_manager->DealWithRequest(name, num);  
        }  
    }  
};  

//总经理  
class GeneralManager: public Manager  
{  
public:  
    GeneralManager(Manager *manager, string name):Manager(manager,name) {}  
    void DealWithRequest(string name, int num)  //总经理可以处理所有请求  
    {  
        cout<<"总经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;  
    }  
};  

#endif //_manager_h