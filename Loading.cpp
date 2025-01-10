#include <iostream>
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::milliseconds

using namespace std;

class Loading {
	private:
		string Phrase;
		int i = 0;
	public:
		Loading(string p) {
		 	Phrase = p;
		}

		void _Try_() {
			for(i=1; i <= 100; i++) {
				cout<<"\r"<<Phrase<<i<<"%";
				cout.flush();
				this_thread::sleep_for(chrono::milliseconds(80));
			}
			cout<<endl;
		}
};

Loading Load("loading... \0");

int main() {
	// Loading with \b and \n, if return 0 it's ok
	Load._Try_();

	return 0;
}
