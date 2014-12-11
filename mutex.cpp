#include <pthread.h>
#include <iostream>
using namespace std;
class CBVBlock
{
public:
	pthread_mutex_t *mutex;

	void lock(){pthread_mutex_lock(mutex);}
	void unlock(){pthread_mutex_unlock(mutex);}

CBVBlock(){pthread_mutex_init(mutex,NULL);}
~CBVBlock(){pthread_mutex_destroy(mutex);}

};
class ObjectLocker 
{
public:
	ObjectLocker(CBVBlock *obj){obj->lock();}
	
};
class ObjectUnLocker 
{
public:
	ObjectUnLocker(CBVBlock *obj){obj->unlock();}
	
};
class A :public CBVBlock
{	
public:
	int a;
	void counter(){
	ObjectLocker lock(this);
	a++;
	ObjectUnLocker unlock(this);
    }
};



int main()
{
    A func;
    func.a=0;
    func.counter();
    cout << func.a;
	return 0;
}
