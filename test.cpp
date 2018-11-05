#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedListOfInts.h"

//Testing isEmpty function
TEST_CASE("An empty list reports empty")
{
  LinkedListOfInts list;
  SECTION("list is empty")
  {
    CHECK(list.isEmpty() == true);
  }
  SECTION("list is not empty")
  {
    list.addFront(1);
    CHECK(list.isEmpty() == false);
  }
}

//testing size function
TEST_CASE("Size reports the size of the list")
{
  LinkedListOfInts list;
  SECTION("list is empty")
  {
    CHECK(list.size() == 0);
  }
  SECTION("list has one item")
  {
    list.addFront(1);
    auto vector = list.toVector();
    CHECK(list.size() == 1);
  }
  SECTION("list has multiple items")
  {
    list.addFront(1);
    list.addFront(2);
    list.addBack(3);
    auto vector = list.toVector();
    CHECK(list.size() == 3);
  }

}

//testing search function
TEST_CASE("searching through a list")
{
  LinkedListOfInts list;
  SECTION("empty list")
  {
    CHECK(list.search(1) == false);
  }
  SECTION("list has multiple items")
  {
    list.addFront(1);
    list.addBack(2);
    CHECK(list.search(1) == true);
  }
}

//testing addBack function
TEST_CASE("adding item to back of list")
{
  LinkedListOfInts list;
  list.addBack(1);
  list.addBack(2);
  list.addBack(3);
  auto vector = list.toVector();
	CHECK(vector.size() == 3);
	CHECK(vector[0] == 1);
	CHECK(vector[1] == 2);
	CHECK(vector[2] == 3);
}

//testing addFront
TEST_CASE("adding item to front of list")
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addFront(2);
  list.addFront(3);
  auto vector = list.toVector();
  CHECK(vector.size() == 3);
  CHECK(vector[0] == 3);
	CHECK(vector[1] == 2);
	CHECK(vector[2] == 1);
}

//testing removeBack
TEST_CASE("removing item from back of list")
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addFront(2);
  list.addFront(3);
  auto vector = list.toVector();
  CHECK(vector.size() == 3);
  CHECK(vector[0] == 3);
  CHECK(vector[1] == 2);
  CHECK(vector[2] == 1);
  list.removeBack();
  CHECK(vector.size() == 2);
  CHECK(vector[0] == 3);
  CHECK(vector[1] == 2);
  list.removeBack();
  CHECK(vector.size() == 1);
  CHECK(vector[0] == 3);
}

//testing removeFront
TEST_CASE("removing item from front of list")
{
  LinkedListOfInts list;
  list.addFront(3);
  list.addFront(2);
  list.addFront(1);
  auto vector = list.toVector();
  CHECK(vector.size() == 3);
  CHECK(vector[0] == 1);
  CHECK(vector[1] == 2);
  CHECK(vector[2] == 3);
  list.removeBack();
  CHECK(vector.size() == 2);
  CHECK(vector[0] == 1);
  CHECK(vector[1] == 2);
  list.removeBack();
  CHECK(vector.size() == 1);
  CHECK(vector[0] == 1);
}
}
