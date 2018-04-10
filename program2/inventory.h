#include <vector>
#include <string>
using namespace std;

class Inventory
{
public:
	Inventory();

	void Update(string item, int amount);

	void ListByName();

	void ListByQuantity();

private:
	// TODO: You provide this.
    int numItems;
	struct itemBox {
		string entry;
		int value;
	};
	vector<itemBox> sortedByName;
	vector<itemBox> sortedByQuantity;
};