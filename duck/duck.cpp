#include<iostream>

using namespace std;

class Fly_behaviour {
	public:
		virtual void fly() = 0;
};

class Fly_withwings: public Fly_behaviour {
	public:
		void fly()
		{
			cout << "I am flying" <<"\n";
		}
};
class Fly_withoutwings: public Fly_behaviour {
	public:
		void fly()
		{
			cout << "I am not flying!burrh" << "\n";
		}
};

class Quack_behaviour {
	public:
		virtual void quack() = 0;
};

class Quack:public Quack_behaviour {
	public: 
		void quack()
		{
			std::cout<<"quack quack!" << "\n";
		}
};
class Squeak:public Quack_behaviour {
	public: 
		void quack()
		{
			std::cout<<"squeak squeak!" << "\n";
		};
};
class Mutequack:public Quack_behaviour {
	public: 
		void quack() 
		{
			std::cout<<" Mute Mute!" << "\n";
		}
};
class Duck {
	public:
		Quack_behaviour *qb;
		Fly_behaviour *fb;

		Duck() {}
		~Duck() {}
		void set_quack_b(Quack_behaviour *_qb) 
		{
			qb = _qb;
		}
		void set_fly_b(Fly_behaviour *_fb) 
		{
			fb = _fb;
		}

		virtual void perform_quack() = 0;
		virtual void perform_fly() = 0;
		virtual void display() = 0;
};
class Mallad_duck : public  Duck {
	public:

		void display();
		void perform_quack();
		void perform_fly();
};

void Mallad_duck::display()
{
	std::cout<<"I am Mallad" << "\n";
}
void Mallad_duck::perform_quack()
{
	//std::cout<<"quack quack!" << "\n";
	qb->quack();
}
void Mallad_duck::perform_fly()
{
	//std::cout<<"flying!" << "\n";
	fb->fly();
}
class Rubber_duck : public  Duck {
	public:
		void display();
		void perform_quack();
		void perform_fly();

};

void Rubber_duck::display()
{
	std::cout<<"I am Rubber duck" << "\n";
}
void Rubber_duck::perform_quack()
{
	//std::cout<<"squeak squeak!" << "\n";
	qb->quack();
}
void Rubber_duck::perform_fly()
{
	//std::cout<<"no flying!" << "\n";
	fb->fly();

}

int main()
{
	Duck* mallad = new Mallad_duck();
	Duck* rubber = new Rubber_duck();
	Quack_behaviour *qb = new Quack();
	Quack_behaviour *qb_1 = new Squeak();
	Fly_behaviour *fb = new Fly_withwings();
	Fly_behaviour *fb_1 = new Fly_withoutwings();

	mallad->display();
	mallad->set_quack_b(qb);
	mallad->set_fly_b(fb);
	mallad->perform_fly();
	mallad->perform_quack();

	rubber->display();
	rubber->set_quack_b(qb_1);
	rubber->set_fly_b(fb_1);
	rubber->perform_fly();
	rubber->perform_quack();

	free(mallad);
	free(rubber);
	free(qb);
	free(qb_1);
	free(fb);
	free(fb_1);

	return 0;

}
