#include "MySBBST.hh"
#include "student.h"
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  int i;
  student *sarr[5];

  if (argc < 2)
    {
      student nope;
      MySBBST<student, unsigned int, studentStudentComp, uintStudentComp> tree(nope);
      sarr[0] = new student("bob", "marley", 1);
      sarr[1] = new student("sid", "vicious", 2);
      sarr[2] = new student("kurt", "cobain", 3);
      sarr[3] = new student("Darth", "Bewchy", 4);
      sarr[4] = new student("Foo", "Fighter", 5);
      for (i = 0; i < 5; i++)
	{
	  tree.add(*sarr[i]);
	  tree.printout();
	  cout << endl << "-----------" << endl;
	}
      student tmp = tree.remove(3);
      cout << tmp << endl;
      tmp = tree.remove(598);
      cout << tmp << endl;
    }
  else
    {
      MySBBST<int, int, intintCompare, intintCompare> tree(0);
      tree.printout();
      for (i = 1; i < argc; i++)
	{
	  tree.add(atoi(argv[i]));
	  tree.printout();
	  cout << endl << "=============" << endl;
	}
      cout << "SEARCHING: " << tree.search(42) << " " << tree.search(51) << " " << tree.search(69) << " " << tree.search(5)  << endl;
      cout << "TIME TO REMOVE!\n" << endl;
      cout << "removed " << tree.remove(69) << endl;
      tree.printout();
      cout << endl << "=============" << endl;
      cout << "removed " << tree.remove(42) << endl;
      tree.printout();
      cout << endl << "=============" << endl;
      cout << "removed " << tree.remove(51) << endl;
      tree.printout();
      cout << endl << "=============" << endl;
      cout << "removed " << tree.remove(5) << endl;
      tree.printout();
      cout << endl << "=============" << endl;
    }
  return 0;
}