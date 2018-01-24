#include"Common.h"
/*#include <process.h>
#include <windows.h>
#include <iostream>

int tickets = 10;
HANDLE iMutex ;

void sellTickets(void *ptr)
{
	while(tickets > 0)
	{
		WaitForSingleObject(iMutex, INFINITE);
		Sleep(10);
		std::cout<<"Thread 1 sell : "<< tickets<<std::endl;
		tickets --;
		ReleaseMutex(iMutex);
	}
}

void sellTickets2(void *ptr)
{
	while(tickets > 0)
	{
		WaitForSingleObject(iMutex, INFINITE);
		Sleep(10);
		std::cout<<"Thread 2 sell : "<< tickets<<std::endl;
		tickets --;
		ReleaseMutex(iMutex);
	}
}

int main()
{
	HANDLE t1 = (HANDLE)_beginthread(&sellTickets, 0, 0);
	HANDLE t2 = (HANDLE)_beginthread(&sellTickets2, 0, 0);
	iMutex	  = (HANDLE)CreateMutex(0, FALSE, 0);
	
	Sleep(2000);
	return 0;
}*/
/*


#include <OpenThreads/Thread>
#include <OpenThreads/Mutex>
#include <OpenThreads/Barrier>
#include <iostream>
#include <windows.h>

OpenThreads::Mutex mutex;
OpenThreads::Barrier bar;


class ThreadSelf : public OpenThreads::Thread
{
public:
	ThreadSelf(int a){threadid = a;}
	virtual ~ThreadSelf()
	{
		while(isRunning())
		{
			OpenThreads::Thread::YieldCurrentThread();
		}
	}
	virtual void run()
	{
		//OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mutex); 
		int count = 10;
		while(--count)
		{
			Sleep(10);
			std::cout<<"Thread print:"<< threadid <<std::endl;
		}
		bar.block(3);
	}
	int threadid;
};

int main()
{
	ThreadSelf t1(10);
	ThreadSelf t2(6);

	t1.start();
	t2.start();

	bar.block(3);
	std::cout<<"Here"<<std::endl;
	Sleep(1000);
	return 1;
}*/

#include <iostream>
#include <process.h>
#include <windows.h>
#include <OpenThreads/Condition>

int condition = 0;

OpenThreads::Condition cond;
OpenThreads::Mutex mutex;

void setCondition(void *ptr)
{
	condition = 1;
	cond.signal();
}

void ifCondition(void *ptr)
{
	cond.wait(&mutex, INFINITE);
	if(condition)
	{
		std::cout<<"Condifion is find"<<std::endl;
	}
}

int main()
{
	HANDLE t1 = (HANDLE)_beginthread(&ifCondition, 0, 0);

	Sleep(1000);
	HANDLE t2 = (HANDLE)_beginthread(&setCondition, 0, 0);


	Sleep(1000);
	std::cout<<"END"<<std::endl;
	return 0;
}