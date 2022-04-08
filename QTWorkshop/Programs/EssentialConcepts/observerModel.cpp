//bin/true; g++ -o "/tmp/$0.bin" "$0" && "/tmp/$0.bin" "$@"; exit $?
#include <iostream>
#include <vector>

struct Observer {
	private:
		int id;
	  std::string action;
	public:
		Observer(int id, std::string action) :id(id) , action(action) {
			std::cout << "Create new observer with action `" << action << " `which will be triggered if the subject that it is being observed changes its state" << std::endl;

		};
		void startAction() {
			std::cout << action << std::endl;
		}
};

struct Subject {
	private:
		int state;
		std::vector<Observer> observerList;
		void notify() {
				for (Observer a: observerList) {
						a.startAction();
				}
		}

	public:
		Subject(int state): state(state) {}
		void attach(Observer a) {
			observerList.push_back(a);
		}

		void changeState(int newState) {
			state = newState;
			notify();
		} 
};


int main() {
	Observer a(1, "update age of the person on database");
	Observer b(2, "send notification on mobile");

	Subject ageState(21);
	ageState.attach(a);
	ageState.attach(b);

	ageState.changeState(22);
}
