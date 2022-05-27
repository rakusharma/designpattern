/*Headfirst weather implementation in C++*/
/*Weather: How am I doing? Me: Dry :)*/
#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include <iomanip>

using namespace std;


class Observer {
	public:
		virtual void update(float t, float h, float p)=0;
};

class Display {
	public: 
		virtual void display() = 0;
};


class Current_condition_display: public Observer, Display {

	public:
		float temp, humidity, pressure;
		void display()
		{
			cout << "displaying current conditions" << endl;
			cout << "temp" <<setw(8) <<temp << "humidity" <<setw(8) <<humidity << "pressure" <<setw(8) <<pressure <<endl ;
		}

		void update(float t, float h, float p)
		{
			temp = t;
			humidity = h;
			pressure = p;
			display();
		}

};

class Subject {
	public:
		vector<Observer*> o;
		virtual void register_o(Observer& _o) = 0;
		virtual void unregister_o(Observer& _o) = 0;
		virtual void notify_all_o() = 0;
};

class Weatherdata : public Subject {
	public:
		float temp;
		float humidity;
		float pressure;

		void register_o(Observer& _o) 
		{
			o.push_back(&_o);

		}
		void unregister_o(Observer& _o)
		{
			//o.remove(&_o);
		}
		void notify_all_o()
		{
			
			vector<Observer*>::iterator it;
			for (it = o.begin(); it != o.end(); ++it) {
				(*it)->update(temp, humidity, pressure);
			}
			
			//notify all 
		}

		void measurement_changed()
		{

			notify_all_o();
		}

		void set_measurement(float t, float h, float p)
		{
			temp = t;
			humidity = h;
			pressure = p;
			measurement_changed();
		}
};

int main()
{
	Weatherdata *wd = new Weatherdata;
	Current_condition_display *curr = new Current_condition_display;
	wd->register_o(*curr);
	wd->set_measurement(80, 65, 30.4f);
	return 1;
}


