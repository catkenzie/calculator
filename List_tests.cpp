#include "List.h"
#include "unit_test_framework.h"

using namespace std;


TEST(test_list_default_ctor) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

//test member functions for list

TEST(test_list_size_func) {
  //Initialize an empty list and check that size = 0
  List<int> test;
  ASSERT_EQUAL(test.size(), 0);

  //Fill the list and check the size
  test.push_front(3);
  test.push_back(4);
  ASSERT_EQUAL(test.size(), 2);

}

TEST(test_list_front_and_back_funcs) {
  //Initialize a list 6 4 1
  List<int> test;
  test.push_front(1);
  test.push_front(4);
  test.push_front(6);

  ASSERT_EQUAL(test.front(), 6);
  //ASSERT_EQUAL(test.front(), test.first())
  ASSERT_EQUAL(test.back(), 1);
  //ASSERT_EQUAL(test.back(), test.last());
}

TEST(test_list_push_front_func){
  //Initialize a list as 1 using push_front
  List <int> test;
  ASSERT_TRUE(test.empty());
  test.push_front(1);

  //Check that the first and last elements are both 1 and size is 1
  ASSERT_EQUAL(test.size(), 1);
  ASSERT_EQUAL(test.front(), 1);
  ASSERT_EQUAL(test.back(), 1);

  //Fill the list with more elements and check that they are inserted on the front
  test.push_front(5);
  ASSERT_EQUAL(test.front(), 5);
  test.push_front(7);
  ASSERT_EQUAL(test.front(), 7);
  test.push_front(9);
  ASSERT_EQUAL(test.front(), 9);

}

TEST(test_list_push_back_func){
  //Initialize a list as 4 using push_back
  List <int> test;
  test.push_back(4);

  //Check that the first and last elements are both 4 and size is 4
  ASSERT_EQUAL(test.front(), 4);
  ASSERT_EQUAL(test.back(), 4);

  //Fill with more elements and check that they are inserted on the back
  test.push_back(8);
  ASSERT_EQUAL(test.back(), 8);
  test.push_back(3);
  ASSERT_EQUAL(test.back(), 3);

}

TEST(test_list_pop_front_func){
  //Initialize a list 1 3 5 7 9
  List <int> test;
  test.push_front(9);
  test.push_front(7);
  test.push_front(5);
  test.push_front(3);
  test.push_front(1);

  //Remove the elements and check that size and front properly update
  test.pop_front();
  ASSERT_EQUAL(test.front(), 3);
  ASSERT_EQUAL(test.size(), 4);
  test.pop_front();
  ASSERT_EQUAL(test.front(), 5);
  ASSERT_EQUAL(test.size(), 3);
  test.pop_front();
  ASSERT_EQUAL(test.front(), 7);
  ASSERT_EQUAL(test.size(), 2);
  test.pop_front();
  ASSERT_EQUAL(test.front(), 9);
  ASSERT_EQUAL(test.size(), 1);
  //Check the removal of the last element
  test.pop_front();
  ASSERT_EQUAL(test.size(), 0);

}

TEST(test_list_copy_all_func) {
  //Initialize a list of  98 4 6
  List<int> test;
  test.push_back(98);
  test.push_back(4);
  test.push_back(6);

  List<int> test2(test);
  ASSERT_EQUAL(test2.front(), test.front());
  ASSERT_EQUAL(test2.size(), test.size());
  ASSERT_EQUAL(test2.back(), test.back());
}

TEST(test_iterator_pointer_operator){
  //Initialize a list 6 9 1 and an iterator pointing at 6
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  List<int>::Iterator it = test.begin();

  //Testing the * operator
  ASSERT_EQUAL(*it, 6);
  ++it;
  ASSERT_EQUAL(*it, 9);

}

TEST(test_iterator_equals_operator){
  //Initialize a list 6 9 1 and an iterator pointing at 6
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  List<int>::Iterator it = test.begin();

  //Testing the == operator
  it = test.begin();
  List<int>::Iterator it2(it);
  ASSERT_TRUE(it == it2);

}
TEST(test_iterator_unequal_operator){
  //Initialize a list 6 9 1 and an iterator pointing at 6
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  List<int>::Iterator it = test.begin();

  //Make it and it2 point to different nodes and check that it!=it2
  it = test.begin();
  List<int>::Iterator it2 = test.end();
  ASSERT_TRUE(it != it2);
}

TEST(test_iterator_plus_operator){
  //Initialize a list 6 9 1 and an iterator pointing at 6
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  List<int>::Iterator it = test.begin();

  ASSERT_EQUAL(*it, 6);
  ++it;
  ASSERT_EQUAL(*it, 9);
  ++it;
  ASSERT_EQUAL(*it, 1);
}

TEST(test_iterator_minus_operator){
  //Initialize a list 6 9 1 and an iterator pointing at 1
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  List<int>::Iterator it = test.begin();

  ++it;
  ++it;

  //Testing the -- operator
  ASSERT_EQUAL(*it, 1);
  --it;
  ASSERT_EQUAL(*it, 9);
  --it;
  ASSERT_EQUAL(*it, 6);

}

TEST(test_iterator_begin_func){
  //Initialize a list 6 9 1 and an iterator pointing at 6
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  List<int>::Iterator it = test.begin();

  ASSERT_EQUAL(*it, 6);

}
TEST(test_iterator_erase_func_one_item_list){
  //Initialize a list 6 and an iterator pointing at 6
  List<int> test;
  test.push_back(6);
  auto it = test.begin();

  //Test the erase function on a list of one item
  test.erase(it);
  ASSERT_EQUAL(test.size(), 0);


}

TEST(test_iterator_erase_func_middle){
  //Initialize a list 6 9 1 and an iterator pointing at 9
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  auto it = test.begin();
  ++it;

  //Test the erase function on the second item
  test.erase(it);
  ASSERT_EQUAL(test.size(), 2);

}

TEST(test_iterator_erase_func_beginning){
  //Initialize a list 6 9 1 and an iterator pointing at 6
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  auto it = test.begin();

  //Test the erase function on the first item
  test.erase(it);
  ASSERT_EQUAL(test.front(), 9);
  ASSERT_EQUAL(test.size(), 2);

}

TEST(test_iterator_erase_func_end){
  //Initialize a list 6 9 1 and an iterator pointing at 1
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  auto it = test.begin();
  ++it;
  ++it;

  //Test the erase function on the last item
  test.erase(it);
  ASSERT_EQUAL(test.back(), 9);
  ASSERT_EQUAL(test.size(), 2);
}

///////////////////////////////////////////////////////////
TEST(test_iterator_insert_func_empty_list){
  //Initialize an empty list and an iterator
  List<int> test;
  auto it = test.begin();

  //Test the insert function on a list of one item
  test.insert(it, 5);
  ASSERT_EQUAL(test.back(), test.front());
  ASSERT_EQUAL(test.size(), 1);


}

TEST(test_iterator_insert_func_middle){
  //Initialize a list 6 9 1 and an iterator pointing at 1
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  auto it = test.begin();
  ++it;
  ++it;

  //Test the insert function in the middle to make 6 9 8 1
  test.insert(it, 8);
  auto it2 = test.begin();
  ++it2;
  ++it2;
  ASSERT_EQUAL(*it2, 8);
  ASSERT_EQUAL(test.size(), 4);
}

TEST(test_iterator_insert_func_beginning){
  //Initialize a list 6 9 1 and an iterator pointing at 1
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  auto it = test.begin();

  //Test the insert function at the beginning of the list to make 8 6 9 1
  test.insert(it, 8);
  ASSERT_EQUAL(test.front(), 8);
  ASSERT_EQUAL(test.size(), 4);

}
TEST(test_iterator_insert_func_end){
  //Initialize a list 6 9 1 and an iterator pointing past 1
  List<int> test;
  test.push_back(6);
  test.push_back(9);
  test.push_back(1);
  auto it = test.begin();
  ++it;
  ++it;
  ++it;

  //Test the insert function at the end to make 6 9 1 8
  test.insert(it, 8);
  ASSERT_EQUAL(test.back(), 8);
  ASSERT_EQUAL(test.size(), 4);
}


//Graveyard tests

/*TEST(test_list_pop_back_func){
  //Initialize a list 2 4 6 8 10
  List<int> test;
  test.push_back(2);
  test.push_back(4);
  test.push_back(6);
  test.push_back(8);
  test.push_back(10);

  //Remove the elements with pop back and check that size and back properly update
  test.pop_back();
  ASSERT_EQUAL(test.back(), 8);
  ASSERT_EQUAL(test.size(), 4);
  test.pop_back();
  ASSERT_EQUAL(test.back(), 6);
  ASSERT_EQUAL(test.size(), 3);
  test.pop_back();
  ASSERT_EQUAL(test.back(), 4);
  ASSERT_EQUAL(test.size(), 2);
  test.pop_back();
  ASSERT_EQUAL(test.back(), 2);
  ASSERT_EQUAL(test.size(), 1);
  //Check the removal of the last element
  test.pop_back();
  ASSERT_EQUAL(test.size(), 0);
}

TEST(test_list_push_and_pop_front) {
	//testing list with 1 element
	List<int> test1;
	ASSERT_TRUE(test1.empty());
	test.push_front(3);
	ASSERT_EQUAL(test1.front(), 3);
	ASSERT_EQUAL(test1.back(), 3);
	ASSERT_TRUE(test1.size() == 1);
	ASSERT_EQUAL(test1.pop_front(), 3);
	ASSERT_TRUE(test1.empty());

	//testing list with multiple elements
	List<int> test2;
	ASSERT_TRUE(test2.empty());
	test2.push_front(5);
	test2.push_front(3);
	ASSERT_EQUAL(test2.front(), 3);
	ASSERT_EQUAL(test2.back(), 5);
	ASSERT_TRUE(test2.size() == 2);
	test2.push_front(11);
	ASSERT_EQUAL(test2.front(), 11);
	ASSERT_EQUAL(test2.back(), 5);
	ASSERT_TRUE(test2.size() == 3);

	// 11 3 5
	test2.pop_front();
	ASSERT_EQUAL(test2.front(), 3);
	ASSERT_EQUAL(test2.back(), 5);
	ASSERT_TRUE(test2.size() == 2);
	// 3 5
	test2.pop_front();
	ASSERT_EQUAL(test2.front(), 5);
	ASSERT_EQUAL(test2.back(), 5);
	ASSERT_TRUE(test2.size() == 1);
	// 5
	test2.pop_front();
	ASSERT_TRUE(test2.empty());
}

TEST(test_list_push_and_pop_back) {
	//testing list with 1 element
	List<int> test1;
	test.push_back(12);
	ASSERT_EQUAL(test1.front(), 12);
	ASSERT_EQUAL(test1.back(), 12);
	ASSERT_TRUE(test1.size() == 1);
	test1.pop_back();
	ASSERT_TRUE(test1.empty());

	//testing list with multiple elements
	List<int> test2;
	ASSERT_TRUE(test2.empty());
	test2.push_back(7);
	test2.push_back(24);

	ASSERT_EQUAL(test2.front(), 7);
	ASSERT_EQUAL(test2.back(), 24);
	ASSERT_TRUE(test2.size() == 2);
	test2.push_back(1);
	ASSERT_EQUAL(test2.front(), 7);
	ASSERT_EQUAL(test2.back(), 1);
	ASSERT_TRUE(test2.size() == 3);
	test2.push_back(10);
	ASSERT_EQUAL(test2.front(), 7);
	ASSERT_EQUAL(test2.back(), 10);
	ASSERT_TRUE(test2.size() == 4);

	// 10 1 24 7
	test2.pop_back();
	ASSERT_EQUAL(test2.front(), 7);
	ASSERT_EQUAL(test2.back(), 1);
	ASSERT_TRUE(test2.size() == 3);
	// 1 24 7
	test2.pop_back();
	ASSERT_EQUAL(test2.front(), 7);
	ASSERT_EQUAL(test2.back(), 24);
	ASSERT_TRUE(test2.size() == 2);
	// 24 7
	test2.pop_back();
	ASSERT_EQUAL(test2.front(), 7);
	ASSERT_EQUAL(test2.back(), 7);
	ASSERT_TRUE(test2.size() == 1);
	// 7
	test2.pop_back();
	ASSERT_TRUE(test2.empty());
}

TEST(test_list_push_and_pop_front_and_back) {
	List<int> test1;
	//testing list with 1 element
	test1.push_front(3);
	ASSERT_EQUAL(test1.front(), 3);
	ASSERT_EQUAL(test1.back(), 3);
	ASSERT_TRUE(test1.size() == 1);
	ASSERT_EQUAL(test1.pop_front(), 3);
	ASSERT_TRUE(test1.empty());

	List<int> test2;
	test2.push_back(5);
	ASSERT_EQUAL(test2.front(), 5);
	ASSERT_EQUAL(test2.back(), 5);
	ASSERT_TRUE(test2.size() == 1);

	//testing list with multiple elements
	List<int> test3;
	test3.push_front(2);
	test3.push_front(7);
	test3.push_back(9);
	test3.push_front(5);
	test3.push_back(4);
	ASSERT_EQUAL(test3.front(), 5);
	ASSERT_EQUAL(test3.back(), 4);
	ASSERT_TRUE(test3.size() == 5);
	//list test3: 5 7 2 9 4

	//test pop_front and pop_back until empty

	ASSERT_TRUE(test3.empty());
}*/

// Add more test cases here

TEST_MAIN()
