#include<iostream>

using namespace std;

class Fly_behaviour {
	public:
		virtual void fly() = 0;
};

class Fly_withwings: public Fly_behaviour {
	public:
		void fly();
};
class Fly_withoutwings: public Fly_behaviour {
	public:
		void fly();
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

		Duck() {}
		~Duck() {}
		virtual void set_quack_behaviour(Quack_behaviour *_qbb) = 0;
		virtual void perform_quack()
		{
			std::cout << "abstract! can't quak quack" << "\n";
		}
		virtual void perform_fly()
		{

			std::cout<<"abstract! can't fly" << "\n";
		}
		virtual void display()
		{
			std::cout<<"abstract! I am abstract" << "\n";
		}
};
class Mallad_duck : public  Duck {
	public:
		void set_quack_behaviour(Quack_behaviour *_qbb)
		{
			qb = _qbb;
		}

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
	std::cout<<"flying!" << "\n";
}
class Rubber_duck : public  Duck {
	public:
		void display();
		void perform_quack();
		void perform_fly();
		void set_quack_behaviour(Quack_behaviour *_qbb)
		{
			qb = _qbb;
		}

};

void Rubber_duck::display()
{
	std::cout<<"I am Rubber duck" << "\n";
}
void Rubber_duck::perform_quack()
{
	std::cout<<"squeak squeak!" << "\n";
}
void Rubber_duck::perform_fly()
{
	std::cout<<"no flying!" << "\n";
}

int main()
{
	Duck* mallad = new Mallad_duck();
	Duck* rubber = new Rubber_duck();
	Quack_behaviour *qb = new Quack();

	mallad->display();
	mallad->set_quack_behaviour(qb);
	mallad->perform_fly();
	mallad->perform_quack();

	//rubber->display();
	//rubber->perform_fly();
	//rubber->perform_quack();

	free(mallad);
	free(rubber);

	return 0;

}
