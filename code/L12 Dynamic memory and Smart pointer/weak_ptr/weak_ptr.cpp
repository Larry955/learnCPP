#include<memory>
using std::make_shared; using std::shared_ptr; using std::weak_ptr;

int main()
{
	auto p = make_shared<int>(42);

	weak_ptr<int>wp(p);		//wp weakly shares with p,use count on p is unchanged

	p.reset();	//assuming p.unique() was true, the int is deleted

	if (shared_ptr<int> np = wp.lock()){	//true if no is not null
		//inside the if, no shares its object with p
	}
	getchar();
}