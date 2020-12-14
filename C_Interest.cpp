#include <thread> 
#include<bits/stdc++.h>
using namespace std; 

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

class Actor{
	protected:
		 string name;
		 int count;
	public:
		Actor(){
			this->count = 0;
			
			// Generate randonm name
			// Number of possible names n = (24 ^ 64) * (24 ^ 64)!
			// the probability that two names we choose are distinct is n! / (n^2 * (n - 2)!)
			// rng gets  
			long long cipher = rng() % 25;

			for(int i = 0; i < to_string(cipher).size(); i++){
				this->name+= char(i + 'a');
			}
		}
		virtual void increase();
		virtual void decrease();

		string getName(){
			return this->name;
		}
		int getCount(){
			return this->count;
		}
		~Actor(){}

};

class DefaultCount: public Actor{
	public:
		void increase(){
			this->count++;
		}
		void decrease(){
			this->count--;
		}
};

class CountWithValue: public Actor{
	public:
		int value;
		CountWithValue(int value):value(value){

		}
		void increase(){
			this->count+=this->value;
		}
		void decrease(){
			this->count-=this->value;
		}
};

class AutoIncrease: public CountWithValue{
	public:
		AutoIncrease(int inc):CountWithValue(0){
			this->count+=inc;
		}
};

class AutoDecrease: public CountWithValue{
	public:
		AutoDecrease(int dec):CountWithValue(0){
			this->count+=dec;
		}
};

template <typename T>

void test_internal_default() {
   Actor* act;
   T child;
   act = &child;
}

template <typename T>

void test_default() {
   test_internal_default<T>();
}

template <typename T>

void test_internal_cnt_val() {
   Actor* act;
   T child(1);
   act = &child;
}

template <typename T>

void test_cnt_val() {
   test_internal_cnt_val<T>();
}

template <typename T>

void test_internal_auto() {
   Actor* act;
   T child(1);
   act = &child;
}

template <typename T>

void test_auto() {
   test_internal_auto<T>();
}

class Dispatcher{
	public:
	    Dispatcher(){
	    	thread thr1(test_default<DefaultCount>);
	    	thread thr2(test_cnt_val<CountWithValue>);
	    	thread thr3(test_auto<AutoIncrease>);
	    	thread thr4(test_auto<AutoDecrease>);
		thr1.join();
	    	thr2.join();
	    	thr3.join();
	    	thr4.join();
	    }
};


int main() 
{	 
	Dispatcher* inst;
} 
